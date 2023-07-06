#include "special_units/percentage.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace msci
{
	percentage::percentage() : value(0)
	{}
	
	percentage::percentage(const percentage& x) : value(x.get_value())
	{}
	
	percentage::percentage(percentage&& x) : value(move(x.get_value()))
	{}

	percentage::percentage(float x) : value(x)
	{}

	percentage::percentage(float x,const string& init_dimensions)
	{
		if (init_dimensions == "%")
		{
			value = x;
		}
		else if (init_dimensions == "ppm")
		{
			value = x / 10000.0f;
		}
		else if (init_dimensions == "ppb")
		{
			value = x / 10000000.0f;
		}
		else if (init_dimensions == "ppt")
		{
			value = x / 10000000000.0f;
		}
		else if (init_dimensions == "ppq")
		{
			value = x / 10000000000000.0f;
		}
	}

	percentage::percentage(const string& init_percentage) : value()
	{
		if (init_percentage[init_percentage.length() - 1] == '%')
		{
			value = stof(init_percentage.substr(0,init_percentage.length() - 1));
		}
		else if (init_percentage.length() >= 4)
		{
			string percentage_unit = init_percentage.substr(init_percentage.length() - 4,4);
			if (percentage_unit == " ppm")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 4)) / 10000.0f;
			}
			else if (percentage_unit == " ppb")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 4)) / 10000000.0f;
			}
			else if (percentage_unit == " ppt")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 4)) / 10000000000.0f;
			}
			else if (percentage_unit == " ppq")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 4)) / 10000000000000.0f;
			}
		}
		else if (init_percentage.length() >= 3)
		{
			string percentage_unit = init_percentage.substr(init_percentage.length() - 3,3);
			if (percentage_unit == "ppm")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 3)) / 10000.0f;
			}
			else if (percentage_unit == "ppb")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 3)) / 10000000.0f;
			}
			else if (percentage_unit == "ppt")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 3)) / 10000000000.0f;
			}
			else if (percentage_unit == "ppq")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 3)) / 10000000000000.0f;
			}
			else
			{
				value = 0;
			}
		}
	}

	percentage::percentage(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = float(x);
		}
		else
		{
			cerr << "An percentage cannot be initialized with dimensions";
			value = 0;
		}
	}

	percentage& percentage::operator=(const percentage& x)
	{
		value = x.get_value();
		return *this;
	}

	percentage& percentage::operator=(percentage&& x)
	{
		value = move(x.get_value());
		return *this;
	}

	percentage& percentage::operator=(float x)
	{
		value = x;
		return *this;
	}

	percentage& percentage::operator=(const string& init_percentage)
	{
		if (init_percentage[init_percentage.length() - 1] == '%')
		{
			value = stof(init_percentage.substr(0,init_percentage.length() - 1));
		}
		else if (init_percentage.length() >= 4)
		{
			string percentage_unit = init_percentage.substr(init_percentage.length() - 4,4);
			if (percentage_unit == " ppm")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 4)) / 10000.0f;
			}
			else if (percentage_unit == " ppb")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 4)) / 10000000.0f;
			}
			else if (percentage_unit == " ppt")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 4)) / 10000000000.0f;
			}
			else if (percentage_unit == " ppq")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 4)) / 10000000000000.0f;
			}
		}
		else if (init_percentage.length() >= 3)
		{
			string percentage_unit = init_percentage.substr(init_percentage.length() - 3,3);
			if (percentage_unit == "ppm")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 3)) / 10000.0f;
			}
			else if (percentage_unit == "ppb")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 3)) / 10000000.0f;
			}
			else if (percentage_unit == "ppt")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 3)) / 10000000000.0f;
			}
			else if (percentage_unit == "ppq")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 3)) / 10000000000000.0f;
			}
			else
			{
				value = 0;
			}
		}
		return *this;
	}

	percentage& percentage::operator=(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = x.get_value();
		}
		else
		{
			cerr << "An percentage cannot be initialized with dimensions";
		}
		return *this;
	}

	percentage percentage::operator +(const percentage& x) const
	{
		return percentage(value + x.get_value());
	}

	percentage percentage::operator -(const percentage& x) const
	{
		return percentage(value - x.get_value());
	}
	
	percentage percentage::operator *(const percentage& x) const
	{
		return percentage(value * x.get_value() / 100);
	}
	
	percentage percentage::operator /(const percentage& x) const
	{
		return percentage(100 * value / x.get_value());
	}

	void percentage::operator +=(const percentage& x)
	{
		value += x.get_value();
	}

	void percentage::operator -=(const percentage& x)
	{
		value -= x.get_value();
	}
	
	void percentage::operator *=(const percentage& x)
	{
		value *= (x.get_value() / 100);
	}
	
	void percentage::operator /=(const percentage& x)
	{
		value *= 100 / x.get_value();
	}
	
	percentage& percentage::operator++()
	{
		value++;
		return *this;
	}

	percentage percentage::operator++(int)
	{
		percentage tmp = percentage(*this);
		operator++();
		return tmp;
	}

	percentage& percentage::operator--()
	{
		value--;
		return *this;
	}

	percentage percentage::operator--(int)
	{
		percentage tmp = percentage(*this);
		operator--();
		return tmp;
	}

	scalar_unit percentage::operator *(const scalar_unit& x) const
	{
		return get_factor() * x;
	}

	scalar_unit percentage::operator /(const scalar_unit& x) const
	{
		return get_factor() / x;
	}

	float percentage::get_factor() const
	{
		return value / 100;
	}

	float percentage::get_ppm() const
	{
		return value * 10000.0f;
	}

	float percentage::get_ppb() const
	{
		return value * 10000000.0f;
	}

	float percentage::get_ppt() const
	{
		return value * 10000000000.0f;
	}

	float percentage::get_ppq() const
	{
		return value * 10000000000000.0f;
	}

	string percentage::display_ppm() const
	{
		ostringstream out;
		out << get_ppm() << " ppm";
		return out.str();
	}

	string percentage::display_ppb() const
	{
		ostringstream out;
		out << get_ppb() << " ppb";
		return out.str();
	}

	string percentage::display_ppt() const
	{
		ostringstream out;
		out << get_ppt() << " ppt";
		return out.str();
	}

	string percentage::display_ppq() const
	{
		ostringstream out;
		out << get_ppq() << " ppq";
		return out.str();
	}

	string to_string(const percentage& x)
	{
		ostringstream output;
		output << x.get_value() << "%";
		return output.str();
	}

	bool is_percentage(const string& x)
	{
		int iteration_limit;
		string percentage_unit = x.substr(x.length() - 4,4);
		if (percentage_unit == " ppm" or percentage_unit == " ppb" or percentage_unit == " ppt" or percentage_unit == " ppq")
		{
			iteration_limit = x.length() - 4;
		}
		else if (x[x.length() - 1] == '%')
		{
			iteration_limit = x.length() - 1;
		}
		else
		{
			return false;
		}
		bool dot_present = false;
		for (int i = 0; i < iteration_limit; i++)
		{
			if (x[i] == '.')
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
			else if (!std::isdigit(x[i]))
			{
				return false;
			}
		}
		return true;
	}
}

