cmake_minimum_required(VERSION 3.8)
project(tangerbot_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tangerbot_msgs REQUIRED)
<<<<<<< HEAD
find_package(OpenCV REQUIRED)
=======
find_package(rcl_interfaces REQUIRED)
>>>>>>> dev

add_executable(tangerbot_manager src/tangerbot_manager.cpp)
ament_target_dependencies(tangerbot_manager
  rclcpp
  tangerbot_msgs
  rcl_interfaces
)
target_include_directories(tangerbot_manager PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(tangerbot_manager PUBLIC c_std_99 cxx_std_17) 

install(TARGETS 
  tangerbot_manager
  DESTINATION lib/${PROJECT_NAME})

add_executable(udp_sender src/udp_sender.cpp)
target_include_directories(udp_sender PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  <INSTALL_INTERFACE:include>
)
target_link_libraries(udp_sender ${OpenCV_LIBS})
target_compile_features(udp_sender PUBLIC cxx_std_17)

install(TARGETS udp_sender
  DESTINATION lib/${PROJECT_NAME}
)

install(PROGRAMS
  scripts/WakeWordListener.py
  scripts/emotion.py
  scripts/pinky_lcd.py
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()