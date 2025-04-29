cmake_minimum_required(VERSION 3.5)
project(vision_server)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Include directories (if needed)
# include_directories(
#   include
# )

# Declare the executable
add_executable(obstacle_detector src/obstacleDetector.cpp)
ament_target_dependencies(obstacle_detector rclcpp std_msgs)

# Install executable
install(TARGETS
  obstacle_detector
  DESTINATION lib/${PROJECT_NAME}
)

# ament package macros
ament_package()
