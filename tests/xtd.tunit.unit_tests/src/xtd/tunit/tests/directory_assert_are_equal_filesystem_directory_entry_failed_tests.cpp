#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>

#if defined(__cpp_lib_filesystem)
namespace xtd::tunit::tests {
  class test_class_(directory_assert_are_equal_filesystem_directory_entry_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::filesystem::directory_entry d1(std::filesystem::path(xtd::environment::get_folder_path(xtd::environment::special_folder::common_application_data).c_str()));
      std::filesystem::directory_entry d2(std::filesystem::path(xtd::environment::get_folder_path(xtd::environment::special_folder::common_application_data).c_str()) / "subdir");
      xtd::tunit::directory_assert::are_equal(d1, d2);
    }
  };
}

void test_(directory_assert_are_equal_filesystem_directory_entry_failed_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("directory_assert_are_equal_filesystem_directory_entry_failed_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_(xtd::ustring::format("Start 1 test from 1 test case\n"
      "  FAILED  directory_assert_are_equal_filesystem_directory_entry_failed_tests.test_case_failed\n"
      "    Expected: {0}\n"
      "    But was:  {1}\n"
      "End 1 test from 1 test case ran.\n", xtd::environment::get_folder_path(xtd::environment::special_folder::common_application_data).quoted(), xtd::io::path::combine(xtd::environment::get_folder_path(xtd::environment::special_folder::common_application_data), "subdir").quoted()), ss.str());
}

void test_(directory_assert_are_equal_filesystem_directory_entry_failed_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("directory_assert_are_equal_filesystem_directory_entry_failed_tests.*");
  std::stringstream ss;
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
#endif
