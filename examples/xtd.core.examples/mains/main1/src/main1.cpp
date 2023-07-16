#include <xtd/console>
#include <xtd/environment>
#include <xtd/startup>

using namespace xtd;

namespace main1_example {
  class program {
  public:
    static void main() {
      // Write arguments to the console output
      for (auto arg : environment::get_command_line_args())
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

startup_(main1_example::program);
// startup_(main1_example::program); is same as :
//
// auto main(int argc, char* argv[])->int {
//   main1_example::program::main();
//   return environment::exit_code();
// }


// This code produces the following output if one two "three four" five are entered on command line:
//
// /!---OMITTED---!/main1
// one
// two
// three four
// five
