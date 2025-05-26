#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from tangerbot_msgs.msg import RawVoice  # RawVoice 메시지 임포트
from pinky_interfaces.srv import Emotion

import speech_recognition as sr
import time
import sounddevice as sd
import numpy as np
import io
import wave

SAMPLE_RATE = 16000
FRAME_SIZE = 1024
SILENCE_THRESHOLD = 2  # 2초 침묵 시 종료

class WakeWordListener(Node):
    def __init__(self):
        super().__init__('wake_word_listener')

        self.wake_pub_ = self.create_publisher(String, '/wake_word', 10)
        self.raw_voice_pub_ = self.create_publisher(RawVoice, '/raw_voice', 10)  # ✅ 퍼블리셔 추가

        # 감정 서비스 클라이언트
        self.emotion_cli = self.create_client(Emotion, 'set_emotion')
        while not self.emotion_cli.wait_for_service(timeout_sec=1.0):
<<<<<<< HEAD
            self.get_logger().info('감정 서비스 기다리는 중...')
=======
            self.get_logger().info('⏳ 감정 서비스 기다리는 중...')
            
        self.voice_cli = self.create_client(HandleRawVoice, 'handle_raw_voice')
        # while not self.voice_cli.wait_for_service(timeout_sec=1.0):
        #     self.get_logger().info('🎙 음성 처리 서비스 기다리는 중...')
>>>>>>> dev

        self.recognizer = sr.Recognizer()
        self.mic = sr.Microphone(device_index=1)
        self.trigger_word = "핑키야"
        self.listening = False

        self.get_logger().info("Wake word listener 시작됨. '핑키야'라고 말하세요.")
        self.timer = self.create_timer(0.1, self.listen_loop)

    def listen_loop(self):
        if self.listening:
            return

        with self.mic as source:
            self.get_logger().info("대기 중...")
            self.recognizer.adjust_for_ambient_noise(source)
            audio = self.recognizer.listen(source)

        try:
            text = self.recognizer.recognize_google(audio, language="ko-KR")
            self.get_logger().info(f"인식된 텍스트: {text}")

            if self.trigger_word == text:
                self.listening = True

                # wake word 퍼블리시
                wake_msg = String()
                wake_msg.data = self.trigger_word
                self.wake_pub_.publish(wake_msg)

                # 감정 상태 'basic' 요청
                req = Emotion.Request()
                req.emotion = "basic"
                self.emotion_cli.call_async(req)

                # 음성 녹음
                audio_np = self.record_until_silence()
                if audio_np is not None:
                    self.publish_raw_voice(audio_np)
                else:
                    self.get_logger().warn("❌ 유효한 음성 없음")
                    req = Emotion.Request()
                    req.emotion = "sad"
                    self.emotion_cli.call_async(req)

                self.listening = False

        except sr.UnknownValueError:
            self.get_logger().warn("🤷 음성 인식 실패")
            req = Emotion.Request()
            req.emotion = "sad"
            self.emotion_cli.call_async(req)

        except sr.RequestError as e:
            self.get_logger().error(f"❌ STT 오류: {e}")
            req = Emotion.Request()
            req.emotion = "sad"
            self.emotion_cli.call_async(req)

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

    def publish_raw_voice(self, audio_np):
        self.get_logger().info("오디오 데이터 WAV 인코딩 중...")

        buf = io.BytesIO()
        with wave.open(buf, 'wb') as wf:
            wf.setnchannels(1)
            wf.setsampwidth(2)  # 16-bit PCM
            wf.setframerate(SAMPLE_RATE)
            wf.writeframes(audio_np.tobytes())

        wav_bytes = buf.getvalue()
        wav_uint8_array = np.frombuffer(wav_bytes, dtype=np.uint8)

        # ✅ RawVoice 메시지 생성 및 퍼블리시
        msg = RawVoice()
        msg.robot_id = "pinky"
        msg.data = list(wav_uint8_array)

        self.get_logger().info(f"퍼블리시 준비 완료 - 길이: {len(msg.data)} bytes")
        self.raw_voice_pub_.publish(msg)
        self.get_logger().info("RawVoice 메시지 퍼블리시 완료")

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
