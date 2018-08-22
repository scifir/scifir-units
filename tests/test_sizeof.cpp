#include "msci/units/meca_numbers.hpp"
#include "msci/units.hpp"

#include <iostream>
#include <string>

using namespace std;

enum test_enum {a,b,c};

class test_empty_class
{
	public:
		test_empty_class();

	private:
		int a;
};

test_empty_class::test_empty_class() : a()
{
}

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
	cout << "prefix: " << sizeof(msci::prefix) << endl;
	cout << "abstract_dimension: " << sizeof(msci::abstract_dimension) << endl;
	cout << "dimension: " << sizeof(msci::dimension) << endl;
	cout << "abbreviation: " << sizeof(msci::abbreviation) << endl;
	cout << endl;
	cout << "angle_number: " << sizeof(msci::angle_number) << endl;
	cout << "lab_number: " << sizeof(msci::lab_number) << endl;
	cout << "unit_number: " << sizeof(msci::unit_number) << endl;
	cout << endl;
	cout << "unit: " << sizeof(msci::unit) << endl;
	cout << "scalar_unit: " << sizeof(msci::scalar_unit) << endl;
	cout << "vector_unit: " << sizeof(msci::vector_unit) << endl;
	cout << "auto_unit: " << sizeof(msci::auto_unit) << endl;
	cout << "auto_scalar: " << sizeof(msci::auto_scalar) << endl;
	cout << "auto_vector: " << sizeof(msci::auto_vector) << endl;
}
