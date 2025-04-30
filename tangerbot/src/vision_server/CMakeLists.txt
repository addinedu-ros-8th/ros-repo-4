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

# Include directories (if needed)
# include_directories(
#   include
# )

# Declare the executable
add_executable(obstacle_detector src/obstacle_detector.cpp)
ament_target_dependencies(obstacle_detector rclcpp std_msgs tangerbot_msgs)

add_executable(follower src/follower.cpp)
ament_target_dependencies(follower rclcpp std_msgs tangerbot_msgs)

# Install executable
install(TARGETS
  obstacle_detector
  follower
  DESTINATION lib/${PROJECT_NAME}
)

# For Python 
install(PROGRAMS
  scripts/my_python_node.py
  DESTINATION lib/${PROJECT_NAME}
)

# ament package macros
ament_package()

