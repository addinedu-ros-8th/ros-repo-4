// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tangerbot_msgs:srv/HandleRawVoice.idl
// generated code does not contain a copyright notice

#include "tangerbot_msgs/srv/detail/handle_raw_voice__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__srv__HandleRawVoice__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xec, 0x40, 0x16, 0x1d, 0x3f, 0x96, 0x89, 0x09,
      0xc0, 0x8a, 0x75, 0x76, 0x17, 0x03, 0x31, 0xe2,
      0x2e, 0x26, 0xfe, 0x08, 0x18, 0x43, 0x6a, 0xbd,
      0x4a, 0xf9, 0x65, 0x55, 0xac, 0xae, 0x4a, 0x8d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__srv__HandleRawVoice_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7d, 0x52, 0xc1, 0x18, 0x24, 0x31, 0x2b, 0xf2,
      0xf5, 0xc2, 0x10, 0xa8, 0xec, 0xde, 0x6a, 0xf5,
      0x27, 0xfe, 0xe8, 0x67, 0x9c, 0x55, 0xad, 0x89,
      0x88, 0x50, 0x78, 0x21, 0xc5, 0x5f, 0x34, 0xdb,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__srv__HandleRawVoice_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2a, 0x31, 0x69, 0xd2, 0xbd, 0x5e, 0xcb, 0x16,
      0xf1, 0xde, 0xbe, 0xe3, 0x10, 0xd5, 0x2d, 0x3e,
      0x43, 0x3f, 0x91, 0x51, 0x75, 0x06, 0x27, 0x6c,
      0x23, 0x3a, 0x49, 0xd9, 0x47, 0x9c, 0x01, 0x13,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__srv__HandleRawVoice_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd0, 0x35, 0x80, 0x82, 0x49, 0xc4, 0xec, 0xe5,
      0x0a, 0x67, 0xf8, 0x02, 0x87, 0xf7, 0xb1, 0x9c,
      0xbf, 0xfc, 0x16, 0x8d, 0x58, 0x15, 0xf4, 0x10,
      0x88, 0xc5, 0x52, 0xf2, 0xf6, 0x81, 0x3d, 0x13,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/multi_array_layout__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/multi_array_dimension__functions.h"
#include "std_msgs/msg/detail/byte_multi_array__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
static const rosidl_type_hash_t std_msgs__msg__ByteMultiArray__EXPECTED_HASH = {1, {
    0x97, 0x2f, 0xec, 0x7f, 0x50, 0xab, 0x3c, 0x1d,
    0x06, 0x78, 0x3c, 0x22, 0x8e, 0x79, 0xe8, 0xa9,
    0xa5, 0x09, 0x02, 0x17, 0x08, 0xc5, 0x11, 0xc0,
    0x59, 0x92, 0x62, 0x61, 0xad, 0xa9, 0x01, 0xd4,
  }};
static const rosidl_type_hash_t std_msgs__msg__MultiArrayDimension__EXPECTED_HASH = {1, {
    0x5e, 0x77, 0x3a, 0x60, 0xa4, 0xc7, 0xfc, 0x8a,
    0x54, 0x98, 0x5f, 0x30, 0x7c, 0x78, 0x37, 0xaa,
    0x29, 0x94, 0x25, 0x2a, 0x12, 0x6c, 0x30, 0x19,
    0x57, 0xa2, 0x4e, 0x31, 0x28, 0x2c, 0x9c, 0xbe,
  }};
static const rosidl_type_hash_t std_msgs__msg__MultiArrayLayout__EXPECTED_HASH = {1, {
    0x4c, 0x66, 0xe6, 0xf7, 0x8e, 0x74, 0x0a, 0xc1,
    0x03, 0xa9, 0x4c, 0xf6, 0x32, 0x59, 0xf9, 0x68,
    0xe4, 0x8c, 0x61, 0x7e, 0x76, 0x99, 0xe8, 0x29,
    0xb6, 0x3c, 0x21, 0xa5, 0xcb, 0x50, 0xda, 0xc6,
  }};
#endif

