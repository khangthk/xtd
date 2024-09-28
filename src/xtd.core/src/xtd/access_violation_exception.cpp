#include "../../include/xtd/access_violation_exception.h"
#include "../../include/xtd/literals.h"

using namespace xtd;
using namespace xtd::diagnostics;

access_violation_exception::access_violation_exception(const stack_frame& info) : system_exception(std::nullopt, info) {
  error_code(make_error_code(h_results::E_POINTER));
}

access_violation_exception::access_violation_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& info) : system_exception(message, info) {
  error_code(make_error_code(h_results::E_POINTER));
}

access_violation_exception::access_violation_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info) : system_exception(message, info) {
  error_code(error);
}

access_violation_exception::access_violation_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : system_exception(message, info) {
  error_code(make_error_code(h_results::E_POINTER));
  this->help_link(help_link);
}

access_violation_exception::access_violation_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : system_exception(message, info) {
  error_code(error);
  this->help_link(help_link);
}

access_violation_exception::access_violation_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info) : system_exception(info) {
  error_code(make_error_code(h_results::E_POINTER));
}

access_violation_exception::access_violation_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info) : system_exception(message, info) {
  error_code(make_error_code(h_results::E_POINTER));
}

access_violation_exception::access_violation_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info) : system_exception(message, info) {
  error_code(error);
}

access_violation_exception::access_violation_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : system_exception(message, info) {
  error_code(make_error_code(h_results::E_POINTER));
  this->help_link(help_link);
}

access_violation_exception::access_violation_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : system_exception(message, info) {
  error_code(error);
  this->help_link(help_link);
}
