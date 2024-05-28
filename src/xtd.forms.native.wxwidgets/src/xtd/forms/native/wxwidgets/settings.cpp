#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application>
#include <xtd/forms/native/settings>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <wx/string.h>
#include <wx/config.h>
#if !defined(__WXMSW__)
#include <unistd.h>
#endif

using namespace xtd;
using namespace xtd::forms::native;

intptr xtd::forms::native::settings::create(const ustring& product_name, const ustring& company_name) {
  application::initialize(); // Must be first
  return reinterpret_cast<intptr>(new wxConfig(convert_string::to_wstring(product_name), convert_string::to_wstring(company_name)));
}

void xtd::forms::native::settings::destroy(intptr config) {
  if (!config) throw argument_exception {csf_};
  delete reinterpret_cast<wxConfig*>(config);
}

void xtd::forms::native::settings::reset(intptr config) {
  if (!config) throw argument_exception {csf_};
  reinterpret_cast<wxConfig*>(config)->DeleteAll();
}

ustring xtd::forms::native::settings::read(intptr config, const ustring& key, const ustring& default_value) {
  if (!config) throw argument_exception {csf_};
  return reinterpret_cast<wxConfig*>(config)->Read(convert_string::to_wstring(key), convert_string::to_wstring(default_value)).c_str().AsWChar();
}

void xtd::forms::native::settings::save(intptr config) {
  if (!config) throw argument_exception {csf_};
  reinterpret_cast<wxConfig*>(config)->Flush();
}

void xtd::forms::native::settings::write(intptr config, const ustring& key, const ustring& value) {
  if (!config) throw argument_exception {csf_};
  reinterpret_cast<wxConfig*>(config)->Write(convert_string::to_wstring(key), wxString(convert_string::to_wstring(value)));
}
