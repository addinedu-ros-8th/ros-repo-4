// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tangerbot_msgs:action/NavigateToPose.idl
// generated code does not contain a copyright notice
#include "tangerbot_msgs/action/detail/navigate_to_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robot_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
tangerbot_msgs__action__NavigateToPose_Goal__init(tangerbot_msgs__action__NavigateToPose_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__init(&msg->robot_id)) {
    tangerbot_msgs__action__NavigateToPose_Goal__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->pose)) {
    tangerbot_msgs__action__NavigateToPose_Goal__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__action__NavigateToPose_Goal__fini(tangerbot_msgs__action__NavigateToPose_Goal * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  rosidl_runtime_c__String__fini(&msg->robot_id);
  // pose
  geometry_msgs__msg__PoseStamped__fini(&msg->pose);
}

bool
tangerbot_msgs__action__NavigateToPose_Goal__are_equal(const tangerbot_msgs__action__NavigateToPose_Goal * lhs, const tangerbot_msgs__action__NavigateToPose_Goal * rhs)
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
  // pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_Goal__copy(
  const tangerbot_msgs__action__NavigateToPose_Goal * input,
  tangerbot_msgs__action__NavigateToPose_Goal * output)
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
  // pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

tangerbot_msgs__action__NavigateToPose_Goal *
tangerbot_msgs__action__NavigateToPose_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_Goal * msg = (tangerbot_msgs__action__NavigateToPose_Goal *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__action__NavigateToPose_Goal));
  bool success = tangerbot_msgs__action__NavigateToPose_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__action__NavigateToPose_Goal__destroy(tangerbot_msgs__action__NavigateToPose_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__action__NavigateToPose_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__action__NavigateToPose_Goal__Sequence__init(tangerbot_msgs__action__NavigateToPose_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_Goal * data = NULL;

  if (size) {
    data = (tangerbot_msgs__action__NavigateToPose_Goal *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__action__NavigateToPose_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__action__NavigateToPose_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__action__NavigateToPose_Goal__fini(&data[i - 1]);
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
tangerbot_msgs__action__NavigateToPose_Goal__Sequence__fini(tangerbot_msgs__action__NavigateToPose_Goal__Sequence * array)
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
      tangerbot_msgs__action__NavigateToPose_Goal__fini(&array->data[i]);
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

tangerbot_msgs__action__NavigateToPose_Goal__Sequence *
tangerbot_msgs__action__NavigateToPose_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_Goal__Sequence * array = (tangerbot_msgs__action__NavigateToPose_Goal__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__action__NavigateToPose_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__action__NavigateToPose_Goal__Sequence__destroy(tangerbot_msgs__action__NavigateToPose_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__action__NavigateToPose_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__action__NavigateToPose_Goal__Sequence__are_equal(const tangerbot_msgs__action__NavigateToPose_Goal__Sequence * lhs, const tangerbot_msgs__action__NavigateToPose_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_Goal__Sequence__copy(
  const tangerbot_msgs__action__NavigateToPose_Goal__Sequence * input,
  tangerbot_msgs__action__NavigateToPose_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__action__NavigateToPose_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__action__NavigateToPose_Goal * data =
      (tangerbot_msgs__action__NavigateToPose_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__action__NavigateToPose_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__action__NavigateToPose_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `error_msg`
// Member `robot_id`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
tangerbot_msgs__action__NavigateToPose_Result__init(tangerbot_msgs__action__NavigateToPose_Result * msg)
{
  if (!msg) {
    return false;
  }
  // error_code
  // error_msg
  if (!rosidl_runtime_c__String__init(&msg->error_msg)) {
    tangerbot_msgs__action__NavigateToPose_Result__fini(msg);
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__init(&msg->robot_id)) {
    tangerbot_msgs__action__NavigateToPose_Result__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__action__NavigateToPose_Result__fini(tangerbot_msgs__action__NavigateToPose_Result * msg)
{
  if (!msg) {
    return;
  }
  // error_code
  // error_msg
  rosidl_runtime_c__String__fini(&msg->error_msg);
  // robot_id
  rosidl_runtime_c__String__fini(&msg->robot_id);
}

bool
tangerbot_msgs__action__NavigateToPose_Result__are_equal(const tangerbot_msgs__action__NavigateToPose_Result * lhs, const tangerbot_msgs__action__NavigateToPose_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // error_code
  if (lhs->error_code != rhs->error_code) {
    return false;
  }
  // error_msg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_msg), &(rhs->error_msg)))
  {
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
tangerbot_msgs__action__NavigateToPose_Result__copy(
  const tangerbot_msgs__action__NavigateToPose_Result * input,
  tangerbot_msgs__action__NavigateToPose_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // error_code
  output->error_code = input->error_code;
  // error_msg
  if (!rosidl_runtime_c__String__copy(
      &(input->error_msg), &(output->error_msg)))
  {
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

tangerbot_msgs__action__NavigateToPose_Result *
tangerbot_msgs__action__NavigateToPose_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_Result * msg = (tangerbot_msgs__action__NavigateToPose_Result *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__action__NavigateToPose_Result));
  bool success = tangerbot_msgs__action__NavigateToPose_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__action__NavigateToPose_Result__destroy(tangerbot_msgs__action__NavigateToPose_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__action__NavigateToPose_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__action__NavigateToPose_Result__Sequence__init(tangerbot_msgs__action__NavigateToPose_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_Result * data = NULL;

  if (size) {
    data = (tangerbot_msgs__action__NavigateToPose_Result *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__action__NavigateToPose_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__action__NavigateToPose_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__action__NavigateToPose_Result__fini(&data[i - 1]);
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
tangerbot_msgs__action__NavigateToPose_Result__Sequence__fini(tangerbot_msgs__action__NavigateToPose_Result__Sequence * array)
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
      tangerbot_msgs__action__NavigateToPose_Result__fini(&array->data[i]);
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

tangerbot_msgs__action__NavigateToPose_Result__Sequence *
tangerbot_msgs__action__NavigateToPose_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_Result__Sequence * array = (tangerbot_msgs__action__NavigateToPose_Result__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__action__NavigateToPose_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__action__NavigateToPose_Result__Sequence__destroy(tangerbot_msgs__action__NavigateToPose_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__action__NavigateToPose_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__action__NavigateToPose_Result__Sequence__are_equal(const tangerbot_msgs__action__NavigateToPose_Result__Sequence * lhs, const tangerbot_msgs__action__NavigateToPose_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_Result__Sequence__copy(
  const tangerbot_msgs__action__NavigateToPose_Result__Sequence * input,
  tangerbot_msgs__action__NavigateToPose_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__action__NavigateToPose_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__action__NavigateToPose_Result * data =
      (tangerbot_msgs__action__NavigateToPose_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__action__NavigateToPose_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__action__NavigateToPose_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `robot_id`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
tangerbot_msgs__action__NavigateToPose_Feedback__init(tangerbot_msgs__action__NavigateToPose_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__init(&msg->robot_id)) {
    tangerbot_msgs__action__NavigateToPose_Feedback__fini(msg);
    return false;
  }
  // distance_remaining
  return true;
}

void
tangerbot_msgs__action__NavigateToPose_Feedback__fini(tangerbot_msgs__action__NavigateToPose_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  rosidl_runtime_c__String__fini(&msg->robot_id);
  // distance_remaining
}

bool
tangerbot_msgs__action__NavigateToPose_Feedback__are_equal(const tangerbot_msgs__action__NavigateToPose_Feedback * lhs, const tangerbot_msgs__action__NavigateToPose_Feedback * rhs)
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
  // distance_remaining
  if (lhs->distance_remaining != rhs->distance_remaining) {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_Feedback__copy(
  const tangerbot_msgs__action__NavigateToPose_Feedback * input,
  tangerbot_msgs__action__NavigateToPose_Feedback * output)
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
  // distance_remaining
  output->distance_remaining = input->distance_remaining;
  return true;
}

tangerbot_msgs__action__NavigateToPose_Feedback *
tangerbot_msgs__action__NavigateToPose_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_Feedback * msg = (tangerbot_msgs__action__NavigateToPose_Feedback *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__action__NavigateToPose_Feedback));
  bool success = tangerbot_msgs__action__NavigateToPose_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__action__NavigateToPose_Feedback__destroy(tangerbot_msgs__action__NavigateToPose_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__action__NavigateToPose_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__action__NavigateToPose_Feedback__Sequence__init(tangerbot_msgs__action__NavigateToPose_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_Feedback * data = NULL;

  if (size) {
    data = (tangerbot_msgs__action__NavigateToPose_Feedback *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__action__NavigateToPose_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__action__NavigateToPose_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__action__NavigateToPose_Feedback__fini(&data[i - 1]);
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
tangerbot_msgs__action__NavigateToPose_Feedback__Sequence__fini(tangerbot_msgs__action__NavigateToPose_Feedback__Sequence * array)
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
      tangerbot_msgs__action__NavigateToPose_Feedback__fini(&array->data[i]);
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

tangerbot_msgs__action__NavigateToPose_Feedback__Sequence *
tangerbot_msgs__action__NavigateToPose_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_Feedback__Sequence * array = (tangerbot_msgs__action__NavigateToPose_Feedback__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__action__NavigateToPose_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__action__NavigateToPose_Feedback__Sequence__destroy(tangerbot_msgs__action__NavigateToPose_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__action__NavigateToPose_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__action__NavigateToPose_Feedback__Sequence__are_equal(const tangerbot_msgs__action__NavigateToPose_Feedback__Sequence * lhs, const tangerbot_msgs__action__NavigateToPose_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_Feedback__Sequence__copy(
  const tangerbot_msgs__action__NavigateToPose_Feedback__Sequence * input,
  tangerbot_msgs__action__NavigateToPose_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__action__NavigateToPose_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__action__NavigateToPose_Feedback * data =
      (tangerbot_msgs__action__NavigateToPose_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__action__NavigateToPose_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__action__NavigateToPose_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "tangerbot_msgs/action/detail/navigate_to_pose__functions.h"

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Request__init(tangerbot_msgs__action__NavigateToPose_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    tangerbot_msgs__action__NavigateToPose_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!tangerbot_msgs__action__NavigateToPose_Goal__init(&msg->goal)) {
    tangerbot_msgs__action__NavigateToPose_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__action__NavigateToPose_SendGoal_Request__fini(tangerbot_msgs__action__NavigateToPose_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  tangerbot_msgs__action__NavigateToPose_Goal__fini(&msg->goal);
}

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Request__are_equal(const tangerbot_msgs__action__NavigateToPose_SendGoal_Request * lhs, const tangerbot_msgs__action__NavigateToPose_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!tangerbot_msgs__action__NavigateToPose_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Request__copy(
  const tangerbot_msgs__action__NavigateToPose_SendGoal_Request * input,
  tangerbot_msgs__action__NavigateToPose_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!tangerbot_msgs__action__NavigateToPose_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

tangerbot_msgs__action__NavigateToPose_SendGoal_Request *
tangerbot_msgs__action__NavigateToPose_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_SendGoal_Request * msg = (tangerbot_msgs__action__NavigateToPose_SendGoal_Request *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Request));
  bool success = tangerbot_msgs__action__NavigateToPose_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__action__NavigateToPose_SendGoal_Request__destroy(tangerbot_msgs__action__NavigateToPose_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__action__NavigateToPose_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence__init(tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_SendGoal_Request * data = NULL;

  if (size) {
    data = (tangerbot_msgs__action__NavigateToPose_SendGoal_Request *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__action__NavigateToPose_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__action__NavigateToPose_SendGoal_Request__fini(&data[i - 1]);
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
tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence__fini(tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence * array)
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
      tangerbot_msgs__action__NavigateToPose_SendGoal_Request__fini(&array->data[i]);
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

tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence *
tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence * array = (tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence__destroy(tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence__are_equal(const tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence * lhs, const tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence__copy(
  const tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence * input,
  tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__action__NavigateToPose_SendGoal_Request * data =
      (tangerbot_msgs__action__NavigateToPose_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__action__NavigateToPose_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Response__init(tangerbot_msgs__action__NavigateToPose_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    tangerbot_msgs__action__NavigateToPose_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__action__NavigateToPose_SendGoal_Response__fini(tangerbot_msgs__action__NavigateToPose_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Response__are_equal(const tangerbot_msgs__action__NavigateToPose_SendGoal_Response * lhs, const tangerbot_msgs__action__NavigateToPose_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Response__copy(
  const tangerbot_msgs__action__NavigateToPose_SendGoal_Response * input,
  tangerbot_msgs__action__NavigateToPose_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

tangerbot_msgs__action__NavigateToPose_SendGoal_Response *
tangerbot_msgs__action__NavigateToPose_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_SendGoal_Response * msg = (tangerbot_msgs__action__NavigateToPose_SendGoal_Response *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Response));
  bool success = tangerbot_msgs__action__NavigateToPose_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__action__NavigateToPose_SendGoal_Response__destroy(tangerbot_msgs__action__NavigateToPose_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__action__NavigateToPose_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence__init(tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_SendGoal_Response * data = NULL;

  if (size) {
    data = (tangerbot_msgs__action__NavigateToPose_SendGoal_Response *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__action__NavigateToPose_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__action__NavigateToPose_SendGoal_Response__fini(&data[i - 1]);
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
tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence__fini(tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence * array)
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
      tangerbot_msgs__action__NavigateToPose_SendGoal_Response__fini(&array->data[i]);
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

tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence *
tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence * array = (tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence__destroy(tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence__are_equal(const tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence * lhs, const tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence__copy(
  const tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence * input,
  tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__action__NavigateToPose_SendGoal_Response * data =
      (tangerbot_msgs__action__NavigateToPose_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__action__NavigateToPose_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Response__copy(
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
// #include "tangerbot_msgs/action/detail/navigate_to_pose__functions.h"

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Event__init(tangerbot_msgs__action__NavigateToPose_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    tangerbot_msgs__action__NavigateToPose_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    tangerbot_msgs__action__NavigateToPose_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    tangerbot_msgs__action__NavigateToPose_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__action__NavigateToPose_SendGoal_Event__fini(tangerbot_msgs__action__NavigateToPose_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Event__are_equal(const tangerbot_msgs__action__NavigateToPose_SendGoal_Event * lhs, const tangerbot_msgs__action__NavigateToPose_SendGoal_Event * rhs)
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
  if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Event__copy(
  const tangerbot_msgs__action__NavigateToPose_SendGoal_Event * input,
  tangerbot_msgs__action__NavigateToPose_SendGoal_Event * output)
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
  if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

tangerbot_msgs__action__NavigateToPose_SendGoal_Event *
tangerbot_msgs__action__NavigateToPose_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_SendGoal_Event * msg = (tangerbot_msgs__action__NavigateToPose_SendGoal_Event *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Event));
  bool success = tangerbot_msgs__action__NavigateToPose_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__action__NavigateToPose_SendGoal_Event__destroy(tangerbot_msgs__action__NavigateToPose_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__action__NavigateToPose_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence__init(tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_SendGoal_Event * data = NULL;

  if (size) {
    data = (tangerbot_msgs__action__NavigateToPose_SendGoal_Event *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__action__NavigateToPose_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__action__NavigateToPose_SendGoal_Event__fini(&data[i - 1]);
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
tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence__fini(tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence * array)
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
      tangerbot_msgs__action__NavigateToPose_SendGoal_Event__fini(&array->data[i]);
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

tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence *
tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence * array = (tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence__destroy(tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence__are_equal(const tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence * lhs, const tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence__copy(
  const tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence * input,
  tangerbot_msgs__action__NavigateToPose_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__action__NavigateToPose_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__action__NavigateToPose_SendGoal_Event * data =
      (tangerbot_msgs__action__NavigateToPose_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__action__NavigateToPose_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Request__init(tangerbot_msgs__action__NavigateToPose_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    tangerbot_msgs__action__NavigateToPose_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__action__NavigateToPose_GetResult_Request__fini(tangerbot_msgs__action__NavigateToPose_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Request__are_equal(const tangerbot_msgs__action__NavigateToPose_GetResult_Request * lhs, const tangerbot_msgs__action__NavigateToPose_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Request__copy(
  const tangerbot_msgs__action__NavigateToPose_GetResult_Request * input,
  tangerbot_msgs__action__NavigateToPose_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

tangerbot_msgs__action__NavigateToPose_GetResult_Request *
tangerbot_msgs__action__NavigateToPose_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_GetResult_Request * msg = (tangerbot_msgs__action__NavigateToPose_GetResult_Request *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Request));
  bool success = tangerbot_msgs__action__NavigateToPose_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__action__NavigateToPose_GetResult_Request__destroy(tangerbot_msgs__action__NavigateToPose_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__action__NavigateToPose_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence__init(tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_GetResult_Request * data = NULL;

  if (size) {
    data = (tangerbot_msgs__action__NavigateToPose_GetResult_Request *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__action__NavigateToPose_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__action__NavigateToPose_GetResult_Request__fini(&data[i - 1]);
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
tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence__fini(tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence * array)
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
      tangerbot_msgs__action__NavigateToPose_GetResult_Request__fini(&array->data[i]);
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

tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence *
tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence * array = (tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence__destroy(tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence__are_equal(const tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence * lhs, const tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence__copy(
  const tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence * input,
  tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__action__NavigateToPose_GetResult_Request * data =
      (tangerbot_msgs__action__NavigateToPose_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__action__NavigateToPose_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__action__NavigateToPose_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "tangerbot_msgs/action/detail/navigate_to_pose__functions.h"

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Response__init(tangerbot_msgs__action__NavigateToPose_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!tangerbot_msgs__action__NavigateToPose_Result__init(&msg->result)) {
    tangerbot_msgs__action__NavigateToPose_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__action__NavigateToPose_GetResult_Response__fini(tangerbot_msgs__action__NavigateToPose_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  tangerbot_msgs__action__NavigateToPose_Result__fini(&msg->result);
}

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Response__are_equal(const tangerbot_msgs__action__NavigateToPose_GetResult_Response * lhs, const tangerbot_msgs__action__NavigateToPose_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!tangerbot_msgs__action__NavigateToPose_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Response__copy(
  const tangerbot_msgs__action__NavigateToPose_GetResult_Response * input,
  tangerbot_msgs__action__NavigateToPose_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!tangerbot_msgs__action__NavigateToPose_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

tangerbot_msgs__action__NavigateToPose_GetResult_Response *
tangerbot_msgs__action__NavigateToPose_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_GetResult_Response * msg = (tangerbot_msgs__action__NavigateToPose_GetResult_Response *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Response));
  bool success = tangerbot_msgs__action__NavigateToPose_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__action__NavigateToPose_GetResult_Response__destroy(tangerbot_msgs__action__NavigateToPose_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__action__NavigateToPose_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence__init(tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_GetResult_Response * data = NULL;

  if (size) {
    data = (tangerbot_msgs__action__NavigateToPose_GetResult_Response *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__action__NavigateToPose_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__action__NavigateToPose_GetResult_Response__fini(&data[i - 1]);
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
tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence__fini(tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence * array)
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
      tangerbot_msgs__action__NavigateToPose_GetResult_Response__fini(&array->data[i]);
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

tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence *
tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence * array = (tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence__destroy(tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence__are_equal(const tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence * lhs, const tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence__copy(
  const tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence * input,
  tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__action__NavigateToPose_GetResult_Response * data =
      (tangerbot_msgs__action__NavigateToPose_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__action__NavigateToPose_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__action__NavigateToPose_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "tangerbot_msgs/action/detail/navigate_to_pose__functions.h"

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Event__init(tangerbot_msgs__action__NavigateToPose_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    tangerbot_msgs__action__NavigateToPose_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence__init(&msg->request, 0)) {
    tangerbot_msgs__action__NavigateToPose_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence__init(&msg->response, 0)) {
    tangerbot_msgs__action__NavigateToPose_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__action__NavigateToPose_GetResult_Event__fini(tangerbot_msgs__action__NavigateToPose_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence__fini(&msg->request);
  // response
  tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence__fini(&msg->response);
}

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Event__are_equal(const tangerbot_msgs__action__NavigateToPose_GetResult_Event * lhs, const tangerbot_msgs__action__NavigateToPose_GetResult_Event * rhs)
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
  if (!tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Event__copy(
  const tangerbot_msgs__action__NavigateToPose_GetResult_Event * input,
  tangerbot_msgs__action__NavigateToPose_GetResult_Event * output)
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
  if (!tangerbot_msgs__action__NavigateToPose_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!tangerbot_msgs__action__NavigateToPose_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

tangerbot_msgs__action__NavigateToPose_GetResult_Event *
tangerbot_msgs__action__NavigateToPose_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_GetResult_Event * msg = (tangerbot_msgs__action__NavigateToPose_GetResult_Event *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Event));
  bool success = tangerbot_msgs__action__NavigateToPose_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__action__NavigateToPose_GetResult_Event__destroy(tangerbot_msgs__action__NavigateToPose_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__action__NavigateToPose_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence__init(tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_GetResult_Event * data = NULL;

  if (size) {
    data = (tangerbot_msgs__action__NavigateToPose_GetResult_Event *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__action__NavigateToPose_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__action__NavigateToPose_GetResult_Event__fini(&data[i - 1]);
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
tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence__fini(tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence * array)
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
      tangerbot_msgs__action__NavigateToPose_GetResult_Event__fini(&array->data[i]);
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

tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence *
tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence * array = (tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence__destroy(tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence__are_equal(const tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence * lhs, const tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence__copy(
  const tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence * input,
  tangerbot_msgs__action__NavigateToPose_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__action__NavigateToPose_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__action__NavigateToPose_GetResult_Event * data =
      (tangerbot_msgs__action__NavigateToPose_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__action__NavigateToPose_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__action__NavigateToPose_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "tangerbot_msgs/action/detail/navigate_to_pose__functions.h"

bool
tangerbot_msgs__action__NavigateToPose_FeedbackMessage__init(tangerbot_msgs__action__NavigateToPose_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    tangerbot_msgs__action__NavigateToPose_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!tangerbot_msgs__action__NavigateToPose_Feedback__init(&msg->feedback)) {
    tangerbot_msgs__action__NavigateToPose_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__action__NavigateToPose_FeedbackMessage__fini(tangerbot_msgs__action__NavigateToPose_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  tangerbot_msgs__action__NavigateToPose_Feedback__fini(&msg->feedback);
}

bool
tangerbot_msgs__action__NavigateToPose_FeedbackMessage__are_equal(const tangerbot_msgs__action__NavigateToPose_FeedbackMessage * lhs, const tangerbot_msgs__action__NavigateToPose_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!tangerbot_msgs__action__NavigateToPose_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_FeedbackMessage__copy(
  const tangerbot_msgs__action__NavigateToPose_FeedbackMessage * input,
  tangerbot_msgs__action__NavigateToPose_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!tangerbot_msgs__action__NavigateToPose_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

tangerbot_msgs__action__NavigateToPose_FeedbackMessage *
tangerbot_msgs__action__NavigateToPose_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_FeedbackMessage * msg = (tangerbot_msgs__action__NavigateToPose_FeedbackMessage *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__action__NavigateToPose_FeedbackMessage));
  bool success = tangerbot_msgs__action__NavigateToPose_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__action__NavigateToPose_FeedbackMessage__destroy(tangerbot_msgs__action__NavigateToPose_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__action__NavigateToPose_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence__init(tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_FeedbackMessage * data = NULL;

  if (size) {
    data = (tangerbot_msgs__action__NavigateToPose_FeedbackMessage *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__action__NavigateToPose_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__action__NavigateToPose_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__action__NavigateToPose_FeedbackMessage__fini(&data[i - 1]);
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
tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence__fini(tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence * array)
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
      tangerbot_msgs__action__NavigateToPose_FeedbackMessage__fini(&array->data[i]);
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

tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence *
tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence * array = (tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence__destroy(tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence__are_equal(const tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence * lhs, const tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence__copy(
  const tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence * input,
  tangerbot_msgs__action__NavigateToPose_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__action__NavigateToPose_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__action__NavigateToPose_FeedbackMessage * data =
      (tangerbot_msgs__action__NavigateToPose_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__action__NavigateToPose_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__action__NavigateToPose_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__action__NavigateToPose_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
