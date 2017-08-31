// Document covariant types: http://en.cppreference.com/w/cpp/language/virtual

// NEARLY-FINISHED TASKS
// TODO: operator = of auto_unit and auto_scalar should check dimensions. operator = for auto_vector
// TODO: If to lose the move assignment inside class unit does something to performance
// TODO: initialize_real_dimensions() of class auto_unit and check initialization of dimensions
// TODO: Add 1d 1h 1m 1s display to time units (when they're only of time)
// TODO: check if dynamic_cast is the only solution for left-hand operators. If so, change it inside auto_scalar.hpp too if needed. Find out the performance of dynamic_cast related to the performance of static_cast
// TODO: abbreviation_electron_volt should have the factor E-19 enabled

// ARCHITECTURE OF UNITS
// TODO: Change the shared_ptr of both dimension containers to a unique_ptr
// TODO: Check that the copy constructor of vector_unit copies every kind of vector or not based on the dimensions

// FINISH ACTUAL UNITS
// TODO: Correct the operator - of vector_unit
// TODO: maybe initialization with literals can be done with a move instead of a copy (which actually happens)

// AFTER NEARLY-FINISHED TASKS
// TODO: delete the exceptions from constructors and other parts where it's unneeded
// TODO: see what to do for units with the same dimensions at the numerator and at the denominator
// TODO: a way to initialize concentration without the ' ' at last (maybe to use % as an special abbreviation of empty dimensions)

// TODO: check if inside the example of the wiki density is well initialized
// TODO: document that to fix a dimension it's done like (a + b,"N") using the abbreviation string

// FINISH ACTUAL MECA NUMBERS
// TODO: Try that class lab_number doesn't use print, instead it should use operator << always
// TODO: Use print() inside unit to print the unit for vector_units too
// TODO: operator << and maybe print() for direction
// TODO: Bidirectional operators of meca_numbers for numbers
// TODO: meca_number class for angle_number class
// TODO: angle_number should invalidate when the unit given is not empty
// TODO: angle_number class doesn't has their functions finished

// PROPERLY DISPLAY OF UNITS
// TODO: unit_number should display with the proper locale
// TODO: Reduce linker libraries needed for boost::locale
// TODO: Display the u of micro good, with the μ
// TODO: Change the symbol of angle to the one with theta

// PROPERLY USE OF TESTS
// TODO: test of create_abbreviation()
// TODO: test of create_dimension()
// TODO: test of create_prefix()
// TODO: test of undefined_number
// TODO: test of unit_number
// TODO: test of angle_number
// TODO: test of lab_number
// TODO: test of coordinates (is easy)
// TODO: test of unit constructors
// TODO: test of auto_unit
// TODO: test of scalar_unit (check temperature special initialization)
// TODO: test of vector_unit

// MEMORY OPTIMIZATION
// TODO: Use a memory profiler to analize the size of each object
// TODO: Implement real_dimensions with a UTF8 string (use an order to print each dimension, then it's done) if it's faster than actual_dimensions container and only in that case
// TODO: Check if the clone() function of undefined_number (and some others also) are causing a memory leak

// PROPERLY USE OF C++ FEATURES
// TODO: See if to change any name using the full namespace to avoid name collisions inside classes
// TODO: Apply GNU Coding Standards
// TODO: Log system for the errors, including, if possible, the variable name
// TODO: Check best way to use print() related to GNU standards
// TODO: Check best way to convert string to wstring and viceversa. Also, change .c_str() conversion if needed
// TODO: Use inline everywhere
// TODO: See if to send reference in some cases and const-reference when const is a practice, and add those two functions everywhere
// TODO: see if const-reference inside the constructor is a best prefix related to reference-only. Then, change abbreviation class constructor adding that
// TODO: Use static functions for get_enum_type() among maybe others
// TODO: Use noexcept if needed
// TODO: Use abstract everywhere. See if __ is used for proto classes and use it inside scalar_unit_crtp and vector_unit_crtp
// TODO: See if auto_unit and similar have a simpler option for copy and move constructors and assignments
// TODO: Find out how to use explicit good and use it (maybe with angle_number)
// TODO: See if there's a code scan tool good for C++ and use it
// TODO: units.hpp should be loaded without ../../../units.hpp if possible
// TODO: if the optimization of the compiler gives code optimized in order to see the code by layers

// TODO: See how static_assert works and use it for the next two TODOS
// TODO: Regex that checks all the invalid dimensions initialization (create a static function of valid_dimensions_string()). Maybe try first by undefining the value if there's something that doesn't exist (with an else). It's possible to test, with static_assert, that dimension == nullptr, abbreviation == nullptr and conversion == nullptr
// TODO: Detect when there's the same dimension at the numerator and at the denominator of the string initialization

// MECA NUMBERS
// TODO: Add the operators += -= *= etc to the number classes, and change the get_value().get_value() to get_value()
// TODO: undefined_number_union containing all the undefined_number derived classes. It shouldn't contain angle_number. Try first with a union of smart pointers, after with a undefined_number and a dynamic_cast inside unit.hpp, if it doesn't work a pointer, and if it doesn't work a union.
// TODO: Add names to the meca numbers (angler, laber, etc)
// TODO: The meca number class and it's kernel derived classes
// TODO: The interval number class
// TODO: The interval number subclasses of other numbers
// TODO: The bounce number class
// TODO: The percentage number class
// TODO: Implement the bounce number in the spherical coordinates and the hyperspherical coordinates
// TODO: Solve the problem with left and right repeated (it's not exclusive for direction_symbol)

