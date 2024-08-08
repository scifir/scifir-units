# SCIFIR UNITS - VERSION 2

**Number of TODOs:** 264

## MATERIAL_VECTOR_UNIT (1)
- TODO: add operator == and operator !=

## TENSORS (4)
- TODO: add display functions without new lines and other equivalents with new lines, they should allow to display like the other units related to dimensions
- TODO: add operator*, cross_product(), dot_product(), hadamard_product()
- TODO: add a tensor_field inside fields
- TODO: store the vectors in tensor_unit as spherical coordinates

## TRAJECTORY AND PARAMETERIZATION (1)
- TODO: finish the trajectory_3d class

## WAVES (1)
- TODO: think if to add the waves here too

## CURRENT (28)
- TODO: document the light units somewhere
- TODO: zones must match that the type send corresponds to the data
- TODO: aid must match that the type send corresponds to the data
- TODO: initialize_from_string() should test for whitespace at the end both on aid and zid classes
- TODO: conversion of size_t to and int gives a warning in MSVC
- TODO: finish testing in Windows all tests
- TODO: support solid_angle, with the literal _sr too
- TODO: explanation, with code examples, of physics and chemistry laws
- TODO: there is a bug with is_close_prefix in base_display()
- TODO: add the system of units of origin and reason of why each dimension::type is present in the README.md file
- TODO: think if area and surface should be simple or composite dimensions
- TODO: explain the interpretation of dimensions inside scifir-units
- TODO: warning of to_string() functions of body.hpp
- TODO: explain how to use the tensors, instead of tensor_unit, inside the README.md file in concepts
- TODO: add the history of dimensions after preferences of use
- TODO: add the central inventions of each dimension, like the sundial, the waterclock, etc
- TODO: explain the current normal instruments of measure in the README.md file, and also that scifir-units is used for their electronic counterpart
- TODO: add the readings section here to other place

- TODO: maybe it's needed to change characters of the initialization strings of some vector_unit classes. It's needed to update the file README.md too with that
- TODO: think of how to implement conversions, do also the test of them
- TODO: support the conversion inside the display of scalar_unit
- TODO: add the old historic systems of units to conversion, and explain them in the README.md file
- TODO: add the conversions of the CGS system of units, and the FPS system of units
- TODO: add Farenheit, Rankine and maybe other dimensions of temperature as conversions
- TODO: check if the member-variable names of dimension class can be changed

- TODO: complex_number<> and lab_number<> should work with scalar_unit class as template parameter too, not only with their derived classes

- TODO: custom dimensions should allow to store their names too, not only their symbols

- TODO: display_double() and display_long_double() functions of types.cpp

- TODO: create percentage<double> and percentage<long double> with ppb, ppt and ppq. Create also the function is_long_percentage() to test for ppb, ppt and ppq

## BUGS AND SIMILAR PROBLEMS - HARD (3)
- TODO: check and correct all the warnings of cl.exe with /Wall
- TODO: -Wall gives a warning for vector_unit_nd with end of non-void function
- TODO: look at the 1.99 of test_coordinates_2d vs the 2 of the float specialization

## BUILD (2)
- TODO: support freebsd and openbsd
- TODO: upload the package to the container registry of github packages

## BUILD - ADVANCED (7)
- TODO: study bazel and look the files of bazel that are part of Catch2, maybe the same should be done for scifir-units
- TODO: see how to support consoles inside the building, if possible
- TODO: possibly add the library to conan
- TODO: test vcpkg.json uploading scifir-units to vcpkg
- TODO: check the welcome file for cpack, maybe it's useful
- TODO: support the compilation with Emscripten and add web-assembly as another preset more
- TODO: check the configuration options that exist for gcov

## IDE (2)
- TODO: check the extension gcov viewer is working properly
- TODO: configure ctest inside Visual Studio Code

## GITHUB (8)
- TODO: update the github action that updates the CHANGELOG.md file, make it work
- TODO: release the version 2.0-beta
- TODO: add the github action with windows
- TODO: add the github action with macos
- TODO: add try online badge
- TODO: add the release badge
- TODO: add the code coverage badge
- TODO: upload scifir-units to sourceforge too

## TESTS (7)
- TODO: finish the tests of all classes
- TODO: review get_nd() of the tests of vector_unit_nd and coordinates_nd
- TODO: verify that are present all functions of coordinates with rotations
- TODO: report the bug to CATCH of the use of bool()
- TODO: verify the titles of sections of tests of units, meca_number and special_units
- TODO: test of base unit classes
- TODO: test stof() with bad values

