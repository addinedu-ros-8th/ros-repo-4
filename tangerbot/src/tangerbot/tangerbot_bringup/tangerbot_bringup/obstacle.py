from picamera2 import Picamera2

# 시스템에 연결된 모든 카메라 정보를 출력
camera_list = Picamera2.global_camera_info()
print("사용 가능한 카메라 목록:")
print(camera_list)
for i, cam in enumerate(camera_list):
    print(f"카메라 인덱스 {i}: {cam}")
