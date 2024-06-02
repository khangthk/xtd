/// @file
/// @brief Contains xtd::configuration::file_settings class
/// .
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.h"
#include "../collections/specialized/string_map.h"
#include "../collections/specialized/string_vector.h"
#include "../io/directory.h"
#include "../io/file.h"
#include "../io/path.h"
#include "../iequatable.h"
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains the types that provide the programming model for handling configuration data.
  namespace configuration {
    /// @brief Represents an object for storing and retrieving configuration information using text files in [INI format](https://en.wikipedia.org/wiki/INI_file).
    /// @par Header
    /// @code #include <xtd/configuration/file_settings> @endcode
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core configuration
    /// @remarks An [INI file](https://en.wikipedia.org/wiki/INI_file) is a configuration file that consists of a text-based content with a structure and syntax comprising key–value pairs for properties, and sections that organize the properties.
    class core_export_ file_settings : public object, public iequatable<file_settings> {
    public:
      /// @name Public Aliass
      
      /// @{
      /// @brief Represents a std::map with the key and the value strongly typed to be strings.
      using string_map = xtd::collections::specialized::string_map;

      /// @brief Represents a collection of strings.
      using string_vector = xtd::collections::specialized::string_vector;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize an xtd::configuration::file_settings without loading a file.
      /// @remarks The xtd::configuration::file_settings::save method has no effect.
      /// @remarks This is equivalent to using the xtd::configuration::file_settings constructor with an empty string as the file path.
      file_settings() noexcept = default;
      /// @brief Initialize an xtd::configuration::file_settings with file path to load.
      /// @param file_path the file path to load.
      /// @remarks When the xtd::configuration::file_settings file is destroyed, the backup is not automatically called up. The backup must be made manually.
      /// @remarks If the file path is empty, this is equivalent to using the xtd::configuration::file_settings constructor with no parameters.
      explicit file_settings(const xtd::ustring& file_path);
      /// @}
      
      /// @cond
      file_settings(file_settings&&) noexcept = default;
      file_settings(const file_settings&) noexcept = default;
      file_settings& operator =(const file_settings&) noexcept = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the file path of the current instance.
      /// @return The file path of the current instance.
      /// @remarks If no file the property can be return xtd::ustring::empty_string.
      /// @warning Don't manipulate the file yourself, otherwise the expected result may be undefined.
      const xtd::ustring& file_path() const noexcept;

      /// @brief Gets all key-values from global section.
      /// @return The key-values map.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::key_values (const xtd::ustring& section) with xtd::ustring::empty_string paramreter.
      string_map key_values() const noexcept;
      /// @brief Gets all key-values from a specified section.
      /// @param section The section to get key-values.
      /// @return The key-values map from the specified section.
      /// @remarks Use xtd::ustring::empty_string paramreter to get key-values of the global section.
      string_map key_values(const xtd::ustring& section) const noexcept;
      
      /// @brief Gets all keys from global section.
      /// @return The keys vector.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::keys (const xtd::ustring& section) with xtd::ustring::empty_string paramreter.
      string_vector keys() const noexcept;
      /// @brief Gets all keys from a specified section.
      /// @param section The section to get keys.
      /// @return The keys vector from the specified section.
      /// @remarks Use xtd::ustring::empty_string paramreter to get keys of the global section.
      string_vector keys(const xtd::ustring& section) const noexcept;

      /// @brief Gets all sections.
      /// @return The sections vector.
      string_vector sections() const noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Indicates whether the current object is equal to another object of the same type.
      /// @param obj An object to compare with this object.
      /// @return true if the current object is equal to the other parameter; otherwise, false.
      bool equals(const file_settings& obj) const noexcept override;
      
      /// @brief Loads settings from specified file.
      /// @param file_path The file path to load settings.
      void load(const xtd::ustring& file_path);
      
      /// @brief Reads value associate to the specified key.
      /// @param key The key to read the value.
      /// @param default_value The value to return if `key` does not exist.
      /// @return The value associated with `key`, or `default_value` if name is not found.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::read (const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& default_value) with xtd::ustring::empty_string paramreter as section parameter.
      xtd::ustring read(const xtd::ustring& key, const xtd::ustring& default_value) noexcept;
      /// @brief Reads value associate to the specified key.
      /// @param key The key to read the value.
      /// @param default_value The value to return if `key` does not exist.
      /// @return The value associated with `key`, or `default_value` if name is not found.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::read (const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& default_value) with xtd::ustring::empty_string paramreter as section parameter.
      template<typename type_t>
      type_t read(const xtd::ustring& key, const type_t& default_value) noexcept {
        return xtd::parse<type_t>(read_string(xtd::ustring::empty_string, key, xtd::ustring::format("{}", default_value)));
      }
      /// @brief Reads value associate to the specified key.
      /// @param key The key to read the value.
      /// @param default_value The value to return if `key` does not exist.
      /// @return The value associated with `key`, or `default_value` if name is not found.
      /// @remarks Use xtd::ustring::empty_string for section paramreter to read keys of the global section.
      xtd::ustring read(const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& default_value) noexcept;
      /// @brief Reads value associate to the specified key.
      /// @param key The key to read the value.
      /// @param default_value The value to return if `key` does not exist.
      /// @return The value associated with `key`, or `default_value` if name is not found.
      /// @remarks Use xtd::ustring::empty_string for section paramreter to read keys of the global section.
      template<typename type_t>
      type_t read(const xtd::ustring& section, const xtd::ustring& key, const type_t& default_value) noexcept {
        return xtd::parse<type_t>(read_string(section, key, xtd::ustring::format("{}", default_value)));
      }

      void remove(const xtd::ustring& key) noexcept;
      
      void remove(const xtd::ustring& section, const xtd::ustring& key) noexcept;
      
      void remove_all_keys() noexcept;
      
      void remove_all_keys(const xtd::ustring& section) noexcept;
      
      void reset();
      
      void save();
      
      void save_as(const xtd::ustring& file_path);

      /// @brief Sets the current settings with parsing the xtd::ustring in [INI format](https://en.wikipedia.org/wiki/INI_file).
      /// @param text A text to set the current setting.
      /// @par Notes to inheritors
      /// To create your own file_settings with another format, you just need to override the xtd::confguration::file_settings::from_string and xtd::confguration::file_settings::to_string methods.
      virtual void from_string(const xtd::ustring& text);
      
      /// @brief Returns a xtd::ustring that represents the current setting in [INI format](https://en.wikipedia.org/wiki/INI_file).
      /// @return A string that represents the current setting.
      /// @par Notes to inheritors
      /// To create your own file_settings with another format, you just need to override the xtd::confguration::file_settings::from_string and xtd::confguration::file_settings::to_string methods.
      xtd::ustring to_string() const noexcept override;
      
      void write(const xtd::ustring& key, const xtd::ustring& value) noexcept;

      template<typename type_t>
      void write(const xtd::ustring& key, type_t&& value) {
        write_string(xtd::ustring::empty_string, key, xtd::ustring::format("{}", value));
      }

      void write(const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& value) noexcept;

      template<typename type_t>
      void write(const xtd::ustring& section, const xtd::ustring& key, type_t&& value) {
        write_string(section, key, xtd::ustring::format("{}", value));
      }
      /// @}
      
      /// @name Public Operators
      
      /// @{
      const string_map& operator [](const xtd::ustring& section) const noexcept;
      
      string_map& operator [](const xtd::ustring& section) noexcept;
      /// @}
      
    private:
      xtd::ustring read_string(const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& default_value) noexcept;
      void write_string(const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& value) noexcept;

      std::map<xtd::ustring, string_map> section_key_values_;
      xtd::ustring file_path_;
    };
  }
}
