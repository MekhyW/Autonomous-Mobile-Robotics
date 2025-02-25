import rclpy
from rclpy.node import Node
from custom_interfaces.msg import Aula7

class Publisher(Node):
    def __init__(self):
        super().__init__('aula7_publisher')
        self.publisher = self.create_publisher(Aula7, 'aula7_topic', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.contador = 0

    def timer_callback(self):
        self.contador +=1
        msg = Aula7()
        msg.count = self.contador
        msg.message = 'The count is: ' 
        self.publisher.publish(msg)
        self.get_logger().info('Publishing: "%s%i"' % (msg.message, msg.count))

def main(args=None):
    rclpy.init(args=args)
    publisher = Publisher()
    rclpy.spin(publisher)
    publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()