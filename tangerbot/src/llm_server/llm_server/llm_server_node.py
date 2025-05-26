#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import whisper
import io
import wave
import numpy as np
import librosa

from tangerbot_msgs.msg import RawVoice, DecodedVoice  # ✅ 메시지 타입 수정

# Whisper 모델 로딩 (최초 1회)
whisper_model = whisper.load_model("base", device="cpu")

class AudioToTextNode(Node):
    def __init__(self):
        super().__init__('audio_to_text_node')

        # ✅ RawVoice 메시지 구독
        self.voice_subscriber = self.create_subscription(
            RawVoice,
            '/raw_voice',
            self.audio_callback,
            10
        )

        self.text_publisher = self.create_publisher(DecodedVoice, '/decoded_voice', 10)

        self.get_logger().info("오디오 텍스트 변환 노드 시작됨")

    def audio_callback(self, msg: RawVoice):
        try:
            self.get_logger().info(f"오디오 수신: robot_id={msg.robot_id}, 크기={len(msg.data)} bytes")

            audio_bytes = bytes(msg.data)  # ✅ 직접 변환 가능

            wav_io = io.BytesIO(audio_bytes)
            recognized_text = self.transcribe_audio(wav_io)

            if recognized_text:
                self.get_logger().info(f"변환된 텍스트: {recognized_text}")
                self.send_text_to_server(recognized_text)
            else:
                self.get_logger().warn("❌ 텍스트 변환 실패 또는 음성 없음")

        except Exception as e:
            self.get_logger().error(f"❌ 처리 중 오류: {e}")

    def transcribe_audio(self, wav_io):
        try:
            with wave.open(wav_io, 'rb') as wf:
                sample_width = wf.getsampwidth()
                sample_rate = wf.getframerate()
                n_channels = wf.getnchannels()
                n_frames = wf.getnframes()
                audio_frames = wf.readframes(n_frames)

            audio_np = np.frombuffer(audio_frames, dtype=np.int16).astype(np.float32) / 32768.0

            if n_channels > 1:
                audio_np = audio_np[::n_channels]

            if sample_rate != 16000:
                self.get_logger().warn(f"샘플레이트 {sample_rate} → 16000 변환")
                audio_np = librosa.resample(audio_np, orig_sr=sample_rate, target_sr=16000)

            audio_padded = whisper.pad_or_trim(audio_np)
            mel = whisper.log_mel_spectrogram(audio_padded).to(whisper_model.device)

            result = whisper_model.decode(mel)
            return result.text

        except Exception as e:
            self.get_logger().error(f"❌ Whisper 변환 실패: {e}")
            return None

    def send_text_to_server(self, text):
        msg = DecodedVoice()
        msg.text = text
        self.text_publisher.publish(msg)
        self.get_logger().info(f"텍스트 전송 완료: {text}")

def main(args=None):
    rclpy.init(args=args)
    node = AudioToTextNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
