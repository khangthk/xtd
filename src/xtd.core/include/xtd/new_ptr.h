/// @file
/// @brief Contains xtd::new_ptr method.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "ptr.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::new_ptr operator creates a xtd::ptr object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::new_ptr with xtd::version class
  /// @code
  /// ptr<xtd::version> version = new_ptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  /// @remarks The xtd::new_ptr is equivalent to [xtd::new_sptr](https://en.cppreference.com/w/cpp/memory/shared_ptr/xtd::new_sptr).
  template<typename type_t, typename ...args_t>
  ptr<type_t> new_ptr(args_t&& ... args) {return ptr<type_t> {new type_t(args...)};}
  
  /// @cond
  template<typename type_t>
  ptr<type_t> new_ptr(const type_t& arg) {return ptr<type_t> {new type_t(arg)};}
  
  template<typename type_t>
  ptr<type_t> new_ptr() {return ptr<type_t>(new type_t);}
  /// @endcond
}