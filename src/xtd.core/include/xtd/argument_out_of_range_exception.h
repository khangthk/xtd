/// @file
/// @brief Contains xtd::argument_out_of_range_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "argument_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when one of the arguments provided to a method is out of range.
  /// @par Header
  /// ```cpp
  /// #include <xtd/argument_out_of_range_exception>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an xtd::argument_out_of_range_exception.
  /// @include argument_out_of_range_exception.cpp
  class argument_out_of_range_exception : public argument_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_out_of_range_exception(const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(default_message(), info) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, info) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, error, info) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, help_link, info) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit argument_out_of_range_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_out_of_range_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(default_message(), inner_exception, info) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, inner_exception, info) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, inner_exception, help_link, info) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, inner_exception, error, help_link, info) {}
    /// @}
    
    /// @cond
    argument_out_of_range_exception(const argument_out_of_range_exception&) = default;
    argument_out_of_range_exception& operator =(const argument_out_of_range_exception&) = default;
    /// @endcond
    
    /// @name Public static Methods
    
    /// @{
    /// @brief Throws an xtd::argument_out_of_range_exception if value is negative.
    /// @tparam value_t The type of the object to validate.
    /// @param value The argument to validate as non-negative.
    /// @param param_name (optional) The name of the parameter with which `value` corresponds.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    template <typename value_t>
    static void throw_if_negative(const value_t& value, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) {if (value < static_cast<value_t>(0)) throw argument_out_of_range_exception {string::format("value ('{0}') must be a non-negative value. (Parameter '{1}')\nActual value was {0}.", value, param_name, info)};}
    /// @brief Throws an xtd::argument_out_of_range_exception if value is zero.
    /// @tparam value_t The type of the object to validate.
    /// @param value The argument to validate as non-zero.
    /// @param param_name (optional) The name of the parameter with which `value` corresponds.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    template <typename value_t>
    static void throw_if_zero(const value_t& value, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) {if (value == static_cast<value_t>(0)) throw argument_out_of_range_exception {string::format("value ('{0}') must be a non-zero value. (Parameter '{1}')\nActual value was {0}.", value, param_name, info)};}
    /// @}

  private:
    const char* default_message() const noexcept {return "Specified argument is out of range of valid values."_t;}
  };
}
