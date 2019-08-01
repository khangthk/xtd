#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("Check box example");

      this->radio_button1.parent(*this);
      this->radio_button1.auto_check(false);
      this->radio_button1.location({30, 30});
      this->radio_button1.text("unchecked");

      this->radio_button2.parent(*this);
      this->radio_button2.checked(true);
      this->radio_button2.location({30, 60});
      this->radio_button2.text("checked");

      this->radio_button3.parent(*this);
      this->radio_button3.check_state_changed += [&](const control& sender, const event_args& e) {
        this->label1.text(strings::format("check_box3 state = {}", this->radio_button3.check_state()));
      };
      this->radio_button3.check_state(forms::check_state::indeterminate);
      this->radio_button3.three_state(true);
      this->radio_button3.location({30, 90});
      this->radio_button3.text("indeterminate");
      
      this->label1.parent(*this);
      this->label1.auto_size(true);
      this->label1.location({30, 150});
    }
    
  private:
    check_box radio_button1;
    check_box radio_button2;
    check_box radio_button3;
    label label1;
  };
}

int main() {
  application::enable_visual_styles();
  application::run(examples::form1());
}
