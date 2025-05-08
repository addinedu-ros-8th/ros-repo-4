cmake_minimum_required(VERSION 3.18)
project(vision_server)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# ----------- CUDA 수동 설정 ---------------
set(CUDA_TOOLKIT_ROOT_DIR "/usr/local/cuda")
set(CUDA_INCLUDE_DIRS "${CUDA_TOOLKIT_ROOT_DIR}/include")
set(CUDA_LIBRARIES "${CUDA_TOOLKIT_ROOT_DIR}/lib64/libcudart.so")

# ----------- libSGM 수동 설정 ---------------
set(LIBSGM_INC "/home/mu/dev_ws/final/libSGM/include")
set(LIBSGM_LIB "/home/mu/dev_ws/final/libSGM/install/lib/libsgm.so")

# ----------- ROS2/OpenCV 패키지 찾기 ----------
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(tangerbot_msgs REQUIRED)
find_package(ament_index_cpp REQUIRED)

# ----------- include 경로 설정 ---------------
include_directories(
  ${CUDA_INCLUDE_DIRS}
  ${LIBSGM_INC}
  ${OpenCV_INCLUDE_DIRS}
  include
)

# ----------- sample_common 라이브러리 추가 (정적 링크) ----------
add_library(sample_common STATIC
  src/sample_common.cpp
)
target_include_directories(sample_common PUBLIC
  ${OpenCV_INCLUDE_DIRS}
)
target_link_libraries(sample_common PUBLIC
  ${OpenCV_LIBS}
)

# ----------- obstacle_detector 노드 ----------
add_executable(obstacle_detector src/obstacle_detector.cpp)
ament_target_dependencies(obstacle_detector
  rclcpp
  std_msgs
  tangerbot_msgs
  OpenCV
  ament_index_cpp
)
target_link_libraries(obstacle_detector
  ${OpenCV_LIBS}
  ${CUDA_LIBRARIES}
  ${LIBSGM_LIB}
  sample_common
)
target_include_directories(obstacle_detector PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# ----------- follower 노드 ----------
add_executable(follower src/follower.cpp)
ament_target_dependencies(follower
  rclcpp
  std_msgs
  tangerbot_msgs
  OpenCV
)
target_link_libraries(follower
  ${OpenCV_LIBS}
)
target_include_directories(follower PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# ----------- Python 노드 설치 (옵션) ----------
install(PROGRAMS
  scripts/gesture_node.py
  DESTINATION lib/${PROJECT_NAME}
)

# ----------- 타겟 설치 ----------
install(TARGETS
  obstacle_detector
  follower
  sample_common
  DESTINATION lib/${PROJECT_NAME}
)

# calibration_data.yml 설치 추가
install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
