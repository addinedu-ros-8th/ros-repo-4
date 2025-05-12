import yaml
from utils import ARUCO_DICT
import numpy as np
import cv2
import sys
import time
import os

from utils import ARUCO_DICT

from scipy.spatial.transform import Rotation

BASE_DIR = os.path.dirname(os.path.abspath(__file__)) + "/.."

class Calibration():
    def __init__(self):
        calibration_path = os.path.join(BASE_DIR, 'config', 'pose.yaml')

        with open(calibration_path, 'r+') as f:
            data = yaml.safe_load(f)
        self.base_pos = data['base_marker']['position']
        
        self.cap = cv2.VideoCapture(0)
        self.cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'MJPG'))
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
        
        
        
        if ARUCO_DICT.get("DICT_4X4_100", None) is None:
            print("[ERROR] Unsupported ArUCo type: 'DICT_4X4_100'")
            sys.exit(1)
            
        k_path = BASE_DIR + "/config/calibration_matrix.npy"
        k = np.load(k_path)
        d_path = BASE_DIR + "/config/distortion_coefficients.npy"
        d = np.load(d_path)
        self.marker_length = 0.1
        aruco_dict_type = ARUCO_DICT["DICT_4X4_100"]
        aruco_dict = cv2.aruco.getPredefinedDictionary(aruco_dict_type)
        aruco_params = cv2.aruco.DetectorParameters()
        self.detector = cv2.aruco.ArucoDetector(aruco_dict, aruco_params)
        self.matrix_coefficients = k
        self.distortion_coefficients = d
        
        self.calibrate()
        
    def average_quaternions(self, quaternions):
        Q = np.array(quaternions)
        A = np.zeros((4, 4))
        for q in Q:
            q = q.reshape(4, 1)
            A += q @ q.T
        A /= len(Q)

        eigenvalues, eigenvectors = np.linalg.eigh(A)
        avg_quat = eigenvectors[:, -1]  # 가장 큰 고유값에 대응하는 고유벡터
        return avg_quat / np.linalg.norm(avg_quat) 

    def calibrate(self):
        print("START")
        start_time = time.time()
        poses = []
        orients = []
        while time.time() - start_time < 5:
            ret, frame = self.cap.read()
            if not ret:
                print("NO RET")
                return
            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            corners, ids, _ = self.detector.detectMarkers(gray)
            
            if ids is not None and len(corners) > 0:
                ids = [ids[i][0] for i in range(len(ids))]
                if 0 not in ids:
                    continue
                
                base_id_index = ids.index(0)
                
                rvec, tvec, _ = cv2.aruco.estimatePoseSingleMarkers(
                    corners[base_id_index], self.marker_length, self.matrix_coefficients, self.distortion_coefficients
                )
                R, _ = cv2.Rodrigues(rvec)
                tvec = tvec.reshape(3, 1)
                R_c2m = R.T
                t_c2m = -R.T @ tvec
                
                #print(f"ID 0 | rvec: {R_c2m.flatten()} | tvec: {t_c2m.flatten()}")
                
                r = Rotation.from_matrix(R_c2m)
                q = r.as_quat()
                pose = [t_c2m[0][0], t_c2m[1][0], t_c2m[2][0]]
                orient = [q[0], q[1], q[2], q[3]]
                poses.append(pose)
                orients.append(orient)
                print("xyz: ", pose)
                print("q: ", orient)
                cv2.aruco.drawDetectedMarkers(frame, corners)
                cv2.drawFrameAxes(frame, self.matrix_coefficients, self.distortion_coefficients, rvec, tvec, self.marker_length * 0.5)
            
            cv2.imshow("Calibrate", frame)

            key = cv2.waitKey(1) & 0xFF
            if key == ord('q'):
                return
        mean_pose = np.mean(poses, axis=0)
        mean_orient = self.average_quaternions(np.array(orients))
        print(mean_pose, mean_orient)
        
        camera_pose = {
            "camera_pose": {
                "position": {
                    "x": float(mean_pose[0] + self.base_pos['x']),
                    "y": float(mean_pose[1] + self.base_pos['y']),
                    "z": float(mean_pose[2] + self.base_pos['z'])
                },
                "orientation": {
                    "x": float(mean_orient[0]),
                    "y": float(mean_orient[1]),
                    "z": float(mean_orient[2]),
                    "w": float(mean_orient[3])
                }
            }
        }
        calibration_path = os.path.join(BASE_DIR, 'config', 'pose.yaml')
        try:
            with open(calibration_path, 'r') as f:
                data = yaml.safe_load(f) or {}  # 파일이 비어있으면 빈 딕셔너리
        except FileNotFoundError:
            data = {}
        
        data.update(camera_pose)
        
        with open(calibration_path, 'w') as f:
            yaml.dump(data, f, sort_keys=False)
        
        
def main(args=None):

    ca = Calibration()
    
    
if __name__ == "__main__":
    main()