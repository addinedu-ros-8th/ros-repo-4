import sys
import os
import rclpy
from rclpy.node import Node
from PyQt5.QtWidgets import QApplication, QMainWindow
from PyQt5.uic import loadUi
import cv2
from PyQt5.QtGui import QImage, QPixmap
from PyQt5.QtCore import *
from tangerbot_msgs.msg import RobotState  # 메시지 타입
from functools import partial
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure
import mysql.connector

# mydb = mysql.connector.connect(
#     host = "localhost",
#     user = "root",
#     passwd = "0000"
#     database = "tangerine"
# )
# conn = mydb.cursor()

# cursor = conn.cursor()
# results = cursor.fetchall()



class AdminInterface(Node, QMainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        Node.__init__(self, 'admin_interface_gui')

        # UI 파일 로드
        ui_file = os.path.join(os.path.dirname(__file__), '../ui/admin_interface.ui')
        loadUi(ui_file, self)

        # 버튼 이미지 설정
        base_dir = os.path.dirname(__file__)
        self.setButtonImage(self.pushButton_1, os.path.join(base_dir, '../data/47727.jpg'))
        self.setButtonImage(self.pushButton_2, os.path.join(base_dir, '../data/37005.jpg'))
        self.setButtonImage(self.pushButton_3, os.path.join(base_dir, '../data/robot_report.png'))
        self.setButtonImage(self.pushButton_4, os.path.join(base_dir, '../data/report.png'))
        self.setButtonImage(self.pushButton_5, os.path.join(base_dir, '../data/settings.png'))

        # 페이지 버튼 연결
        self.pushButton_1.clicked.connect(lambda: self.changePage(0, self.frame_6))
        self.pushButton_2.clicked.connect(lambda: self.changePage(1, self.frame_7))
        self.pushButton_3.clicked.connect(lambda: self.changePage(2, self.frame_8))
        self.pushButton_4.clicked.connect(lambda: self.changePage(3, self.frame_9))
        self.pushButton_5.clicked.connect(lambda: self.changePage(4, self.frame_10))

        # 상태 매핑
        self.status_labels = {
            "핑키_1번": (self.label_10, self.label_16, self.label_13, self.label_27),
            "핑키_2번": (self.label_11, self.label_28, self.label_14, self.label_30),
            "핑키_3번": (self.label_12, self.label_29, self.label_15, self.label_31),
        }

        # pinky cam 스트림 시작
        # self.start_camera_streams()
        
        self.figure = Figure(figsize=(4, 3))
        self.canvas = FigureCanvas(self.figure)
        self.canvas.setParent(self.label_32)
        self.canvas.move(0, 0)
        self.canvas.resize(self.label_32.size())

        self.mask_image()
        self.label_39.setlabel
        # ComboBox 이벤트 연결
        self.comboBox.currentTextChanged.connect(self.update_graph)

        # RobotState 토픽 구독
        self.create_subscription(RobotState, '/robot_state', self.handle_robot_state, 10)

    def setButtonImage(self, button, image_path):
        button.setStyleSheet(f"""
            QPushButton {{
                border-image: url("{image_path}");
                border: none;
            }}
        """)
    # def worker_time(self):
    #     cursor.excute("SELECT * FROM DailyWorkload WHERE UID, workload")


    # worker_report profile label
    def mask_image(self):
        
        image_files = ['duck.jpg', 'puppy.png', 'dog.jpg']  # 넣고 싶은 이미지 파일들
        labels = [self.label_36, self.label_37, self.label_38]  # 대응하는 QLabel 객체들

        for image_file, label in zip(image_files, labels):
            image_path = os.path.join(os.path.dirname(__file__), '../data/', image_file)
            pixmap = QPixmap(image_path)
            if pixmap.isNull():
                print(f"[에러] 이미지 로딩 실패: {image_path}")
                continue

            scaled_pixmap = pixmap.scaled(
                label.width(), label.height(),
                Qt.KeepAspectRatio, Qt.SmoothTransformation
            )
            label.setPixmap(scaled_pixmap)
            label.setScaledContents(True)

    def changePage(self, index, target_frame):
        self.stackedWidget.setCurrentIndex(index)
        for frame in [self.frame_6, self.frame_7, self.frame_8, self.frame_9, self.frame_10]:
            frame.setStyleSheet("background-color: none;")
        target_frame.setStyleSheet("background-color: #cccccc; border-radius: 5px;")

    def handle_robot_state(self, msg: RobotState):
        robot_id = msg.robot_id
        main_status = msg.main_status
        motion_status = msg.motion_status
        battery = int(msg.battery)

        if robot_id not in self.status_labels:
            return  # 알 수 없는 로봇 ID면 무시

        status_dot, status_text_label, battery_dot, battery_text = self.status_labels[robot_id]

        # 메인 상태 색상
        main_status_map = {
            0: ('대기 중', '#3399ff'),
            1: ('작업 중', '#00cc44'),
            2: ('DEACTIVATE', '#ff3333')
        }
        status_text, color = main_status_map.get(main_status, ('알 수 없음', '#000000'))
        status_dot.setText("●")
        status_dot.setStyleSheet(f"color: {color}; font-size: 16px;")

        # 이동 상태 텍스트
        motion_status_map = {
            0: "이동 중",
            1: "따라가는 중",
            2: "정지 상태",
            3: "적재 중"
        }
        motion_text = motion_status_map.get(motion_status, "알 수 없음")
        status_text_label.setText(motion_text)

        # 배터리 상태
        if battery >= 60:
            battery_color = "#00cc44"
        elif battery >= 20:
            battery_color = "#ffcc00"
        else:
            battery_color = "#ff3333"

        battery_dot.setText("●")
        battery_dot.setStyleSheet(f"color: {battery_color}; font-size: 16px;")
        battery_text.setText(f"{battery}%")

    def start_camera_streams(self):
        self.streams = {
            '핑키_1번': ('udp://192.168.4.1:5000', self.label_22),
            '핑키_2번': ('udp://192.168.4.2:5000', self.label_24),
            '핑키_3번': ('udp://192.168.4.3:5000', self.label_26),
        }

        self.captures = {}
        self.camera_timers = {}

        for robot_name, (url, label) in self.streams.items():
            cap = cv2.VideoCapture(url, cv2.CAP_FFMPEG)
            self.captures[robot_name] = cap

            if not cap.isOpened():
                print(f"[경고] {robot_name} 카메라 스트림 열 수 없음: {url}")
                continue

            timer = QTimer(self)
            timer.timeout.connect(self.make_frame_updater(robot_name, cap, label))
            timer.start(50)
            self.camera_timers[robot_name] = timer

    def make_frame_updater(self, name, cap, label):
        def update():
            if cap.isOpened():
                ret, frame = cap.read()
                if ret:
                    try:
                        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
                        h, w, ch = frame.shape
                        bytes_per_line = ch * w
                        qimg = QImage(frame.data, w, h, bytes_per_line, QImage.Format_RGB888)
                        pixmap = QPixmap.fromImage(qimg)
                        label.setPixmap(pixmap.scaled(label.width(), label.height()))
                    except Exception as e:
                        print(f"[에러] {name} 프레임 처리 실패: {e}")
        return update
    
    def update_graph(self, period):
        # 테스트용 데이터
        import random
        self.figure.clear()
        ax = self.figure.add_subplot(111)

        if period == "weekly":
            labels = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
            data = [random.randint(5, 15) for _ in range(7)]
        elif period == "monthly":
            labels = [f'{i+1}일' for i in range(30)]
            data = [random.randint(10, 20) for _ in range(30)]
        elif period == "yearly":
            labels = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun',
                    'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec']
            data = [random.randint(50, 100) for _ in range(12)]
        else:
            labels = []
            data = []

        ax.bar(labels, data, color="#3399ff")
        ax.set_title(f"{period.capitalize()} 수확량")
        ax.set_ylabel("수확량 (단위)")
        ax.set_xlabel("기간")
        ax.tick_params(axis='x', labelrotation=45)
        self.canvas.draw()

def main(args=None):
    rclpy.init(args=args)
    app = QApplication(sys.argv)
    window = AdminInterface()
    window.show()

    timer = QTimer()
    timer.timeout.connect(lambda: rclpy.spin_once(window, timeout_sec=0))
    timer.start(10)

    app.exec()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
