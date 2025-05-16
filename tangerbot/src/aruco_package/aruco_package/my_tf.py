import rclpy as rp
from rclpy.node import Node

from geometry_msgs.msg import TransformStamped
from geometry_msgs.msg import PoseWithCovarianceStamped
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import Twist
import tf2_ros
import math
import numpy as np
import cv2
import sys
import time
import argparse
from aruco_package.utils import ARUCO_DICT
from ament_index_python.packages import get_package_share_directory
import os
from tf_transformations import euler_from_quaternion, quaternion_from_euler
import tf_transformations
import yaml
from std_msgs.msg import Bool

# TF 보정 import
import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.neighbors import KNeighborsRegressor
from sklearn.preprocessing import MinMaxScaler

""" MyTfBroadcaster Node
    
    Description:
        Estimate robot pose and publish
"""
class MyTfBroadcaster(Node):
    def __init__(self, source, aruco_dict_type, matrix_coefficients, distortion_coefficients, marker_length):
        super().__init__("my_tf_broadcaster")
        
        self.br = tf2_ros.TransformBroadcaster(self)
        
        self.tracked_pose_pub = self.create_publisher(PoseStamped, "tracked_pose", 10)
        self.timer = self.create_timer(0.05, self.timer_callback)
        self.t = 0.0
        
        self.cap = cv2.VideoCapture(source)
        self.cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'MJPG'))
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
        
        aruco_dict = cv2.aruco.getPredefinedDictionary(aruco_dict_type)
        aruco_params = cv2.aruco.DetectorParameters()
        self.detector = cv2.aruco.ArucoDetector(aruco_dict, aruco_params)
        self.matrix_coefficients = matrix_coefficients
        self.distortion_coefficients = distortion_coefficients
        self.marker_length = marker_length
        
        pkg_path = get_package_share_directory('aruco_package')
        robot_yaml_path = os.path.join(pkg_path, 'config', 'robot.yaml')
        robot_data = self.get_yaml(robot_yaml_path)
        self.aruco_marker_list = robot_data["robot"]["aruco_marker"]
        self.robot_id_list = robot_data["robot"]["robot_id"]
        
        self.prev_yaw = 0
        self.prev_tvec = np.array([0, 0, 0])
        self.ALPHA = 0.6
        
        self.is_driving = False
        
        self.cmd_vel_sub = self.create_subscription(Twist, "/cmd_vel", lambda msg, ns="robot1": self.cmd_vel_callback(msg, ns), 10)
        
    def get_yaml(self, path):
        with open(path, 'r') as f:
            data = yaml.safe_load(f)
        return data
        
    # Get frame and pose esimation of aruco marker
    def timer_callback(self):
        ret, frame = self.cap.read()
        if not ret:
            raise Exception

        output = self.pose_estimation(frame)
        cv2.imshow("Estimated Pose", output)

        key = cv2.waitKey(1) & 0xFF
        if key == ord('q'):
            raise Exception
        
    def cmd_vel_callback(self, msg, ns):
        if msg.linear.x == 0.0 and msg.angular.z == 0.0:
            self.is_driving = False
        else:
            self.is_driving = True
        
    def pose_estimation(self, frame):
        pkg_path = get_package_share_directory('aruco_package')
        calibration_path = os.path.join(pkg_path, 'config', 'pose.yaml')
        
        data = self.get_yaml(calibration_path)
        
        base_position = data["base_marker"]["position"]
        camera_pose = data["camera_pose"]
        time_stamp = self.get_clock().now().to_msg()
        # Calibration marker TF    
        base = TransformStamped()
        base.header.stamp = time_stamp
        
        base.header.frame_id = "map"
        base.child_frame_id = "base_marker"
        
        base.transform.translation.x = base_position['x']
        base.transform.translation.y = base_position['y']
        base.transform.translation.z = base_position['z']
        
        # Camera TF
        camera = TransformStamped()
                
        camera.header.stamp = time_stamp
        
        camera.header.frame_id = "map"
        camera.child_frame_id = "camera"
        
        camera.transform.translation.x = camera_pose["position"]['x']
        camera.transform.translation.y = camera_pose["position"]['y']
        camera.transform.translation.z = camera_pose["position"]['z']
        
        camera.transform.rotation.x = camera_pose["orientation"]['x']
        camera.transform.rotation.y = camera_pose["orientation"]['y']
        camera.transform.rotation.z = camera_pose["orientation"]['z']
        camera.transform.rotation.w = camera_pose["orientation"]['w']
        
        # Map -> odom TF required for nav2 navigation
        odom = TransformStamped()
        odom.header.frame_id = "map"
        odom.child_frame_id = "odom"
        odom.header.stamp = time_stamp
        
        tf_list = [base, odom]
        
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        corners, ids, _ = self.detector.detectMarkers(gray)
        
        if ids is not None and len(corners) > 0:
            ids = [ids[i][0] for i in range(len(ids))]
            for i in range(len(ids)):
                
                # Get rvec, tvec
                rvec, tvec, _ = cv2.aruco.estimatePoseSingleMarkers(
                    corners[i], self.marker_length, self.matrix_coefficients, self.distortion_coefficients
                )
                
                # if ids[i] not in self.aruco_marker_list:
                #     continue
                
                if ids[i] != 3:
                    continue
                
                R, _ = cv2.Rodrigues(rvec)
                tvec = tvec.reshape(3, 1)
                R_c2m = R.T
                t_c2m = -R.T @ tvec
                
                #print(f"ID {ids[i]} | rvec: {R_c2m.flatten()} | tvec: {t_c2m.flatten()}")
                
                # roll, pitch, yaw = euler_from_matrix(R_c2m)
                
                # quat_cam_to_marker = quaternion_from_euler(roll, pitch, yaw)
                
                # camera.transform.translation.x = float(t_c2m[0])
                # camera.transform.translation.y = float(t_c2m[1])
                # camera.transform.translation.z = float(t_c2m[2])
                
                # camera.transform.rotation.x = float(quat_cam_to_marker[0])
                # camera.transform.rotation.y = float(quat_cam_to_marker[1])
                # camera.transform.rotation.z = float(quat_cam_to_marker[2])
                # camera.transform.rotation.w = float(quat_cam_to_marker[3])
                
                # map to robot
                T_cam_marker = np.eye(4)
                T_cam_marker[:3, :3] = R
                T_cam_marker[:3, 3] = tvec.flatten()

                T_map_cam = tf_transformations.concatenate_matrices(
                    tf_transformations.translation_matrix([
                        camera.transform.translation.x,
                        camera.transform.translation.y,
                        camera.transform.translation.z
                    ]),
                    tf_transformations.quaternion_matrix([
                        camera.transform.rotation.x,
                        camera.transform.rotation.y,
                        camera.transform.rotation.z,
                        camera.transform.rotation.w
                    ])
                )
                
                T_map_marker = T_map_cam @ T_cam_marker
                t_map_marker = T_map_marker[:3, 3]
                
                t = TransformStamped()
                
                t.header.stamp = time_stamp
        
                t.header.frame_id = "odom"
                t.child_frame_id = "base_footprint"
                
                quat = tf_transformations.quaternion_from_matrix(T_map_marker)
                
                # t.transform.translation.x = float(calibrated_translation[0]/100)e

                # t.transform.translation.y = float(calibrated_translation[1]/100)
                
                if self.is_driving:
                    ALPHA = self.ALPHA
                else:
                    ALPHA = 0.9
                t_map_marker = np.array(t_map_marker)
                t_map_marker = ALPHA * self.prev_tvec + (1 - ALPHA) * t_map_marker
                self.prev_tvec = t_map_marker
                t.transform.translation.x = t_map_marker[0]
                t.transform.translation.y = t_map_marker[1]
                t.transform.translation.z = 0.0
                
                roll, pitch, yaw = euler_from_quaternion(quat)

                yaw = self.prev_yaw * self.ALPHA + yaw * (1 - self.ALPHA)
                self.prev_yaw = yaw
            
                q2d = quaternion_from_euler(0, 0, yaw)

                t.transform.rotation.x = float(q2d[0])
                t.transform.rotation.y = float(q2d[1])
                t.transform.rotation.z = float(q2d[2])
                t.transform.rotation.w = float(q2d[3])
                
                tracked_pose = PoseStamped()
                tracked_pose.header.frame_id = "map"
                tracked_pose.pose.position.x = t_map_marker[0]
                tracked_pose.pose.position.y = t_map_marker[1]
                tracked_pose.pose.position.z = 0.0
                tracked_pose.pose.orientation.x = float(q2d[0])
                tracked_pose.pose.orientation.x = float(q2d[1])
                tracked_pose.pose.orientation.x = float(q2d[2])
                tracked_pose.pose.orientation.x = float(q2d[3])
                
                self.tracked_pose_pub.publish(tracked_pose)
                
                tf_list.append(t)
                # Draw marker border and axis
                cv2.aruco.drawDetectedMarkers(frame, corners)
                cv2.drawFrameAxes(frame, self.matrix_coefficients, self.distortion_coefficients, rvec, tvec, self.marker_length * 0.5)
            
        self.br.sendTransform(tf_list)
        return frame

    def __del__(self):
        print('exit')
        self.cap.release()
        cv2.destroyAllWindows()
            
