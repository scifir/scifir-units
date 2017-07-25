#include "physics/basic/units/abbreviation.hpp"
#include "physics/basic/units/unit_basic.hpp"
#include "physics/basic/units/dimension.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/units.hpp"
#include "physics/particles.hpp"
#include "informatics/units.hpp"
#include "chemistry/general/atoms.hpp"
#include "math/number/angle_number.hpp"
#include "math/number/unit_number.hpp"
#include "math/number/lab_number.hpp"
#include "informatics/types/is_number.hpp"
#include "math/topology/coordinates/hyper_spherical_coordinates.hpp"
#include "math/linear_algebra/matrix.hpp"

#include "boost/locale.hpp"
#include "boost/variant.hpp"
#include "boost/math/constants/constants.hpp"

#include <cfloat>
#include <cmath>
#include <complex>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <type_traits>

using namespace std;
using namespace physics::units;
using namespace math::number;
using namespace math;

// 10-01-2017: 19 warnings

// Document covariant types: http://en.cppreference.com/w/cpp/language/virtual

// TODO: Check that the copy constructor of vector_unit copies every kind of vector or not based on the dimensions
// TODO: Check if auto_scalar operators are unneeded because of the inheritance of auto_unit operators
// TODO: auto_unit, auto_scalar and auto_vector. Use virtual inheritance with auto_init for auto_scalar and auto_vector (check virtual inheritance performance first). Also, maybe auto_scalar is unneeded because auto_unit is enough for the purpose
// TODO: Add the constructor of vector_unit (unit,vector_unit) for the units of the first expression and the directions of the vector given

// TODO: Bytes should work with 1024 as scale, rather than 1000 between prefixes
// TODO: Implement the UnitConverter measures inside the conversion data
// TODO: See what to do with the std::chrono::duration related to time. Allow time units to sum time. See how to add chrono to ratios (maybe use <ratio> from std)
// TODO: Add 1d 1h 1m 1s display to time units (when they're only of time)

// TODO: Try that class lab_number doesn't use print, instead it should use operator << always
// TODO: Use print() inside unit to print the unit for vector_units too
// TODO: operator << and maybe print() for direction

// TODO: change uma by amu (if it isn't good)
// TODO: Correct the operator - of vector_unit
// TODO: The operator ^ of vector_unit should change dimensions
// TODO: Document that comparison operators cannot be done for units with numbers (because they work with 50_N, etc)
// TODO: Bidirectional operators of vector_unit and scalar_unit for numbers (see Boost first)
// TODO: Bidirectional operators of meca_numbers for numbers

// TODO: Check best way to use print() related to GNU standards
// TODO: Check best way to convert string to wstring and viceversa. Also, change .c_str() conversion if needed

// TODO: test of undefined_number
// TODO: test of unit_number
// TODO: test of angle_number
// TODO: test of lab_number
// TODO: test of coordinates (is easy)
// TODO: test of unit
// TODO: test of scalar_unit (check temperature special initialization)
// TODO: test of vector_unit

// TODO: Use a memory profiler to analize the size of each object
// TODO: Implement real_dimensions with a UTF8 string (use an order to print each dimension, then it's done) if it's faster than actual_dimensions container and only in that case
// TODO: Assure that the vector_unit_tuple and the unit from string literals are returned as a move with the profiler
// TODO: Check if the clone() function of undefined_number (and some others also) are causing a memory leak

// TODO: Apply GNU Coding Standards
// TODO: Log system for the errors, including, if possible, the variable name

// TODO: ppb and ppm inside molarity as a special string constructor
// TODO: a special constructor for mol that contains the exact amount of particles

// TODO: unit_number should display with the proper locale
// TODO: Reduce linker libraries needed for boost::locale
// TODO: Display the u of micro good, with the μ
// TODO: Change the symbol of angle to the one with theta

