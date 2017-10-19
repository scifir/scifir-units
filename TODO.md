// Document covariant types: http://en.cppreference.com/w/cpp/language/virtual

// Number of todos: 190

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

// NEARLY-FINISHED TASKS
// TODO: initialize_real_dimensions() of class auto_unit and check initialization of dimensions
// TODO: check if dynamic_cast is the only solution for left-hand operators. If so, change it inside auto_scalar.hpp too if needed. Find out the performance of dynamic_cast related to the performance of static_cast
// TODO: abbreviation_electron_volt should have the factor E-19 enabled

// ARCHITECTURE OF UNITS
// TODO: Change the shared_ptr of both dimension containers to a unique_ptr

// FINISH ACTUAL UNITS
// TODO: Correct the operator - of vector_unit

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

// MEMORY OPTIMIZATION
// TODO: Use a memory profiler to analize the size of each object
// TODO: Implement real_dimensions with a UTF8 string (use an order to print each dimension, then it's done) if it's faster than actual_dimensions container and only in that case
// TODO: Check if the clone() function of undefined_number (and some others also) are causing a memory leak

// PROPERLY USE OF C++ FEATURES
// TODO: units.hpp should be loaded without ../../../units.hpp if possible
// TODO: See if to send reference in some cases and const-reference when const is a practice, and add those two functions everywhere. Maybe change some member-variables to be public instead of using both functions
// TODO: use references and const-references instead of copies inside the body of functions that can be changed
// TODO: use explicit with angle_number and other classes

// TODO: include the build configuration of CodeBlocks inside GitHub with a file
// TODO: Debug target maybe can have configuration options that improve performance by avoiding some optimizations
// TODO: check how are inline constructors and constexpr constructors
// TODO: when it's necessary to use destructors and implement them if necessary
// TODO: if to add exceptions or error_codes, when to use each one
// TODO: See if to change any name using the full namespace to avoid name collisions inside classes (check which names should be changed to get that)
// TODO: Apply GNU Coding Standards
// TODO: Log system for the errors, including, if possible, the variable name
// TODO: Check best way to use print() related to GNU standards
// TODO: Check best way to convert string to wstring and viceversa. Also, change .c_str() conversion if needed
// TODO: Use static functions for get_enum_type() among maybe others
// TODO: Use abstract everywhere. See if __ is used for proto classes and use it inside scalar_unit_crtp and vector_unit_crtp
// TODO: See if auto_unit and similar have a simpler option for copy and move constructors and assignments
// TODO: check if vectors can have a const size and add it to hyper_spherical_coordinates and the other coordinates classes
// TODO: if size_t and other similar constants are intended to be used inside normal code
// TODO: see when it's useful to create a custom buffer

// TODO: See how static_assert works and use it for the next two TODOS
// TODO: Regex that checks all the invalid dimensions initialization (create a static function of valid_dimensions_string()). Maybe try first by undefining the value if there's something that doesn't exist (with an else). It's possible to test, with static_assert, that dimension == nullptr, abbreviation == nullptr and conversion == nullptr
// TODO: Detect when there's the same dimension at the numerator and at the denominator of the string initialization

// TOOLS
// TODO: check the better code scan tools for C++
// TODO: if the optimization of the compiler gives code optimized in order to see the code by layers

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
// TODO: solid_angle class (maybe it isn't a meca number)

// VECTOR FIELDS
// TODO: vector_field (it should operate with vector_units and maybe with scalar_units. With (x,y,z) it gives the respective vector). +, - and ^ with vector_field, + - * with vector_unit
// TODO: Typecasting of vector_unit to math_vector, boost_Ublas_vector, etc. Same for math_vector to vector_unit
// TODO: rotational coordinates

// ADDITIONAL CHARACTERISTICS OF UNITS
// TODO: pixel dimension, pixel unit and pixels_distance classes
// TODO: delete the exceptions from constructors and other parts where it's unneeded
// TODO: see what to do for units with the same dimensions at the numerator and at the denominator
// TODO: default zero units for the cases of errors with operators (unit, scalar and vector). see first if to use exceptions instead
// TODO: vector unit should have display_as_scalar() function
// TODO: operator == should care about dimensions and the value related to dimensions (cast operator == of unit,unit there)
// TODO: initialization of 1/g and similar
// TODO: support scientific notation on constructors and display(int,bool) (check if there's a function to get the order of the number)
// TODO: units with a value depending of a math function (that is stored maybe as an string)
// TODO: units updated with a clock
// TODO: 2d display of scalar_units and of vector_units
// TODO: 3d display of scalar_units and of vector_units
// TODO: maybe create_dimension(), create_abbreviation() and create_prefix() should have parameters to pass to constructors
// TODO: create_abbreviation() should forbid some constructions
// TODO: operator >> should allow to create vectors giving angles
// TODO: unit time class should be initialized by multiple abbreviations as 100 min 40 s for example
// TODO: unit time class should display with an string "d s" specifying the dimensions to calculate on
// TODO: divide single dimensions unit of multiple-dimensions unit in order to save a lot of space by not using vectors of prefixes, dimensions and abbreviations
// TODO: maybe create position unit class to use for position purposes, instead of length

