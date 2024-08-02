#include <xtd/any_object>
#include <xtd/console>
#include <xtd/date_time>

using namespace xtd;

struct foo1 : public object {
  explicit foo1(int v) : value(v) {}
  int value = 0;
  
  ustring to_string() const noexcept override {return ustring::format("{}", value);}
  bool operator <(const foo1& f) const noexcept {return value < f.value;}
};

struct foo2 {
  int value = 0;
  
  bool operator ==(const foo2& f) const noexcept {return value == f.value;}
  bool operator <(const foo2& f) const noexcept {return value < f.value;}
};

auto main() -> int {
  auto a = any_object {};
  a = "one";
  console::write_line("a = {} => {} ({})", a, as<ustring>(a), typeof_(as<ustring>(a)));
  a = date_time {1971, 1, 5};
  console::write_line("a = {} => {} ({})", a, as<date_time>(a), typeof_(as<date_time>(a)));
  a = 42;
  console::write_line("a = {} => {} ({})", a, as<int32>(a), typeof_(as<int32>(a)));
  a = .42;
  console::write_line("a = {} => {} ({})", a, as<double>(a), typeof_(as<double>(a)));
  a = foo1 {42};
  console::write_line("a = {} => {} ({})", a, as<foo1>(a), typeof_(as<foo1>(a)));
  a = foo2 {42};
  console::write_line("a = {} => {} ({})", a, "NA", typeof_(as<foo2>(a)));
  a = day_of_week::wednesday;
  console::write_line("a = {} => {} ({})", a, as<day_of_week>(a), typeof_(as<day_of_week>(a)));
}

// This code produces the following output :
//
// a = one => one (xtd::ustring)
// a = Tue Jan  5 00:00:00 1971 => Tue Jan  5 00:00:00 1971 (xtd::date_time)
// a = 42 => 42 (int)
// a = 0.42 => 0.42 (double)
// a = 42 => 42 (foo1)
// a = foo2 => NA (foo2)
// a = wednesday => wednesday (xtd::day_of_week)