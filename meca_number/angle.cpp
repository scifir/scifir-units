#include "meca_number/angle.hpp"

#include "boost/algorithm/string.hpp"
#include "unicode/unistr.h"
#include "unicode/uchar.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

namespace msci
{
	angle::angle() : value(0)
	{}

	angle::angle(const angle& x) : value(x.get_value())
	{}

	angle::angle(angle&& x) : value(move(x.get_value()))
	{}

	angle::angle(float x) : value(x)
	{
		normalize_value();
	}

	angle::angle(string init_angle) : value()
	{
		icu::UnicodeString init_angle_unicode = icu::UnicodeString(init_angle.c_str());
		if (init_angle_unicode.endsWith(u'º'))
		{
			init_angle_unicode = init_angle_unicode.tempSubString(0,-1);
		}
		init_angle = init_angle_unicode.toUTF8String(init_angle);
		value = stof(init_angle);
		normalize_value();
	}

	angle::angle(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = float(x);
			normalize_value();
		}
		else
		{
			cerr << "An angle cannot be initialized with dimensions";
			value = 0;
		}
	}

	angle& angle::operator=(const angle& x)
	{
		value = x.get_value();
		return *this;
	}

	angle& angle::operator=(angle&& x)
	{
		value = move(x.get_value());
		return *this;
	}

	angle& angle::operator=(float x)
	{
		value = x;
		normalize_value();
		return *this;
	}

	angle& angle::operator=(string& init_angle)
	{
		icu::UnicodeString init_angle_unicode = icu::UnicodeString(init_angle.c_str());
		if (init_angle_unicode.endsWith(u'º'))
		{
			init_angle_unicode = init_angle_unicode.tempSubString(0,-1);
		}
		init_angle = init_angle_unicode.toUTF8String(init_angle);
		value = stof(init_angle);
		normalize_value();
		return *this;
	}

	angle& angle::operator=(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = x.get_value();
			normalize_value();
		}
		else
		{
			cerr << "An angle cannot be initialized with dimensions";
		}
		return *this;
	}

	angle angle::operator +(const angle& x) const
	{
		return angle(value + x.get_value());
	}

	angle angle::operator -(const angle& x) const
	{
		return angle(value - x.get_value());
	}

	angle angle::operator *(const angle& x) const
	{
		return angle(value * x.get_value());
	}

	angle angle::operator /(const angle& x) const
	{
		return angle(value / x.get_value());
	}

	angle angle::operator ^(const angle& x) const
	{
		return angle(std::pow(value,x.get_value()));
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

	void angle::operator *=(const angle& x)
	{
		value *= x.get_value();
		normalize_value();
	}

	void angle::operator /=(const angle& x)
	{
		value /= x.get_value();
		normalize_value();
	}

	void angle::operator ^=(const angle& x)
	{
		value = std::pow(value,x.get_value());
		normalize_value();
	}

	angle& angle::operator++()
	{
		value++;
		return *this;
	}

	angle angle::operator++(int)
	{
		angle tmp = angle(*this);
		operator++();
		return tmp;
	}

	angle& angle::operator--()
	{
		value--;
		return *this;
	}

	angle angle::operator--(int)
	{
		angle tmp = angle(*this);
		operator--();
		return tmp;
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

	string to_string(const angle& x)
	{
		ostringstream output;
		if (x.get_value() == -0)
		{
			output << 0;
		}
		else
		{
			output << x.get_value();
		}
		output << "°";
		return output.str();
	}

	bool is_angle(const string& x)
	{
		icu::UnicodeString x_unicode = icu::UnicodeString(x.c_str());
		int total_chars = x_unicode.countChar32();
		for (int i = 0; i < total_chars; i++)
		{
			if ((i + 1) == total_chars)
			{
				if (x_unicode[i] == U'º')
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (!u_isdigit(x_unicode[i]))
				{
					return false;
				}
			}
		}
		return true;
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
		return angle(std::sqrt(x.get_value()));
	}

	angle sqrt_nth(const angle& x, int y)
	{
		return angle(std::pow(x.get_value(), 1 / y));
	}

	float sin(const angle& x)
	{
		return std::sin(x.get_radian());
	}

	float cos(const angle& x)
	{
		return std::cos(x.get_radian());
	}

	float tan(const angle& x)
	{
		return std::tan(x.get_radian());
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
		return std::sinh(x.get_radian());
	}

	float cosh(const angle& x)
	{
		return std::cosh(x.get_radian());
	}

	float tanh(const angle& x)
	{
		return std::tanh(x.get_radian());
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

bool operator ==(const msci::angle& x, const string& y)
{
	msci::angle y_angle = msci::angle(y);
	return (x == y_angle);
}

bool operator !=(const msci::angle& x, const string& y)
{
	return !(x == y);
}

bool operator ==(const string& x, const msci::angle& y)
{
	msci::angle x_angle = msci::angle(x);
	return (x_angle == y);
}

bool operator !=(const string& x, const msci::angle& y)
{
	return !(x == y);
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
	return os << to_string(x);
}

istream& operator >>(istream& is, msci::angle& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::angle c(b);
	x = c;
	return is;
}
