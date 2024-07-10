#include "../../../include/xtd/reflection/assembly_identifier_attribute.h"

using namespace std;
using namespace xtd;
using namespace xtd::reflection;

assembly_identifier_attribute::assembly_identifier_attribute(const ustring& identifier) : identifier_(identifier) {
}

assembly_identifier_attribute::assembly_identifier_attribute(const ustring& identifier, const object& executing_assembly) : identifier_(identifier) {
  __assembly_identifier_attribute__() = make_shared<xtd::reflection::assembly_identifier_attribute>(identifier);
}

const ustring& assembly_identifier_attribute::identifier() const noexcept {
  return identifier_;
}

xtd::sptr<object> assembly_identifier_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_identifier_attribute>& __assembly_identifier_attribute__() {
  static auto identifier = xtd::sptr<xtd::reflection::assembly_identifier_attribute> {};
  return identifier;
}
