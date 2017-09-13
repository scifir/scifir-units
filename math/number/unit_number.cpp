#include "unit_number.hpp"

#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

namespace math
{
	unit_number::unit_number() : undefined_number<unit_number>()
	{
	}

	unit_number::unit_number(math::space_type new_value) : undefined_number<unit_number>(new_value)
	{
	}

	void unit_number::operator =(const unit_number& new_number)
	{
		value = new_number.get_value();
		if(!new_number.is_defined())
		{
			invalidate(1);
		}
		else
		{
			error_code = 0;
		}
	}

	wstring unit_number::print(int number_of_decimals) const
	{
		wostringstream output;
		double integer_part;
		modf(get_value(),&integer_part);
		output << setprecision(to_string(int(integer_part)).length() + number_of_decimals);
		if(is_defined())
		{
			if(get_value() >= 0)
			{
				output << get_value();
			}
			else
			{
				output << "Wrong value: " << get_value();
			}
			return output.str();
		}
		else
		{
			if(get_error_code() > 6)
			{
				output << "undefined";
				wstring message;
				switch(get_error_code())
				{
					case 7:
						message = L"Cannot initialize to different dimensions";
						break;
					case 8:
						message = L"Cannot sum different dimensions";
						break;
					case 9:
						message = L"Cannot substract different dimensions";
						break;
					case 10:
						message = L"Exponent of dimensions doesn't exist";
						break;
					case 11:
						message = L"Cannot set dimensions to a different nd";
						break;
					case 12:
						message = L"Temperature prefixes cannot be negative";
						break;
					case 13:
						message = L"Cannot cross-product non-3D or undefined vectors";
				}
				output << " " << message;
				return output.str();

			}
			else
			{
				return undefined_number<unit_number>::print();
			}
		}
	}
}

wostream& operator <<(wostream& os, const math::unit_number& x)
{
	return os << x.print();
}
