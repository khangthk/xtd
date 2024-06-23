#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/settings>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <filesystem>

using namespace std;
using namespace std::filesystem;
using namespace std::literals;
using namespace xtd::native;

__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char** __argv;

string settings::get_path(const string& company_name, const string& product_name) {
  return path {path {__argv[0]}.parent_path() / path {product_name + ".ini"s}}.string();
}
