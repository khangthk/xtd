#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <stdexcept>

namespace xtd::tunit::tests {
  class test_class_(asume_is_not_instance_of_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      std::invalid_argument e("invalid argument");
      xtd::tunit::assume::is_not_instance_of<std::bad_cast>(e);
    }
  };
}

void test_(asume_is_not_instance_of_succeed_tests, test_output) {
  auto [output, result] = run_test_("asume_is_not_instance_of_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED asume_is_not_instance_of_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(asume_is_not_instance_of_succeed_tests, test_result) {
  auto [output, result] = run_test_("asume_is_not_instance_of_succeed_tests.*");
  assert_value_(0, result);
}