// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tangerbot_msgs:msg/LocalMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/local_map.h"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__LOCAL_MAP__STRUCT_H_
#define TANGERBOT_MSGS__MSG__DETAIL__LOCAL_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'robot_id'
#include "rosidl_runtime_c/string.h"
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/LocalMap in the package tangerbot_msgs.
/**
  * 로봇 중심(Local Frame) Occupancy Grid Map 메시지
 */
typedef struct tangerbot_msgs__msg__LocalMap
{
  rosidl_runtime_c__String robot_id;
  std_msgs__msg__Header header;
  /// 1 grid cell의 실제 크기 (meters per cell), ex: 0.05m
  float resolution;
  /// grid map의 가로 칸 수
  uint32_t width;
  /// grid map의 세로 칸 수
  uint32_t height;
  /// grid (0,0) 셀의 상대 시작점 (x) (ex: -2.5m)
  float origin_x;
  /// grid (0,0) 셀의 상대 시작점 (y) (ex: -2.5m)
  float origin_y;
  /// Occupancy data (row-major 1D array)
  ///  -1: Unknown, 0: Free, 100: Occupied
  rosidl_runtime_c__int8__Sequence data;
} tangerbot_msgs__msg__LocalMap;

// Struct for a sequence of tangerbot_msgs__msg__LocalMap.
typedef struct tangerbot_msgs__msg__LocalMap__Sequence
{
  tangerbot_msgs__msg__LocalMap * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__msg__LocalMap__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TANGERBOT_MSGS__MSG__DETAIL__LOCAL_MAP__STRUCT_H_
