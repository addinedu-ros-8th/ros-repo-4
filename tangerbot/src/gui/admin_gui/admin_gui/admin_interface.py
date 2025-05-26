import sys
import os
import rclpy
from rclpy.node import Node
from PyQt5.QtWidgets import QApplication, QMainWindow
from PyQt5.uic import loadUi
import cv2
from PyQt5.QtGui import QImage, QPixmap
from PyQt5.QtCore import *
from tangerbot_msgs.msg import RobotState, RobotPose  # 메시지 타입
from functools import partial
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure
from PyQt5.QtCore import Qt, QTimer
from PyQt5.QtGui import QPainter, QPen, QColor, QPolygonF, QTransform, QFont
from PyQt5.QtCore import QPointF, Qt
import math
import mysql.connector
import threading
import numpy as np
import socket
import struct
from PyQt5.QtWidgets import QTableWidgetItem, QHeaderView
from PyQt5.QtCore import pyqtSignal, QObject
import random
from PyQt5.QtWidgets import QWidget


class HarvestCircle(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self._value = 0  # 수확량 퍼센트

    def set_value(self, value):
        self._value = max(0, min(100, value))
        self.update()

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing)

        size = min(self.width(), self.height())
        margin = 10
        diameter = size - 2 * margin

        rect = QRectF(
            (self.width() - diameter) / 2,
            (self.height() - diameter) / 2,
            diameter,
            diameter
        )

        start_angle = int(90 * 16)
        span_angle = int(-self._value * 360 / 100 * 16)

        painter.setPen(QPen(Qt.lightGray, 10))
        painter.drawArc(rect, 0, 360 * 16)

        painter.setPen(QPen(Qt.green, 10))
        painter.drawArc(rect, start_angle, span_angle)

        painter.setPen(Qt.white)
        painter.setFont(QFont("Arial", 14, QFont.Bold))
        # rect_top = QRectF(self.rect().x(), self.rect().y(), self.rect().width(), self.rect().height() / 2)
        # rect_bottom = QRectF(self.rect().x(), self.rect().y() + self.rect().height() / 2, self.rect().width(), self.rect().height() / 2)

        # painter.drawText(rect_top, Qt.AlignCenter, "수확량")
        # painter.setFont(QFont("Arial", 14, QFont.Bold))  # 퍼센트는 글씨 좀 더 크게
        painter.drawText(self.rect(), Qt.AlignCenter, f"수확량\n{self._value}%")

