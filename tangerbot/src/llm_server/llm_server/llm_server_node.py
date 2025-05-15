import rclpy
from rclpy.node import Node
from std_msgs.msg import ByteMultiArray, String  # 변경된 메시지 타입
import whisper
import io
import wave
import numpy as np
import librosa
from tangerbot_msgs.msg import DecodedVoice
from tangerbot_msgs.srv import HandleRawVoice

# Whisper 모델 로딩 (최초 1회)
whisper_model = whisper.load_model("base")

class AudioToTextNode(Node):
    def __init__(self):
        super().__init__('audio_to_text_node')

        # 음성 스트림 수신 토픽
        self.voice_srv = self.create_service(
            HandleRawVoice,
            'handle_raw_voice',
            self.audio_callback
        )
        
        # 텍스트 전송 퍼블리셔
        self.text_publisher = self.create_publisher(DecodedVoice, '/decoded_voice', 10)

    def audio_callback(self, request, response):
        try:
            self.get_logger().info("🎧 오디오 수신")

            # UInt8MultiArray -> BytesIO
            audio_bytes = bytes(request.audio)
            wav_io = io.BytesIO(audio_bytes)

            # Whisper를 사용하여 음성 텍스트 변환
            recognized_text = self.transcribe_audio(wav_io)

            if recognized_text:
                self.get_logger().info(f"📝 변환된 텍스트: {recognized_text}")
                self.send_text_to_server(recognized_text)
                response.text = recognized_text
            else:
                self.get_logger().warn("❌ 텍스트 변환 실패 또는 음성 없음")
                response.text = ""

        except Exception as e:
            self.get_logger().error(f"🚨 처리 중 오류: {e}")
            response.text = ""
        
        return response


    def transcribe_audio(self, wav_io):
        try:
            # WAV 파일에서 데이터 추출
            with wave.open(wav_io, 'rb') as wf:
                sample_width = wf.getsampwidth()
                sample_rate = wf.getframerate()
                n_channels = wf.getnchannels()
                n_frames = wf.getnframes()
                audio_frames = wf.readframes(n_frames)

            # 16-bit PCM 기준 numpy 배열 변환
            audio_np = np.frombuffer(audio_frames, dtype=np.int16).astype(np.float32) / 32768.0  # Normalize to [-1.0, 1.0]

            # Whisper가 mono 16kHz를 요구함
            if n_channels > 1:
                audio_np = audio_np[::n_channels]  # 간단한 채널 압축 (왼쪽 채널만 사용)

            if sample_rate != 16000:
                self.get_logger().warn(f"⚠️ 샘플레이트 {sample_rate} -> 16000 변환 필요")
                
                audio_np = librosa.resample(audio_np, orig_sr=sample_rate, target_sr=16000)

            # Whisper 입력 준비
            audio_padded = whisper.pad_or_trim(audio_np)
            mel = whisper.log_mel_spectrogram(audio_padded).to(whisper_model.device)

            # 텍스트 추출
            result = whisper_model.decode(mel)
            return result.text

        except Exception as e:
            self.get_logger().error(f"❌ Whisper 변환 실패: {e}")
            return None

    def send_text_to_server(self, text):
        msg = DecodedVoice()
        msg.text = text
        self.text_publisher.publish(msg)
        self.get_logger().info(f"📤 텍스트 전송 완료: {text}")


def main(args=None):
    rclpy.init(args=args)
    node = AudioToTextNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
