# SCIFIR UNITS - VERSION 2

**Number of TODOs:** 195
**Number of TODOs to release version 2:** 37

## POSSIBLE OR MANDATORY READINGS (1)

- TODO: read the ISO 80000 (mandatory)

## CURRENT (9)

- TODO**: fuse to_string() and display() in lots of cases
- TODO: conversion of size_t to and int gives a warning in MSVC
- TODO: finish testing in MSVC all tests
- TODO: solid_angle class, with the literal "_sr" too
- TODO: explanation, with code examples, of physics and chemistry laws
- TODO: there is a bug with is_close_prefix in base_display()
- TODO: solve the bug of scalar_unit with operator ^

- TODO: custom dimensions should allow to store their names too, not only their symbols

- TODO: display_double() and display_long_double() functions of types.cpp

- TODO: create percentage\<double\> and percentage\<long double\> with ppb, ppt and ppq. Create also the function is_long_percentage() to test for ppb, ppt and ppq

## BUGS AND SIMILAR PROBLEMS - HARD (3)

- TODO: check and correct all the warnings of cl.exe with /Wall
- TODO: -Wall gives a warning for vector_unit_nd with end of non-void function
- TODO: look at the 1.99 of test_coordinates_2d vs the 2 of the float specialization

## BUILD (1)

- TODO: support freebsd and openbsd

## BUILD - ADVANCED (7)

- TODO: study bazel and look the files of bazel that are part of Catch2, maybe the same should be done for scifir-units
- TODO: see how to support some consoles inside the building, if possible
- TODO: possibly add the library to conan
- TODO: test vcpkg.json uploading scifir-units to vcpkg
- TODO: check the welcome file for cpack, maybe it's useful
- TODO: support the compilation with Emscripten and add web-assembly as another preset more
- TODO: check the configuration options that exist for gcov

## IDE (1)

- TODO: check the extension gcov viewer is working properly

## DEPLOY - GITHUB AND OTHERS (9)

- TODO: update the github action that updates the CHANGELOG.md file, make it work
- TODO: release the version 2.0-beta
- TODO: add the github action with windows
- TODO: add the github action with macos
- TODO: add try online badge
- TODO: add the release badge
- TODO: add the code coverage badge
- TODO: upload scifir-units to sourceforge too
- TODO: upload the package to the container registry of github packages

## RELEASE (5)

- TODO: publish scifir-units, beta version, in Universidad de Chile
- TODO: see other repositories of universities where scifir-units can be published
- TODO: see what to do to configure optimizations
- TODO: add scifir-units to the official repository of vcpkg
- TODO: add google analytics to the github pages of scifir-units

## TESTS (6)

- TODO: finish the tests of all classes
- TODO: review get_nd() of the tests of vector_unit_nd and coordinates_nd
- TODO: verify that are present all functions of coordinates with rotations
- TODO: report the bug to CATCH of the use of bool()
- TODO: test of base unit classes
- TODO: test stof() with bad values

## DOCUMENTATION (32)

### DOCUMENTATION - DOXYGEN (7)

- TODO: create all the dox files of the library
- TODO: add latex to the factors of prefixes in prefix.dox
- TODO: explain in initialize_from_string() the use of this function. The explanation of the format of the initialization string should be inside the string constructor and the string assignment
- TODO: add the description of each file, which is different than the description of the class
- TODO: add in some way or another the base and the derived units to the reference
- TODO: think if to add the help of Eclipse, and search if other IDEs use some help too
- TODO: decide if to generate documentation for man, and if so, explain that inside the README.md file

### DOCUMENTATION - README (14)

- TODO: inside README.md file add the conversion of aid::type and zid::type in their explanation
- TODO: think on the different cases of use of coordinates and document them, including the use of an origin
- TODO: document the coordinates for the universe, publish that too as an standard inside scifir
- TODO: mention the WGS in the part of coordinates
- TODO: explain how digital geographic coordinates work, that are like a giant globe around the digital world the characters are in

- TODO: explain some normal code examples of robotics, medical machines, chemistry machines
- TODO: add an example of fluiddynamics with scifir-geometry for robotics applications
- TODO: describe in detail how to measure in very small scale for each different base unit
- TODO: add a system of surface parameterization of the human body

