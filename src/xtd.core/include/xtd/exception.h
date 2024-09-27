/// @file
/// @brief Contains xtd::exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "diagnostics/stack_frame.h"
#include "diagnostics/stack_trace.h"
#include "core_export.h"
#include "h_results.h"
#include "literals.h"
#include "object.h"
#include "optional.h"
#include "ptr.h"
#include "size.h"
#include "string.h"
#include <cstdint>
#include <stdexcept>
#include <system_error>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Defines the base class for predefined exceptions in the xtd namespace.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  class core_export_ exception : public object, public std::exception {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Optional reference wrapper on std::exception
    using exception_ref = std::optional<std::reference_wrapper<const std::exception>>;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class exception
    /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
    /// @brief Create a new instance of class exception
    /// @param message Message string associate to the exception.
    /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit exception(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
    /// @brief Create a new instance of class exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    template<typename exception_t>
    exception(const xtd::string& message, const std::optional<exception_t>& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : exception(message, inner_exception.has_value() ? inner_exception.value().template memberwise_clone<exception_t>() : nullptr, info) {}

    /// @brief Create a new instance of class exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_framee) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0
    exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
    /// @brief Create a new instance of class exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_framee) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0
    exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
    /// @brief Create a new instance of class exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_framee) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0
    exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
    /// @brief Create a new instance of class exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    /// @deprecated Use xtd::exception (const xtd::string& message, const std::optional<exception_t>& inner_exception, const xtd::diagnostics::stack_frame& stack_framee) - Will be removed in version 0.4.0
    explicit exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
    /// @brief Create a new instance of class exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::exception (const xtd::string& message, const std::optional<exception_t>& inner_exception, const xtd::diagnostics::stack_frame& stack_framee) - Will be removed in version 0.4.0
    exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
    /// @brief Create a new instance of class exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::exception (const xtd::string& message, const std::optional<exception_t>& inner_exception, const xtd::diagnostics::stack_frame& stack_framee) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0
    exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
    /// @brief Create a new instance of class exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::exception (const xtd::string& message, const std::optional<exception_t>& inner_exception, const xtd::diagnostics::stack_frame& stack_framee) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0
    exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
    /// @brief Create a new instance of class exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::exception (const xtd::string& message, const std::optional<exception_t>& inner_exception, const xtd::diagnostics::stack_frame& stack_framee) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0
    exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
    /// @}
    
    /// @cond
    exception(exception&&) = default;
    exception(const exception&) = default;
    exception& operator =(exception&&) = default;
    exception& operator =(const exception&) = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets file path where exception occurred
    /// @return A string represent file path where exception occurred
    /// @deprecated Replaced by xtd::exception::get_last_stack_frame().get_file_name - Will be removed in version 0.4.0
    virtual const xtd::string& file_path() const noexcept;
    
    /// @brief Gets a link to the help file associated with this exception.
    /// @return A string represent a link to Help file associated with exception
    virtual const xtd::string& help_link() const noexcept;
    /// @brief Sets a link to the help file associated with this exception.
    /// @param value A string represent a link to Help file associated with exception
    virtual void help_link(const xtd::string& value) noexcept;
    
    /// @brief Gets HRESULT, a coded numerical value that is assigned to a specific exception.
    /// @return The HRESULT value.
    virtual int32 h_result() const noexcept;
    /// @brief Sets HRESULT, a coded numerical value that is assigned to a specific exception.
    /// @param value The HRESULT value.
    virtual void h_result(int32 value) noexcept;
    
    /// @brief Gets error associate to the exception
    /// @return An error_code represent a Error associate to the exception
    virtual const std::error_code& error_code() const noexcept;
    /// @brief Sets error associate to the exception
    /// @param value An error_code represent a Error associate to the exception
    virtual void error_code(const std::error_code& value) noexcept;

    /// @brief Gets the exception instance that caused the current exception.
    /// @return An instance of exception that describes the error that caused the current exception. The inner_exception property returns the same value as was passed into the constructor, or a null reference if the inner exception value was not supplied to the constructor.
    virtual exception_ref inner_exception() const noexcept;
    
    /// @brief Gets Line number where the exception occurred
    /// @return the line number where exception occurred
    /// @deprecated Replaced by xtd::exception::get_last_stack_frame().get_file_line_number - Will be removed in version 0.4.0
    virtual xtd::size line_number() const noexcept;
    
    /// @brief Gets file member where exception occurred
    /// @return A string represent member name where exception occurred
    /// @deprecated Replaced by xtd::exception::get_last_stack_frame().get_method - Will be removed in version 0.4.0
    virtual const xtd::string& member_name() const noexcept;
    
    /// @brief Gets message associate to the exception
    /// @return A string represent a massage associate to the exception
    virtual const xtd::string& message() const noexcept;
    
    /// @brief Gets full class name the exception
    /// @return A string represent a full class name of the exception
    /// @deprecated Replaced by xtd::exception::get_type().full_name() - Will be removed in version 0.4.0
    virtual const xtd::string& name() const noexcept;
    
    /// @brief Gets the name of the application or the object that causes the error.
    /// @return The name of the application or the object that causes the error.
    /// @remarks If the xtd::exception::source property is not set explicitly, the runtime automatically sets it to the name of the assembly in which the exception originated.
    virtual const xtd::string& source() const noexcept;
    /// @brief Sets the name of the application or the object that causes the error.
    /// @return The name of the application or the object that causes the error.
    /// @remarks If the xtd::exception::source property is not set explicitly, the runtime automatically sets it to the name of the assembly in which the exception originated.
    virtual void source(const xtd::string& value) noexcept;
    
    /// @brief Gets a string representation of the immediate frames on the call stack.
    /// @return A string that describes the immediate frames of the call stack.
    virtual xtd::string stack_trace() const noexcept;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Gets the last stack frame where the exception occurred
    /// @return The last stack frame where exception occurred
    virtual const xtd::diagnostics::stack_frame& get_last_stack_frame() const noexcept;
    /// @brief Returns a string that represents the current exception.
    /// @return A string that represents the current exception.
    xtd::string to_string() const noexcept override;

    /// @brief Gets message associate to the exception
    /// @return A string represent a massage associate to the exception
    const char* what() const noexcept override;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Gets if the generation of the stack trace is enabled.
    /// @return triue if stack trace enabled; otherwhise false.
    static bool enable_stack_trace() noexcept;
    /// @brief Sets if the generation of the stack trace is enabled.
    /// @paran enable triue if stack trace enabled; otherwhise false.
    static void enable_stack_trace(bool enable) noexcept;
    /// @}

  private:
    exception(const xtd::string& message, uptr<xtd::exception>&& inner_exception, const xtd::diagnostics::stack_frame& information);
    xtd::string stack_trace_to_string() const noexcept;
    const xtd::string& get_name() const noexcept;

    struct data;
    ptr<data> data_;    
    static bool enable_stack_trace_;
  };
}
