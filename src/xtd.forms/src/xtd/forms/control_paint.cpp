#include <xtd/as.h>
#include <xtd/math.h>
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/control.h"
#include "../../../include/xtd/forms/screen.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  static void draw_fixed_single_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect, bool light) {
    auto color = light ? light_color : dark_color;
    if ((sides & border_sides::top) == border_sides::top) graphics.draw_line(pen(color, 1), point {rect.left(), rect.top()}, point {rect.right(), rect.top()});
    if ((sides & border_sides::left) == border_sides::left) graphics.draw_line(pen(color, 1), point {rect.left(), rect.top()}, point {rect.left(), rect.bottom()});
    if ((sides & border_sides::bottom) == border_sides::bottom) graphics.draw_line(pen(color, 1), point {rect.left(), rect.bottom()}, point {rect.right(), rect.bottom()});
    if ((sides & border_sides::right) == border_sides::right) graphics.draw_line(pen(color, 1), point {rect.right(), rect.top()}, point {rect.right(), rect.bottom()});
  }
  
  static void draw_thin_sunken_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect) {
    if ((sides & border_sides::top) == border_sides::top) graphics.draw_line(pen(dark_color, 1), point {rect.left(), rect.top()}, point {rect.right(), rect.top()});
    if ((sides & border_sides::left) == border_sides::left) graphics.draw_line(pen(dark_color, 1), point {rect.left(), rect.top()}, point {rect.left(), rect.bottom()});
    if ((sides & border_sides::bottom) == border_sides::bottom) graphics.draw_line(pen(light_color, 1), point {rect.left(), rect.bottom()}, point {rect.right(), rect.bottom()});
    if ((sides & border_sides::right) == border_sides::right) graphics.draw_line(pen(light_color, 1), point {rect.right(), rect.top()}, point {rect.right(), rect.bottom()});
  }
  
  static void draw_thin_raised_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect) {
    if ((sides & border_sides::top) == border_sides::top) graphics.draw_line(pen(light_color, 1), point {rect.left(), rect.top()}, point {rect.right(), rect.top()});
    if ((sides & border_sides::left) == border_sides::left) graphics.draw_line(pen(light_color, 1), point {rect.left(), rect.top()}, point {rect.left(), rect.bottom()});
    if ((sides & border_sides::bottom) == border_sides::bottom) graphics.draw_line(pen(dark_color, 1), point {rect.left(), rect.bottom()}, point {rect.right(), rect.bottom()});
    if ((sides & border_sides::right) == border_sides::right) graphics.draw_line(pen(dark_color, 1), point {rect.right(), rect.top()}, point {rect.right(), rect.bottom()});
  }
  
  static void draw_bevel_sunken_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect) {
    if ((sides & border_sides::top) == border_sides::top) {
      graphics.draw_line(pen(dark_color, 1), point {rect.left(), rect.top()}, point {rect.right(), rect.top()});
      graphics.draw_line(pen(dark_color, 1), point {rect.left() + 1, rect.top() + 1}, point {rect.right() - 1, rect.top() + 1});
    }
    if ((sides & border_sides::left) == border_sides::left) {
      graphics.draw_line(pen(dark_color, 1), point {rect.left(), rect.top()}, point {rect.left(), rect.bottom()});
      graphics.draw_line(pen(dark_color, 1), point {rect.left() + 1, rect.top() + 1}, point {rect.left() + 1, rect.bottom() - 1});
    }
    if ((sides & border_sides::bottom) == border_sides::bottom) {
      graphics.draw_line(pen(light_color, 1), point {rect.left(), rect.bottom()}, point {rect.right(), rect.bottom()});
      graphics.draw_line(pen(light_color, 1), point {rect.left() + 1, rect.bottom() - 1}, point {rect.right() - 1, rect.bottom() - 1});
    }
    if ((sides & border_sides::right) == border_sides::right) {
      graphics.draw_line(pen(light_color, 1), point {rect.right(), rect.top()}, point {rect.right(), rect.bottom()});
      graphics.draw_line(pen(light_color, 1), point {rect.right() - 1, rect.top() + 1}, point {rect.right() - 1, rect.bottom() - 1});
    }
  }
  
  static void draw_bevel_raised_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect) {
    if ((sides & border_sides::top) == border_sides::top) {
      graphics.draw_line(pen(light_color, 1), point {rect.left(), rect.top()}, point {rect.right(), rect.top()});
      graphics.draw_line(pen(light_color, 1), point {rect.left() + 1, rect.top() + 1}, point {rect.right() - 1, rect.top() + 1});
    }
    if ((sides & border_sides::left) == border_sides::left) {
      graphics.draw_line(pen(light_color, 1), point {rect.left(), rect.top()}, point {rect.left(), rect.bottom()});
      graphics.draw_line(pen(light_color, 1), point {rect.left() + 1, rect.top() + 1}, point {rect.left() + 1, rect.bottom() - 1});
    }
    if ((sides & border_sides::bottom) == border_sides::bottom) {
      graphics.draw_line(pen(dark_color, 1), point {rect.left(), rect.bottom()}, point {rect.right(), rect.bottom()});
      graphics.draw_line(pen(dark_color, 1), point {rect.left() + 1, rect.bottom() - 1}, point {rect.right() - 1, rect.bottom() - 1});
    }
    if ((sides & border_sides::right) == border_sides::right) {
      graphics.draw_line(pen(dark_color, 1), point {rect.right(), rect.top()}, point {rect.right(), rect.bottom()});
      graphics.draw_line(pen(dark_color, 1), point {rect.right() - 1, rect.top() + 1}, point {rect.right() - 1, rect.bottom() - 1});
    }
  }
  
  static void draw_etched_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect) {
    if ((sides & border_sides::top) == border_sides::top) {
      graphics.draw_line(pen(dark_color, 1), point {rect.left(), rect.top()}, point {rect.right(), rect.top()});
      graphics.draw_line(pen(light_color, 1), point {rect.left() + 1, rect.top() + 1}, point {rect.right() - 1, rect.top() + 1});
    }
    if ((sides & border_sides::left) == border_sides::left) {
      graphics.draw_line(pen(dark_color, 1), point {rect.left(), rect.top()}, point {rect.left(), rect.bottom()});
      graphics.draw_line(pen(light_color, 1), point {rect.left() + 1, rect.top() + 1}, point {rect.left() + 1, rect.bottom() - 1});
    }
    if ((sides & border_sides::bottom) == border_sides::bottom) {
      graphics.draw_line(pen(light_color, 1), point {rect.left(), rect.bottom()}, point {rect.right(), rect.bottom()});
      graphics.draw_line(pen(dark_color, 1), point {rect.left() + 1, rect.bottom() - 1}, point {rect.right() - 1, rect.bottom() - 1});
    }
    if ((sides & border_sides::right) == border_sides::right) {
      graphics.draw_line(pen(light_color, 1), point {rect.right(), rect.top()}, point {rect.right(), rect.bottom()});
      graphics.draw_line(pen(dark_color, 1), point {rect.right() - 1, rect.top() + 1}, point {rect.right() - 1, rect.bottom() - 1});
    }
  }
  
  static void draw_bump_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect) {
    if ((sides & border_sides::top) == border_sides::top) {
      graphics.draw_line(pen(light_color, 1), point {rect.left(), rect.top()}, point {rect.right(), rect.top()});
      graphics.draw_line(pen(dark_color, 1), point {rect.left() + 1, rect.top() + 1}, point {rect.right() - 1, rect.top() + 1});
    }
    if ((sides & border_sides::left) == border_sides::left) {
      graphics.draw_line(pen(light_color, 1), point {rect.left(), rect.top()}, point {rect.left(), rect.bottom()});
      graphics.draw_line(pen(dark_color, 1), point {rect.left() + 1, rect.top() + 1}, point {rect.left() + 1, rect.bottom() - 1});
    }
    if ((sides & border_sides::bottom) == border_sides::bottom) {
      graphics.draw_line(pen(dark_color, 1), point {rect.left(), rect.bottom()}, point {rect.right(), rect.bottom()});
      graphics.draw_line(pen(light_color, 1), point {rect.left() + 1, rect.bottom() - 1}, point {rect.right() - 1, rect.bottom() - 1});
    }
    if ((sides & border_sides::right) == border_sides::right) {
      graphics.draw_line(pen(dark_color, 1), point {rect.right(), rect.top()}, point {rect.right(), rect.bottom()});
      graphics.draw_line(pen(light_color, 1), point {rect.right() - 1, rect.top() + 1}, point {rect.right() - 1, rect.bottom() - 1});
    }
  }
  
  static void draw_themed_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect) {
    if ((sides & border_sides::top) == border_sides::top) {
      graphics.draw_line(pen(dark_color, 1), point {rect.left(), rect.top()}, point {rect.right(), rect.top()});
      graphics.draw_line(pen(light_color, 1), point {rect.left() + 1, rect.top() + 1}, point {rect.right() - 1, rect.top() + 1});
    }
    if ((sides & border_sides::left) == border_sides::left) {
      graphics.draw_line(pen(dark_color, 1), point {rect.left(), rect.top()}, point {rect.left(), rect.bottom()});
      graphics.draw_line(pen(light_color, 1), point {rect.left() + 1, rect.top() + 1}, point {rect.left() + 1, rect.bottom() - 1});
    }
    if ((sides & border_sides::bottom) == border_sides::bottom) {
      graphics.draw_line(pen(dark_color, 1), point {rect.left(), rect.bottom()}, point {rect.right(), rect.bottom()});
      graphics.draw_line(pen(light_color, 1), point {rect.left() + 1, rect.bottom() - 1}, point {rect.right() - 1, rect.bottom() - 1});
    }
    if ((sides & border_sides::right) == border_sides::right) {
      graphics.draw_line(pen(dark_color, 1), point {rect.right(), rect.top()}, point {rect.right(), rect.bottom()});
      graphics.draw_line(pen(light_color, 1), point {rect.right() - 1, rect.top() + 1}, point {rect.right() - 1, rect.bottom() - 1});
    }
  }
  
  static void draw_rounded_single_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect, bool light) {
    //graphics.draw_rounded_rectangle(pen(light ? light_color : dark_color, 1), rect, 4);
    
    int32_t radius = 6;
    if (math::max(rect.width(), rect.height()) <= 12) radius = 5;
    if (math::max(rect.width(), rect.height()) <= 10) radius = 4;
    if (math::max(rect.width(), rect.height()) <= 8) radius = 3;
    if (math::max(rect.width(), rect.height()) <= 6) radius = 2;
    if (math::max(rect.width(), rect.height()) <= 4) radius = 1;
    if (math::max(rect.width(), rect.height()) <= 2) radius = 0;
    
    if ((sides & border_sides::top) == border_sides::top) {
      // top
      graphics.draw_line(pen(light ? light_color : dark_color, 1), rect.x() + radius, rect.y(), rect.right() - radius, rect.y());
      // top-left
      graphics.draw_arc(pen(light ? light_color : dark_color, 1), rect.x(), rect.y(), radius * 2, radius * 2, 225, 45);
      // top-right
      graphics.draw_arc(pen(light ? light_color : dark_color, 1), rect.right() - radius * 2, rect.y(), radius * 2, radius * 2, 270, 45);
    }
    
    if ((sides & border_sides::left) == border_sides::left) {
      // left
      graphics.draw_line(pen(light ? light_color : dark_color, 1), rect.x(), rect.y() + radius, rect.x(), rect.bottom() - radius);
      // left-top
      graphics.draw_arc(pen(light ? light_color : dark_color, 1), rect.x(), rect.y(), radius * 2, radius * 2, 180, 45);
      // left-bottom
      graphics.draw_arc(pen(light ? light_color : dark_color, 1), rect.x(), rect.bottom() - radius * 2, radius * 2, radius * 2, 135, 45);
    }
    
    if ((sides & border_sides::bottom) == border_sides::bottom) {
      // botttom
      graphics.draw_line(pen(light ? light_color : dark_color, 1), rect.x() + radius, rect.bottom(), rect.right() - radius, rect.bottom());
      // bottom-left
      graphics.draw_arc(pen(light ? light_color : dark_color, 1), rect.x(), rect.bottom() - radius * 2, radius * 2, radius * 2, 90, 45);
      // botttom-right
      graphics.draw_arc(pen(light ? light_color : dark_color, 1), rect.right() - radius * 2, rect.bottom() - radius * 2, radius * 2, radius * 2, 45, 45);
    }
    
    if ((sides & border_sides::right) == border_sides::right) {
      // right
      graphics.draw_line(pen(light ? light_color : dark_color, 1), rect.right(), rect.y() + radius, rect.right(), rect.bottom() - radius);
      // right-top
      graphics.draw_arc(pen(light ? light_color : dark_color, 1), rect.right() - radius * 2, rect.y(), radius * 2, radius * 2, 315, 45);
      // right-bottom
      graphics.draw_arc(pen(light ? light_color : dark_color, 1), rect.right() - radius * 2, rect.bottom() - radius * 2, radius * 2, radius * 2, 0, 45);
    }
  }
  
  static void draw_dot_single_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect, bool light) {
    pen dot_pen(light ? light_color : dark_color, 1);
    dot_pen.dash_style(dash_style::dot);
    if ((sides & border_sides::top) == border_sides::top) graphics.draw_line(dot_pen, point {rect.left(), rect.top()}, point {rect.right(), rect.top()});
    if ((sides & border_sides::left) == border_sides::left) graphics.draw_line(dot_pen, point {rect.left(), rect.top()}, point {rect.left(), rect.bottom()});
    if ((sides & border_sides::bottom) == border_sides::bottom) graphics.draw_line(dot_pen, point {rect.left(), rect.bottom()}, point {rect.right(), rect.bottom()});
    if ((sides & border_sides::right) == border_sides::right) graphics.draw_line(dot_pen, point {rect.right(), rect.top()}, point {rect.right(), rect.bottom()});
  }
  
  static void draw_dash_single_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect, bool light) {
    pen dash_pen(light ? light_color : dark_color, 1);
    dash_pen.dash_style(dash_style::dash);
    if ((sides & border_sides::top) == border_sides::top) graphics.draw_line(dash_pen, point {rect.left(), rect.top()}, point {rect.right(), rect.top()});
    if ((sides & border_sides::left) == border_sides::left) graphics.draw_line(dash_pen, point {rect.left(), rect.top()}, point {rect.left(), rect.bottom()});
    if ((sides & border_sides::bottom) == border_sides::bottom) graphics.draw_line(dash_pen, point {rect.left(), rect.bottom()}, point {rect.right(), rect.bottom()});
    if ((sides & border_sides::right) == border_sides::right) graphics.draw_line(dash_pen, point {rect.right(), rect.top()}, point {rect.right(), rect.bottom()});
  }
  
  static void draw_dash_dot_single_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect, bool light) {
    pen dash_pen(light ? light_color : dark_color, 1);
    dash_pen.dash_style(dash_style::dash_dot);
    if ((sides & border_sides::top) == border_sides::top) graphics.draw_line(dash_pen, point {rect.left(), rect.top()}, point {rect.right(), rect.top()});
    if ((sides & border_sides::left) == border_sides::left) graphics.draw_line(dash_pen, point {rect.left(), rect.top()}, point {rect.left(), rect.bottom()});
    if ((sides & border_sides::bottom) == border_sides::bottom) graphics.draw_line(dash_pen, point {rect.left(), rect.bottom()}, point {rect.right(), rect.bottom()});
    if ((sides & border_sides::right) == border_sides::right) graphics.draw_line(dash_pen, point {rect.right(), rect.top()}, point {rect.right(), rect.bottom()});
  }
  
  static void draw_dash_dot_dot_single_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect, bool light) {
    pen dash_pen(light ? light_color : dark_color, 1);
    dash_pen.dash_style(dash_style::dash_dot_dot);
    if ((sides & border_sides::top) == border_sides::top) graphics.draw_line(dash_pen, point {rect.left(), rect.top()}, point {rect.right(), rect.top()});
    if ((sides & border_sides::left) == border_sides::left) graphics.draw_line(dash_pen, point {rect.left(), rect.top()}, point {rect.left(), rect.bottom()});
    if ((sides & border_sides::bottom) == border_sides::bottom) graphics.draw_line(dash_pen, point {rect.left(), rect.bottom()}, point {rect.right(), rect.bottom()});
    if ((sides & border_sides::right) == border_sides::right) graphics.draw_line(dash_pen, point {rect.right(), rect.top()}, point {rect.right(), rect.bottom()});
  }
  
  static void draw_fixed_double_border(drawing::graphics& graphics, border_sides sides, const color& dark_color, const color& light_color, const rectangle& rect, bool light) {
    auto color = light ? light_color : dark_color;
    if ((sides & border_sides::top) == border_sides::top) {
      graphics.draw_line(pen(color, 1), point {rect.left(), rect.top()}, point {rect.right(), rect.top()});
      graphics.draw_line(pen(color, 1), point {rect.left() + 2, rect.top() + 2}, point {rect.right() - 2, rect.top() + 2});
    }
    if ((sides & border_sides::left) == border_sides::left) {
      graphics.draw_line(pen(color, 1), point {rect.left(), rect.top()}, point {rect.left(), rect.bottom()});
      graphics.draw_line(pen(color, 1), point {rect.left() + 2, rect.top() + 2}, point {rect.left() + 2, rect.bottom() - 2});
    }
    if ((sides & border_sides::bottom) == border_sides::bottom) {
      graphics.draw_line(pen(color, 1), point {rect.left(), rect.bottom()}, point {rect.right(), rect.bottom()});
      graphics.draw_line(pen(color, 1), point {rect.left() + 2, rect.bottom() - 2}, point {rect.right() - 2, rect.bottom() - 2});
    }
    if ((sides & border_sides::right) == border_sides::right) {
      graphics.draw_line(pen(color, 1), point {rect.right(), rect.top()}, point {rect.right(), rect.bottom()});
      graphics.draw_line(pen(color, 1), point {rect.right() - 2, rect.top() + 2}, point {rect.right() - 2, rect.bottom() - 2});
    }
  }
}

