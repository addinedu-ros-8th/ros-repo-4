#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from tangerbot_msgs.msg import Gesture  # HandleCommand는 이제 메시지
from geometry_msgs.msg import Point
class GestureInterpreterNode(Node):
    def __init__(self):
        super().__init__('gesture_interpreter_node')
        self.subscription = self.create_subscription(
            Gesture,
            'gesture_preprocessed',
            self.gesture_callback,
            10
        )
        # 서비스 대신 퍼블리셔 사용
        self.publisher = self.create_publisher(Gesture, 'gesture', 10)


        self.get_logger().info(":다섯_손가락을_편_손바닥: 제스처 해석 노드 시작됨. '/gesture_preprocessed' 구독 중")

    def gesture_callback(self, msg: Gesture):
        robot_id = msg.robot_id
        point: Point = msg.point
        gesture_type = self.interpret_gesture(point)
        if gesture_type is None:
            self.get_logger().info(":질문: 알 수 없는 제스처, 무시됨")
            return
        # HandleCommand 메시지 생성
        command_msg = Gesture()
        command_msg.robot_id = robot_id
        command_msg.user_id = self.user_id
        command_msg.type = gesture_type
        command_msg.data = '0'  # 현재는 필요 없으므로 '0' 문자열로 보냄
        self.publisher.publish(command_msg)
        self.get_logger().info(f":수신_봉투: 명령 퍼블리시됨: {robot_id} <- 타입 {gesture_type}")


    def interpret_gesture(self, point: Point):
        if point.y < 0.4:
            return 1  # FOLLOWING
        elif point.y > 0.6:
            return 2  # STOP
        elif point.x < 0.3:
            return 3  # RETURN
        else:
            return None  # 알 수 없는 제스처
        

def main(args=None):
    rclpy.init(args=args)
    node = GestureInterpreterNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
if __name__ == '__main__':
    main()