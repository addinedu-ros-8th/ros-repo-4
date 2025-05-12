// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tangerbot_msgs:srv/Redirect.idl
// generated code does not contain a copyright notice
#include "tangerbot_msgs/srv/detail/redirect__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `robot_id`
#include "rosidl_runtime_c/string_functions.h"

bool
tangerbot_msgs__srv__Redirect_Request__init(tangerbot_msgs__srv__Redirect_Request * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__init(&msg->robot_id)) {
    tangerbot_msgs__srv__Redirect_Request__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__srv__Redirect_Request__fini(tangerbot_msgs__srv__Redirect_Request * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  rosidl_runtime_c__String__fini(&msg->robot_id);
}

bool
tangerbot_msgs__srv__Redirect_Request__are_equal(const tangerbot_msgs__srv__Redirect_Request * lhs, const tangerbot_msgs__srv__Redirect_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_id), &(rhs->robot_id)))
  {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__srv__Redirect_Request__copy(
  const tangerbot_msgs__srv__Redirect_Request * input,
  tangerbot_msgs__srv__Redirect_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_id), &(output->robot_id)))
  {
    return false;
  }
  return true;
}

tangerbot_msgs__srv__Redirect_Request *
tangerbot_msgs__srv__Redirect_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__srv__Redirect_Request * msg = (tangerbot_msgs__srv__Redirect_Request *)allocator.allocate(sizeof(tangerbot_msgs__srv__Redirect_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__srv__Redirect_Request));
  bool success = tangerbot_msgs__srv__Redirect_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__srv__Redirect_Request__destroy(tangerbot_msgs__srv__Redirect_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__srv__Redirect_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__srv__Redirect_Request__Sequence__init(tangerbot_msgs__srv__Redirect_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__srv__Redirect_Request * data = NULL;

  if (size) {
    data = (tangerbot_msgs__srv__Redirect_Request *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__srv__Redirect_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__srv__Redirect_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__srv__Redirect_Request__fini(&data[i - 1]);
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
tangerbot_msgs__srv__Redirect_Request__Sequence__fini(tangerbot_msgs__srv__Redirect_Request__Sequence * array)
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
      tangerbot_msgs__srv__Redirect_Request__fini(&array->data[i]);
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

tangerbot_msgs__srv__Redirect_Request__Sequence *
tangerbot_msgs__srv__Redirect_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__srv__Redirect_Request__Sequence * array = (tangerbot_msgs__srv__Redirect_Request__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__srv__Redirect_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__srv__Redirect_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__srv__Redirect_Request__Sequence__destroy(tangerbot_msgs__srv__Redirect_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__srv__Redirect_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__srv__Redirect_Request__Sequence__are_equal(const tangerbot_msgs__srv__Redirect_Request__Sequence * lhs, const tangerbot_msgs__srv__Redirect_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__srv__Redirect_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__srv__Redirect_Request__Sequence__copy(
  const tangerbot_msgs__srv__Redirect_Request__Sequence * input,
  tangerbot_msgs__srv__Redirect_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__srv__Redirect_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__srv__Redirect_Request * data =
      (tangerbot_msgs__srv__Redirect_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__srv__Redirect_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__srv__Redirect_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__srv__Redirect_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
tangerbot_msgs__srv__Redirect_Response__init(tangerbot_msgs__srv__Redirect_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
tangerbot_msgs__srv__Redirect_Response__fini(tangerbot_msgs__srv__Redirect_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
tangerbot_msgs__srv__Redirect_Response__are_equal(const tangerbot_msgs__srv__Redirect_Response * lhs, const tangerbot_msgs__srv__Redirect_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__srv__Redirect_Response__copy(
  const tangerbot_msgs__srv__Redirect_Response * input,
  tangerbot_msgs__srv__Redirect_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

tangerbot_msgs__srv__Redirect_Response *
tangerbot_msgs__srv__Redirect_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__srv__Redirect_Response * msg = (tangerbot_msgs__srv__Redirect_Response *)allocator.allocate(sizeof(tangerbot_msgs__srv__Redirect_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__srv__Redirect_Response));
  bool success = tangerbot_msgs__srv__Redirect_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__srv__Redirect_Response__destroy(tangerbot_msgs__srv__Redirect_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__srv__Redirect_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__srv__Redirect_Response__Sequence__init(tangerbot_msgs__srv__Redirect_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__srv__Redirect_Response * data = NULL;

  if (size) {
    data = (tangerbot_msgs__srv__Redirect_Response *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__srv__Redirect_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__srv__Redirect_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__srv__Redirect_Response__fini(&data[i - 1]);
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
tangerbot_msgs__srv__Redirect_Response__Sequence__fini(tangerbot_msgs__srv__Redirect_Response__Sequence * array)
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
      tangerbot_msgs__srv__Redirect_Response__fini(&array->data[i]);
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

tangerbot_msgs__srv__Redirect_Response__Sequence *
tangerbot_msgs__srv__Redirect_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__srv__Redirect_Response__Sequence * array = (tangerbot_msgs__srv__Redirect_Response__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__srv__Redirect_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__srv__Redirect_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__srv__Redirect_Response__Sequence__destroy(tangerbot_msgs__srv__Redirect_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__srv__Redirect_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__srv__Redirect_Response__Sequence__are_equal(const tangerbot_msgs__srv__Redirect_Response__Sequence * lhs, const tangerbot_msgs__srv__Redirect_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__srv__Redirect_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__srv__Redirect_Response__Sequence__copy(
  const tangerbot_msgs__srv__Redirect_Response__Sequence * input,
  tangerbot_msgs__srv__Redirect_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__srv__Redirect_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__srv__Redirect_Response * data =
      (tangerbot_msgs__srv__Redirect_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__srv__Redirect_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__srv__Redirect_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__srv__Redirect_Response__copy(
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
// #include "tangerbot_msgs/srv/detail/redirect__functions.h"

bool
tangerbot_msgs__srv__Redirect_Event__init(tangerbot_msgs__srv__Redirect_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    tangerbot_msgs__srv__Redirect_Event__fini(msg);
    return false;
  }
  // request
  if (!tangerbot_msgs__srv__Redirect_Request__Sequence__init(&msg->request, 0)) {
    tangerbot_msgs__srv__Redirect_Event__fini(msg);
    return false;
  }
  // response
  if (!tangerbot_msgs__srv__Redirect_Response__Sequence__init(&msg->response, 0)) {
    tangerbot_msgs__srv__Redirect_Event__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__srv__Redirect_Event__fini(tangerbot_msgs__srv__Redirect_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  tangerbot_msgs__srv__Redirect_Request__Sequence__fini(&msg->request);
  // response
  tangerbot_msgs__srv__Redirect_Response__Sequence__fini(&msg->response);
}

bool
tangerbot_msgs__srv__Redirect_Event__are_equal(const tangerbot_msgs__srv__Redirect_Event * lhs, const tangerbot_msgs__srv__Redirect_Event * rhs)
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
  if (!tangerbot_msgs__srv__Redirect_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!tangerbot_msgs__srv__Redirect_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__srv__Redirect_Event__copy(
  const tangerbot_msgs__srv__Redirect_Event * input,
  tangerbot_msgs__srv__Redirect_Event * output)
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
  if (!tangerbot_msgs__srv__Redirect_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!tangerbot_msgs__srv__Redirect_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

tangerbot_msgs__srv__Redirect_Event *
tangerbot_msgs__srv__Redirect_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__srv__Redirect_Event * msg = (tangerbot_msgs__srv__Redirect_Event *)allocator.allocate(sizeof(tangerbot_msgs__srv__Redirect_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__srv__Redirect_Event));
  bool success = tangerbot_msgs__srv__Redirect_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__srv__Redirect_Event__destroy(tangerbot_msgs__srv__Redirect_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__srv__Redirect_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__srv__Redirect_Event__Sequence__init(tangerbot_msgs__srv__Redirect_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__srv__Redirect_Event * data = NULL;

  if (size) {
    data = (tangerbot_msgs__srv__Redirect_Event *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__srv__Redirect_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__srv__Redirect_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__srv__Redirect_Event__fini(&data[i - 1]);
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
tangerbot_msgs__srv__Redirect_Event__Sequence__fini(tangerbot_msgs__srv__Redirect_Event__Sequence * array)
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
      tangerbot_msgs__srv__Redirect_Event__fini(&array->data[i]);
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

tangerbot_msgs__srv__Redirect_Event__Sequence *
tangerbot_msgs__srv__Redirect_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__srv__Redirect_Event__Sequence * array = (tangerbot_msgs__srv__Redirect_Event__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__srv__Redirect_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__srv__Redirect_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__srv__Redirect_Event__Sequence__destroy(tangerbot_msgs__srv__Redirect_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__srv__Redirect_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__srv__Redirect_Event__Sequence__are_equal(const tangerbot_msgs__srv__Redirect_Event__Sequence * lhs, const tangerbot_msgs__srv__Redirect_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__srv__Redirect_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__srv__Redirect_Event__Sequence__copy(
  const tangerbot_msgs__srv__Redirect_Event__Sequence * input,
  tangerbot_msgs__srv__Redirect_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__srv__Redirect_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__srv__Redirect_Event * data =
      (tangerbot_msgs__srv__Redirect_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__srv__Redirect_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__srv__Redirect_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__srv__Redirect_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
