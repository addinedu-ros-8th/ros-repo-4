// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pinky_interfaces:srv/Emotion.idl
// generated code does not contain a copyright notice
#include "pinky_interfaces/srv/detail/emotion__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `emotion`
#include "rosidl_runtime_c/string_functions.h"

bool
pinky_interfaces__srv__Emotion_Request__init(pinky_interfaces__srv__Emotion_Request * msg)
{
  if (!msg) {
    return false;
  }
  // emotion
  if (!rosidl_runtime_c__String__init(&msg->emotion)) {
    pinky_interfaces__srv__Emotion_Request__fini(msg);
    return false;
  }
  return true;
}

void
pinky_interfaces__srv__Emotion_Request__fini(pinky_interfaces__srv__Emotion_Request * msg)
{
  if (!msg) {
    return;
  }
  // emotion
  rosidl_runtime_c__String__fini(&msg->emotion);
}

bool
pinky_interfaces__srv__Emotion_Request__are_equal(const pinky_interfaces__srv__Emotion_Request * lhs, const pinky_interfaces__srv__Emotion_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // emotion
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->emotion), &(rhs->emotion)))
  {
    return false;
  }
  return true;
}

bool
pinky_interfaces__srv__Emotion_Request__copy(
  const pinky_interfaces__srv__Emotion_Request * input,
  pinky_interfaces__srv__Emotion_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // emotion
  if (!rosidl_runtime_c__String__copy(
      &(input->emotion), &(output->emotion)))
  {
    return false;
  }
  return true;
}

