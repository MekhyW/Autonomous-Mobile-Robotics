import rclpy
from rclpy.node import Node
from custom_interfaces.srv import Aula8

class SrvServer(Node):
    def __init__(self):
        super().__init__('aula8_srv_server')
        self.srv = self.create_service(Aula8, 'aula8_srv', self.srv_callback)

    def srv_callback(self, request, response):
        response.sum = request.a + request.b
        self.get_logger().info('Incoming request\na: %d b: %d' % (request.a, request.b))
        return response
        
def main(args=None):
    rclpy.init(args=args)
    srv_server = SrvServer()
    rclpy.spin(srv_server)
    srv_server.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
