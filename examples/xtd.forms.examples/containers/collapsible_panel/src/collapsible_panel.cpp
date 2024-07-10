#define TRACE
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/collapsible_panel>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/toggle_button>
#include <list>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    auto_scroll(true);
    text("Collapsible panel example");
    
    collapsible_panel2.parent(*this);
    collapsible_panel2.dock(dock_style::top);
    collapsible_panel2.location({10, 100});
    collapsible_panel2.text("collapsible_panel2");
    collapsible_panel2.expanded_changed += [&] {
      button_expand.text(collapsible_panel2.expanded() ? "Collapse" : "Expand");
    };
    
    collapsible_panel1.parent(*this);
    collapsible_panel1.dock(dock_style::top);
    collapsible_panel1.location({10, 10});
    collapsible_panel1.text("collapsible_panel1");
    
    button_add.parent(collapsible_panel1);
    button_add.location({10, 0});
    button_add.text("Add");
    button_add.click += [&] {
      auto item = new_ptr<label>();
      item->parent(collapsible_panel2);
      item->text(ustring::format("item{}", ++count));
      item->dock(dock_style::top);
      control_items.push_back(item);
    };
    
    button_remove.parent(collapsible_panel1);
    button_remove.location({10, 30});
    button_remove.text("Remove");
    button_remove.click += [&] {
      if (control_items.size()) {
        control_items.front()->parent(nullptr);
        control_items.pop_front();
      }
    };
    
    button_expand.parent(collapsible_panel1);
    button_expand.location({10, 60});
    button_expand.checked(false);
    button_expand.text("Expand");
    button_expand.click += [&] {
      collapsible_panel2.expanded(!collapsible_panel2.expanded());
    };
  }
  
private:
  int count = 0;
  collapsible_panel collapsible_panel1;
  collapsible_panel collapsible_panel2;
  button button_add;
  button button_remove;
  toggle_button button_expand;
  list<ptr<control>> control_items;
};

auto main() -> int {
  application::run(form1 {});
}
