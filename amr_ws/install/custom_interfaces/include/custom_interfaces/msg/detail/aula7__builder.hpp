// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/Aula7.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__AULA7__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__AULA7__BUILDER_HPP_

#include "custom_interfaces/msg/detail/aula7__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_Aula7_message
{
public:
  explicit Init_Aula7_message(::custom_interfaces::msg::Aula7 & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::Aula7 message(::custom_interfaces::msg::Aula7::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::Aula7 msg_;
};

class Init_Aula7_count
{
public:
  Init_Aula7_count()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Aula7_message count(::custom_interfaces::msg::Aula7::_count_type arg)
  {
    msg_.count = std::move(arg);
    return Init_Aula7_message(msg_);
  }

private:
  ::custom_interfaces::msg::Aula7 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::Aula7>()
{
  return custom_interfaces::msg::builder::Init_Aula7_count();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__AULA7__BUILDER_HPP_