- TODO: add to the README.md file an example for creating new unit classes with the macros for them
- TODO: check what to do with the programming libraries of ISOs and document them inside the README.md file. If there isn't a programming library of ISOs, decide if to create one
- TODO: add initialization of lab_number<> inside README.md file
- TODO: common use cases of each dimension, like eV is for quantum purposes, pc for space travel, etc
- TODO: create a file giving a complete example of scalar_unit in java version, in order to provide an example of portability to java that can be used both for java and for any other programming language following the rules of portability documented in the README, written all ScalarUnit methods and parameters

### DOCUMENTATION - DOXYGEN PAGES (10)

- TODO: add the abbreviations in the groups too
- TODO: add the explanation of the definition of each unit inside a file, including conversions
- TODO: document how ppm and ppb work, also in the theorical sense
- TODO: explain the apotechary system, the english units, the imperial units and the united states units in a separate page. Explain them in the part of conversion inside the README.md file too
- TODO: add the summary sheet somewhere
- TODO: formulas of physics related to units, with code examples
- TODO: formulas of chemistry related to units, with code examples
- TODO: formulas of biology related to units, with code examples
- TODO: document how all the operations of scalars and vector units work mathematically, possibly use mathjax inside markdown to display formulas
- TODO: document the demonstration of why a number or a scalar unit divided by a vector should give a vector, explaining that it's the reverse as the multiplication

### DOCUMENTATION - OTHERS (2)

- TODO: document all the NEWS file
- TODO: write an specification of scifir-units to be implemented in any programming language. Write there too the generic method for writing bindings which is to maintain all function names and classnames equal, changing only their spelling to snake-case or camel-case as used in the programming language, and also document equivalencies like using static methods in Java inside a class instead of normal functions in C++.

## C++ (10)

- TODO*: change the use of const-reference to value and std::move in constructors
- TODO*: change the use of const-reference to value and std::move in other places
- TODO: use reference when instantiating variables and when it's not needed to instantiate by value inside the body of functions
- TODO: if size_t and other similar constants are intended to be used inside normal code
- TODO: replace boost::split by split of C++20
- TODO: check where string_view should be used as parameter instead of string
- TODO: use string_view to the enum functions
- TODO: use constexpr and consteval to initialize units instantly, possibly use it in more parts of the code
- TODO: use << directly with strings in replacement of ostringstream
- TODO: maybe the operator + of scifir-units classes with strings aren't needed in favor of the use of operator <<

## CONSTANTS (3)

- TODO: add the constants of astronomy
- TODO: maybe all constant values should be constexpr, and maybe there's a way to make them scalar_unit without needing to have all of them defined at the same time, because that sizes
- TODO: add in the comments of constants.hpp their dimensions

## PREFIX (1)

- TODO: convert prefix class to a literal type

## DIMENSIONS (10)

- TODO*: some dimensions like degree, radian and money shouldn't be allowed to have a prefix
- TODO*: test dimension class with MSVC for the uses of the special characters
- TODO*: finish custom_basic dimensions, change values of enum::type to CUSTOM_BASE_DIMENSION, CUSTOM_DERIVED_DIMENSION and CUSTOM_DERIVED_DIMENSION_FULL_SYMBOL, respectively
- TODO*: finish the test of custom_basic dimensions and document them in the README.md file
- TODO*: add the Gaussian units
- TODO*: solve the error of custom dimensions in some way

- TODO: function get_frequent_dimensions(), which are the frequent definitions (J is N*m, W is J/s, etc)
- TODO: support the binary prefixes too
- TODO: scalar_unit should have get_notdimensionless_base_dimensions() and notdimensionless_base_display()

- TODO: add the atomic units (add them with the dimension value ATOMIC_UNIT and a tag)

## CONVERSION (9)

- TODO*: allow to display in any conversion. By default it should always display in SI units, only if a conversion is expressly specified in the display functions the conversion is then the dimension that gets displayed
- TODO*: add the conversions of the CGS system of units, and the FPS system of units
- TODO*: add Farenheit, Rankine and maybe other dimensions of temperature as conversions, finish the inline conversion functions first

