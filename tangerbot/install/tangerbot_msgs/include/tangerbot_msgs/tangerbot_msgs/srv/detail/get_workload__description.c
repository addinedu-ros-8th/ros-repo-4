// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tangerbot_msgs:srv/GetWorkload.idl
// generated code does not contain a copyright notice

#include "tangerbot_msgs/srv/detail/get_workload__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__srv__GetWorkload__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7c, 0x52, 0xc4, 0xc4, 0x0f, 0xd5, 0x13, 0x00,
      0xe0, 0x16, 0x04, 0xbe, 0xa4, 0xb0, 0x6a, 0x28,
      0x53, 0x91, 0xc7, 0x34, 0x44, 0xad, 0x68, 0x56,
      0x47, 0x40, 0x8f, 0xba, 0xce, 0xbc, 0xeb, 0x4e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__srv__GetWorkload_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb6, 0x50, 0x16, 0xf8, 0x27, 0x2d, 0x94, 0xdf,
      0x2e, 0x13, 0xcb, 0x3c, 0xa5, 0x78, 0xbe, 0xc3,
      0xa4, 0xf2, 0x3f, 0xf4, 0xbb, 0xa8, 0x2d, 0x69,
      0x73, 0xa0, 0x9f, 0x5e, 0x6f, 0x3d, 0xe3, 0xf9,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__srv__GetWorkload_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb4, 0xdd, 0xcd, 0x5d, 0x23, 0x06, 0x29, 0x25,
      0x0a, 0xcc, 0xbb, 0x0e, 0x22, 0xbc, 0xae, 0x3e,
      0x87, 0xea, 0xc8, 0x68, 0x58, 0x4c, 0xce, 0xf3,
      0x5f, 0x06, 0x48, 0x4b, 0x8f, 0xce, 0xaa, 0x2f,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__srv__GetWorkload_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd2, 0xd7, 0x07, 0x16, 0xf0, 0xde, 0x5c, 0xf2,
      0x89, 0x01, 0x17, 0xfe, 0xd7, 0x2e, 0xcc, 0x42,
      0x87, 0x56, 0xce, 0xce, 0x28, 0xf7, 0x09, 0xae,
      0x4c, 0x87, 0x3a, 0x44, 0x34, 0xe6, 0x87, 0xd4,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

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
#endif

static char tangerbot_msgs__srv__GetWorkload__TYPE_NAME[] = "tangerbot_msgs/srv/GetWorkload";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char tangerbot_msgs__srv__GetWorkload_Event__TYPE_NAME[] = "tangerbot_msgs/srv/GetWorkload_Event";
static char tangerbot_msgs__srv__GetWorkload_Request__TYPE_NAME[] = "tangerbot_msgs/srv/GetWorkload_Request";
static char tangerbot_msgs__srv__GetWorkload_Response__TYPE_NAME[] = "tangerbot_msgs/srv/GetWorkload_Response";

// Define type names, field names, and default values
static char tangerbot_msgs__srv__GetWorkload__FIELD_NAME__request_message[] = "request_message";
static char tangerbot_msgs__srv__GetWorkload__FIELD_NAME__response_message[] = "response_message";
static char tangerbot_msgs__srv__GetWorkload__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__srv__GetWorkload__FIELDS[] = {
  {
    {tangerbot_msgs__srv__GetWorkload__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tangerbot_msgs__srv__GetWorkload_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__GetWorkload__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tangerbot_msgs__srv__GetWorkload_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__GetWorkload__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tangerbot_msgs__srv__GetWorkload_Event__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tangerbot_msgs__srv__GetWorkload__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__GetWorkload_Event__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__GetWorkload_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__GetWorkload_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__srv__GetWorkload__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__srv__GetWorkload__TYPE_NAME, 30, 30},
      {tangerbot_msgs__srv__GetWorkload__FIELDS, 3, 3},
    },
    {tangerbot_msgs__srv__GetWorkload__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = tangerbot_msgs__srv__GetWorkload_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = tangerbot_msgs__srv__GetWorkload_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = tangerbot_msgs__srv__GetWorkload_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tangerbot_msgs__srv__GetWorkload_Request__FIELD_NAME__robot_id[] = "robot_id";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__srv__GetWorkload_Request__FIELDS[] = {
  {
    {tangerbot_msgs__srv__GetWorkload_Request__FIELD_NAME__robot_id, 8, 8},
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
tangerbot_msgs__srv__GetWorkload_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__srv__GetWorkload_Request__TYPE_NAME, 38, 38},
      {tangerbot_msgs__srv__GetWorkload_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tangerbot_msgs__srv__GetWorkload_Response__FIELD_NAME__workload[] = "workload";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__srv__GetWorkload_Response__FIELDS[] = {
  {
    {tangerbot_msgs__srv__GetWorkload_Response__FIELD_NAME__workload, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__srv__GetWorkload_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__srv__GetWorkload_Response__TYPE_NAME, 39, 39},
      {tangerbot_msgs__srv__GetWorkload_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tangerbot_msgs__srv__GetWorkload_Event__FIELD_NAME__info[] = "info";
static char tangerbot_msgs__srv__GetWorkload_Event__FIELD_NAME__request[] = "request";
static char tangerbot_msgs__srv__GetWorkload_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__srv__GetWorkload_Event__FIELDS[] = {
  {
    {tangerbot_msgs__srv__GetWorkload_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__GetWorkload_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {tangerbot_msgs__srv__GetWorkload_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__GetWorkload_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {tangerbot_msgs__srv__GetWorkload_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tangerbot_msgs__srv__GetWorkload_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__GetWorkload_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__GetWorkload_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__srv__GetWorkload_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__srv__GetWorkload_Event__TYPE_NAME, 36, 36},
      {tangerbot_msgs__srv__GetWorkload_Event__FIELDS, 3, 3},
    },
    {tangerbot_msgs__srv__GetWorkload_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = tangerbot_msgs__srv__GetWorkload_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = tangerbot_msgs__srv__GetWorkload_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string robot_id\n"
  "---\n"
  "float32 workload";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__srv__GetWorkload__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__srv__GetWorkload__TYPE_NAME, 30, 30},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 36, 36},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__srv__GetWorkload_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__srv__GetWorkload_Request__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__srv__GetWorkload_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__srv__GetWorkload_Response__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__srv__GetWorkload_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__srv__GetWorkload_Event__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__srv__GetWorkload__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__srv__GetWorkload__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *tangerbot_msgs__srv__GetWorkload_Event__get_individual_type_description_source(NULL);
    sources[4] = *tangerbot_msgs__srv__GetWorkload_Request__get_individual_type_description_source(NULL);
    sources[5] = *tangerbot_msgs__srv__GetWorkload_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__srv__GetWorkload_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__srv__GetWorkload_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__srv__GetWorkload_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__srv__GetWorkload_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__srv__GetWorkload_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__srv__GetWorkload_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *tangerbot_msgs__srv__GetWorkload_Request__get_individual_type_description_source(NULL);
    sources[4] = *tangerbot_msgs__srv__GetWorkload_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
