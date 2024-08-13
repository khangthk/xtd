#include <xtd/collections/generic/list>
#include <xtd/ustring>

using namespace xtd;
using namespace xtd::collections::generic;

class character : public iequatable<character>, public icomparable<character> {
public:
  character() = default;
  character(const ustring& name, const ustring& rank) noexcept : name_(name), rank_(rank) {}
  
  const ustring& name() const noexcept {return name_;}
  const ustring& rank() const noexcept {return rank_;}
  
  ustring to_string() const noexcept {return name_ + " (" + rank_ + ")";}
  
  int compare_to(const character& rhs) const noexcept override {
    if (name_ == rhs.name_ && rank_ == rhs.rank_) return 0;
    if (name_ > rhs.name_) return 1;
    if (name_ == rhs.name_ && rank_ > rhs.rank_) return 1;
    return -1;
  }

  bool equals(const character& rhs) const noexcept override {return compare_to(rhs) == 0;}

private:
  ustring name_;
  ustring rank_;
};

using characters = list<character>;

auto main() -> int {
  for (auto c : characters {{"Jean-Luc Picard", "Captain"}, {"William Riker", "Commander"}, {"Data", "Commander"}, {"Beverly Crusher", "Commander"}, {"Geordi La Forge", "Lieutenant Commander"}, {"Worf", "Lieutenant Commander"}, {"Tasha Yar", "Lieutenant"}})
  std::cout << ustring::sprintf("%s", c.to_string()) << std::endl;
}

// This code produces the following output :
//
// Jean-Luc Picard (Captain)
// William Riker (Commander)
// Data (Commander)
// Beverly Crusher (Commander)
// Geordi La Forge (Lieutenant Commander)
// Worf (Lieutenant Commander)
// Tasha Yar (Lieutenant)
