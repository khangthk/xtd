/// @file
/// @brief Contains xtd::ptr type.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "sptr.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief The xtd::ptr object is a shared pointer.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @par Examples
  /// this is example shows to use xtd::new_ with xtd::version class
  /// @code
  /// ptr<xtd::version> version = new_ptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  //template<typename type_t, typename ptr_t=xtd::sptr<type_t>>
  //using ptr = ptr_t;
  template<typename type_t>
  using ptr = xtd::sptr<type_t>;
  /// @}
}