pinky_interfaces__srv__Emotion_Request *
pinky_interfaces__srv__Emotion_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pinky_interfaces__srv__Emotion_Request * msg = (pinky_interfaces__srv__Emotion_Request *)allocator.allocate(sizeof(pinky_interfaces__srv__Emotion_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pinky_interfaces__srv__Emotion_Request));
  bool success = pinky_interfaces__srv__Emotion_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pinky_interfaces__srv__Emotion_Request__destroy(pinky_interfaces__srv__Emotion_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pinky_interfaces__srv__Emotion_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pinky_interfaces__srv__Emotion_Request__Sequence__init(pinky_interfaces__srv__Emotion_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pinky_interfaces__srv__Emotion_Request * data = NULL;

  if (size) {
    data = (pinky_interfaces__srv__Emotion_Request *)allocator.zero_allocate(size, sizeof(pinky_interfaces__srv__Emotion_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pinky_interfaces__srv__Emotion_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pinky_interfaces__srv__Emotion_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pinky_interfaces__srv__Emotion_Request__Sequence__fini(pinky_interfaces__srv__Emotion_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pinky_interfaces__srv__Emotion_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pinky_interfaces__srv__Emotion_Request__Sequence *
pinky_interfaces__srv__Emotion_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pinky_interfaces__srv__Emotion_Request__Sequence * array = (pinky_interfaces__srv__Emotion_Request__Sequence *)allocator.allocate(sizeof(pinky_interfaces__srv__Emotion_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pinky_interfaces__srv__Emotion_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pinky_interfaces__srv__Emotion_Request__Sequence__destroy(pinky_interfaces__srv__Emotion_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pinky_interfaces__srv__Emotion_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pinky_interfaces__srv__Emotion_Request__Sequence__are_equal(const pinky_interfaces__srv__Emotion_Request__Sequence * lhs, const pinky_interfaces__srv__Emotion_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pinky_interfaces__srv__Emotion_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pinky_interfaces__srv__Emotion_Request__Sequence__copy(
  const pinky_interfaces__srv__Emotion_Request__Sequence * input,
  pinky_interfaces__srv__Emotion_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pinky_interfaces__srv__Emotion_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pinky_interfaces__srv__Emotion_Request * data =
      (pinky_interfaces__srv__Emotion_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pinky_interfaces__srv__Emotion_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pinky_interfaces__srv__Emotion_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pinky_interfaces__srv__Emotion_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `response`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
pinky_interfaces__srv__Emotion_Response__init(pinky_interfaces__srv__Emotion_Response * msg)
{
  if (!msg) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__init(&msg->response)) {
    pinky_interfaces__srv__Emotion_Response__fini(msg);
    return false;
  }
  return true;
}

void
pinky_interfaces__srv__Emotion_Response__fini(pinky_interfaces__srv__Emotion_Response * msg)
{
  if (!msg) {
    return;
  }
  // response
  rosidl_runtime_c__String__fini(&msg->response);
}

bool
pinky_interfaces__srv__Emotion_Response__are_equal(const pinky_interfaces__srv__Emotion_Response * lhs, const pinky_interfaces__srv__Emotion_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
pinky_interfaces__srv__Emotion_Response__copy(
  const pinky_interfaces__srv__Emotion_Response * input,
  pinky_interfaces__srv__Emotion_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

pinky_interfaces__srv__Emotion_Response *
pinky_interfaces__srv__Emotion_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pinky_interfaces__srv__Emotion_Response * msg = (pinky_interfaces__srv__Emotion_Response *)allocator.allocate(sizeof(pinky_interfaces__srv__Emotion_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pinky_interfaces__srv__Emotion_Response));
  bool success = pinky_interfaces__srv__Emotion_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pinky_interfaces__srv__Emotion_Response__destroy(pinky_interfaces__srv__Emotion_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pinky_interfaces__srv__Emotion_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pinky_interfaces__srv__Emotion_Response__Sequence__init(pinky_interfaces__srv__Emotion_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pinky_interfaces__srv__Emotion_Response * data = NULL;

  if (size) {
    data = (pinky_interfaces__srv__Emotion_Response *)allocator.zero_allocate(size, sizeof(pinky_interfaces__srv__Emotion_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pinky_interfaces__srv__Emotion_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pinky_interfaces__srv__Emotion_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pinky_interfaces__srv__Emotion_Response__Sequence__fini(pinky_interfaces__srv__Emotion_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pinky_interfaces__srv__Emotion_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pinky_interfaces__srv__Emotion_Response__Sequence *
pinky_interfaces__srv__Emotion_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pinky_interfaces__srv__Emotion_Response__Sequence * array = (pinky_interfaces__srv__Emotion_Response__Sequence *)allocator.allocate(sizeof(pinky_interfaces__srv__Emotion_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pinky_interfaces__srv__Emotion_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pinky_interfaces__srv__Emotion_Response__Sequence__destroy(pinky_interfaces__srv__Emotion_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pinky_interfaces__srv__Emotion_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pinky_interfaces__srv__Emotion_Response__Sequence__are_equal(const pinky_interfaces__srv__Emotion_Response__Sequence * lhs, const pinky_interfaces__srv__Emotion_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pinky_interfaces__srv__Emotion_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pinky_interfaces__srv__Emotion_Response__Sequence__copy(
  const pinky_interfaces__srv__Emotion_Response__Sequence * input,
  pinky_interfaces__srv__Emotion_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pinky_interfaces__srv__Emotion_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pinky_interfaces__srv__Emotion_Response * data =
      (pinky_interfaces__srv__Emotion_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pinky_interfaces__srv__Emotion_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pinky_interfaces__srv__Emotion_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pinky_interfaces__srv__Emotion_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "pinky_interfaces/srv/detail/emotion__functions.h"

bool
pinky_interfaces__srv__Emotion_Event__init(pinky_interfaces__srv__Emotion_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    pinky_interfaces__srv__Emotion_Event__fini(msg);
    return false;
  }
  // request
  if (!pinky_interfaces__srv__Emotion_Request__Sequence__init(&msg->request, 0)) {
    pinky_interfaces__srv__Emotion_Event__fini(msg);
    return false;
  }
  // response
  if (!pinky_interfaces__srv__Emotion_Response__Sequence__init(&msg->response, 0)) {
    pinky_interfaces__srv__Emotion_Event__fini(msg);
    return false;
  }
  return true;
}

void
pinky_interfaces__srv__Emotion_Event__fini(pinky_interfaces__srv__Emotion_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  pinky_interfaces__srv__Emotion_Request__Sequence__fini(&msg->request);
  // response
  pinky_interfaces__srv__Emotion_Response__Sequence__fini(&msg->response);
}

bool
pinky_interfaces__srv__Emotion_Event__are_equal(const pinky_interfaces__srv__Emotion_Event * lhs, const pinky_interfaces__srv__Emotion_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!pinky_interfaces__srv__Emotion_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!pinky_interfaces__srv__Emotion_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
pinky_interfaces__srv__Emotion_Event__copy(
  const pinky_interfaces__srv__Emotion_Event * input,
  pinky_interfaces__srv__Emotion_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!pinky_interfaces__srv__Emotion_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!pinky_interfaces__srv__Emotion_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

pinky_interfaces__srv__Emotion_Event *
pinky_interfaces__srv__Emotion_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pinky_interfaces__srv__Emotion_Event * msg = (pinky_interfaces__srv__Emotion_Event *)allocator.allocate(sizeof(pinky_interfaces__srv__Emotion_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pinky_interfaces__srv__Emotion_Event));
  bool success = pinky_interfaces__srv__Emotion_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pinky_interfaces__srv__Emotion_Event__destroy(pinky_interfaces__srv__Emotion_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pinky_interfaces__srv__Emotion_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pinky_interfaces__srv__Emotion_Event__Sequence__init(pinky_interfaces__srv__Emotion_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pinky_interfaces__srv__Emotion_Event * data = NULL;

  if (size) {
    data = (pinky_interfaces__srv__Emotion_Event *)allocator.zero_allocate(size, sizeof(pinky_interfaces__srv__Emotion_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pinky_interfaces__srv__Emotion_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pinky_interfaces__srv__Emotion_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pinky_interfaces__srv__Emotion_Event__Sequence__fini(pinky_interfaces__srv__Emotion_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pinky_interfaces__srv__Emotion_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pinky_interfaces__srv__Emotion_Event__Sequence *
pinky_interfaces__srv__Emotion_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pinky_interfaces__srv__Emotion_Event__Sequence * array = (pinky_interfaces__srv__Emotion_Event__Sequence *)allocator.allocate(sizeof(pinky_interfaces__srv__Emotion_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pinky_interfaces__srv__Emotion_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pinky_interfaces__srv__Emotion_Event__Sequence__destroy(pinky_interfaces__srv__Emotion_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pinky_interfaces__srv__Emotion_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pinky_interfaces__srv__Emotion_Event__Sequence__are_equal(const pinky_interfaces__srv__Emotion_Event__Sequence * lhs, const pinky_interfaces__srv__Emotion_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pinky_interfaces__srv__Emotion_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pinky_interfaces__srv__Emotion_Event__Sequence__copy(
  const pinky_interfaces__srv__Emotion_Event__Sequence * input,
  pinky_interfaces__srv__Emotion_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pinky_interfaces__srv__Emotion_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pinky_interfaces__srv__Emotion_Event * data =
      (pinky_interfaces__srv__Emotion_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pinky_interfaces__srv__Emotion_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pinky_interfaces__srv__Emotion_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pinky_interfaces__srv__Emotion_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