// GRAPHICS AND SOUND
// TODO: graphic class with display() and save() abstract functions
// TODO: graphic_2d class with display function
// TODO: graphic_3d class with display function
// TODO: sound class

// PATTERNS
// TODO: implement a pattern class using a regular expressions library

// ADDITIONAL CHARACTERISTICS TO PHYSICS
// TODO: Add all physical constants: https://en.wikipedia.org/wiki/Physical_constant#Number_of_fundamental_constants

// DOCUMENTATION
// TODO: Maybe document common variables: https://en.wikipedia.org/wiki/List_of_common_physics_notations
// TODO: Units: why to use units? section providing a complete example of the advantage
// TODO: Divide the documentation of units in different pages in order to reduce the total size
// TODO: Units: The problem with commas and dots to write numbers (maybe use english notation)
// TODO: Units: Formulas with * up and down appear bad
// TODO: Units: unit classes should appear in their informatic form (and say classname as the title of the column)
// TODO: Units: abbreviations should be ordered by topic and priority, maybe add categories
// TODO: Units: Maybe add categories for units reference, instead of the column science
// TODO: Units: literals should appear with unit classes
// TODO: Change the index of the wiki
// TODO: Units: Document the functions of vector_unit
// TODO: Units: check if inside the example of the wiki density is well initialized
// TODO: Units: vector units constructors should be documented
// TODO: Units: assignment operators should be documented inside arithmetic operations
// TODO: Document with doxygen all the classes and functions

// GITHUB
// TODO: see of the habit of adding the author of a file inside the header
// TODO: See every program for developing of GitHub
// TODO: Maybe change the name to lowercase to have a more C++ friendly project (do the same with smartText)
// TODO: Follow all GitHub rules for the repository
// TODO: See the guide to find users for the library
// TODO: See the best build automation tool to add to the project, and the INSTALL.md file
// TODO: see the best way to versioning the project
// TODO: Create a donations system
// TODO: Add stars to every important project I know of
// TODO: See how to distribute MagickScience along the open-source community
// TODO: Add MagickScience to the list of https://www.contributor-covenant.org/
// TODO: Think if to create a website for MagickScience

// BUILDING
// TODO: see if to create a .pc file
// TODO: try to integrate the library to MSYS2
// TODO: see other toolchains where magickscience can be added

// PROMOTION
// TODO: promote the library inside the #chemistry channel

// UNINMPORTANT BUGS AND DETAILS
// TODO: See what causes the error with the literal operator _MT
// TODO: Find in which cases angle_number becomes -0
// TODO: a limit of initialization of mole related to the maximum number that can be given there without having mid particles
// TODO: a way to initialize concentration without the ' ' at last (maybe to use % as an special abbreviation of empty dimensions)
// TODO: time_display of unit time class should display months related to the actual day
// TODO: add custom dimensions and currency_dimension (see what to do with custom dimensions first)

// MSCIENCE COMMAND-LINE
// TODO: command-line program that outputs the result of a unit conversion. It should allow to calculate for vectors and normal numbers. First it's needed to check if there exist something similar. Also, it's needed to connect the application with dionisius or a similar program. Time units should be displayed with time_display
// TODO: atom function that displays all the properties of an atom (with colored text)

// MSCIENCE MOLECULES VISUALIZER
// TODO: .msm file extension (abbreviation of Mscience Molecule)
// TODO: support proteins (check if possible for all proteins first)

// MSCIENCE CHEMISTRY CREATOR
// TODO: Chemistry Creator program for creating molecules with .sm extension

// ATOMS
// TODO: 3D graphical functions: get_image_3d(),get_molecular_geometry_angle(const atom&) finish two angles
// TODO: atom::get_molecular_geometry_angle() needs good the square_antipristamic and tricapped_trigonal_prismatic values
// TODO: 2D graphical functions: get_image_2d(),get_detailed_image_2d()
// TODO: finish atom::get_atomic_color() using an enum for all colors
// TODO: review all electrical classes, atom::get_lone_pairs() among others
// TODO: finish normal_atom::get_electronic_configuration()
// TODO: create the first isotope class
// TODO: create all common isotopes of chemistry
// TODO: create_atom() should detect ions and isotopes (and more of the nomenclature, if it exists)
// TODO: class atomic_group
// TODO: function atom::is_chiral()
// TODO: is_factible(), is_valence_full(), get_valence_number() should work for atomic_group_b(), lanthanides and actinides
// TODO: finish some properties of some atoms (like radioactive)
// TODO: what's speed of sound of atoms
// TODO: what's half-life and unit to represent it
// TODO: create triple_point and melting_point (maybe point classes)