// TODO: Use inline everywhere
// TODO: Use static functions for get_enum_type() among maybe others
// TODO: Use noexcept if needed
// TODO: Use const on operator + - * / ^ if it's like that
// TODO: Use abstract everywhere
// TODO: Find out how to use explicit good and use it (maybe with angle_number)
// TODO: Delete the get_ name that isn't needed on all classes
// TODO: See if there exist int of 1 byte size (instead of 2 or more)
// TODO: Find out how boost operators work and use them inside meca numbers, unit, scalar_unit, vector_unit
// TODO: See how static_assert works and use it for the next two TODOS
// TODO: Regex that checks all the invalid dimensions initialization (create a static function of valid_dimensions_string()). Maybe try first by undefining the value if there's something that doesn't exist (with an else). It's possible to test, with static_assert, that dimension == nullptr, abbreviation == nullptr and conversion == nullptr
// TODO: Detect when there's the same dimension at the numerator and at the denominator of the string initialization

// TODO: real_dimensions should be static for each derived_class
// TODO: auto_vector should have real_dimensions as member-variable (instead of unit)
// TODO: the functions of dimensions to create them should go inside dimension_container (among other functions)
// TODO: Change the shared_ptr of dimension_container to a unique_ptr
// TODO: Solve the problem with left and right repeated (it's not exclusive for direction_symbol)

// TODO: Find library for tests

// TODO: Create a GitHub repository for MagickScience

// TODO: Add the operators += -= *= etc to the number classes, and change the get_value().get_value() to get_value()
// TODO: undefined_number_union containing all the undefined_number derived classes. It shouldn't contain angle_number. Try first with a union of smart pointers, after with a undefined_number and a dynamic_cast inside unit.hpp, if it doesn't work a pointer, and if it doesn't work a union.
// TODO: Add names to the meca numbers (angler, laber, etc)
// TODO: The meca number class and it's kernel derived classes
// TODO: The interval number class
// TODO: The interval number subclasses of other numbers
// TODO: The bounce number class
// TODO: Implement the bounce number in the spherical coordinates and the hyperspherical coordinates

// TODO: vector_field (it should operate with vector_units and maybe with scalar_units. With (x,y,z) it gives the respective vector). +, - and ^ with vector_field, + - * with vector_unit
// TODO: Typecasting of vector_unit to math_vector, boost_Ublas_vector, etc. Same for math_vector (to vector_unit)
// TODO: rotational coordinates
// TODO: Maybe delete unit_crtp and convert then unit a template-class

// TODO: units with a value depending of a math function (that is stored maybe as an string)
// TODO: ratios of numbers
// TODO: relations of units (like acceleration with velocity)
// TODO: units updated with a clock
// TODO: Add custom dimensions and currency_dimension (see what to do with custom dimensions first)
// TODO: The operator * maybe can have a solution without tuples
// TODO: See what causes the error with the literal operator _MT
// TODO: Find in which cases angle_number becomes -0

// TODO: Add all physical constants: https://en.wikipedia.org/wiki/Physical_constant#Number_of_fundamental_constants
// TODO: Maybe document common variables: https://en.wikipedia.org/wiki/List_of_common_physics_notations


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

// SOLIDS
// TODO: crystal structures and polymorphism
// TODO: Support theoretical density and experimental density

// POLYGON
// TODO: polygon is the class for math polygons. is_inside() works by checking the four directions
// TODO: graphical_polygon inherits from polygon and 2d_rigid_body. It includes borders (that can be 0) and is_inside_border(), is_inside_body(). Ghost behavior is part of 2d_rigid_body

// To find
// TODO: Find out: When I have to use entire namespace scope to access a variable (what has happened with templates)
// TODO: Generic solution to the metaprogramming problem of vector_unit operators: To return a type compatible after within a function param, a cout and object initialization. See if the tuple method can be replace with auto

// Maybe
// TODO: The constructor of dimension_abstract with more than one as prefix (it has to create more prefixes)
// TODO: unit::dimensions_equals(unit_real_dimensions) should not copy the real_dimensions to make the comparison
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

