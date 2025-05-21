cmake_minimum_required(VERSION 3.8)
project(tangerbot_server)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(tf2 REQUIRED)
find_package(tangerbot_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(yaml-cpp REQUIRED)


find_library(MYSQLCPP_CONN_LIB mysqlcppconn)


include_directories(
  include
)

add_executable(udp_server
  src/udp_server.cpp
)

add_executable(path_planner src/path_planner.cpp)
ament_target_dependencies(path_planner rclcpp rclcpp_action nav_msgs tangerbot_msgs tf2)

target_include_directories(path_planner
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE  
    ${OpenCV_INCLUDE_DIRS})
target_link_libraries(path_planner ${OpenCV_LIBS})

add_executable(brain
  src/brain.cpp
)
ament_target_dependencies(brain 
  rclcpp 
  rclcpp_action
  nav2_msgs
  tangerbot_msgs 
  geometry_msgs
)

target_link_libraries(brain 
  ${YAML_CPP_LIBRARIES}
  ${MYSQLCPP_CONN_LIB}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
  udp_server
  path_planner
  brain
  DESTINATION lib/${PROJECT_NAME})

install(PROGRAMS
  scripts/llm_node.py
  scripts/wav_to_topic.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()