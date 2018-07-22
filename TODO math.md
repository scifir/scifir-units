// MATH
// TODO: search for actual math libraries: graph libraries, function libraries
// TODO: interval of (a,b) class: interval_state enum (open,close), ordinal pairs, operator << and print(), range iterator(?)

// VARIABLES AND FUNCTIONS
// TODO: use a functor for the function class instead of math_expression and related classes (do that variables when multiplying, suming, etc, do the same with names, then it's possible to print at instantly the name of the function). For removing the extra parentheses caused by the variable operators + and - it's needed to count the extra parentheses after /( and remove ) only if the extra parentheses are 0. Use a function_2d class for the event-oriented programming part of the graph of the function
// TODO: finish math/algebra classes
// TODO: constants.hpp files
// TODO: create all constant units and their variable class
// TODO: see if to use unit* instead of auto_unit for member-variable value inside math_variable class
// TODO: see if to plot with a custom function or using an external library (check if external libraries have support for vector fields and scalar fields, and vector units / scalar units, and to mix with other objects)

// MATRIX
// TODO: See if it's best to use template arguments for row and column or if to store those values as member-variables
// TODO: Multiplication of matrices of different but compatible types
// TODO: typecast to other matrix-classes of important libraries
// TODO: Iterator with range to use only one range-for
// TODO: Check limits of matrices for all operators
// TODO: Use the GSL to implement the reverse matrix

// 3D
// TODO: finish hyper_spherical_coordinates::rotate2()
// TODO: finish hyper_spherical_coordinates::x_projection(), hyper_spherical_coordinates::y_projection(), hyper_spherical_coordinates::z_projection()
// TODO: finish hyper_spherical_coordinates::n_projection() for the n-case
// TODO: hyper_coordinates, cartesian_coordinates_1d
// TODO: math_vector
// TODO: hyper_coordinates_unit<>
// TODO: vector_unit should inherit of math_vector and of hyper_coordinates_unit<>
// TODO: point_2d_units<> with dimensions, and spatial_2d_point with length dimensions
// TODO: hyper_spherical_coordinates after the changes here shouldn't need the lambda function
// TODO: figure_2d classes in 3D
// TODO: display_3d() function for all figure_3d classes
// TODO: display_2d() function for all figure_3d classes

// 2D FIGURES
// TODO: http://www.boost.org/doc/libs/1_64_0/libs/polygon/doc/index.htm
// TODO: https://github.com/ArashPartow/wykobi
// TODO: http://shapeop.org/
// TODO: Decide which geometry library to wrap
// TODO: If to separate the positioning from the logic. Then to remove center from figure_2d
// TODO: Find out if there's a general name for complex shapes
// TODO: constructors should check border cases, see what to do when the input is wrong
// TODO: polygon class can maybe use something from boost in order to don't calculate math
// TODO: translate(physics::units::distance) function inside cartesian_coordinates. Also, add cartesian_coordinates to point_2d and point_3d
// TODO: graphical_polygon inherits from polygon and 2d_rigid_body. It includes borders (that can be 0) and is_inside_border(), is_inside_body(). Ghost behavior is part of 2d_rigid_body
// TODO: figure_2d classes should have rotate
// TODO: polygon class should be initialized as an initializer-list like {{0,0},{1,0}}
// TODO: add() method for adding figures inside a complex shape
// TODO: display_2d() function for all figure_3d classes
// TODO: display_2d() function for point_2d,line_2d and curve_2d classes
// TODO: scale(const math::percentage_number&) needs percentage_number class to be finished
// TODO: get_angle()
// TODO: maybe delete edges as a member-variables and change create_edges() name to get_edges()
// TODO: line_ed::is_inside() to test if the point is inside the line. Add that to is_inside() of linear_figure_2d class