static char tangerbot_msgs__srv__HandleRawVoice__TYPE_NAME[] = "tangerbot_msgs/srv/HandleRawVoice";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char std_msgs__msg__ByteMultiArray__TYPE_NAME[] = "std_msgs/msg/ByteMultiArray";
static char std_msgs__msg__MultiArrayDimension__TYPE_NAME[] = "std_msgs/msg/MultiArrayDimension";
static char std_msgs__msg__MultiArrayLayout__TYPE_NAME[] = "std_msgs/msg/MultiArrayLayout";
static char tangerbot_msgs__srv__HandleRawVoice_Event__TYPE_NAME[] = "tangerbot_msgs/srv/HandleRawVoice_Event";
static char tangerbot_msgs__srv__HandleRawVoice_Request__TYPE_NAME[] = "tangerbot_msgs/srv/HandleRawVoice_Request";
static char tangerbot_msgs__srv__HandleRawVoice_Response__TYPE_NAME[] = "tangerbot_msgs/srv/HandleRawVoice_Response";

// Define type names, field names, and default values
static char tangerbot_msgs__srv__HandleRawVoice__FIELD_NAME__request_message[] = "request_message";
static char tangerbot_msgs__srv__HandleRawVoice__FIELD_NAME__response_message[] = "response_message";
static char tangerbot_msgs__srv__HandleRawVoice__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__srv__HandleRawVoice__FIELDS[] = {
  {
    {tangerbot_msgs__srv__HandleRawVoice__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tangerbot_msgs__srv__HandleRawVoice_Request__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__HandleRawVoice__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tangerbot_msgs__srv__HandleRawVoice_Response__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__HandleRawVoice__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tangerbot_msgs__srv__HandleRawVoice_Event__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tangerbot_msgs__srv__HandleRawVoice__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__ByteMultiArray__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayDimension__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayLayout__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__HandleRawVoice_Event__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__HandleRawVoice_Request__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__HandleRawVoice_Response__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__srv__HandleRawVoice__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__srv__HandleRawVoice__TYPE_NAME, 33, 33},
      {tangerbot_msgs__srv__HandleRawVoice__FIELDS, 3, 3},
    },
    {tangerbot_msgs__srv__HandleRawVoice__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__ByteMultiArray__EXPECTED_HASH, std_msgs__msg__ByteMultiArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__ByteMultiArray__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayDimension__EXPECTED_HASH, std_msgs__msg__MultiArrayDimension__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__MultiArrayDimension__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayLayout__EXPECTED_HASH, std_msgs__msg__MultiArrayLayout__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = std_msgs__msg__MultiArrayLayout__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = tangerbot_msgs__srv__HandleRawVoice_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = tangerbot_msgs__srv__HandleRawVoice_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[7].fields = tangerbot_msgs__srv__HandleRawVoice_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tangerbot_msgs__srv__HandleRawVoice_Request__FIELD_NAME__robot_id[] = "robot_id";
static char tangerbot_msgs__srv__HandleRawVoice_Request__FIELD_NAME__user_id[] = "user_id";
static char tangerbot_msgs__srv__HandleRawVoice_Request__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__srv__HandleRawVoice_Request__FIELDS[] = {
  {
    {tangerbot_msgs__srv__HandleRawVoice_Request__FIELD_NAME__robot_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__HandleRawVoice_Request__FIELD_NAME__user_id, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__HandleRawVoice_Request__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__ByteMultiArray__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tangerbot_msgs__srv__HandleRawVoice_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {std_msgs__msg__ByteMultiArray__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayDimension__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayLayout__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__srv__HandleRawVoice_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__srv__HandleRawVoice_Request__TYPE_NAME, 41, 41},
      {tangerbot_msgs__srv__HandleRawVoice_Request__FIELDS, 3, 3},
    },
    {tangerbot_msgs__srv__HandleRawVoice_Request__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&std_msgs__msg__ByteMultiArray__EXPECTED_HASH, std_msgs__msg__ByteMultiArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = std_msgs__msg__ByteMultiArray__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayDimension__EXPECTED_HASH, std_msgs__msg__MultiArrayDimension__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__MultiArrayDimension__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayLayout__EXPECTED_HASH, std_msgs__msg__MultiArrayLayout__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__MultiArrayLayout__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tangerbot_msgs__srv__HandleRawVoice_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__srv__HandleRawVoice_Response__FIELDS[] = {
  {
    {tangerbot_msgs__srv__HandleRawVoice_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__srv__HandleRawVoice_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__srv__HandleRawVoice_Response__TYPE_NAME, 42, 42},
      {tangerbot_msgs__srv__HandleRawVoice_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tangerbot_msgs__srv__HandleRawVoice_Event__FIELD_NAME__info[] = "info";
static char tangerbot_msgs__srv__HandleRawVoice_Event__FIELD_NAME__request[] = "request";
static char tangerbot_msgs__srv__HandleRawVoice_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__srv__HandleRawVoice_Event__FIELDS[] = {
  {
    {tangerbot_msgs__srv__HandleRawVoice_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__HandleRawVoice_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {tangerbot_msgs__srv__HandleRawVoice_Request__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__HandleRawVoice_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {tangerbot_msgs__srv__HandleRawVoice_Response__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tangerbot_msgs__srv__HandleRawVoice_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__ByteMultiArray__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayDimension__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayLayout__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__HandleRawVoice_Request__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__HandleRawVoice_Response__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__srv__HandleRawVoice_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__srv__HandleRawVoice_Event__TYPE_NAME, 39, 39},
      {tangerbot_msgs__srv__HandleRawVoice_Event__FIELDS, 3, 3},
    },
    {tangerbot_msgs__srv__HandleRawVoice_Event__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__ByteMultiArray__EXPECTED_HASH, std_msgs__msg__ByteMultiArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__ByteMultiArray__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayDimension__EXPECTED_HASH, std_msgs__msg__MultiArrayDimension__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__MultiArrayDimension__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayLayout__EXPECTED_HASH, std_msgs__msg__MultiArrayLayout__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = std_msgs__msg__MultiArrayLayout__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = tangerbot_msgs__srv__HandleRawVoice_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = tangerbot_msgs__srv__HandleRawVoice_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string robot_id # if robot\n"
  "string user_id # if user gui\n"
  "std_msgs/ByteMultiArray data\n"
  "---\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__srv__HandleRawVoice__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__srv__HandleRawVoice__TYPE_NAME, 33, 33},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 101, 101},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__srv__HandleRawVoice_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__srv__HandleRawVoice_Request__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__srv__HandleRawVoice_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__srv__HandleRawVoice_Response__TYPE_NAME, 42, 42},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__srv__HandleRawVoice_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__srv__HandleRawVoice_Event__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__srv__HandleRawVoice__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__srv__HandleRawVoice__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__ByteMultiArray__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__MultiArrayDimension__get_individual_type_description_source(NULL);
    sources[5] = *std_msgs__msg__MultiArrayLayout__get_individual_type_description_source(NULL);
    sources[6] = *tangerbot_msgs__srv__HandleRawVoice_Event__get_individual_type_description_source(NULL);
    sources[7] = *tangerbot_msgs__srv__HandleRawVoice_Request__get_individual_type_description_source(NULL);
    sources[8] = *tangerbot_msgs__srv__HandleRawVoice_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__srv__HandleRawVoice_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__srv__HandleRawVoice_Request__get_individual_type_description_source(NULL),
    sources[1] = *std_msgs__msg__ByteMultiArray__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__MultiArrayDimension__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__MultiArrayLayout__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__srv__HandleRawVoice_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__srv__HandleRawVoice_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__srv__HandleRawVoice_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__srv__HandleRawVoice_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__ByteMultiArray__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__MultiArrayDimension__get_individual_type_description_source(NULL);
    sources[5] = *std_msgs__msg__MultiArrayLayout__get_individual_type_description_source(NULL);
    sources[6] = *tangerbot_msgs__srv__HandleRawVoice_Request__get_individual_type_description_source(NULL);
    sources[7] = *tangerbot_msgs__srv__HandleRawVoice_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
