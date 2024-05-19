#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto a = vector {1, 2, 3, 4};
      collection_valid::is_not_empty(a);
    }
    
    void test_method_(test_case_failed) {
      auto a = vector<int> {};
      collection_valid::is_not_empty(a);
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED unit_tests::test.test_case_succeed (0 ms total)
//   FAILED  unit_tests::test.test_case_failed (0 ms total)
//     Expected: not <empty>
//     But was:  <empty>
//     Stack Trace: in |---OMITTED---|/collection_valid_is_not_empty.cpp:13
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
