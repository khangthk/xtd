#include "../../../../include/xtd/forms/style_sheets/button_renderer.h"
#include "../../../../include/xtd/forms/style_sheets/button_data.h"
#include "../../../../include/xtd/forms/style_sheets/pseudo_state.h"
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/diagnostics/debug.h>
#include <xtd/console.h>
#include <xtd/invalid_operation_exception.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;
using namespace style_sheets;
using namespace visual_styles;

class control_styles {
public:
  using button_datas_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::button_data>;

  static const button_datas_t& button_datas() {
    static button_datas_t datas = {
      // :standard
      {xtd::forms::style_sheets::pseudo_state::standard, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {system_colors::button_face(), system_colors::button_face()}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(78, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::hover, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(system_colors::button_face()), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color::from_argb(35, 255, 255, 255), std::nullopt, std::nullopt}, {color_data(system_colors::gray_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      // :standard:default
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(0xFF177AE5), color::from_argb(0xFF166ECD)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::hover, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(0xFF177AE5), color::from_argb(0xFF166ECD)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(35, 255, 255, 255), color::from_argb(35, 255, 255, 255)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::gray_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      // :flat
      {xtd::forms::style_sheets::pseudo_state::flat, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(system_colors::control()), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(78, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::hover, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(30, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::gray_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      // :flat:default
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(system_colors::control()), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(78, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::hover, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(30, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::gray_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      // :popup
      {xtd::forms::style_sheets::pseudo_state::popup, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(system_colors::control()), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::inset, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::inset, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::inset, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(78, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::hover, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(30, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::gray_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      // :popup:default
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(system_colors::control()), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::inset, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::inset, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::inset, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(78, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::hover, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(93, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_data {{padding(0), {color_data(system_colors::control_text()), border_style::solid, 1, 5}, padding(1, 1, 1, 3), color_data(color::from_argb(30, 255, 255, 255)), std::nullopt, std::nullopt}, {color_data(system_colors::gray_text()), content_alignment::middle_center, system_fonts::default_font()}}},
    };
    return datas;
  }
};

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds) {
  draw_button(graphics, bounds, flat_style::standard, push_button_state::normal, false, nullopt, "", nullopt, nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style) {
  draw_button(graphics, bounds, button_style, push_button_state::normal, false, nullopt, "", nullopt, nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, push_button_state button_state, bool default_button) {
  draw_button(graphics, bounds, button_style, button_state, default_button, nullopt, "", nullopt, nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, push_button_state button_state, bool default_button, const optional<color>& back_color) {
  draw_button(graphics, bounds, button_style, button_state, default_button, nullopt, "", nullopt, nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, push_button_state button_state, bool default_button, const optional<color>& back_color, const ustring& text, const optional<text_format_flags>& text_flags, const optional<color>& fore_color, const optional<font>& font) {
  diagnostics::debug::write_line(ustring::format("{} - state = {}", text, button_state));
  diagnostics::debug::write_line(ustring::format("{} - style = {}", text, button_style));
  diagnostics::debug::write_line(ustring::format("{} - back_color = {}", text, back_color));
  diagnostics::debug::write_line(ustring::format("{} - fore_color = {}", text, fore_color));
  diagnostics::debug::write_line(ustring::format("{} - font = {}", text, font));
  auto pseudo_state_base = pseudo_state::standard;
  if (button_style == flat_style::flat) pseudo_state_base = pseudo_state::flat;
  if (button_style == flat_style::popup) pseudo_state_base = pseudo_state::popup;
  if (default_button) pseudo_state_base += pseudo_state::default_state;

  auto button_data_iterator = control_styles::button_datas().end();
  switch (button_state) {
    case push_button_state::normal: button_data_iterator = control_styles::button_datas().find(pseudo_state_base); break;
    case push_button_state::hot: button_data_iterator = control_styles::button_datas().find(pseudo_state_base | pseudo_state::hover); break;
    case push_button_state::pressed: button_data_iterator = control_styles::button_datas().find(pseudo_state_base | pseudo_state::pressed); break;
    case push_button_state::checked: button_data_iterator = control_styles::button_datas().find(pseudo_state_base | pseudo_state::checked); break;
    case push_button_state::disabled: button_data_iterator = control_styles::button_datas().find(pseudo_state_base | pseudo_state::disabled); break;
    case push_button_state::default_state: button_data_iterator = control_styles::button_datas().find(pseudo_state_base | pseudo_state::default_state); break;
  }
  if (button_data_iterator == control_styles::button_datas().end()) throw invalid_operation_exception(csf_);

  auto current_button_data = button_data_iterator->second;
  if ((button_state == push_button_state::normal || button_state == push_button_state::default_state) && back_color.has_value() && button_data_iterator->second.box().background_color().style() == color_style::solid) current_button_data.box().background_color(back_color.value());
  if (fore_color.has_value()) current_button_data.text().color(fore_color.value());
  if (font.has_value()) current_button_data.text().font(font.value());

  box_renderer::draw_box(graphics, bounds, current_button_data.box());
  text_renderer::draw_text(graphics, current_button_data.box().get_content_rectangle(bounds), text, current_button_data.text());
}
