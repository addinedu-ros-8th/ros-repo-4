cmake_minimum_required(VERSION 3.8)
project(vision_server)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tangerbot_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Include directories (if needed)
# include_directories(
#   include
# )

# Declare the executable
add_executable(obstacle_detector src/obstacle_detector.cpp)
ament_target_dependencies(obstacle_detector rclcpp std_msgs tangerbot_msgs)

add_executable(follower src/follower.cpp)
ament_target_dependencies(follower rclcpp std_msgs tangerbot_msgs)

#add_executable(my_server src/gesture_detector.cpp src/another_file.cpp)
#ament_target_dependencies(my_server rclcpp tangerbot_msgs  # 의존성 추가
#)
# Install executable
install(TARGETS
  obstacle_detector
  follower
  DESTINATION lib/${PROJECT_NAME}
)

# For Python 
install(PROGRAMS
  scripts/gesture_node.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_export_dependencies(rosidl_default_runtime)
# ament package macros
ament_package()

