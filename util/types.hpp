#ifndef SCIFIR_UNITS_UTIL_TYPES_HPP_INCLUDED
#define SCIFIR_UNITS_UTIL_TYPES_HPP_INCLUDED

#include <string>

using namespace std;

namespace scifir
{
	float parse_float(const string&);
	int parse_int(const string&);
	string display_float(const float&,int = 2);
}

#endif // SCIFIR_UNITS_UTIL_TYPES_HPP_INCLUDED
