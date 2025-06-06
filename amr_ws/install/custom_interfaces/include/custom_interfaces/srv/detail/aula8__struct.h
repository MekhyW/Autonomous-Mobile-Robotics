// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/Aula8.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__AULA8__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__AULA8__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/Aula8 in the package custom_interfaces.
typedef struct custom_interfaces__srv__Aula8_Request
{
  int64_t a;
  int64_t b;
} custom_interfaces__srv__Aula8_Request;

// Struct for a sequence of custom_interfaces__srv__Aula8_Request.
typedef struct custom_interfaces__srv__Aula8_Request__Sequence
{
  custom_interfaces__srv__Aula8_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__Aula8_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/Aula8 in the package custom_interfaces.
typedef struct custom_interfaces__srv__Aula8_Response
{
  int64_t sum;
} custom_interfaces__srv__Aula8_Response;

// Struct for a sequence of custom_interfaces__srv__Aula8_Response.
typedef struct custom_interfaces__srv__Aula8_Response__Sequence
{
  custom_interfaces__srv__Aula8_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__Aula8_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__AULA8__STRUCT_H_