color control_paint::average(const color& color1, const color& color2, double weight, bool average_alpha) {
  return color::average(color1, color2, weight, average_alpha);
}

color control_paint::average(const color& color1, const color& color2, double weight) {
  return average(color1, color2, weight, false);
}

color control_paint::dark(const xtd::drawing::color& base_color) {
  return dark(base_color, 1.0 / 3);
}

color control_paint::dark(const color& base_color, double perc_of_dark_dark) {
  return color::dark(base_color, perc_of_dark_dark);
}

color control_paint::dark_dark(const color& base_color) {
  return dark(base_color, 1.0);
}

void control_paint::draw_button(const forms::control& control, drawing::graphics& graphics, const drawing::rectangle& rectangle, button_state state) {
  draw_button(control, graphics, rectangle.x(), rectangle.y(), rectangle.width(), rectangle.height(), state);
}

void control_paint::draw_button(const forms::control& control, drawing::graphics& graphics, int32_t x, int32_t y, int32_t width, int32_t height, button_state state) {

}

void control_paint::draw_border(const forms::control& control, drawing::graphics& graphics, border_style border, border_sides sides, const drawing::color& color, const rectangle& rect) {
  draw_border(control, graphics, border, sides, color, rect, color.is_light());
}

void control_paint::draw_border(const forms::control& control, drawing::graphics& graphics, border_style border, border_sides sides, const drawing::color& color, const rectangle& rect, bool light) {
  auto percent_of_color = 2.0 / 3;
  auto dark_color = dark(color, percent_of_color);
  auto light_color = color;
  auto border_rect = screen::from_control(control).high_resolution() ? rect : rectangle::inflate(rect,  drawing::size {-1, -1});
  
  switch (border) {
    case border_style::none: break;
    case border_style::fixed_single: draw_fixed_single_border(graphics, sides, dark_color, light_color, border_rect, light); break;
    case border_style::thin_sunken: draw_thin_sunken_border(graphics, sides, dark_color, light_color, border_rect); break;
    case border_style::thin_raised: draw_thin_raised_border(graphics, sides, dark_color, light_color, border_rect); break;
    case border_style::bevel_sunken: draw_bevel_sunken_border(graphics, sides, dark_color, light_color, border_rect); break;
    case border_style::bevel_raised: draw_bevel_raised_border(graphics, sides, dark_color, light_color, border_rect); break;
    case border_style::etched: draw_etched_border(graphics, sides, dark_color, light_color, border_rect); break;
    case border_style::bump: draw_bump_border(graphics, sides, dark_color, light_color, border_rect); break;
    case border_style::themed: draw_themed_border(graphics, sides, dark_color, light_color, border_rect); break;
    case border_style::rounded_single: draw_rounded_single_border(graphics, sides, dark_color, light_color, border_rect, light); break;
    case border_style::dot_single: draw_dot_single_border(graphics, sides, dark_color, light_color, border_rect, light); break;
    case border_style::dash_single: draw_dash_single_border(graphics, sides, dark_color, light_color, border_rect, light); break;
    case border_style::dash_dot_single: draw_dash_dot_single_border(graphics, sides, dark_color, light_color, border_rect, light); break;
    case border_style::dash_dot_dot_single: draw_dash_dot_dot_single_border(graphics, sides, dark_color, light_color, border_rect, light); break;
    case border_style::fixed_double: draw_fixed_double_border(graphics, sides, dark_color, light_color, border_rect, light); break;
  }
}

