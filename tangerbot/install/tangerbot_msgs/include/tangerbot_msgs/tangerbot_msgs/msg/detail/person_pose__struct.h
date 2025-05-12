// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tangerbot_msgs:msg/PersonPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/person_pose.h"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__PERSON_POSE__STRUCT_H_
#define TANGERBOT_MSGS__MSG__DETAIL__PERSON_POSE__STRUCT_H_

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
// Member 'pose'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/PersonPose in the package tangerbot_msgs.
typedef struct tangerbot_msgs__msg__PersonPose
{
  rosidl_runtime_c__String robot_id;
  geometry_msgs__msg__Point pose;
} tangerbot_msgs__msg__PersonPose;

// Struct for a sequence of tangerbot_msgs__msg__PersonPose.
typedef struct tangerbot_msgs__msg__PersonPose__Sequence
{
  tangerbot_msgs__msg__PersonPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__msg__PersonPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TANGERBOT_MSGS__MSG__DETAIL__PERSON_POSE__STRUCT_H_
