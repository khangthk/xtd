#include <xtd/io>
#include <xtd/tunit>

using namespace std;
using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_file) {
  public:
    static constexpr auto test_file_name = "file.txt";
    void test_initialize_(test_initialize) {
      if (std::ifstream(test_file_name).good())
        ::remove(test_file_name);
    }
    
    void test_cleanup_(test_clean_up) {
      if (std::ifstream(test_file_name).good())
        ::remove(test_file_name);
    }

    void test_method_(append_all_lines) {
      assert::is_true(file::append_all_lines(test_file_name, {"Line 1"}));
      assert::is_true(file::append_all_lines(test_file_name, {"Line 2", "Line 3"}));
      std::ifstream file(test_file_name);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Line 1\nLine 2\nLine 3\n", contents);
    }

    void test_method_(append_all_text) {
      assert::is_true(file::append_all_text(test_file_name, "This is a text\n"));
      assert::is_true(file::append_all_text(test_file_name, "to append"));
      std::ifstream file(test_file_name);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("This is a text\nto append", contents);
    }
    
    void test_method_(copy) {
      assert::is_true(file::append_all_text(test_file_name, "Text"));
      assert::is_true(file::copy(test_file_name, "file2.txt"));
      assert::is_true(std::ifstream(test_file_name).good());
      std::ifstream file("file2.txt");
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents);
      ::remove("file2.txt");
    }
    
    void test_method_(copy_with_override) {
      std::ofstream existing_file("file2.txt");
      existing_file << "Existing";
      existing_file.close();
      assert::is_true(file::append_all_text(test_file_name, "Text"));
      assert::is_true(file::copy(test_file_name, "file2.txt", true));
      assert::is_true(std::ifstream(test_file_name).good());
      std::ifstream file("file2.txt");
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents);
      ::remove("file2.txt");
    }
    
    void test_method_(copy_with_override_false) {
      std::ofstream existing_file("file2.txt");
      existing_file << "Existing";
      existing_file.close();
      assert::is_true(file::append_all_text(test_file_name, "Text"));
      assert::is_false(file::copy(test_file_name, "file2.txt", false));
      assert::is_true(std::ifstream(test_file_name).good());
      std::ifstream file("file2.txt");
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Existing", contents);
      ::remove("file2.txt");
    }

    void test_method_(create) {
      auto file = file::create(test_file_name);
      assert::is_true(file.good());
      file.seekp(0, ios::end);
      assert::are_equal(0, file.tellp());
    }
    
    void test_method_(create_with_override) {
      assert::is_true(file::append_all_text(test_file_name, "Text"));
      auto file = file::create(test_file_name);
      assert::is_true(file.good());
      file.seekp(0, ios::end);
      assert::are_equal(0, file.tellp());
    }

    void test_method_(create_text) {
      auto file = file::create_text(test_file_name);
      assert::is_true(file.good());
      file.seekp(0, ios::end);
      assert::are_equal(0, file.tellp());
    }
    
    void test_method_(create_text_with_override) {
      assert::is_true(file::append_all_text(test_file_name, "Text"));
      auto file = file::create_text(test_file_name);
      assert::is_true(file.good());
      file.seekp(0, ios::end);
      assert::are_equal(0, file.tellp());
    }

    void test_method_(exists) {
      assert::is_false(file::exists(test_file_name));
      std::ofstream file(test_file_name);
      file.close();
      assert::is_true(file::exists(test_file_name));
    }
    
    void test_method_(get_attributes_directory) {
      assert::is_true((file::get_attributes(".") & file_attributes::directory) == file_attributes::directory);
    }
    
    void test_method_(get_attributes_normal) {
      std::ofstream file(test_file_name);
      file.close();
      assert::is_true((file::get_attributes(test_file_name) & file_attributes::normal) == file_attributes::normal);
    }
    
    void test_method_(move) {
      assert::is_true(file::append_all_text(test_file_name, "Text"));
      assert::is_true(file::move(test_file_name, "file2.txt"));
      assert::is_false(std::ifstream(test_file_name).good());
      std::ifstream file("file2.txt");
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents);
      ::remove("file2.txt");
    }
    
    void test_method_(move_on_existing_file) {
      std::ofstream existing_file("file2.txt");
      existing_file << "Existing";
      existing_file.close();
      assert::is_true(file::append_all_text(test_file_name, "Text"));
      assert::is_false(file::move(test_file_name, "file2.txt"));
      assert::is_true(std::ifstream(test_file_name).good());
      std::ifstream file(test_file_name);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents);
      std::ifstream file2("file2.txt");
      contents = {istreambuf_iterator<char> {file2}, istreambuf_iterator<char> {}};
      assert::are_equal("Existing", contents);
      ::remove("file2.txt");
    }
  };
}
