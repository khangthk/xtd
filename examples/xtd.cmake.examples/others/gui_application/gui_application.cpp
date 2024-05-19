#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/label>

using namespace xtd::forms;

auto main() -> int {
  auto main_form = form::create("Gui application");
  auto information_label = label::create(main_form, "\nThis GUI application was generated by \nxtd cmake helpers.\n\nSee CMakeLists.txt file.", {10, 10});
  information_label.text_align(content_alignment::top_center).dock(dock_style::fill);
  application::run(main_form);
}
