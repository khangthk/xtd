#include <xtd/tunit/collection_assert.h>
#include <xtd/tunit/test_class_attribute.h>
#include <xtd/tunit/test_method_attribute.h>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(collection_assert_are_equal_vector_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      std::vector<int> a = {1, 2, 3, 4};
      xtd::tunit::collection_assert::are_equal({1, 2, 3, 4}, a);
    }
  };
}

void test_(collection_assert_are_equal_vector_succeed_tests, test_output) {
  auto [output, result] = run_test_("collection_assert_are_equal_vector_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED collection_assert_are_equal_vector_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(collection_assert_are_equal_vector_succeed_tests, test_result) {
  auto [output, result] = run_test_("collection_assert_are_equal_vector_succeed_tests.*");
  assert_value_(0, result);
}
