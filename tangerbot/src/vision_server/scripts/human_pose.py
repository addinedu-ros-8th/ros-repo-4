#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PointStamped

import cv2
import torch
import numpy as np
from ultralytics import YOLO
from deep_sort_realtime.deepsort_tracker import DeepSort
from torchvision.ops import box_iou
from scipy.optimize import linear_sum_assignment
import posix_ipc
import mmap
import struct
import time

class HumanPose(Node):
    def __init__(self):
        super().__init__('human_pose')
        self.pub = self.create_publisher(PointStamped, 'object_pixel', 10)

        timer_period = 1.0 / 30.0
        self.publish_timer = self.create_timer(timer_period, self.publish_pixel)
        self.display_timer = self.create_timer(timer_period, self.display_image)

        # Deep Learning 초기화
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        print(f"[INFO] Using device: {self.device}")
        self.model = YOLO("yolov8l-seg.pt").to(self.device)
        self.tracker = DeepSort(max_age = 70, n_init = 3, max_cosine_distance = 0.3, nn_budget = 100)
        self.TARGET_ID = None  # 추적할 대상 ID

        # 공유 메모리 초기화
        self.shm = posix_ipc.SharedMemory("/stereo_shm", flags=0)
        self.seg_size = 2 * (4 + 4 + 56 + (1 << 20))  # 패딩 포함
        self.mapfile = mmap.mmap(self.shm.fd, self.seg_size, access=mmap.ACCESS_READ)
        self.shm.close_fd()

        # 디코딩 오프셋
        self.OFFSET_FRAME_ID = 0
        self.OFFSET_SIZE = 4
        self.OFFSET_DATA = 64  # alignas(64)로 인한 패딩
        self.MAX_IMG = 1 << 20
        self.SLOT_SIZE = 8 + 56 + (1 << 20)  # frame_id(4) + size(4) + padding(56) + data

        # 이미지 저장용 변수
        self.current_frame = None
        self.current_frame_id = None

    def get_center_distance(self, x1, y1, x2, y2, img_w, img_h):
        """이미지 중심과 바운딩 박스 중심 간의 거리 계산"""
        box_cx = (x1 + x2) / 2
        box_cy = (y1 + y2) / 2
        img_cx = img_w / 2
        img_cy = img_h / 2
        return np.hypot(box_cx - img_cx, box_cy - img_cy)

    def read_shared_memory(self):
        """공유 메모리에서 이미지 읽기"""
        camera_id = 0  # cam[0] 사용
        BASE_OFFSET = camera_id * self.SLOT_SIZE

        self.mapfile.seek(BASE_OFFSET + self.OFFSET_FRAME_ID)
        frame_id_1 = struct.unpack('I', self.mapfile.read(4))[0]

        self.mapfile.seek(BASE_OFFSET + self.OFFSET_SIZE)
        size = struct.unpack('I', self.mapfile.read(4))[0]

        if size == 0 or size > self.MAX_IMG:
            self.get_logger().warn(f"Invalid image size: {size}")
            return None, None

        self.mapfile.seek(BASE_OFFSET + self.OFFSET_DATA)
        jpeg_bytes = self.mapfile.read(size)

        self.mapfile.seek(BASE_OFFSET + self.OFFSET_FRAME_ID)
        frame_id_2 = struct.unpack('I', self.mapfile.read(4))[0]

        if frame_id_1 != frame_id_2:
            self.get_logger().warn("Frame changed during read")
            return None, None

        if len(jpeg_bytes) < 2 or jpeg_bytes[:2].hex() != 'ffd8':
            self.get_logger().error(f"Invalid JPEG header: {jpeg_bytes[:10].hex()}")
            return None, None

        img_np = np.frombuffer(jpeg_bytes, dtype=np.uint8)
        img = cv2.imdecode(img_np, cv2.IMREAD_COLOR)
        if img is None:
            self.get_logger().warn("JPEG decoding failed → check data integrity")
            return None, None

        return img, frame_id_1

    def detect_target(self):
        """YOLOv8-seg와 DeepSORT로 대상 검출 및 추적"""
        if self.current_frame is None:
            return 320, 240  # 기본값 반환

        start_time = time.time()
        frame = self.current_frame
        h, w = frame.shape[:2]

        # YOLOv8-seg 예측
        results = self.model(frame)
        boxes = results[0].boxes
        masks = results[0].masks

        detections = []
        yolo_boxes = []
        yolo_indices = []
        center_distances = []

        # 사람 클래스(클래스 0)만 처리
        if boxes is not None:
            for i, cls in enumerate(boxes.cls):
                if int(cls) == 0:  # 사람 클래스
                    x1, y1, x2, y2 = boxes.xyxy[i].cpu().numpy()
                    conf = float(boxes.conf[i])
                    yolo_boxes.append([x1, y1, x2, y2])
                    detections.append(([x1, y1, x2 - x1, y2 - y1], conf, 'person'))
                    yolo_indices.append(i)
                    center_distances.append(self.get_center_distance(x1, y1, x2, y2, w, h))

        # DeepSORT 추적
        tracks = self.tracker.update_tracks(detections, frame=frame)

        # 중심 좌표 계산
        u, v = 320, 240  # 기본값
        if tracks and yolo_boxes:
            yolo_tensor = torch.tensor(yolo_boxes, dtype=torch.float32)
            track_boxes = []
            track_ids = []

            for t in tracks:
                if not t.is_confirmed():
                    continue
                x1, y1, x2, y2 = t.to_ltrb()
                track_boxes.append([x1, y1, x2, y2])
                track_ids.append(t.track_id)

            if track_boxes:
                track_tensor = torch.tensor(track_boxes, dtype=torch.float32)
                iou_matrix = box_iou(yolo_tensor, track_tensor)
                r, c = linear_sum_assignment(-iou_matrix.numpy())

                index_to_id = {}
                for yolo_idx, track_idx in zip(r, c):
                    if iou_matrix[yolo_idx][track_idx] > 0.8:
                        index_to_id[yolo_idx] = track_ids[track_idx]

                # 첫 프레임에서 중심에 가까운 사람 선택
                if self.TARGET_ID is None and len(index_to_id) > 0:
                    best_idx = min(index_to_id.keys(), key=lambda i: center_distances[i])
                    self.TARGET_ID = index_to_id[best_idx]
                    self.get_logger().info(f"TARGET_ID 설정됨: {self.TARGET_ID}")

                # TARGET_ID에 해당하는 마스크 중심 좌표 계산
                if masks is not None:
                    for yolo_local_idx, track_id in index_to_id.items():
                        if track_id != self.TARGET_ID:
                            continue
                        real_idx = yolo_indices[yolo_local_idx]
                        mask = masks.data[real_idx].detach().cpu().numpy()
                        binary_mask = (mask > 0.5).astype(np.uint8) * 255

                        M = cv2.moments(binary_mask)
                        if M["m00"] != 0:
                            u = int(M["m10"] / M["m00"])
                            v = int(M["m01"] / M["m00"])
                            self.get_logger().info(f"Segmentation 중심 좌표: ({u}, {v})")
                        else:
                            self.get_logger().warn("중심 좌표 계산 실패: 면적이 0입니다.")

        return u, v

    # publish
    def publish_pixel(self):
        u, v = self.detect_target()

        msg = PointStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'camera_frame'
        msg.point.x = float(u)
        msg.point.y = float(v)
        msg.point.z = 0.0

        self.pub.publish(msg)
        self.get_logger().debug(f'Published pixel: ({u}, {v})')

    # show image
    def display_image(self):
        start_time = time.time()

        # 공유 메모리에서 이미지 읽기
        frame, frame_id = self.read_shared_memory()
        if frame is None:
            return

        self.current_frame = frame
        self.current_frame_id = frame_id

        h, w = frame.shape[:2]
        overlay = frame.copy()

        # YOLOv8-seg 예측
        results = self.model(frame)
        boxes = results[0].boxes
        masks = results[0].masks

        detections = []
        yolo_boxes = []
        yolo_indices = []
        center_distances = []

        if boxes is not None:
            for i, cls in enumerate(boxes.cls):
                if int(cls) == 0:
                    x1, y1, x2, y2 = boxes.xyxy[i].cpu().numpy()
                    conf = float(boxes.conf[i])
                    yolo_boxes.append([x1, y1, x2, y2])
                    detections.append(([x1, y1, x2 - x1, y2 - y1], conf, 'person'))
                    yolo_indices.append(i)
                    center_distances.append(self.get_center_distance(x1, y1, x2, y2, w, h))

        tracks = self.tracker.update_tracks(detections, frame=frame)

        if tracks and yolo_boxes:
            yolo_tensor = torch.tensor(yolo_boxes, dtype=torch.float32)
            track_boxes = []
            track_ids = []

            for t in tracks:
                if not t.is_confirmed():
                    continue
                x1, y1, x2, y2 = t.to_ltrb()
                track_boxes.append([x1, y1, x2, y2])
                track_ids.append(t.track_id)

            if track_boxes:
                track_tensor = torch.tensor(track_boxes, dtype=torch.float32)
                iou_matrix = box_iou(yolo_tensor, track_tensor)
                r, c = linear_sum_assignment(-iou_matrix.numpy())

                index_to_id = {}
                for yolo_idx, track_idx in zip(r, c):
                    if iou_matrix[yolo_idx][track_idx] > 0.8:
                        index_to_id[yolo_idx] = track_ids[track_idx]

                if masks is not None:
                    for yolo_local_idx, track_id in index_to_id.items():
                        if track_id != self.TARGET_ID:
                            continue
                        real_idx = yolo_indices[yolo_local_idx]
                        mask = masks.data[real_idx].detach().cpu().numpy()
                        binary_mask = (mask > 0.5).astype(np.uint8) * 255

                        M = cv2.moments(binary_mask)
                        if M["m00"] != 0:
                            cx = int(M["m10"] / M["m00"])
                            cy = int(M["m01"] / M["m00"])
                            cv2.circle(overlay, (cx, cy), 5, (255, 0, 0), -1)

                        color_mask = np.zeros_like(frame)
                        color_mask[:, :, 1] = binary_mask
                        overlay = cv2.addWeighted(overlay, 1.0, color_mask, 0.4, 0)

                        x1, y1, x2, y2 = map(int, yolo_boxes[yolo_local_idx])
                        cv2.rectangle(overlay, (x1, y1), (x2, y2), (0, 255, 0), 2)
                        cv2.putText(overlay, f"TARGET ID: {track_id}", (x1, y1 - 10),
                                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)

        if masks is None or not detections or not tracks:
            cv2.putText(overlay, "No detection", (30, 30),
                        cv2.FONT_HERSHEY_SIMPLEX, 1.0, (0, 0, 255), 2)

        # FPS 표시
        end_time = time.time()
        fps = 1.0 / (end_time - start_time)
        cv2.putText(overlay, f"FPS: {fps:.2f}", (10, overlay.shape[0] - 10),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

        cv2.imshow("Seg+Track", overlay)
        if cv2.waitKey(1) == 27:
            rclpy.shutdown()

    def clean_up(self):
        self.get_logger().info("Cleaning up shared memory")
        self.mapfile.close()
        self.get_logger().info("Cleanup complete.")

def main(args=None):
    rclpy.init(args=args)
    node = HumanPose()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.clean_up()
        node.destroy_node()
        cv2.destroyAllWindows()
        rclpy.shutdown()

if __name__ == '__main__':
    main()