#include "msci/units/meca_number/unit_number.hpp"

#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

namespace msci
{
	unit_number::unit_number() : undefined_number<unit_number>()
	{
	}

	unit_number::unit_number(msci::space_type new_value) : undefined_number<unit_number>(new_value)
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

	string unit_number::print(int number_of_decimals) const
	{
		ostringstream output;
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
				string message;
				switch(get_error_code())
				{
					case 7:
						message = "Cannot initialize to different dimensions";
						break;
					case 8:
						message = "Cannot sum different dimensions";
						break;
					case 9:
						message = "Cannot substract different dimensions";
						break;
					case 10:
						message = "Exponent of dimensions doesn't exist";
						break;
					case 11:
						message = "Cannot set dimensions to a different nd";
						break;
					case 12:
						message = "Temperature prefixes cannot be negative";
						break;
					case 13:
						message = "Cannot cross-product non-3D or undefined vectors";
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

ostream& operator <<(ostream& os, const msci::unit_number& x)
{
	return os << x.print();
}
