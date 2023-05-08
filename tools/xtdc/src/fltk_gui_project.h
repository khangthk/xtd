#pragma once
#include "base_project.h"

namespace xtdc_command {
  class fltk_gui_project : public base_project {
  public:
    explicit fltk_gui_project(const xtd::ustring& path) : base_project(path) {}
    
    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_solution_cmakelists_txt(name);
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_include(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_main(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void generate(const xtd::ustring& name) const {
      generate_cmakelists_txt(name, current_path());
    }

  private:
    void create_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/Window1.h",
        "  src/Window1.cpp",
        "  src/Program.cpp",
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(FLTK REQUIRED)",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})",
        "target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIR})",
        "if (APPLE)",
        "  # Workaround: fltk.framework does not exist, so we have to replace it by libfltk.dylib",
        "  string(REPLACE \"libfltk_images\" \"libfltk\" FLTK_LIBRARY_NAME \"${FLTK_IMAGES_LIBRARY_RELEASE}\")",
        "  string(REPLACE \"/usr/local/fltk.framework\" \"${FLTK_LIBRARY_NAME}\" FLTK_LIBRARIES \"${FLTK_LIBRARIES}\")",
        "  endif()",
        "target_link_libraries(${PROJECT_NAME} ${FLTK_LIBRARIES})",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_include(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains Window1 class.",
        "#pragma once",
        "#include <FL/Fl_Window.H>",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represent the main window",
        "  class Window1 : public Fl_Window {",
        "  public:",
        "    /// @brief Initializes a new instance of the Window1 class.",
        "    Window1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Window1.h"), lines);
    }
    
    void create_source(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"Window1.h\"",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "Window1::Window1() : Fl_Window(100, 100, 800, 450, \"Window1\") {",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Window1.cpp"), lines);
    }
    
    void create_main(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"Window1.h\"",
        "#include <FL/Fl.H>",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "// The main entry point for the application.",
        "auto main(int argc, char* argv[])->int {",
        "  Window1 window;",
        "  window.show(argc, argv);",
        "  return Fl::run();",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Program.cpp"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
      };
      auto [headers, sources] = get_cpp_sources(path, path);
      for (auto file : headers)
        lines.push_back(xtd::ustring::format("  {}", file));
      for (auto file : sources)
        lines.push_back(xtd::ustring::format("  {}", file));
      lines.push_back(")");
      lines.push_back("source_group(src FILES ${SOURCES})");
      lines.push_back("find_package(FLTK REQUIRED)");
      lines.push_back("");
      lines.push_back("# Options");
      lines.push_back("set(CMAKE_CXX_STANDARD 17)");
      lines.push_back("set(CMAKE_CXX_STANDARD_REQUIRED ON)");
      lines.push_back("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.push_back("");
      lines.push_back("# Application properties");
      lines.push_back("add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})");
      lines.push_back("target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIR})");
      lines.push_back("if (APPLE)");
      lines.push_back("  # Workaround: fltk.framework does not exist, so we have to replace it by libfltk.dylib");
      lines.push_back("  string(REPLACE \"libfltk_images\" \"libfltk\" FLTK_LIBRARY_NAME \"${FLTK_IMAGES_LIBRARY_RELEASE}\")");
      lines.push_back("  string(REPLACE \"/usr/local/fltk.framework\" \"${FLTK_LIBRARY_NAME}\" FLTK_LIBRARIES \"${FLTK_LIBRARIES}\")");
      lines.push_back("  endif()");
      lines.push_back("target_link_libraries(${PROJECT_NAME} ${FLTK_LIBRARIES})");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
