#include <xtd/threading/manual_reset_event>
#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

namespace manual_reset_event_example {
  class program {
  public:
    static void main() {
      console::write_line("\nStart 3 named threads that block on a ManualresetEvent:\n");
      
      for(auto i = 0; i <= 2; ++i) {
        auto t = thread {thread_start {thread_proc}};
        t.name(ustring::format("Thread_{}", i));
        t.start();
      }
      
      thread::sleep(500);
      console::write_line("\nWhen all three threads have started, press Enter to call set()"
                          "\nto release all the threads.\n");
      console::read_line();
      
      mre.set();
      
      thread::sleep(500);
      console::write_line("\nWhen a ManualresetEvent is signaled, threads that call WaitOne()"
                          "\ndo not block. Press Enter to show this.\n");
      console::read_line();
      
      for(auto i = 3; i <= 4; ++i) {
        auto t = thread {thread_start {thread_proc}};
        t.name(ustring::format("Thread_{}", i));
        t.start();
      }
      
      thread::sleep(500);
      console::write_line("\nPress Enter to call reset(), so that threads once again block"
                          "\nwhen they call WaitOne().\n");
      console::read_line();
      
      mre.reset();
      
      // Start a thread that waits on the ManualresetEvent.
      auto t5 = thread {thread_start {thread_proc}};
      t5.name("Thread_5");
      t5.start();

      thread::sleep(500);
      console::write_line("\nPress Enter to call set() and conclude the demo.");
      console::read_line();
      
      mre.set();
      
      // If you run this example in Visual Studio, uncomment the following line:
      //console::read_line();
    }
    
  private:
    // mre is used to block and release threads manually. It is
    // created in the unsignaled state.
    inline static manual_reset_event mre {false};
    
    static void thread_proc() {
      ustring name = thread::current_thread().name();
      
      console::write_line(name + " starts and calls mre.WaitOne()");
      
      mre.wait_one();
      
      console::write_line(name + " ends.");
    }
  };
}

startup_(manual_reset_event_example::program);

// This example produces output similar to the following:
//
// Start 3 named threads that block on a ManualresetEvent:
//
// Thread_0 starts and calls mre.WaitOne()
// Thread_2 starts and calls mre.WaitOne()
// Thread_1 starts and calls mre.WaitOne()
//
// When all three threads have started, press Enter to call set()
// to release all the threads.
//
//
// Thread_2 ends.
// Thread_0 ends.
// Thread_1 ends.
//
// When a ManualresetEvent is signaled, threads that call WaitOne()
// do not block. Press Enter to show this.
//
//
// Thread_3 starts and calls mre.WaitOne()
// Thread_4 starts and calls mre.WaitOne()
// Thread_3 ends.
// Thread_4 ends.
//
// Press Enter to call reset(), so that threads once again block
// when they call WaitOne().
//
//
// Thread_5 starts and calls mre.WaitOne()
//
// Press Enter to call set() and conclude the demo.
//
// Thread_5 ends.