#include "./percentage.hpp"

#include "../util/types.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace scifir
{
	percentage::percentage() : value(0.0f)
	{}
	
	percentage::percentage(const percentage& x) : value(x.get_value())
	{}
	
	percentage::percentage(percentage&& x) : value(std::move(x.get_value()))
	{}

	percentage::percentage(float new_value,percentage::type init_type) : value()
	{
		if (init_type == percentage::PERCENTAGE)
		{
			value = new_value;
		}
		else if (init_type == percentage::RATIO)
		{
			value = new_value * 100.0f;
		}
		else if (init_type == percentage::PARTS_PER_MILLION)
		{
			value = new_value / 10000.0f;
		}
		else
		{
			value = 0.0f;
		}
	}

	percentage::percentage(double new_value,percentage::type init_type) : value()
	{
		if (init_type == percentage::PERCENTAGE)
		{
			value = float(new_value);
		}
		else if (init_type == percentage::RATIO)
		{
			value = float(new_value) * 100.0f;
		}
		else if (init_type == percentage::PARTS_PER_MILLION)
		{
			value = float(new_value) / 10000.0f;
		}
		else
		{
			value = 0.0f;
		}
	}

	percentage::percentage(long double new_value,percentage::type init_type) : value()
	{
		if (init_type == percentage::PERCENTAGE)
		{
			value = float(new_value);
		}
		else if (init_type == percentage::RATIO)
		{
			value = float(new_value) * 100.0f;
		}
		else if (init_type == percentage::PARTS_PER_MILLION)
		{
			value = float(new_value) / 10000.0f;
		}
		else
		{
			value = 0.0f;
		}
	}

	percentage::percentage(int new_value,percentage::type init_type) : value()
	{
		if (init_type == percentage::PERCENTAGE)
		{
			value = float(new_value);
		}
		else if (init_type == percentage::PARTS_PER_MILLION)
		{
			value = float(new_value) / 10000.0f;
		}
		else
		{
			value = 0.0f;
		}
	}

	percentage::percentage(float new_value,const string& init_type)
	{
		if (init_type == "%")
		{
			value = new_value;
		}
		else if (init_type == "ppm")
		{
			value = new_value / 10000.0f;
		}
		else
		{
			value = 0.0f;
		}
		/*else if (init_type == "ppb")
		{
			value = new_value / 10000000.0f;
		}
		else if (init_type == "ppt")
		{
			value = new_value / 10000000000.0f;
		}
		else if (init_type == "ppq")
		{
			value = new_value / 10000000000000.0f;
		}*/
	}

	percentage::percentage(double new_value,const string& init_type)
	{
		if (init_type == "%")
		{
			value = float(new_value);
		}
		else if (init_type == "ppm")
		{
			value = float(new_value) / 10000.0f;
		}
		else
		{
			value = 0.0f;
		}
		/*else if (init_type == "ppb")
		{
			value = float(new_value) / 10000000.0f;
		}
		else if (init_type == "ppt")
		{
			value = float(new_value) / 10000000000.0f;
		}
		else if (init_type == "ppq")
		{
			value = float(new_value) / 10000000000000.0f;
		}*/
	}

	percentage::percentage(long double new_value,const string& init_type)
	{
		if (init_type == "%")
		{
			value = float(new_value);
		}
		else if (init_type == "ppm")
		{
			value = float(new_value) / 10000.0f;
		}
		else
		{
			value = 0.0f;
		}
		/*else if (init_type == "ppb")
		{
			value = float(new_value) / 10000000.0f;
		}
		else if (init_type == "ppt")
		{
			value = float(new_value) / 10000000000.0f;
		}
		else if (init_type == "ppq")
		{
			value = float(new_value) / 10000000000000.0f;
		}*/
	}

	percentage::percentage(int new_value,const string& init_type)
	{
		if (init_type == "%")
		{
			value = float(new_value);
		}
		else if (init_type == "ppm")
		{
			value = float(new_value) / 10000.0f;
		}
		else
		{
			value = 0.0f;
		}
		/*else if (init_type == "ppb")
		{
			value = float(new_value) / 10000000.0f;
		}
		else if (init_type == "ppt")
		{
			value = float(new_value) / 10000000000.0f;
		}
		else if (init_type == "ppq")
		{
			value = float(new_value) / 10000000000000.0f;
		}*/
	}

	percentage::percentage(const string& init_percentage) : value()
	{
		initialize_from_string(init_percentage);
	}

	percentage::percentage(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = float(x);
		}
		else
		{
			cerr << "A percentage cannot be initialized with dimensions" << endl;
			value = 0.0f;
		}
	}

	percentage& percentage::operator =(const percentage& x)
	{
		value = x.get_value();
		return *this;
	}

	percentage& percentage::operator =(percentage&& x)
	{
		value = std::move(x.get_value());
		return *this;
	}

	percentage& percentage::operator =(float new_value)
	{
		value = new_value;
		return *this;
	}

	percentage& percentage::operator =(double new_value)
	{
		value = float(new_value);
		return *this;
	}

	percentage& percentage::operator =(long double new_value)
	{
		value = float(new_value);
		return *this;
	}

	percentage& percentage::operator =(int new_value)
	{
		value = float(new_value);
		return *this;
	}

	percentage& percentage::operator =(const string& init_percentage)
	{
		initialize_from_string(init_percentage);
		return *this;
	}

	percentage& percentage::operator =(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = x.get_value();
		}
		else
		{
			cerr << "A percentage cannot be initialized with dimensions" << endl;
			value = 0.0f;
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
		return percentage(value * x.get_value() / 100.0f);
	}
	
	percentage percentage::operator /(const percentage& x) const
	{
		return percentage(100.0f * value / x.get_value());
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
		value *= (x.get_value() / 100.0f);
	}
	
	void percentage::operator /=(const percentage& x)
	{
		value *= 100.0f / x.get_value();
	}
	
	percentage& percentage::operator ++()
	{
		value++;
		return *this;
	}

	percentage percentage::operator ++(int)
	{
		percentage tmp = percentage(*this);
		operator ++();
		return tmp;
	}

	percentage& percentage::operator --()
	{
		value--;
		return *this;
	}

	percentage percentage::operator --(int)
	{
		percentage tmp = percentage(*this);
		operator --();
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
		return value / 100.0f;
	}

	float percentage::get_ppm() const
	{
		return value * 10000.0f;
	}

	/*float percentage::get_ppb() const
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
	}*/

	string percentage::display_percentage(int number_of_decimals) const
	{
		ostringstream out;
		out << display_float(value,number_of_decimals) << "%";
		return out.str();
	}

	string percentage::display_ppm() const
	{
		ostringstream out;
		out << display_float(get_ppm()) << " ppm";
		return out.str();
	}

	/*string percentage::display_ppb() const
	{
		ostringstream out;
		out << display_float(get_ppb()) << " ppb";
		return out.str();
	}

	string percentage::display_ppt() const
	{
		ostringstream out;
		out << display_float(get_ppt()) << " ppt";
		return out.str();
	}

	string percentage::display_ppq() const
	{
		ostringstream out;
		out << display_float(get_ppq()) << " ppq";
		return out.str();
	}*/

	void percentage::initialize_from_string(const string& init_percentage)
	{
		if (init_percentage.size() == 0)
		{
			value = 0.0f;
			return;
		}
		else if (init_percentage[init_percentage.length() - 1] == '%')
		{
			value = stof(init_percentage.substr(0,init_percentage.length() - 1));
		}
		else if (init_percentage.find(" ") != string::npos)
		{
			string percentage_unit = init_percentage.substr(init_percentage.length() - 4,4);
			if (percentage_unit == " ppm")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 4)) / 10000.0f;
			}
			else
			{
				value = 0.0f;
			}
			/*else if (percentage_unit == " ppb")
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
			}*/
		}
		else if (init_percentage.length() > 3)
		{
			string percentage_unit = init_percentage.substr(init_percentage.length() - 3,3);
			if (percentage_unit == "ppm")
			{
				value = stof(init_percentage.substr(0,init_percentage.length() - 3)) / 10000.0f;
			}
			/*else if (percentage_unit == "ppb")
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
			}*/
			else
			{
				value = 0.0f;
			}
		}
		else
		{
			value = 0.0f;
		}
	}

	string to_string(const percentage& x)
	{
		return x.display_percentage();
	}

	bool is_percentage(const string& init_percentage)
	{
		int iteration_limit = 0;
		if (init_percentage.back() == '%')
		{
			iteration_limit = int(init_percentage.length()) - 1;
		}
		else
		{
			if (init_percentage.length() >= 5 and init_percentage.substr(init_percentage.length() - 4,4) == " ppm"/* or percentage_unit == " ppb" or percentage_unit == " ppt" or percentage_unit == " ppq"*/)
			{
				iteration_limit = int(init_percentage.length()) - 4;
			}
			else if (init_percentage.length() >= 4 and init_percentage.substr(init_percentage.length() - 3,3) == "ppm")
			{
				iteration_limit = int(init_percentage.length()) - 3;
			}
			else
			{
				return false;
			}
		}
		bool dot_present = false;
		for (int i = 0; i < iteration_limit; i++)
		{
			if (init_percentage[i] == '.')
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
			else if (!std::isdigit(init_percentage[i]))
			{
				return false;
			}
		}
		return true;
	}
}

