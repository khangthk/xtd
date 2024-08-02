/// @file
/// @brief Contains xtd::comparison_operators class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.h"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Internal comparable operators definition.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t, typename comparable_t>
  /// class comparison_operators
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/comparison_operators
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @warning Internal use only for xtd::icomparable interfece.
  template<typename type_t, typename comparable_t>
  class comparison_operators {
  public:
    /// @name Public Operators
    
    /// @{
    /// @brief Less than comparison operator with specidied lhs ans rhs values.
    /// @param lhs The left hand side value to compare.
    /// @param rhs The right hand side value to compare.
    /// @return true if lhs less than rhs; otherwise false.
    friend bool operator <(const type_t& lhs, const type_t& rhs) noexcept {return dynamic_cast<const type_t*>(&rhs) && lhs.compare_to(static_cast<const type_t&>(rhs)) < 0;}

    /// @brief Less than or equal to comparison operator with specidied lhs ans rhs values.
    /// @param lhs The left hand side value to compare.
    /// @param rhs The right hand side value to compare.
    /// @return true if lhs less than or equal to rhs; otherwise false.
    friend bool operator <=(const type_t& lhs, const type_t& rhs) noexcept {return dynamic_cast<const type_t*>(&rhs) && lhs.compare_to(static_cast<const type_t&>(rhs)) <= 0;}

    /// @brief Greater than or equal to comparison operator with specidied lhs ans rhs values.
    /// @param lhs The left hand side value to compare.
    /// @param rhs The right hand side value to compare.
    /// @return true if lhs greater than rhs; otherwise false.
    friend bool operator >(const type_t& lhs, const type_t& rhs) noexcept {return dynamic_cast<const type_t*>(&rhs) && lhs.compare_to(static_cast<const type_t&>(rhs)) > 0;}

    /// @brief Less than comparison operator with specidied lhs ans rhs values.
    /// @param lhs The left hand side value to compare.
    /// @param rhs The right hand side value to compare.
    /// @return true if lhs greater than or equal to rhs; otherwise false.
    friend bool operator >=(const type_t& lhs, const type_t& rhs) noexcept {return dynamic_cast<const type_t*>(&rhs) && lhs.compare_to(static_cast<const type_t&>(rhs)) >= 0;}

#if defined(__xtd__cpp_lib_three_way_comparison)
    /// @brief Three-way comparison operator with specidied lhs ans rhs values.
    /// @param lhs The left hand side value to compare.
    /// @param rhs The right hand side value to compare.
    /// @return A strong ordering result:
    /// * std::strong_ordering::less : if lhs less than rhs;
    /// * std::strong_ordering::greater : if lhs greater than rhs;
    /// * std::strong_ordering::equivalent : if lhs is equal to rhs.
    friend std::strong_ordering operator <=>(const type_t& lhs, const type_t& rhs) noexcept {
      if (dynamic_cast<const type_t*>(&rhs) && lhs.compare_to(static_cast<const type_t&>(rhs)) < 0) return std::strong_ordering::less;
      if (dynamic_cast<const type_t*>(&rhs) && lhs.compare_to(static_cast<const type_t&>(rhs)) > 0) return std::strong_ordering::greater;
      if (dynamic_cast<const type_t*>(&rhs) && lhs.compare_to(static_cast<const type_t&>(rhs)) == 0) return std::strong_ordering::equivalent;
      return std::strong_ordering::less;
    }
#endif
    /// @}
  private:
    friend comparable_t;
    comparison_operators() = default;
  };
}