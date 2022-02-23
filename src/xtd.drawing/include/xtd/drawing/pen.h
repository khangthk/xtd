/// @file
/// @brief Contains xtd::drawing::pen class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <memory>
#include <ostream>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../drawing_export.h"
#include "drawing2d/line_cap.h"
#include "drawing2d/line_join.h"
#include "drawing2d/pen_alignment.h"
#include "drawing2d/pen_type.h"
#include "brush.h"
#include "color.h"
#include "dash_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Defines an object used to draw lines and curves. This class cannot be inherited.
    /// @code
    /// class drawing_export_ pen : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::pen
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ pen final : public xtd::object {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::drawing::pen class with the specified xtd::drawing::brush.
      /// @param brush A xtd::drawing::brush that determines the fill properties of this xtd::drawing::pen.
      /// @remarks The brush property determines how the xtd::drawing::pen draws lines. Lines are drawn as if they are filled rectangles, with the characteristics of the specified brush.
      /// @remarks The width property of the new xtd::drawing::pen  is set to 1 (the default).
      template <typename brush_t>
      explicit pen(const brush_t& brush) {
        this->brush(brush);
      }
      
      /// @brief Initializes a new instance of the xtd::drawing::pen class with the specified xtd::drawing::brush.
      /// @param brush A xtd::drawing::brush that determines the fill properties of this xtd::drawing::pen.
      /// @param width A single number that represent the pen width.
      /// @remarks The brush property determines how the xtd::drawing::pen draws lines. Lines are drawn as if they are filled rectangles, with the characteristics of the specified brush.
      /// @remarks The width property of the new xtd::drawing::pen  is set to 1 (the default).
      template<typename brush_t>
      pen(const brush_t& brush, float width) {
        this->width(width);
        this->brush(brush);
      }
    
      /// @brief Initializes a new instance of the xtd::drawing::pen class with the specified xtd::drawing::color.
      /// @param color A xtd::drawing::color structure that indicates the color of this xtd::drawing::pen.
      /// @remarks The color property is set to the color specified by the color parameter. The width property is set to 1 (the default).
      explicit pen(const xtd::drawing::color& color);
      
      /// @brief Initializes a new instance of the xtd::drawing::pen class with the specified xtd::drawing::color.
      /// @param color A xtd::drawing::color structure that indicates the color of this xtd::drawing::pen.
      /// @param width A single number that represent the pen width.
      /// @remarks The color property is set to the color specified by the color parameter. The width property is set to 1 (the default).
      pen(const xtd::drawing::color& color, float width);
      /// @}
      
      /// @cond
      pen(const xtd::drawing::pen& value);
      pen& operator=(const xtd::drawing::pen& value);
      ~pen();
      bool operator==(const xtd::drawing::pen& value) const;
      bool operator!=(const xtd::drawing::pen& value) const;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the alignment for this xtd::drawing::pen.
      /// @return A xtd::drawing::drawing2d::pen_alignment that represents the alignment for this xtd::drawing::pen.
      /// @remarks This property determines how the xtd::drawing::pen draws closed curves and polygons. The td::drawing2d::pen_alignment enumeration specifies five values; however, only two values - td::drawing2d::pen_alignment::center and td::drawing2d::pen_alignment::inset - will change the appearance of a drawn line. td::drawing2d::pen_alignment::center is the default value for this property and specifies that the width of the pen is centered on the outline of the curve or polygon. A value of td::drawing2d::pen_alignment::inset for this property specifies that the width of the pen is inside the outline of the curve or polygon. The other three values, td::drawing2d::pen_alignment::right, td::drawing2d::pen_alignment::left, and td::drawing2d::pen_alignment::outset, will result in a pen that is centered.
      xtd::drawing::drawing2d::pen_alignment alignment() const;
      
      /// @brief Sets the alignment for this xtd::drawing::pen.
      /// @param value A xtd::drawing::drawing2d::pen_alignment that represents the alignment for this xtd::drawing::pen.
      /// @remarks This property determines how the xtd::drawing::pen draws closed curves and polygons. The xtd::drawing::drawing2d::pen_alignment enumeration specifies five values; however, only two values - xtd::drawing::drawing2d::pen_alignment::center and xtd::drawing::drawing2d::pen_alignment::inset - will change the appearance of a drawn line. xtd::drawing::drawing2d::pen_alignment::center is the default value for this property and specifies that the width of the pen is centered on the outline of the curve or polygon. A value of xtd::drawing::drawing2d::pen_alignment::inset for this property specifies that the width of the pen is inside the outline of the curve or polygon. The other three values, xtd::drawing::drawing2d::pen_alignment::right, xtd::drawing::drawing2d::pen_alignment::left, and xtd::drawing::drawing2d::pen_alignment::outset, will result in a pen that is centered.
      xtd::drawing::pen& alignment(xtd::drawing::drawing2d::pen_alignment value);
      
      /// @brief Gets the xtd::drawing::brush that determines attributes of this xtd::drawing::pen.
      /// @return A Brush that determines attributes of this xtd::drawing::pen.
      /// @remarks Assigning this property causes the pen to draw filled lines and curves. It overrides thextd::drawing::pen::color property of the xtd::drawing::pen.
      const std::unique_ptr<xtd::drawing::brush>& brush() const;
      /// @brief Sets the xtd::drawing::brush that determines attributes of this xtd::drawing::pen.
      /// @param value A xtd::drawing::brush that determines attributes of this xtd::drawing::pen.
      /// @remarks Assigning this property causes the pen to draw filled lines and curves. It overrides thextd::drawing::pen::color property of the xtd::drawing::pen.
      template<typename brush_t>
      xtd::drawing::pen& brush(const brush_t& value) {
        data_->brush = value.template memberwise_clone<brush_t>();
        data_->color = xtd::drawing::color::empty;
        recreate_handle();
        return *this;
      }
      
      /// @brief Gets the color of this xtd::drawing::pen.
      /// @return A xtd::drawing::color structure that represents the color of this xtd::drawing::pen.
      const xtd::drawing::color& color() const;
      /// @brief Sets the color of this xtd::drawing::pen.
      /// @param value A xtd::drawing::color structure that represents the color of this xtd::drawing::pen.
      /// @return This current instance.
      xtd::drawing::pen& color(const xtd::drawing::color& value);
      
      /// @brief Gets an array of custom dashes and spaces.
      /// @return An array of real numbers that specifies the lengths of alternating dashes and spaces in dashed lines.
      /// @remarks Assigning a value other than empty to this property will set the xtd::drawing::pen::dash_style property for this xtd::drawing::pen to xtd::drawing:dash_style::custom.
      /// @remarks The elements in the dash_pattern array set the length of each dash and space in the dash pattern. The first element sets the length of a dash, the second element sets the length of a space, the third element sets the length of a dash, and so on. Consequently, each element should be a non-zero positive number.
      /// @remarks The length of each dash and space in the dash pattern is the product of the element value in the array and the width of the xtd::drawing::pen.
      std::vector<float> dash_pattern() const;
      /// @brief Sets an array of custom dashes and spaces.
      /// @param value An array of real numbers that specifies the lengths of alternating dashes and spaces in dashed lines.
      /// @remarks Assigning a value other than empty to this property will set the xtd::drawing::pen::dash_style property for this xtd::drawing::pen to xtd::drawing:dash_style::custom.
      /// @remarks The elements in the dash_pattern array set the length of each dash and space in the dash pattern. The first element sets the length of a dash, the second element sets the length of a space, the third element sets the length of a dash, and so on. Consequently, each element should be a non-zero positive number.
      /// @remarks The length of each dash and space in the dash pattern is the product of the element value in the array and the width of the xtd::drawing::pen.
      xtd::drawing::pen& dash_pattern(const std::vector<float>& value);
      
      /// @brief Gets the style used for dashed lines drawn with this xtd::drawing::pen.
      /// @return A xtd::drawing::dash_style that represents the style used for dashed lines drawn with this xtd::drawing::pen.
      /// @remarks A value of xtd::drawing::dash_style::custom for this property specifies that a custom pattern of dashes and spaces, defined by the xtd::drawing::pendash_pattern property, makes up lines drawn with this xtd::drawing::pen. If the value of this property is xtd::drawing::dash_style::custom and the value of the xtd::drawing::pen::dash_pattern property is empty, the pen draws solid lines.
      xtd::drawing::dash_style dash_style() const;
      /// @brief Sets the style used for dashed lines drawn with this xtd::drawing::pen.
      /// @param value A xtd::drawing::dash_style that represents the style used for dashed lines drawn with this xtd::drawing::pen.
      /// @return This current instance.
      /// @remarks A value of xtd::drawing::dash_style::custom for this property specifies that a custom pattern of dashes and spaces, defined by the xtd::drawing::pendash_pattern property, makes up lines drawn with this xtd::drawing::pen. If the value of this property is xtd::drawing::dash_style::custom and the value of the xtd::drawing::pen::dash_pattern property is empty, the pen draws solid lines.
      xtd::drawing::pen& dash_style(drawing::dash_style value);
      
      /// @brief Gets the cap style used at the end of lines drawn with this xtd::drawing::pen.
      /// @return One of the xtd::drawing::drawing2d::line_cap values that represents the cap style used at the end of lines drawn with this xtd::drawing::pen.
      xtd::drawing::drawing2d::line_cap end_cap() const noexcept;
      /// @brief Sets the cap style used at the end of lines drawn with this xtd::drawing::pen.
      /// @param value One of the xtd::drawing::drawing2d::line_cap values that represents the cap style used at the end of lines drawn with this xtd::drawing::pen.
      /// @return This current instance.
      xtd::drawing::pen& end_cap(xtd::drawing::drawing2d::line_cap value);
      
      /// @brief Gets the handle of the pen.
      /// @return An intptr_t that contains the handle of the pen.
      intptr_t handle() const;
      
      /// @brief Gets the join style for the ends of two consecutive lines drawn with this xtd::drawing::pen.
      /// @return A xtd::drawing::drawing2d::line_join that represents the join style for the ends of two consecutive lines drawn with this xtd::drawing::pen.
      /// @remarks A line join is the common area that is formed by two lines whose ends meet or overlap. There are three line join styles: miter, bevel, and round. When you specify a line join style for a xtd::drawing::pen object, that join style will be applied to all the connected lines in any xtd::drawing::drawing2d::graphics_path object drawn using that pen. The following illustration shows the results of the beveled line join example.
      /// @image html line_join_bevel.png
      xtd::drawing::drawing2d::line_join line_join() const noexcept;
      /// @brief Sets the join style for the ends of two consecutive lines drawn with this xtd::drawing::pen.
      /// @param value A xtd::drawing::drawing2d::line_join that represents the join style for the ends of two consecutive lines drawn with this xtd::drawing::pen.
      /// @return This current instance.
      /// @remarks A line join is the common area that is formed by two lines whose ends meet or overlap. There are three line join styles: miter, bevel, and round. When you specify a line join style for a xtd::drawing::pen object, that join style will be applied to all the connected lines in any xtd::drawing::drawing2d::graphics_path object drawn using that pen. The following illustration shows the results of the beveled line join example.
      /// @image html line_join_bevel.png
      xtd::drawing::pen& line_join(xtd::drawing::drawing2d::line_join value);

      /// @brief Gets the limit of the thickness of the join on a mitered corner.
      /// @return The limit of the thickness of the join on a mitered corner.
      /// @remarks The miter length is the distance from the intersection of the line walls on the inside of the join to the intersection of the line walls outside of the join. The miter length can be large when the angle between two lines is small. The miter limit is the maximum allowed ratio of miter length to stroke width. The default value is 10.0f.
      /// @remarks If the miter length of the join of the intersection exceeds the limit of the join, then the join will be beveled to keep it within the limit of the join of the intersection.
      float miter_limit() const noexcept;
      /// @brief Sets the limit of the thickness of the join on a mitered corner.
      /// @param value The limit of the thickness of the join on a mitered corner.
      /// @return This current instance.
      /// @remarks The miter length is the distance from the intersection of the line walls on the inside of the join to the intersection of the line walls outside of the join. The miter length can be large when the angle between two lines is small. The miter limit is the maximum allowed ratio of miter length to stroke width. The default value is 10.0f.
      /// @remarks If the miter length of the join of the intersection exceeds the limit of the join, then the join will be beveled to keep it within the limit of the join of the intersection.
      xtd::drawing::pen& miter_limit(float value);

      /// @brief Gets the cap style used at the beginning of lines drawn with this xtd::drawing::pen.
      /// @return One of the xtd::drawing::drawing2d::line_cap values that represents the cap style used at the beginning of lines drawn with this xtd::drawing::pen.
      xtd::drawing::drawing2d::line_cap start_cap() const noexcept;
      /// @brief Sets the cap style used at the beginning of lines drawn with this xtd::drawing::pen.
      /// @param value One of the xtd::drawing::drawing2d::line_cap values that represents the cap style used at the beginning of lines drawn with this xtd::drawing::pen.
      /// @return This current instance.
      xtd::drawing::pen& start_cap(xtd::drawing::drawing2d::line_cap value);

      /// @brief Gets the style of lines drawn with this xtd::drawing::pen.
      /// @return A xtd::drawing::drawing2d::pen_type enumeration that specifies the style of lines drawn with this xtd::drawing::pen.
      /// @remarks A Pen can draw solid lines, filled lines, or textured lines, depending on the style specified by a member of the PenType enumeration.
      xtd::drawing::drawing2d::pen_type type() const;
      
      /// @brief Gets the width of this xtd::drawing::pen, in units of the xtd::drawing::graphics object used for drawing.
      /// @return The width of this xtd::drawing::pen.
      /// @remarks You can access the unit of measure of the xtd::drawing::graphics object using its xtd::drawing::graphics::page_unit property. The unit of measure is typically pixels. A Width of 0 will result in the xtd::drawing::pen drawing as if the xtd::drawing::pen::width were 1.
      float width() const {return data_->width;}
      /// @brief Sets the width of this xtd::drawing::pen, in units of the xtd::drawing::graphics object used for drawing.
      /// @param value The width of this xtd::drawing::pen.
      /// @return This current instance.
      /// @remarks You can access the unit of measure of the xtd::drawing::graphics object using its xtd::drawing::graphics::page_unit property. The unit of measure is typically pixels. A Width of 0 will result in the xtd::drawing::pen drawing as if the xtd::drawing::pen::width were 1.
      xtd::drawing::pen& width(float value);
      /// @}
 
      /// @cond
      xtd::drawing::pen& dash_pattern(const std::initializer_list<float>& value);
      /// @endcond

      /// @name Methods
      
      /// @{
      xtd::ustring to_string() const noexcept override;
      /// @}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::pen& pen) noexcept {return os << pen.to_string();}
      /// @endcond
      
    private:
      pen();
      void recreate_handle();
      struct data {
        intptr_t handle_ = 0;
        xtd::drawing::drawing2d::pen_alignment alignment = xtd::drawing::drawing2d::pen_alignment::center;
        xtd::drawing::color color;
        std::unique_ptr<xtd::drawing::brush> brush;
        float dash_offset = 0.0f;
        std::vector<float> dash_pattern;
        xtd::drawing::dash_style dash_style = xtd::drawing::dash_style::solid;
        xtd::drawing::drawing2d::line_cap end_cap = xtd::drawing::drawing2d::line_cap::flat;
        xtd::drawing::drawing2d::line_join line_join = xtd::drawing::drawing2d::line_join::miter;
        float miter_limit = 10.0f;
        xtd::drawing::drawing2d::line_cap start_cap = xtd::drawing::drawing2d::line_cap::flat;
        xtd::drawing::drawing2d::pen_type type = xtd::drawing::drawing2d::pen_type::solid_color;
        float width = 1.0f;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
