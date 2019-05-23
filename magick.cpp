#include "units.hpp"
//#include "math/algebra/math_variable.hpp"
//#include "spatial_math.hpp"
//#include "chemistry.hpp"

#include "boost/locale.hpp"
#include "boost/variant.hpp"
#include "boost/math/constants/constants.hpp"

#include <cfloat>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <complex>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <type_traits>

using namespace std;
using namespace msci;

/*void memory_consumption();
void test_angle_number();
void test_atom();
void test_basic_unit();
void test_lab_number();
void test_matrix();

void test_dimension_container();
void test_unit();
void test_unit_number();
void test_auto_unit();
void test_scalar_unit();
void test_vector_unit();
void test_vector_unit_1d();*/

int main()
{
	cout << "Do you guess? This is the superb library of science MagickScience! We are testing units today, enjoy :D" << endl << endl;

	msci::auto_vector a ("100 N",10,10);
	cout << a << endl;

	msci::auto_vector b ("50 N",10,10);
	cout << b << endl;
	cout << (a - b) << endl;

	/*msci::auto_vector a ("100 N",10,10);
	cout << a << endl;

	msci::auto_scalar b_unit(100,"N");
	msci::math_variable b ("Nb",b_unit);
	cout << b << endl;

	msci::auto_scalar c_unit(50,"N");
	msci::math_variable c ("Nc",c_unit);
	cout << c << endl;

	cout << b * (b + c) + b * c << endl;*/

	/*atom_H a = atom_H();
	if (a.get_enum_type() == atom_symbol::H)
	{
		cout << "Atom H!" << endl;
	}
	if (a.get_atomic_group() == IA)
	{
		cout << "Atomic group IA" << endl;
	}
	cout << "period: " << a.get_period() << endl;
	if (a.get_atomic_block() == atomic_block::s)
	{
		cout << "Atomic block s" << endl;
	}
	cout << "z: " << a.get_z() << endl;
	cout << "mass number: " << a.get_mass_number() << endl;
	cout << "electronegativity: " << a.get_electronegativity() << endl;
	if (a.is_radioactive() == false)
	{
		cout << "radioactive atom" << endl;
	}*/

	/*msci::polygon poly ({{0,0},{1,0},{2,2},{0,1}});
	cout << poly << endl;
	msci::point_2d p1 (0.5,0.5);
	if (poly.is_inside(p1))
	{
		cout << "inside the polygon!" << endl;
	}
	else
	{
		cout << "not inside the polygon :(" << endl;
	}

	msci::line_2d line1 ({0,0},{1,0});
	cout << line1 << endl;

	msci::line_3d line2 ({0,0,0},{1,0,1});
	cout << line2 << endl;*/

	// TASK: CHECK DIMENSIONS OF VECTORS
	//auto_vector b ("100 m",10);
	//auto_vector c ("100 g",10);
	//auto_vector d ("200 m",10);

	/*msci::normal_molecule molecule_a ("example_molecule.xml");
	cout << molecule_a.get_canonical_formula() << endl;
	molecule_a.save("","example1.xml");
	msci::normal_molecule molecule_b ("<molecule><atoms>O O</atoms><bonds>2;1</bonds></molecule>");
	molecule_b.save("","example2.xml");
	cout << molecule_a.get_canonical_formula() << endl;
	cout << molecule_a.get_standard_atomic_mass() << endl;
	cout << molecule_a.get_real_mass() << endl;*/

	// READY FOR A TASK, ASK IRC
	/*map<int,unique_ptr<abstract_dimension>> a_map = map<int,unique_ptr<abstract_dimension>>();
	a_map[0] = unique_ptr<dimension>(create_dimension("m"));
	a_map[1] = unique_ptr<abbreviation>(create_abbreviation("N"));
	for (const auto& new_dimension : a_map)
	{
		cout << *new_dimension.second << endl;
	}
	map<int,unique_ptr<abstract_dimension>> b_map = map<int,unique_ptr<abstract_dimension>>();
	for (auto& new_dimension : a_map)
	{
		unique_ptr<abbreviation> new_abbreviation_ptr (dynamic_cast<abbreviation*>(new_dimension.second.release()));
		if (new_abbreviation_ptr)
		{
			b_map[new_dimension.first] = new_abbreviation_ptr;
		}
		unique_ptr<dimension> new_dimension_ptr = dynamic_cast<dimension>(new_dimension.second);
		if (new_dimension_ptr)
		{
			b_map[new_dimension.first] = new_dimension_ptr;
		}
	}*/

	// READY FOR A TASK
	/*force a ("500 N",10,10);
	cout << a << endl;
	force b ("200 N",30,10);
	cout << b << endl;
	cout << angle_between_vectors(a,b) << endl;*/

	//temperature b ("100 K");
	//cout << b << endl;

	// READY FOR A TASK
	/*msci::force a ("50 000 N",10,10);
	cout << a << endl;
	velocity b ("20 000 m/s",10,10);
	cout << b << endl;
	msci::force c = msci::force(b);
	cout << c << endl;*/

	//test_atom();
	//test_dimension_container();
	//test_unit();
	//test_auto_unit();
	//test_scalar_unit();
	//test_basic_unit();
	cout << endl << endl;
	//test_vector_unit();

	/*msci::hyper_spherical_coordinates a (10,90,0);
	cout << a.get_r() << endl;
	//cout << a.get_angle1() << endl;
	//cout << a.get_angle2() << endl;
	cout << setprecision(2);
	cout << a.x_projection() << endl;
	cout << a.y_projection() << endl;
	cout << a.z_projection() << endl;*/
}

