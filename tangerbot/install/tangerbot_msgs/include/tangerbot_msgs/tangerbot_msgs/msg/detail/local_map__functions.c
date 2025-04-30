// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tangerbot_msgs:msg/LocalMap.idl
// generated code does not contain a copyright notice
#include "tangerbot_msgs/msg/detail/local_map__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robot_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
tangerbot_msgs__msg__LocalMap__init(tangerbot_msgs__msg__LocalMap * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__init(&msg->robot_id)) {
    tangerbot_msgs__msg__LocalMap__fini(msg);
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tangerbot_msgs__msg__LocalMap__fini(msg);
    return false;
  }
  // resolution
  // width
  // height
  // origin_x
  // origin_y
  // data
  if (!rosidl_runtime_c__int8__Sequence__init(&msg->data, 0)) {
    tangerbot_msgs__msg__LocalMap__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__msg__LocalMap__fini(tangerbot_msgs__msg__LocalMap * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  rosidl_runtime_c__String__fini(&msg->robot_id);
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // resolution
  // width
  // height
  // origin_x
  // origin_y
  // data
  rosidl_runtime_c__int8__Sequence__fini(&msg->data);
}

bool
tangerbot_msgs__msg__LocalMap__are_equal(const tangerbot_msgs__msg__LocalMap * lhs, const tangerbot_msgs__msg__LocalMap * rhs)
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
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // resolution
  if (lhs->resolution != rhs->resolution) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // origin_x
  if (lhs->origin_x != rhs->origin_x) {
    return false;
  }
  // origin_y
  if (lhs->origin_y != rhs->origin_y) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__int8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__msg__LocalMap__copy(
  const tangerbot_msgs__msg__LocalMap * input,
  tangerbot_msgs__msg__LocalMap * output)
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
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // resolution
  output->resolution = input->resolution;
  // width
  output->width = input->width;
  // height
  output->height = input->height;
  // origin_x
  output->origin_x = input->origin_x;
  // origin_y
  output->origin_y = input->origin_y;
  // data
  if (!rosidl_runtime_c__int8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

tangerbot_msgs__msg__LocalMap *
tangerbot_msgs__msg__LocalMap__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__msg__LocalMap * msg = (tangerbot_msgs__msg__LocalMap *)allocator.allocate(sizeof(tangerbot_msgs__msg__LocalMap), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__msg__LocalMap));
  bool success = tangerbot_msgs__msg__LocalMap__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__msg__LocalMap__destroy(tangerbot_msgs__msg__LocalMap * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__msg__LocalMap__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__msg__LocalMap__Sequence__init(tangerbot_msgs__msg__LocalMap__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__msg__LocalMap * data = NULL;

  if (size) {
    data = (tangerbot_msgs__msg__LocalMap *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__msg__LocalMap), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__msg__LocalMap__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__msg__LocalMap__fini(&data[i - 1]);
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
tangerbot_msgs__msg__LocalMap__Sequence__fini(tangerbot_msgs__msg__LocalMap__Sequence * array)
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
      tangerbot_msgs__msg__LocalMap__fini(&array->data[i]);
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

tangerbot_msgs__msg__LocalMap__Sequence *
tangerbot_msgs__msg__LocalMap__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__msg__LocalMap__Sequence * array = (tangerbot_msgs__msg__LocalMap__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__msg__LocalMap__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__msg__LocalMap__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__msg__LocalMap__Sequence__destroy(tangerbot_msgs__msg__LocalMap__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__msg__LocalMap__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__msg__LocalMap__Sequence__are_equal(const tangerbot_msgs__msg__LocalMap__Sequence * lhs, const tangerbot_msgs__msg__LocalMap__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__msg__LocalMap__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__msg__LocalMap__Sequence__copy(
  const tangerbot_msgs__msg__LocalMap__Sequence * input,
  tangerbot_msgs__msg__LocalMap__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__msg__LocalMap);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__msg__LocalMap * data =
      (tangerbot_msgs__msg__LocalMap *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__msg__LocalMap__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__msg__LocalMap__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__msg__LocalMap__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
