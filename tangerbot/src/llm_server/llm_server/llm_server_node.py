import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import whisper
import os

# Whisper 모델 불러오기
whisper_model = whisper.load_model("base")

class AudioToTextNode(Node):
    def __init__(self):
        super().__init__('audio_to_text_node')
        
        # 음성 명령을 받는 토픽 생성
        self.subscription = self.create_subscription(
            String,
            'audio_from_robot',  # 로봇에서 전송한 음성 데이터 받는 토픽
            self.audio_callback,
            10
        )
        
        # 변환된 텍스트를 tangerbot_server로 전송할 퍼블리셔 생성
        self.text_publisher = self.create_publisher(String, 'processed_text', 10)

    def audio_callback(self, msg):
        # 로봇에서 전송된 음성 데이터 경로를 받음 (예시: 파일 경로)
        audio_path = msg.data
        self.get_logger().info(f"🎧 받은 음성 파일 경로: {audio_path}")

        # Whisper를 사용하여 음성을 텍스트로 변환
        recognized_text = self.transcribe_audio(audio_path)
        
        if recognized_text:
            self.get_logger().info(f"📝 변환된 텍스트: {recognized_text}")
            self.send_text_to_server(recognized_text)

    def transcribe_audio(self, audio_path):
        try:
            # Whisper로 음성 파일을 텍스트로 변환
            result = whisper_model.transcribe(audio_path, language='ko')
            recognized_text = result['text']
            return recognized_text
        except Exception as e:
            self.get_logger().error(f"❌ 음성 인식 실패: {e}")
            return None

    def send_text_to_server(self, text):
        # 텍스트를 tangerbot_server로 전송
        msg = String()
        msg.data = text
        self.text_publisher.publish(msg)
        self.get_logger().info(f"✅ 텍스트를 tangerbot_server로 전송: {text}")


def main(args=None):
    rclpy.init(args=args)

    # AudioToTextNode 생성
    audio_to_text_node = AudioToTextNode()

    # ROS 2 이벤트 루프 실행
    rclpy.spin(audio_to_text_node)

    # 종료 시 노드 파괴
    audio_to_text_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
    



'''import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class TangerbotServer(Node):
    def __init__(self):
        super().__init__('tangerbot_server')
        
        # 'processed_text' 토픽을 구독하여 텍스트 메시지 처리
        self.subscription = self.create_subscription(
            String,
            'processed_text',  # 'audio_to_text_node'에서 보낸 텍스트를 받는 토픽
            self.process_text_callback,
            10
        )

    def process_text_callback(self, msg):
        text = msg.data
        self.get_logger().info(f"받은 텍스트: {text}")
        # 여기서 텍스트를 처리하고 로봇의 동작이나 명령을 실행하는 로직 추가

def main(args=None):
    rclpy.init(args=args)

    tangerbot_server_node = TangerbotServer()

    rclpy.spin(tangerbot_server_node)

    tangerbot_server_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()'''