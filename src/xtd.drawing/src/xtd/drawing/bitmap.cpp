#include "../../../include/xtd/drawing/bitmap.h"
#include <xtd/argument_exception.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/image.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;

bitmap bitmap::empty;

bitmap::bitmap(const image& original) : xtd::drawing::image(original) {
}

bitmap::bitmap(const image& original, const xtd::drawing::size& new_size) : xtd::drawing::image(original, new_size.width(), new_size.height()) {
}

bitmap::bitmap(const image& original, int32 width, int32 height) : xtd::drawing::image(original, width, height) {
}

bitmap::bitmap(const image& original, const rectangle& new_rect) : xtd::drawing::image(original, new_rect) {
}

bitmap::bitmap(const xtd::ustring& filename) : xtd::drawing::image(filename) {
}

bitmap::bitmap(const xtd::ustring& filename, bool use_icm) : xtd::drawing::image(filename, use_icm) {
}

bitmap::bitmap(std::istream& stream) : xtd::drawing::image(stream) {
}

bitmap::bitmap(std::istream& stream, bool use_icm) : xtd::drawing::image(stream, use_icm) {
}

bitmap::bitmap(const char* const* bits) : xtd::drawing::image(bits) {
}

bitmap::bitmap(int32 width, int32 height) : xtd::drawing::image(width, height) {
}

bitmap::bitmap(int32 width, int32 height, const graphics& g) : xtd::drawing::image(width, height, g.dpi_x(), g.dpi_y()) {
}

bitmap::bitmap(int32 width, int32 height, xtd::drawing::imaging::pixel_format format) : xtd::drawing::image(width, height, format) {
}

bitmap::bitmap(int32 width, int32 height, int32 stride, xtd::drawing::imaging::pixel_format format, intptr scan0) : xtd::drawing::image(width, height, stride, format, scan0) {
}

bitmap::bitmap(const xtd::drawing::size& size) : xtd::drawing::image(size.width(), size.height()) {
}

bitmap bitmap::clone(const rectangle& rect) const {
  return bitmap(*this, rect);
}

bitmap bitmap::clone(const rectangle_f& rect) const {
  return bitmap(*this, xtd::drawing::rectangle::ceiling(rect));
}

bitmap bitmap::from_hicon(intptr hicon) {
  return bitmap(image::from_hicon(hicon));
}

intptr bitmap::get_hbitmap() const {
  return native::image::get_hbitmap(handle());
}

intptr bitmap::get_hbitmap(const color& background) const {
  return native::image::get_hbitmap(handle(), background.a(), background.r(), background.g(), background.b());
}

intptr bitmap::get_hicon() const {
  return native::image::get_hicon(handle());
}

drawing::color bitmap::get_pixel(int32 x, int32 y) const {
  xtd::byte a = 0, r = 0, g = 0, b = 0;
  native::image::get_pixel(handle(), x, y, a, r, g, b);
  return color::from_argb(a, r, g, b);
}

bitmap_data bitmap::lock_bits(const rectangle& rect, xtd::drawing::imaging::image_lock_mode flags, xtd::drawing::imaging::pixel_format format) {
  return lock_bits(rect, flags, format, bitmap_data {});
}

bitmap_data bitmap::lock_bits(const rectangle& rect, xtd::drawing::imaging::image_lock_mode flags, xtd::drawing::imaging::pixel_format format, const bitmap_data& data) {
  if (format == xtd::drawing::imaging::pixel_format::indexed || format == xtd::drawing::imaging::pixel_format::gdi) throw argument_exception(csf_);
  int32 height = data.height();
  int32 pixel_format = static_cast<int32>(data.pixel_format());
  int32 reserved = data.reserved();
  intptr scan0 = data.scan0();
  int32 stride = data.stride();
  int32 width = data.width();
  native::image::lock_bits(handle(), height, pixel_format, reserved, scan0, stride, width);
  return bitmap_data().height(height).pixel_format(static_cast<xtd::drawing::imaging::pixel_format>(pixel_format)).reserved(reserved).scan0(scan0).stride(stride).width(width);
}

void bitmap::set_pixel(int32 x, int32 y, const drawing::color& color) {
  native::image::set_pixel(handle(), x, y, color.a(), color.r(), color.g(), color.b());
}
