/// @file
/// @brief Contains xtd::decimal type.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief Represents a decimal-precision floating-point number.
  /// @par Header
  /// ```cpp
  /// #include <xtd/decimal>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using decimal = long double;
  /// @}
}
