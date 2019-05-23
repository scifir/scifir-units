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

// MEMORY OPTIMIZATION
// TODO: Use a memory profiler to analize the size of each object
// TODO: Implement real_dimensions with a UTF8 string (use an order to print each dimension, then it's done) if it's faster than actual_dimensions container and only in that case
// TODO: Check if the clone() function of undefined_number (and some others also) are causing a memory leak

// MAGICKSCIENCE
// TODO: delete some extra folders of physics
// TODO: divide between msci and msci_genetics
// TODO: maybe divide each msci discipline as one different msci library. Check first how if then it's mandatory to have different namespaces (see how to integrate that to GitHub). The libraries are msci_units, msci_geometry, msci_chemistry, msci_genetics, msci_plot
// TODO: document in a .odt file all the class and function names

// C++
// TODO: See if to send reference in some cases and const-reference when const is a practice, and add those two functions everywhere. Maybe change some member-variables to be public instead of using both functions
// TODO: use references and const-references instead of copies inside the body of functions that can be changed
// TODO: use explicit with angle_number and other classes
// TODO: delete c_str() where it's unneeded

// TODO: convert any enum that needs string representation with a to_string function (maybe it already exists something)
// TODO: what to do with exceptions of rapidxml (if to document, to add a catch, etc)
// TODO: include the build configuration of CodeBlocks inside GitHub with a file
// TODO: Debug target maybe can have configuration options that improve performance by avoiding some optimizations
// TODO: check how are inline constructors and constexpr constructors
// TODO: when it's necessary to use destructors and implement them if necessary
// TODO: if to add exceptions or error_codes, when to use each one
// TODO: See if to change any name using the full namespace to avoid name collisions inside classes (check which names should be changed to get that)
// TODO: Apply GNU Coding Standards
// TODO: Log system for the errors, including, if possible, the variable name
// TODO: Check best way to use print() related to GNU standards
// TODO: Use static functions for get_enum_type() among maybe others
// TODO: Use abstract everywhere. See if __ is used for proto classes and use it inside scalar_unit_crtp and vector_unit_crtp
// TODO: See if auto_unit and similar have a simpler option for copy and move constructors and assignments
// TODO: check if vectors can have a const size and add it to hyper_spherical_coordinates and the other coordinates classes
// TODO: if size_t and other similar constants are intended to be used inside normal code
// TODO: see when it's useful to create a custom buffer
// TODO: use of #pragma?

// TODO: See how static_assert works and use it for the next two TODOS
// TODO: Regex that checks all the invalid dimensions initialization (create a static function of valid_dimensions_string()). Maybe try first by undefining the value if there's something that doesn't exist (with an else). It's possible to test, with static_assert, that dimension == nullptr, abbreviation == nullptr and conversion == nullptr
// TODO: Detect when there's the same dimension at the numerator and at the denominator of the string initialization

// TOOLS
// TODO: tool for TODO (or create one if it doesn't exist)
// TODO: check the better code scan tools for C++
// TODO: if the optimization of the compiler gives code optimized in order to see the code by layers

// BUILDING
// TODO: see file formats for autotools files NEWS, INSTALL, README, etc
// TODO: see how to delete doxygen comments when building with autotools (see best practices for doxygen first)
// TODO: see if to create a .pc file
// TODO: try to integrate the library to MSYS2
// TODO: try to integrate the library to linux install system
// TODO: see other toolchains where magickscience can be added

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
// TODO: See every program for developing that GitHub has for open source projects
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

// PROMOTION
// TODO: promote the library inside the #chemistry channel
// TODO: promote the library with friends

// UNINMPORTANT BUGS AND DETAILS
// TODO: See what causes the error with the literal operator _MT
// TODO: Find in which cases angle_number becomes -0
// TODO: a limit of initialization of mole related to the maximum number that can be given there without having mid particles
// TODO: a way to initialize concentration without the ' ' at last (maybe to use % as an special abbreviation of empty dimensions)
// TODO: time_display of unit time class should display months related to the actual day
// TODO: add custom dimensions and currency_dimension (see what to do with custom dimensions first)

// MAYBE
// TODO: The constructor of abstract_dimension with more than one as prefix (it has to create more prefixes)
// TODO: unit::dimensions_equals(vector_real_dimensions) should not copy the real_dimensions to make the comparison
// TODO: A function from unit to change a specific dimension to be displayed with a set of prefixes

// FIND OUT
// TODO: when I have to use entire namespace scope to access a variable (what has happened with templates)
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
