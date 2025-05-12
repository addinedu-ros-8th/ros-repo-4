// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tangerbot_msgs:srv/PathPlanning.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/path_planning.h"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__PATH_PLANNING__STRUCT_H_
#define TANGERBOT_MSGS__SRV__DETAIL__PATH_PLANNING__STRUCT_H_

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
// Member 'end'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/PathPlanning in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__PathPlanning_Request
{
  rosidl_runtime_c__String__Sequence robot_id;
  rosidl_runtime_c__int8__Sequence end;
} tangerbot_msgs__srv__PathPlanning_Request;

// Struct for a sequence of tangerbot_msgs__srv__PathPlanning_Request.
typedef struct tangerbot_msgs__srv__PathPlanning_Request__Sequence
{
  tangerbot_msgs__srv__PathPlanning_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__PathPlanning_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'robot_id'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'waypoints'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'distance'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/PathPlanning in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__PathPlanning_Response
{
  rosidl_runtime_c__String__Sequence robot_id;
  geometry_msgs__msg__Point__Sequence waypoints;
  rosidl_runtime_c__float__Sequence distance;
} tangerbot_msgs__srv__PathPlanning_Response;

// Struct for a sequence of tangerbot_msgs__srv__PathPlanning_Response.
typedef struct tangerbot_msgs__srv__PathPlanning_Response__Sequence
{
  tangerbot_msgs__srv__PathPlanning_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__PathPlanning_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tangerbot_msgs__srv__PathPlanning_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tangerbot_msgs__srv__PathPlanning_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/PathPlanning in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__PathPlanning_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tangerbot_msgs__srv__PathPlanning_Request__Sequence request;
  tangerbot_msgs__srv__PathPlanning_Response__Sequence response;
} tangerbot_msgs__srv__PathPlanning_Event;

// Struct for a sequence of tangerbot_msgs__srv__PathPlanning_Event.
typedef struct tangerbot_msgs__srv__PathPlanning_Event__Sequence
{
  tangerbot_msgs__srv__PathPlanning_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__PathPlanning_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TANGERBOT_MSGS__SRV__DETAIL__PATH_PLANNING__STRUCT_H_