- TODO: possibly add the drop units
- TODO: possibly add the metric horsepower too
- TODO: decide something to do with the US customary units of dry volume pint, quart and gallon, which have different values than those same units of measurement for fluids, maybe it's needed to define two different customary units with similar names
- TODO: add the chinese units of measurement as conversions
- TODO: add the apothecaries system of units, maybe there are more systems to add
- TODO: add the old historic systems of units to conversion, and explain them in the README.md file

## UNITS (10)

- TODO*: template functions is_scalar_unit<>,is_vector_unit_2d<>,is_vector_unit_3d<>,is_vector_unit_nd<>
- TODO*: support the brackets inside is_complex_number() and is_lab_number()
- TODO*: contains_dimensions() to test if some dimensions are present, but not if those dimensions are the only ones present
- TODO*: to_dimensions("") function

- TODO: is_number(), is_integer_number(), is_decimal_number()
- TODO: function point_to() to a point and point_to() to a coordinate for vector_unit classes
- TODO: think if to add functions of statistics here, check if there is a solution in other C++ libraries or if it is good to have them here
- TODO: follow the schema of numbers of the 22 General Conference on Weights and Measures. Check if there are more rules to add of the General Conferences, too

- TODO: function that displays the scalar_unit as text, with the plural if the scalar_unit has a value greather than 1

- TODO: detect when there's the same dimension at the numerator and at the denominator of the string initialization
- TODO: regex that checks all the invalid dimensions initialization inside a static_assert (create a static function of valid_initialization_string()). Maybe try first by undefining the value if there's something that doesn't exist (with an else). It's possible to test, with static_assert, that dimension == nullptr, abbreviation == nullptr and conversion == nullptr

## BASE UNITS (3)

- TODO: coordinates_1d<>, without the bug of constructors, should initialize inside the string initialization without scalar_unit first
- TODO: functions like get_mass(molecular_weight,density) in mole class and get_moles(molecular_weight,density) in mass class but normal functions, inside chemistry
- TODO: perfect_mole class, maybe inheriting mole class, that allows to store moles and also add or substract by an integer number of molecules, not only by mole. Another option is to just extend the mole class, instead of creating a new class

## DERIVED UNITS (5)

- TODO*: delete all field classes that currently are vector_units, and make them fields
- TODO*: add a function to calculate with mEq inside a child class that uses them
- TODO*: maybe a way to have "tags" in mEq and money classes would work to have it of specific instead of generic purpose, that should be only in mEq and money classes
- TODO: biology units, like heart_rate, respiration_rate
- TODO: UNIX time constructor in the string constructor for time_duration

## MATRIX (7)

- TODO*: see if it's best to use template arguments for row and column or if to store those values as member-variables
- TODO*: use | character as separation for columns, use newlines to separate rows, don't accept another format for the data of the matrix in string form
- TODO*: iterator with range to use only one range-for
- TODO*: check limits of matrices for all operators
- TODO*: add the hadamard_product()

- TODO: typecast to other matrix-classes of important libraries
- TODO: use the GSL to implement the reverse matrix

## MECA NUMBERS (3)

- TODO*: add the allowed typenames to lab_number, and don't accept any other type
- TODO: complex_number<> should have trigonometric functions for complex numbers
- TODO: think if to add microdegrees and millidegrees

## SPECIAL UNITS (10)

- TODO*: constructors of zid class should be updated to follow the constructors of aid class
- TODO*: functions is_aid() and is_zid()
- TODO: maybe add zoom class, which allows to work with zooms

- TODO: change body and mind to biology, and pH and pOH to chemistry
- TODO: nutrition_information
- TODO: complete color class like coordinate classes, with all the getters of all the different color versions, like get_h(), get_s(), get_v()
- TODO: enum of movement maybe should be divided in kind of animal
- TODO: maybe delete the operator = T of percentage class, maybe there are more in similar classes. Try first the different literals of non-floating numeric types
- TODO: pixel_color<>. Use monochrome_pixel, truecolor_pixel, etc, as typedefs of pixel_color<>
- TODO: maybe create a mesh_3d class, or vector<coordinates_3d<>>

