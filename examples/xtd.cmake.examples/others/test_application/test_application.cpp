#include <xtd/xtd.tunit>

using namespace xtd::tunit;

class test_class_(test_application) {
public:
  void test_method_(test) {
    assert::succeed("This test application was generated by xtd cmake helpers. See CMakeLists.txt file.");
  }
};

auto main() -> int {
  return console_unit_test().run();
}
