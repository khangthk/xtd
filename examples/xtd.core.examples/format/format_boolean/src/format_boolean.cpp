#include <xtd/console>
#include <xtd/environment>
#include <xtd/ustring>

using namespace xtd;

enum class cap {title, middle, end};

void print_boolean(ustring text, bool value, cap c) {
  if (c == cap::title)
    console::out << "┌───────────┬────────────┬──────────────────────────────────┐" << environment::new_line
                 << "│  boolean  │   format   │      representation              │" << environment::new_line
                 << "├───────────┼────────────┼──────────────────────────────────┤" << environment::new_line;

  console::out <<  "│ " << text.pad_right(9) << " │ {}         │ " << ustring::format("{}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:b}       │ " << ustring::format("{:b}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:b4}      │ " << ustring::format("{:b4}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:b8}      │ " << ustring::format("{:b8}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:B}       │ " << ustring::format("{:B}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:B4}      │ " << ustring::format("{:B4}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:B8}      │ " << ustring::format("{:B8}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:d}       │ " << ustring::format("{:d}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:d2}      │ " << ustring::format("{:d2}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:D}       │ " << ustring::format("{:D}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:D2}      │ " << ustring::format("{:D2}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:g}       │ " << ustring::format("{:g}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:G}       │ " << ustring::format("{:G}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:o}       │ " << ustring::format("{:o}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:o3}      │ " << ustring::format("{:o3}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:O}       │ " << ustring::format("{:O}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:O3}      │ " << ustring::format("{:O3}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:x}       │ " << ustring::format("{:x}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:x5}      │ " << ustring::format("{:x5}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:X}       │ " << ustring::format("{:X}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:X5}      │ " << ustring::format("{:X5}", value).pad_right(32) << " |" << environment::new_line;

  if (c != cap::end)
    console::out << "├───────────┼────────────┼──────────────────────────────────┤" << environment::new_line;
  else
    console::out << "└───────────┴────────────┴──────────────────────────────────┘" << environment::new_line;
}

auto main() -> int {
  print_boolean("true", true, cap::title);
  print_boolean("false", false, cap::end);
}

// This code produces the following output :
//
// ┌───────────┬────────────┬──────────────────────────────────┐
// │  boolean  │   format   │      representation              │
// ├───────────┼────────────┼──────────────────────────────────┤
// │ true      │ {}         │ true                             |
// │ true      │ {:b}       │ 1                                |
// │ true      │ {:b4}      │ 0001                             |
// │ true      │ {:b8}      │ 00000001                         |
// │ true      │ {:B}       │ 1                                |
// │ true      │ {:B4}      │ 0001                             |
// │ true      │ {:B8}      │ 00000001                         |
// │ true      │ {:d}       │ 1                                |
// │ true      │ {:d2}      │ 01                               |
// │ true      │ {:D}       │ 1                                |
// │ true      │ {:D2}      │ 01                               |
// │ true      │ {:g}       │ true                             |
// │ true      │ {:G}       │ true                             |
// │ true      │ {:o}       │ 1                                |
// │ true      │ {:o3}      │ 001                              |
// │ true      │ {:O}       │ 1                                |
// │ true      │ {:O3}      │ 001                              |
// │ true      │ {:x}       │ 1                                |
// │ true      │ {:x5}      │ 00001                            |
// │ true      │ {:X}       │ 1                                |
// │ true      │ {:X5}      │ 00001                            |
// ├───────────┼────────────┼──────────────────────────────────┤
// │ false     │ {}         │ false                            |
// │ false     │ {:b}       │ 0                                |
// │ false     │ {:b4}      │ 0000                             |
// │ false     │ {:b8}      │ 00000000                         |
// │ false     │ {:B}       │ 0                                |
// │ false     │ {:B4}      │ 0000                             |
// │ false     │ {:B8}      │ 00000000                         |
// │ false     │ {:d}       │ 0                                |
// │ false     │ {:d2}      │ 00                               |
// │ false     │ {:D}       │ 0                                |
// │ false     │ {:D2}      │ 00                               |
// │ false     │ {:g}       │ false                            |
// │ false     │ {:G}       │ false                            |
// │ false     │ {:o}       │ 0                                |
// │ false     │ {:o3}      │ 000                              |
// │ false     │ {:O}       │ 0                                |
// │ false     │ {:O3}      │ 000                              |
// │ false     │ {:x}       │ 0                                |
// │ false     │ {:x5}      │ 00000                            |
// │ false     │ {:X}       │ 0                                |
// │ false     │ {:X5}      │ 00000                            |
// └───────────┴────────────┴──────────────────────────────────┘
