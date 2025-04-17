import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
from std_srvs.srv import Empty
from custom_interfaces.action import Rotate

class MainNavigationNode(Node):
    def __init__(self):
        super().__init__('main_navigation_node')
        self.declare_parameter('wall_distance_threshold', 0.5)
        self.declare_parameter('forward_speed', 0.2)
        self.declare_parameter('rotation_angle', 90.0)
        self.wall_threshold = self.get_parameter('wall_distance_threshold').value
        self.forward_speed = self.get_parameter('forward_speed').value
        self.rotation_angle = self.get_parameter('rotation_angle').value
        self.vel_pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.scan_sub = self.create_subscription(LaserScan, 'scan', self.laser_callback, 10)
        self.srv = self.create_service(Empty, 'start_navigation', self.start_navigation_callback)
        self.action_client = ActionClient(self, Rotate, 'rotate')
        self.is_navigating = False
        self.is_rotating = False
        self.get_logger().info('Main navigation node initialized')

    def laser_callback(self, msg):
        if not self.is_navigating:
            return
        front_angles = len(msg.ranges) // 3
        middle_start = len(msg.ranges) // 3
        middle_end = 2 * len(msg.ranges) // 3
        front_readings = msg.ranges[middle_start:middle_end]
        min_distance = min(front_readings)
        if not self.is_rotating and min_distance < self.wall_threshold:
            self.get_logger().info(f'Wall detected at {min_distance}m. Starting rotation.')
            self.stop_robot()
            self.send_rotation_goal()
        elif not self.is_rotating:
            self.move_forward()

    def move_forward(self):
        msg = Twist()
        msg.linear.x = self.forward_speed
        self.vel_pub.publish(msg)
        
    def stop_robot(self):
        msg = Twist()
        self.vel_pub.publish(msg)
        
    def send_rotation_goal(self):
        self.is_rotating = True
        goal_msg = Rotate.Goal()
        goal_msg.angle = self.rotation_angle
        self.action_client.wait_for_server()
        self.send_goal_future = self.action_client.send_goal_async(
            goal_msg, 
            feedback_callback=self.feedback_callback)
        self.send_goal_future.add_done_callback(self.goal_response_callback)
        
    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error('Rotation goal rejected')
            self.is_rotating = False
            return
        self.get_logger().info('Rotation goal accepted')
        self.result_future = goal_handle.get_result_async()
        self.result_future.add_done_callback(self.get_result_callback)
        
    def get_result_callback(self, future):
        result = future.result().result
        status = future.result().status
        if status == 4:
            self.get_logger().info('Rotation completed successfully')
        else:
            self.get_logger().error(f'Rotation failed with status: {status}')
        self.is_rotating = False
        
    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f'Remaining degrees: {feedback.remaining_degrees}')
        
    def start_navigation_callback(self, request, response):
        if not self.is_navigating:
            self.get_logger().info('Starting navigation')
            self.is_navigating = True
        else:
            self.get_logger().info('Navigation already in progress')
        return response

def main(args=None):
    rclpy.init(args=args)
    node = MainNavigationNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()