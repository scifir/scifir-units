SCIFIR UNITS - VERSION 2

// NUMBER OF TODOS: 52

// BUGS AND SIMILAR PROBLEMS (13)
// TODO: add the initialization to aid with string with a whitespace between the type and the universe
// TODO: zid needs to have a default name for no countries
// TODO: zid needs full display and partial display

// TODO: all display functions of coordinates classes need an int argument to select number of decimals
// TODO: scalar_unit needs a constructor with int
// TODO: check the literal of Ohm initialization in string class to be used instead of IS_UNIX and IS_WINDOWS in all the code files. Also, possibly it's needed to add IS_UNIX and IS_WINDOWS there
// TODO: look at the 1.99 of test_coordinates_2d vs the 2 of the float specialization
// TODO: think if to add a function that allows to test for values near another value
// TODO: -Wall gives a warning for vector_unit_nd with end of non-void function
// TODO: check prefix_math() everywhere, maybe there's a better implementation to do than the current implementation
// TODO: check and correct all the warnings of cl.exe with /Wall
// TODO: create percentage<double> and percentage<long double> with ppb, ppt and ppq. Create also the function is_long_percentage() to test for ppb, ppt and ppq
// TODO: display_double() and display_long_double() functions of types.cpp

// BUILD (3)
// TODO: support freebsd and openbsd
// TODO: upload the package to the container registry of github packages
// TODO: search if there's a way to add multiple jobs to the build with the command cmake --build, similar to make -j

// BUILD - ADVANCED (7)
// TODO: study bazel and look the files of bazel that are part of Catch2, maybe the same should be done for scifir-units
// TODO: see how to support consoles inside the building, if possible
// TODO: possibly add the library to conan
// TODO: test vcpkg.json uploading scifir-units to vcpkg
// TODO: check the welcome file for cpack, maybe it's useful
// TODO: support the compilation with Emscripten and add web-assembly as another preset more
// TODO: check the configuration options that exist for gcov

// IDE (2)
// TODO: check the extension gcov viewer is working properly
// TODO: configure ctest inside Visual Studio Code

// GITHUB (8)
// TODO: update the github action that updates the CHANGELOG.md file, make it work
// TODO: release the version 2.0-beta
// TODO: add the github action with windows
// TODO: add the github action with macos
// TODO: add try online badge
// TODO: add the release badge
// TODO: add the code coverage badge
// TODO: upload scifir-units to sourceforge too

// TESTS (3)
// TODO: finish the tests of all classes
// TODO: review get_nd() of the tests of vector_unit_nd and coordinates_nd
// TODO: verify that are present all functions of coordinates with rotations

// DOCUMENTATION (18)
// TODO: document the coordinates for the universe, publish that too as an standard inside scifir
// TODO: document example of use cases (laboratory machines,medical devices,robotics)
// TODO: document all the NEWS file
// TODO: reference books related to the physics, chemistry, biology or math implemented
// TODO: mention the WGS in the part of coordinates
// TODO: explain the custom dimensions in the file README.md
// TODO: document the use of the custom_display "sci"
// TODO: think on the different cases of use of coordinates and document them, including the use of an origin
// TODO: check what to do with the libraries of ISOs and document them inside the README.md file
// TODO: document how to create scientific inventions in the library, how to create laboratory machines and how to create medical devices
// TODO: document how to use the library for robots
// TODO: think if to add the help of Eclipse, and search if other IDEs use some help too
// TODO: decide if to generate documentation for man, and if so, exxplain that inside the README.md file
// TODO: add the summary sheet somewhere
// TODO: formulas of physics related to units
// TODO: formulas of chemistry related to units
// TODO: formulas of biology related to units
// TODO: document how all the operations of scalars and vector units work mathematically, possibly use mathjax inside markdown to display formulas
// TODO: document the use of fabs() and display() to compare values of units
// TODO: "Things to remember" section, which explains the use of the degree for vector_unit_nd instead of the other two cases, the use of fabs, the use of display that doesn't displays all decimals

// COORDINATES AND POINTS (10)
// TODO: add coordinates_3d::origin() to allow to initialize with an origin, it's specially useful for geographic coordinates
// TODO: functions of conversion of coordinates for scalar_unit classes
// TODO: coordinates and point classes should have a move constructor and move assignment for the related type (point_3d for coordinates_3d and coordinates_3d for point_3d, etc)
// TODO: coordinates_nd needs a constructor with vector<T>. coordinates_ndr needs it too
// TODO: delete the float references in constructors
// TODO: the case when the initialization string contains only the character ',', without a value, has to initialize to zero
// TODO: maybe display_cartesian() function should be in all coordinates classes too
// TODO: string assignment for all coordinates classes
// TODO: display functions should allow to change dimensions for any case
// TODO: add the operator<< of the float specialization everywhere