void memory_consumption();
void test_angle_number();
void test_atom();
void test_basic_unit();
void test_lab_number();
void test_matrix();
void test_scalar_unit();
void test_unit();
void test_unit_number();
void test_vector_unit();
void test_vector_unit_1d();

int main()
{
	wcout << L"Do you guess? This is the superb library of science MagickScience! We are testing units today, enjoy :D" << endl << endl;

	//test_atom();
	test_unit();
	test_basic_unit();
	wcout << physics::proton::common_mass << endl;

	wcout << endl << endl;
	//test_vector_unit();

	/*math::topology::hyper_spherical_coordinates a (10,90,0);
	cout << a.get_r() << endl;
	//cout << a.get_angle1() << endl;
	//cout << a.get_angle2() << endl;
	cout << setprecision(2);
	cout << a.x_projection() << endl;
	cout << a.y_projection() << endl;
	cout << a.z_projection() << endl;*/
}

void memory_consumption()
{
	wcout << "math::number::unit_number: " << sizeof(math::number::unit_number) << endl;
	wcout << "math::number::undefined_number: " << sizeof(math::number::undefined_number<unit_number>) << endl;
	wcout << "math::topology::space_type (float): " << sizeof(math::topology::space_type) << endl;
	wcout << "physics::units::unit: " << sizeof(physics::units::unit) << endl;
}

void test_angle_number()
{
	math::number::angle_number a = 40;
	wcout << a << endl;
	wcout << (a + 50) << endl;
	wcout << (a - 50) << endl;
	wcout << (a * 50) << endl;
	wcout << (a / 50) << endl;
	wcout << (a ^ 50) << endl;
	math::number::angle_number b = 50;
	b = a;
	b += 50;
	wcout << b << endl;
	math::number::angle_number c = 50;
	c -= 234;
	wcout << c << endl;
	math::number::angle_number d = 50;
	d *= 10;
	wcout << d << endl;
	math::number::angle_number e = 50;
	e /= 10;
	wcout << e << endl;
	math::number::angle_number f = 50;
	f ^= 2;
	wcout << f << endl;
	wcout << (e + f) << endl;
	wcout << (e - f) << endl;
	math::number::angle_number g = 50;
	math::number::angle_number h = 120;
	g += h;
	wcout << g << endl;
	math::number::angle_number i = 50;
	math::number::angle_number j = 120;
	i -= j;
	wcout << i << endl;
	//wcout << "type-cast to float: " << float(i) << endl;
	wcout << "sin(angle_number): " << math::number::sin(math::number::angle_number(0)) << endl;
	wcout << "cos(angle_number): " << math::number::cos(math::number::angle_number(90)) << endl;
	wcout << "tan(angle_number): " << math::number::tan(math::number::angle_number(0)) << endl;
	//wcout << "asin(angle_number): " << math::number::asin(math::number::angle_number(0)) << endl;
	//wcout << "acos(angle_number): " << math::number::acos(math::number::angle_number(1)) << endl;
	//wcout << "atan(angle_number): " << math::number::atan(math::number::angle_number(0)) << endl;
	wcout << "sinh(angle_number): " << math::number::sinh(math::number::angle_number(0)) << endl;
	wcout << "cosh(angle_number): " << math::number::cosh(math::number::angle_number(90)) << endl;
	wcout << "tanh(angle_number): " << math::number::tanh(math::number::angle_number(0)) << endl;
	//wcout << "asinh(angle_number): " << math::number::asinh(math::number::angle_number(0)) << endl;
	//wcout << "acosh(angle_number): " << math::number::acosh(math::number::angle_number(1)) << endl;
	//wcout << "atanh(angle_number): " << math::number::atanh(math::number::angle_number(0)) << endl;
}

void test_atom()
{
	//chemistry::atom_H atom_h;
	//atom_h.print();
}

