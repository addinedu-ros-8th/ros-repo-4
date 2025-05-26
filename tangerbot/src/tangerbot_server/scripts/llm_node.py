#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import re

from tangerbot_msgs.msg import DecodedVoice
from tangerbot_msgs.srv import HandleCommand  # 수정된 서비스 사용

class tangerbotServer(Node):
    def __init__(self):
        super().__init__('llm_node')

        self.subscription = self.create_subscription(
            DecodedVoice,
            '/decoded_voice',
            self.process_text_callback, 
            10
        )

        self.cli = self.create_client(HandleCommand, 'handle_command')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('📡 handle_command 서비스 대기 중...')

        self.get_logger().info("LLM Node 시작됨 - '/decoded_voice' 구독 중, 'handle_command' 서비스 호출 준비됨")

        self.declare_parameter('robot_id', 'robot1')  # 기본값 설정
        self.declare_parameter('user_id', 'user1')
        self.robot_id = self.get_parameter('robot_id').get_parameter_value().string_value
        self.user_id = self.get_parameter('user_id').get_parameter_value().string_value

    def get_robot_id(self):
        return self.robot_id
    
    def get_user_id(self):
        return self.user_id

    def process_text_callback(self, msg):
        text = msg.text
        user_id = self.get_user_id()
        robot_id = self.get_robot_id()

        self.get_logger().info(f"받은 텍스트: {text}")

        command = self.analyze_command(text)
        action_type = self.map_action_to_type(command["action"])
        area_number = self.extract_area_number(command["area"])

        if action_type is not None:
            req = HandleCommand.Request()
            req.robot_id = robot_id
            req.user_id = user_id
            req.type = action_type
            req.data = f"section{area_number}" if area_number is not None else ""

            future = self.cli.call_async(req)
            future.add_done_callback(self.handle_response)

            self.get_logger().info(f"명령 전송: {req}")
            # self.get_logger("%s, %s, %s, %s", req.robot_id, req.user_id, req.type, req.data)
        else:
            self.get_logger().info("❌ 명령을 이해하지 못했습니다.")

    def handle_response(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info("명령 처리 성공!")
            else:
                self.get_logger().warn("❌ 명령 처리 실패!")
        except Exception as e:
            self.get_logger().error(f"❌ 서비스 호출 실패: {e}")

    def analyze_command(self, text):
        text = self.convert_korean_number(text)

        area_match = re.search(r'(\d+\s*(번\s*구역|구역|번|번으로|로)|구역\s*[-]?\s*\d+)', text)
        area = None
        if area_match:
            number_match = re.search(r'\d+', area_match.group())
            if number_match:
                area = f"구역-{number_match.group()}"

        action_map = {
            '이동': ['이동', '이동해', '가', '가줘', '출발', '들어가'],
            '정지': ['멈춰', '정지', '스탑', '서'],
            '따라와': ['따라와', '따라오다', '같이', '함께', '같이 가자'],
            '복귀': ['돌아가', '복귀', '리턴', '되돌아가']
        }

        action = None
        for key, synonyms in action_map.items():
            if any(word in text for word in synonyms):
                action = key
                break

        return {"action": action, "area": area}

    def map_action_to_type(self, action):
        if action == "이동":
            return HandleCommand.Request.MOVETOSECTION
        elif action == "따라와":
            return HandleCommand.Request.FOLLOWING
        elif action == "정지":
            return HandleCommand.Request.STOP
        elif action == "복귀":
            return HandleCommand.Request.RETURN
        return None

    def extract_area_number(self, area_str):
        if area_str:
            match = re.search(r'\d+', area_str)
            if match:
                return int(match.group())
        return None

    def convert_korean_number(self, text):
        units = {'천': 1000, '백': 100, '십': 10}
        nums = {'공': 0, '영': 0, '일': 1, '이': 2, '삼': 3, '사': 4, '오': 5,
                '육': 6, '칠': 7, '팔': 8, '구': 9}
        def korean_to_number(kor_num):
            result = 0
            tmp = 0
            num = 0
            for char in kor_num:
                if char in nums:
                    num = nums[char]
                elif char in units:
                    if num == 0:
                        num = 1
                    tmp += num * units[char]
                    num = 0
            return tmp + num

        return re.sub(r'([일이삼사오육칠팔구십백천]+)(?=\s*(구역|번|번으로|로))', lambda m: str(korean_to_number(m.group(1))), text)

def main(args=None):
    rclpy.init(args=args)
    node = tangerbotServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
