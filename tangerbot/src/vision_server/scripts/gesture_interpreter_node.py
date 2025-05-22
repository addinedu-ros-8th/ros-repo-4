#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from tangerbot_msgs.msg import Gesture
from tangerbot_msgs.srv import HandleCommand
from geometry_msgs.msg import Point

class GestureInterpreterNode(Node):
    def __init__(self):
        super().__init__('gesture_interpreter_node')

        self.subscription = self.create_subscription(
            Gesture,
            '/gesture',
            self.gesture_callback,
            10
        )

        self.cli = self.create_client(HandleCommand, 'handle_command')

        while not self.cli.wait_for_service(timeout_sec=2.0):
            self.get_logger().warn('handle_command 서비스 대기 중...')

        self.user_id = 'user1'
        self.last_gesture_type = None  # 마지막으로 전송한 제스처 타입 저장

    def gesture_callback(self, msg: Gesture):
        current_gesture = msg.gesture
        point: Point = msg.point
        robot_id = msg.robot_id

        self.get_logger().info(
            f"[Gesture] 받은 제스처: {current_gesture} (Point: {point.x:.2f}, {point.y:.2f})"
        )

        # 제스처가 이전과 다르면 서비스 요청
        if current_gesture != self.last_gesture_type:
            self.get_logger().info(
                f"[전송] 제스처 변경 감지: {self.last_gesture_type} → {current_gesture}"
            )
            self.send_service_request(robot_id, current_gesture)
            self.last_gesture_type = current_gesture
        else:
            self.get_logger().debug("같은 제스처, 전송 생략")

    def send_service_request(self, robot_id, gesture_type):
        request = HandleCommand.Request()
        request.robot_id = robot_id
        request.user_id = self.user_id
        request.type = gesture_type
        request.data = ""  # 현재는 추가 데이터 없음

        future = self.cli.call_async(request)
        future.add_done_callback(self.response_callback)

    def response_callback(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info("명령 성공적으로 처리됨 ✅")
            else:
                self.get_logger().warn("명령 실패 ⚠️")
        except Exception as e:
            self.get_logger().error(f"서비스 호출 실패 ❌: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = GestureInterpreterNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("노드 종료 중 (Ctrl+C)")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
