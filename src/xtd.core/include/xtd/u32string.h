/// @file
/// @brief Contains xtd::u32string alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "basic_string.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents text as a sequence of UTF-32 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::u32string object is a sequential collection of xtd::char32 that represent a string; a xtd::char32 corresponds to a UTF-32 code unit. The value of the xtd::u32string object is the content of the sequential collection of xtd::char32, and unlike [std::basic_string<char16_t>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::u32string_builder class.
  /// @remarks xtd::string implements [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) and therefore offers the full (immutable) API of std::string.
  using u32string = xtd::basic_string<xtd::char32>;
}
