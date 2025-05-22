#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String, ByteMultiArray
import speech_recognition as sr
import time
import sounddevice as sd
import numpy as np
import io
import wave
from pinky_interfaces.srv import Emotion
from tangerbot_msgs.srv import HandleRawVoice


SAMPLE_RATE = 16000
FRAME_SIZE = 1024
SILENCE_THRESHOLD = 2  # 2초 침묵 시 종료

class WakeWordListener(Node):
    def __init__(self):
        super().__init__('wake_word_listener')

        # 퍼블리셔
        self.wake_pub_ = self.create_publisher(String, '/wake_word', 10)

        # 감정 서비스 클라이언트
        self.emotion_cli = self.create_client(Emotion, 'set_emotion')
        while not self.emotion_cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('⏳ 감정 서비스 기다리는 중...')
            
        self.voice_cli = self.create_client(HandleRawVoice, 'handle_raw_voice')
        # while not self.voice_cli.wait_for_service(timeout_sec=1.0):
        #     self.get_logger().info('🎙 음성 처리 서비스 기다리는 중...')

        # 음성 인식기 초기화
        self.recognizer = sr.Recognizer()
        self.mic = sr.Microphone(device_index=1)
        self.trigger_word = "핑키야"
        self.listening = False  # 음성 녹음 중인지 확인용

        self.get_logger().info("🔊 Wake word listener 시작됨. '핑키야'라고 말하세요.")

        # 0.1초마다 listen_loop를 비동기로 실행
        self.timer = self.create_timer(0.1, self.listen_loop)

    def listen_loop(self):
        if self.listening:
            return  # 현재 녹음 중이면 skip

        with self.mic as source:
            self.get_logger().info("👂 대기 중...")
            self.recognizer.adjust_for_ambient_noise(source)
            audio = self.recognizer.listen(source)

        try:
            text = self.recognizer.recognize_google(audio, language="ko-KR")
            self.get_logger().info(f"🗣 인식된 텍스트: {text}")

            if self.trigger_word == text:
                self.listening = True

                # 깨우기 메시지 퍼블리시
                wake_msg = String()
                wake_msg.data = self.trigger_word
                self.wake_pub_.publish(wake_msg)
                self.get_logger().info("✅ '핑키야' 감지됨. 사용자 음성 녹음 시작...")

                # 감정 상태 변경 요청 (basic)
                req = Emotion.Request()
                req.emotion = "basic"
                self.emotion_cli.call_async(req)
                self.get_logger().info("📺 감정 상태 'basic' 요청 전송")

                # 사용자 음성 녹음
                audio_np = self.record_until_silence()
                if audio_np is not None:
                    self.send_audio_stream(audio_np)
                else:
                    self.get_logger().warn("⛔ 유효한 음성 없음")
                    req = Emotion.Request()
                    req.emotion = "sad"
                    self.emotion_cli.call_async(req)
                    self.get_logger().info("📺 감정 상태 'sad' 요청 전송")

                self.listening = False

        except sr.UnknownValueError:
            self.get_logger().warn("🤷 음성 인식 실패")
            req = Emotion.Request()
            req.emotion = "sad"
            self.emotion_cli.call_async(req)
            self.get_logger().info("📺 감정 상태 'sad' 요청 전송")

        except sr.RequestError as e:
            self.get_logger().error(f"❌ STT 오류: {e}")
            req = Emotion.Request()
            req.emotion = "sad"
            self.emotion_cli.call_async(req)
            self.get_logger().info("📺 감정 상태 'sad' 요청 전송")

    def record_until_silence(self):
        self.get_logger().info("🎤 말하세요! (2초 침묵 시 종료)")
        buffer = []
        silence_start = None
        speech_detected = False
        start_time = time.time()
        stop_recording = False

        def callback(indata, frames, time_info, status):
            nonlocal buffer, silence_start, speech_detected, start_time, stop_recording
            int_data = (indata[:, 0] * 32767).astype(np.int16)
            frame_bytes = int_data.tobytes()

            if self.is_speech(frame_bytes):
                buffer.append(int_data.copy())
                speech_detected = True
                silence_start = None
            else:
                if speech_detected:
                    buffer.append(int_data.copy())
                if silence_start is None:
                    silence_start = time.time()
                elif time.time() - silence_start > SILENCE_THRESHOLD:
                    stop_recording = True

            if not speech_detected and time.time() - start_time > SILENCE_THRESHOLD:
                stop_recording = True

        try:
            with sd.InputStream(channels=1, samplerate=SAMPLE_RATE, dtype='float32',
                                blocksize=FRAME_SIZE, callback=callback):
                while not stop_recording:
                    time.sleep(0.1)
        except sd.CallbackStop:
            pass

        if not buffer:
            return None

        return np.concatenate(buffer, axis=0)

    def is_speech(self, audio_bytes):
        return np.max(np.frombuffer(audio_bytes, dtype=np.int16)) > 500

    def send_audio_via_service(self, audio_np):
        self.get_logger().info("📤 오디오 바이트 스트림 인코딩 중...")
        buf = io.BytesIO()
        with wave.open(buf, 'wb') as wf:
            wf.setnchannels(1)
            wf.setsampwidth(2)  # 16-bit PCM
            wf.setframerate(SAMPLE_RATE)
            wf.writeframes(audio_np.tobytes())

        byte_data = np.frombuffer(buf.getvalue(), dtype=np.uint8)

        # 📨 서비스 요청 생성
        req = HandleRawVoice.Request()
        req.robot_id = "pinky"
        req.user_id = "user123"
        req.data = ByteMultiArray()
        req.data.data = byte_data.tolist()

        # 🛠 서비스 호출
        future = self.voice_cli.call_async(req)

        def response_callback(future):
            try:
                res = future.result()
                if res.success:
                    self.get_logger().info("✅ 음성 데이터 전송 성공")
                else:
                    self.get_logger().warn("⚠️ 음성 처리 실패")
            except Exception as e:
                self.get_logger().error(f"❌ 서비스 호출 실패: {e}")

        future.add_done_callback(response_callback)

def main(args=None):
    rclpy.init(args=args)
    node = WakeWordListener()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
