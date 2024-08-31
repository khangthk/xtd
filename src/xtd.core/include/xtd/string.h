/// @file
/// @brief Contains xtd::string alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__string_definitions.h"
#undef __XTD_CORE_INTERNAL__
#include "basic_string.h"

/// @cond
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents text as a sequence of UTF-8 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::string object is a sequential collection of char that represent a string; a char corresponds to a UTF-8 code unit. The value of the xtd::string object is the content of the sequential collection of char, and unlike [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::string_builder class.
  /// @remarks xtd::string implements xtd::basic_string and therefore offers the full (immutable) API of [std::string](https://en.cppreference.com/w/cpp/string/basic_string).
  using string = xtd::basic_string<char>;
    
  /// @brief Converts a signed integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_ustring(int val);
  /// @brief Converts an unsigned integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_ustring(unsigned val);
  /// @brief Converts a signed integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_ustring(long val);
  /// @brief Converts an unsigned integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_ustring(unsigned long val);
  /// @brief Converts a signed integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_ustring(long long val);
  /// @brief Converts an unsigned integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_ustring(unsigned long long val);
  /// @brief Converts a floating point to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_ustring(float val);
  /// @brief Converts a floating point integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_ustring(double val);
  /// @brief Converts a floating point to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_ustring(long double val);
  /// @brief Converts a type_t to xtd::string.
  /// @param val A type_t value to convert.
  /// @return A string holding the converted value.
  template <typename type_t>
  string to_ustring(type_t val) {
    return string::format("{}", val);
  }

  /// @todo Uncomment the folllowing line and remove the next..
  template<typename char_t, typename traits_t, typename allocator_t>
  inline xtd::string basic_string<char_t, traits_t, allocator_t>::to_string() const noexcept {return __xtd_convert_to_string<char>(chars_);}
}

/*
/// @cond
/// Needed for std::format
#if defined(__xtd__cpp_lib_format)
template <>
struct std::formatter<xtd::string> : std::formatter<std::string> {
  template <typename object_t, typename format_context_t>
  auto format(const object_t& obj, format_context_t& ctx) const {return std::format_to(ctx.out(), "{}", std::string {obj.to_string()});}
};
#endif
/// @endcond
*/

/// @todo Remove `string` class.
template<>
inline std::string xtd::to_string(const xtd::string& value, const std::string& fmt, const std::locale& loc) {return value.to_string();}

