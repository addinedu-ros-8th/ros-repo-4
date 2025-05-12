// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tangerbot_msgs:srv/HandleCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/handle_command.h"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__HANDLE_COMMAND__STRUCT_H_
#define TANGERBOT_MSGS__SRV__DETAIL__HANDLE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MOVETOSECTION'.
/**
  * type
 */
enum
{
  tangerbot_msgs__srv__HandleCommand_Request__MOVETOSECTION = 0
};

/// Constant 'FOLLOWING'.
enum
{
  tangerbot_msgs__srv__HandleCommand_Request__FOLLOWING = 1
};

/// Constant 'STOP'.
enum
{
  tangerbot_msgs__srv__HandleCommand_Request__STOP = 2
};

/// Constant 'RETURN'.
enum
{
  tangerbot_msgs__srv__HandleCommand_Request__RETURN = 3
};

// Include directives for member types
// Member 'robot_id'
// Member 'user_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/HandleCommand in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__HandleCommand_Request
{
  /// if robot
  rosidl_runtime_c__String robot_id;
  /// if user
  rosidl_runtime_c__String user_id;
  uint8_t type;
  uint8_t data;
} tangerbot_msgs__srv__HandleCommand_Request;

// Struct for a sequence of tangerbot_msgs__srv__HandleCommand_Request.
typedef struct tangerbot_msgs__srv__HandleCommand_Request__Sequence
{
  tangerbot_msgs__srv__HandleCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__HandleCommand_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/HandleCommand in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__HandleCommand_Response
{
  bool success;
} tangerbot_msgs__srv__HandleCommand_Response;

// Struct for a sequence of tangerbot_msgs__srv__HandleCommand_Response.
typedef struct tangerbot_msgs__srv__HandleCommand_Response__Sequence
{
  tangerbot_msgs__srv__HandleCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__HandleCommand_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tangerbot_msgs__srv__HandleCommand_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tangerbot_msgs__srv__HandleCommand_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/HandleCommand in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__HandleCommand_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tangerbot_msgs__srv__HandleCommand_Request__Sequence request;
  tangerbot_msgs__srv__HandleCommand_Response__Sequence response;
} tangerbot_msgs__srv__HandleCommand_Event;

// Struct for a sequence of tangerbot_msgs__srv__HandleCommand_Event.
typedef struct tangerbot_msgs__srv__HandleCommand_Event__Sequence
{
  tangerbot_msgs__srv__HandleCommand_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__HandleCommand_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TANGERBOT_MSGS__SRV__DETAIL__HANDLE_COMMAND__STRUCT_H_