// COORDINATES AND POINTS - FINISH GEOGRAPHIC COORDINATES (2)
// TODO: finish get_altitude(). Read about geographic coordinates and decide what to do in point_3d, point_nd, coordinates_3d and coordinates_nd
// TODO: add the construction with an string for geographic coordinates
// TODO: study the geographic coordinates deeply, and see if to add something more related to them

// VECTOR FIELDS (2)
// TODO: vector_field (it should operate with vector_units and maybe with scalar_units. With (x,y,z) it gives the respective vector). +, - and ^ with vector_field
// TODO: parsing of initialization strings of fields. Allow to declare variables that can be refered by name inside initialization strings of vector fields

// ALGEBRA (4)
// TODO: constructor with initialization string
// TODO: is_algebraic_expression() and is_algebraic_term() functions
// TODO: static variable storing scalar_units, scalar_fields, etc
// TODO: search if there's a library that displays equations inside the command-line with math format, with math glyphs

// C++ (6)
// TODO: use constexpr and consteval to initialize units instantly, possibly use it in more parts of the code
// TODO: change the use of const-reference to value and std::move in constructors
// TODO: change the use of const-reference to value and std::move in other places
// TODO: use reference when instantiating variables and when it's not needed to instantiate by value inside the body of functions
// TODO: if size_t and other similar constants are intended to be used inside normal code
// TODO: replace boost::split by split of C++20

// DIMENSIONS (7)
// TODO: support the binary prefixes too
// TODO: a new function to display dimensions with their full name, including the prefix

// TODO: allow to initalize grade dimensions by symbol
// TODO: angle class needs a to_scalar_unit() function that gives an equivalent scalar_unit class with the same value and grade dimension
// TODO: some dimensions like grade, rad and money shouldn't be allowed to have a prefix
// TODO: check the literal with e

// TODO: finish the test of custom_basic dimensions and document them in the README.md file

// UNITS (9)
// TODO: solve in some way the problem that vector_unit_3d needs different characters in Windows an inside Linux when initialized with strings
// TODO: allow to display in any conversion. By default it should always display in SI units, only if a conversion is expressly specified in the display functions the conversion is then the dimension that gets displayed
// TODO: check dimensions in all inheriting classes of scalar_unit and vector_unit, it's needed another constructor that checks them
// TODO: vector_unit_3d class maybe need the comparison operators with themselves
// TODO: use the PI of the std library
// TODO: function point_to() to a point and point_to() to a coordinate

// TODO: Regex that checks all the invalid dimensions initialization inside a static_assert (create a static function of valid_initialization_string()). Maybe try first by undefining the value if there's something that doesn't exist (with an else). It's possible to test, with static_assert, that dimension == nullptr, abbreviation == nullptr and conversion == nullptr
// TODO: Detect when there's the same dimension at the numerator and at the denominator of the string initialization

// TODO: make scalar_unit a template class converting the default type of the value member-variable to float type. Change the derived units to template classes too, and also all vector_units. Change the macro that defines derived units to be only the macro with HPP and use it in all predefined_unit files

// PREDEFINED UNITS (4)
// TODO: think if to add accoustic and matter predefined units, or if it's not needed
// TODO: delete all field classes that currently are vector_units, and make them fields
// TODO: think if to add another concentration class, the previous one has been deprecated
// TODO: move cas_number to the library of scifir-info, or even to another category

// MECA NUMBERS (3)
// TODO: add the allowed typenames to lab_number, and don't accept any other type
// TODO: function is_lab_number()
// TODO: add initialization of lab_number inside README.md file

// SPECIAL UNITS - EXTRA (5)
// TODO: ip class? check networking libraries of C++ and decide if to add it here
// TODO: nutrition_information
// TODO: Class for geographical position including ZID and coordinates_3d
// TODO: maybe pixel should be called pixel_length
// TODO: think if to add a default case for the none value of aid and for the none value of zid
// TODO: functions is_aid() and is_zid()

// EMOTIONAL UNITS (1)
// TODO: finish the enums of mind.hpp

// SPECIAL UNITS (4)
// TODO: complete color class like coordinate classes, with all the getters of all the different color versions, like get_h(), get_s(), get_v()
// TODO: pixel_color<>. Use monochrome_pixel, truecolor_pixel, etc, as typedefs of pixel_color<>
// TODO: complex_number<> should have trigonometric functions for complex numbers
// TODO: maybe create a mesh_3d class, or vector<point_3d<>>

// MATERIAL_VECTOR_UNIT (1)
// TODO: add operator== and operator!=

