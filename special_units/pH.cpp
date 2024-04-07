#include "special_units/ph.hpp"
#include "special_units/poh.hpp"

#include "util/types.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace scifir
{
	pH::pH() : value(0)
	{}

	pH::pH(const pH& x) : value(x.get_value())
	{}

	pH::pH(pH&& x) : value(move(x.get_value()))
	{}

	pH::pH(float x) : value(x)
	{
		normalize_value();
	}

	pH::pH(const string& init_pH) : value()
	{
		value = stof(init_pH);
		normalize_value();
	}

	pH::pH(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = float(x);
			normalize_value();
		}
		else
		{
			cerr << "A pH cannot be initialized with dimensions";
			value = 0;
		}
	}

	pH& pH::operator=(const pH& x)
	{
		value = x.get_value();
		return *this;
	}

	pH& pH::operator=(pH&& x)
	{
		value = move(x.get_value());
		return *this;
	}

	pH& pH::operator=(float x)
	{
		value = x;
		normalize_value();
		return *this;
	}

	pH& pH::operator=(const string& x)
	{
		value = stof(x);
		normalize_value();
		return *this;
	}

	pH& pH::operator=(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = x.get_value();
			normalize_value();
		}
		else
		{
			cerr << "A pH cannot be initialized with dimensions";
		}
		return *this;
	}

	pH pH::operator +(const pH& x) const
	{
		return pH(value + x.get_value());
	}

	pH pH::operator -(const pH& x) const
	{
		return pH(value - x.get_value());
	}

	void pH::operator +=(const pH& x)
	{
		value += x.get_value();
		normalize_value();
	}

	void pH::operator -=(const pH& x)
	{
		value -= x.get_value();
		normalize_value();
	}

	pH& pH::operator++()
	{
		value++;
		return *this;
	}

	pH pH::operator++(int)
	{
		pH tmp = pH(*this);
		operator++();
		return tmp;
	}

	pH& pH::operator--()
	{
		value--;
		return *this;
	}

	pH pH::operator--(int)
	{
		pH tmp = pH(*this);
		operator--();
		return tmp;
	}

	molarity pH::get_H() const
	{
		return molarity(std::pow(10,-value),"M");
	}

	molarity pH::get_OH() const
	{
		return molarity(std::pow(10,-float(14 - value)),"M");
	}

	pOH pH::get_pOH() const
	{
		float pOH_value = 14 - value;
		return pOH(pOH_value);
	}

	bool pH::is_acidic() const
	{
		return (value < 7);
	}

	bool pH::is_basic() const
	{
		return (value > 7);
	}

	bool pH::is_neutral() const
	{
		return (value == 7);
	}

	string pH::display(int number_of_decimals) const
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
		return output.str();
	}

	void pH::normalize_value()
	{
		if(isfinite(value))
		{
			if (value > 14)
			{
				value = 0;
			}
			else if (value < 1)
			{
				value = 0;
			}
		}
		else
		{
			return;
		}
	}
	
	string to_string(const pH& x)
	{
		ostringstream output;
		output << x.display(2);
		return output.str();
	}
}

bool operator ==(const scifir::pH& x, const scifir::pH& y)
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

bool operator !=(const scifir::pH& x, const scifir::pH& y)
{
	return !(x == y);
}

bool operator <(const scifir::pH& x, const scifir::pH& y)
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

bool operator >(const scifir::pH& x, const scifir::pH& y)
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

bool operator <=(const scifir::pH& x, const scifir::pH& y)
{
	return !(x > y);
}

bool operator >=(const scifir::pH& x, const scifir::pH& y)
{
	return !(x < y);
}

bool operator ==(const scifir::pH& x, const string& y)
{
	scifir::pH y_pH = scifir::pH(y);
	return (x == y_pH);
}

bool operator !=(const scifir::pH& x, const string& y)
{
	return !(x == y);
}

bool operator ==(const string& x, const scifir::pH& y)
{
	scifir::pH x_pH = scifir::pH(x);
	return (x_pH == y);
}

bool operator !=(const string& x, const scifir::pH& y)
{
	return !(x == y);
}

void operator +=(string& x, const scifir::pH& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const scifir::pH& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const scifir::pH& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const scifir::pH& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, scifir::pH& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	scifir::pH c(b);
	x = c;
	return is;
}

