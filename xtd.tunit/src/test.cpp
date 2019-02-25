#include "../include/xtd/test.hpp"
#include "../include/xtd/unit_test.hpp"
#include <exception>

using namespace xtd::tunit;

test* test::current_test_ = nullptr;

void test::run(const unit_test& unit_test, const xtd::tunit::test_class& test_class) {
  this->start_time_point = std::chrono::high_resolution_clock::now();
  current_test_ = this;
  
  if (settings::default_settings().is_valid_test_name(test_class.name(), this->name()) && (!this->ignore_ || settings::default_settings().also_run_ignored_tests())) {
    unit_test.event_listener_->on_test_initialize_start(xtd::tunit::test_event_args(*this, test_class, unit_test));
    if (test_class.test_initialize().method() != nullptr)
      test_class.test_initialize().method()();
    unit_test.event_listener_->on_test_initialize_end(xtd::tunit::test_event_args(*this, test_class, unit_test));
    
    unit_test.event_listener_->on_test_start(xtd::tunit::test_event_args(*this, test_class, unit_test));
    try {
      this->method()();
      if (this->passed_)
        unit_test.event_listener_->on_test_succeed(xtd::tunit::test_event_args(*this, test_class, unit_test));
      else {
        xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
        unit_test.event_listener_->on_test_failed(xtd::tunit::test_event_args(*this, test_class, unit_test));
      }
    } catch(const xtd::tunit::assert_error&) {
      xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
      unit_test.event_listener_->on_test_failed(xtd::tunit::test_event_args(*this, test_class, unit_test));
    } catch(const std::exception&) {
      xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
      unit_test.event_listener_->on_test_failed(xtd::tunit::test_event_args(*this, test_class, unit_test));
    } catch(...) {
      xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
      unit_test.event_listener_->on_test_failed(xtd::tunit::test_event_args(*this, test_class, unit_test));
    }
    
    unit_test.event_listener_->on_test_cleanup_start(xtd::tunit::test_event_args(*this, test_class, unit_test));
    if (test_class.test_cleanup().method() != nullptr)
      test_class.test_cleanup().method()();
    unit_test.event_listener_->on_test_cleanup_end(xtd::tunit::test_event_args(*this, test_class, unit_test));
    
    unit_test.event_listener_->on_test_end(xtd::tunit::test_event_args(*this, test_class, unit_test));
  }
  
  this->end_time_point = std::chrono::high_resolution_clock::now();
}

