#pragma once

#include "delegate.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  template<typename... arguments_t>
  using action = delegate <void(arguments_t...)>;
}
