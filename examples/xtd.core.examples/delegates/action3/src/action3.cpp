#include <xtd/action>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/forms/message_box>

using namespace xtd;
using namespace xtd::forms;

auto main() -> int {
  auto message_target = action<const string&> {};
  
  if (environment::get_command_line_args().size() > 1)
    message_target = [](const string & message) {message_box::show(message);};
  else
    message_target = [](const string & message) {console::write_line(message);};
    
  message_target("Hello, World!");
}
