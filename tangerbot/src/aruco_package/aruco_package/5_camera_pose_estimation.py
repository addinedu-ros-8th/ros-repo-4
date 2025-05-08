import numpy as np
import cv2
import sys
import time
import argparse
from utils import ARUCO_DICT


def pose_estimation(frame, aruco_dict_type, matrix_coefficients, distortion_coefficients, marker_length):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    aruco_dict = cv2.aruco.getPredefinedDictionary(aruco_dict_type)
    aruco_params = cv2.aruco.DetectorParameters()
    detector = cv2.aruco.ArucoDetector(aruco_dict, aruco_params)

    corners, ids, _ = detector.detectMarkers(gray)

    if ids is not None and len(corners) > 0:
        for i in range(len(ids)):
            rvec, tvec, _ = cv2.aruco.estimatePoseSingleMarkers(
                corners[i], marker_length, matrix_coefficients, distortion_coefficients
            )
            R, _ = cv2.Rodrigues(rvec)
            R_c2m = R.T
            t_c2m = -R.T @ tvec
            print(f"ID {ids[i][0]} | rvec: {R_c2m.flatten()} | tvec: {t_c2m.flatten()}")

            # Draw marker border and axis
            cv2.aruco.drawDetectedMarkers(frame, corners)
            cv2.drawFrameAxes(frame, matrix_coefficients, distortion_coefficients, rvec, tvec, marker_length * 0.5)

    return frame


if __name__ == '__main__':
    ap = argparse.ArgumentParser()
    ap.add_argument("-k", "--K_Matrix", required=True, help="Path to camera calibration matrix (.npy)")
    ap.add_argument("-d", "--D_Coeff", required=True, help="Path to distortion coefficients (.npy)")
    ap.add_argument("-t", "--type", type=str, default="DICT_5X5_100", help="Type of ArUCo dictionary")
    ap.add_argument("-s", "--source", default=0, help="Video source (camera index or video file path)")
    ap.add_argument("-m", "--marker-length", type=float, required=True, help="Actual length of the marker's side (in meters)")
    args = vars(ap.parse_args())

    if ARUCO_DICT.get(args["type"], None) is None:
        print(f"[ERROR] Unsupported ArUCo type: {args['type']}")
        sys.exit(1)

    aruco_dict_type = ARUCO_DICT[args["type"]]
    k = np.load(args["K_Matrix"])
    d = np.load(args["D_Coeff"])
    marker_length = args["marker_length"]

    source = int(args["source"]) if args["source"].isdigit() else args["source"]
    video = cv2.VideoCapture(source)
    video.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'MJPG'))
    video.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
    video.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
    time.sleep(2.0)

    while True:
        ret, frame = video.read()
        if not ret:
            break

        output = pose_estimation(frame, aruco_dict_type, k, d, marker_length)
        cv2.imshow("Estimated Pose", output)

        key = cv2.waitKey(1) & 0xFF
        if key == ord('q'):
            break

    video.release()
    cv2.destroyAllWindows()
