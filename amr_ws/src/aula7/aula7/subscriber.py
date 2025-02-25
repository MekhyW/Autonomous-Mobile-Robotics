import rclpy
from rclpy.node import Node
from custom_interfaces.msg import Aula7

class Subscriber(Node):
    def __init__(self):
        super().__init__('aula7_subscriber')
        self.subscription = self.create_subscription(Aula7, 'aula7_topic', self.listener_callback, 10)
        
    def subscription_callback(self, msg):
        mensagem = msg.message
        contagem = msg.count
        self.get_logger().info('Receiving: "%s%i"' % (mensagem, contagem))

def main(args=None):
    rclpy.init(args=args)
    subscriber = Subscriber()
    rclpy.spin(subscriber)
    subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()