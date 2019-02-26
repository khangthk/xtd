#include "../include/xtd/assert.hpp"
#include "../include/xtd/test.hpp"
#include <string>

using namespace xtd::tunit;
using namespace std;
using namespace std::string_literals;

void assert::abort(const std::string& abort_message, const std::string& user_message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().message_ = abort_message;
  xtd::tunit::test::current_test().status_ = test::test_status::aborted;
  xtd::tunit::test::current_test().user_message_ = user_message;
  throw abort_error(user_message != ""s ? user_message : "aborted!"s);
}

void assert::fail(const std::string& expected, const std::string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().actual_ = actual;
  xtd::tunit::test::current_test().expect_ = expected;
  xtd::tunit::test::current_test().status_ = test::test_status::failed;
  xtd::tunit::test::current_test().user_message_ = message;
  throw assert_error(message != ""s ? message : "assertion failed!"s);
}


void assert::ignore(const std::string& ignore_message, const std::string& user_message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().message_ = ignore_message;
  xtd::tunit::test::current_test().status_ = test::test_status::ignored;
  xtd::tunit::test::current_test().user_message_ = user_message;
  throw ignore_error(user_message != ""s ? user_message : "aborted!"s);
}

void assert::succeed(const std::string& user_message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().status_ = test::test_status::succeed;
  xtd::tunit::test::current_test().user_message_ = user_message;
}
