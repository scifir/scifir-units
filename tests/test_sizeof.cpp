#include "meca_numbers.hpp"
#include "coordinates.hpp"
#include "units.hpp"

#include <iostream>
#include <string>

using namespace std;

enum test_enum {a,b,c};

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
	cout << endl;
	cout << "enum: " << sizeof(test_enum) << endl;
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
	cout << "point_1d: " << sizeof(point_1d) << endl;
	cout << "point_2d: " << sizeof(point_2d) << endl;
	cout << "point_3d: " << sizeof(point_3d) << endl;
	cout << "point_nd: " << sizeof(point_nd) << endl;
	cout << endl;
	cout << "coordinates_1d: " << sizeof(coordinates_1d) << endl;
	cout << "coordinates_2d: " << sizeof(coordinates_2d) << endl;
	cout << "coordinates_3d: " << sizeof(coordinates_3d) << endl;
	cout << "coordinates_nd: " << sizeof(coordinates_nd) << endl;
}
