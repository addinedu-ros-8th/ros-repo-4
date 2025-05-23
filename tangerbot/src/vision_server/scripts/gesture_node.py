#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from tangerbot_msgs.msg import Gesture
from geometry_msgs.msg import Point
import cv2
import mediapipe as mp
import numpy as np
import posix_ipc
import mmap
import struct

class GestureNode(Node):
    def __init__(self):
        super().__init__('gesture_node')
        self.publisher_ = self.create_publisher(Gesture, '/gesture', 10)

        # MediaPipe 초기화
        self.mp_hands = mp.solutions.hands
        self.hands = self.mp_hands.Hands(static_image_mode=False, max_num_hands=1)
        self.mp_drawing = mp.solutions.drawing_utils

        # OpenCV 및 타이머
        self.running = True
        self.timer = self.create_timer(0.05, self.process_frame)  # 20 FPS

        # 공유 메모리 초기화
        self.shm = posix_ipc.SharedMemory("/stereo_shm", flags=0)
        self.seg_size = 9 * (4 + 4 + 56 + (1 << 20))
        self.mapfile = mmap.mmap(self.shm.fd, self.seg_size, access = mmap.ACCESS_READ)
        self.shm.close_fd()

        self.OFFSET_FRAME_ID = 0
        self.OFFSET_SIZE = 4
        self.OFFSET_DATA = 64
        self.MAX_IMG = 1 << 20
        self.SLOT_SIZE = 8 + 56 + (1 << 20)

        self.NUM_CAMERAS = 3
        self.robot_idx = 0
        self.camera_id = 2  # picam

        self.robot_id = "robot1"  # 하드코딩 또는 동적으로 수정 가능

    def read_shared_memory(self):
        BASE_OFFSET = (self.robot_idx * self.NUM_CAMERAS + self.camera_id) * self.SLOT_SIZE

        self.mapfile.seek(BASE_OFFSET + self.OFFSET_FRAME_ID)
        frame_id_1 = struct.unpack('I', self.mapfile.read(4))[0]

        self.mapfile.seek(BASE_OFFSET + self.OFFSET_SIZE)
        size = struct.unpack('I', self.mapfile.read(4))[0]

        if size == 0 or size > self.MAX_IMG:
            self.get_logger().warn(f"Invalid image size: {size}")
            return None, None

        self.mapfile.seek(BASE_OFFSET + self.OFFSET_DATA)
        jpeg_bytes = self.mapfile.read(size)

        self.mapfile.seek(BASE_OFFSET + self.OFFSET_FRAME_ID)
        frame_id_2 = struct.unpack('I', self.mapfile.read(4))[0]

        if frame_id_1 != frame_id_2:
            self.get_logger().warn("Frame changed during read")
            return None, None

        if len(jpeg_bytes) < 2 or jpeg_bytes[:2].hex() != 'ffd8':
            self.get_logger().error(f"Invalid JPEG header: {jpeg_bytes[:10].hex()}")
            return None, None

        img_np = np.frombuffer(jpeg_bytes, dtype=np.uint8)
        img = cv2.imdecode(img_np, cv2.IMREAD_COLOR)
        if img is None:
            self.get_logger().warn("JPEG decoding failed")
            return None, None

        return img, frame_id_1

    def classify_hand_gesture(self, landmarks):
        finger_tips = [8, 12, 16, 20]
        finger_pips = [6, 10, 14, 18]
        fingers_up = [landmarks[tip].y < landmarks[pip].y for tip, pip in zip(finger_tips, finger_pips)]

        thumb_tip = landmarks[4]
        thumb_cmc = landmarks[1]
        thumb_folded = abs(thumb_tip.x - thumb_cmc.x) < 0.05

        if all(fingers_up) and not thumb_folded:
            return 1  # Palm -> COME
        if sum(fingers_up) <= 1 and thumb_folded:
            return 2  # Fist -> STOP
        return -1  # UNKNOWN

    def process_frame(self):
        if not self.running:
            return

        frame, frame_id = self.read_shared_memory()
        if frame is None:
            return

        image_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        results = self.hands.process(image_rgb)

        gesture = -1
        point = Point(x=0.0, y=0.0, z=0.0)

        if results.multi_hand_landmarks:
            hand_landmarks = results.multi_hand_landmarks[0]
            gesture = self.classify_hand_gesture(hand_landmarks.landmark)

            # 좌표 설정 (손목 기준)
            wrist = hand_landmarks.landmark[0]
            point = Point(x=wrist.x, y=wrist.y, z=wrist.z)

            self.mp_drawing.draw_landmarks(image_rgb, hand_landmarks, self.mp_hands.HAND_CONNECTIONS)

        # 퍼블리시
        if gesture != -1:
            msg = Gesture()
            msg.robot_id = self.robot_id
            msg.gesture = gesture  # 0: COME, 1: STOP, 2: BACK
            msg.point = point

            self.publisher_.publish(msg)
            self.get_logger().info(f"Published Gesture - ID: {msg.robot_id}, Type: {gesture}, Point: ({point.x:.2f}, {point.y:.2f}, {point.z:.2f})")

        # 디버깅 시각화
        gesture_labels = {
            1: "COME",
            2: "STOP",
            -1: "UNKNOWN"
        }
        gesture_text = gesture_labels.get(gesture, "❓ UNKNOWN")
        cv2.putText(image_rgb, f"Gesture: {gesture_text}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2)
        cv2.imshow('Hand Gesture', image_rgb)

        # ESC 종료
        if cv2.waitKey(1) & 0xFF == 27:
            self.running = False
            self.get_logger().info("ESC 입력 감지. 노드 종료 예정.")
            self.timer.cancel()
            self.destroy_node()
            rclpy.shutdown()

    def destroy_node(self):
        self.mapfile.close()
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



