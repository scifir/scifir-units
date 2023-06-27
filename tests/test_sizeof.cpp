#include "units.hpp"
#include "special_units/ph.hpp"
#include "special_units/aid.hpp"

#include <iostream>
#include <string>

using namespace std;

class test_empty_class
{
	public:
		test_empty_class();

	private:
		bool b;
		dimension a[];
};

test_empty_class::test_empty_class()
{}

int main()
{
	cout << "short: " << sizeof(short) << endl;
	cout << "int: " << sizeof(int) << endl;
	cout << "long int: " << sizeof(long int) << endl;
	cout << "long long int: " << sizeof(long long int) << endl;
	cout << "unsigned short: " << sizeof(unsigned short) << endl;
	cout << "unsigned int: " << sizeof(unsigned int) << endl;
	cout << "unsigned long int: " << sizeof(unsigned long int) << endl;
	cout << "unsigned long long int: " << sizeof(unsigned long long int) << endl;
	cout << "float: " << sizeof(float) << endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "long double: " << sizeof(long double) << endl;
	cout << "string: " << sizeof(string) << endl;
	cout << "string*: " << sizeof(string*) << endl;
	cout << endl;
	cout << "empty-class: " << sizeof(test_empty_class) << endl;
	cout << endl;
	cout << "prefix: " << sizeof(prefix) << endl;
	cout << "dimension: " << sizeof(dimension) << endl;
	cout << "vector<float>: " << sizeof(vector<float>) << endl;
	cout << "vector<dimension>: " << sizeof(vector<dimension>) << endl;
	cout << "dimension[]: " << sizeof(dimension[1]) << endl;
	cout << endl;
	cout << "angle: " << sizeof(angle) << endl;
	cout << "lab_number: " << sizeof(lab_number<length>) << endl;
	cout << endl;
	cout << "scalar_unit: " << sizeof(scalar_unit) << endl;
	cout << "vector_unit_2d: " << sizeof(vector_unit_2d) << endl;
	cout << "vector_unit_3d: " << sizeof(vector_unit_3d) << endl;
	cout << "vector_unit_nd: " << sizeof(vector_unit_nd) << endl;
	cout << endl;
	cout << "point_1d: " << sizeof(point_1d<float>) << endl;
	cout << "point_2d: " << sizeof(point_2d<float>) << endl;
	cout << "point_3d: " << sizeof(point_3d<float>) << endl;
	cout << "point_nd: " << sizeof(point_nd<length>) << endl;
	cout << endl;
	cout << "coordinates_1d: " << sizeof(coordinates_1d<float>) << endl;
	cout << "coordinates_2d: " << sizeof(coordinates_2d<float>) << endl;
	cout << "coordinates_3d<float>: " << sizeof(coordinates_3d<float>) << endl;
	cout << "coordinates_nd: " << sizeof(coordinates_nd<length>) << endl;
	cout << endl;
	//dimension a = dimension("hello_dimension",prefix(prefix::no_prefix),dimension::positive);
	//dimension b = dimension("hello_dimension2",prefix(prefix::no_prefix),dimension::positive);
	//dimension c = dimension("hello_dimension3",prefix(prefix::no_prefix),dimension::positive);
	//dimension d = dimension("hello_dimension4",prefix(prefix::no_prefix),dimension::positive);
	//dimension e = dimension("hello_dimension5",prefix(prefix::no_prefix),dimension::positive);
	//cout << "a: " << a.get_symbol() << endl;
	//cout << "b: " << b.get_symbol() << endl;
	//cout << "c: " << c.get_symbol() << endl;
	//cout << "d: " << d.get_symbol() << endl;
	//cout << "e: " << e.get_symbol() << endl;
	//cout << "custom dimension: " << create_dimension("hello_here1",dimension::positive) << endl;
	scalar_unit f = scalar_unit("20 hellohere1");
	cout << "f: " << f << endl;
	cout << "f dimensions: " << f.get_dimensions()[0].get_symbol() << endl;
	cout << "g: " << sqrt(scalar_unit("10000 m4")) << endl;
	//dimension a = dimension(dimension::Ohm,prefix::no_prefix,dimension::positive);
	//cout << "resistance dimension: " << a << endl;
	//vector<dimension> new_dimensions {create_dimension("km",dimension::positive),create_dimension("m",dimension::positive),create_dimension("s",dimension::positive),dimension(dimension::Ohm,prefix::no_prefix,dimension::negative),dimension(dimension::B,prefix::Y,dimension::negative)};
	//cout << to_string(new_dimensions) << endl;
	//cout << scalar_unit("10 usd") << endl;
	//scalar_unit c = scalar_unit("10 usd");
	//cout << "custom symbol: " << reinterpret_cast<const msci::custom_dimension&>(c.get_dimensions()[0]).get_symbol() << endl;
	//if (c.get_dimensions()[0].dimension_type == dimension::custom)
	//{
	//	cout << "custom dimension type" << endl;
	//}
	//msci::custom_dimension b = msci::custom_dimension("asdf",prefix(),dimension::positive);
	//cout << b.get_symbol() << endl;
	pH phA = pH(6);
	cout << "pH" << phA << endl;

	point_1d<length> x_point_1d = point_1d<length>("10 m");
	cout << "x_point_1d: " << x_point_1d << endl;
	point_1d<float> y_point_1d = point_1d<float>("30");
	cout << "y_point_1d: " << y_point_1d << endl;
	coordinates_1d<length> x_coordinates_1d = coordinates_1d<length>("30 m");
	cout << "x_coordinates_1d: " << x_coordinates_1d << endl;
	coordinates_1d<float> y_coordinates_1d = coordinates_1d<float>("30");
	cout << "y_coordinates_1d: " << y_coordinates_1d << endl;

	point_2d<length> x_point_2d = point_2d<length>("10 m,30 m");
	cout << "x_point_2d: " << x_point_2d << endl;
	point_2d<float> y_point_2d = point_2d<float>("30,20");
	cout << "y_point_2d: " << y_point_2d << endl;
	coordinates_2d<length> x_coordinates_2d = coordinates_2d<length>("30 m,5 m");
	cout << "x_coordinates_2d: " << x_coordinates_2d << endl;
	coordinates_2d<float> y_coordinates_2d = coordinates_2d<float>("30,5");
	cout << "y_coordinates_2d: " << y_coordinates_2d << endl;

	point_3d<length> x_point = point_3d<length>("10000000 m,30 m,20 m");
	cout << "x_point_3d: " << x_point << endl;
	point_3d<float> y_point = point_3d<float>("30 m,20º");
	cout << "y_point_3d: " << y_point << endl;
	coordinates_3d<length> x_coordinates = coordinates_3d<length>("30 m,5 m,10 m");
	cout << "x_coordinates_3d: " << x_coordinates << endl;
	coordinates_3d<float> y_coordinates = coordinates_3d<float>("30,5,10");
	cout << "y_coordinates_3d: " << y_coordinates << endl;

	point_nd<length> x_point_nd = point_nd<length>("10 m,30 m,20 m");
	cout << "x_point_nd: " << x_point_nd << endl;
	point_nd<float> y_point_nd = point_nd<float>("30 m,20º");
	cout << "y_point_nd: " << y_point_nd << endl;
	coordinates_nd<length> x_coordinates_nd = coordinates_nd<length>("30 m,5 m,10 m");
	cout << "x_coordinates_nd: " << x_coordinates_nd << endl;
	coordinates_nd<float> y_coordinates_nd = coordinates_nd<float>("30,5,10");
	cout << "y_coordinates_nd: " << y_coordinates_nd << endl;

	coordinates_2dr<length> x_coordinates_2dr = coordinates_2dr<length>("30.532 m,5.123 m;10.5º");
	cout << "x_coordinates_2dr: " << x_coordinates_2dr << endl;
	coordinates_2dr<float> y_coordinates_2dr = coordinates_2dr<float>("30,5;10º");
	cout << "y_coordinates_2dr: " << y_coordinates_2dr << endl;

	coordinates_3dr<length> x_coordinates_3dr = coordinates_3dr<length>("30 m,5 m,10 m;10º,20º");
	cout << "x_coordinates_3dr: " << x_coordinates_3dr << endl;
	coordinates_3dr<float> y_coordinates_3dr = coordinates_3dr<float>("30,5,10;10º,15º");
	cout << "y_coordinates_3dr: " << y_coordinates_3dr << endl;

	coordinates_ndr<length> x_coordinates_ndr = coordinates_ndr<length>("30 m,5 m,10 m,20 m;10º,20º,30º");
	cout << "x_coordinates_ndr: " << x_coordinates_ndr << endl;
	coordinates_ndr<float> y_coordinates_ndr = coordinates_ndr<float>("30,5,10,20;10º,15º,20º");
	cout << "y_coordinates_ndr: " << y_coordinates_ndr << endl;

	angle x_angle = angle(34);
	cout << "x_angle: " << to_string(x_angle) << endl;
	/*point_nd x_coordinates = point_nd("10º,20º,30 m");
	cout << "x_coordinates: " << x_coordinates << endl;
	point_nd y_coordinates = point_nd("30 m,20º,10 m");
	cout << "y_coordinates: " << y_coordinates << endl;
	point_nd z_coordinates = point_nd("30 m,10º,20º");
	cout << "z_coordinates: " << z_coordinates << endl;
	point_nd a_coordinates = point_nd("10 m,10 m,10 m");
	cout << "a_coordinates: " << a_coordinates << endl;*/
	aid aidA = aid(astronomical_body::EARTH);
	cout << "aidA: " << aidA << endl;
	
	mass a(100,"g");
	mass b(50,"g");
	if ((a + b) == 150_g)
	{
		cout << "match!" << endl;
	}
}
