// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tangerbot_msgs:msg/DecodedVoice.idl
// generated code does not contain a copyright notice

#include "tangerbot_msgs/msg/detail/decoded_voice__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__msg__DecodedVoice__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd5, 0xd5, 0x55, 0xa9, 0xf6, 0xad, 0xaa, 0x2d,
      0xeb, 0xbc, 0xf9, 0xf0, 0xa8, 0xd2, 0xb3, 0x60,
      0x47, 0x65, 0x0e, 0xef, 0x05, 0x29, 0x86, 0x14,
      0xd9, 0x37, 0x69, 0x44, 0x61, 0x3f, 0x6e, 0x1b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char tangerbot_msgs__msg__DecodedVoice__TYPE_NAME[] = "tangerbot_msgs/msg/DecodedVoice";

// Define type names, field names, and default values
static char tangerbot_msgs__msg__DecodedVoice__FIELD_NAME__user_id[] = "user_id";
static char tangerbot_msgs__msg__DecodedVoice__FIELD_NAME__text[] = "text";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__msg__DecodedVoice__FIELDS[] = {
  {
    {tangerbot_msgs__msg__DecodedVoice__FIELD_NAME__user_id, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__msg__DecodedVoice__FIELD_NAME__text, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__msg__DecodedVoice__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__msg__DecodedVoice__TYPE_NAME, 31, 31},
      {tangerbot_msgs__msg__DecodedVoice__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string user_id\n"
  "string text";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__msg__DecodedVoice__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__msg__DecodedVoice__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 26, 26},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__msg__DecodedVoice__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__msg__DecodedVoice__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
