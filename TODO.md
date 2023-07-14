MSCI UNITS - VERSION 2

// COORDINATES AND POINTS
// TODO: finish get_altitude(). Read about geographic coordinates and decide what to do in point_3d, point_nd, coordinates_3d and coordinates_nd
// TODO: displacement_nd in point_nd class should be initialized with zero dimensions instead of m?. Check the all the default dimensions cases for point_nd, coordinates_nd and coordinates_ndr
// TODO: think on the different cases of use of coordinates and document them, including the use of an origin

// VECTOR FIELDS
// TODO: vector_field (it should operate with vector_units and maybe with scalar_units. With (x,y,z) it gives the respective vector). +, - and ^ with vector_field, + - * with vector_unit
// TODO: Typecasting of vector_unit to math_vector, boost_Ublas_vector, etc. Same for math_vector to vector_unit

// C++
// TODO: use of constexpr
// TODO: change char in enum for int8_t
// TODO: use scientific notation for the avogadro constant
// TODO: change the use of const-reference to value and std::move in constructors
// TODO: change the use of const-reference to value and std::move in other places

// DIMENSIONS
// TODO: support the binary prefixes too
// TODO: see how to free the char[]

// UNITS
// TODO: finish the tests of all the unit classes

// TODO: to_string() of vector_unit classes should truncate the amount of digits to display for the value and for the angles

// TODO: see what to do with the imprecision when converting the string to a float, it's needed to have perfect precision, not an approximated conversion instead

// TODO: allow to display in any conversion. By default it should always display in SI units, only if a conversion is expressly specified in the display functions the conversion is then the dimension that gets displayed

// TODO: add the emotional dimensions for robotics and similar purposes. Think of the names for rage, mourning, etc related to the dimensions, which has to be a different name than the name of the emotion

// TODO: vectorial_display for vector_unit classes using custom_display() and display_derived() of scalar_unit, but adding the angles next to it

// TODO: check dimensions in all inheriting classes of scalar_unit and vector_unit, it's needed another constructor

// SPECIAL UNITS
// TODO: complete color class like coordinate classes, with all the getters of all the different color versions, like get_h(), get_s(), get_v()
// TODO: pixel_color<>. Use monochrome_pixel, truecolor_pixel, etc, as typedefs of pixel_color<>

// TODO: complex_number<> should have trigonometric functions for complex numbers

// TODO: maybe create a mesh_3d class, or vector<point_3d<>>

// TODO: study the geographic coordinates deeply, and see if to add something more related to them

// CALCULUS WITH UNITS
// TODO: think if to add the functions of calculations or to add example of calculations in the documentation

// UNITS - ADVANCED
// TODO: maybe delete the dimensions member-variable of scalar_unit, and use instead another system for handling prefixes. The dimensions can be automatic based on their class. One possibility is to use an empty array and, when it's empty, to send the fixed dimensions of the class instead, and only when changing something to add the dimensions there
// TODO: add const to the enum of light_unit
// TODO: 2d display of scalar_units and of vector_units (create a msci_units_2d library for it)
// TODO: 3d display of scalar_units and of vector_units (create a msci_units_3d library for it)
// TODO: divide single dimensions unit of multiple-dimensions unit in order to save a lot of space by not using vectors of prefixes, dimensions and abbreviations
// TODO: check the object code resulting by testing different functions of the unit classes
// TODO: light_length which uses only an enum of prefixes and a value, maybe it should be called length, and length should be called full_length
// TODO: sqrt() and pow() maybe should be direct for created units, instead of passing by scalar_unit again to initialize after that the other unit
// TODO: check if it's needed to add a function that gives whether the dimension is basic or not in the sense of the SI system of units
// TODO: support and UTF32 string constructor for scalar_unit in order to allow to create dimensions directly with some Unicode characters that are not present in UTF8
// TODO: scalar_unit should have is_valid() with some system
// TODO: maybe the prefix and the dimension can be removed as member-variables if displaying automatically in some way or another, as it's expressly specified. That is maybe the biggest optimization possible
// TODO: think if to change the float for a double, or if to make scalar_unit a template class converting the default type of the value to float type
// TODO: support the conversions natively
// TODO: function to_SI_convention(vector<scalar_unit>&)
// TODO: finish initial_dimensions_get_structure() and get_dimensions_match() related to the new implementation

// BASIC UNITS
// TODO: think if to add another concentration class, the previous one has been deprecated

// SPECIAL UNIS - EXTRA
// ip class? check networking libraries of C++ and decide if to add it here
// isbn class
// issn class