void control_paint::draw_border_from_back_color(const forms::control& control, drawing::graphics& graphics, border_style border, border_sides sides, const color& back_color, const rectangle& rect) {
  auto percent_of_color = back_color.is_dark() ? 1.0 / 3 : 2.0 / 3;
  draw_border(control, graphics, border, sides, light(back_color, percent_of_color), rect, back_color.is_dark());
}

void control_paint::draw_image(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle, xtd::forms::image_layout image_layout) {draw_image(graphics, image, rectangle.x(), rectangle.y(), rectangle.width(), rectangle.height(), image_layout);}


void control_paint::draw_image(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, int32_t x, int32_t y, int32_t width, int32_t height, xtd::forms::image_layout image_layout) {
  if (image_layout == xtd::forms::image_layout::none)
    graphics.draw_image(image, x, y);
  else if (image_layout == xtd::forms::image_layout::tile) {
    for (int32_t offset_y = 0; offset_y < height; offset_y += image.size().height())
      for (int32_t offset_x = 0; offset_x < width; offset_x += image.size().width())
        graphics.draw_image(image, x + offset_x, y + offset_y);
  } else if (image_layout == xtd::forms::image_layout::center)
    graphics.draw_image(image, x + (width - image.width()) / 2, y + (height - image.height()) / 2);
  else if (image_layout == xtd::forms::image_layout::stretch)
    graphics.draw_image(image, x, y, width, height);
  else if (image_layout == xtd::forms::image_layout::zoom) {
    auto target_ratio = as<float>(width) / height;
    auto image_ratio = as<float>(image.width()) / image.height();
    auto ratio = target_ratio > image_ratio ? as<float>(height) / image.height() : as<float>(width) / image.width();
    auto image_rect = xtd::drawing::rectangle(as<int32_t>(width - image.width() * ratio) / 2, as<int32_t>(height - image.height() * ratio) / 2, as<int32_t>(image.width() * ratio), as<int32_t>(image.height() * ratio));
    graphics.draw_image(image, image_rect);
  }
}

