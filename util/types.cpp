#include "util/types.hpp"

#include <cmath>
#include <sstream>

using namespace std;

namespace scifir
{
	float parse_float(const string& x)
	{
		try
		{
			float value = stof(x);
			return value;
		}
		catch (const exception& e)
		{
			return 0;
		}
	}

	int parse_int(const string& x)
	{
		try
		{
			int value = stoi(x);
			return value;
		}
		catch (const exception& e)
		{
			return 0;
		}
	}

	string display_float(const float& value,int number_of_decimals)
	{
		ostringstream output;
		if (number_of_decimals > 0)
		{
			float fract_value,int_value;
			fract_value = modf(value,&int_value);
			output << (int)int_value;
			if (fract_value != 0)
			{
				output << ".";
				output << int(fract_value*std::pow(10,number_of_decimals));
			}
		}
		else
		{
			output << value;
		}
		return output.str();
	}
}
