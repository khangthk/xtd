#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  auto form1 = control::create<form>("form1", {20, 20}, {800, 450});
  form1->start_position(form_start_position::center_screen);
  
  auto button1 = control::create<button>(*form1, "Dialog", {10, 10});
  button1->click += [&] {
    auto dialog = control::create<form>("dialog");
    dialog->client_size({200, 80});
    dialog->start_position(form_start_position::center_parent);
    
    auto text_box_input = control::create<text_box>(*dialog, "User input text", {10, 10}, {180, 23});
    
    auto button_ok = control::create<button>(*dialog, "OK", {10, 50});
    button_ok->dialog_result(forms::dialog_result::ok);
    button_ok->notify_default(true);

    auto button_cancel = control::create<button>(*dialog, "Cancel", {110, 50});
    button_cancel->dialog_result(forms::dialog_result::cancel);
    
    cdebug << format("dialog_result = {}, text = \"{}\"", dialog->show_dialog(), text_box_input->text()) << endl;
  };
  application::run(*form1);
}
