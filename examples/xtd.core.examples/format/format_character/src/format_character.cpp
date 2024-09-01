#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>
#include <xtd/u32string>

using namespace xtd;

enum class cap {title, middle, end};

void print_character(u32string text, char32 value, cap c) {
  if (c == cap::title)
    console::out << "┌───────────┬────────────┬──────────────────────────────────┐" << environment::new_line
                 << "│  char     │   format   │      representation              │" << environment::new_line
                 << "├───────────┼────────────┼──────────────────────────────────┤" << environment::new_line;
  
  console::out <<  "│ " << text.pad_right(9) << " │ {}         │ " << u32string::format("{}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:g}       │ " << u32string::format("{:g}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:G}       │ " << u32string::format("{:G}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:d}       │ " << u32string::format("{:d}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:D}       │ " << u32string::format("{:D}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:x}       │ " << u32string::format("{:x}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:X}       │ " << u32string::format("{:X}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:ANY_FMT} │ " << u32string::format("{:ANY_FMT}", value).pad_right(32) << " |" << environment::new_line;

  if (c != cap::end)
    console::out << "├───────────┼────────────┼──────────────────────────────────┤" << environment::new_line;
  else
    console::out << "└───────────┴────────────┴──────────────────────────────────┘" << environment::new_line;
}

auto main() -> int {
  console::output_code_page(65001);
  
  print_character(string {"a"}, 'a', cap::title);
  print_character(string {u8"1"}, u8'1', cap::middle);
  print_character(string {L"\x1F603"}, L'\x1F603', cap::middle);
  print_character(string {u"\u4eb0"}, u'\u4eb0', cap::middle);
  print_character(string {U"\U0001F428"}, U'\U0001F428', cap::end);
}
  
// This code produces the following output :
//
// ┌───────────┬────────────┬──────────────────────────────────┐
// │  char     │   format   │      representation              │
// ├───────────┼────────────┼──────────────────────────────────┤
// │ a         │ {}         │ a                                |
// │ a         │ {:g}       │ a                                |
// │ a         │ {:G}       │ a                                |
// │ a         │ {:d}       │ a                                |
// │ a         │ {:D}       │ a                                |
// │ a         │ {:x}       │ a                                |
// │ a         │ {:X}       │ a                                |
// │ a         │ {:ANY_FMT} │ a                                |
// ├───────────┼────────────┼──────────────────────────────────┤
// │ 1         │ {}         │ 1                                |
// │ 1         │ {:g}       │ 1                                |
// │ 1         │ {:G}       │ 1                                |
// │ 1         │ {:d}       │ 1                                |
// │ 1         │ {:D}       │ 1                                |
// │ 1         │ {:x}       │ 1                                |
// │ 1         │ {:X}       │ 1                                |
// │ 1         │ {:ANY_FMT} │ 1                                |
// ├───────────┼────────────┼──────────────────────────────────┤
// │ 😃         │ {}         │ 😃                                |
// │ 😃         │ {:g}       │ 😃                                |
// │ 😃         │ {:G}       │ 😃                                |
// │ 😃         │ {:d}       │ 😃                                |
// │ 😃         │ {:D}       │ 😃                                |
// │ 😃         │ {:x}       │ 😃                                |
// │ 😃         │ {:X}       │ 😃                                |
// │ 😃         │ {:ANY_FMT} │ 😃                                |
// ├───────────┼────────────┼──────────────────────────────────┤
// │ 亰         │ {}         │ 亰                                |
// │ 亰         │ {:g}       │ 亰                                |
// │ 亰         │ {:G}       │ 亰                                |
// │ 亰         │ {:d}       │ 亰                                |
// │ 亰         │ {:D}       │ 亰                                |
// │ 亰         │ {:x}       │ 亰                                |
// │ 亰         │ {:X}       │ 亰                                |
// │ 亰         │ {:ANY_FMT} │ 亰                                |
// ├───────────┼────────────┼──────────────────────────────────┤
// │ 🐨         │ {}         │ 🐨                                |
// │ 🐨         │ {:g}       │ 🐨                                |
// │ 🐨         │ {:G}       │ 🐨                                |
// │ 🐨         │ {:d}       │ 🐨                                |
// │ 🐨         │ {:D}       │ 🐨                                |
// │ 🐨         │ {:x}       │ 🐨                                |
// │ 🐨         │ {:X}       │ 🐨                                |
// │ 🐨         │ {:ANY_FMT} │ 🐨                                |
// └───────────┴────────────┴──────────────────────────────────┘
