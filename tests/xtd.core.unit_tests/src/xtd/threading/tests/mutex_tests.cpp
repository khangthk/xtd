#include <xtd/threading/mutex.h>
#include <xtd/xtd.tunit>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(mutex_tests) {
  public:
    static void class_initialize_(class_initialize) {
      auto m = mutex {"xtd_mutex_test"};
      auto m2 = mutex {"xtd_mutex_test_2"};
    }

    void test_method_(constructor) {
      auto m1 = mutex {};
      auto m2 = mutex {};
      assert::are_not_equal(mutex::invalid_handle, m1.handle(), csf_);
      assert::are_not_equal(mutex::invalid_handle, m2.handle(), csf_);
      assert::are_not_equal(m2, m1, csf_);
    }
    
    void test_method_(copy_constructor) {
      auto m1 = mutex {};
      auto m2 = m1;
      assert::are_equal(m2, m1, csf_);
    }
    
    void test_method_(copy_operator) {
      auto m1 = mutex {};
      auto m2 = mutex {};
      m2 = m1;
      assert::are_equal(m2, m1, csf_);
    }

    void test_method_(constructor_with_initially_owned_to_false) {
      auto m = mutex {false};
      assert::are_not_equal(mutex::invalid_handle, m.handle(), csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        assert::is_true(m.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(constructor_with_initially_owned_to_true) {
      auto m = mutex {true};
      assert::are_not_equal(mutex::invalid_handle, m.handle(), csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        assert::is_false(m.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(constructor_with_initially_owned_to_false_and_name) {
      auto m = mutex {false, "xtd_mutex_test"};
      assert::are_not_equal(mutex::invalid_handle, m.handle(), csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        assert::is_true(m.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(constructor_with_initially_owned_to_true_and_name) {
      auto m = mutex {true, "xtd_mutex_test"};
      assert::are_not_equal(mutex::invalid_handle, m.handle(), csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        assert::is_false(m.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(copy_constructor_with_initially_owned_to_false_and_name) {
      auto m1 = mutex {false, "xtd_mutex_test"};
      auto m2 = m1;
      assert::are_equal(m2.handle(), m1.handle(), csf_);
    }

    void test_method_(create_two_mutex_with_same_name) {
      auto m1 = mutex {true, "xtd_mutex_test"};
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        auto m2 = mutex {false, "xtd_mutex_test"};
        assert::is_false(m2.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(create_two_mutex_with_same_name_and_created_new) {
      auto created_new = false;
      auto m1 = mutex {true, "xtd_mutex_test", created_new};
      assert::is_true(created_new, csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        auto m2 = mutex {false, "xtd_mutex_test", created_new};
        assert::is_false(created_new, csf_);
        assert::is_false(m2.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(create_two_mutex_with_different_name_and_created_new) {
      auto created_new = false;
      auto m1 = mutex {true, "xtd_mutex_test", created_new};
      assert::is_true(created_new, csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        auto m2 = mutex {false, "xtd_mutex_test_2", created_new};
        assert::is_true(created_new, csf_);
        assert::is_true(m2.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(unnamed_mutex_and_close) {
      auto m = mutex {};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle(), csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        auto m2 = mutex {};
        m.close();
        assert::are_equal(wait_handle::invalid_handle, m.handle(), csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
      assert::are_equal(wait_handle::invalid_handle, m.handle(), csf_);
    }

    void test_method_(named_mutex_and_close) {
      auto created_new = false;
      auto m = mutex {false, "xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle(), csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        m.close();
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
      assert::are_equal(wait_handle::invalid_handle, m.handle(), csf_);
    }

    void test_method_(open_existing_with_same_name) {
      auto created_new = false;
      auto m = mutex {false, "xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle(), csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        auto m2 = mutex::open_existing("xtd_mutex_test");
        assert::are_not_equal(wait_handle::invalid_handle, m2.handle(), csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(open_existing_with_different_name) {
      auto created_new = false;
      auto m = mutex {false, "xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle(), csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        assert::throws<io::io_exception>([] {auto m2 = mutex::open_existing("xtd_mutex_test_2");}, csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(open_existing_with_empty_name) {
      auto created_new = false;
      auto m = mutex {false, "xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle(), csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        assert::throws<argument_exception>([] {auto m2 = mutex::open_existing("");}, csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(try_open_existing_with_same_name) {
      auto created_new = false;
      auto m = mutex {false, "xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle(), csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        auto m2 = mutex {};
        auto result = mutex::try_open_existing("xtd_mutex_test", m2);
        assert::is_true(result, csf_);
        assert::are_not_equal(wait_handle::invalid_handle, m2.handle(), csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(try_open_existing_with_different_name) {
      auto created_new = false;
      auto m = mutex {false, "xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle(), csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        auto m2 = mutex {};
        auto result = mutex::try_open_existing("xtd_mutex_test_2", m2);
        assert::is_false(result, csf_);
        assert::are_equal(wait_handle::invalid_handle, m2.handle(), csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(try_open_existing_with_empty_name) {
      auto created_new = false;
      auto m = mutex {false, "xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle(), csf_);
      auto thread_ran = false;
      auto thread = std::thread {[&] {
        auto m2 = mutex {};
        auto result = mutex::try_open_existing("", m2);
        assert::is_false(result, csf_);
        assert::are_equal(wait_handle::invalid_handle, m2.handle(), csf_);
        thread_ran = true;
      }};
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(wait_one) {
      auto m = mutex {};
      assert::is_true(m.wait_one(), csf_);
    }

    void test_method_(wait_one_and_release_mutex) {
      auto m = mutex {};
      assert::is_true(m.wait_one(), csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
    }

    void test_method_(wait_one_and_release_mutex_and_release_mutex) {
      auto m = mutex {};
      assert::is_true(m.wait_one(), csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
    }
     
    void test_method_(wait_one_and_wait_one_and_release_mutex) {
      auto m = mutex {false};
      assert::is_true(m.wait_one(0), csf_);
      assert::is_true(m.wait_one(0), csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
    }

    void test_method_(close_and_wait_one) {
      auto m = mutex {};
      m.close();
      assert::throws<object_closed_exception>([&] {m.wait_one();}, csf_);
    }

    void test_method_(close_and_release_mutex) {
      auto m = mutex {};
      m.close();
      assert::are_equal(mutex::invalid_handle, m.handle(), csf_);
      assert::throws<object_closed_exception>([&] {m.release_mutex();}, csf_);
    }
    
    void test_method_(signal_and_wait) {
      auto m1 = mutex {};
      auto m2 = mutex {};
      m1.wait_one();
      mutex::signal_and_wait(m1, m2);
    }
    
    void test_method_(wait_all) {
      auto m1 = mutex {};
      auto m2 = mutex {};
      auto m3 = mutex {};
      assert::is_true(mutex::wait_all({m1, m2, m3}), csf_);
    }
    
    void test_method_(wait_any) {
      auto m1 = mutex {};
      auto m2 = mutex {};
      auto m3 = mutex {};
      assert::are_equal(0ul, mutex::wait_any({m1, m2, m3}), csf_);
    }
  };
}
