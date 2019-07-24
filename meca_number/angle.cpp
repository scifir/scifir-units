#include "msci/units/meca_number/angle.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

namespace msci
{
	angle::angle() : value(0)
	{
	}

	angle::angle(float x) : value(x)
	{
		normalize_value();
	}

	angle::angle(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = float(x);
			normalize_value();
		}
	}

	angle angle::operator +(const angle& x) const
	{
		return angle(value + x.get_value());
	}

	angle angle::operator -(const angle& x) const
	{
		return angle(value - x.get_value());
	}

	void angle::operator +=(const angle& x)
	{
		value += x.get_value();
		normalize_value();
	}

	void angle::operator -=(const angle& x)
	{
		value -= x.get_value();
		normalize_value();
	}

	void angle::invert()
	{
		value += 180;
		normalize_value();
	}

	void angle::normalize_value()
	{
		if(isfinite(value))
		{
			if (value >= 360)
			{
				float decimal_part;
				float value_remainder = modf(value / 360,&decimal_part);
				value = value_remainder * 360;
			}
			else if (value < 0)
			{
				float decimal_part;
				float value_remainder = modf(value / 360,&decimal_part);
				value = 360 - std::abs(value_remainder * 360);
			}
			if (value > 359.99)
			{
				value = 0;
			}
		}
		else
		{
			return;
		}
	}

	bool parallel(const angle& x, const angle& y)
	{
		if(x == y /*or (x + 180) == y*/)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool orthogonal(const angle& x, const angle& y)
	{
		return true;
		/*float difference = (x - y).get_value();
		if (difference == 90 or difference == 270)
		{
			return true;
		}*/
	}

	angle sqrt(const angle& x)
	{
		return angle(sqrt(x.get_value()));
	}

	angle sqrt_nth(const angle& x, int y)
	{
		return angle(pow(x.get_value(), 1 / y));
	}

	float sin(const angle& x)
	{
		return std::sin(x.get_radian_value());
	}

	float cos(const angle& x)
	{
		return std::cos(x.get_radian_value());
	}

	float tan(const angle& x)
	{
		return std::tan(x.get_radian_value());
	}

	angle asin(float x)
	{
		return angle(radian_to_grade(std::asin(x)));
	}

	angle acos(float x)
	{
		return angle(radian_to_grade(std::acos(x)));
	}

	angle atan(float x)
	{
		return angle(radian_to_grade(std::atan(x)));
	}

	float sinh(const angle& x)
	{
		return std::sinh(x.get_radian_value());
	}

	float cosh(const angle& x)
	{
		return std::cosh(x.get_radian_value());
	}

	float tanh(const angle& x)
	{
		return std::tanh(x.get_radian_value());
	}

	angle asinh(float x)
	{
		return angle(radian_to_grade(std::asinh(x)));
	}

	angle acosh(float x)
	{
		return angle(radian_to_grade(std::acosh(x)));
	}

	angle atanh(float x)
	{
		return angle(radian_to_grade(std::atanh(x)));
	}
}

bool operator ==(const msci::angle& x, const msci::angle& y)
{
	if(x.get_value() == y.get_value())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::angle& x, const msci::angle& y)
{
	return !(x == y);
}

bool operator <(const msci::angle& x, const msci::angle& y)
{
	if(x.get_value() < y.get_value())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator >(const msci::angle& x, const msci::angle& y)
{
	if(x.get_value() > y.get_value())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator <=(const msci::angle& x, const msci::angle& y)
{
	return !(x > y);
}

bool operator >=(const msci::angle& x, const msci::angle& y)
{
	return !(x < y);
}

void operator +=(string& x, const msci::angle& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const msci::angle& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const msci::angle& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const msci::angle& x)
{
	ostringstream output;
	double integer_part;
	modf(x.get_value(), &integer_part);
	output << setprecision(to_string(int(integer_part)).length() + 1);
	//output << setprecision(numeric_limits<float>::max_exponent10 + 1);
	//output << x.get_value() << "°";
	if (x.get_value() == -0)
	{
		output << 0;
	}
	else
	{
		output << x.get_value();
	}
	return os << output.str();
}

istream& operator >>(istream& is, msci::angle& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::angle c(stof(b));
	x = c;
	return is;
}
