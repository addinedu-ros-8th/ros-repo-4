# 로봇 중심(Local Frame) Occupancy Grid Map 메시지
string robot_id

std_msgs/Header header

float32 resolution        # 1 grid cell의 실제 크기 (meters per cell), ex: 0.05m
uint32 width               # grid map의 가로 칸 수
uint32 height              # grid map의 세로 칸 수

float32 origin_x           # grid (0,0) 셀의 상대 시작점 (x) (ex: -2.5m)
float32 origin_y           # grid (0,0) 셀의 상대 시작점 (y) (ex: -2.5m)

int8[] data                # Occupancy data (row-major 1D array)
                           #  -1: Unknown, 0: Free, 100: Occupied
