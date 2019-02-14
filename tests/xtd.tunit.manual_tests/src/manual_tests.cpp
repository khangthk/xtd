#include <xtd/tunit>
#include <iostream>

using namespace xtd::tunit;
using namespace std;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test) {
  public:
    // This is the method that is called 1 time before test class run.
    static void class_initialize_(class_initialize) {
      cout << line_info_ << endl;
    }
    
    // This is the method that is called 1 time after test class run.
    static void class_cleanup_(class_cleanup) {
      cout << line_info_ << endl;
    }
    
    // This is the method that is called before any tests in a fixture are run.
    static void test_initialize_(test_initialize) {
      cout << line_info_ << endl;
    }
    
    // This is the method that is called after any tests in a fixture are run.
    static void test_cleanup_(test_cleanup) {
      cout << line_info_ << endl;
    }
    
    void test_method_(test_case1) {
      cout << line_info_ << endl;
    }
    
    void test_method_(test_case2) {
      cout << line_info_ << endl;
    }
    
    void ignore_test_method_(test_case3) {
      cout << line_info_ << endl;
    }
  };
}

int main(int argc, char* argv[]) {
  cout << line_info_ << endl;
  return unit_test(argv, argc).run();
}