msci::scalar_unit operator *(const msci::scalar_unit& x, const msci::percentage& y)
{
	return x * y.get_factor();
}

msci::scalar_unit operator /(const msci::scalar_unit& x, const msci::percentage& y)
{
	return x / y.get_factor();
}

bool operator ==(const msci::percentage& x, const msci::percentage& y)
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

bool operator !=(const msci::percentage& x, const msci::percentage& y)
{
	return !(x == y);
}

bool operator <(const msci::percentage& x, const msci::percentage& y)
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

bool operator >(const msci::percentage& x, const msci::percentage& y)
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

bool operator <=(const msci::percentage& x, const msci::percentage& y)
{
	return !(x > y);
}

bool operator >=(const msci::percentage& x, const msci::percentage& y)
{
	return !(x < y);
}

bool operator ==(const msci::percentage& x, const string& y)
{
	msci::percentage y_percentage = msci::percentage(y);
	return (x == y_percentage);
}

bool operator !=(const msci::percentage& x, const string& y)
{
	return !(x == y);
}

bool operator ==(const string& x, const msci::percentage& y)
{
	msci::percentage x_percentage = msci::percentage(x);
	return (x_percentage == y);
}

bool operator !=(const string& x, const msci::percentage& y)
{
	return !(x == y);
}

void operator +=(string& x, const msci::percentage& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const msci::percentage& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const msci::percentage& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const msci::percentage& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, msci::percentage& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::percentage c(b);
	x = c;
	return is;
}


