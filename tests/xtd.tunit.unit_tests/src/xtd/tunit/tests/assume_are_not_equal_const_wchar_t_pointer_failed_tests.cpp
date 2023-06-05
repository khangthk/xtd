#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(assume_are_not_equal_const_wchar_t_pointer_failed__tests) {
  public:
    void test_method_(test_case_failed) {
      const wchar* s = L"value";
      xtd::tunit::assume::are_not_equal(L"value", s);
    }
  };
}

void test_(assume_are_not_equal_const_wchar_t_pointer_failed__tests, test_output) {
  auto [output, result] = run_test_("assume_are_not_equal_const_wchar_t_pointer_failed__tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  ABORTED assume_are_not_equal_const_wchar_t_pointer_failed__tests.test_case_failed\n"
    "    Test aborted\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assume_are_not_equal_const_wchar_t_pointer_failed__tests, test_result) {
  auto [output, result] = run_test_("assume_are_not_equal_const_wchar_t_pointer_failed__tests.*");
  assert_value_(0, result);
}