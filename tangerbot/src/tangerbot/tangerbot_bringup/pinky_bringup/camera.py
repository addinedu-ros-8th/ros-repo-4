import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CameraInfo, Image
import numpy as np
import os
import cv2
from picamera2 import Picamera2
from ament_index_python.packages import get_package_share_directory
from pinky_bringup.utils import ARUCO_DICT
import tf2_ros
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped, Vector3, Transform, Point
from tangerbot_msgs.msg import DetectedMarker
from transforms3d.quaternions import quat2mat, mat2quat
from scipy.spatial.transform import Rotation
import transforms3d
import math
import time

import socket
import threading
import struct

class CameraPublisher(Node):
    def __init__(self):
        super().__init__('camera_publisher')
        self.image_publisher = self.create_publisher(Image, '/image_raw', 10)
        self.info_publisher = self.create_publisher(CameraInfo, '/camera_info', 10)
        self.timer = self.create_timer(0.1, self.publish_image)
        self.info_timer = self.create_timer(1.0, self.publish_camera_info)
        self.tf_buffer = tf2_ros.Buffer()
        self.listener = tf2_ros.TransformListener(self.tf_buffer, self)
        self.br = TransformBroadcaster(self)
        self.detected_marker_pub = self.create_publisher(DetectedMarker, "/detected_marker", 10)
        
        self.camera_info = self.load_camera_info()
        self.picam2 = Picamera2()
        self.picam2.configure(self.picam2.create_preview_configuration(
            main={"format": 'RGB888', "size": (640, 480)}))
        self.picam2.start()
        
        if self.camera_info:
            self.get_logger().info("Camera Info Publisher Node Started")
        else:
            self.get_logger().warn("No camera info loaded, continuing without publishing.")
            
        # Aruco setting
        if ARUCO_DICT.get("DICT_4X4_100", None) is None:
            print(f"[ERROR] Unsupported ArUCo type: DICT_4X4_100")
            sys.exit(1)
        pkg_path = get_package_share_directory('pinky_bringup')
        aruco_dict_type = ARUCO_DICT["DICT_4X4_100"]
        k_path = os.path.join(pkg_path, 'config', "calibration_matrix.npy")
        self.k = np.load(k_path)
        d_path = os.path.join(pkg_path, 'config', "distortion_coefficients.npy")
        self.d = np.load(d_path)
        self.marker_length = 0.05
        aruco_dict = cv2.aruco.getPredefinedDictionary(aruco_dict_type)
        aruco_params = cv2.aruco.DetectorParameters()
        self.detector = cv2.aruco.ArucoDetector(aruco_dict, aruco_params)
        
        self.client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.frame_num = 0
        self.host = "192.168.4.18"
        self.port = 14555
        
        time.sleep(3)
            

    def load_camera_info(self):
        npz_file = '/home/pinky/calib/camera_calibration.npz'  # 수정 필요
        if not os.path.exists(npz_file):
            self.get_logger().warn(f"NPZ file {npz_file} not found, skipping camera info loading.")
            return None
        
        try:
            data = np.load(npz_file)
            camera_info = CameraInfo()
            camera_info.width = 640  # 기본값 설정
            camera_info.height = 480  # 기본값 설정
            camera_info.k = data['camera_matrix'].flatten().tolist()
            camera_info.d = data['distortion_coefficients'].flatten().tolist()
            camera_info.distortion_model = 'plumb_bob'
            
            # rectification_matrix 기본값 (3x3 단위 행렬)
            camera_info.r = np.eye(3).flatten().tolist()
            
            # projection_matrix 기본값 (camera_matrix에 4번째 열 추가)
            projection_matrix = np.hstack((data['camera_matrix'], np.zeros((3, 1))))
            camera_info.p = projection_matrix.flatten().tolist()
            
            return camera_info
        except Exception as e:
            self.get_logger().error(f"Failed to load camera info: {e}")
            return None

    def publish_camera_info(self):
        if self.camera_info:
            self.camera_info.header.stamp = self.get_clock().now().to_msg()
            self.camera_info.header.frame_id = 'camera'
            self.info_publisher.publish(self.camera_info)
    
    def publish_image(self):
        
        frame = self.picam2.capture_array()
        frame = cv2.rotate(frame, cv2.ROTATE_180)
        #frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        
        threading.Thread(target=self.send_stream, args=(frame, ), daemon=True).start()
        
        ####################
        self.frame_num += 1
        ####################

        msg = Image()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'camera'
        msg.height = frame.shape[0]
        msg.width = frame.shape[1]
        msg.encoding = 'rgb8'
        msg.is_bigendian = False
        msg.step = frame.shape[1] * 3
        msg.data = frame.tobytes()
        
        #self.image_publisher.publish(msg)
        
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        corners, ids, _ = self.detector.detectMarkers(gray)
        
        if ids is not None and len(corners) > 0:
            ids = [ids[i][0] for i in range(len(ids))]
            for i in range(len(ids)):
                rvec, tvec, _ = cv2.aruco.estimatePoseSingleMarkers(
                    corners[i], self.marker_length, self.k, self.d
                )
                
                R, _ = cv2.Rodrigues(rvec)
                
                R_ocv_to_ros = np.array([
                    [ 0,  0,  1],
                    [-1,  0,  0],
                    [ 0, -1,  0]
                ])
                
                R = R_ocv_to_ros @ R
                
                tvec = tvec.reshape(3, 1)
                tvec_new = R_ocv_to_ros @ tvec
                translation = np.array([tvec_new[0], tvec_new[1], tvec_new[2]])
                T = np.eye(4)
                T[:3, :3] = R
                T[:3, 3] = translation.flatten()
                
                R_inv = R.T
                T_inv = -R_inv @ tvec_new
                translation = np.array([T_inv[0], T_inv[1], T_inv[2]])
                
                transform_mat = np.eye(4)
                transform_mat[:3, :3] = R_inv
                transform_mat[:3, 3] = translation.flatten()
                
                odom_to_map = self.lookup_transform("map", "odom")
                
                self.get_logger().error(f"rvec: {rvec}, tvec: {tvec}")
                
                try:
                    matrix_o_to_m = self.transform_to_matrix(odom_to_map)
                    base_foot_to_odom = self.lookup_transform("odom", "base_footprint")
                    matrix_b_to_o = self.transform_to_matrix(base_foot_to_odom)
                    base_to_base_foot = self.lookup_transform("base_footprint", "base_link")
                    matrix_b_to_b = self.transform_to_matrix(base_to_base_foot)

                    matrix_b_to_m = matrix_o_to_m @ matrix_b_to_o @ matrix_b_to_b
                
                    chassis_to_base = self.lookup_transform("base_link", "chassis")
                    matrix_c_to_b = self.transform_to_matrix(chassis_to_base)
                    front_camera_to_chassis = self.lookup_transform("chassis", "front_camera_mount")
                    matrix_c_to_c = self.transform_to_matrix(front_camera_to_chassis)
                    camera_link_to_front_camera = self.lookup_transform("front_camera_mount", "camera_link")
                    matrix_c_to_f = self.transform_to_matrix(camera_link_to_front_camera)
                    
                    matrix_camera_to_base = matrix_c_to_b @ matrix_c_to_c @ matrix_c_to_f
                    matrix_base_to_camera = np.linalg.inv(matrix_camera_to_base)
                    
                    matrix_base_to_marker = transform_mat @ matrix_base_to_camera
                    marker_to_map = self.lookup_transform("map", "marker" + str(ids[i]))
                    matrix_marker_to_map = self.transform_to_matrix(marker_to_map)
                    base_to_map = matrix_marker_to_map @ transform_mat @ matrix_base_to_camera
                
                
                    trans = base_to_map[:3, 3]
                    rot_mat = base_to_map[:3, :3]
                    r, p, y = transforms3d.euler.mat2euler(rot_mat, axes='sxyz')
                    flat_rot = transforms3d.euler.euler2mat(y, 0.0, math.radians(180), axes='sxyz')
                    flat_trans = [trans[0], trans[1], 0.0]
                    T_flat = np.eye(4)
                    T_flat[:3, :3] = flat_rot
                    T_flat[:3, 3] = flat_trans
                    transform = self.matrix_to_transform(T_flat)
                    self.get_logger().error(f"transform: {transform}")
                    t = TransformStamped()
                    
                    t.header.stamp = self.get_clock().now().to_msg()
                    t.header.frame_id = "map"
                    t.child_frame_id = "base"
                    t.transform = transform
                    self.br.sendTransform(t)
                    
                    # print marker pose
                    matrix_marker_to_map = matrix_b_to_m @ matrix_camera_to_base @ T
                    self.get_logger().error(f"marker{ids[i]} tvec: {matrix_marker_to_map[:3, 3]}")
                
                except:
                    pass
                
                cv2.aruco.drawDetectedMarkers(frame, corners)
                cv2.drawFrameAxes(frame, self.k, self.d, rvec, tvec, self.marker_length * 0.5)
                
                ##### Publish Detected Marker ID #####
                
                detected_marker = DetectedMarker()
                relative_point = Point(x=float(tvec[0]), y=float(tvec[1]), z=float(tvec[2]))
                detected_marker.robot_id = "robot1"
                detected_marker.marker_id = int(ids[i])
                detected_marker.relative_point = relative_point
                self.detected_marker_pub.publish(detected_marker)
        cv2.imwrite('/home/pinky/pinky_violet/stream.jpg', frame)
        
    def lookup_transform(self, target_frame, source_frame):
        try:
            # 원하는 변환을 구합니다 (map -> marker)
            transform = self.tf_buffer.lookup_transform(target_frame, source_frame, rclpy.time.Time())
            return transform
        except (tf2_ros.TransformException) as e:
            self.get_logger().error(f"Could not get transform: {e}")
            return None
        
    def transform_to_matrix(self, transform):
        if not transform:
            return
        t = transform.transform.translation
        q = transform.transform.rotation

        translation = np.array([t.x, t.y, t.z])
        quaternion = [q.w, q.x, q.y, q.z]  # transforms3d는 [w, x, y, z] 순서

        R = quat2mat(quaternion)

        T = np.eye(4)
        T[:3, :3] = R
        T[:3, 3] = translation

        return T
    
    def matrix_to_transform(self, matrix):
        # Extract translation (x, y, z)
        translation = Vector3()
        translation.x = matrix[0, 3]
        translation.y = matrix[1, 3]
        translation.z = matrix[2, 3]

        # Extract rotation matrix (3x3) and convert to quaternion (x, y, z, w)
        rotation_matrix = matrix[:3, :3]
        quaternion = mat2quat(rotation_matrix)

        # Create Transform message
        transform = Transform()
        transform.translation = translation
        transform.rotation.x = quaternion[0]
        transform.rotation.y = quaternion[1]
        transform.rotation.z = quaternion[2]
        transform.rotation.w = quaternion[3]

        return transform
    
    def send_stream(self, frame):
        frame = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)
        ret, frame_data = cv2.imencode(".jpg", frame, [cv2.IMWRITE_JPEG_QUALITY, 50])
        
        if not ret:
            return
        
        frame_data = frame_data.tobytes()
        header = 0xAA
        robot_id = 1
        camera_id = 2
        img_size = len(frame_data)
        chunk_size = 10240
        total_chunks = (img_size + chunk_size - 1) // chunk_size
        self.frame_num %= 65535
        for i in range(total_chunks):
            offset = i * chunk_size
            img_chunk_size = min(chunk_size, img_size - offset)
            """
            self.client.sendto(struct.pack(f"<BBBIHHI{chunk_size}s", header, robot_id, camera_id, self.frame_num, total_chunks, i, img_chunk_size, frame_data[offset:])
                               , (self.host, self.port))
            """
            chunk_data = frame_data[offset:offset + img_chunk_size]
            self.client.sendto(struct.pack(f"<BBBIHHI{img_chunk_size}s", header, robot_id, camera_id, self.frame_num, total_chunks, i, img_chunk_size, chunk_data), (self.host, self.port))
            #self.frame_num += 1

        
    def __del__(self):
        if hasattr(self, 'picam2'):
            self.picam2.close()


def main(args=None):
    rclpy.init(args=args)
    node = CameraPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()