void test_basic_unit()
{
	wcout << "Testing basic units:" << endl << endl;
	length a = 100_m;
	wcout << "a: " << a << endl;
	mass b = 100_g;
	wcout << "b: " << b << endl;
	physics::units::time c = 100_s;
	wcout << "c: " << c << endl;
	charge d = 100_C;
	wcout << "d: " << d << endl;
	temperature e = 100_K;
	wcout << "e: " << e << endl;
	mole f = 100_mol;
	wcout << "f: " << f << endl;
	light g = 100_cd;
	wcout << "g: " << g << endl;
	data h = 100_B;
	wcout << "h: " << h << endl;
}

void test_lab_number()
{
	math::number::lab_number a (100,5);
	wcout << "a: " << a << endl;
	math::number::lab_number b (20,2);
	wcout << "b: " << b << endl;
	wcout << "a + b: " << (a + b) << endl;
	wcout << "a - b: " << (a - b) << endl;
	wcout << "a * b: " << (a * b) << endl;
	wcout << "a / b: " << (a / b) << endl;
	wcout << "a ^ b: " << (a ^ b) << endl;
	wcout << "a + 50: " << (a + 50) << endl;
	wcout << "a - 20: " << (a - 20) << endl;
	wcout << "a * 10: " << (a * 10) << endl;
	wcout << "a / 5: " << (a / 5) << endl;
	wcout << "a ^ 3: " << (a ^ 3) << endl;
}

void test_matrix()
{
	matrix<int,3,3> x {{1,2,3},{1,7,6},{5,4,2}};
	matrix<int,3,3> y {{2,3,4},{4,5,6},{7,8,9}};
	wcout << "x: " << x << endl;
	wcout << "y: " << y << endl;
	wcout << "x row size: " << x.row_size() << endl;
	wcout << "x column size: " << x.column_size() << endl;
	wcout << "x row: " << x.row(1) << endl;
	wcout << "x column: " << x.column(1) << endl;
	wcout << "x + y: " << (x + y) << endl;
	wcout << "x - y: " << (x - y) << endl;
	wcout << "x * y: " << (x * y) << endl;
	wcout << "x ^ 2: " << (x ^ 2) << endl;
	wcout << "x transpose: " << x.t() << endl;
}

void test_scalar_unit()
{
	wcout << endl;
	wcout << "Testing scalar unit:" << endl << endl;
	physics::units::distance a ("50 km");
	wcout << "a: " << a << endl;
	physics::units::distance b ("50 m");
	wcout << "a + b: " << (a + b) << endl;
	wcout << "a - b: " << (a - b) << endl;
	wcout << "a * b: " << (a * b) << endl; // TODO: Test unit constructors first. We need auto_scalar here!
	wcout << "a / b: " << (a / b) << endl;
	length c = 100_m;
	wcout << "c: " << c << endl;
	length d = 50_dam;
	d = c;
	wcout << "d: " << d << endl;
	/*physics::units::frequency e ("50 Hz");
	wcout << "e: " << e << endl;*/
	length f = d;
	wcout << "f: " << f << endl;
	charge g = 10_C;
	wcout << "g: " << g << endl;
}

void test_unit()
{
	/*boost::locale::generator gen;
	locale new_locale = locale(gen("de_DE.UTF-8"));
	cout.imbue(new_locale);*/
	wcout << endl;
	wcout << "Testing unit:" << endl << endl;
	unit a(100,"g");
	wcout << "a: " << a << endl;
	unit b(100.5,"g");
	wcout << "b: " << b << endl;
	physics::units::unit f("50 N2");
	wcout << "f: " << f << endl;
	physics::units::unit i("20 kg2*m2/s4");
	wcout << (f + i) << endl;
	wcout << "f ^ 2: " << (f ^ 2) << endl;
	wcout << "f + 50: " << (f + 50) << endl;
	wcout << "50 + f: " << (50 + f) << endl;
	wcout << "f - 50: " << (f - 50) << endl;
	wcout << "50 - f: " << (50 - f) << endl;
	wcout << "f * 50: " << (f * 50) << endl;
	wcout << "50 * f: " << (50 * f) << endl;
	wcout << "f / 50: " << (f / 50) << endl;
	wcout << "50 / f: " << (50 / f) << endl;
	wcout << "f ^ 2: " << (f ^ 22) << endl;
	wcout << "sqrt(f ^ 2): " << sqrt(f ^ 2) << endl;
	wcout << f << endl;
	physics::units::unit g("5 1/s");
	wcout << "g: " << g << endl;
	physics::units::time h("5 s");
	wcout << "h :" << h << endl;
	wcout << "g * h: " << (g * h) << endl;
	cout << get_dimension_structure(f.get_actual_dimensions()) << endl;

	//cout << "50 ^ (f / (x * z)): " << (50 ^ (f / (x*z))) << endl;
}

