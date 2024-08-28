/// @file
/// @brief Contains xtd::basic_string class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_BASIC_STRING_INTERNAL__)
#error "Do not include this file: Internal use only. Include <basic_string> or <basic_string.h> instead."
#endif

#include "array.h"

/// @cond
template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::basic_string<char_t, traits_t, allocator_t>::basic_string(const allocator_type& allocator) noexcept : chars_(allocator) {}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split() const noexcept {
  return split(default_split_separators, std::numeric_limits<xtd::size>::max(), xtd::string_split_options::none);
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(value_type separator) const noexcept {
  return split(xtd::array<value_type> {separator}, std::numeric_limits<xtd::size>::max(), xtd::string_split_options::none);
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(value_type separator, xtd::string_split_options options) const noexcept {
  return split(xtd::array<value_type> {separator}, std::numeric_limits<xtd::size>::max(), options);
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(value_type separator, xtd::size count) const noexcept {
  return split(xtd::array<value_type> {separator}, count, xtd::string_split_options::none);
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(value_type separator, xtd::size count, xtd::string_split_options options) const noexcept {
  return split(xtd::array<value_type> {separator}, count, options);
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(const xtd::array<value_type>& separators) const noexcept {
  return split(separators, std::numeric_limits<xtd::size>::max(), xtd::string_split_options::none);
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(const xtd::array<value_type>& separators, xtd::string_split_options options) const noexcept {
  return split(separators, std::numeric_limits<xtd::size>::max(), options);
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(const xtd::array<value_type>& separators, xtd::size count) const noexcept {
  return split(separators, count, xtd::string_split_options::none);
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(const xtd::array<value_type>& separators, xtd::size count, xtd::string_split_options options) const noexcept {
  if (count == 0) return {};
  if (count == 1) return {*this};
  
  auto list = xtd::array<basic_string> {};
  auto sub_string = basic_string::empty_string;
  auto split_char_separators = separators.size() == 0 ? default_split_separators : separators;
  for (auto it = begin(); it != end(); ++it) {
    auto is_separator = std::find(split_char_separators.begin(), split_char_separators.end(), *it) != split_char_separators.end();
    if (!is_separator) sub_string.chars_.append(basic_string(1, *it));
    if ((static_cast<xtd::size>(it - begin()) == length() - 1 || is_separator) && (sub_string.length() > 0 || (sub_string.length() == 0 && options != xtd::string_split_options::remove_empty_entries))) {
      if (list.size() == count - 1) {
        list.push_back(sub_string + basic_string(c_str(), it - begin() + (is_separator ? 0 : 1), length() - (it - begin()) + (is_separator ? 0 : 1)));
        return list;
      }
      list.push_back(sub_string);
      sub_string.chars_.clear();
    }
  }
  
  return list;
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::to_array() const noexcept {
  return to_array(0, size());
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::to_array(xtd::size start_index) const {
  return to_array(start_index, size() - start_index);
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::to_array(xtd::size start_index, xtd::size length) const {
  if (start_index >= size()) return {};
  if (start_index + length >= size()) return {begin() + start_index, end()};
  return {begin() + start_index, begin() + start_index + length};
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::to_char_array() const noexcept {
  return to_array(0, size());
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::to_char_array(xtd::size start_index, xtd::size length) const {
  return to_array(start_index, length);
}

template<typename char_t, typename traits_t, typename allocator_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::to_title_case() const noexcept {
  auto words = split({' '});
  for (auto& word : words)
    if (word.size() && word != word.to_upper()) word = static_cast<value_type>(toupper(word[0])) + word.substring(1).to_lower();
  return basic_string::join(" ", words);
}

template<typename char_t, typename traits_t, typename allocator_t>
inline const xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::empty_string;

template<typename char_t, typename traits_t, typename allocator_t>
inline const xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::default_split_separators = {9, 10, 11, 12, 13, 32};

template<typename char_t, typename traits_t, typename allocator_t>
inline const xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::default_trim_chars = default_split_separators;


template<typename arg_t>
void __basic_string_extract_format_arg(std::basic_string<char>& fmt, xtd::size& index, xtd::array<__format_information<char>>& formats, arg_t&& arg) {
  auto offset = xtd::size {0};
  for (auto& format : formats) {
    format.location += offset;
    if (format.index == index) {
      xtd::basic_string<char> arg_str = xtd::to_string(arg, format.format);
      
      if (!format.alignment.empty()) {
        xtd::int32 alignment = 0;
        try {
          alignment = std::stoi(format.alignment);
        } catch (...) {
          __throw_basic_string_format_exception(__FILE__, __LINE__, __func__);
        }
        if (alignment > 0) arg_str = arg_str.pad_left(alignment);
        else if (alignment < 0) arg_str = arg_str.pad_right(-alignment);
      }
      fmt.insert(format.location, arg_str);
      offset += arg_str.size();
    }
  }
  ++index;
}

template<typename ...args_t>
void __basic_string_extract_format_arg(xtd::basic_string<char>& fmt, xtd::array<__format_information<char>>& formats, args_t&&... args) {
  auto index = xtd::size {0};
  (__basic_string_extract_format_arg(const_cast<std::basic_string<char>&>(fmt.chars()), index, formats, args), ...);
  unused_(index); // workaround to mute gcc warning: unused-but-set-variable
}

template<typename target_t, typename source_t>
inline std::basic_string<target_t> __xtd_convert_to_string(std::basic_string<source_t>&& str) noexcept {
  auto out = std::basic_string<target_t> {};
  auto codepoint = 0u;
  for (const auto& character : str) {
    if (character >= 0xd800 && character <= 0xdbff)
      codepoint = ((character - 0xd800) << 10) + 0x10000;
    else  {
      if (character >= 0xdc00 && character <= 0xdfff) codepoint |= character - 0xdc00;
      else codepoint = character;
      
      if (codepoint <= 0x7f)
        out.append(1, static_cast<target_t>(codepoint));
      else if (codepoint <= 0x7ff) {
        out.append(1, static_cast<target_t>(0xc0 | ((codepoint >> 6) & 0x1f)));
        out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
      } else if (codepoint <= 0xffff) {
        out.append(1, static_cast<target_t>(0xe0 | ((codepoint >> 12) & 0x0f)));
        out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 6) & 0x3f)));
        out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
      } else {
        out.append(1, static_cast<target_t>(0xf0 | ((codepoint >> 18) & 0x07)));
        out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 12) & 0x3f)));
        out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 6) & 0x3f)));
        out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
      }
      codepoint = 0;
    }
  }
  str.clear();
  return out;
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, char>(std::basic_string<char>&& str) noexcept {
  auto out = std::basic_string<xtd::char16> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::char16>(0xd800 + (static_cast<xtd::char16>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::char16>(0xdc00 + (static_cast<xtd::char16>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::char16>(codepoint));
    }
  }
  str.clear();
  return out;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  auto out = std::basic_string<xtd::char16> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::char16>(0xd800 + (static_cast<xtd::char16>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::char16>(0xdc00 + (static_cast<xtd::char16>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::char16>(codepoint));
    }
  }
  str.clear();
  return out;
}
#endif

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, char>(std::basic_string<char>&& str) noexcept {
  auto out = std::basic_string<xtd::wchar> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(xtd::wchar) > 2)
        out.append(1, static_cast<xtd::wchar>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::wchar>(0xd800 + (static_cast<xtd::wchar>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::wchar>(0xdc00 + (static_cast<xtd::wchar>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::wchar>(codepoint));
    }
  }
  str.clear();
  return out;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  auto out = std::basic_string<xtd::wchar> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(xtd::wchar) > 2)
        out.append(1, static_cast<xtd::wchar>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::wchar>(0xd800 + (static_cast<xtd::wchar>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::wchar>(0xdc00 + (static_cast<xtd::wchar>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::wchar>(codepoint));
    }
  }
  str.clear();
  return out;
}
#endif

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, char>(std::basic_string<char>&& str) noexcept {
  auto out = std::basic_string<xtd::char32> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
      out.append(1, static_cast<xtd::char32>(codepoint));
  }
  str.clear();
  return out;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  auto out = std::basic_string<xtd::char32> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
      out.append(1, static_cast<xtd::char32>(codepoint));
  }
  str.clear();
  return out;
}
#endif

template<>
inline std::basic_string<char> __xtd_convert_to_string<char, char>(std::basic_string<char>&& str) noexcept {
  return std::move(str);
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char16>(std::basic_string<xtd::char16>&& str) noexcept {
  return std::move(str);
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char32>(std::basic_string<xtd::char32>&& str) noexcept {
  return std::move(str);
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char8> __xtd_convert_to_string<xtd::char8, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  return std::move(str);
}
#endif

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::wchar>(std::basic_string<xtd::wchar>&& str) noexcept {
  return std::move(str);
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char8> __xtd_convert_to_string<xtd::char8, char>(std::basic_string<char>&& str) noexcept {
  auto result = std::basic_string<xtd::char8> {reinterpret_cast<const xtd::char8*>(str.c_str())};
  str.clear();
  return result;
}

template<>
inline std::basic_string<char> __xtd_convert_to_string<char, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  auto result = std::basic_string<char> {reinterpret_cast<const char*>(str.c_str())};
  str.clear();
  return result;
}
#endif

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char32>(std::basic_string<xtd::char32>&& str) noexcept {
  return __xtd_convert_to_string<xtd::char16>(__xtd_convert_to_string<char>(std::move(str)));
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::wchar>(std::basic_string<xtd::wchar>&& str) noexcept {
  return __xtd_convert_to_string<xtd::char16>(__xtd_convert_to_string<char>(std::move(str)));
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char16>(std::basic_string<xtd::char16>&& str) noexcept {
  return __xtd_convert_to_string<xtd::char32>(__xtd_convert_to_string<char>(std::move(str)));
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::wchar>(std::basic_string<xtd::wchar>&& str) noexcept {
  return __xtd_convert_to_string<xtd::char32>(__xtd_convert_to_string<char>(std::move(str)));
}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char16>(std::basic_string<xtd::char16>&& str) noexcept {
  return __xtd_convert_to_string<xtd::wchar>(__xtd_convert_to_string<char>(std::move(str)));}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char32>(std::basic_string<xtd::char32>&& str) noexcept {
  return __xtd_convert_to_string<xtd::wchar>(__xtd_convert_to_string<char>(std::move(str)));
}

template<typename target_t, typename source_t>
inline std::basic_string<target_t> __xtd_convert_to_string(const std::basic_string<source_t>& str) noexcept {
  auto out = std::basic_string<target_t> {};
  auto codepoint = 0u;
  for (const auto& character : str) {
    if (character >= 0xd800 && character <= 0xdbff)
      codepoint = ((character - 0xd800) << 10) + 0x10000;
    else  {
      if (character >= 0xdc00 && character <= 0xdfff) codepoint |= character - 0xdc00;
      else codepoint = character;
      
      if (codepoint <= 0x7f)
        out.append(1, static_cast<target_t>(codepoint));
      else if (codepoint <= 0x7ff) {
        out.append(1, static_cast<target_t>(0xc0 | ((codepoint >> 6) & 0x1f)));
        out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
      } else if (codepoint <= 0xffff) {
        out.append(1, static_cast<target_t>(0xe0 | ((codepoint >> 12) & 0x0f)));
        out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 6) & 0x3f)));
        out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
      } else {
        out.append(1, static_cast<target_t>(0xf0 | ((codepoint >> 18) & 0x07)));
        out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 12) & 0x3f)));
        out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 6) & 0x3f)));
        out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
      }
      codepoint = 0;
    }
  }
  return out;
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, char>(const std::basic_string<char>& str) noexcept {
  auto out = std::basic_string<xtd::char16> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::char16>(0xd800 + (static_cast<xtd::char16>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::char16>(0xdc00 + (static_cast<xtd::char16>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::char16>(codepoint));
    }
  }
  return out;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {
  auto out = std::basic_string<xtd::char16> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::char16>(0xd800 + (static_cast<xtd::char16>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::char16>(0xdc00 + (static_cast<xtd::char16>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::char16>(codepoint));
    }
  }
  return out;
}
#endif

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, char>(const std::basic_string<char>& str) noexcept {
  auto out = std::basic_string<xtd::wchar> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(xtd::wchar) > 2)
        out.append(1, static_cast<xtd::wchar>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::wchar>(0xd800 + (static_cast<xtd::wchar>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::wchar>(0xdc00 + (static_cast<xtd::wchar>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::wchar>(codepoint));
    }
  }
  return out;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {
  auto out = std::basic_string<xtd::wchar> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(xtd::wchar) > 2)
        out.append(1, static_cast<xtd::wchar>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::wchar>(0xd800 + (static_cast<xtd::wchar>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::wchar>(0xdc00 + (static_cast<xtd::wchar>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::wchar>(codepoint));
    }
  }
  return out;
}
#endif

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, char>(const std::basic_string<char>& str) noexcept {
  auto out = std::basic_string<xtd::char32> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
      out.append(1, static_cast<xtd::char32>(codepoint));
  }
  return out;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {
  auto out = std::basic_string<xtd::char32> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
      out.append(1, static_cast<xtd::char32>(codepoint));
  }
  return out;
}
#endif

template<>
inline std::basic_string<char> __xtd_convert_to_string<char, char>(const std::basic_string<char>& str) noexcept {
  return str;
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char16>(const std::basic_string<xtd::char16>& str) noexcept {
  return str;
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char32>(const std::basic_string<xtd::char32>& str) noexcept {
  return str;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char8> __xtd_convert_to_string<xtd::char8, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {
  return str;
}
#endif

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::wchar>(const std::basic_string<xtd::wchar>& str) noexcept {
  return str;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char8> __xtd_convert_to_string<xtd::char8, char>(const std::basic_string<char>& str) noexcept {
  return reinterpret_cast<const xtd::char8*>(str.c_str());
}

template<>
inline std::basic_string<char> __xtd_convert_to_string<char, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {
  return reinterpret_cast<const char*>(str.c_str());
}
#endif

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char32>(const std::basic_string<xtd::char32>& str) noexcept {
  return __xtd_convert_to_string<xtd::char16>(__xtd_convert_to_string<char>(str));
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::wchar>(const std::basic_string<xtd::wchar>& str) noexcept {
  return __xtd_convert_to_string<xtd::char16>(__xtd_convert_to_string<char>(str));
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char16>(const std::basic_string<xtd::char16>& str) noexcept {
  return __xtd_convert_to_string<xtd::char32>(__xtd_convert_to_string<char>(str));
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::wchar>(const std::basic_string<xtd::wchar>& str) noexcept {
  return __xtd_convert_to_string<xtd::char32>(__xtd_convert_to_string<char>(str));
}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char16>(const std::basic_string<xtd::char16>& str) noexcept {
  return __xtd_convert_to_string<xtd::wchar>(__xtd_convert_to_string<char>(str));
}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char32>(const std::basic_string<xtd::char32>& str) noexcept {
  return __xtd_convert_to_string<xtd::wchar>(__xtd_convert_to_string<char>(str));
}
/// @endcond
