#ifndef SCIFIR_UNITS_UTIL_TYPES_HPP_INCLUDED
#define SCIFIR_UNITS_UTIL_TYPES_HPP_INCLUDED

#include <string>

using namespace std;

namespace scifir
{
	float parse_float(const string& x);
	int parse_int(const string& x);
	string display_float(const float& value,int number_of_decimals = 2);
	string display_double(const double& value,int number_of_decimals = 2);
	string display_long_double(const long double& value,int number_of_decimals = 2);
}

#endif // SCIFIR_UNITS_UTIL_TYPES_HPP_INCLUDED