// VECTOR FIELDS AND ADDITIONAL UNITS
// TODO: vector_field (it should operate with vector_units and maybe with scalar_units. With (x,y,z) it gives the respective vector). +, - and ^ with vector_field, + - * with vector_unit
// TODO: Typecasting of vector_unit to math_vector, boost_Ublas_vector, etc. Same for math_vector to vector_unit
// TODO: rotational coordinates

// ADDITIONAL CHARACTERISTICS OF UNITS
// TODO: units with a value depending of a math function (that is stored maybe as an string)
// TODO: class angle should have an angle_number as value
// TODO: units updated with a clock
// TODO: add custom dimensions and currency_dimension (see what to do with custom dimensions first)
// TODO: hyper_coordinates, cartesian_coordinates_1d
// TODO: distance_between_points(point_2d,point_2d), distance_between_points(point_3d,point_3d)
// TODO: command-line program that outputs the result of a unit conversion. It should allow to calculate for vectors and normal numbers. First it's needed to check if there exist something similar. Also, it's needed to connect the application with dionisius or a similar program
// TODO: 2d display of scalar_units and of vector_units
// TODO: 3d display of scalar_units and of vector_units
// TODO: units to edges of all coordinates classes (maybe to create a template-class derived of the coordinate class to add the units without changing the behavior, and a auto_coordinates to have dynamic dimensions)
// TODO: point_2d_units<> with dimensions, and spatial_2d_point with length dimensions
// TODO: a proper initialization of solid_angles (maybe they don't work as m2, it should be checked)
// TODO: time_display of unit time class should display months related to the actual day
// TODO: unit time class should be initialized by multiple abbreviations as 100 min 40 s for example

// ADDITIONAL CHARACTERISTICS TO PHYSICS
// TODO: Add all physical constants: https://en.wikipedia.org/wiki/Physical_constant#Number_of_fundamental_constants

// DOCUMENTATION
// TODO: Document MagickScience Units
// TODO: Maybe document common variables: https://en.wikipedia.org/wiki/List_of_common_physics_notations
// TODO: Document that comparison operators cannot be done for units with numbers (because they work with 50_N, etc)

// UNINMPORTANT BUGS AND DETAILS
// TODO: See what causes the error with the literal operator _MT
// TODO: Find in which cases angle_number becomes -0
// TODO: a limit of initialization of mole related to the maximum number that can be given there without having mid particles

// MATRIX
// TODO: See if it's best to use template arguments for row and column or if to store those values as member-variables
// TODO: Multiplication of matrices of different but compatible types
// TODO: typecast to other matrix-classes of important libraries
// TODO: Iterator with range to use only one range-for
// TODO: Check limits of matrices for all operators
// TODO: Use the GSL to implement the reverse matrix

// MOLECULES
// TODO: Decide if to have the pointers on bound.hpp and atom.hpp based on the total size of the object (with and without them)
// TODO: Store the proteins only one time, and to calculate a lot of them use that unique instead for the data purposes. For movement modeling, with one instance is enough, and use position coordinates and rotation coordinates to store the data of each protein
// TODO: Constructors of molecules should allow variables (they receive a map) for dividing the explanation of the compound among different groups
// TODO: Document that normal_atom template-class isn't an abstract class because it's not intended to be used directly

// DNA
// TODO: change the include of gene.hpp of normal_molecule.hpp to a general one for molecules
// TODO: load and free genes in ram
// TODO: warn if the DNA is composed by an non-divisible per 3 number of nitrogenous bases
// TODO: see which enumeration systems exists for genes and use one inside dna class

// SOLIDS
// TODO: architecture of solids, life-controlled or natural
// TODO: solids should have the follow(distance) member function
// TODO: crystal structures and polymorphism
// TODO: Support theoretical density and experimental density

// 2D FIGURES
// TODO: http://www.boost.org/doc/libs/1_64_0/libs/polygon/doc/index.htm
// TODO: https://github.com/ArashPartow/wykobi
// TODO: http://shapeop.org/
// TODO: Decide which geometry library to wrap
// TODO: If to separate the positioning from the logic. Then to remove center from figure_2d
// TODO: Find out if there's a general name for complex shapes
// TODO: polygon is the class for math polygons. is_inside() works by checking the four directions
// TODO: polygon class can maybe use something from boost in order to don't calculate math
// TODO: translate(physics::units::distance) function inside cartesian_coordinates. Also, add cartesian_coordinates to point_2d and point_3d
// TODO: graphical_polygon inherits from polygon and 2d_rigid_body. It includes borders (that can be 0) and is_inside_border(), is_inside_body(). Ghost behavior is part of 2d_rigid_body
// TODO: add() method for adding figures inside a complex shape

// To find
// TODO: Find out: When I have to use entire namespace scope to access a variable (what has happened with templates)

// Maybe
// TODO: The constructor of dimension_abstract with more than one as prefix (it has to create more prefixes)
// TODO: unit::dimensions_equals(vector_real_dimensions) should not copy the real_dimensions to make the comparison
// TODO: A function from unit to change a specific dimension to be displayed with a set of prefixes

// Find out
// TODO: See what to do with the sr (stereoradian) that's used for luminous_energy and luminous_exposure)
// TODO: Difference between the real and the abstraction layer for each physic topic
// TODO: tensor_unit, as vector_unit and scalar_unit. Moment of inertia maybe needs it. vector_field
// TODO: A path vector
// TODO: Find out if the dimensions can be elevated at a decimal number
// TODO: Topology: See what to do with point
// TODO: If the temperature_gradient is a vector_unit or other thing
// TODO: Implement hyper_spherical_coordinates for n >= 4
// TODO: See what to do with the different coordinates system that exist (like toroid coordinates), which implement and which don't
// TODO: See the official ISOs and similar standards of units and check if to add something