// TENSORS (2)
// TODO: add display functions without new lines and other equivalents with new lines, they should allow to display like the other units related to dimensions
// TODO: add operator*, cross_product(), dot_product(), hadamard_product()

// PREDEFINED PHYSICS UNITS (4)
// TODO: electric_field which calculates based on coulomb charges
// TODO: gravity_field
// TODO: possibly magnetic_field?
// TODO: electric_current?

// CONTROL VOLUME (1)
// TODO: think what to do with the control_volume

// UNITS - ADVANCED (9)
// TODO: sqrt() and pow() maybe should be direct for created units, instead of passing by scalar_unit again to initialize after that the other unit
// TODO: check if it's needed to add a function is_si_basic_dimension() that gives whether the dimension is basic or not in the sense of the SI system of units
// TODO: support and UTF32 string constructor for scalar_unit in order to allow to create dimensions directly with some Unicode characters that are not present in UTF8
// TODO: scalar_unit should have is_valid() with some system
// TODO: support the conversions with constexpr
// TODO: add the operators +,-,* and / in the derived classes of scalar_unit and vector_unit with the same class in order to avoid to check that the dimensions are the same, that saves time
// TODO: check the object code resulting by testing different functions of the unit classes
// TODO: 2d display of scalar_units and of vector_units (create a scifir_units_2d library for it)
// TODO: 3d display of scalar_units and of vector_units (create a scifir_units_3d library for it)

// UNITS - ADVANCED - REDUCTION OF MEMORY CONSUMPTION (2)
// OPTION 1: maybe delete the dimensions member-variable of scalar_unit, and use instead another system for handling prefixes. The dimensions can be automatic based on their class. One possibility is to use an empty array and, when it's empty, to send the fixed dimensions of the class instead, and only when changing something to add the dimensions there
// OPTION 2: divide single dimensions unit of multiple-dimensions unit by adding only one dimension instead of the vector<dimension>
// OPTION 3: maybe the prefix and the dimension can be removed as member-variables if displaying automatically in some way or another, as it's expressly specified. That is maybe the biggest optimization possible
// OPTION 4: light_length which uses only an enum of prefixes and a value, maybe it should be called length, and length should be called full_length
// OPTION 4 - TODO: add const to the enum of light_unit
// AFTER SOME OPTION - TODO: finish initial_dimensions_get_structure() and get_dimensions_match() related to the new implementation

// ANOTHER PROJECT - LIBRARY OF INFORMATION
// TODO: isbn class
// TODO: issn class

// ISOs
// TODO: Publish the ISO of geographic location based on aid and zid classes
// TODO: See if to make an ISO of an official symbol for money (not a concrete money of a country, but a universal one)
// TODO: Add "depth" to an ISO of names for the lengths of objects (width, height and depth are the names). It's needed to have a name in spanish for the depth too
// TODO: Maybe create an "ISO" of geographic positioning taking the major axis of the planet, which can be the Earth or not, and adding 50 km to it, in order to have a border of safety in order to be sure that no point remains uncovered by the imaginary sphere that the geographic positioning creates around the planet. It can be used for any planet of the universe. The center of the planet is considered always the geometrical one, not the center of mass, because that last one changes with changes of the distribution of mass inside the planet

// ISO C++
// TODO: add º to the string literals
// TODO: add % to the string literals
// TODO: add the possibility to create class names starting with numbers

// ELECTRONICS
// TODO: check sensor libraries and decide which ones to support inside scifir-units (maybe in a new scifir library if needed)

// PATTERNS
// TODO: possibly implement a pattern class using a regular expressions library

// EXTRA TOOLS
// TODO: Create scicalcs, a cli tool that calculates with scifir-units any value

// PORTS
// TODO: Port to C#
// TODO: Port to Java
// TODO: Port to Octave
// TODO: Port to Visual Basic

// TESTS
// TODO: test of sizeof for all unit classes
// TODO: benchmark test for scalar_unit, comparing them to a float

// DOCUMENTATION (9)
// TODO: document the point of view of the library of when a dimension is considered "basic"
// TODO: document the ISOs important to use with this library
// TODO: document a little how to handle currency
// TODO: document that the pixel in dimension is only as length, not as a pixel on the screen as is in the pixel class
// TODO: document how ppm and ppb work, also in the theorical sense
// TODO: document an example of converting all currencies to money dimension, with different values. Use the currency abreviations of the ISO of currencies
// TODO: add nomenclature of units
// TODO: think if to add the functions of calculations or to add example of calculations in the documentation
// TODO: document the explanation of what each unit means, given the defintion of the SI or of the entity that corresponds to reference

// RELEASE (3)
// TODO: configure CMake with cpack
// TODO: see what to do to configure optimizations
// TODO: add scifir-units to the official repository of vcpkg

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
