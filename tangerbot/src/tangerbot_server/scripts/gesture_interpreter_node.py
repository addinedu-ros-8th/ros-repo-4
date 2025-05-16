#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from tangerbot_msgs.msg import Gesture
from geometry_msgs.msg import Point
from std_srvs.srv import Trigger  # 참고용
from tangerbot_msgs.srv import HandleCommand  # srv 경로 확인 필요

class GestureInterpreterNode(Node):
    def __init__(self):
        super().__init__('gesture_interpreter_node')

        self.subscription = self.create_subscription(
            Gesture,
            'gesture_preprocessed',
            self.gesture_callback,
            10
        )

        self.cli = self.create_client(HandleCommand, 'handle_command')

        while not self.cli.wait_for_service(timeout_sec=2.0):
            self.get_logger().warn('handle_command 서비스 대기 중...')

        self.user_id = 'user_1'  # 고정값 또는 추후 사용자 ID 매핑

    def gesture_callback(self, msg: Gesture):
        robot_id = msg.robot_id
        point: Point = msg.point

        # 단순 좌표 기반 판단 (예시 기준)
        gesture_type = self.interpret_gesture(point)

        if gesture_type is None:
            self.get_logger().info("알 수 없는 제스처, 무시됨")
            return

        # 서비스 요청 메시지 구성
        request = HandleCommand.Request()
        request.robot_id = robot_id
        request.user_id = self.user_id
        request.type = gesture_type
        request.data = 0  # 현재는 필요 없음

        future = self.cli.call_async(request)
        future.add_done_callback(self.response_callback)

        self.get_logger().info(f"요청 보냄: {robot_id} <- {gesture_type}")

    def interpret_gesture(self, point: Point):
        if point.y < 0.4:
            return 1  # FOLLOWING
        elif point.y > 0.6:
            return 2  # STOP
        elif point.x < 0.3:
            return 3  # RETURN
        else:
            return None  # Unknown

    def response_callback(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info("명령 성공")
            else:
                self.get_logger().warn("명령 실패")
        except Exception as e:
            self.get_logger().error(f"서비스 호출 중 예외: {e}")

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
