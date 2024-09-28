/// @file
/// @brief Contains xtd::nullopt valiue.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "null_opt.h"
#include "core_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a nullopt value. Used to indicate that an [std::optional](https://en.cppreference.com/w/cpp/utility/optional) does not contain a value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/nullopt>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// ```cpp
  /// std::optional<foo_class> foo = foo_class {};
  /// ...
  /// foo = nullopt; // reset the optional foo variable.
  /// ```
  /// @ingroup xtd_core types
  extern core_export_ null_opt nullopt;
}
