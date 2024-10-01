/// @file
/// @brief Contains xtd::collections::key_not_found_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../system_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The exception that is thrown when the key specified for accessing an element in a collection does not match any key in the collection.
    /// ```cpp
    /// class key_not_found_exception : public xtd::system_exception
    /// ```
    /// @par Inheritance
    /// xtd::system_exception → xtd::collections::key_not_found_exception
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/key_not_found_exception>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core exceptions
    /// @par Examples
    /// The following example demonstrates how to throw and catch an key_not_found_exception.
    /// @include key_not_found_exception.cpp
    class key_not_found_exception : public xtd::system_exception {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new instance of class key_not_found_exception
      /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      explicit key_not_found_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit key_not_found_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      template<typename exception_t>
      key_not_found_exception(const std::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : xtd::system_exception(message, inner_exception, stack_frame) {error_code(h_result::make_error_code(h_result::E_POINTER));}
      
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::key_not_found_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::key_not_found_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.")]]
      key_not_found_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::key_not_found_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::key_not_found_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      key_not_found_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::key_not_found_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::key_not_found_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      key_not_found_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
      /// @brief Create a new instance of class key_not_found_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      /// @deprecated Use xtd::key_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::key_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.")]]
      key_not_found_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::key_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::key_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.")]]
      key_not_found_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::key_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::key_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.")]]
      key_not_found_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::key_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::key_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      key_not_found_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::key_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::key_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      key_not_found_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
      /// @}
      
      /// @cond
      key_not_found_exception(const key_not_found_exception&) = default;
      key_not_found_exception& operator =(const key_not_found_exception&) = default;
      /// @endcond
    };
  }
}
