#include "util/types.hpp"

using namespace std;

namespace msci
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
}
