#pragma once
#include <xtd/delegate.hpp>
#include <xtd/event_args.hpp>
#include <cstdint>

namespace xtd {
  namespace forms {
    namespace native {
      class timer {
      public:
        static intptr_t create(int interval, const delegate<void(const event_args&)>& tick);
        static void destroy(intptr_t handle);
      };
    }
  }
}