def main(args=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("-t", "--type", type=str, default="DICT_4X4_100", help="Type of ArUCo dictionary")
    ap.add_argument("-s", "--source", default='0', help="Video source (camera index or video file path)")
    ap.add_argument("-m", "--marker-length", type=float, default=0.1, help="Actual length of the marker's side (in meters)")
    #parsed_args = vars(ap.parse_args())
    parsed_args, unknown = ap.parse_known_args()
    if ARUCO_DICT.get(parsed_args.type, None) is None:
        print(f"[ERROR] Unsupported ArUCo type: {parsed_args.type}")
        sys.exit(1)
        
    pkg_path = get_package_share_directory('aruco_package')
    aruco_dict_type = ARUCO_DICT[parsed_args.type]
    k_path = os.path.join(pkg_path, 'config', "calibration_matrix.npy")
    k = np.load(k_path)
    d_path = os.path.join(pkg_path, 'config', "distortion_coefficients.npy")
    d = np.load(d_path)
    marker_length = parsed_args.marker_length

    source = int(parsed_args.source) if parsed_args.source.isdigit() else parsed_args.source

    rp.init(args=args)
    tf = MyTfBroadcaster(source, aruco_dict_type, k, d, marker_length)
    
    time.sleep(2)
    rp.spin(tf)
    rp.shutdown(tf)