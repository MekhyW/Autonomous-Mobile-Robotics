import rclpy
from rclpy.node import Node
from custom_interfaces.srv import Aula8
import sys

class SrvClient(Node):
    def __init__(self):
        super().__init__('aula8_srv_client')
        self.srv_client = self.create_client(Aula8, 'aula8_srv')
        while not self.srv_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting...')

    def send_request(self, a, b):
        req = Aula8.Request()
        req.a = a
        req.b = b
        future = self.srv_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        return future.result()

def main(args=None):
    rclpy.init(args=args)
    srv_client = SrvClient()
    result = srv_client.send_request(int(sys.argv[1]), int(sys.argv[2]))
    srv_client.get_logger().info('Result of add: %d' % (result.sum))
    srv_client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

