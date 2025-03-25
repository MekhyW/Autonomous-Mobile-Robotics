import rclpy
from rclpy.node import Node
from custom_interfaces.srv import CelsiusToFahrenheit

class SrvServer(Node):
    def __init__(self):
        super().__init__('celsiustofahrenheit_srv_server')
        self.srv = self.create_service(CelsiusToFahrenheit, 'celsiustofahrenheit_srv', self.srv_callback)

    def srv_callback(self, request, response):
        response.fahrenheit = request.celsius * 9/5 + 32
        return response
        
def main(args=None):
    rclpy.init(args=args)
    srv_server = SrvServer()
    rclpy.spin(srv_server)
    srv_server.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
