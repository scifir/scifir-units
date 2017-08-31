#include "angle_number.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

namespace math
{
	angle_number::angle_number() : value(0)
	{
	}

	angle_number::angle_number(math::angle_type x)
	{
		value = x;
		normalize_value();
	}

	angle_number::angle_number(const unit& x)
	{
		if (x.empty_dimensions())
		{
			value = float(x);
			normalize_value();
		}
	}

	angle_number angle_number::operator +(const angle_number& x) const
	{
		return angle_number(value + x.get_value());
	}

	angle_number angle_number::operator -(const angle_number& x) const
	{
		return angle_number(value - x.get_value());
	}

	void angle_number::operator +=(const angle_number& x)
	{
		value += x.get_value();
		normalize_value();
	}

	void angle_number::operator -=(const angle_number& x)
	{
		value -= x.get_value();
		normalize_value();
	}

	const math::angle_type& angle_number::get_value() const
	{
		return value;
	}

	void angle_number::invert()
	{
		value += 180;
		normalize_value();
	}

	math::angle_type angle_number::get_radian_value() const
	{
		return grade_to_radian(value);
	}

	void angle_number::normalize_value()
	{
		if(isfinite(value))
		{
			if (value >= 360)
			{
				math::angle_type decimal_part;
				math::angle_type value_remainder = modf(value / 360,&decimal_part);
				value = value_remainder * 360;
			}
			else if (value < 0)
			{
				math::angle_type decimal_part;
				math::angle_type value_remainder = modf(value / 360,&decimal_part);
				value = 360 - abs(value_remainder * 360);
			}
			if (value > 359.99)
			{
				value = 0;
			}
		}
		else
		{
			throw invalid_argument("Value of angle number is not finite");
		}
	}

	bool parallel(const angle_number& x, const angle_number& y)
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

	bool orthogonal(const angle_number& x, const angle_number& y)
	{
		return true;
		/*float difference = (x - y).get_value();
		if (difference == 90 or difference == 270)
		{
			return true;
		}*/
	}

	angle_number sqrt(const angle_number& x)
	{
		return angle_number(sqrt(x.get_value()));
	}

	angle_number sqrt_nth(const angle_number& x, int y)
	{
		return angle_number(pow(x.get_value(), 1 / y));
	}

	math::angle_type sin(const angle_number& x)
	{
		return std::sin(x.get_radian_value());
	}

	math::angle_type cos(const angle_number& x)
	{
		return std::cos(x.get_radian_value());
	}

	math::angle_type tan(const angle_number& x)
	{
		return std::tan(x.get_radian_value());
	}

	angle_number asin(math::angle_type x)
	{
		return angle_number(radian_to_grade(std::asin(x)));
	}

	angle_number acos(math::angle_type x)
	{
		return angle_number(radian_to_grade(std::acos(x)));
	}

	angle_number atan(math::angle_type x)
	{
		return angle_number(radian_to_grade(std::atan(x)));
	}

	math::angle_type sinh(const angle_number& x)
	{
		return std::sinh(x.get_radian_value());
	}

	math::angle_type cosh(const angle_number& x)
	{
		return std::cosh(x.get_radian_value());
	}

	math::angle_type tanh(const angle_number& x)
	{
		return std::tanh(x.get_radian_value());
	}

	angle_number asinh(math::angle_type x)
	{
		return angle_number(radian_to_grade(std::asinh(x)));
	}

	angle_number acosh(math::angle_type x)
	{
		return angle_number(radian_to_grade(std::acosh(x)));
	}

	angle_number atanh(math::angle_type x)
	{
		return angle_number(radian_to_grade(std::atanh(x)));
	}
}

bool operator ==(const math::angle_number& x, const math::angle_number& y)
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

bool operator !=(const math::angle_number& x, const math::angle_number& y)
{
	return !(x == y);
}

bool operator <(const math::angle_number& x, const math::angle_number& y)
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

bool operator >(const math::angle_number& x, const math::angle_number& y)
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

bool operator <=(const math::angle_number& x, const math::angle_number& y)
{
	return !(x > y);
}

bool operator >=(const math::angle_number& x, const math::angle_number& y)
{
	return !(x < y);
}

void operator +=(wstring& x, const math::angle_number& y)
{
	wostringstream output;
	output << y;
	x += output.str();
}

wstring operator +(const wstring& x, const math::angle_number& y)
{
	wostringstream output;
	output << x;
	output << y;
	return output.str();
}

wstring operator +(const math::angle_number& y, const wstring& x)
{
	wostringstream output;
	output << y;
	output << x;
	return output.str();
}

wostream& operator <<(wostream& os, const math::angle_number& x)
{
	wostringstream output;
	double integer_part;
	modf(x.get_value(), &integer_part);
	output << setprecision(to_string(int(integer_part)).length() + 1);
	//output << setprecision(numeric_limits<float>::max_exponent10 + 1);
	//output << x.get_value() << L"°";
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

istream& operator >>(istream& is, math::angle_number& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	math::angle_number c(stof(b));
	x = c;
	return is;
}
