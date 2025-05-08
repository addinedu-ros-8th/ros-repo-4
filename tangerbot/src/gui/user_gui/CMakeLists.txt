cmake_minimum_required(VERSION 3.8)
project(user_gui)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Qt 설정
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# include 디렉토리 지정
include_directories(
  include
)

# 헤더, 소스, UI 파일 수동으로 지정
set(SOURCES
  src/main.cpp
  src/tangerine.cpp
)

set(HEADERS
  include/user_gui/tangerine.h
)

set(UIS
  ui/tangerine.ui
)

qt5_wrap_ui(UI_HEADERS ${UIS})

# 실행 파일 생성
add_executable(user_gui
  ${SOURCES}
  ${HEADERS}
  ${UIS}
)

# 링크 설정
target_link_libraries(
  user_gui
  Qt5::Widgets
)

install(TARGETS 
  user_gui
  DESTINATION lib/${PROJECT_NAME})

ament_package()