## DOCUMENTATION (49)
- TODO: create all the dox files of the library
- TODO: document the thinking behind the geographic coordinates of allowing to change planet. By default it's the Earth
- TODO: document the use of special characters in prefixes
- TODO: document the special character in angle class
- TODO: document what is a dimension, what is a derived dimension, and what is a basic dimension
- TODO: add the abbreviations in the groups too
- TODO: add latex to the factors of prefixes in prefix.dox
- TODO: document how the england and united states units work, which are different than the SI system of units
- TODO: resolve how to document the string representation of enum types
- TODO: explain in initialize_from_string() the use of this function. The explanation of the format of the initialization string should be inside the string constructor and the string assignment
- TODO: explain how to use the basic units apart from the scalar_unit class, it doesn't appears inside the reference of Doxygen
- TODO: in the README.md file add the explanation of the first thing to learn first, after that the rest of the library
- TODO: inside scalar_unit explain how basic unit work
- TODO: inside vector_unit classes explain how basic units of vector_unit classes work
- TODO: inside README.md file add the conversion of aid::type and zid::type in their explanation
- TODO: add the symbol of pi in the README.md file with the things to memorize
- TODO: add the explanation of the definition of each unit inside a file, including conversions
- TODO: document the imperial system of units (https:##en.wikipedia.org/wiki/Imperial_units)
- TODO: explain how a robot can calculate angles
- TODO: explain how to create lambda functions of mathematical functions with different parts, using if-else for that
- TODO: explain how to use mEq in the README.md file, in case of use

- TODO: desactivate the search engine in the doxyfile for the doxyfile of development, not the doxyfile of github pages
- TODO: maybe use two different files Doxyfile, one for master and one for gh-pages
- TODO: use a dev_doxyfile for the master branch without the search engine
- TODO: add google analytics to the website of scifir-units of github pages

- TODO: document the coordinates for the universe, publish that too as an standard inside scifir
- TODO: check what to do with the libraries of ISOs and document them inside the README.md file. If there isn't a library of ISOs, decide if to create one
- TODO: reference books related to the physics, chemistry, biology or math implemented
- TODO: explain the custom dimensions in the file README.md
- TODO: display as plain text the <T> inside the md file
- TODO: document the demonstration of why a number or a scalar unit divided by a vector should give a vector, explaining that it's the reverse as the multiplication
- TODO: add the BIPM to some part of the documentation, where it should be cited

- TODO: document the use of the custom_display "sci"
- TODO: think on the different cases of use of coordinates and document them, including the use of an origin
- TODO: mention the WGS in the part of coordinates
- TODO: document the use of fabs() and display() to compare values of units
- TODO: document the special initialization of mass and mole with percentage
- TODO: add initialization of lab_number<> inside README.md file

- TODO: add the summary sheet somewhere
- TODO: "Things to remember" section, which explains the use of the degree for vector_unit_nd instead of the other two cases, the use of fabs, the use of display that doesn't displays all decimals
- TODO: add a section of "Optional knowledge"

- TODO: formulas of physics related to units
- TODO: formulas of chemistry related to units
- TODO: formulas of biology related to units
- TODO: document how all the operations of scalars and vector units work mathematically, possibly use mathjax inside markdown to display formulas

- TODO: think if to add the help of Eclipse, and search if other IDEs use some help too
- TODO: decide if to generate documentation for man, and if so, explain that inside the README.md file
- TODO: document all the NEWS file

- TODO: write an specification of scifir-units to be implemented in any programming language. Write there too the generic method for writing bindings which is to maintain all function names and classnames equal, changing only their spelling to snake-case or camel-case as used in the programming language, and also document equivalencies like using static methods in Java inside a class instead of normal functions in C++.

## COORDINATES AND POINTS (5)
- TODO: add coordinates_3d::origin() to allow to initialize with an origin (another coordinates class of the same type), it's specially useful for geographic coordinates

- TODO: the case when the initialization string contains only the character ',', without a value, has to initialize to zero

- TODO: display functions of coordinates and point classes should allow to change dimensions for any case, with another function identical in name but with the argument of the string of dimensions
- TODO: all display functions of coordinates classes need an int argument to select number of decimals
- TODO: is_coordinates_1d(), is_coordinates_2d(), etc

## COORDINATES AND POINTS - FINISH GEOGRAPHIC COORDINATES (3)
- TODO: finish get_altitude(). Read about geographic coordinates and decide what to do in point_3d, point_nd, coordinates_3d and coordinates_nd
- TODO: add the construction with an string for geographic coordinates
- TODO: study the geographic coordinates deeply, and see if to add something more related to them

## VECTOR FIELDS (3)
- TODO: vector_field (it should operate with vector_units and maybe with scalar_units. With (x,y,z) it gives the respective vector). +, - and ^ with vector_field
- TODO: parsing of initialization strings of fields. Allow to declare variables that can be refered by name inside initialization strings of vector fields
- TODO: create magnetic_field class, and add the string literal _T to the README.md file

## PLOTTING (1)
- TODO: add functions that allow to use also matplot++ inside the library

## ALGEBRA (5)
- TODO: constructor with initialization string
- TODO: is_algebraic_expression() and is_algebraic_term() functions
- TODO: static variable storing scalar_units, scalar_fields, etc
- TODO: search if there's a library that displays equations inside the command-line with math format, with math glyphs
- TODO: to_latex() function that gives the algebraic_expression in latex format

## C++ (8)
- TODO: use constexpr and consteval to initialize units instantly, possibly use it in more parts of the code
- TODO: change the use of const-reference to value and std::move in constructors
- TODO: change the use of const-reference to value and std::move in other places
- TODO: use reference when instantiating variables and when it's not needed to instantiate by value inside the body of functions
- TODO: if size_t and other similar constants are intended to be used inside normal code
- TODO: replace boost::split by split of C++20
- TODO: check is string_view should be used as parameters
- TODO: use string_view to the enum functions

## CONSTANTS (1)
- TODO: maybe all constant values should be constexpr, and maybe there's a way to make them scalar_unit without needing to have all of them defined at the same time, because that sizes
- TODO: add the constants of astronomy

## DIMENSIONS (10)
- TODO: support the binary prefixes too
- TODO: function get_frequent_dimensions(), which are the frequent definitions (J is N*m, W is J/s, etc)

- TODO: test dimension class with MSVC for the uses of the special characters
- TODO: some dimensions like degree, radian and money shouldn't be allowed to have a prefix
- TODO: check the literal with e
- TODO: read the ISO 80000

- TODO: scalar_unit should have get_notdimensionless_base_dimensions() and notdimensionless_base_display()

- TODO: finish custom_basic dimensions, change names to CUSTOM_BASE_DIMENSION, CUSTOM_DERIVED_DIMENSION and CUSTOM_DERIVED_DIMENSION_FULL_SYMBOL
- TODO: finish the test of custom_basic dimensions and document them in the README.md file
- TODO: maybe is_complex_dimension() for cases were the the dimension is not a simple dimension

## CONVERSION (2)
- TODO: add the apothecaries system of units, maybe there are more systems to add
- TODO: possibly add the drop units

## UNITS (17)
- TODO: solve in some way the problem that vector_unit_3d needs different characters in Windows an inside Linux when initialized with strings
- TODO: allow to display in any conversion. By default it should always display in SI units, only if a conversion is expressly specified in the display functions the conversion is then the dimension that gets displayed
- TODO: check dimensions in all inheriting classes of scalar_unit and vector_unit, it's needed another constructor that checks them
- TODO: vector_unit_3d class maybe need the comparison operators with themselves
- TODO: use the PI of the std library
- TODO: function point_to() to a point and point_to() to a coordinate for vector_unit classes
- TODO: support the brackets inside is_scalar_unit(), is_complex() and is_lab_number()
- TODO: possibly add the light_scalar_unit class that allows operations with scalar_unit classes, which must contain only one dimension, not a vector<dimension>
- TODO: function to_latex() for dimensions and scalar_unit
- TODO: function that displays the scalar_unit as text, with the plural if the scalar_unit has a value greather than 1
- TODO: maybe change the SI constants to be a base unit instead of a long double
- TODO: maybe the dimension memo needs a base unit class
- TODO: think if to add functions of statistics here, check if there is a solution in other C++ libraries or if it is good to have them here
- TODO: follow the schema of numbers of the 22 General Conference on Weights and Measures. Check if there are more rules to add of the General Conferences, too

- TODO: Regex that checks all the invalid dimensions initialization inside a static_assert (create a static function of valid_initialization_string()). Maybe try first by undefining the value if there's something that doesn't exist (with an else). It's possible to test, with static_assert, that dimension == nullptr, abbreviation == nullptr and conversion == nullptr
- TODO: Detect when there's the same dimension at the numerator and at the denominator of the string initialization

- TODO: make scalar_unit a template class converting the default type of the value member-variable to float type. Change the derived units to template classes too, and also all vector_units. Change the macro that defines derived units to be only the macro with HPP and use it in all derived_unit files

## DERIVED UNITS (6)
- TODO: think if to add accoustic and matter derived units, or if it's not needed
- TODO: delete all field classes that currently are vector_units, and make them fields
- TODO: think if to add another concentration class, the previous one has been deprecated
- TODO: move cas_number to the library of scifir-info, or even to another category
- TODO: biology units, like heart_rate
- TODO: UNIX time constructor in the string constructor for time_duration

## MECA NUMBERS (8)
- TODO: add the allowed typenames to lab_number, and don't accept any other type
- TODO: angle should read initialization strings in radian too inside the string constructor, maybe with "radian" name, possibly "rad" should be supported too
- TODO: maybe add obtusangle, rect angle, acutangle, etc
- TODO: study if to add the gradian
- TODO: study if to add the turn
- TODO: think if to add minute and second to angle
- TODO: maybe support prefixes for radians, search if there are prefixes for the other units of angles
- TODO: add minutes and seconds to degrees

## SPECIAL UNITS - EXTRA (14)
- TODO: ip class? check networking libraries of C++ and decide if to add it here
- TODO: nutrition_information
- TODO: class for geographical position including ZID and coordinates_3d
- TODO: class for geographical position in space, using AID and coordinates_3d
- TODO: maybe pixel should be called pixel_length
- TODO: think if to add a default case for the none value of aid and for the none value of zid
- TODO: functions is_aid() and is_zid()
- TODO: initialize_from_string() for pH and pOH classes should work with pH and pOH at the start, respectively
- TODO: maybe add zoom class, which allows to work with zooms
- TODO: _percentage literal
- TODO: address class with zid inside
- TODO: enum of movement maybe should be divided in kind of animal
- TODO: display() function for pixel class
- TODO: maybe delete the operator = T of percentage class, maybe there are more in similar classes. Try first the different literals of non-floating numeric types

## EMOTIONAL UNITS (1)
- TODO: finish the enums of mind.hpp

## SPECIAL UNITS (4)
- TODO: complete color class like coordinate classes, with all the getters of all the different color versions, like get_h(), get_s(), get_v()
- TODO: pixel_color<>. Use monochrome_pixel, truecolor_pixel, etc, as typedefs of pixel_color<>
- TODO: complex_number<> should have trigonometric functions for complex numbers
- TODO: maybe create a mesh_3d class, or vector<point_3d<>>

## PREDEFINED PHYSICS UNITS (4)
- TODO: electric_field which calculates based on coulomb charges
- TODO: gravity_field
- TODO: possibly magnetic_field?
- TODO: electric_current?

## CONTROL VOLUME (1)
- TODO: think what to do with the control_volume

## UNITS - ADVANCED (9)
- TODO: sqrt() and pow() maybe should be direct for created units, instead of passing by scalar_unit again to initialize after that the other unit
- TODO: check if it's needed to add a function is_si_basic_dimension() that gives whether the dimension is basic or not in the sense of the SI system of units
- TODO: support and UTF32 string constructor for scalar_unit in order to allow to create dimensions directly with some Unicode characters that are not present in UTF8
- TODO: scalar_unit should have is_valid() with some system
- TODO: support the conversions with constexpr
- TODO: add the operators +,-,* and / in the derived classes of scalar_unit and vector_unit with the same class in order to avoid to check that the dimensions are the same, that saves time
- TODO: check the object code resulting by testing different functions of the unit classes
- TODO: 2d display of scalar_units and of vector_units (create a scifir_units_2d library for it)
- TODO: 3d display of scalar_units and of vector_units (create a scifir_units_3d library for it)

## UNITS - ADVANCED - REDUCTION OF MEMORY CONSUMPTION (4 options)
- OPTION 1: maybe delete the dimensions member-variable of scalar_unit, and use instead another system for handling prefixes. The dimensions can be automatic based on their class. One possibility is to use an empty array and, when it's empty, to send the fixed dimensions of the class instead, and only when changing something to add the dimensions there
- OPTION 2: divide single dimensions unit of multiple-dimensions unit by adding only one dimension instead of the vector<dimension>
- OPTION 3: maybe the prefix and the dimension can be removed as member-variables if displaying automatically in some way or another, as it's expressly specified. That is maybe the biggest optimization possible
- OPTION 4: light_length which uses only an enum of prefixes and a value, maybe it should be called length, and length should be called full_length
- OPTION 4 - add const to the enum of light_unit
- AFTER SOME OPTION - finish initial_dimensions_get_structure() and get_dimensions_match() related to the new implementation

## DOUBTS (1)
- TODO: maybe delete the string literals of the prefixes of AU, leave only the string literal without prefix

## ANOTHER PROJECT - LIBRARY OF INFORMATION (2)
- TODO: isbn class
- TODO: issn class

## ISOs (4)
- TODO: Publish the ISO of geographic location based on aid and zid classes
- TODO: See if to make an ISO of an official symbol for money (not a concrete money of a country, but a universal one)
- TODO: Add "depth" to an ISO of names for the lengths of objects (width, height and depth are the names). It's needed to have a name in spanish for the depth too
- TODO: Maybe create an "ISO" of geographic positioning taking the major axis of the planet, which can be the Earth or not, and adding 50 km to it, in order to have a border of safety in order to be sure that no point remains uncovered by the imaginary sphere that the geographic positioning creates around the planet. It can be used for any planet of the universe. The center of the planet is considered always the geometrical one, not the center of mass, because that last one changes with changes of the distribution of mass inside the planet

## ISO C++ (3)
- TODO: add º to the string literals
- TODO: add % to the string literals
- TODO: add the possibility to create class names starting with numbers

## ELECTRONICS (1)
- TODO: check sensor libraries and decide which ones to support inside scifir-units (maybe in a new scifir library if needed)

## PATTERNS (1)
- TODO: possibly implement a pattern class using a regular expressions library

## EXTRA TOOLS (1)
- TODO: Create scicalcs, a cli tool that calculates with scifir-units any value

## PORTS (4)
- TODO: Port to C#
- TODO: Port to Java
- TODO: Port to Octave
- TODO: Port to Visual Basic

## TESTS (2)
- TODO: test of sizeof for all unit classes
- TODO: benchmark test for scalar_unit, comparing them to a float

## DOCUMENTATION (5)
- TODO: document the ISOs important to use with this library
- TODO: document how ppm and ppb work, also in the theorical sense
- TODO: document an example of converting all currencies to money dimension, with different values. Use the currency abreviations of the ISO of currencies
- TODO: add nomenclature of units
- TODO: think if to add the functions of calculations or to add example of calculations in the documentation

## RELEASE (3)
- TODO: configure CMake with cpack
- TODO: see what to do to configure optimizations
- TODO: add scifir-units to the official repository of vcpkg

## MATRIX (6)
- TODO: See if it's best to use template arguments for row and column or if to store those values as member-variables
- TODO: Multiplication of matrices of different but compatible types
- TODO: typecast to other matrix-classes of important libraries
- TODO: Iterator with range to use only one range-for
- TODO: Check limits of matrices for all operators
- TODO: Use the GSL to implement the reverse matrix

## FUTURE (9)
- TODO: support the case of n dimensions fixed
- TODO: add the theta and phi characters to C++ variable names, and add them then to the member-variables of vector_unit classes, and any other case of similar use. Add the symbol º to string literals
- TODO: add the astronomy coordinates
- TODO: add the other orthogonal coordinates, like paraboloidal
- TODO: add to the ISO of the keyboards some system to write pi, theta, phi, among other symbols, with the keyboard in an easy way, without having to memorize any numeric code
- TODO: propose an ISO symbol for money in general?
- TODO: finish the empty array implementation for dimension, in order to have normal dimensions, no custom dimensions, of size 3 instead of size 6
- TODO: add the symbol '%' to the string literals
- TODO: add the symbol 'μ' to the string literals

## FUTURE - MECA NUMBERS (POSSIBLE, THINK) (8)
- TODO: Add names to the meca numbers (angler, laber, etc)
- TODO: The interval number class
- TODO: The interval number subclasses of other numbers
- TODO: The bounce number class
- TODO: The percentage number class (it has to have the calculate function in order to receive a value to be the percentage of)
- TODO: Solve the problem with left and right repeated (it's not exclusive for direction_symbol)
- TODO: solid_angle class (maybe it isn't a meca number)
- TODO: maybe _angle for angle in order to use cos(x),sin(x),etc with degrees

## READINGS
- Unit of measurement: https:##en.wikipedia.org/wiki/Unit_of_measurement
- International system of units: https:##en.wikipedia.org/wiki/International_System_of_Units
- Angle: https:##en.wikipedia.org/wiki/Angle
- Metrology: https:##en.wikipedia.org/wiki/Metrology
- Color: https:##en.wikipedia.org/wiki/Color
- RGB color model: https:##en.wikipedia.org/wiki/RGB_color_model
- Color model: https:##en.wikipedia.org/wiki/Color_model
- Unit prefix: https:##en.wikipedia.org/wiki/Unit_prefix
- Metric prefix: https:##en.wikipedia.org/wiki/Metric_prefix
- Euclidean space: https:##en.wikipedia.org/wiki/Euclidean_space
- Radian: https:##en.wikipedia.org/wiki/Radian