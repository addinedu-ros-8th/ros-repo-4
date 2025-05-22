import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Float32

from .pinkylib import Motor

from rcl_interfaces.msg import SetParametersResult
import time

class PinkyBringup(Node):
 
    def __init__(self):
        super().__init__('pinky_bringup')
 
        self.pinky = Motor()

        self.pinky.enable_motor()
        self.pinky.start_motor()
 
        self.cmd_vel_subscription = self.create_subscription(
            Twist,
            '/cmd_vel',
            self.cmd_vel_callback,
            1
        )

        self.declare_parameter('motor_ratio', 1.0) # 왼쪽 모터 출력 비율 설정
        self.motor_ratio = self.get_parameter('motor_ratio').value
        self.pinky.set_ratio(self.motor_ratio)
     
        self.add_on_set_parameters_callback(self.parameter_callback)

        self.get_logger().info("pinky is ready!!")

 
    def parameter_callback(self, params):
        for param in params:
            if param.name == 'motor_ratio':
                self.motor_ratio = param.value
                self.pinky.set_ratio(self.motor_ratio)

        self.get_logger().info(f"set L motor ratio {self.motor_ratio * 100} %")
        
        return SetParametersResult(successful=True)
 
    def cmd_vel_callback(self, msg):
        linear_x = msg.linear.x 
        angular_z = msg.angular.z / 5

        # 좌우 회전
        left_speed = linear_x - angular_z
        right_speed = linear_x + angular_z

        set_l = self.custom_map(left_speed)
        set_r = self.custom_map(right_speed)
 
        self.pinky.move(set_l, set_r)
        self.cnt = 0

    def custom_map(self, value):
        if value == 0:
            return 0
        elif value > 0:
            result = 25 + ((value * 20) / 0.5)
        else:
            result = -25 + ((value * 20) / 0.5)
        
        return max(min(result, 100), -100)

    def destroy_node(self):
        self.pinky.disable_motor()
        self.pinky.stop_motor()
        self.pinky.clean()
        
def main(args=None):
    rclpy.init(args=args)
    pinky_bringup_node = PinkyBringup()
     
    try:
        rclpy.spin(pinky_bringup_node)
    except KeyboardInterrupt:
        pass
    finally:
        pinky_bringup_node.destroy_node()
        rclpy.shutdown()
 
if __name__ == '__main__':
    main()
