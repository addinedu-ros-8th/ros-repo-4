#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
import cv2
import mediapipe as mp

class GestureNode(Node):
    def __init__(self):
        super().__init__('gesture_node')
        self.publisher_ = self.create_publisher(Int32, 'vision_server/gesture', 10)

        # MediaPipe 초기화
        self.mp_hands = mp.solutions.hands
        self.hands = self.mp_hands.Hands(static_image_mode=False, max_num_hands=1)
        self.mp_drawing = mp.solutions.drawing_utils

        # OpenCV 초기화
        self.cap = cv2.VideoCapture('udp://192.168.4.1:5000', cv2.CAP_FFMPEG)
        self.running = True  # 루프 중지 플래그
        self.timer = self.create_timer(0.05, self.process_frame)  # 20 FPS

    def classify_hand_gesture(self, landmarks):
        finger_tips = [8, 12, 16, 20]  # index, middle, ring, pinky
        finger_pips = [6, 10, 14, 18]

        fingers_up = [landmarks[tip].y < landmarks[pip].y for tip, pip in zip(finger_tips, finger_pips)]
        thumb_open = landmarks[4].x < landmarks[3].x

        if all(fingers_up) and thumb_open:
            return 1  # Palm
        elif fingers_up[0] and not any(fingers_up[1:]):
            return 2  # Index/Back of Hand
        elif not any(fingers_up) and not thumb_open:
            return 0  # Fist
        else:
            return -1  # Unknown

    def process_frame(self):
        if not self.running:
            return

        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().warn("카메라 프레임을 읽을 수 없습니다.")
            return

        image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        results = self.hands.process(image)

        gesture = -1
        if results.multi_hand_landmarks:
            for hand_landmarks in results.multi_hand_landmarks:
                gesture = self.classify_hand_gesture(hand_landmarks.landmark)
                self.mp_drawing.draw_landmarks(frame, hand_landmarks, self.mp_hands.HAND_CONNECTIONS)

        # 퍼블리시
        if gesture != -1:
            msg = Int32()
            msg.data = gesture
            self.publisher_.publish(msg)
            self.get_logger().info(f"Published gesture: {gesture}")

        # 디버깅 시각화
        cv2.putText(frame, f"Gesture: {gesture}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2)
        cv2.imshow('Hand Gesture', frame)

        # ESC 키 종료
        if cv2.waitKey(1) & 0xFF == 27:
            self.running = False
            self.get_logger().info("ESC 입력 감지. 노드 종료 예정.")
            self.timer.cancel()
            rclpy.shutdown()

    def destroy_node(self):
        self.cap.release()
        cv2.destroyAllWindows()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = GestureNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
