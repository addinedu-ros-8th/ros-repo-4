// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tangerbot_msgs:msg/Gesture.idl
// generated code does not contain a copyright notice

#include "tangerbot_msgs/msg/detail/gesture__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__msg__Gesture__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5b, 0x13, 0xf7, 0xad, 0x83, 0x2d, 0xcf, 0x19,
      0x7c, 0xc6, 0xea, 0xa4, 0xdb, 0xee, 0xda, 0x5d,
      0xbf, 0x19, 0x1e, 0xdd, 0x68, 0x3f, 0xc2, 0xae,
      0xc5, 0x5c, 0x89, 0xdf, 0x27, 0x91, 0xc3, 0x8d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/point__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
#endif

static char tangerbot_msgs__msg__Gesture__TYPE_NAME[] = "tangerbot_msgs/msg/Gesture";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";

// Define type names, field names, and default values
static char tangerbot_msgs__msg__Gesture__FIELD_NAME__robot_id[] = "robot_id";
static char tangerbot_msgs__msg__Gesture__FIELD_NAME__point[] = "point";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__msg__Gesture__FIELDS[] = {
  {
    {tangerbot_msgs__msg__Gesture__FIELD_NAME__robot_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__msg__Gesture__FIELD_NAME__point, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tangerbot_msgs__msg__Gesture__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__msg__Gesture__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__msg__Gesture__TYPE_NAME, 26, 26},
      {tangerbot_msgs__msg__Gesture__FIELDS, 2, 2},
    },
    {tangerbot_msgs__msg__Gesture__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string robot_id\n"
  "geometry_msgs/Point point";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__msg__Gesture__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__msg__Gesture__TYPE_NAME, 26, 26},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 41, 41},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__msg__Gesture__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__msg__Gesture__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
