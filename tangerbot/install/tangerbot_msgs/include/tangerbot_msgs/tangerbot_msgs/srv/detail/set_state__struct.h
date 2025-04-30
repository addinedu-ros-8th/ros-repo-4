// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tangerbot_msgs:srv/SetState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/set_state.h"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__SET_STATE__STRUCT_H_
#define TANGERBOT_MSGS__SRV__DETAIL__SET_STATE__STRUCT_H_

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

/// Struct defined in srv/SetState in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__SetState_Request
{
  rosidl_runtime_c__String robot_id;
  uint8_t main_status;
  uint8_t motion_status;
} tangerbot_msgs__srv__SetState_Request;

// Struct for a sequence of tangerbot_msgs__srv__SetState_Request.
typedef struct tangerbot_msgs__srv__SetState_Request__Sequence
{
  tangerbot_msgs__srv__SetState_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__SetState_Request__Sequence;

// Constants defined in the message

/// Constant 'IDLE'.
/**
  * main_status constants
 */
enum
{
  tangerbot_msgs__srv__SetState_Response__IDLE = 0
};

/// Constant 'WORKING'.
enum
{
  tangerbot_msgs__srv__SetState_Response__WORKING = 1
};

/// Constant 'DEACTIVATE'.
enum
{
  tangerbot_msgs__srv__SetState_Response__DEACTIVATE = 2
};

/// Constant 'MOVING'.
/**
  * motion_status
 */
enum
{
  tangerbot_msgs__srv__SetState_Response__MOVING = 0
};

/// Constant 'FOLLOWING'.
enum
{
  tangerbot_msgs__srv__SetState_Response__FOLLOWING = 1
};

/// Constant 'STOPPED'.
enum
{
  tangerbot_msgs__srv__SetState_Response__STOPPED = 2
};

/// Constant 'LOADING'.
enum
{
  tangerbot_msgs__srv__SetState_Response__LOADING = 3
};

/// Struct defined in srv/SetState in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__SetState_Response
{
  bool success;
} tangerbot_msgs__srv__SetState_Response;

// Struct for a sequence of tangerbot_msgs__srv__SetState_Response.
typedef struct tangerbot_msgs__srv__SetState_Response__Sequence
{
  tangerbot_msgs__srv__SetState_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__SetState_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tangerbot_msgs__srv__SetState_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tangerbot_msgs__srv__SetState_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetState in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__SetState_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tangerbot_msgs__srv__SetState_Request__Sequence request;
  tangerbot_msgs__srv__SetState_Response__Sequence response;
} tangerbot_msgs__srv__SetState_Event;

// Struct for a sequence of tangerbot_msgs__srv__SetState_Event.
typedef struct tangerbot_msgs__srv__SetState_Event__Sequence
{
  tangerbot_msgs__srv__SetState_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__SetState_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TANGERBOT_MSGS__SRV__DETAIL__SET_STATE__STRUCT_H_