class AdminInterface(Node, QMainWindow):
    HEADER_FORMAT = '<BBBIHHI'  # little-endian: magic, robot_id, camera_id, frame_id, total_chunks, chunk_id, chunk_size
    HEADER_SIZE = struct.calcsize(HEADER_FORMAT)
    image_received = pyqtSignal(int, int, QPixmap)
    update_text_signal = pyqtSignal(str)

    def __init__(self):
        QMainWindow.__init__(self)
        Node.__init__(self, 'admin_interface_gui')
        
        # UI 파일 로드
        ui_file = os.path.join(os.path.dirname(__file__), '../ui/admin_interface.ui')
        loadUi(ui_file, self)

        
        self.show_map_image()
        
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind(('0.0.0.0', 14555))  # 예시 포트

        self.buffers = {}  # {(robot_id, frame_id): [None]*total_chunks}
        self.meta = {}     # {(robot_id, frame_id): (received_chunks, total_chunks)}

        threading.Thread(target=self.receive_loop, daemon=True).start()
        
        self.image_received.connect(self.on_image_received)
        
        image_path = os.path.join(os.path.dirname(__file__), '../data/tangermap_fix.png')
        self.original_map_pixmap = QPixmap(image_path)
        if self.original_map_pixmap.isNull():
            print("[에러] 지도 이미지 로딩 실패")
            return

        # 수확량
        self.harvest_circle = HarvestCircle(self.widget)
        self.harvest_circle.setGeometry(0, 0, self.widget.width(), self.widget.height())
        self.harvest_circle.show()
        # self.widget.hide()
        self.harvest_circle.set_value(40)
        
        # 로봇 위치 저장 dict {robot_id: Pose}
        self.robot_poses = {}

        # ROS 구독: RobotPose 메시지
        self.create_subscription(RobotPose, '/robot_pose', self.handle_robot_pose, 10)

        # 지도 + 로봇 위치 표시
        self.update_map_with_robots()
        
        # log connect with db
        self.load_log_data()

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
            "robot1": (self.label_10, self.label_16, self.label_13, self.label_27),
            "robot2": (self.label_11, self.label_28, self.label_14, self.label_30),
            "robot3": (self.label_12, self.label_29, self.label_15, self.label_31),
        }
        
        self.figure = Figure(figsize=(4, 3))
        self.canvas = FigureCanvas(self.figure)
        self.canvas.setParent(self.label_32)
        self.canvas.move(0, 0)
        self.canvas.resize(self.label_32.size())

        self.mask_image()
        self.label_39.setText
        
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
    
    
    def show_map_image(self):
        image_path = os.path.join(os.path.dirname(__file__), '../data/tangermap_fix.png')
        print("로드 시도 이미지 경로:", image_path)

        pixmap = QPixmap(image_path)
        if pixmap.isNull():
            print("[에러] 이미지 로딩 실패:", image_path)
            return

        target_width = 658
        target_height = 291

        self.label_17.setFixedSize(target_width, target_height)

        scaled_pixmap = pixmap.scaled(target_width, target_height, Qt.IgnoreAspectRatio, Qt.SmoothTransformation)
        self.label_17.setPixmap(scaled_pixmap)
        self.label_17.setScaledContents(True)  # 또는 False로 두되 크기 맞추기
        self.label_17.repaint()


    # worker_report profile label
    def mask_image(self):
        base_dir = os.path.dirname(os.path.abspath(__file__))
        image_files = [
            os.path.join(base_dir, '../data/duck.jpg'),
            os.path.join(base_dir, '../data/puppy.png'),
            os.path.join(base_dir, '../data/cat.jpg')
        ]
        labels = [self.label_36, self.label_37, self.label_38]

        for image_path, label in zip(image_files, labels):
            pixmap = QPixmap(image_path)
            
            if pixmap.isNull():
                print(f"[에러] 이미지 로딩 실패: {image_path}")
                continue

            label.setPixmap(pixmap)
            label.setScaledContents(True) 
            
    def ros_to_image_coords(self, x, y):
        # 원본 지도 기준
        origin_x, origin_y = 0.0, 0.0
        resolution = 0.01  # 1픽셀 = 1cm = 0.01m

        # 원본 이미지 크기
        orig_w = 279
        orig_h = 174

        # 라벨에 표시되는 실제 이미지 크기 (tangermap_fix.png)
        display_w = self.label_17.width()
        display_h = self.label_17.height()

        # ROS 좌표 → 원본 이미지 좌표
        px = (x - origin_x) / resolution
        py = (y - origin_y) / resolution
        py = orig_h - py  # Y축 반전

        # 원본 좌표 → 표시 이미지 좌표 (스케일링)
        scale_x = display_w / orig_w
        scale_y = display_h / orig_h


        scale = min(scale_x, scale_y)  # KeepAspectRatio 기반
        margin_x = (display_w - orig_w * scale) / 2
        margin_y = (display_h - orig_h * scale) / 2

        px_scaled = int(px * scale + margin_x)
        py_scaled = int(py * scale + margin_y)

        return px_scaled, py_scaled


    def quaternion_to_yaw(self, q):
        siny_cosp = 2 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
        return math.atan2(siny_cosp, cosy_cosp)


    def draw_robot_triangle(self, painter, x, y, yaw):
        size = 15
        yaw += math.radians(-90)
        points = [
            QPointF(0, -size),
            QPointF(size / 2, size / 2),
            QPointF(-size / 2, size / 2)
        ]
        rotated_points = []
        for p in points:
            mirrored_x = -p.x()
            rx = p.x() * math.cos(-yaw) - p.y() * math.sin(-yaw)
            ry = p.x() * math.sin(-yaw) + p.y() * math.cos(-yaw)
            rotated_points.append(QPointF(x + rx, y + ry))
    
        polygon = QPolygonF(rotated_points)
        painter.setBrush(QColor(255, 0, 0, 180))  # 반투명 빨강
        painter.drawPolygon(polygon)


    def handle_robot_pose(self, msg):
        # ROS RobotPose 메시지: msg.robot_id, msg.pose (PoseStamped)
        self.robot_poses[msg.robot_id] = msg.pose.pose

        # 갱신된 위치로 지도 업데이트
        self.update_map_with_robots()


    def update_map_with_robots(self):
        label_w = self.label_17.width()
        label_h = self.label_17.height()

        # 1) 원본 이미지 한 번만 스케일링 (KeepAspectRatio)
        scaled_pixmap = self.original_map_pixmap.scaled(
            label_w, label_h,
            Qt.KeepAspectRatio,
            Qt.SmoothTransformation
        )

        # 2) 스케일된 이미지 복사해서 그리기용으로 만듦
        pixmap_to_paint = QPixmap(scaled_pixmap)  # 복사본

        painter = QPainter(pixmap_to_paint)
        painter.setRenderHint(QPainter.Antialiasing)

        pen = QPen(QColor(255, 0, 0))
        pen.setWidth(3)
        painter.setPen(pen)

        # 3) 여백 계산 (라벨 크기 - 이미지 크기)
        margin_x = (label_w - scaled_pixmap.width()) / 2
        margin_y = (label_h - scaled_pixmap.height()) / 2

        # 4) 원본 이미지 크기 기준
        orig_w = self.original_map_pixmap.width()
        orig_h = self.original_map_pixmap.height()

        # 스케일 비율 (KeepAspectRatio이므로 동일)
        scale = scaled_pixmap.width() / orig_w  # 또는 height도 같음

        origin_x, origin_y = 0.0, 0.0
        resolution_y = 0.006
        resolution_x = 0.0045

        for robot_id, pose in self.robot_poses.items():
            x = pose.position.x
            y = pose.position.y
            yaw = self.quaternion_to_yaw(pose.orientation)

            # ROS 좌표 → 원본 이미지 픽셀 좌표
            px = (x - origin_x) / resolution_x
            py = (y - origin_y) / resolution_y
            py = orig_h - py  # y 반전

            # 스케일 적용 후 여백 보정
            px_scaled = int(px * scale + margin_x)
            py_scaled = int(py * scale + margin_y)

            self.draw_robot_triangle(painter, px_scaled, py_scaled, yaw)

        painter.end()

        # 5) 그려진 이미지 라벨에 세팅, 스케일링 다시 안 함
        self.label_17.setPixmap(pixmap_to_paint)
        self.label_17.setScaledContents(False)


    def load_log_data(self):
        self.tableWidget.setRowCount(0)
        self.tableWidget.setColumnCount(6)
        self.tableWidget.setHorizontalHeaderLabels(['LogID','UserID', 'robot ID', 'section', 'command', 'time'])
        conn = None
        try:
            conn = mysql.connector.connect(
                host='127.0.0.1',
                port=3306,
                user='root',
                password='0119',
                database='tgdb',
                charset='utf8mb4'
            )
            cursor = conn.cursor()
            cursor.execute("SELECT * FROM Log ORDER BY LID")
            results = cursor.fetchall()

            print("[디버그] 결과 수:", len(results))
            self.tableWidget.setRowCount(len(results))
            for row_idx, row_data in enumerate(results):
                print(f"[디버그] row {row_idx}:", row_data)
                
                for col_idx, value in enumerate(row_data):
                    self.tableWidget.setItem(row_idx, col_idx, QTableWidgetItem(str(value)))
            self.tableWidget.resizeColumnsToContents()
            self.tableWidget.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
            self.tableWidget.repaint()
            
        except Exception as e:
            import traceback
            print("[에러] DB 연결 또는 쿼리 실패:", e)
            traceback.print_exc()
            
        finally:
            if conn is not None and conn.is_connected():
                conn.close()

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
            return

        status_dot, status_text_label, battery_dot, battery_text = self.status_labels[robot_id]

        main_status_map = {
            0: ('대기 중', '#3399ff'),
            1: ('작업 중', '#00cc44'),
            2: ('DEACTIVATE', '#ff3333')
        }
        status_text, color = main_status_map.get(main_status, ('알 수 없음', '#000000'))
        status_dot.setText("●")
        status_dot.setStyleSheet(f"color: {color}; font-size: 16px;")

        motion_status_map = {
            0: "이동 중",
            1: "따라가는 중",
            2: "정지 상태",
            3: "적재 중"
        }
        motion_text = motion_status_map.get(motion_status, "알 수 없음")
        status_text_label.setText(motion_text)

        if battery >= 60:
            battery_color = "#00cc44"
        elif battery >= 20:
            battery_color = "#ffcc00"
        else:
            battery_color = "#ff3333"

        battery_dot.setText("●")
        battery_dot.setStyleSheet(f"color: {battery_color}; font-size: 16px;")
        battery_text.setText(f"{battery}%")

    def receive_loop(self):
        while True:
            try:
                data, _ = self.sock.recvfrom(14555)
                header = data[:self.HEADER_SIZE]
                magic, robot_id, camera_id, frame_id, total_chunks, chunk_id, chunk_size = struct.unpack(self.HEADER_FORMAT, header)

                if magic != 0xAA:
                    continue

                chunk_data = data[self.HEADER_SIZE:self.HEADER_SIZE + chunk_size]
                key = (robot_id, frame_id)

                if key not in self.buffers:
                    self.buffers[key] = [None] * total_chunks
                    self.meta[key] = [0, total_chunks]

                if self.buffers[key][chunk_id] is None:
                    self.buffers[key][chunk_id] = chunk_data
                    self.meta[key][0] += 1

                if self.meta[key][0] == total_chunks:
                    full_data = b''.join(self.buffers[key])
                    del self.buffers[key]
                    del self.meta[key]

                    nparr = np.frombuffer(full_data, np.uint8)
                    frame = cv2.imdecode(nparr, cv2.IMREAD_UNCHANGED)
                    if frame is None:
                        print(f"[에러] OpenCV 디코딩 실패: robot {robot_id} cam {camera_id}")
                        continue

                    frame = frame.copy()
                    h, w = frame.shape[:2]
                    ch = frame.shape[2] if len(frame.shape) == 3 else 1
                    bytes_per_line = ch * w

                    if ch == 4:
                        frame = cv2.cvtColor(frame, cv2.COLOR_BGRA2RGB)
                        qimg = QImage(frame.data, w, h, bytes_per_line, QImage.Format_ARGB32)
                    elif ch == 3:
                        qimg = QImage(frame.data, w, h, bytes_per_line, QImage.Format_RGB888)
                    else:
                        print(f"[에러] 알 수 없는 채널 수: {ch}")
                        continue

                    qimg = qimg.copy()
                    pixmap = QPixmap.fromImage(qimg)
                    self.image_received.emit(robot_id, camera_id, pixmap)

            except socket.timeout:
                continue
            except Exception as e:
                print(f"[에러] 이미지 처리 실패: robot {robot_id} cam {camera_id}, 오류: {e}")

    def on_image_received(self, robot_id, cam_id, pixmap):
        label_map = {
            1: self.label_22,
            2: self.label_24,
            3: self.label_26
        }
        label = label_map.get(robot_id)
        if label:
            label.setScaledContents(False)  # 명확하게 설정
            print(f"라벨 크기: {label.width()} x {label.height()}")
            print(f"수신된 영상 크기: {pixmap.width()} x {pixmap.height()}")
            scaled_pixmap = pixmap.scaled(label.size(), Qt.KeepAspectRatio, Qt.SmoothTransformation)
            label.setPixmap(scaled_pixmap)

    def update_graph(self, period):
        self.figure.clear()
        ax = self.figure.add_subplot(111)

        if period == "weekly":
            labels = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
            data = [random.randint(5, 15) for _ in range(7)]
        elif period == "monthly":
            labels = [f'{i+1}day' for i in range(30)]
            data = [random.randint(10, 20) for _ in range(30)]
        elif period == "yearly":
            labels = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec']
            data = [random.randint(50, 100) for _ in range(12)]
        else:
            labels = []
            data = []

        ax.bar(labels, data, color="#3399ff")
        ax.set_title(f"{period.capitalize()} harvest")
        ax.set_ylabel("harvest (kg)")
        ax.set_xlabel("period")
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