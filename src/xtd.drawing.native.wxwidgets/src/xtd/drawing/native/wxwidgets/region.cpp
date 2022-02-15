#include <map>
#include <vector>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/region.h>
#include <xtd/drawing/native/toolkit.h>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/colour.h>
#include <wx/region.h>
#include <xtd/as.h>

using namespace std;
using namespace xtd::drawing::native;

namespace {
  static wxBitmap create_graphics_path_bitmap(wxGraphicsPath& path) noexcept {
    double x = .0f, y = .0f, width = .0f, height = .0f;
    path.GetBox(&x, &y, &width, &height);
    wxBitmap bitmap(static_cast<int32_t>(x + width), static_cast<int32_t>(y + height));
    auto graphics = wxGraphicsContext::Create(wxMemoryDC(bitmap));
    graphics->SetPen(graphics->CreatePen(wxNullPen));
    graphics->SetBrush(graphics->CreateBrush(wxBrush((wxColour(255, 0, 255)))));
    graphics->DrawRectangle(0, 0, x + width, y + height);
    graphics->SetBrush(graphics->CreateBrush(wxBrush((wxColour(0, 0, 0)))));
    graphics->FillPath(path);
    return bitmap;
  }
}

intptr_t region::create_from_rect(float x, float y, float width, float height) {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr_t>(new wxRegion(as<int32_t>(x), as<int32_t>(y), as<int32_t>(width), as<int32_t>(height)));
}

intptr_t region::create_from_graphics_path(intptr_t path) {
  auto wx_path = reinterpret_cast<wxGraphicsPath*>(path);
  wxBitmap bitmap = create_graphics_path_bitmap(*wx_path);
  return reinterpret_cast<intptr_t>(new wxRegion(bitmap, wxColour(255, 0, 255)));
}

void region::destroy(intptr_t handle) {
  delete reinterpret_cast<wxRegion*>(handle);
}

void region::complement(intptr_t handle, intptr_t region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region2.Subtract(region1);
  region1 = region2;
}

void region::exclude(intptr_t handle, intptr_t region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region1.Subtract(region2);
}

void region::intersect(intptr_t handle, intptr_t region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region1.Intersect(region2);
}

void region::make_union(intptr_t handle, intptr_t region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region1.Union(region2);
}

void region::make_xor(intptr_t handle, intptr_t region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region1.Xor(region2);
}
