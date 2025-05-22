#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PointStamped
from tangerbot_msgs.srv import SetFollowMode
from ament_index_python.packages import get_package_share_directory

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
import os

class HumanPose(Node):
    def __init__(self):
        super().__init__('human_pose')
        self.get_logger().info("Initializing HumanPose node")
        try:
            self.shm = posix_ipc.SharedMemory("/stereo_shm", flags = 0)
            self.get_logger().info("Shared memory opened successfully")
        except posix_ipc.ExistentialError as e:
            self.get_logger().error(f"Failed to open shared memory: {e}")
            raise

        self.active_ = False
        self.robot_idx = 0
        self.camera_id = 0  # 왼쪽 카메라

        self.pub = self.create_publisher(PointStamped, 'object_pixel', 10)
        self.srv = self.create_service(SetFollowMode, 'set_human_pose_follow_mode', self.handle_set_mode)

        timer_period = 1.0 / 30.0
        self.publish_timer = self.create_timer(timer_period, self.publish_pixel)
        self.display_timer = self.create_timer(timer_period, self.display_image)

        self.calib_file = os.path.join(
            get_package_share_directory("vision_server"),
            "config",
            "calibration_data.yml"
        )

        # Deep Learning 초기화
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        self.get_logger().info(f"Using device: {self.device}")
        self.model = YOLO("yolov8n-seg.pt").to(self.device)
        self.tracker = DeepSort(max_age = 50, n_init = 3, max_cosine_distance = 0.3, nn_budget = 50)
        self.TARGET_ID = None

        # 왜곡 보정 파라미터
        self.map1x, self.map1y = self.load_left_camera_calibration()

        # 공유 메모리 초기화
        self.shm = posix_ipc.SharedMemory("/stereo_shm", flags = 0)
        self.seg_size = 9 * (4 + 4 + 56 + (1 << 20))
        self.mapfile = mmap.mmap(self.shm.fd, self.seg_size, access = mmap.ACCESS_READ)
        self.shm.close_fd()

        # 디코딩 오프셋
        self.OFFSET_FRAME_ID = 0
        self.OFFSET_SIZE = 4
        self.OFFSET_DATA = 64
        self.MAX_IMG = 1 << 20
        self.SLOT_SIZE = 8 + 56 + (1 << 20)

        self.NUM_CAMERAS = 3

        # 디텍션 상태
        self.current_frame = None
        self.current_frame_id = None
        self.fail_count = 0
        self.max_fails = 3
        self.last_detection_time = time.time()  # 마지막 유효 디텍션 시간
        self.no_detection_timeout = 3.0  # 3초 타임아웃

    def handle_set_mode(self, request, response):
        # "robot1" → 인덱스 0
        name = request.robot_id
        self.robot_idx = int(name.replace('robot','')) - 1
        self.active_ = request.mode
        response.success = True
        self.get_logger().warn("read")
        return response

    # 이미지 왜곡 보정 캘리브레이션 파일 업로드
    def load_left_camera_calibration(self):
        fs = cv2.FileStorage(self.calib_file, cv2.FILE_STORAGE_READ)
        if not fs.isOpened():
            raise RuntimeError(f"Cannot open calibration file: {self.calib_file}")

        K1 = fs.getNode("mtx_l").mat()
        D1 = fs.getNode("dist_l").mat()
        fs.release()

        cam_size = (640, 480)
        new_K1, _ = cv2.getOptimalNewCameraMatrix(K1, D1, cam_size, 0)
        map1x, map1y = cv2.initUndistortRectifyMap(
            K1, D1, None, new_K1, cam_size, cv2.CV_32FC1
        )
        return map1x, map1y

    def get_center_distance(self, x1, y1, x2, y2, img_w, img_h):
        box_cx = (x1 + x2) / 2
        box_cy = (y1 + y2) / 2
        img_cx = img_w / 2
        img_cy = img_h / 2
        return np.hypot(box_cx - img_cx, box_cy - img_cy)

    def read_shared_memory(self):
        BASE_OFFSET = (self.robot_idx * self.NUM_CAMERAS + self.camera_id) * self.SLOT_SIZE

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
            self.get_logger().warn("JPEG decoding failed")
            return None, None

        img = cv2.remap(img, self.map1x, self.map1y, cv2.INTER_LINEAR)

        return img, frame_id_1

    def detect_target(self):
        if self.current_frame is None:
            self.fail_count += 1
            self.get_logger().warn(f"No frame available, fail_count={self.fail_count}")
            return None

        start_time = time.time()
        frame = self.current_frame
        h, w = frame.shape[:2]

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

        if not tracks or not yolo_boxes:
            self.fail_count += 1
            self.get_logger().warn(f"No valid tracks or boxes, fail_count={self.fail_count}")
            return None

        yolo_tensor = torch.tensor(yolo_boxes, dtype=torch.float32)
        track_boxes = []
        track_ids = []

        for t in tracks:
            if not t.is_confirmed():
                continue
            x1, y1, x2, y2 = t.to_ltrb()
            track_boxes.append([x1, y1, x2, y2])
            track_ids.append(t.track_id)

        if not track_boxes:
            self.fail_count += 1
            self.get_logger().warn(f"No confirmed tracks, fail_count={self.fail_count}")
            return None

        track_tensor = torch.tensor(track_boxes, dtype=torch.float32)
        iou_matrix = box_iou(yolo_tensor, track_tensor)
        r, c = linear_sum_assignment(-iou_matrix.numpy())

        index_to_id = {}
        for yolo_idx, track_idx in zip(r, c):
            if iou_matrix[yolo_idx][track_idx] > 0.2:
                index_to_id[yolo_idx] = track_ids[track_idx]

        if self.TARGET_ID is None and len(index_to_id) > 0:
            best_idx = min(index_to_id.keys(), key=lambda i: center_distances[i])
            self.TARGET_ID = index_to_id[best_idx]
            self.get_logger().info(f"New TARGET_ID set: {self.TARGET_ID}")

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
                    v = int(M["m01"] / M["m00"]) - 100  # y 값을 15픽셀 위로 조정
                    if v < 0:
                        v = 0  # 이미지 범위 내로
                    self.get_logger().info(f"Segmentation center: (u={u}, v={v}) (original v={int(M['m01']/M['m00'])})")
                    self.fail_count = 0
                    self.last_detection_time = time.time()  # 유효 디텍션 시 시간 업데이트
                    return u, v

        self.fail_count += 1
        self.get_logger().warn(f"No valid mask or TARGET_ID not found, fail_count={self.fail_count}")
        return None

    def publish_pixel(self):
        if not self.active_:
            return
        # 디텍션 실패 지속 시간 체크
        current_time = time.time()
        if self.fail_count >= self.max_fails:
            elapsed = current_time - self.last_detection_time
            if elapsed > self.no_detection_timeout:
                self.get_logger().info(f"No detection for {elapsed:.2f} seconds, resetting TARGET_ID")
                self.TARGET_ID = None
                self.fail_count = 0

        result = self.detect_target()
        if result is None:
            if self.fail_count >= self.max_fails:
                elapsed = current_time - self.last_detection_time
                self.get_logger().warn(f"Detection failed {self.fail_count} times for {elapsed:.2f} seconds, skipping publish")
            return

        u, v = result
        msg = PointStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'camera_frame'
        msg.point.x = float(u)
        msg.point.y = float(v)
        msg.point.z = 0.0

        self.pub.publish(msg)
        self.get_logger().debug(f'Published pixel: (x={u}, y={v})')

    def display_image(self):
        if not self.active_:
            return
        
        start_time = time.time()

        frame, frame_id = self.read_shared_memory()
        if frame is None:
            return

        self.current_frame = frame
        self.current_frame_id = frame_id

        h, w = frame.shape[:2]
        overlay = frame.copy()

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
                track_tensor = torch.tensor(track_boxes, dtype = torch.float32)
                iou_matrix = box_iou(yolo_tensor, track_tensor)
                r, c = linear_sum_assignment(-iou_matrix.numpy())

                index_to_id = {}
                for yolo_idx, track_idx in zip(r, c):
                    if iou_matrix[yolo_idx][track_idx] > 0.2:
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
