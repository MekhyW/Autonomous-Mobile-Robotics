import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from custom_interfaces.action import Aula9
import sys

class ActionClientNode(Node):
    def __init__(self):
        super().__init__('action_client')
        self.action_client = ActionClient(self, Aula9, 'aula9_action')

    def send_goal(self, count_up_to):
        self.get_logger().info('Sending goal...')
        goal_msg = Aula9.Goal()
        goal_msg.count_up_to = count_up_to

        self.action_client.wait_for_server()

        self.send_goal_future = self.action_client.send_goal_async(
            goal_msg, 
            feedback_callback=self.feedback_callback
        )
        self.send_goal_future.add_done_callback(self.goal_response_callback)

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f'Received feedback: {feedback.current_number}')

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Final Result: {result.final_count}')
        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    action_client = ActionClientNode()
    action_client.send_goal(int(sys.argv[1]))
    rclpy.spin(action_client)