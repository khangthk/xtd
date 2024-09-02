#include <xtd/text/basic_string_builder>
#include <xtd/argument_exception>
#include <xtd/argument_out_of_range_exception>
#include <xtd/char16>
#include <xtd/char32>
#include <xtd/char8>
#include <xtd/index_out_of_range_exception.h>
#include <xtd/size_object>
#include <xtd/wchar>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <sstream>

using namespace xtd;
using namespace xtd::text;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::tests {
  template <typename value_t>
  class basic_string_builder_tests;

  test_class_attribute<basic_string_builder_tests<char>> basic_string_builder_tests_class_char_attr {"basic_string_builder_tests<char>"};
  test_class_attribute<basic_string_builder_tests<char16>> basic_string_builder_tests_class_char16_attr {"basic_string_builder_tests<char16>"};
  test_class_attribute<basic_string_builder_tests<char32>> basic_string_builder_tests_class_char32_attr {"basic_string_builder_tests<char32>"};
#if defined(__xtd__cpp_lib_char8_t)
  test_class_attribute<basic_string_builder_tests<char8>> basic_string_builder_tests_class_char8_attr {"basic_string_builder_tests<char8>"};
#endif
  test_class_attribute<basic_string_builder_tests<wchar>> basic_string_builder_tests_class_wchar_attr {"basic_string_builder_tests<wchar>"};

  template <typename char_t>
  class basic_string_builder_tests : public test_class {
  public:
    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                        Aliases
    void test_method_(base_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>>(), typeof_<typename basic_string_builder<char_t>::base_type>(), csf_);
    }
    
    void test_method_(traits_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::traits_type>(), typeof_<typename basic_string_builder<char_t>::traits_type>(), csf_);
    }
    
    void test_method_(value_type) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      assert::are_equal(typeof_<char_t>(), typeof_<typename basic_string_builder<char_t>::value_type>(), csf_);
    }
    
    void test_method_(allocator_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::allocator_type>(), typeof_<typename basic_string_builder<char_t>::allocator_type>(), csf_);
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::size_type>(), typeof_<typename basic_string_builder<char_t>::size_type>(), csf_);
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::difference_type>(), typeof_<typename basic_string_builder<char_t>::difference_type>(), csf_);
    }
    
    void test_method_(reference) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      assert::are_equal(typeof_<char_t&>(), typeof_<typename basic_string_builder<char_t>::reference>(), csf_);
    }
    
    void test_method_(const_reference) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      assert::are_equal(typeof_<const char_t&>(), typeof_<typename basic_string_builder<char_t>::const_reference>(), csf_);
    }
    
    void test_method_(pointer) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      assert::are_equal(typeof_<char_t*>(), typeof_<typename basic_string_builder<char_t>::pointer>(), csf_);
    }
    
    void test_method_(const_pointer) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) return;
