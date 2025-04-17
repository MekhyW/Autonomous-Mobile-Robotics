// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/Aula8.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__AULA8__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__AULA8__BUILDER_HPP_

#include "custom_interfaces/srv/detail/aula8__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_Aula8_Request_b
{
public:
  explicit Init_Aula8_Request_b(::custom_interfaces::srv::Aula8_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::Aula8_Request b(::custom_interfaces::srv::Aula8_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::Aula8_Request msg_;
};

class Init_Aula8_Request_a
{
public:
  Init_Aula8_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Aula8_Request_b a(::custom_interfaces::srv::Aula8_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_Aula8_Request_b(msg_);
  }

private:
  ::custom_interfaces::srv::Aula8_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::Aula8_Request>()
{
  return custom_interfaces::srv::builder::Init_Aula8_Request_a();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_Aula8_Response_sum
{
public:
  Init_Aula8_Response_sum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::Aula8_Response sum(::custom_interfaces::srv::Aula8_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::Aula8_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::Aula8_Response>()
{
  return custom_interfaces::srv::builder::Init_Aula8_Response_sum();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__AULA8__BUILDER_HPP_