## COORDINATES (7)

- TODO*: add a constructor with the different types of coordinates systems with an enum at the start, like the constructor with enum of percentage class
- TODO*: all display functions of coordinates classes need an int argument to select number of decimals
- TODO*: is_coordinates_1d(), is_coordinates_2d(), etc

- TODO: to_vector_unit_3d(), to_vector_unit_2d(), respectively, to each coordinates class
- TODO: display functions of coordinates classes should allow to change dimensions for any case, with another function identical in name but with the argument of the string of dimensions
- TODO: add minutes and seconds to degrees for latitude and longitude, document that minutes and seconds are not for degrees of angles, add the function to convert degrees to sexagesimal degrees, returning a struct
- TODO: possibly add the enum to latitude and longitude of DEGREE and SEXAGESIMAL_DEGREE values

## COORDINATES - GEOGRAPHIC COORDINATES (7)

- TODO*: string constructor for astronomical_coordinates
- TODO*: string constructor for zone_coordinates
- TODO*: get_altitude() can be two different functions
- TODO*: add display functions for astronomical_coordinates_3d, with "name ()" for planetary, "Orbit of name ()" for orbital, "name ()" or "Inside name ()" for stellar, "name ()" for central galactic
- TODO*: add the ecliptic coordinates system inside the astronomical_coordinates_3d
- TODO*: add the variant of the ecliptic coordinates system with a selection of the planet or of the params (which is the generic case)

- TODO: add the observation_coordinates class and the observation_altitude class for telescope measurements, add observation_azimuth too

## MATERIAL_VECTOR_UNIT (1)

- TODO*: add operator == and operator !=
- TODO*: finish material_vector_unit_2d class and the material_vector_unit_3d and material_vector_unit_nd classes

## TRAJECTORY AND PARAMETERIZATION (1)

- TODO*: finish the trajectory_3d class
- TODO*: finish the trajectory classes

## WAVES (2)

- TODO: add an enum of the types of radio waves AM and FM
- TODO: wave class with frequency and wavelength scalar_units, with child classes wave_2d and wave_3d that include coordinates_2dr and coordinates_3dr respectively. It can calculate the speed with the frequency and the wavelength, it returns the type of wave based on the value of the frequency

## PHYSICS - PREDEFINED UNITS (4)

- TODO: electric_field which calculates based on coulomb charges
- TODO: gravity_field
- TODO: possibly magnetic_field?
- TODO: electric_current?

## PHYSICS (3)

- TODO: add functions of movement
- TODO: add functions of gravity
- TODO: add functions of electricity

## ASTRONOMY (1)

- TODO: possibly add the masses of common astronomical objects

## CONTROL VOLUME (1)

- TODO: think what to do with the control_volume

## VECTOR FIELDS (3)

- TODO: vector_field (it should operate with vector_units and maybe with scalar_units. With (x,y,z) it gives the respective vector). +, - and ^ with vector_field
- TODO: parsing of initialization strings of fields. Allow to declare variables that can be refered by name inside initialization strings of vector fields
- TODO: create magnetic_field class, and add the string literal "_T" to the README.md file

## ALGEBRA (5)

- TODO: constructor with initialization string
- TODO: is_algebraic_expression() and is_algebraic_term() functions
- TODO: static variable storing scalar_units, scalar_fields, etc
- TODO: search if there's a library that displays equations inside the command-line with math format, with math glyphs
- TODO: to_latex() function that gives the algebraic_expression in latex format

## POSSIBLE - PLOTTING (1)

- TODO: add functions that allow to use also matplot++ inside the library

## UNITS - ADVANCED (7)

- TODO: sqrt() and pow() maybe should be direct for created units, instead of passing by scalar_unit again to initialize after that the other unit
- TODO: scalar_unit should have is_valid() with some system
- TODO: support the conversions with constexpr
- TODO: add the operators +,-,* and / in the derived classes of scalar_unit and vector_unit with the same class in order to avoid to check that the dimensions are the same, that saves time. Maybe use templates for that
- TODO: check the object code resulting by testing different functions of the unit classes, maybe it's possible to optimize assembler there
- TODO: 2d display of scalar_units and of vector_units (create a scifir_units_2d library for it)
- TODO: 3d display of scalar_units and of vector_units (create a scifir_units_3d library for it)

