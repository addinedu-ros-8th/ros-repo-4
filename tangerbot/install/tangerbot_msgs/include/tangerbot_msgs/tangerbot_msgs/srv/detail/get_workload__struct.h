// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tangerbot_msgs:srv/GetWorkload.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/get_workload.h"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__GET_WORKLOAD__STRUCT_H_
#define TANGERBOT_MSGS__SRV__DETAIL__GET_WORKLOAD__STRUCT_H_

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

/// Struct defined in srv/GetWorkload in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__GetWorkload_Request
{
  rosidl_runtime_c__String robot_id;
} tangerbot_msgs__srv__GetWorkload_Request;

// Struct for a sequence of tangerbot_msgs__srv__GetWorkload_Request.
typedef struct tangerbot_msgs__srv__GetWorkload_Request__Sequence
{
  tangerbot_msgs__srv__GetWorkload_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__GetWorkload_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/GetWorkload in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__GetWorkload_Response
{
  float workload;
} tangerbot_msgs__srv__GetWorkload_Response;

// Struct for a sequence of tangerbot_msgs__srv__GetWorkload_Response.
typedef struct tangerbot_msgs__srv__GetWorkload_Response__Sequence
{
  tangerbot_msgs__srv__GetWorkload_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__GetWorkload_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tangerbot_msgs__srv__GetWorkload_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tangerbot_msgs__srv__GetWorkload_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetWorkload in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__GetWorkload_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tangerbot_msgs__srv__GetWorkload_Request__Sequence request;
  tangerbot_msgs__srv__GetWorkload_Response__Sequence response;
} tangerbot_msgs__srv__GetWorkload_Event;

// Struct for a sequence of tangerbot_msgs__srv__GetWorkload_Event.
typedef struct tangerbot_msgs__srv__GetWorkload_Event__Sequence
{
  tangerbot_msgs__srv__GetWorkload_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__GetWorkload_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TANGERBOT_MSGS__SRV__DETAIL__GET_WORKLOAD__STRUCT_H_
