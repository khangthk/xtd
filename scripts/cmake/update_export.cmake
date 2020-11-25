macro(xtd_update_file_export path keyword export)
  if (XTD_BUILD_SHARED_LIBRARIES)
    file(WRITE ${path} 
      "/// @file\n"
      "/// @brief Contains ${export} keyword.\n"
      "#pragma once\n"
      "\n"
      "#if defined(WIN32)\n"
      "#  if defined(${keyword})\n"
      "#    define ${export} __declspec(dllexport)\n"
      "#  else\n"
      "#    define ${export} __declspec(dllimport)\n"
      "#  endif\n"
      "#else\n"
      "#  if defined(${keyword})\n"
      "#    define ${export} __attribute__((visibility (\"default\")))\n"
      "#  else\n"
      "#    define ${export}\n"
      "#  endif\n"
      "#endif\n"
    )
  else()
    file(WRITE ${path} 
    "/// @file\n"
    "/// @brief Contains ${export} keyword.\n"
    "#pragma once\n"
    "\n"
    "#define ${export}\n"
    )
  endif()
endmacro()

xtd_update_file_export(src/xtd.core/include/xtd/core_export.h XTD_CORE_EXPORT core_export_)
xtd_update_file_export(src/xtd.drawing/include/xtd/drawing_export.h XTD_DRAWING_EXPORT drawing_export_)
xtd_update_file_export(src/xtd.forms/include/xtd/forms_export.h XTD_FORMS_EXPORT forms_export_)
xtd_update_file_export(src/xtd.tunit/include/xtd/tunit_export.h XTD_TUNIT_EXPORT tunit_export_)
xtd_update_file_export(src/xtd/include/xtd/export.h XTD_EXPORT export_)
