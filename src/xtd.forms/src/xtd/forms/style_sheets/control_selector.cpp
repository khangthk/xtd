#include "../../../../include/xtd/forms/style_sheets/control_selector.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

control_selector::control_selector(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::drawing::color& background_color, std::optional<int32_t> width, std::optional<int32_t> height, const xtd::drawing::color& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_color_(background_color), width_(width), height_(height), color_(color), alignment_(alignment), font_(font) {
}

control_selector::control_selector(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::forms::style_sheets::background_image& background_image, std::optional<int32_t> width, std::optional<int32_t> height, const xtd::drawing::color& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_image_(background_image), width_(width), height_(height), color_(color), alignment_(alignment), font_(font) {
}

const drawing::color& control_selector::background_color() const noexcept {
  return background_color_;
}

void control_selector::background_color(const drawing::color& value) noexcept {
  background_color_ = value;
}

const style_sheets::background_image& control_selector::background_image() const noexcept {
  return background_image_;
}

void control_selector::background_image(const style_sheets::background_image& value) noexcept {
  background_image_ = value;
}

const xtd::forms::style_sheets::border_color& control_selector::border_color() const noexcept {
  return border_color_;
}

void control_selector::border_color(const xtd::forms::style_sheets::border_color& value) noexcept {
  border_color_ = value;
}

xtd::forms::style_sheets::border_radius control_selector::border_radius() const noexcept {
  return border_radius_;
}

void control_selector::border_radius(xtd::forms::style_sheets::border_radius value) noexcept {
  border_radius_ = value;
}

xtd::forms::style_sheets::border_style control_selector::border_style() const noexcept {
  return border_style_;
}

void control_selector::border_style(xtd::forms::style_sheets::border_style value) noexcept {
  border_style_ = value;
}

xtd::forms::style_sheets::border_width control_selector::border_width() const noexcept {
  return border_width_;
}

void control_selector::border_width(xtd::forms::style_sheets::border_width value) noexcept {
  border_width_ = value;
}

optional<int32_t> control_selector::height() const noexcept {
  return height_;
}

void control_selector::height(const std::optional<int32_t>& value) noexcept {
  height_ = value;
}

const xtd::forms::padding& control_selector::margin() const noexcept {
  return margin_;
}

void control_selector::margin(const xtd::forms::padding& value) noexcept {
  margin_ = value;
}

const xtd::forms::padding& control_selector::padding() const noexcept {
  return padding_;
}

void control_selector::padding(const xtd::forms::padding& value) noexcept {
  padding_ = value;
}

optional<int32_t> control_selector::width() const noexcept {
  return width_;
}

void control_selector::width(optional<int32_t> value) noexcept {
  width_ = value;
}

content_alignment control_selector::alignment() const noexcept {
  return alignment_;
}

void control_selector::alignment(content_alignment value) noexcept {
  alignment_ = value;
}

const drawing::color& control_selector::color() const noexcept {
  return color_;
}

void control_selector::color(const drawing::color& value) noexcept {
  color_ = value;
}

text_decoration control_selector::decoration() const noexcept {
  return decoration_;
}

void control_selector::decoration(text_decoration value) noexcept {
  decoration_ = value;
}

text_transformation control_selector::transformation() const noexcept {
  return transformation_;
}

void control_selector::transformation(text_transformation value) noexcept {
  transformation_ = value;
}

const font& control_selector::font() const noexcept {
  return font_;
}

void control_selector::font(const drawing::font& value) noexcept {
  font_ = value;
}

bool control_selector::equals(const object& other) const noexcept {
  return is<control_selector>(other) ? equals(static_cast<const control_selector&>(other)) : false;
}

bool control_selector::equals(const control_selector& other) const noexcept {
  return margin_ == other.margin_ && border_style_ == other.border_style_ && border_color_ == other.border_color_ && border_width_ == other.border_width_ && border_radius_ == other.border_radius_ && padding_ == other.padding_ && background_color_ == other.background_color_ && background_image_ == other.background_image_ && width_ == other.width_ && height_ == other.height_ && color_ == other.color_ && alignment_ == other.alignment_ && font_ == other.font_ && decoration_ == other.decoration_ && transformation_ == other.transformation_;
}

rectangle control_selector::get_border_rectangle(const rectangle& bounds) const noexcept {
  auto bounds_rect = bounds;
  if (width() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), margin().left() + border_width().left() + padding().left() + width().value() + padding().right() + border_width().right() + margin().right(), bounds_rect.height());
  if (height() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), bounds_rect.width(), margin().top() + border_width().top() + padding().top() + height().value() + padding().bottom() + border_width().bottom() + margin().bottom());
  
  auto border_rect = rectangle::offset(bounds_rect, margin().left(), margin().top());
  border_rect = rectangle::inflate(border_rect, -margin().right() - margin().left(), -margin().bottom() - margin().top());
  return border_rect;
}

rectangle control_selector::get_fill_rectangle(const rectangle& bounds) const noexcept {
  auto fill_rect = rectangle::offset(get_border_rectangle(bounds), border_width().left(), border_width().top());
  fill_rect = rectangle::inflate(fill_rect, -border_width().left() - border_width().right(), -border_width().top() - border_width().bottom());
  return fill_rect;
}

rectangle control_selector::get_content_rectangle(const rectangle& bounds) const noexcept {
  auto content_rect = rectangle::offset(get_fill_rectangle(bounds), padding().left(), padding().top());
  content_rect = rectangle::inflate(content_rect, -padding().left() - padding().right(), -padding().top() - padding().bottom());
  return content_rect;
}

string_format control_selector::control_selector::make_string_format() const noexcept {
  string_format format;
  format.line_alignment(xtd::drawing::string_alignment::center);
  format.alignment(xtd::drawing::string_alignment::center);
  
  if (alignment() == content_alignment::top_left) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (alignment() == content_alignment::top_center) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (alignment() == content_alignment::top_right) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::far);
  }
  
  if (alignment() == content_alignment::middle_left) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (alignment() == content_alignment::middle_center) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (alignment() == content_alignment::middle_right) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::far);
  }
  
  if (alignment() == content_alignment::bottom_left) {
    format.line_alignment(xtd::drawing::string_alignment::far);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (alignment() == content_alignment::bottom_center) {
    format.line_alignment(xtd::drawing::string_alignment::far);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (alignment() == content_alignment::bottom_right) {
    format.alignment(xtd::drawing::string_alignment::far);
    format.line_alignment(xtd::drawing::string_alignment::far);
  }
  
  return format;
}
