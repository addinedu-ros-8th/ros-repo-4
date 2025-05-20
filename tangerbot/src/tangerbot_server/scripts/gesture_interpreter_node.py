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
            'gesture_preprocessed',
            self.gesture_callback,
            10
        )
        # 서비스
        self.handle_command_client = self.create_client(HandleCommand, 'handle_command')


        self.get_logger().info(":다섯_손가락을_편_손바닥: 제스처 해석 노드 시작됨. '/gesture_preprocessed' 구독 중")

    def gesture_callback(self, msg: Gesture):
        robot_id = msg.robot_id
        user_id = msg.user_id
        point: Point = msg.point
        gesture_type = self.interpret_gesture(point)
        if gesture_type is None:
            self.get_logger().info(":질문: 알 수 없는 제스처, 무시됨")
            return
        
        # 서비스 요청 메시지 구성
        request = HandleCommand.Request()
        request.robot_id = robot_id
        request.user_id = user_id
        request.type = gesture_type
        request.data = 0  # 현재는 필요 없음

        future = self.handle_command_client.call_async(request)
        future.add_done_callback(self.response_callback)
        self.get_logger().info(f":수신_봉투: 명령 전송됨: {robot_id} <- 타입 {gesture_type}")


    def interpret_gesture(self, point: Point):
        if point.y < 0.4:
            return 1  # FOLLOWING (COME)
        elif point.y > 0.6:
            return 2  # STOP
        # elif point.x < 0.3: 
        #     return 3  # RETURN #(BACK 삭제)
        else:
            return None  # 알 수 없는 제스처
        
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