void test_unit_number()
{
	unit_number x (100);
	unit_number z (50);
	wcout << x << endl;
	wcout << z << endl;
	wcout << "Basic operations of two unit numbers:" << endl;
	wcout << "sum: " << (x + z) << endl;
	wcout << "substract: " << (x - z) << endl;
	wcout << "multiply: " << (x * z) << endl;
	wcout << "division: " << (x / z) << endl;
	wcout << "power: " << (x ^ z) << endl;
	wcout << "Basic operations of a unit number with and integer, returning a unit number:" << endl;
	unit_number f(4);
	wcout << (f + 50) << endl;
	wcout << (50 + f) << endl;
	wcout << (f - 50) << endl;
	wcout << (50 - f) << endl;
	wcout << (f * 50) << endl;
	wcout << (50 * f) << endl;
	wcout << (f / 50) << endl;
	wcout << (50 / f) << endl;
	wcout << (f ^ 2) << endl;
	wcout << (50 ^ f) << endl;
}

void test_vector_unit()
{
	wcout << "Testing vectors: " << endl;
	test_vector_unit_1d();

	/*force c (50_N,50,30);
	wcout << c << endl;
	wcout << c.x_projection() << endl;
	force d (20_N,40,20);
	wcout << (c + d) << endl;
	wcout << (c - d) << endl;
	wcout << force(c * d) << endl;*/
	//wcout << force(d * c) << endl;
}

void test_vector_unit_1d()
{
	wcout << "Testing vectors 1D: " << endl;
	force a (50_N,direction_symbol::left);
	force b (20_N,direction_symbol::right);
	wcout << "a: " << a << endl;
	wcout << "b: " << b << endl;
	wcout << "a.x: " << a.x_projection() << endl;
	wcout << "b.x: " << b.x_projection() << endl;

	wcout << "1D operations with vectors:" << endl;
	wcout << "a + b: " << (a + b) << endl;
	wcout << "a - b: " << (a - b) << endl;

	wcout << "1D operations with scalars:" << endl;
	// TODO: Here operations with scalars (it needs auto_scalar)

	wcout << "1D operations with numbers:" << endl;
	wcout << "a + 40: " << (a + 40) << endl;
	wcout << "a - 10: " << (a - 10) << endl;
	wcout << "a * 3: " << (a * 3) << endl;
	wcout << "a / 5: " << (a / 5) << endl;
	wcout << "a ^ 2: " << force(a ^ 2) << endl;
	force c (10_N,direction_symbol::left);
	wcout << "c: " << c << endl;
	c += 25;
	wcout << "c += 25: " << c << endl;
	force d (20_N,direction_symbol::left);
	wcout << "d: " << d << endl;
	d -= 5;
	wcout << "d -= 5: " << d << endl;
	force e (15_N,direction_symbol::left);
	wcout << "e: " << e << endl;
	e *= 10;
	wcout << "e *= 10: " << e << endl;
	force f (30_N,direction_symbol::left);
	wcout << "f: " << f << endl;
	f /= 5;
	wcout << "f /= 5: " << f << endl;
	force g (5_N,direction_symbol::left);
	wcout << "g: " << g << endl;
	g ^= 2;
	wcout << "g ^= 2: " << g << endl;
}
