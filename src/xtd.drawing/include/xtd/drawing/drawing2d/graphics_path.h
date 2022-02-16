/// @file
/// @brief Contains xtd::drawing::graphics_path class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <memory>
#include <ostream>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../../drawing_export.h"
#include "fill_mode.h"
#include "../rectangle.h"
#include "../rectangle_f.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::.drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Defines an object used to draw lines and curves. This class cannot be inherited.
      /// @code
      /// class drawing_export_ graphics_path final : public object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::drawing::drawing2d::graphics_path
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing drawing
      class drawing_export_ graphics_path final : public object {
      public:
        /// @name Constructors
        
        /// @brief Initializes a new instance of the xtd::drawing::drawing2d::graphics_path class with a xtd::drawing::drawing2d::graphics_path::fill_mode value of xtd::drawing::drawing2d::fill_mode::alternate.
        graphics_path();
        /// @brief Initializes a new instance of the xtd::drawing::drawing2d::graphics_path class with the specified xtd::drawing::drawing2d::fil_mode enumeration.
        /// @param mode The xtd::drawing::drawing2d::fill_mode enumeration that determines how the interior of this xtd::drawing::drawing2d::graphics_path is filled.
        explicit graphics_path(xtd::drawing::drawing2d::fill_mode mode);
        /// @}
        
        /// @cond
        graphics_path(const xtd::drawing::drawing2d::graphics_path& value);
        graphics_path& operator=(const xtd::drawing::drawing2d::graphics_path& value);
        ~graphics_path();
        bool operator==(const xtd::drawing::drawing2d::graphics_path& value) const;
        bool operator!=(const xtd::drawing::drawing2d::graphics_path& value) const;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the handle of the graphics path.
        /// @return An intptr_t that contains the handle of the graphics path.
        intptr_t handle() const noexcept;
        
        
        /// @brief Gets a xtd::drawing::drawing2d::fill_mode enumeration that determines how the interiors of shapes in this xtd::drawing::drawing2d::graphics_path are filled.
        /// @return A xtd::drawing::drawing2d::fill_mode enumeration that specifies how the interiors of shapes in this xtd::drawing::drawing2d::graphics_path are filled.
        xtd::drawing::drawing2d::fill_mode fill_mode() const noexcept;
        /// @brief Sets a xtd::drawing::drawing2d::fill_mode enumeration that determines how the interiors of shapes in this xtd::drawing::drawing2d::graphics_path are filled.
        /// @param value A xtd::drawing::drawing2d::fill_mode enumeration that specifies how the interiors of shapes in this xtd::drawing::drawing2d::graphics_path are filled.
        graphics_path& fill_mode(xtd::drawing::drawing2d::fill_mode value) noexcept;
        /// @}
   
        /// @name Methods
        
        /// @{
        /// @brief Appends an elliptical arc to the current figure.
        /// @param rect A xtd::drawing::rectangle that represents the rectangular bounds of the ellipse from which the arc is taken.
        /// @param start_angle The starting angle of the arc, measured in degrees clockwise from the x-axis.
        /// @param sweep_angle The angle between start_angle and the end of the arc.
        /// @remarks If there are previous lines or curves in the figure, a line is added to connect the endpoint of the previous segment to the beginning of the arc.
        /// @remarks The arc is traced along the perimeter of the ellipse bounded by the specified rectangle. The starting point of the arc is determined by measuring clockwise from the x-axis of the ellipse (at the 0-degree angle) by the number of degrees in the start angle. The endpoint is similarly located by measuring clockwise from the starting point by the number of degrees in the sweep angle. If the sweep angle is greater than 360 degrees or less than -360 degrees, the arc is swept by exactly 360 degrees or -360 degrees, respectively.
        void add_arc(const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle);
        /// @brief Appends an elliptical arc to the current figure.
        /// @param rect A xtd::drawing::rectangle_f that represents the rectangular bounds of the ellipse from which the arc is taken.
        /// @param start_angle The starting angle of the arc, measured in degrees clockwise from the x-axis.
        /// @param sweep_angle The angle between start_angle and the end of the arc.
        /// @remarks If there are previous lines or curves in the figure, a line is added to connect the endpoint of the previous segment to the beginning of the arc.
        /// @remarks The arc is traced along the perimeter of the ellipse bounded by the specified rectangle. The starting point of the arc is determined by measuring clockwise from the x-axis of the ellipse (at the 0-degree angle) by the number of degrees in the start angle. The endpoint is similarly located by measuring clockwise from the starting point by the number of degrees in the sweep angle. If the sweep angle is greater than 360 degrees or less than -360 degrees, the arc is swept by exactly 360 degrees or -360 degrees, respectively.
        void add_arc(const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle);
        /// @brief Appends an elliptical arc to the current figure.
        /// @param x The x-coordinate of the upper-left corner of the rectangular region that defines the ellipse from which the arc is drawn.
        /// @param y The y-coordinate of the upper-left corner of the rectangular region that defines the ellipse from which the arc is drawn.
        /// @param width The width of the rectangular region that defines the ellipse from which the arc is drawn.
        /// @param height The height of the rectangular region that defines the ellipse from which the arc is drawn.
        /// @param start_angle The starting angle of the arc, measured in degrees clockwise from the x-axis.
        /// @param sweep_angle The angle between start_angle and the end of the arc.
        /// @remarks If there are previous lines or curves in the figure, a line is added to connect the endpoint of the previous segment to the beginning of the arc.
        /// @remarks The arc is traced along the perimeter of the ellipse bounded by the specified rectangle. The starting point of the arc is determined by measuring clockwise from the x-axis of the ellipse (at the 0-degree angle) by the number of degrees in the start angle. The endpoint is similarly located by measuring clockwise from the starting point by the number of degrees in the sweep angle. If the sweep angle is greater than 360 degrees or less than -360 degrees, the arc is swept by exactly 360 degrees or -360 degrees, respectively.
        void add_arc(int32_t x, int32_t y, int32_t width, int32_t height, float start_angle, float sweep_angle);
        /// @brief Appends an elliptical arc to the current figure.
        /// @param x The x-coordinate of the upper-left corner of the rectangular region that defines the ellipse from which the arc is drawn.
        /// @param y The y-coordinate of the upper-left corner of the rectangular region that defines the ellipse from which the arc is drawn.
        /// @param width The width of the rectangular region that defines the ellipse from which the arc is drawn.
        /// @param height The height of the rectangular region that defines the ellipse from which the arc is drawn.
        /// @param start_angle The starting angle of the arc, measured in degrees clockwise from the x-axis.
        /// @param sweep_angle The angle between start_angle and the end of the arc.
        /// @remarks If there are previous lines or curves in the figure, a line is added to connect the endpoint of the previous segment to the beginning of the arc.
        /// @remarks The arc is traced along the perimeter of the ellipse bounded by the specified rectangle. The starting point of the arc is determined by measuring clockwise from the x-axis of the ellipse (at the 0-degree angle) by the number of degrees in the start angle. The endpoint is similarly located by measuring clockwise from the starting point by the number of degrees in the sweep angle. If the sweep angle is greater than 360 degrees or less than -360 degrees, the arc is swept by exactly 360 degrees or -360 degrees, respectively.
        void add_arc(float x, float y, float width, float height, float start_angle, float sweep_angle);

        /// @brief Adds a cubic Bézier curve to the current figure.
        /// @param pt1 A xtd::drawing::point that represents the starting point of the curve.
        /// @param pt2 A xtd::drawing::point that represents the first control point for the curve.
        /// @param pt3 A xtd::drawing::point that represents the second control point for the curve.
        /// @param pt4 A xtd::drawing::point that represents the endpoint of the curve.
        /// @remarks The cubic curve is constructed from the first point to the fourth point by using the second and third points as control points.
        /// @remarks If there is a previous line or curve segment in the figure, a line is added to connect the endpoint of the previous segment to the starting point of the cubic curve.
        void add_bezier(const xtd::drawing::point& pt1, const xtd::drawing::point& pt2, const xtd::drawing::point& pt3, const xtd::drawing::point& pt4);
        /// @brief Adds a cubic Bézier curve to the current figure.
        /// @param pt1 A xtd::drawing::point_f that represents the starting point of the curve.
        /// @param pt2 A xtd::drawing::point_f that represents the first control point for the curve.
        /// @param pt3 A xtd::drawing::point_f that represents the second control point for the curve.
        /// @param pt4 A xtd::drawing::point_f that represents the endpoint of the curve.
        /// @remarks The cubic curve is constructed from the first point to the fourth point by using the second and third points as control points.
        /// @remarks If there is a previous line or curve segment in the figure, a line is added to connect the endpoint of the previous segment to the starting point of the cubic curve.
        void add_bezier(const xtd::drawing::point_f& pt1, const xtd::drawing::point_f& pt2, const xtd::drawing::point_f& pt3, const xtd::drawing::point_f& pt4);
        /// @brief Adds a cubic Bézier curve to the current figure.
        /// @param x1 The x-coordinate of the starting point of the curve.
        /// @param y1 The y-coordinate of the starting point of the curve.
        /// @param x2 The x-coordinate of the first control point for the curve.
        /// @param y2 The y-coordinate of the first control point for the curve.
        /// @param x3 The x-coordinate of the second control point for the curve.
        /// @param y3 The y-coordinate of the second control point for the curve.
        /// @param x4 The x-coordinate of the endpoint of the curve.
        /// @param y4 The y-coordinate of the endpoint of the curve.
        /// @remarks The cubic curve is constructed from the first point to the fourth point by using the second and third points as control points.
        /// @remarks If there is a previous line or curve segment in the figure, a line is added to connect the endpoint of the previous segment to the starting point of the cubic curve.
        void add_bezier(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4);
        /// @brief Adds a cubic Bézier curve to the current figure.
        /// @param x1 The x-coordinate of the starting point of the curve.
        /// @param y1 The y-coordinate of the starting point of the curve.
        /// @param x2 The x-coordinate of the first control point for the curve.
        /// @param y2 The y-coordinate of the first control point for the curve.
        /// @param x3 The x-coordinate of the second control point for the curve.
        /// @param y3 The y-coordinate of the second control point for the curve.
        /// @param x4 The x-coordinate of the endpoint of the curve.
        /// @param y4 The y-coordinate of the endpoint of the curve.
        /// @remarks The cubic curve is constructed from the first point to the fourth point by using the second and third points as control points.
        /// @remarks If there is a previous line or curve segment in the figure, a line is added to connect the endpoint of the previous segment to the starting point of the cubic curve.
        void add_bezier(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

        /// @brief Adds a sequence of connected cubic Bézier curves to the current figure.
        /// @param points An array of xtd::drawing::point structures that represents the points that define the curves.
        /// @remarks The points parameter specifies an array of endpoints and control points of the connected curves. The first curve is constructed from the first point to the fourth point in the points array by using the second and third points as control points. In addition to the endpoint of the previous curve, each subsequent curve in the sequence needs exactly three more points: the next two points in the sequence are control points, and the third is the endpoint for the added curve.
        /// @remarks If there are previous lines or curves in the figure, a line is added to connect the endpoint of the previous segment to the starting point of the first cubic curve in the sequence.
        void add_beziers(const std::vector<xtd::drawing::point>& points);
        /// @brief Adds a sequence of connected cubic Bézier curves to the current figure.
        /// @param points An array of xtd::drawing::point_f structures that represents the points that define the curves.
        /// @remarks The points parameter specifies an array of endpoints and control points of the connected curves. The first curve is constructed from the first point to the fourth point in the points array by using the second and third points as control points. In addition to the endpoint of the previous curve, each subsequent curve in the sequence needs exactly three more points: the next two points in the sequence are control points, and the third is the endpoint for the added curve.
        /// @remarks If there are previous lines or curves in the figure, a line is added to connect the endpoint of the previous segment to the starting point of the first cubic curve in the sequence.
        void add_beziers(const std::vector<xtd::drawing::point_f>& points);

        /// @brief Adds a closed curve to this path. A cardinal spline curve is used because the curve travels through each of the points in the array.
        /// @param points An array of xtd::drawing::point structures that represents the points that define the curve.
        /// @remarks The user must keep the original points if they are needed. The original points are converted to cubic Bézier control points internally, therefore there is no mechanism for returning the original points. If the first point and the last point in the points array are not the same point, the curve is closed by connecting these two points.The tension value cannot be set for this method, and defaults to a value equivalent to 0.5.
        void add_closed_curve(const std::vector<xtd::drawing::point>& points);
        /// @brief Adds a closed curve to this path. A cardinal spline curve is used because the curve travels through each of the points in the array.
        /// @param points An array of xtd::drawing::point_f structures that represents the points that define the curve.
        /// @remarks The user must keep the original points if they are needed. The original points are converted to cubic Bézier control points internally, therefore there is no mechanism for returning the original points. If the first point and the last point in the points array are not the same point, the curve is closed by connecting these two points.The tension value cannot be set for this method, and defaults to a value equivalent to 0.5.
        void add_closed_curve(const std::vector<xtd::drawing::point_f>& points);
        /// @brief Adds a closed curve to this path. A cardinal spline curve is used because the curve travels through each of the points in the array.
        /// @param points An array of xtd::drawing::point_f structures that represents the points that define the curve.
        /// @param tension A value between from 0 through 1 that specifies the amount that the curve bends between points, with 0 being the smallest curve (sharpest corner) and 1 being the smoothest curve.
        /// @remarks The user must keep the original points if they are needed. The original points are converted to cubic Bézier control points internally, therefore there is no mechanism for returning the original points. If the first point and the last point in the points array are not the same point, the curve is closed by connecting these two points.
        void add_closed_curve(const std::vector<xtd::drawing::point>& points, float tension);
        /// @brief Adds a closed curve to this path. A cardinal spline curve is used because the curve travels through each of the points in the array.
        /// @param points An array of xtd::drawing::point_f structures that represents the points that define the curve.
        /// @param tension A value between from 0 through 1 that specifies the amount that the curve bends between points, with 0 being the smallest curve (sharpest corner) and 1 being the smoothest curve.
        /// @remarks The user must keep the original points if they are needed. The original points are converted to cubic Bézier control points internally, therefore there is no mechanism for returning the original points. If the first point and the last point in the points array are not the same point, the curve is closed by connecting these two points.
        void add_closed_curve(const std::vector<xtd::drawing::point_f>& points, float tension);
        
        /// @brief Adds a spline curve to the current figure.
        /// @brief Adds a spline curve to the current figure.
        /// @param points An array of PointF structures that represents the points that define the curve.
        /// @remarks The user must keep the original points if they are needed. The original points are converted to cubic Bézier control points internally, therefore there is no mechanism for returning the original points.
        void add_curve(const std::vector<xtd::drawing::point>& points);
        /// @brief Adds a spline curve to the current figure.
        /// @param points An array of PointF structures that represents the points that define the curve.
        /// @remarks The user must keep the original points if they are needed. The original points are converted to cubic Bézier control points internally, therefore there is no mechanism for returning the original points.
        void add_curve(const std::vector<xtd::drawing::point_f>& points);
        /// @brief Adds a spline curve to the current figure.
        /// @param points An array of PointF structures that represents the points that define the curve.
        /// @param tension A value that specifies the amount that the curve bends between control points. Values greater than 1 produce unpredictable results.
        /// @remarks The user must keep the original points if they are needed. The original points are converted to cubic Bézier control points internally, therefore there is no mechanism for returning the original points.
        void add_curve(const std::vector<xtd::drawing::point>& points, float tension);
        /// @brief Adds a spline curve to the current figure.
        /// @param points An array of PointF structures that represents the points that define the curve.
        /// @param tension A value that specifies the amount that the curve bends between control points. Values greater than 1 produce unpredictable results.
        /// @remarks The user must keep the original points if they are needed. The original points are converted to cubic Bézier control points internally, therefore there is no mechanism for returning the original points.
        void add_curve(const std::vector<xtd::drawing::point_f>& points, float tension);
        /// @brief Adds a spline curve to the current figure.
        /// @param points An array of PointF structures that represents the points that define the curve.
        /// @param offset he index of the element in the points array that is used as the first point in the curve.
        /// @param number_of_segments The number of segments used to draw the curve. A segment can be thought of as a line connecting two points.
        /// @param tension A value that specifies the amount that the curve bends between control points. Values greater than 1 produce unpredictable results.
        /// @remarks The user must keep the original points if they are needed. The original points are converted to cubic Bézier control points internally, therefore there is no mechanism for returning the original points.
        /// @remarks The curve begins at the point in the array specified by offset, and includes the number of points (segments) specified by number_of_segments.
        void add_curve(const std::vector<xtd::drawing::point>& points, size_t offset, size_t number_of_segments, float tension);
        /// @brief Adds a spline curve to the current figure.
        /// @param points An array of PointF structures that represents the points that define the curve.
        /// @param offset he index of the element in the points array that is used as the first point in the curve.
        /// @param number_of_segments The number of segments used to draw the curve. A segment can be thought of as a line connecting two points.
        /// @param tension A value that specifies the amount that the curve bends between control points. Values greater than 1 produce unpredictable results.
        /// @remarks The user must keep the original points if they are needed. The original points are converted to cubic Bézier control points internally, therefore there is no mechanism for returning the original points.
        /// @remarks The curve begins at the point in the array specified by offset, and includes the number of points (segments) specified by number_of_segments.
        void add_curve(const std::vector<xtd::drawing::point_f>& points, size_t offset, size_t number_of_segments, float tension);

        /// @brief Adds an ellipse to the current path.
        /// @param rect A xtd::drawing::rectangle that represents the bounding rectangle that defines the ellipse.
        void add_ellipse(const xtd::drawing::rectangle& rect);
        /// @brief Adds an ellipse to the current path.
        /// @param rect A xtd::drawing::rectangle_f that represents the bounding rectangle that defines the ellipse.
        void add_ellipse(const xtd::drawing::rectangle_f& rect);
        /// @brief Adds an ellipse to the current path.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
        /// @param y The y-coordinate of the upper left corner of the bounding rectangle that defines the ellipse.
        /// @param width The width of the bounding rectangle that defines the ellipse.
        /// @param height The height of the bounding rectangle that defines the ellipse.
        void add_ellipse(int32_t x, int32_t y, int32_t width, int32_t height);
        /// @brief Adds an ellipse to the current path.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
        /// @param y The y-coordinate of the upper left corner of the bounding rectangle that defines the ellipse.
        /// @param width The width of the bounding rectangle that defines the ellipse.
        /// @param height The height of the bounding rectangle that defines the ellipse.
        void add_ellipse(float x, float y, float width, float height);

        /// @brief Appends a line segment to this xtd::drawing::drawing2d::graphics_path.
        /// @param pt1 A xtd::drawing::point that represents the starting point of the line.
        /// @param pt2 A xtd::drawing::point that represents the endpoint of the line.
        /// @remarks This method adds the line segment defined by the specified points to the end of this xtd::drawing::drawing2d::graphics_path. If there are previous lines or curves in the xtd::drawing::drawing2d::graphics_path, a line segment is drawn to connect the last point in the path to the first point in the new line segment.
        void add_line(const xtd::drawing::point& pt1, const xtd::drawing::point& pt2);
        /// @brief Appends a line segment to this xtd::drawing::drawing2d::graphics_path.
        /// @param pt1 A xtd::drawing::point_f that represents the starting point of the line.
        /// @param pt2 A xtd::drawing::point_f that represents the endpoint of the line.
        /// @remarks This method adds the line segment defined by the specified points to the end of this xtd::drawing::drawing2d::graphics_path. If there are previous lines or curves in the xtd::drawing::drawing2d::graphics_path, a line segment is drawn to connect the last point in the path to the first point in the new line segment.
        void add_line(const xtd::drawing::point_f& pt1, const xtd::drawing::point_f& pt2);
        /// @brief Appends a line segment to this xtd::drawing::drawing2d::graphics_path.
        /// @param x1 The x-coordinate of the starting point of the line.
        /// @param y1 The y-coordinate of the starting point of the line.
        /// @param x2 The x-coordinate of the endpoint of the line.
        /// @param y2 The y-coordinate of the endpoint of the line.
        /// @remarks This method adds the line segment defined by the specified points to the end of this xtd::drawing::drawing2d::graphics_path. If there are previous lines or curves in the xtd::drawing::drawing2d::graphics_path, a line segment is drawn to connect the last point in the path to the first point in the new line segment.
        void add_line(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
        /// @brief Appends a line segment to this xtd::drawing::drawing2d::graphics_path.
        /// @param x1 The x-coordinate of the starting point of the line.
        /// @param y1 The y-coordinate of the starting point of the line.
        /// @param x2 The x-coordinate of the endpoint of the line.
        /// @param y2 The y-coordinate of the endpoint of the line.
        /// @remarks This method adds the line segment defined by the specified points to the end of this xtd::drawing::drawing2d::graphics_path. If there are previous lines or curves in the xtd::drawing::drawing2d::graphics_path, a line segment is drawn to connect the last point in the path to the first point in the new line segment.
        void add_line(float x1, float y1, float x2, float y2);

        /// @brief Appends a series of connected line segments to the end of this xtd::drawing::drawing2d::graphics_path.
        /// @param points An array of xtd::drawing::point structures that represents the points that define the line segments to add.
        /// @remarks If there are previous lines or curves in the figure, a line is added to connect the endpoint of the previous segment the starting point of the line. The points parameter specifies an array of endpoints. The first two specify the first line. Each additional point specifies the endpoint of a line segment whose starting point is the endpoint of the previous line.
        void add_lines(const std::vector<xtd::drawing::point>& points);
        /// @brief Appends a series of connected line segments to the end of this xtd::drawing::drawing2d::graphics_path.
        /// @param points An array of xtd::drawing::point_f structures that represents the points that define the line segments to add.
        /// @remarks If there are previous lines or curves in the figure, a line is added to connect the endpoint of the previous segment the starting point of the line. The points parameter specifies an array of endpoints. The first two specify the first line. Each additional point specifies the endpoint of a line segment whose starting point is the endpoint of the previous line.
        void add_lines(const std::vector<xtd::drawing::point_f>& points);

        /// @brief Appends the specified xtd::drawing::drawing2d::graphics_path to this path.
        /// @param adding_path The xtd::drawing::drawing2d::graphics_path to add.
        /// @param connect A bool value that specifies whether the first figure in the added path is part of the last figure in this path. A value of true specifies that (if possible) the first figure in the added path is part of the last figure in this path. A value of false specifies that the first figure in the added path is separate from the last figure in this path.
        void add_path(const graphics_path& adding_path, bool connect);

        /// @brief Adds the outline of a pie shape to this path.
        /// @param rect A xtd::drawing::rectangle that represents the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param start_angle The starting angle for the pie section, measured in degrees clockwise from the x-axis.
        /// @param sweep_angle The angle between start_angle and the end of the pie section, measured in degrees clockwise from start_angle.
        /// @remarks The pie shape is defined by a partial outline of an ellipse and the two radial lines that intersect the endpoints of the partial outline. The partial outline begins at start_angle (measured clockwise from the x-axis) and ends at start_angle + sweep_angle.
        void add_pie(const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle);
        /// @brief Adds the outline of a pie shape to this path.
        /// @param rect A xtd::drawing::rectangle_f that represents the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param start_angle The starting angle for the pie section, measured in degrees clockwise from the x-axis.
        /// @param sweep_angle The angle between start_angle and the end of the pie section, measured in degrees clockwise from start_angle.
        /// @remarks The pie shape is defined by a partial outline of an ellipse and the two radial lines that intersect the endpoints of the partial outline. The partial outline begins at start_angle (measured clockwise from the x-axis) and ends at start_angle + sweep_angle.
        void add_pie(const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle);
        /// @brief Adds the outline of a pie shape to this path.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param width The width of the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param height The height of the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param start_angle The starting angle for the pie section, measured in degrees clockwise from the x-axis.
        /// @param sweep_angle The angle between start_angle and the end of the pie section, measured in degrees clockwise from start_angle.
        /// @remarks The pie shape is defined by a partial outline of an ellipse and the two radial lines that intersect the endpoints of the partial outline. The partial outline begins at start_angle (measured clockwise from the x-axis) and ends at start_angle + sweep_angle.
        void add_pie(int32_t x, int32_t y, int32_t width, int32_t height, float start_angle, float sweep_angle);
        /// @brief Adds the outline of a pie shape to this path.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param width The width of the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param height The height of the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param start_angle The starting angle for the pie section, measured in degrees clockwise from the x-axis.
        /// @param sweep_angle The angle between start_angle and the end of the pie section, measured in degrees clockwise from start_angle.
        /// @remarks The pie shape is defined by a partial outline of an ellipse and the two radial lines that intersect the endpoints of the partial outline. The partial outline begins at start_angle (measured clockwise from the x-axis) and ends at start_angle + sweep_angle.
        void add_pie(float x, float y, float width, float height, float start_angle, float sweep_angle);

        /// @brief Adds a polygon to this path.
        /// @param points An array of xtd::drawing::point structures that defines the polygon to add.
        /// @remarks The points in the points array specify the vertices of a polygon. If the first point in the array is not the same as the last point, those two points are connected to close the polygon.
        void add_polygon(const std::vector<xtd::drawing::point>& points);
        /// @brief Adds a polygon to this path.
        /// @param points An array of xtd::drawing::point_f structures that defines the polygon to add.
        /// @remarks The points in the points array specify the vertices of a polygon. If the first point in the array is not the same as the last point, those two points are connected to close the polygon.
        void add_polygon(const std::vector<xtd::drawing::point_f>& points);

        void add_rectangle(const xtd::drawing::rectangle& rect);
        void add_rectangle(const xtd::drawing::rectangle_f& rect);
        void add_rectangle(int32_t x, int32_t y, int32_t width, int32_t height);
        void add_rectangle(float x, float y, float width, float height);

        void add_rectangles(const std::vector<xtd::drawing::rectangle>& rects);
        void add_rectangles(const std::vector<xtd::drawing::rectangle_f>& rects);

        void add_rounded_rectangle(const xtd::drawing::rectangle& rect, float radius);
        void add_rounded_rectangle(const xtd::drawing::rectangle_f& rect, float radius);
        void add_rounded_rectangle(int32_t x, int32_t y, int32_t width, int32_t height, float radius);
        void add_rounded_rectangle(float x, float y, float width, float height, float radius);

        void close_markers();

        void close_all_figures();

        void close_figure();

        void flatten();

        xtd::drawing::rectangle_f get_bounds() const;

        void reverse();
        
        void set_markers();
        
        void start_figure();

        xtd::ustring to_string() const noexcept override;
        /// @}
        
        /// @cond
        friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::drawing2d::graphics_path& graphics_path) noexcept {return os << graphics_path.to_string();}
        /// @endcond
        
      private:
        struct data {
          intptr_t handle = 0;
          xtd::drawing::drawing2d::fill_mode fill_mode = xtd::drawing::drawing2d::fill_mode::alternate;
        };
        std::shared_ptr<data> data_ = std::make_shared<data>();
      };
    }
  }
}
