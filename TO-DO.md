# SCIFIR UNITS - VERSION 2

**Number of TODOs:** 229

## MATERIAL_VECTOR_UNIT (1)

- TODO: add operator == and operator !=

## TRAJECTORY AND PARAMETERIZATION (1)

- TODO: finish the trajectory_3d class

## WAVES (2)

- TODO: add an enum of the types of radio waves AM and FM
- TODO: wave class with frequency and wavelength scalar_units, with child classes wave_2d and wave_3d that include coordinates_2dr and coordinates_3dr respectively. It can calculate the speed with the frequency and the wavelength, it returns the type of wave based on the value of the frequency

## CURRENT (18)

- TODO: conversion of size_t to and int gives a warning in MSVC
- TODO: finish testing in MSVC all tests
- TODO: solid_angle class, with the literal "_sr" too
- TODO: explanation, with code examples, of physics and chemistry laws
- TODO: there is a bug with is_close_prefix in base_display()
- TODO: warning of to_string() functions of body.hpp
- TODO: change the default of display() to be of all decimals instead of two
- TODO: apparently units.hpp should have the #include directives with ./ at the start

- TODO: think of how to implement conversions, do also the test of them
- TODO: support the conversion inside the display of scalar_unit
- TODO: add the old historic systems of units to conversion, and explain them in the README.md file
- TODO: add the conversions of the CGS system of units, and the FPS system of units
- TODO: add Farenheit, Rankine and maybe other dimensions of temperature as conversions
- TODO: check if the member-variable names of dimension class can be changed

- TODO: complex_number<> and lab_number<> should work with scalar_unit class as template parameter too, not only with their child classes

- TODO: custom dimensions should allow to store their names too, not only their symbols

- TODO: display_double() and display_long_double() functions of types.cpp

- TODO: create percentage\<double\> and percentage\<long double\> with ppb, ppt and ppq. Create also the function is_long_percentage() to test for ppb, ppt and ppq

## BUGS AND SIMILAR PROBLEMS - HARD (3)

- TODO: check and correct all the warnings of cl.exe with /Wall
- TODO: -Wall gives a warning for vector_unit_nd with end of non-void function
- TODO: look at the 1.99 of test_coordinates_2d vs the 2 of the float specialization

## BUILD (2)

- TODO: support freebsd and openbsd
- TODO: upload the package to the container registry of github packages

## BUILD - ADVANCED (7)

- TODO: study bazel and look the files of bazel that are part of Catch2, maybe the same should be done for scifir-units
- TODO: see how to support some consoles inside the building, if possible
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

## RELEASE (4)

- TODO: publish scifir-units, beta version, in Universidad de Chile
- TODO: see other repositories of universities where scifir-units can be published
- TODO: see what to do to configure optimizations
- TODO: add scifir-units to the official repository of vcpkg

## TESTS (7)

- TODO: finish the tests of all classes
- TODO: review get_nd() of the tests of vector_unit_nd and coordinates_nd
- TODO: verify that are present all functions of coordinates with rotations
- TODO: report the bug to CATCH of the use of bool()
- TODO: verify the titles of sections of tests of units, meca_number and special_units
- TODO: test of base unit classes
- TODO: test stof() with bad values

## DOCUMENTATION (36)

- TODO: create all the dox files of the library
- TODO: add latex to the factors of prefixes in prefix.dox
- TODO: explain in initialize_from_string() the use of this function. The explanation of the format of the initialization string should be inside the string constructor and the string assignment
- TODO: add the description of each file, which is different than the description of the class
- TODO: add in some way or another the base and the derived units to the reference

- TODO: add in the table of contents a link to each documentation of class
- TODO: add an example of fluiddynamics with scifir-geometry for robotics applications
- TODO: explain some normal code examples of robotics, medical machines, chemistry machines
- TODO: increase the introduction of the README.md file
- TODO: add initialization of lab_number<> inside README.md file
- TODO: inside README.md file add the conversion of aid::type and zid::type in their explanation
- TODO: add a readings section in the README.md file, with some of the urls of the TODO.md file
- TODO: add to the README.md file an example for creating new unit classes with the macros for them
- TODO: think on the different cases of use of coordinates and document them, including the use of an origin
- TODO: document the thinking behind the geographic coordinates of allowing to change planet. By default it's the Earth
- TODO: document the coordinates for the universe, publish that too as an standard inside scifir
- TODO: mention the WGS in the part of coordinates
- TODO: add a section of "Optional knowledge"
- TODO: add a system of surface parameterization of the human body
- TODO: describe in detail how to measure in very small scale for each different base unit

- TODO: add google analytics to the website of scifir-units of github pages

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

- TODO: check what to do with the libraries of ISOs and document them inside the README.md file. If there isn't a library of ISOs, decide if to create one
- TODO: reference books related to the physics, chemistry, biology or math implemented

- TODO: think if to add the help of Eclipse, and search if other IDEs use some help too
- TODO: decide if to generate documentation for man, and if so, explain that inside the README.md file
- TODO: document all the NEWS file

