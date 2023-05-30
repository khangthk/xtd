#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(assert_are_equal_long_double_with_tolerence_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      long double ld = 0.599l;
      xtd::tunit::assert::are_equal(0.6l, ld, 0.01l);
    }
  };
}

// fail on linux
void test_(assert_are_equal_long_double_with_tolerence_succeed_tests, test_output) {
  auto [result, output] = run_test_("assert_are_equal_long_double_with_tolerence_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED assert_are_equal_long_double_with_tolerence_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assert_are_equal_long_double_with_tolerence_succeed_tests, test_result) {
  auto [result, output] = run_test_("assert_are_equal_long_double_with_tolerence_succeed_tests.*");
  assert_value_(0, result);
}