## UNITS - ADVANCED - REDUCTION OF MEMORY CONSUMPTION (4 options)

- OPTION 1: maybe delete the dimensions member-variable of scalar_unit, and use instead another system for handling prefixes. The dimensions can be automatic based on their class. One possibility is to use an empty array and, when it's empty, to send the fixed dimensions of the class instead, and only when changing something to add the dimensions there
- OPTION 2: divide single dimensions unit of multiple-dimensions unit by adding only one dimension instead of the vector\<dimension\>
- OPTION 3: maybe the prefix and the dimension can be removed as member-variables if displaying automatically in some way or another, as it's expressly specified, in each different class that inherits scalar_unit (excepting vector unit classes). That is maybe the biggest optimization possible
- OPTION 4: light_length which uses only an enum of prefixes and a value, maybe it should be called length, and length should be called full_length
- OPTION 4 - add const to the enum of light_unit
- AFTER SOME OPTION - finish initial_dimensions_get_structure() and get_dimensions_match() related to the new implementation

## POSSIBLE - ISO C++ (1)

- TODO: add the possibility to create class names starting with numbers

## POSSIBLE - TENSORS (1)

- TODO: check if there's something needed related to tensors, given that scalar_unit, vector_unit and matrix are being used already

## POSSIBLE - ELECTRONICS (1)

- TODO: check sensor libraries and decide which ones to support inside scifir-units (maybe in a new scifir library if needed)

## POSSIBLE - EXTRA TOOLS (1)

- TODO: Create scicalcs, a cli tool that calculates with scifir-units any value

## FUTURE (5)

- TODO: support the case of n dimensions fixed
- TODO: add the other orthogonal coordinates, like paraboloidal
- TODO: add to the ISO of the keyboards some system to write pi, theta, phi, among other symbols, with the keyboard in an easy way, without having to memorize any numeric code
- TODO: finish the empty array implementation for dimension, in order to have normal dimensions, no custom dimensions, of size 3 instead of size 6
- TODO: make scalar_unit a template class converting the default type of the value member-variable to float type, allowing to use then double or long double there too if it's needed to have more precision. Change the derived units to template classes too, and also all vector_units. Change the macro that defines derived units to be only the macro with HPP and use it in all derived_unit files (don't add this feature if C++ is not supporting template classes without <>, because otherwise the base syntax of the library is changing too much)

## FUTURE - MECA NUMBERS (POSSIBLE, THINK) (5)

- TODO: Add names to the meca numbers (angler, laber, etc)
- TODO: The interval number class
- TODO: The interval number subclasses of other numbers
- TODO: The bounce number class
- TODO: Solve the problem with left and right repeated (it's not exclusive for direction_symbol)

## ISOs

- TODO: Publish the ISO of geographic location based on aid and zid classes
- TODO: See if to make an ISO of an official symbol for money (not a concrete money of a country, but a universal one)
- TODO: Add "depth" to an ISO of names for the lengths of objects (width, height and depth are the names). It's needed to have a name in spanish for the depth too
- TODO: Maybe create an "ISO" of geographic positioning taking the major axis of the planet, which can be the Earth or not, and adding 50 km to it, in order to have a border of safety in order to be sure that no point remains uncovered by the imaginary sphere that the geographic positioning creates around the planet. It can be used for any planet of the universe. The center of the planet is considered always the geometrical one, not the center of mass, because that last one changes with changes of the distribution of mass inside the planet

## PORTS

- TODO: Port to C#
- TODO: Port to Java
- TODO: Port to Octave
- TODO: Port to Visual Basic
- TODO: Possibly port to JavaScript

## ANOTHER PROJECT - LIBRARY OF ROBOTICS

- TODO: body classes

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
- Metre Convention: [https://en.wikipedia.org/wiki/Metre_Convention](https://en.wikipedia.org/wiki/Metre_Convention)
