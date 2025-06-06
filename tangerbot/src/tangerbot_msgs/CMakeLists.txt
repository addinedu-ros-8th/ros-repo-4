cmake_minimum_required(VERSION 3.8)
project(tangerbot_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/RobotState.msg"
  "msg/RobotPose.msg"
  "msg/DecodedVoice.msg"
  "msg/PersonPose.msg"
  "msg/Gesture.msg"
  "msg/CallState.msg"
  "msg/LocalMap.msg"
  "msg/DetectedMarker.msg"
  "msg/PathResult.msg"
  "msg/RawVoice.msg"
  "msg/ObstacleBool.msg"

  "srv/HandleCommand.srv"
  "srv/SetFollowMode.srv"
  "srv/SignUp.srv"
  "srv/SignIn.srv"
  "srv/Speak.srv"
  "srv/HandleRawVoice.srv"
  "srv/SetState.srv"
  "action/PathPlanning.action"
  "action/Parking.action"
  DEPENDENCIES geometry_msgs std_msgs nav_msgs # Add packages that above messages depend on, in this case geometry_msgs for Sphere.msg
)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
