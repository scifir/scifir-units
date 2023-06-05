MSCI UNITS - VERSION 2

// NEARLY-FINISHED TASKS
// TODO: abbreviation_electron_volt should have the factor E-19 enabled

// PROPERLY DISPLAY OF UNITS
// TODO: scalar_unit should display with the configured locale of the execution of the program
// TODO: Reduce linker libraries needed for boost::locale (see if the libraries aren't needed and delete them)
// TODO: auto display in the units that closely match the value (100 or less is the unit selected, if it's more than 1000 it's the prefix 10^3 bigger, and if it's less than 0.1 it has to display in the previous 10^-3 prefix)

// COORDINATES
// TODO: all coordinates classes should have ostream << with (x,y), (p,theta), etc
// TODO: rotational coordinates
// TODO: initialization with string using coordinate systems different than cartesian
// TODO: finish get_altitude(). Read about geographic coordinates

// VECTOR FIELDS
// TODO: vector_field (it should operate with vector_units and maybe with scalar_units. With (x,y,z) it gives the respective vector). +, - and ^ with vector_field, + - * with vector_unit
// TODO: Typecasting of vector_unit to math_vector, boost_Ublas_vector, etc. Same for math_vector to vector_unit

// DIMENSIONS
// TODO: custom_dimension in order to have custom dimensions
// TODO: maybe create_dimension() and create_prefix() should have parameters to pass to constructors
// TODO: add the omega symbol when displaying the resistance

// UNITS - Finish creating the new class inheritance
// TODO: support the conversions natively
// TODO: function to_SI_convention(vector<scalar_unit>&)

// UNITS
// TODO: maybe delete the dimensions member-variable of scalar_unit, and use instead another system for prefixes
// TODO: add const to the enum of light_unit
// TODO: mass of standard_atomic_mass() is displayed [empty], fix it

// TODO: see what to do for units with the same dimensions at the numerator and at the denominator
// TODO: default zero units for the cases of errors with operators (unit, scalar and vector)
// TODO: operator == should care about dimensions and the value related to dimensions (cast operator == of unit,unit there)
// TODO: initialization of 1/g and similar
// TODO: support scientific notation on constructors and display(int,bool) (check if there's a function to get the order of the number)
// TODO: display all the numbers of the unit in the case 0
// TODO: display all the numbers of the unit in the cases of a very big number
// TODO: configure option to display the units with scientific notation (inside display())

// TODO: units updated with a clock (not automatically, by doing += and similar operations)
// TODO: 2d display of scalar_units and of vector_units (create a msci_units_2d library for it)
// TODO: 3d display of scalar_units and of vector_units (create a msci_units_3d library for it)
// TODO: volume should be constructed with an string of the form 2cm * 1cm * 3cm and separate the three dimensions as different units. Also, the display should be, for that case, automatically configured to be 2cm * 1cm * 3cm than to be the total amount (with a member-variable)
// TODO: units should allow to sum strings
// TODO: vector<scalar_unit> initialized from a list of units (separated by a selectable string)
// TODO: is_dimension(const string&,const string&) which gives true if the given string is of the asked dimensions
// TODO: light_length which uses only an enum of prefixes and a value, maybe it should be called length, and length should be called full_length

// TODO: sqrt() and pow() maybe should be direct for created units, instead of passing by scalar_unit again to initialize after that the other unit

// MATERIAL_VECTOR_UNIT
// TODO: decide how it'll be, in order to include real space to the vector_unit

// SPECIAL UNITS
// TODO: add the omega greek symbol to the text of solid angle
// TODO: pixel dimension, pixel unit and pixels_distance classes
// TODO: the pH should be an special unit
// TODO: unit time class should be initialized by multiple abbreviations as 100 min 40 s for example
// TODO: unit time class should display with an string "d s" specifying the dimensions to calculate on
// TODO: unit time class shouldn't have display_mode as variable
// TODO: complete color class like coordinate classes, with all the getters of all the different color versions
// TODO: support currency dimension
// TODO: document a little how to handle currency
// TODO: document the ISOs important to use with this library
// TODO: object geographic location, using my ISO of geographic location
// TODO: study the geographic coordinates deeply, and see if to add something more related to them

// MECA NUMBERS
// TODO: add the allowed typenames to lab_number, and don't accept any other type

// CODE OPTIMIZATION
// TODO: divide single dimensions unit of multiple-dimensions unit in order to save a lot of space by not using vectors of prefixes, dimensions and abbreviations
// TODO: maybe prefix class shouldn't have the power. Instead, use different prefixes
// TODO: check the object code resulting by testing different functions of the unit classes

// ELECTRONICS
// TODO: check sensor libraries and decide which ones to support inside msci_units (maybe in a new msci library if needed)

// PATTERNS
// TODO: implement a pattern class using a regular expressions library

// TESTS
// TODO: test of sizeof for all unit classes

// MATRIX
// TODO: See if it's best to use template arguments for row and column or if to store those values as member-variables
// TODO: Multiplication of matrices of different but compatible types
// TODO: typecast to other matrix-classes of important libraries
// TODO: Iterator with range to use only one range-for
// TODO: Check limits of matrices for all operators
// TODO: Use the GSL to implement the reverse matrix

// CONSTANTS
// TODO: make a list of all important constants of science, with their respective unit

// FUTURE
// TODO: support the case of n dimensions fixed
// TODO: add the theta and phi characters to C++ variable names, and add them then to the member-variables of vector_unit classes, and any other case of similar use
// TODO: add the astronomy coordinates
// TODO: add the other orthogonal coordinates, like paraboloidal

// FUTURE - MECA NUMBERS (POSSIBLE, THINK)
// TODO: Add names to the meca numbers (angler, laber, etc)
// TODO: The interval number class
// TODO: The interval number subclasses of other numbers
// TODO: The bounce number class
// TODO: The percentage number class (it has to have the calculate function in order to receive a value to be the percentage of)
// TODO: Solve the problem with left and right repeated (it's not exclusive for direction_symbol)
// TODO: solid_angle class (maybe it isn't a meca number)
// TODO: maybe _angle for angle in order to use cos(x),sin(x),etc with degrees
