/// @file
/// @brief Contains xtd::collections::generic::hasher struct.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "../../internal/__hasher.h"
#undef __XTD_CORE_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Implements a function object for hashing data.
      /// ```cpp
      /// class hasher
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/hasher
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The unordered associative containers xtd::collections::generic::set, xtd::collections::generic::multi_set, xtd::collections::generic::dictionary, xtd::collections::generic::multi_dictionary use specializations of the template xtd::collections::generic::hasher as the default hash function.
      template<typename key_t>
      struct hasher {
        /// @brief Serves as a hash function for a specified key with a particular type (type_t).
        /// @param key The key to hash.
        /// @return A hash code for the spesified key.
        /// @remarks If key_t inherits from xtd::object, the xtd::object::get_hash_code method will be used; otherwise, the [std::hash](https://en.cppreference.com/w/cpp/utility/hash) object function will be used.
        size_t operator()(const key_t& key) const {return __polymorphic_hasher__<key_t, typename std::is_polymorphic<key_t>::type> {}(key);}
      };
    }
  }
}