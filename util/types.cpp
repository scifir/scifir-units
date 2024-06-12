#include "./types.hpp"

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
			output << (std::trunc(value*std::pow(10,number_of_decimals)) / std::pow(10,number_of_decimals));
		}
		else
		{
			output << value;
		}
		if (output.str() == "-0")
		{
			return "0";
		}
		else
		{
			return output.str();
		}
	}
}