scifir::scalar_unit operator *(const scifir::scalar_unit& x, const scifir::percentage& y)
{
	return x * y.get_factor();
}

scifir::scalar_unit operator /(const scifir::scalar_unit& x, const scifir::percentage& y)
{
	return x / y.get_factor();
}

bool operator ==(const scifir::percentage& x, const scifir::percentage& y)
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

bool operator !=(const scifir::percentage& x, const scifir::percentage& y)
{
	return !(x == y);
}

bool operator <(const scifir::percentage& x, const scifir::percentage& y)
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

bool operator >(const scifir::percentage& x, const scifir::percentage& y)
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

bool operator <=(const scifir::percentage& x, const scifir::percentage& y)
{
	return !(x > y);
}

bool operator >=(const scifir::percentage& x, const scifir::percentage& y)
{
	return !(x < y);
}

bool operator ==(const scifir::percentage& x, const string& init_percentage)
{
	scifir::percentage y = scifir::percentage(init_percentage);
	return (x == y);
}

bool operator !=(const scifir::percentage& x, const string& init_percentage)
{
	return !(x == init_percentage);
}

bool operator ==(const string& init_percentage, const scifir::percentage& x)
{
	scifir::percentage y = scifir::percentage(init_percentage);
	return (x == y);
}

bool operator !=(const string& init_percentage, const scifir::percentage& x)
{
	return !(init_percentage == x);
}

void operator +=(string& x, const scifir::percentage& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const scifir::percentage& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const scifir::percentage& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const scifir::percentage& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, scifir::percentage& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	x = scifir::percentage(b);
	return is;
}
