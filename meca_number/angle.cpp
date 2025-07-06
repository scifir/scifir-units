#include "./angle.hpp"

#include "../util/types.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace scifir
{
	angle::angle() : value(0.0f)
	{}

	angle::angle(const angle& x) : value(x.get_value())
	{}

	angle::angle(angle&& x) : value(std::move(x.get_value()))
	{}

	angle::angle(float new_value,angle::type init_type) : value()
	{
		if (init_type == angle::DEGREE)
		{
			value = new_value;
		}
		else if (init_type == angle::RADIAN)
		{
			value = radian_to_degree(new_value);
		}
		else if (init_type == angle::GRADIAN)
		{
			value = gradian_to_degree(new_value);
		}
		else if (init_type == angle::TURN)
		{
			value = turn_to_degree(new_value);
		}
		normalize_value();
	}

	angle::angle(double new_value,angle::type init_type) : value()
	{
		if (init_type == angle::DEGREE)
		{
			value = float(new_value);
		}
		else if (init_type == angle::RADIAN)
		{
			value = radian_to_degree(float(new_value));
		}
		else if (init_type == angle::GRADIAN)
		{
			value = gradian_to_degree(float(new_value));
		}
		else if (init_type == angle::TURN)
		{
			value = turn_to_degree(float(new_value));
		}
		normalize_value();
	}

	angle::angle(long double new_value,angle::type init_type) : value()
	{
		if (init_type == angle::DEGREE)
		{
			value = float(new_value);
		}
		else if (init_type == angle::RADIAN)
		{
			value = radian_to_degree(float(new_value));
		}
		else if (init_type == angle::GRADIAN)
		{
			value = gradian_to_degree(float(new_value));
		}
		else if (init_type == angle::TURN)
		{
			value = turn_to_degree(float(new_value));
		}
		normalize_value();
	}

	angle::angle(int new_value,angle::type init_type) : value()
	{
		if (init_type == angle::DEGREE)
		{
			value = float(new_value);
		}
		else if (init_type == angle::RADIAN)
		{
			value = radian_to_degree(float(new_value));
		}
		else if (init_type == angle::GRADIAN)
		{
			value = gradian_to_degree(float(new_value));
		}
		else if (init_type == angle::TURN)
		{
			value = turn_to_degree(float(new_value));
		}
		normalize_value();
	}

	angle::angle(const string& init_angle) : value()
	{
		initialize_from_string(init_angle);
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
			cerr << "An angle cannot be initialized with dimensions" << endl;
			value = 0.0f;
		}
	}

	angle& angle::operator =(const angle& x)
	{
		value = x.get_value();
		return *this;
	}

	angle& angle::operator =(angle&& x)
	{
		value = std::move(x.get_value());
		return *this;
	}

	angle& angle::operator =(float new_value)
	{
		value = new_value;
		normalize_value();
		return *this;
	}

	angle& angle::operator =(const string& init_angle)
	{
		initialize_from_string(init_angle);
		return *this;
	}

	angle& angle::operator =(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = x.get_value();
			normalize_value();
		}
		else
		{
			cerr << "An angle cannot be initialized with dimensions" << endl;
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

	angle& angle::operator ++()
	{
		value++;
		return *this;
	}

	angle angle::operator ++(int)
	{
		angle tmp = angle(*this);
		operator ++();
		return tmp;
	}

	angle& angle::operator --()
	{
		value--;
		return *this;
	}

	angle angle::operator --(int)
	{
		angle tmp = angle(*this);
		operator --();
		return tmp;
	}

	void angle::invert()
	{
		value += 180.0f;
		normalize_value();
	}

	scalar_unit angle::to_scalar_unit() const
	{
		return scalar_unit(value, { dimension(dimension::DEGREE, prefix::NONE, dimension::NUMERATOR) });
	}

	string angle::display(int number_of_decimals) const
	{
		ostringstream output;
		if (get_value() == -0)
		{
			output << 0;
		}
		else
		{
			output << display_float(get_value(),number_of_decimals);
		}
		output << "°";
		return output.str();
	}

	void angle::normalize_value()
	{
		if(isfinite(value))
		{
			if (value >= 360.0f)
			{
				while (value >= 360.0f)
				{
					value -= 360.0f;
				}
			}
			else if (value < 0.0f)
			{
				while (value < 0.0f)
				{
					value += 360.0f;
				}
			}
		}
	}

	void angle::initialize_from_string(string init_angle)
	{
		if (init_angle.length() >= 5 and init_angle.substr(init_angle.length() - 4) == " deg")
		{
			value = stof(init_angle.substr(0,init_angle.length() - 4));
			normalize_value();
			return;
		}
		else if (init_angle.length() >= 5 and init_angle.substr(init_angle.length() - 4) == " rad")
		{
			value = radian_to_degree(stof(init_angle.substr(0,init_angle.length() - 4)));
			normalize_value();
			return;
		}
		else if (init_angle.length() >= 6 and init_angle.substr(init_angle.length() - 5) == " grad")
		{
			value = gradian_to_degree(stof(init_angle.substr(0,init_angle.length() - 5)));
			normalize_value();
			return;
		}
		else if (init_angle.length() >= 4 and init_angle.substr(init_angle.length() - 3) == " tr")
		{
			value = turn_to_degree(stof(init_angle.substr(0,init_angle.length() - 3)));
			normalize_value();
			return;
		}
		if (init_angle.substr(init_angle.length() - 2).compare("°") == 0 or init_angle.substr(init_angle.length() - 2).compare("θ") == 0 or init_angle.substr(init_angle.length() - 2).compare("Φ") == 0)
		{
			value = stof(init_angle);
			normalize_value();
		}
	}

	string to_string(const angle& x)
	{
		return x.display(2);
	}

	bool is_angle(const string& init_angle)
	{
		int total_chars = int(init_angle.size());
		if (total_chars < 3)
		{
			return false;
		}
		bool loop = false;
		if (total_chars >= 3 and init_angle.substr(total_chars - 2,2) == "°")
		{
			loop = true;
			total_chars -= 2;
		}
		else if (total_chars >= 5 and init_angle.substr(init_angle.length() - 4) == " deg")
		{
			loop = true;
			total_chars -= 4;
		}
		else if (total_chars >= 5 and init_angle.substr(init_angle.length() - 4) == " rad")
		{
			loop = true;
			total_chars -= 4;
		}
		else if (total_chars>= 6 and init_angle.substr(init_angle.length() - 5) == " grad")
		{
			loop = true;
			total_chars -= 5;
		}
		else if (total_chars >= 4 and init_angle.substr(init_angle.length() - 3) == " tr")
		{
			loop = true;
			total_chars -= 3;
		}
		if (loop == false)
		{
			return false;
		}
		bool dot_present = false;
		for (int i = 0; i < total_chars; i++)
		{
			if (init_angle[i] == '.')
			{
				if (dot_present)
				{
					return false;
				}
				else
				{
					dot_present = true;
				}
			}
			else if (!isdigit(init_angle[i]))
			{
				return false;
			}
		}
		return true;
	}

	bool parallel(const angle& x, const angle& y)
	{
		if(x == y or (x + 180.0f) == y)
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
		float difference = std::abs((x - y).get_value());
		if (difference == 90.0f or difference == 270.0f)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	angle sqrt(const angle& x)
	{
		return angle(std::sqrt(x.get_value()));
	}

	angle sqrt_nth(const angle& x, int index)
	{
		return angle(std::pow(x.get_value(), float(1.0f / index)));
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
		return angle(radian_to_degree(std::asin(x)));
	}

	angle acos(float x)
	{
		return angle(radian_to_degree(std::acos(x)));
	}

	angle atan(float x)
	{
		return angle(radian_to_degree(std::atan(x)));
	}

	angle atan2(float y,float x)
	{
		return angle(radian_to_degree(std::atan2(y,x)));
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
		return angle(radian_to_degree(std::asinh(x)));
	}

	angle acosh(float x)
	{
		return angle(radian_to_degree(std::acosh(x)));
	}

	angle atanh(float x)
	{
		return angle(radian_to_degree(std::atanh(x)));
	}
}

bool operator ==(const scifir::angle& x, const scifir::angle& y)
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

bool operator !=(const scifir::angle& x, const scifir::angle& y)
{
	return !(x == y);
}

bool operator <(const scifir::angle& x, const scifir::angle& y)
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

bool operator >(const scifir::angle& x, const scifir::angle& y)
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

bool operator <=(const scifir::angle& x, const scifir::angle& y)
{
	return !(x > y);
}

bool operator >=(const scifir::angle& x, const scifir::angle& y)
{
	return !(x < y);
}

bool operator ==(const scifir::angle& x, const string& init_angle)
{
	scifir::angle y = scifir::angle(init_angle);
	return (x == y);
}

bool operator !=(const scifir::angle& x, const string& init_angle)
{
	return !(x == init_angle);
}

bool operator ==(const string& init_angle, const scifir::angle& x)
{
	scifir::angle y = scifir::angle(init_angle);
	return (x == y);
}

bool operator !=(const string& init_angle, const scifir::angle& x)
{
	return !(init_angle == x);
}

void operator +=(string& x, const scifir::angle& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const scifir::angle& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const scifir::angle& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const scifir::angle& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, scifir::angle& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	x = scifir::angle(b);
	return is;
}
