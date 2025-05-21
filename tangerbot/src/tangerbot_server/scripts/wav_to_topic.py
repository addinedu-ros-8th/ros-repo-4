#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import ByteMultiArray
import sys
import os

class WavPublisher(Node):
    def __init__(self, wav_path):
        super().__init__('wav_publisher')
        self.publisher_ = self.create_publisher(ByteMultiArray, '/raw_audio', 10)

        if not os.path.exists(wav_path):
            self.get_logger().error(f'파일이 존재하지 않습니다: {wav_path}')
            rclpy.shutdown()
            return

        with open(wav_path, 'rb') as f:
            wav_bytes = f.read()

        msg = ByteMultiArray()
        # ✅ 핵심 수정: data에 bytes를 직접 할당 (Python bytes → C Byte[])
        msg.data = wav_bytes

        self.get_logger().info(f'{wav_path} 파일을 퍼블리시 중...')
        self.publisher_.publish(msg)
        self.get_logger().info(f'퍼블리시 완료')
        rclpy.shutdown()


def main():
    rclpy.init()

    if len(sys.argv) != 2:
        print("❗ 사용법: ros2 run tangerbot_server wav_to_topic.py <wav 파일 경로>")
        return

    wav_path = sys.argv[1]
    node = WavPublisher(wav_path)
    rclpy.spin(node)

if __name__ == '__main__':
    main()