// ISOs
// TODO: Publish the ISO of geographic location based on aid and zid classes
// TODO: See if to make an ISO of an official symbol for money (not a concrete money of a country, but a universal one)
// TODO: Add "depth" to an ISO of names for the lengths of objects (width, height and depth are the names). It's needed to have a name in spanish for the depth too
// TODO: Maybe create an "ISO" of geographic positioning taking the major axis of the planet, which can be the Earth or not, and adding 50 km to it, in order to have a border of safety in order to be sure that no point remains uncovered by the imaginary sphere that the geographic positioning creates around the planet. It can be used for any planet of the universe. The center of the planet is considered always the geometrical one, not the center of mass, because that last one changes with changes of the distribution of mass inside the planet

// ISO C++
// TODO: add º to the string literals
// TODO: add % to the string literals
// TODO: add the possibility to create class names starting with numbers

// MATERIAL_VECTOR_UNIT
// TODO: decide how it'll be, in order to include real space to the vector_unit?

// MECA NUMBERS
// TODO: add the allowed typenames to lab_number, and don't accept any other type
// TODO: lab_number should have another symbol in place of +-

// ELECTRONICS
// TODO: check sensor libraries and decide which ones to support inside msci_units (maybe in a new msci library if needed)

// PATTERNS
// TODO: implement a pattern class using a regular expressions library

// TESTS
// TODO: test of sizeof for all unit classes
// TODO: benchmark test for scalar_unit, comparing them to a float

// DOCUMENTATION
// TODO: document the point of view of the library of when a dimension is considered "basic"
// TODO: document the ISOs important to use with this library
// TODO: document a little how to handle currency
// TODO: document that the pixel in dimension is only as length, not as a pixel on the screen as is in the pixel class
// TODO: document how ppm and ppb work, also in the theorical sense
// TODO: document an example of converting all currencies to money dimension, with different values. Use the currency abreviations of the ISO of currencies
// TODO: add nomenclature of units

// RELEASE
// TODO: configure CMake with cpack
// TODO: see what to do with msci.pc
// TODO: see what to do to configure optimizations

// MATRIX
// TODO: See if it's best to use template arguments for row and column or if to store those values as member-variables
// TODO: Multiplication of matrices of different but compatible types
// TODO: typecast to other matrix-classes of important libraries
// TODO: Iterator with range to use only one range-for
// TODO: Check limits of matrices for all operators
// TODO: Use the GSL to implement the reverse matrix

// CONSTANTS
// TODO: make a list of all important constants of science, with their respective unit. The constants of physics, chemistry and biology should be inside. Also, add the constants of astronomy

// FUTURE
// TODO: support the case of n dimensions fixed
// TODO: add the theta and phi characters to C++ variable names, and add them then to the member-variables of vector_unit classes, and any other case of similar use. Add the symbol º to string literals
// TODO: add the astronomy coordinates
// TODO: add the other orthogonal coordinates, like paraboloidal
// TODO: add to the ISO of the keyboards some system to write pi, theta, phi, among other symbols, with the keyboard in an easy way, without having to memorize any numeric code
// TODO: propose an ISO symbol for money in general?
// TODO: finish the empty array implementation for dimension, in order to have normal dimensions, no custom dimensions, of size 3 instead of size 6

// FUTURE - MECA NUMBERS (POSSIBLE, THINK)
// TODO: Add names to the meca numbers (angler, laber, etc)
// TODO: The interval number class
// TODO: The interval number subclasses of other numbers
// TODO: The bounce number class
// TODO: The percentage number class (it has to have the calculate function in order to receive a value to be the percentage of)
// TODO: Solve the problem with left and right repeated (it's not exclusive for direction_symbol)
// TODO: solid_angle class (maybe it isn't a meca number)
// TODO: maybe _angle for angle in order to use cos(x),sin(x),etc with degrees

// READINGS
// Unit of measurement: https://en.wikipedia.org/wiki/Unit_of_measurement
// International system of units: https://en.wikipedia.org/wiki/International_System_of_Units
// Angle: https://en.wikipedia.org/wiki/Angle
// Metrology: https://en.wikipedia.org/wiki/Metrology
// Color: https://en.wikipedia.org/wiki/Color
// RGB color model: https://en.wikipedia.org/wiki/RGB_color_model
// Color model: https://en.wikipedia.org/wiki/Color_model
// Unit prefix: https://en.wikipedia.org/wiki/Unit_prefix
// Metric prefix: https://en.wikipedia.org/wiki/Metric_prefix
