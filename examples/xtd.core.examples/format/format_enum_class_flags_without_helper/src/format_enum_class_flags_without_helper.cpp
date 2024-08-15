#include <xtd/as>
#include <xtd/console>
#include <xtd/enum_class>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

enum class text_styles {
  normal =    0b0,
  bold =      0b1,
  italic =    0b10,
  underline = 0b100,
  strikeout = 0b1000,
};

// Add text_style enum class flags bitwise operators
text_styles operator|(text_styles lhs, text_styles rhs) {return as<text_styles>(as<int>(lhs) | as<int>(rhs));}

// This operator is needed to register flags attribute.
template<> struct xtd::enum_set_attribute<text_styles> {
  explicit operator auto() const noexcept {return xtd::enum_attribute::flags;}
};

// This operator is needed for text_styles enum class to be recognized by xtd::string::format().
template<> struct xtd::enum_register<text_styles> {
  explicit operator auto() const noexcept {return xtd::enum_collection<text_styles> {{text_styles::normal, "normal"}, {text_styles::bold, "bold"}, {text_styles::italic, "italic"}, {text_styles::underline, "underline"}, {text_styles::strikeout, "strikeout"}};}
};

auto main() -> int {
  console::out << string::format("{}", text_styles::bold | text_styles::italic) << environment::new_line;
  console::out << string::format("0b{:b}", text_styles::bold | text_styles::italic) << environment::new_line;
  console::out << string::format("0b{:B}", text_styles::bold | text_styles::italic) << environment::new_line;
  console::out << string::format("{:d}", text_styles::bold | text_styles::italic) << environment::new_line;
  console::out << string::format("{:D}", text_styles::bold | text_styles::italic) << environment::new_line;
  console::out << string::format("{:g}", text_styles::bold | text_styles::italic) << environment::new_line;
  console::out << string::format("{:G}", text_styles::bold | text_styles::italic) << environment::new_line;
  console::out << string::format("0{:o}", text_styles::bold | text_styles::italic) << environment::new_line;
  console::out << string::format("0{:O}", text_styles::bold | text_styles::italic) << environment::new_line;
  console::out << string::format("0x{:x}", text_styles::bold | text_styles::italic) << environment::new_line;
  console::out << string::format("0x{:X}", text_styles::bold | text_styles::italic) << environment::new_line;
}

// This code produces the following output :
//
// saturday
// 0b101
// 0b101
// 5
// 5
// saturday
// saturday
// 05
// 05
// 0x5
// 0x5
