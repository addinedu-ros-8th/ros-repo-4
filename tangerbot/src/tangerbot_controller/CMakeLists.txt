cmake_minimum_required(VERSION 3.8)
project(tangerbot_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tangerbot_msgs REQUIRED)

add_executable(TangerbotManager src/TangerbotManager.cpp)
ament_target_dependencies(TangerbotManager
  rclcpp
  tangerbot_msgs
)
target_include_directories(TangerbotManager PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(TangerbotManager PUBLIC c_std_99 cxx_std_17) 

install(TARGETS 
  TangerbotManager
  DESTINATION lib/${PROJECT_NAME})

install(PROGRAMS
  scripts/WakeWordListener.py
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()