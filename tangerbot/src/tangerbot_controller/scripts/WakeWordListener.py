#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import speech_recognition as sr

class WakeWordListener(Node):
    def __init__(self):
        super().__init__('wake_word_listener')
        self.publisher_ = self.create_publisher(String, '/wake_word', 10)
        self.command_publisher_ = self.create_publisher(String, '/voice_command', 10)
        self.recognizer = sr.Recognizer()
        self.mic = sr.Microphone()
        self.trigger_word = "핑키야"
        self.listening = False

        self.get_logger().info("Wake word listener started. Say '핑키야' to activate.")
        self.listen_loop()

    def listen_loop(self):
        while rclpy.ok():
            with self.mic as source:
                self.get_logger().info("Listening...")
                self.recognizer.adjust_for_ambient_noise(source)
                audio = self.recognizer.listen(source)

            try:
                text = self.recognizer.recognize_google(audio, language="ko-KR")
                self.get_logger().info(f"Recognized: {text}")

                if self.trigger_word == text and not self.listening:
                    msg = String()
                    msg.data = self.trigger_word
                    self.publisher_.publish(msg)
                    self.get_logger().info(f"Wake word '{self.trigger_word}' detected. Listening for command...")
                    self.listening = True
                    continue

                if self.listening:
                    command_msg = String()
                    command_msg.data = text
                    self.command_publisher_.publish(command_msg)
                    self.get_logger().info(f"Command published: {text}")
                    self.listening = False

            except sr.UnknownValueError:
                self.get_logger().warn("Could not understand audio.")
            except sr.RequestError as e:
                self.get_logger().error(f"STT request failed: {e}")

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
