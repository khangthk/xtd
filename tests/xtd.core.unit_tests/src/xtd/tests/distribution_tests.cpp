#include <xtd/distribution.h>
#include <xtd/tunit/assert.h>
#include <xtd/tunit/collection_assert.h>
#include <xtd/tunit/test_class_attribute.h>
#include <xtd/tunit/test_method_attribute.h>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(distribution_tests) {
  public:
    void test_method_(default_ctor) {
      auto d = distribution {};
      assert::are_equal(uri {}, d.bug_repport(), csf_);
      assert::is_empty(d.code_name(), csf_);
      assert::is_empty(d.description(), csf_);
      assert::are_equal(uri {}, d.home(), csf_);
      assert::is_empty(d.id(), csf_);
      collection_assert::is_empty(d.like_ids(), csf_);
      assert::is_empty(d.name(), csf_);
      assert::are_equal(version {}, d.version(), csf_);
      assert::is_empty(d.version_string(), csf_);
      assert::is_empty(d.to_string(), csf_);
    }
    
    void test_method_(ctor_with_params) {
      auto d = distribution {"macOS", version {12, 6, 5}, "Monterey", "Apple macOS 12.6.5 (Monterey)", "macos", {"macos", "osx"}, "12.6.5 (Monterey)", uri {"https://www.apple.com/macos"}, uri {"https://support.apple.com/macos"}};
      assert::are_equal(uri {"https://support.apple.com/macos"}, d.bug_repport(), csf_);
      assert::are_equal("Monterey", d.code_name(), csf_);
      assert::are_equal("Apple macOS 12.6.5 (Monterey)", d.description(), csf_);
      assert::are_equal(uri {"https://www.apple.com/macos"}, d.home(), csf_);
      assert::are_equal("macos", d.id(), csf_);
      collection_assert::are_equal({"macos", "osx"}, d.like_ids(), csf_);
      assert::are_equal("macOS", d.name(), csf_);
      assert::are_equal(version {12, 6, 5}, d.version(), csf_);
      assert::are_equal("12.6.5 (Monterey)", d.version_string(), csf_);
      assert::are_equal("Apple macOS 12.6.5 (Monterey)", d.to_string(), csf_);
    }
  };
}
