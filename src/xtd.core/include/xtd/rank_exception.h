/// @file
/// @brief Contains xtd::rank_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "system_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when an array with the wrong number of dimensions is passed to a method.
  /// @par Header
  /// ```cpp
  /// #include <xtd/rank_exception>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an rank_exception.
  /// @include rank_exception.cpp
  /// @remarks xtd::rank_exception uses the HRESULT COR_E_RANK, that has the value 0x80131517.
  /// @todo add param_name property and constructors param (param_name is the parameter that cause the exception).
  class rank_exception : public system_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class rank_exception
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit rank_exception(const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(default_message(), default_error(), info) {}
    /// @brief Create a new instance of class rank_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit rank_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, default_error(), info) {}
    /// @brief Create a new instance of class rank_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit rank_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, error, info) {}
    /// @brief Create a new instance of class rank_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit rank_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, default_error(), help_link, info) {}
    /// @brief Create a new instance of class rank_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit rank_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class rank_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit rank_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(default_message(), inner_exception, default_error(), info) {}
    /// @brief Create a new instance of class rank_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit rank_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, inner_exception, default_error(), info) {}
    /// @brief Create a new instance of class rank_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit rank_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class rank_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit rank_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, inner_exception, default_error(), help_link, info) {}
    /// @brief Create a new instance of class rank_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit rank_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, inner_exception, error, help_link, info) {}
    /// @}
    
    /// @cond
    rank_exception(const rank_exception&) = default;
    rank_exception& operator =(const rank_exception&) = default;
    /// @endcond
    
  private:
    const char* default_message() const noexcept {return "Attempted to operate on an array with the incorrect number of dimensions."_t;}
    const std::error_code default_error() const noexcept {return {static_cast<int>(0x80131517), std::system_category()};}
  };
}

/// @brief Helper on xtd::rank_exception to call it with current stack frame information.
/// @par Header
/// ```cpp
/// #include <xtd/rank_exception>
/// ```
/// @par Library
/// xtd.core
/// @ingroup xtd_core exceptions
/// @remarks Is equivalent to xtd::rank_exception {{any argument}, csf_}
/// ```cpp
/// void my_func() {
///   if (invalid_info) throw rank_exception_(); // same as : throw rank_exception {csf_};
///   if (invalid_value) throw rank_exception_("Bad value"); // same as : throw rank_exception {"Bad value", csf_};
///   ...
/// }
/// ```
#define rank_exception_(...) rank_exception(add_csf_(__VA_ARGS__))