- TODO: write an specification of scifir-units to be implemented in any programming language. Write there too the generic method for writing bindings which is to maintain all function names and classnames equal, changing only their spelling to snake-case or camel-case as used in the programming language, and also document equivalencies like using static methods in Java inside a class instead of normal functions in C++.

## COORDINATES AND POINTS (8)

- TODO: add coordinates_3d::origin() to allow to initialize with an origin (another coordinates class of the same type), it's specially useful for geographic coordinates

- TODO: the case when the initialization string contains only the character ',', without a value, has to initialize to zero

- TODO: display functions of coordinates and point classes should allow to change dimensions for any case, with another function identical in name but with the argument of the string of dimensions
- TODO: all display functions of coordinates classes need an int argument to select number of decimals
- TODO: is_coordinates_1d(), is_coordinates_2d(), etc
- TODO: to_vector_unit_3d(), to_vector_unit_2d(), respectively, to each coordinates and point class
- TODO: add a constructor with the different types of coordinates systems with an enum at the start, like the constructor with enum of percentage class
- TODO: enum of cardinale points

## COORDINATES AND POINTS - FINISH GEOGRAPHIC COORDINATES (7)

- TODO: finish get_altitude(). Read about geographic coordinates and decide what to do in point_3d, point_nd, coordinates_3d and coordinates_nd
- TODO: add the construction with an string for geographic coordinates
- TODO: study the geographic coordinates deeply, and see if to add something more related to them
- TODO: get_altitude() can be two different functions
- TODO: add the ecliptic coordinates system too
- TODO: add the variant of the ecliptic coordinates system with a selection of the planet or of the params (which is the generic case)
- TODO: add display functions for astronomical_coordinates_3d, with "name ()" for planetary, "Orbit of name ()" for orbital, "name ()" or "Inside name ()" for stellar, "name ()" for central galactic

## PHYSICS UNITS (3)

- TODO: add functions of movement
- TODO: add functions of gravity
- TODO: add functions of electricity

## VECTOR FIELDS (3)

- TODO: vector_field (it should operate with vector_units and maybe with scalar_units. With (x,y,z) it gives the respective vector). +, - and ^ with vector_field
- TODO: parsing of initialization strings of fields. Allow to declare variables that can be refered by name inside initialization strings of vector fields
- TODO: create magnetic_field class, and add the string literal "_T" to the README.md file

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
- TODO: check where string_view should be used as parameter instead of string
- TODO: use string_view to the enum functions

## CONSTANTS (2)

- TODO: maybe all constant values should be constexpr, and maybe there's a way to make them scalar_unit without needing to have all of them defined at the same time, because that sizes
- TODO: add the constants of astronomy

## DIMENSIONS (14)

- TODO: support the binary prefixes too
- TODO: function get_frequent_dimensions(), which are the frequent definitions (J is N*m, W is J/s, etc)

- TODO: test dimension class with MSVC for the uses of the special characters
- TODO: some dimensions like degree, radian and money shouldn't be allowed to have a prefix
- TODO: check the literal with e
- TODO: read the ISO 80000

- TODO: scalar_unit should have get_notdimensionless_base_dimensions() and notdimensionless_base_display()

- TODO: finish custom_basic dimensions, change values of enum::type to CUSTOM_BASE_DIMENSION, CUSTOM_DERIVED_DIMENSION and CUSTOM_DERIVED_DIMENSION_FULL_SYMBOL, respectively
- TODO: finish the test of custom_basic dimensions and document them in the README.md file
- TODO: add the planck system of units
- TODO: add the Gaussian units
- TODO: add the atomic units
- TODO: add the natural units (used for atomic physics)

- TODO: possibly add the translations of names to some languages

## CONVERSION (4)

