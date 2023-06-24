#ifndef MSCI_UNITS_UTIL_TYPES_HPP_INCLUDED
#define MSCI_UNITS_UTIL_TYPES_HPP_INCLUDED

#include <string>

using namespace std;

namespace msci
{
	float parse_float(const string&);
	int parse_int(const string&);
	string display_float(const float&,int = 2);
}

#endif // MSCI_UNITS_UTIL_TYPES_HPP_INCLUDED