/*void memory_consumption()
{
	cout << "msci::unit_number: " << sizeof(msci::unit_number) << endl;
	cout << "msci::undefined_number: " << sizeof(msci::undefined_number<unit_number>) << endl;
	cout << "msci::space_type (float): " << sizeof(msci::space_type) << endl;
	cout << "msci::unit: " << sizeof(msci::unit) << endl;
}

void test_angle_number()
{
	msci::angle_number a = 40;
	cout << a << endl;
	cout << (a + 50) << endl;
	cout << (a - 50) << endl;
	cout << (a * 50) << endl;
	cout << (a / 50) << endl;
	cout << (a ^ 50) << endl;
	msci::angle_number b = 50;
	b = a;
	b += 50;
	cout << b << endl;
	msci::angle_number c = 50;
	c -= 234;
	cout << c << endl;
	msci::angle_number d = 50;
	d *= 10;
	cout << d << endl;
	msci::angle_number e = 50;
	e /= 10;
	cout << e << endl;
	msci::angle_number f = 50;
	f ^= 2;
	cout << f << endl;
	cout << (e + f) << endl;
	cout << (e - f) << endl;
	msci::angle_number g = 50;
	msci::angle_number h = 120;
	g += h;
	cout << g << endl;
	msci::angle_number i = 50;
	msci::angle_number j = 120;
	i -= j;
	cout << i << endl;
	cout << "type-cast to float: " << float(i) << endl;
	cout << "sin(angle_number): " << msci::sin(msci::angle_number(0)) << endl;
	cout << "cos(angle_number): " << msci::cos(msci::angle_number(90)) << endl;
	cout << "tan(angle_number): " << msci::tan(msci::angle_number(0)) << endl;
	cout << "asin(angle_number): " << msci::asin(msci::angle_number(0)) << endl;
	cout << "acos(angle_number): " << msci::acos(msci::angle_number(1)) << endl;
	cout << "atan(angle_number): " << msci::atan(msci::angle_number(0)) << endl;
	cout << "sinh(angle_number): " << msci::sinh(msci::angle_number(0)) << endl;
	cout << "cosh(angle_number): " << msci::cosh(msci::angle_number(90)) << endl;
	cout << "tanh(angle_number): " << msci::tanh(msci::angle_number(0)) << endl;
	cout << "asinh(angle_number): " << msci::asinh(msci::angle_number(0)) << endl;
	cout << "acosh(angle_number): " << msci::acosh(msci::angle_number(1)) << endl;
	cout << "atanh(angle_number): " << msci::atanh(msci::angle_number(0)) << endl;
}

void test_atom()
{
	cout << "z: " << msci::atom_H::z << endl;
	msci::atom_H atom_h = msci::atom_H();
	cout << atom_h.get_period() << endl;
	atom_h.print();
}

void test_basic_unit()
{
	cout << "Testing basic units:" << endl << endl;
	length a = 100_m;
	cout << "a: " << a << endl;
	mass b = 100_g;
	cout << "b: " << b << endl;
	msci::time c = 100_s;
	cout << "c: " << c << endl;
	charge d = 100_C;
	cout << "d: " << d << endl;
	temperature e = 100_K;
	cout << "e: " << e << endl;
	mole f = 100_mol;
	cout << "f: " << f << endl;
	light g = 100_cd;
	cout << "g: " << g << endl;
	data h = 100_B;
	cout << "h: " << h << endl;
}

void test_lab_number()
{
	msci::lab_number a (100,5);
	cout << "a: " << a << endl;
	msci::lab_number b (20,2);
	cout << "b: " << b << endl;
	cout << "a + b: " << (a + b) << endl;
	cout << "a - b: " << (a - b) << endl;
	cout << "a * b: " << (a * b) << endl;
	cout << "a / b: " << (a / b) << endl;
	cout << "a ^ b: " << (a ^ b) << endl;
	cout << "a + 50: " << (a + 50) << endl;
	cout << "a - 20: " << (a - 20) << endl;
	cout << "a * 10: " << (a * 10) << endl;
	cout << "a / 5: " << (a / 5) << endl;
	cout << "a ^ 3: " << (a ^ 3) << endl;
}

void test_matrix()
{
	matrix<int,3,3> x {{1,2,3},{1,7,6},{5,4,2}};
	matrix<int,3,3> y {{2,3,4},{4,5,6},{7,8,9}};
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "x row size: " << x.row_size() << endl;
	cout << "x column size: " << x.column_size() << endl;
	cout << "x row: " << x.row(1) << endl;
	cout << "x column: " << x.column(1) << endl;
	cout << "x + y: " << (x + y) << endl;
	cout << "x - y: " << (x - y) << endl;
	cout << "x * y: " << (x * y) << endl;
	cout << "x ^ 2: " << (x ^ 2) << endl;
	cout << "x transpose: " << x.t() << endl;
}

void test_scalar_unit()
{
	cout << "Testing scalar unit:" << endl << endl;
	msci::distance a ("50 km");
	cout << "a: " << a << endl;
	msci::distance b ("50 m");
	cout << "a + b: " << (a + b) << endl;
	cout << "a - b: " << (a - b) << endl;
	cout << "a * b: " << (a * b) << endl;
	cout << "a / b: " << (a / b) << endl;
	length c = 100_m;
	cout << "c: " << c << endl;
	length d = 50_dam;
	cout << "d: " << d << endl;
	length f = d;
	cout << "f: " << f << endl;
	charge g = 10_C;
	cout << "g: " << g << endl;
	cout << endl;
}

void test_dimension_container()
{
	cout << "Testing dimension container: " << endl << endl;
	vector_real_dimensions a = create_real_dimensions("g");
	cout << "create_real_dimensions(\"g\"): " << a << endl;
	a = create_real_dimensions("g*m");
	cout << "create_real_dimensions(\"g*m\"): " << a << endl;
	a = create_real_dimensions("N");
	cout << "create_real_dimensions(\"N\"): " << a << endl;
	vector_actual_dimensions b = create_actual_dimensions("g");
	cout << "create_actual_dimensions(\"g\"): " << b << endl;
	b = create_actual_dimensions("g*m");
	cout << "create_actual_dimensions(\"g*m\"): " << b << endl;
	b = create_actual_dimensions("N");
	cout << "create_actual_dimensions(\"N\"): " << b << endl;
	cout << endl;
}

void test_unit()
{
	cout << endl;
	cout << "Testing unit:" << endl << endl;
	auto_unit a(100,"g");
	cout << "a: " << a << endl;
	auto_unit b(100.5,"g");
	cout << "b: " << b << endl;
	msci::auto_unit f("50 N2");
	cout << "f: " << f << endl;
	msci::auto_unit i("20 kg2*m2/s4");
	cout << (f + i) << endl;
	cout << "f ^ 2: " << (f ^ 2) << endl;
	cout << "f + 50: " << (f + 50) << endl;
	cout << "50 + f: " << (50 + f) << endl;
	cout << "f - 50: " << (f - 50) << endl;
	cout << "50 - f: " << (50 - f) << endl;
	cout << "f * 50: " << (f * 50) << endl;
	cout << "50 * f: " << (50 * f) << endl;
	cout << "f / 50: " << (f / 50) << endl;
	cout << "50 / f: " << (50 / f) << endl;
	cout << "f ^ 2: " << (f ^ 22) << endl;
	cout << "sqrt(f ^ 2): " << sqrt(f ^ 2) << endl;
	cout << f << endl;
	msci::auto_unit g("5 1/s");
	cout << "g: " << g << endl;
	msci::time h("5 s");
	cout << "h :" << h << endl;
	cout << "g * h: " << (g * h) << endl;
	cout << get_dimension_structure(f.get_actual_dimensions()) << endl;
}

void test_unit_number()
{
	unit_number x (100);
	unit_number z (50);
	cout << x << endl;
	cout << z << endl;
	cout << "Basic operations of two unit numbers:" << endl;
	cout << "sum: " << (x + z) << endl;
	cout << "substract: " << (x - z) << endl;
	cout << "multiply: " << (x * z) << endl;
	cout << "division: " << (x / z) << endl;
	cout << "power: " << (x ^ z) << endl;
	cout << "Basic operations of a unit number with and integer, returning a unit number:" << endl;
	unit_number f(4);
	cout << (f + 50) << endl;
	cout << (50 + f) << endl;
	cout << (f - 50) << endl;
	cout << (50 - f) << endl;
	cout << (f * 50) << endl;
	cout << (50 * f) << endl;
	cout << (f / 50) << endl;
	cout << (50 / f) << endl;
	cout << (f ^ 2) << endl;
	cout << (50 ^ f) << endl;
}

void test_auto_unit()
{

}

void test_vector_unit()
{
	cout << "Testing vectors: " << endl;
	test_vector_unit_1d();

	force c (50_N,50,30);
	cout << "vector" << endl;
	cout << c << endl;
	cout << "a" << endl;
	cout << c.x_projection() << endl;
	cout << "b" << endl;
	force d (20_N,40,20);
	cout << (c + d) << endl;
	cout << (c - d) << endl;
	cout << force(c * d) << endl;
	cout << force(d * c) << endl;
}

void test_vector_unit_1d()
{
	cout << "Testing vectors 1D: " << endl;
	force a (50_N,direction_symbol::left);
	force b (20_N,direction_symbol::right);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "a.x: " << a.x_projection() << endl;
	cout << "b.x: " << b.x_projection() << endl;

	cout << "1D operations with vectors:" << endl;
	cout << "a + b: " << (a + b) << endl;
	cout << "a - b: " << (a - b) << endl;

	cout << "1D operations with scalars:" << endl;

	cout << "1D operations with numbers:" << endl;
	cout << "a + 40: " << (a + 40) << endl;
	cout << "a - 10: " << (a - 10) << endl;
	cout << "a * 3: " << (a * 3) << endl;
	cout << "a / 5: " << (a / 5) << endl;
	cout << "a ^ 2: " << force(a ^ 2) << endl;
	force c (10_N,direction_symbol::left);
	cout << "c: " << c << endl;
	c += 25;
	cout << "c += 25: " << c << endl;
	force d (20_N,direction_symbol::left);
	cout << "d: " << d << endl;
	d -= 5;
	cout << "d -= 5: " << d << endl;
	force e (15_N,direction_symbol::left);
	cout << "e: " << e << endl;
	e *= 10;
	cout << "e *= 10: " << e << endl;
	force f (30_N,direction_symbol::left);
	cout << "f: " << f << endl;
	f /= 5;
	cout << "f /= 5: " << f << endl;
	force g (5_N,direction_symbol::left);
	cout << "g: " << g << endl;
	g ^= 2;
	cout << "g ^= 2: " << g << endl;
}/*

/*boost::locale::generator gen;
	locale new_locale = locale(gen("de_DE.UTF-8"));
	cout.imbue(new_locale);*/
