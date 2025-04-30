// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tangerbot_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/robot_state.h"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
#define TANGERBOT_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'IDLE'.
/**
  * main_status constants
 */
enum
{
  tangerbot_msgs__msg__RobotState__IDLE = 0
};

/// Constant 'WORKING'.
enum
{
  tangerbot_msgs__msg__RobotState__WORKING = 1
};

/// Constant 'MOVING'.
/**
  * motion_status
 */
enum
{
  tangerbot_msgs__msg__RobotState__MOVING = 0
};

/// Constant 'FOLLOWING'.
enum
{
  tangerbot_msgs__msg__RobotState__FOLLOWING = 1
};

/// Constant 'STOP'.
enum
{
  tangerbot_msgs__msg__RobotState__STOP = 2
};

/// Constant 'LOADING'.
enum
{
  tangerbot_msgs__msg__RobotState__LOADING = 3
};

// Include directives for member types
// Member 'robot_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RobotState in the package tangerbot_msgs.
typedef struct tangerbot_msgs__msg__RobotState
{
  rosidl_runtime_c__String robot_id;
  uint8_t main_status;
  uint8_t motion_status;
  float battery;
} tangerbot_msgs__msg__RobotState;

// Struct for a sequence of tangerbot_msgs__msg__RobotState.
typedef struct tangerbot_msgs__msg__RobotState__Sequence
{
  tangerbot_msgs__msg__RobotState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__msg__RobotState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TANGERBOT_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
