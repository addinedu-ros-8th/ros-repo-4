cmake_minimum_required(VERSION 3.8)
project(tangerbot_server)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tangerbot_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

include_directories(
  include
)

add_executable(udp_server
  src/udp_server.cpp
)

add_executable(path_planner
  src/path_planner.cpp
)
ament_target_dependencies(path_planner rclcpp tangerbot_msgs geometry_msgs)

add_executable(brain
  src/brain.cpp
)
ament_target_dependencies(brain rclcpp tangerbot_msgs geometry_msgs)

add_executable(bridge
  src/bridge.cpp
)
ament_target_dependencies(bridge rclcpp tangerbot_msgs geometry_msgs)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
  udp_server
  path_planner
  brain
  bridge
  DESTINATION lib/${PROJECT_NAME})

install(PROGRAMS
  scripts/llm_node.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
