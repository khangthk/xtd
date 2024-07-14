#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::collections::specialized;

namespace main_example {
  class program {
  public:
    static auto main(const string_collection& args) {
      auto number = 0;
      if (args.size() != 1 || try_parse(args[0], number) == false || number < 0 || number > 20) {
        console::write_line("Please enter an integer argument betwween 0 and 20.");
        console::write_line("Usage: factorial <integer>");
        return -1;
      }
      
      console::write_line("The factorial of {} is {}", number, [&] {
        auto result = 1l;
        for (auto i = 1; i <= number; ++i)
          result *= i;
        return result;
      }());
      return 0;
    }
  };
}

startup_(main_example::program::main);

// This code produces the following output if 3 is entered on command line:
//
// The factorial of 3 is 6.