- TODO: add the apothecaries system of units, maybe there are more systems to add
- TODO: possibly add the drop units
- TODO: search if there are more historical units of measure to add
- TODO: finish the conversion of the imperial units and of the US units [https://en.wikipedia.org/wiki/Comparison_of_the_imperial_and_US_customary_measurement_systems](https://en.wikipedia.org/wiki/Comparison_of_the_imperial_and_US_customary_measurement_systems)

## UNITS (19)

- TODO: solve in some way the problem that vector_unit_3d needs different characters in Windows an inside Linux when initialized with strings
- TODO: allow to display in any conversion. By default it should always display in SI units, only if a conversion is expressly specified in the display functions the conversion is then the dimension that gets displayed
- TODO: check dimensions in all inheriting classes of scalar_unit and vector_unit, it's needed another constructor that checks them
- TODO: vector_unit_3d class maybe need the comparison operators with themselves
- TODO: use the PI of the std library
- TODO: function point_to() to a point and point_to() to a coordinate for vector_unit classes
- TODO: support the brackets inside is_scalar_unit(), is_complex() and is_lab_number()
- TODO: possibly add the light_scalar_unit class that allows operations with scalar_unit classes, which must contain only one dimension, not a vector\<dimension\>
- TODO: function to_latex() for dimensions and scalar_unit
- TODO: function that displays the scalar_unit as text, with the plural if the scalar_unit has a value greather than 1
- TODO: maybe the dimension memo needs a base unit class
- TODO: think if to add functions of statistics here, check if there is a solution in other C++ libraries or if it is good to have them here
- TODO: follow the schema of numbers of the 22 General Conference on Weights and Measures. Check if there are more rules to add of the General Conferences, too
- TODO: maybe a way to have "tags" in mEq and money classes would work to have it of specific instead of generic purpose
- TODO: contains_dimensions() to test if some dimensions are present, but not if those dimensions are the only ones present
- TODO: hide the bad constructors of the derived units of scalar_unit, the constructors that can change the dimensions to a different set of basic dimensions than the real basic dimensions
- TODO: maybe a constructor with float, dimension::type and prefix::type should be added too

- TODO: Regex that checks all the invalid dimensions initialization inside a static_assert (create a static function of valid_initialization_string()). Maybe try first by undefining the value if there's something that doesn't exist (with an else). It's possible to test, with static_assert, that dimension == nullptr, abbreviation == nullptr and conversion == nullptr
- TODO: Detect when there's the same dimension at the numerator and at the denominator of the string initialization

## BASE UNITS (2)

- TODO: get_mass(molecular_weight,density) in mole class and get_moles(molecular_weight,density) in mass class
- TODO: perfect_mole class, maybe inheriting mole class, that allows to store moles and also add or substract by an integer number of molecules, not only by mole. Another option is to just extend the mole class, instead of creating a new class

## DERIVED UNITS (7)

- TODO: think if to add accoustic and matter derived units, or if it's not needed
- TODO: delete all field classes that currently are vector_units, and make them fields
- TODO: move cas_number to the library of scifir-info, or even to another category
- TODO: biology units, like heart_rate
- TODO: UNIX time constructor in the string constructor for time_duration
- TODO: rename number_of_particles() to get_number_of_particles()
- TODO: add a function to calculate with mEq inside a child class that uses them

## MECA NUMBERS (9)

- TODO: add the allowed typenames to lab_number, and don't accept any other type
- TODO: angle should read initialization strings in radian too inside the string constructor, with "rad" name
- TODO: initialization with deg for degree too
- TODO: maybe add obtusangle, rect angle, acutangle, etc
- TODO: study if to add the gradian
- TODO: study if to add the turn
- TODO: add minutes and seconds to degrees
- TODO: maybe support prefixes for radians, search if there are prefixes for the other units of angles
- TODO: add atan2 with angle class, and use it where it's needed in the code

## SPECIAL UNITS (15)

- TODO: nutrition_information
- TODO: maybe add zoom class, which allows to work with zooms
- TODO: address class with zid inside
- TODO: complete color class like coordinate classes, with all the getters of all the different color versions, like get_h(), get_s(), get_v()
- TODO: class for geographical position including ZID and coordinates_3d
- TODO: class for geographical position in space, using AID and coordinates_3d
- TODO: think if to add a default case for the none value of aid and for the none value of zid
- TODO: functions is_aid() and is_zid()
- TODO: initialize_from_string() for pH and pOH classes should work with pH and pOH at the start, respectively
- TODO: enum of movement maybe should be divided in kind of animal
- TODO: finish the enums of mind.hpp
- TODO: maybe delete the operator = T of percentage class, maybe there are more in similar classes. Try first the different literals of non-floating numeric types
- TODO: pixel_color<>. Use monochrome_pixel, truecolor_pixel, etc, as typedefs of pixel_color<>
- TODO: complex_number<> should have trigonometric functions for complex numbers
- TODO: maybe create a mesh_3d class, or vector<point_3d<>>

## TENSORS (1)

- TODO: check if there's something needed related to tensors, given that scalar_unit, vector_unit and matrix are being used already

## PREDEFINED PHYSICS UNITS (4)

- TODO: electric_field which calculates based on coulomb charges
- TODO: gravity_field
- TODO: possibly magnetic_field?
- TODO: electric_current?

## CONTROL VOLUME (1)

- TODO: think what to do with the control_volume

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

## ISO C++ (1)

- TODO: add the possibility to create class names starting with numbers

## ELECTRONICS (1)

- TODO: check sensor libraries and decide which ones to support inside scifir-units (maybe in a new scifir library if needed)

## EXTRA TOOLS (1)

- TODO: Create scicalcs, a cli tool that calculates with scifir-units any value

## MATRIX (7)

- TODO: See if it's best to use template arguments for row and column or if to store those values as member-variables
- TODO: Multiplication of matrices of different but compatible types
- TODO: typecast to other matrix-classes of important libraries
- TODO: Iterator with range to use only one range-for
- TODO: Check limits of matrices for all operators
- TODO: Use the GSL to implement the reverse matrix
- TODO: add the hadamard_product()

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

## ANOTHER PROJECT - LIBRARY OF INFORMATION

- TODO: isbn class
- TODO: issn class
- TODO: ip class? check networking libraries of C++ and decide if to add it here

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