// DETAILED ATOMS
// TODO: finish detailed atoms
// TODO: finish electron_cloud object
// TODO: electron cloud functions: get_electron_cloud(),print_electron_cloud()

// DOCUMENTATION OF ATOMS
// TODO: document that is_atom_specimen() is always used instead of get_z() or get_symbol() to test for the specimen, cause for isotopes the string symbol can change
// TODO: document the nomenclature of the cas number
// TODO: document that the unfinished atoms doesn't have their values actually calculated. Document which values and atoms aren't completed
// TODO: document that normal_atom template-class isn't an abstract class because it's not intended to be used directly

// MOLECULES
// TODO: implement the bond_length inside atomic_bond class
// TODO: 3D display
// TODO: 2D display of molecules by printing inside 2D a 3D molecule
// TODO: molecule::has_functional_group(functional_group)
// TODO: molecule::get_dipole()
// TODO: molecule::is_polar() and molecule::is_apolar()
// TODO: are_isomers(), are_conformational_isomers(), are_enantiomers()
// TODO: are_miscible(), are_inmiscible()
// TODO: molecule::is_cyclical() and molecule::is_acyclical()
// TODO: is_eter(), and all the others of those functions
// TODO: molecule::get_formula(),molecule::print(),operator << of molecule
// TODO: operator == and operator != of molecule
// TODO: ether, carboxilic_acid, and all the other molecule subclasses of normal_molecule in order to have the same clarity as with units length, mass, etc.

// DNA
// TODO: see which functions of molecule change now that bit_molecule is being used and add those functions to normal_molecule, being the ones of molecule class pure-virtual
// TODO: load and free genes in ram
// TODO: warn if the DNA is composed by an non-divisible per 3 number of nitrogenous bases
// TODO: see which enumeration systems exists for genes and use one inside dna class
// TODO: save() function to store .dna files. new_genes should be stored as another member-variable in order to optimize how to save the file without asking to new_genes all the time
// TODO: if the pointers of rapidxml have to be deleted or not
// TODO: maybe the dna should load with a buffer and with multi-threading
// TODO: compression algorithm maybe using zlib for dna files
// TODO: see if it's possible to support to write numbers with bytes
// TODO: add the two dna strings (male and female), and add H- or M- to the operator[] of the dna class as a prefix to select the chain
// TODO: change the include of gene.hpp of normal_molecule.hpp to a general one for molecules

// BIOCHEMISTRY
// TODO: protein class, with special format to store and load it
// TODO: molecule::is_biochemical()
// TODO: Store the proteins only one time, and to calculate a lot of them use that unique instead for the data purpose. For movement modeling, with one instance is enough, and use position coordinates and rotation coordinates to store the data of each protein

// CHEMICAL REACTIONS
// TODO: Finish basic member-functions of the class
// TODO: Reaction is_safe() member-function, related to T change, entropy change, etc.
// TODO: Add all toxicology knowledge inside chemical_reaction and molecule, in order to know if a reaction is safe or not

// UNFINISHED ATOMS
// TODO: Nh (atoms_iiia.hpp), Fl (atoms_iva.hpp), Mc (atoms_va.hpp), Lv (atoms_via.hpp), At y Ts (atoms_viia.hpp), He and the other noble gases (atoms_viiia.hpp), Y (atoms_iiib.hpp), all ivb (atoms_ivb.hpp), all vb (atoms_vb.hpp), all vib (atoms_vib.hpp),
// TODO: Mn doesn´t documents  covalent radius dual spin

// SOLIDS
// TODO: architecture of solids, life-controlled or natural
// TODO: solids should have the follow(distance) member function
// TODO: crystal structures and polymorphism
// TODO: Support theoretical density and experimental density

// MATH
// TODO: search for actual math libraries: graph libraries, function libraries
// TODO: interval of (a,b) class: interval_state enum (open,close), ordinal pairs, operator << and print(), range iterator(?)

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

// UI
// TODO: configure an additional target of compilation which uses wxWidgets for creating visualizers
// TODO: molecules visualizer
// TODO: DNA visualizer
// TODO: proteins visualizer
// TODO: graphs visualizer
// TODO: math space visualizer

// To find
// TODO: Find out: When I have to use entire namespace scope to access a variable (what has happened with templates)

// Maybe
// TODO: The constructor of dimension_abstract with more than one as prefix (it has to create more prefixes)
// TODO: unit::dimensions_equals(vector_real_dimensions) should not copy the real_dimensions to make the comparison
// TODO: A function from unit to change a specific dimension to be displayed with a set of prefixes

// Find out
// TODO: see if there exists different dimensions on different edges for some vectors
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

// POSTPOSED
// TODO: use of noexcept
