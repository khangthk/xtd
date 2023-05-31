#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

#if defined(__cpp_lib_filesystem)
namespace xtd::tunit::tests {
  class test_class_(directory_assert_are_not_equal_filesystem_directory_entry_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      std::filesystem::directory_entry d1(std::filesystem::path("."));
      std::filesystem::directory_entry d2(std::filesystem::path(".."));
      xtd::tunit::directory_assert::are_not_equal(d1, d2);
    }
  };
}

void test_(directory_assert_are_not_equal_filesystem_directory_entry_succeed_tests, test_output) {
  auto [result, output] = run_test_("directory_assert_are_not_equal_filesystem_directory_entry_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED directory_assert_are_not_equal_filesystem_directory_entry_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(directory_assert_are_not_equal_filesystem_directory_entry_succeed_tests, test_result) {
  auto [result, output] = run_test_("directory_assert_are_not_equal_filesystem_directory_entry_succeed_tests.*");
  assert_value_(0, result);
}
#endif