#endif
      assert::are_equal(typeof_<const char_t*>(), typeof_<typename basic_string_builder<char_t>::const_pointer>(), csf_);
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::iterator>(), typeof_<typename basic_string_builder<char_t>::iterator>(), csf_);
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::const_iterator>(), typeof_<typename basic_string_builder<char_t>::const_iterator>(), csf_);
    }
    
    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::reverse_iterator>(), typeof_<typename basic_string_builder<char_t>::reverse_iterator>(), csf_);
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>::const_reverse_iterator>(), typeof_<typename basic_string_builder<char_t>::const_reverse_iterator>(), csf_);
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                         Fields
    void test_method_(npos) {
      assert::are_equal(size_object::max_value, basic_string_builder<char_t>::npos, csf_);
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                   Constructors
    void test_method_(default_constructor) {
      auto s = basic_string_builder<char_t> {};
      assert::is_zero(s.length(), csf_);
    }

    void test_method_(constructor_with_basic_string_builder) {
      auto s = basic_string_builder<char_t>("A test string");
      assert::are_equal("A test string", basic_string_builder<char_t>(s).to_string(), csf_);
      assert::are_equal("A test string", s.to_string(), csf_);
      assert::is_empty(basic_string_builder<char_t>(basic_string_builder<char_t>("")), csf_);
    }
    
    void test_method_(constructor_with_basic_string_builder_and_index) {
      assert::are_equal("string", basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 7).to_string(), csf_);
      assert::are_equal("g", basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 12).to_string(), csf_);
      assert::is_empty(basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 13).to_string(), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 14);}, csf_);
    }
    
    void test_method_(constructor_with_basic_string_and_index_and_count) {
      assert::are_equal("str", basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 7, 3).to_string(), csf_);
      assert::are_equal("string", basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 7, 6).to_string(), csf_);
      assert::throws<index_out_of_range_exception>([]{basic_string_builder<char_t>(basic_string_builder<char_t>("A test string"), 7, 7).to_string();}, csf_);
    }
    
    void test_method_(move_constructor_with_basic_string) {
      auto s = basic_string_builder<char_t>("A test string");
      assert::are_equal("A test string", basic_string_builder<char_t>(std::move(s)).to_string(), csf_);
      assert::is_empty(s, csf_);
    }
    
    void test_method_(constructor_with_count_and_character) {
      auto s = basic_string_builder<char_t>(10, char_t {'*'});
      assert::are_equal(10_z, s.length(), csf_);
      for (auto index = 0_z; index < s.length(); ++index)
        assert::are_equal(char_t {'*'}, s[index], csf_);
    }
    
    void test_method_(constructor_with_count_and_pointer) {
      auto b = basic_string<char_t>("A test string\U0001F603");
      auto p = b.c_str();
      auto s = basic_string_builder<char_t>(p);
      assert::are_equal("A test string\U0001F603", s.to_string(), csf_);
    }
    
    void test_method_(constructor_with_count_and_pointer_and_count) {
      auto b = basic_string<char_t>("A test string");
      auto p = b.c_str();
      auto s = basic_string_builder<char_t>(p, 6);
      assert::are_equal("A test", s.to_string(), csf_);
    }
    
    void test_method_(constructor_with_first_and_last) {
      auto s = xtd::basic_string<char_t>("A test string");
      assert::are_equal("test string", basic_string_builder<char_t>(s.begin() + 2, s.end()).to_string(), csf_);
    }
    
    void test_method_(constructor_with_initializer_list) {
      assert::are_equal("A test string", basic_string_builder<char_t>(std::initializer_list<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}).to_string(), csf_);
    }
    
    void test_method_(constructor_with_capacity) {
      auto s = basic_string_builder<char_t>(512_z);
      assert::is_greater_or_equal(s.capacity(), 512_z, csf_);
      assert::are_equal(s.chars().max_size(), s.max_capacity(), csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t>(std::string().max_size() + 1);}, csf_);
    }
    
    void test_method_(constructor_with_capacity_and_max_capacity) {
      auto s = basic_string_builder<char_t>(512_z, 4096_z);
      assert::is_greater_or_equal(s.capacity(), 512_z, csf_);
      assert::are_equal(4096_z, s.max_capacity(), csf_);
      assert::does_not_throw([] {basic_string_builder<char_t>(1000_z, 1000_z);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t>(1001_z, 1000_z);}, csf_);
    }
    
    void test_method_(constructor_with_basic_string) {
      assert::are_equal("A test string", basic_string_builder<char_t>(basic_string<char_t>("A test string")).to_string(), csf_);
    }
    
    void test_method_(constructor_with_basic_string_and_capaicty) {
      auto s = basic_string_builder<char_t>(basic_string<char_t>("A test string"), 512_z);
      assert::are_equal("A test string", s.to_string(), csf_);
      assert::is_greater_or_equal(s.capacity(), 512_z, csf_);
    }
    
    void test_method_(constructor_with_basic_string_start_index_length_and_capaicty) {
      auto s = basic_string_builder<char_t>(basic_string<char_t>("A test string"), 2_z, 4_z, 512_z);
      assert::are_equal("test", s.to_string(), csf_);
      assert::is_greater_or_equal(s.capacity(), 512_z, csf_);
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                     Properties
    
    void test_method_(back_const) {
      assert::throws<index_out_of_range_exception>([] {basic_string_builder<char_t> {}.back();}, csf_);
      assert::are_equal(char_t {'g'}, basic_string_builder<char_t> {"A test string"}.back(), csf_);
    }
    
    void test_method_(back) {
      auto s = basic_string_builder<char_t> {"A test string"};
      assert::are_equal(char_t {'g'}, s.back(), csf_);
      s.back() = 'h';
      assert::are_equal(char_t {'h'}, s.back(), csf_);
    }
    
    void test_method_(begin) {
      auto s = basic_string_builder<char_t> {"A test string"};
      auto iterator = s.begin();
      assert::are_equal(char_t {'A'}, *iterator++, csf_);
      assert::are_equal(char_t {' '}, *iterator++, csf_);
      assert::are_equal(char_t {'e'}, *++iterator, csf_);
      assert::are_equal(char_t {'e'}, *iterator++, csf_);
      assert::are_equal(char_t {'s'}, *iterator, csf_);
      assert::are_equal(char_t {'i'}, *(iterator + 6), csf_);
    }
    
    void test_method_(c_str) {
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(!std::is_same<char_t, char8>::value)
        assert::are_equal(typeof_<const char_t*>(), typeof_(basic_string_builder<char_t> {}.c_str()), csf_);
#else
      assert::are_equal(typeof_<const char_t*>(), typeof_(basic_string_builder<char_t> {}.c_str()), csf_);
#endif
      assert::is_empty(basic_string_builder<char_t> {}.c_str(), csf_);
      assert::are_equal(std::basic_string<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string_builder<char_t> {"A test string"}.c_str(), csf_);
    }
    
    void test_method_(capacity_getter) {
      assert::is_not_zero(basic_string_builder<char_t> {}.capacity(), csf_);
    }
    
    void test_method_(capacity_setter) {
      auto s = basic_string_builder<char_t>();
      assert::is_less_or_equal(s.capacity(), 100_z, csf_);
      s.capacity(512);
      assert::is_greater_or_equal(s.capacity(), 512_z, csf_);
      assert::throws<argument_out_of_range_exception>([&] {s.capacity(std::string().max_size() + 1);}, csf_);
    }
    
    void test_method_(cbegin) {
      auto s = basic_string_builder<char_t> {"A test string"};
      auto iterator = s.cbegin();
      assert::are_equal(char_t {'A'}, *iterator++, csf_);
      assert::are_equal(char_t {' '}, *iterator++, csf_);
      assert::are_equal(char_t {'e'}, *++iterator, csf_);
      assert::are_equal(char_t {'e'}, *iterator++, csf_);
      assert::are_equal(char_t {'s'}, *iterator, csf_);
      assert::are_equal(char_t {'i'}, *(iterator + 6), csf_);
    }
    
    void test_method_(chars) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>>(), typeof_(basic_string_builder<char_t> {}.chars()), csf_);
      assert::is_empty(basic_string_builder<char_t> {}.chars(), csf_);
      collection_assert::are_equal({'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string_builder<char_t> {"A test string"}.chars(), csf_);
    }
    
    void test_method_(cend) {
      auto s = basic_string_builder<char_t> {"A test string"};
      auto iterator = s.cend();
      assert::does_not_throw([&]{ [[maybe_unused]] auto v = *iterator;}, csf_);
    }
    
    void test_method_(data_const) {
      const auto str = basic_string_builder<char_t> {};
      // Linker error on macOS : Undefined symbol: typeinfo for char8_t
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(!std::is_same<char_t, char8>::value)
        assert::are_equal(typeof_<const char_t*>(), typeof_(str.data()), csf_);
#else
      assert::are_equal(typeof_<const char_t*>(), typeof_(str.data()), csf_);
#endif
      assert::is_empty(str.data(), csf_);
      assert::are_equal(std::basic_string<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string_builder<char_t> {"A test string"}.data(), csf_);
    }
    
    void test_method_(data) {
      auto s = basic_string_builder<char_t> {"A test string"};
      auto data = s.data();
      assert::are_equal(char_t {'A'}, *data, csf_);
      *data = char_t {'C'};
      assert::are_equal(char_t {'C'}, *data, csf_);
      assert::are_equal(char_t {'t'}, *(data + 2), csf_);
      *(data + 2) = char_t {'r'};
      assert::are_equal(char_t {'r'}, *(data + 2), csf_);
      assert::are_equal("C rest string", s.to_string(), csf_);
    }

    void test_method_(empty) {
      assert::is_true(basic_string_builder<char_t> {}.empty(), csf_);
      assert::is_false(basic_string_builder<char_t> {"A test string"}.empty(), csf_);
    }
    
    void test_method_(end) {
      auto s = basic_string_builder<char_t> {"A test string"};
      auto iterator = s.end();
      assert::does_not_throw([&]{ [[maybe_unused]] auto v = *iterator;}, csf_);
    }
    
    void test_method_(front_const) {
      assert::throws<index_out_of_range_exception>([] {basic_string_builder<char_t> {}.front();}, csf_);
      assert::are_equal(char_t {'A'}, basic_string_builder<char_t> {"A test string"}.front(), csf_);
    }
    
    void test_method_(front) {
      auto s = basic_string_builder<char_t> {"A test string"};
      assert::are_equal(char_t {'A'}, s.front(), csf_);
      s.front() = 'B';
      assert::are_equal(char_t {'B'}, s.front(), csf_);
    }

    void test_method_(length) {
      assert::is_zero(basic_string_builder<char_t> {}.length(), csf_);
      assert::are_equal(13_z, basic_string_builder<char_t> {"A test string"}.length(), csf_);
    }
    
    void test_method_(max_capacity) {
      assert::are_equal(std::basic_string<char_t> {}.max_size(), basic_string_builder<char_t> {}.max_capacity(), csf_);
      assert::are_equal(1024_z, basic_string_builder<char_t> (255_z, 1024_z).max_capacity(), csf_);
    }
    
    void test_method_(max_size) {
      assert::are_equal(std::basic_string<char_t> {}.max_size(), basic_string_builder<char_t> {}.max_size(), csf_);
    }
    
    void test_method_(size) {
      assert::is_zero(basic_string_builder<char_t> {}.size(), csf_);
      assert::are_equal(13_z, basic_string_builder<char_t> {"A test string"}.size(), csf_);
    }

    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                        Methods

    void test_method_(append_basic_string_builder) {
      auto s = basic_string_builder<char_t> {"A test string"};
      s.append(basic_string_builder<char_t> {" to test"});
      assert::are_equal("A test string to test", s.to_string(), csf_);
      s.append(basic_string_builder<char_t> {""});
      assert::are_equal("A test string to test", s.to_string(), csf_);
      s.append(basic_string_builder<char_t> {" and other"});
      assert::are_equal("A test string to test and other", s.to_string(), csf_);
    }

    void test_method_(append_basic_string_builder_and_pos) {
      auto s = basic_string_builder<char_t> {"A test string"};
      s.append(basic_string_builder<char_t> {" to test"}, 3);
      assert::are_equal("A test string test", s.to_string(), csf_);
      s.append(basic_string_builder<char_t> {" and other"}, 4);
      assert::are_equal("A test string test other", s.to_string(), csf_);
      assert::throws<argument_out_of_range_exception>([&]{s.append(basic_string_builder<char_t> {" value"}, 7);}, csf_);
    }

    void test_method_(append_basic_string_builder_and_pos_and_count) {
      auto s = basic_string_builder<char_t> {"A test string"};
      s.append(basic_string_builder<char_t> {" to test"}, 3, 2);
      assert::are_equal("A test string t", s.to_string(), csf_);
      s.append(basic_string_builder<char_t> {" and other"}, 4, 3);
      assert::are_equal("A test string t ot", s.to_string(), csf_);
      assert::throws<argument_out_of_range_exception>([&]{s.append(basic_string_builder<char_t> {" value"}, 7, 0);}, csf_);
      assert::throws<argument_out_of_range_exception>([&]{s.append(basic_string_builder<char_t> {" value"}, 2, 5);}, csf_);
    }

    void test_method_(append_const_pointer_and_count) {
      auto s = basic_string_builder<char_t> {"A test string"};
      if constexpr(std::is_same<char_t, char>::value) s.append(" to test", 8);
      if constexpr(std::is_same<char_t, char16>::value) s.append(u" to test", 8);
      if constexpr(std::is_same<char_t, char32>::value) s.append(U" to test", 8);
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) s.append(u8" to test", 8);
#endif
      if constexpr(std::is_same<char_t, wchar>::value) s.append(L" to test", 8);
      assert::are_equal("A test string to test", s.to_string(), csf_);

      if constexpr(std::is_same<char_t, char>::value) s.append(" and check", 4);
      if constexpr(std::is_same<char_t, char16>::value) s.append(u" and check", 4);
      if constexpr(std::is_same<char_t, char32>::value) s.append(U" and check", 4);
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) s.append(u8" and check", 4);
#endif
      if constexpr(std::is_same<char_t, wchar>::value) s.append(L" and check", 4);
      assert::are_equal("A test string to test and", s.to_string(), csf_);
    }

    void test_method_(append_const_pointer) {
      auto s = basic_string_builder<char_t> {"A test string"};
      if constexpr(std::is_same<char_t, char>::value) s.append(" to test");
      if constexpr(std::is_same<char_t, char16>::value) s.append(u" to test");
      if constexpr(std::is_same<char_t, char32>::value) s.append(U" to test");
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) s.append(u8" to test");
#endif
      if constexpr(std::is_same<char_t, wchar>::value) s.append(L" to test");
      assert::are_equal("A test string to test", s.to_string(), csf_);
    }
    
    void test_method_(append_iterator) {
      auto s = basic_string_builder<char_t> {"A test string"};
      auto si = basic_string_builder<char_t> {" to test"};
      s.append(si.begin(), si.end());
      assert::are_equal("A test string to test", s.to_string(), csf_);
      auto si2 = basic_string_builder<char_t> {" and check"};
      s.append(si2.begin(), si2.begin() + 4);
      assert::are_equal("A test string to test and", s.to_string(), csf_);
    }
    
    void test_method_(append_initializer_list) {
      auto s = basic_string_builder<char_t> {"A test string"};
      s.append({' ', 't', 'o', ' ', 't', 'e', 's', 't'});
      assert::are_equal("A test string to test", s.to_string(), csf_);
    }
    
    void test_method_(at_const) {
      const auto s = basic_string_builder<char_t>("A test string");
      assert::are_equal(char_t {'A'}, s.at(0), csf_);
      assert::are_equal(char_t {' '}, s.at(1), csf_);
      assert::are_equal(char_t {'t'}, s.at(2), csf_);
      assert::are_equal(char_t {'e'}, s.at(3), csf_);
      assert::are_equal(char_t {'s'}, s.at(4), csf_);
      assert::are_equal(char_t {'t'}, s.at(5), csf_);
      assert::are_equal(char_t {' '}, s.at(6), csf_);
      assert::are_equal(char_t {'s'}, s.at(7), csf_);
      assert::are_equal(char_t {'t'}, s.at(8), csf_);
      assert::are_equal(char_t {'r'}, s.at(9), csf_);
      assert::are_equal(char_t {'i'}, s.at(10), csf_);
      assert::are_equal(char_t {'n'}, s.at(11), csf_);
      assert::are_equal(char_t {'g'}, s.at(12), csf_);
      assert::throws<index_out_of_range_exception>([&]{s.at(13);}, csf_);
      assert::throws<index_out_of_range_exception>([&]{basic_string_builder<char_t> {}.at(0);}, csf_);
    }
    
    void test_method_(at) {
      auto s = basic_string_builder<char_t>("A test string");
      assert::are_equal(char_t {'t'}, s.at(2), csf_);
      s.at(2) = char_t {'b'};
      assert::are_equal(char_t {'b'}, s.at(2), csf_);
      assert::throws<index_out_of_range_exception>([&]{s.at(13) = char_t {'z'};}, csf_);
      assert::are_equal("A best string", s.to_string(), csf_);
    }
    
    void test_method_(compare) {
      assert::is_zero(basic_string_builder<char_t> {"A test string"}.compare(basic_string<char_t> {"A test string"}), csf_);
      assert::is_zero(basic_string_builder<char_t> {"A test string"}.compare(1, 9, basic_string<char_t> {"B test strong"}, 1, 9), csf_);
      assert::is_negative(basic_string_builder<char_t> {"A test string"}.compare(basic_string<char_t> {"B test strong"}), csf_);
      assert::is_positive(basic_string_builder<char_t> {"B test strong"}.compare(basic_string<char_t> {"A test string"}), csf_);
    }
    
    void test_method_(copy_with_pointer_and_count) {
      auto a = array<char_t>(13);
      auto s = basic_string_builder<char_t>("A test string");
      s.copy(a.data(), 13);
      assert::are_equal(char_t {'A'}, a[0], csf_);
      assert::are_equal(char_t {' '}, a[1], csf_);
      assert::are_equal(char_t {'t'}, a[2], csf_);
      assert::are_equal(char_t {'e'}, a[3], csf_);
      assert::are_equal(char_t {'s'}, a[4], csf_);
      assert::are_equal(char_t {'t'}, a[5], csf_);
      assert::are_equal(char_t {' '}, a[6], csf_);
      assert::are_equal(char_t {'s'}, a[7], csf_);
      assert::are_equal(char_t {'t'}, a[8], csf_);
      assert::are_equal(char_t {'r'}, a[9], csf_);
      assert::are_equal(char_t {'i'}, a[10], csf_);
      assert::are_equal(char_t {'n'}, a[11], csf_);
      assert::are_equal(char_t {'g'}, a[12], csf_);
      assert::throws<argument_out_of_range_exception>([&] {s.copy(a.data(), 14);}, csf_);
    }
    
    void test_method_(copy_with_pointer_count_and_pos) {
      auto a = array<char_t>(4);
      auto s = basic_string_builder<char_t>("A test string");
      s.copy(a.data(), 4, 2);
      assert::are_equal(char_t {'t'}, a[0], csf_);
      assert::are_equal(char_t {'e'}, a[1], csf_);
      assert::are_equal(char_t {'s'}, a[2], csf_);
      assert::are_equal(char_t {'t'}, a[3], csf_);
      assert::throws<argument_out_of_range_exception>([&] {s.copy(a.data(), 0, 14);}, csf_);
      assert::throws<argument_out_of_range_exception>([&] {s.copy(a.data(), 4, 10);}, csf_);
    }

    void test_method_(equals_object) {
      auto s1 = basic_string_builder<char_t> {"A test string"};
      auto s2 = basic_string_builder<char_t> {"A test string"};
      auto& o1 = static_cast<object&>(s2);
      auto o2 = object {};
      assert::is_true(s1.equals(o1), csf_);
      assert::is_false(s1.equals(o2), csf_);
    }

    void test_method_(equals) {
      assert::is_true(basic_string_builder<char_t> {"A test string"}.equals(basic_string_builder<char_t> {"A test string"}), csf_);
      assert::is_false(basic_string_builder<char_t> {"A test string"}.equals(basic_string_builder<char_t> {"B test strong"}), csf_);
      assert::is_false(basic_string_builder<char_t> {"B test strong"}.equals(basic_string_builder<char_t> {"A test string"}), csf_);
    }
    
    void test_method_(erase) {
      assert::is_empty(basic_string_builder<char_t>("A test string").erase().to_string(), csf_);
    }
    
    void test_method_(erase_with_index) {
      assert::are_equal("A test", basic_string_builder<char_t>("A test string").erase(6).to_string(), csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t>("A test string").erase(14);}, csf_);
    }
    
    void test_method_(erase_with_index_and_count) {
      assert::are_equal("A string", basic_string_builder<char_t>("A test string").erase(2, 5).to_string(), csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t>("A test string").erase(14, 0);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t>("A test string").erase(2, 12);}, csf_);
    }
    
    void test_method_(erase_with_position_iterator) {
      auto s = basic_string_builder<char_t>("A test string");
      auto i = s.erase(s.begin() + 6);
      assert::are_equal("A teststring", s.to_string(), csf_);
      assert::are_equal(char_t {'s'}, *i, csf_);
    }
    
    void test_method_(erase_with_first_and_last_iterators) {
      auto s = basic_string_builder<char_t>("A test string");
      auto i = s.erase(s.begin() + 6, s.end());
      assert::are_equal("A test", s.to_string(), csf_);
      assert::are_equal(s.end(), i, csf_);
    }

    void test_method_(find) {
      assert::are_equal(2_z, basic_string_builder<char_t> {"A test string"}.find(basic_string<char_t> {"test"}), csf_);
      assert::are_equal(4_z, basic_string_builder<char_t> {"A test string"}.find(char_t {'s'}), csf_);
    }
    
    void test_method_(find_first_of) {
      assert::are_equal(2_z, basic_string_builder<char_t> {"A test string to test"}.find_first_of(basic_string<char_t> {"tuvw"}), csf_);
      assert::are_equal(4_z, basic_string_builder<char_t> {"A test string to test"}.find_first_of(char_t {'s'}), csf_);
    }
    
    void test_method_(find_first_not_of) {
      assert::are_equal(15_z, basic_string_builder<char_t> {"A test string to test"}.find_first_not_of(basic_string<char_t> {"Aeginrst "}), csf_);
      assert::are_equal(1_z, basic_string_builder<char_t> {"A test string to test"}.find_first_not_of(char_t {'A'}), csf_);
    }

    void test_method_(find_last_of) {
      assert::are_equal(15_z, basic_string_builder<char_t> {"A test string to test"}.find_last_of(basic_string<char_t> {"Baco"}), csf_);
      assert::are_equal(16_z, basic_string_builder<char_t> {"A test string to test"}.find_last_of(char_t {' '}), csf_);
    }

    void test_method_(find_last_not_of) {
      assert::are_equal(12_z, basic_string_builder<char_t> {"A test string to test"}.find_last_not_of(basic_string<char_t> {"eost "}), csf_);
      assert::are_equal(19_z, basic_string_builder<char_t> {"A test string to test"}.find_last_not_of(char_t {'t'}), csf_);
    }
    
    void test_method_(get_allocator) {
      assert::are_equal(typeof_<typename std::allocator<char_t>>(), typeof_(basic_string_builder<char_t> {"A test string"}.get_allocator()), csf_);
    }

    void test_method_(get_base_type) {
      assert::are_equal(typeof_<typename std::basic_string<char_t>>(), typeof_(basic_string_builder<char_t> {}.get_base_type()), csf_);
      assert::is_empty(basic_string_builder<char_t> {}.get_base_type(), csf_);
      collection_assert::are_equal({'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, basic_string_builder<char_t> {"A test string"}.get_base_type(), csf_);
    }
    
    void test_method_(get_hash_code) {
      assert::are_equal(basic_string_builder<char_t> {"01234"}.get_hash_code(), basic_string_builder<char_t> {"01234"}.get_hash_code(), csf_);
      assert::are_not_equal(basic_string_builder<char_t> {"01235"}.get_hash_code(), basic_string_builder<char_t> {"01234"}.get_hash_code(), csf_);
    }
    
    void test_method_(pop_back) {
      auto s = basic_string_builder<char_t> {"A test string"};
      s.pop_back();
      assert::are_equal("A test strin", s.to_string(), csf_);
    }
    
    void test_method_(push_back) {
      auto s = basic_string_builder<char_t> {"A test string"};
      s.push_back(char_t {' '});
      assert::are_equal("A test string ", s.to_string(), csf_);
    }
    
    void test_method_(replace_with_pos_count_and_str) {
      assert::are_equal("A value string", basic_string_builder<char_t> {"A test string"}.replace(2_z, 4_z, basic_string_builder<char_t> {"value"}).to_string(), csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t>("A test string").replace(14_z, 0_z, basic_string_builder<char_t> {"value"});}, csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t>("A test string").replace(2_z, 12_z, basic_string_builder<char_t> {"value"});}, csf_);
    }
    
    void test_method_(replace_with_first_last_and_str) {
      auto s =  basic_string_builder<char_t> {"A test string"};
      assert::are_equal("A value string", s.replace(s.begin() + 2_z, s.begin() + 6_z, basic_string_builder<char_t> {"value"}).to_string(), csf_);
    }
    
    void test_method_(replace_with_pos_count_str_and_pos2) {
      assert::are_equal("A value string", basic_string_builder<char_t> {"A test string"}.replace(2_z, 4_z, basic_string_builder<char_t> {"this value"}, 5_z).to_string(), csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t>("A test string").replace(14_z, 0_z, basic_string_builder<char_t> {"this value"}, 5_z);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t>("A test string").replace(2_z, 12_z, basic_string_builder<char_t> {"this value"}, 5_z);}, csf_);
    }
    
    void test_method_(replace_with_pos_count_str_pos2_and_count2) {
      assert::are_equal("A value string", basic_string_builder<char_t> {"A test string"}.replace(2_z, 5_z, basic_string_builder<char_t> {"this value string"}, 5_z, 6_z).to_string(), csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t>("A test string").replace(14_z, 0_z, basic_string_builder<char_t> {"this value string"}, 5_z, 6_z);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t>("A test string").replace(2_z, 12_z, basic_string_builder<char_t> {"this value string"}, 5_z, 6_z);}, csf_);
    }
    
    void test_method_(replace_with_pos_count_cstr_and_count2) {
      auto s = basic_string_builder<char_t> {"A test string"};
      if constexpr(std::is_same<char_t, char>::value) s.replace(2_z, 4_z, "value string", 5_z);
      if constexpr(std::is_same<char_t, char16>::value) s.replace(2_z, 4_z, u"value string", 5_z);
      if constexpr(std::is_same<char_t, char32>::value) s.replace(2_z, 4_z, U"value string", 5_z);
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) s.replace(2_z, 4_z, u8"value string", 5_z);
#endif
      if constexpr(std::is_same<char_t, wchar>::value) s.replace(2_z, 4_z, L"value string", 5_z);
      assert::are_equal("A value string", s.to_string(), csf_);
    }
    
    void test_method_(replace_with_first_last_cstr_and_count2) {
      auto s = basic_string_builder<char_t> {"A test string"};
      if constexpr(std::is_same<char_t, char>::value) s.replace(s.begin() + 2_z, s.begin() + 6_z, "value string", 5_z);
      if constexpr(std::is_same<char_t, char16>::value) s.replace(s.begin() + 2_z, s.begin() + 6_z, u"value string", 5_z);
      if constexpr(std::is_same<char_t, char32>::value) s.replace(s.begin() + 2_z, s.begin() + 6_z, U"value string", 5_z);
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) s.replace(s.begin() + 2_z, s.begin() + 6_z, u8"value string", 5_z);
#endif
      if constexpr(std::is_same<char_t, wchar>::value) s.replace(s.begin() + 2_z, s.begin() + 6_z, L"value string", 5_z);
      assert::are_equal("A value string", s.to_string(), csf_);
    }
    
    void test_method_(replace_with_pos_count_and_cstr) {
      auto s = basic_string_builder<char_t> {"A test string"};
      if constexpr(std::is_same<char_t, char>::value) s.replace(2_z, 4_z, "value");
      if constexpr(std::is_same<char_t, char16>::value) s.replace(2_z, 4_z, u"value");
      if constexpr(std::is_same<char_t, char32>::value) s.replace(2_z, 4_z, U"value");
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) s.replace(2_z, 4_z, u8"value");
#endif
      if constexpr(std::is_same<char_t, wchar>::value) s.replace(2_z, 4_z, L"value");
      assert::are_equal("A value string", s.to_string(), csf_);
    }
    
    void test_method_(replace_with_first_last_and_cstr) {
      auto s = basic_string_builder<char_t> {"A test string"};
      if constexpr(std::is_same<char_t, char>::value) s.replace(s.begin() + 2_z, s.begin() + 6_z, "value");
      if constexpr(std::is_same<char_t, char16>::value) s.replace(s.begin() + 2_z, s.begin() + 6_z, u"value");
      if constexpr(std::is_same<char_t, char32>::value) s.replace(s.begin() + 2_z, s.begin() + 6_z, U"value");
#if defined(__xtd__cpp_lib_char8_t)
      if constexpr(std::is_same<char_t, char8>::value) s.replace(s.begin() + 2_z, s.begin() + 6_z, u8"value");
#endif
      if constexpr(std::is_same<char_t, wchar>::value) s.replace(s.begin() + 2_z, s.begin() + 6_z, L"value");
      assert::are_equal("A value string", s.to_string(), csf_);
    }
    
    void test_method_(replace_with_pos_count_count2_and_ch) {
      assert::are_equal("A ***** string", basic_string_builder<char_t> {"A test string"}.replace(2_z, 4_z, 5_z, char_t {'*'}).to_string(), csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t>("A test string").replace(14_z, 0_z, 5_z, char_t {'*'});}, csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t>("A test string").replace(2_z, 12_z, 5_z, char_t {'*'});}, csf_);
    }

    void test_method_(replace_with_first_last_count2_and_ch) {
      auto s =  basic_string_builder<char_t> {"A test string"};
      assert::are_equal("A ***** string", s.replace(s.begin() + 2_z, s.begin() + 6_z, 5_z, char_t {'*'}).to_string(), csf_);
    }

    void test_method_(replace_with_first_last_and_ilist) {
      auto s =  basic_string_builder<char_t> {"A test string"};
      assert::are_equal("A value string", s.replace(s.begin() + 2_z, s.begin() + 6_z, {'v', 'a', 'l', 'u', 'e'}).to_string(), csf_);
    }
    
    void test_method_(reserve) {
      auto s = basic_string_builder<char_t>();
      assert::is_less_or_equal(s.capacity(), 100_z, csf_);
      s.reserve(512);
      assert::is_greater_or_equal(s.capacity(), 512_z, csf_);
      assert::throws<argument_out_of_range_exception>([&] {s.reserve(std::string().max_size() + 1);}, csf_);
    }

    void test_method_(resize_with_count) {
      auto s =  basic_string_builder<char_t> {"A test string"};
      assert::are_equal(13_z, s.length(), csf_);
      s.resize(16_z);
      assert::are_equal(16_z, s.length(), csf_);
      assert::are_equal(char_t {'\0'}, s[13], csf_);
      assert::are_equal(char_t {'\0'}, s[14], csf_);
      assert::are_equal(char_t {'\0'}, s[15], csf_);
      s.resize(3_z);
      assert::are_equal(3_z, s.length(), csf_);
      assert::are_equal(char_t {'A'}, s[0], csf_);
      assert::are_equal(char_t {' '}, s[1], csf_);
      assert::are_equal(char_t {'t'}, s[2], csf_);
    }

    void test_method_(resize_with_count_and_char) {
      auto s =  basic_string_builder<char_t> {"A test string"};
      assert::are_equal(13_z, s.length(), csf_);
      s.resize(16_z, char_t {'*'});
      assert::are_equal(16_z, s.length(), csf_);
      assert::are_equal(char_t {'*'}, s[13], csf_);
      assert::are_equal(char_t {'*'}, s[14], csf_);
      assert::are_equal(char_t {'*'}, s[15], csf_);
      s.resize(3_z);
      assert::are_equal(3_z, s.length(), csf_);
      assert::are_equal(char_t {'A'}, s[0], csf_);
      assert::are_equal(char_t {' '}, s[1], csf_);
      assert::are_equal(char_t {'t'}, s[2], csf_);
    }

    void test_method_(rfind) {
      assert::are_equal(17_z, basic_string_builder<char_t> {"A test string to test"}.rfind(basic_string<char_t> {"test"}), csf_);
      assert::are_equal(19_z, basic_string_builder<char_t> {"A test string to test"}.rfind(char_t {'s'}), csf_);
    }
    
    void test_method_(shrink_to_fit) {
      auto s = basic_string_builder<char_t> {basic_string<char_t> {"A test string"}, 1024_z};
      assert::are_equal(13_z, s.length(), csf_);
      assert::is_greater_or_equal(s.capacity(), 1024_z, csf_);
      s.shrink_to_fit();
      assert::are_equal(13_z, s.length(), csf_);
      assert::is_less(s.capacity(), 100_z, csf_);
    }
    
    void test_method_(substr) {
      assert::are_equal("A test string", basic_string_builder<char_t> {"A test string"}.substr().to_string(), csf_);
    }

    void test_method_(swap) {
      auto s1 = basic_string_builder<char_t> {"A test string"};
      auto s2 = basic_string_builder<char_t> {"Another test string"};
      s1.swap(s2);
      assert::are_equal("Another test string", s1.to_string(), csf_);
      assert::are_equal("A test string", s2.to_string(), csf_);
    }
    
    void test_method_(substr_with_start_index) {
      assert::are_equal("test string", basic_string_builder<char_t> {"A test string"}.substr(2).to_string(), csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string_builder<char_t> {"A test string"}.substr(14);}, csf_);
      assert::are_equal("test", basic_string_builder<char_t> {"A test string"}.substr(2, 4).to_string(), csf_);
    }
    
    void test_method_(substr_with_start_index_and_length) {
      assert::are_equal("test", basic_string_builder<char_t> {"A test string"}.substr(2, 4).to_string(), csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t> {"A test string"}.substr(2, 12);}, csf_);
      assert::throws<argument_out_of_range_exception>([] {basic_string<char_t> {"A test string"}.substr(14, 4);}, csf_);
    }

    void test_method_(to_string) {
      auto s = basic_string_builder<char_t> {"A test string"};
      assert::is_instance_of<string>(s.to_string(), csf_);
      assert::are_equal("A test string", s.to_string(), csf_);
    }
    
    // ______________________________________________________________________________________________________________________________________________
    //                                                                                                                                      Operators
    void test_method_(indexer_operator) {
      auto s = basic_string_builder<char_t>("A test string");
      assert::are_equal(char_t {'A'}, s[0], csf_);
      assert::are_equal(char_t {' '}, s[1], csf_);
      assert::are_equal(char_t {'t'}, s[2], csf_);
      assert::are_equal(char_t {'e'}, s[3], csf_);
      assert::are_equal(char_t {'s'}, s[4], csf_);
      assert::are_equal(char_t {'t'}, s[5], csf_);
      assert::are_equal(char_t {' '}, s[6], csf_);
      assert::are_equal(char_t {'s'}, s[7], csf_);
      assert::are_equal(char_t {'t'}, s[8], csf_);
      assert::are_equal(char_t {'r'}, s[9], csf_);
      assert::are_equal(char_t {'i'}, s[10], csf_);
      assert::are_equal(char_t {'n'}, s[11], csf_);
      assert::are_equal(char_t {'g'}, s[12], csf_);
      assert::throws<index_out_of_range_exception>([&]{s[13];}, csf_);
      assert::throws<index_out_of_range_exception>([&]{basic_string_builder<char_t> {}[0];}, csf_);
    }

    void test_method_(cast_operator_base_type) {
      auto s = std::basic_string<char_t> {};
      s = basic_string_builder<char_t>("A test string");
      collection_assert::are_equal({'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'}, s, csf_);
    }

    void test_method_(equal_operator_basic_string) {
      auto s1 = basic_string_builder<char_t> {};
      auto s2 = basic_string_builder<char_t>("A test string");
      s1 = s2;
      assert::are_equal("A test string", s1.to_string(), csf_);
      assert::are_equal("A test string", s2.to_string(), csf_);
    }
    
    void test_method_(equal_operator_move_basic_string) {
      auto s1 = basic_string_builder<char_t> {};
      auto s2 = basic_string_builder<char_t>("A test string");
      s1 = std::move(s2);
      assert::are_equal("A test string", s1.to_string(), csf_);
      assert::is_empty(s2, csf_);
    }
    
    void test_method_(equal_operator_pointer) {
      auto s1 = basic_string_builder<char_t> {};
      auto b = basic_string<char_t> {"A test string"};
      auto s2 = b.c_str();
      s1 = s2;
      assert::are_equal("A test string", s1.to_string(), csf_);
     }
    
    void test_method_(equal_operator_value_type) {
      auto s = basic_string_builder<char_t> {};
      auto c = char_t {'C'};
      s = c;
      assert::are_equal(char_t {'C'}, c, csf_);
      assert::are_equal("C", s.to_string(), csf_);
    }
    
    void test_method_(equal_operator_initializer_list_value_type) {
      auto s = basic_string_builder<char_t> {};
      auto il = std::initializer_list<char_t> {'A', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'};
      s = il;
      assert::are_equal("A test string", s.to_string(), csf_);
    }
    
    void test_method_(addition_assignment_operator_basic_string_value_type) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      s1 += s2;
      assert::are_equal("A test string", s1.to_string(), csf_);
      assert::are_equal(" string", s2.to_string(), csf_);
    }
    
    void test_method_(addition_assignment_operator_move_basic_string_value_type) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      s1 += std::move(s2);
      assert::are_equal("A test string", s1.to_string(), csf_);
      assert::is_empty(s2, csf_);
    }
    
    void test_method_(addition_assignment_operator_value_type_pointer) {
      auto s = basic_string_builder<char_t> {"A test"};
      auto b = basic_string<char_t> {" string"};
      s += b.c_str();
      assert::are_equal("A test string", s.to_string(), csf_);
    }
    
    void test_method_(addition_assignment_operator_value_type) {
      auto s = basic_string_builder<char_t> {"A test"};
      s += char_t {'$'};
      assert::are_equal("A test$", s.to_string(), csf_);
    }
    
    void test_method_(addition_operator_basic_string_value_type) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::are_equal("A test", s1.to_string(), csf_);
      assert::are_equal(" string", s2.to_string(), csf_);
    }
    
    void test_method_(addition_operator_move_basic_string_value_type) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      auto s3 = std::move(s1) + std::move(s2);
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::is_empty(s1, csf_);
      assert::is_empty(s2, csf_);
    }
    
    void test_method_(addition_operator_move_lhs_basic_string_value_type) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::is_empty(s1, csf_);
      assert::are_equal(" string", s2.to_string(), csf_);
    }
    
    void test_method_(addition_operator_move_rhs_basic_string_value_type) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::are_equal("A test", s1.to_string(), csf_);
      assert::is_empty(s2, csf_);
    }
    
    void test_method_(addition_operator_value_type_pointer_rhs) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto b = basic_string<char_t> {" string"};
      auto s2 = b.c_str();
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::are_equal("A test", s1.to_string(), csf_);
    }
    
    void test_method_(addition_operator_move_lhs_char_pointer_rhs) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto b = basic_string<char_t> {" string"};
      auto s2 = b.c_str();
      auto s3 = std::move(s1) + s2;
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::is_empty(s1, csf_);
    }
    
    void test_method_(addition_operator_value_type_pointer_lhs) {
      auto b = basic_string<char_t> {"A test"};
      auto s1 = b.c_str();
      auto s2 = basic_string_builder<char_t> {" string"};
      auto s3 = s1 + s2;
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::are_equal(" string", s2.to_string(), csf_);
    }
    
    void test_method_(addition_operator_value_type_pointer_lhs_move_rhs) {
      auto b = basic_string<char_t> {"A test"};
      auto s1 = b.c_str();
      auto s2 = basic_string_builder<char_t> {" string"};
      auto s3 = s1 + std::move(s2);
      assert::are_equal("A test string", s3.to_string(), csf_);
      assert::is_empty(s2, csf_);
    }
    
    void test_method_(addition_operator_value_type_rhs) {
      auto s = basic_string_builder<char_t> {"A test"};
      auto c = char_t {'$'};
      auto r = s + c;
      assert::are_equal("A test$", r.to_string(), csf_);
      assert::are_equal("A test", s.to_string(), csf_);
      assert::are_equal(char_t {'$'}, c, csf_);
    }
    
    void test_method_(addition_operator_move_lhs_value_type_rhs) {
      auto s = basic_string_builder<char_t> {"A test"};
      auto c = char_t {'$'};
      auto r = std::move(s) + c;
      assert::are_equal("A test$", r.to_string(), csf_);
      assert::is_empty(s, csf_);
      assert::are_equal(char_t {'$'}, c, csf_);
    }
    
    void test_method_(addition_operator_value_type_lhs) {
      auto s = basic_string_builder<char_t> {"A test"};
      auto c = char_t {'$'};
      auto r = c + s;
      assert::are_equal("$A test", r.to_string(), csf_);
      assert::are_equal(char_t {'$'}, c, csf_);
      assert::are_equal("A test", s.to_string(), csf_);
    }
    
    void test_method_(addition_operator_value_type_lhs_move_rhs) {
      auto s = basic_string_builder<char_t> {"A test"};
      auto c = char_t {'$'};
      auto r = c + std::move(s);
      assert::are_equal("$A test", r.to_string(), csf_);
      assert::are_equal(char_t {'$'}, c, csf_);
      assert::is_empty(s, csf_);
    }
    
    void test_method_(output_stream_operator_char) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      
      std::basic_stringstream<char> ss;
      ss << s1 << s2;
      assert::are_equal("A test string", ss.str(), csf_);
    }
    
    void test_method_(output_stream_operator_wchar) {
      auto s1 = basic_string_builder<char_t> {"A test"};
      auto s2 = basic_string_builder<char_t> {" string"};
      
      std::basic_stringstream<wchar> ss;
      ss << s1 << s2;
      assert::are_equal(L"A test string", ss.str(), csf_);
    }

    void test_method_(input_stream_operator_char) {
      auto is = basic_string_builder<char> {"TestString"};
      std::basic_istringstream<char> iss {is};
      
      auto s = basic_string_builder<char_t> {};
      iss >> s;
      assert::are_equal("TestString", s.to_string(), csf_);
    }

    void test_method_(input_stream_operator_wchar) {
      auto is = basic_string_builder<wchar> {L"TestString"};
      std::basic_istringstream<wchar> iss {is};
      
      auto s = basic_string_builder<char_t> {};
      iss >> s;
      assert::are_equal("TestString", s.to_string(), csf_);
    }
  };
}
