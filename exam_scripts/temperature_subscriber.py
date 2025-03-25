import rclpy
from rclpy.node import Node
from custom_interfaces.msg import Temperature

class Subscriber(Node):
    def __init__(self):
        super().__init__('temperature_subscriber')
        self.subscription = self.create_subscription(Temperature, 'temperature', self.listener_callback, 10)
        
    def subscription_callback(self, msg):
        new_temperature = msg.temperature
        self.get_logger().info('Temperature: %d' % new_temperature)

def main(args=None):
    rclpy.init(args=args)
    subscriber = Subscriber()
    rclpy.spin(subscriber)
    subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()