void control_paint::draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, int32_t x, int32_t y, float brightness) {
  graphics.draw_image_disabled(image, x, y, brightness);
}

void control_paint::draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, int32_t x, int32_t y, const xtd::drawing::color& background) {
  draw_image_disabled(graphics, image, x, y, background.get_brightness());
}

void control_paint::draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, const point& location, float brightness) {
  draw_image_disabled(graphics, image, location.x(), location.y(), brightness);
}

void control_paint::draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, const point& location, const xtd::drawing::color& background) {
  draw_image_disabled(graphics, image, location.x(), location.y(), background.get_brightness());
}

xtd::drawing::color control_paint::light(const xtd::drawing::color& base_color) {
  return light(base_color, 1.0 / 3);
}

xtd::drawing::color control_paint::light(const xtd::drawing::color& base_color, double perc_of_light_light) {
  return xtd::drawing::color::light(base_color, perc_of_light_light);
}

xtd::drawing::color control_paint::light_light(const xtd::drawing::color& base_color) {
  return light(base_color, 1.0);
}

xtd::drawing::string_format control_paint::string_format(xtd::forms::text_format_flags flags) {
  xtd::drawing::string_format string_format;
  string_format.line_alignment(xtd::drawing::string_alignment::center);
  string_format.alignment(xtd::drawing::string_alignment::center);
  
  if ((flags & text_format_flags::horizontal_center) == text_format_flags::horizontal_center) string_format.alignment(xtd::drawing::string_alignment::center);
  else if ((flags & text_format_flags::right) == text_format_flags::right) string_format.alignment(xtd::drawing::string_alignment::far);
  else string_format.alignment(xtd::drawing::string_alignment::near);
  
  if ((flags & text_format_flags::vertical_center) == text_format_flags::vertical_center) string_format.line_alignment(xtd::drawing::string_alignment::center);
  else if ((flags & text_format_flags::bottom) == text_format_flags::bottom) string_format.line_alignment(xtd::drawing::string_alignment::far);
  else string_format.line_alignment(xtd::drawing::string_alignment::near);
  
  if ((flags & text_format_flags::no_prefix) == text_format_flags::no_prefix) string_format.hotkey_prefix(xtd::drawing::hotkey_prefix::none);
  else if ((flags & text_format_flags::hide_prefix) == text_format_flags::hide_prefix) string_format.hotkey_prefix(xtd::drawing::hotkey_prefix::hide);
  else string_format.hotkey_prefix(xtd::drawing::hotkey_prefix::show);
  
  return string_format;
}
