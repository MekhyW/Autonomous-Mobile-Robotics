import rclpy
from rclpy.node import Node
from custom_interfaces.msg import Temperature
import random

class Publisher(Node):
    def __init__(self):
        super().__init__('temperature_publisher')
        self.publisher = self.create_publisher(Temperature, 'temperature', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        new_temperature = random.randint(0, 100)
        msg = Temperature()
        msg.temperature = new_temperature
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    publisher = Publisher()
    rclpy.spin(publisher)
    publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()