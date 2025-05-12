#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from vision_server.msg import Gesture  # 커스텀 메시지
import cv2
import mediapipe as mp

class GestureReceiveNode(Node):
    def __init__(self):
        super().__init__('gesture_receive_node')

        # UDP 카메라 스트림 (5000번 포트 예시)
        self.cap = cv2.VideoCapture('udp://0.0.0.0:5000', cv2.CAP_FFMPEG)

        if not self.cap.isOpened():
            self.get_logger().error("카메라 스트림을 열 수 없습니다. 포트를 확인하세요.")
            return

        # MediaPipe Hands 초기화
        self.mp_hands = mp.solutions.hands
        self.hands = self.mp_hands.Hands(static_image_mode=False, max_num_hands=1)

        # 퍼블리셔: 전처리된 손 좌표
        self.publisher_ = self.create_publisher(Gesture, 'gesture_preprocessed', 10)

        # 로봇 ID는 하드코딩 또는 param 처리 가능
        self.robot_id = 'robot_1'

        # 프레임 처리 주기 설정 (10Hz = 0.1초)
        self.timer = self.create_timer(0.1, self.process_frame)

    def process_frame(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().warn("프레임 수신 실패")
            return

        image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        results = self.hands.process(image)

        if results.multi_hand_landmarks:
            for hand_landmarks in results.multi_hand_landmarks:
                wrist = hand_landmarks.landmark[0]  # 손목 기준

                # 메시지 구성
                msg = Gesture()
                msg.robot_id = self.robot_id
                msg.point = Point(x=wrist.x, y=wrist.y, z=wrist.z)

                # 퍼블리시
                self.publisher_.publish(msg)
                self.get_logger().info(f"Published: {msg.robot_id}, Point({wrist.x:.2f}, {wrist.y:.2f}, {wrist.z:.2f})")
                break  # 한 손만 처리

    def destroy_node(self):
        self.cap.release()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = GestureReceiveNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
