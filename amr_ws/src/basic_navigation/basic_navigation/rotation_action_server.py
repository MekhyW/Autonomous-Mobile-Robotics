import math
import time
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse, CancelResponse
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup
from geometry_msgs.msg import Twist
from custom_interfaces.action import Rotate

class RotationActionServer(Node):
    def __init__(self):
        super().__init__('rotation_action_server')
        self.declare_parameter('rotation_speed', 0.5)
        self.rotation_speed = self.get_parameter('rotation_speed').value
        self.vel_pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.action_server = ActionServer(
            self,
            Rotate,
            'rotate',
            self.execute_callback,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            callback_group=ReentrantCallbackGroup())
        self.get_logger().info('Rotation action server initialized')
        
    def goal_callback(self, goal_request):
        self.get_logger().info(f'Received goal request to rotate {goal_request.angle} degrees')
        return GoalResponse.ACCEPT
        
    def cancel_callback(self, goal_handle):
        self.get_logger().info('Received cancel request')
        return CancelResponse.ACCEPT
        
    async def execute_callback(self, goal_handle):
        self.get_logger().info('Executing rotation goal')
        feedback_msg = Rotate.Feedback()
        result = Rotate.Result()
        target_angle = goal_handle.request.angle
        target_radians = math.radians(abs(target_angle))
        direction = 1.0 if target_angle > 0 else -1.0
        vel_msg = Twist()
        vel_msg.angular.z = direction * self.rotation_speed
        angular_velocity = self.rotation_speed
        time_for_rotation = target_radians / angular_velocity
        start_time = self.get_clock().now()
        elapsed_time = 0.0
        remaining_degrees = abs(target_angle)
        while elapsed_time < time_for_rotation:
            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                self.get_logger().info('Goal canceled')
                self.stop_robot()
                result.success = False
                return result
            self.vel_pub.publish(vel_msg)
            elapsed_time = (self.get_clock().now() - start_time).nanoseconds / 1e9
            progress = min(1.0, elapsed_time / time_for_rotation)
            remaining_degrees = abs(target_angle) * (1.0 - progress)
            feedback_msg.remaining_degrees = remaining_degrees
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(0.1)
        self.stop_robot()
        result.success = True
        goal_handle.succeed()
        self.get_logger().info('Rotation completed successfully')
        return result
        
    def stop_robot(self):
        stop_msg = Twist()
        self.vel_pub.publish(stop_msg)

def main(args=None):
    rclpy.init(args=args)
    rotation_action_server = RotationActionServer()
    executor = MultiThreadedExecutor()
    executor.add_node(rotation_action_server)
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        executor.shutdown()
        rotation_action_server.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()