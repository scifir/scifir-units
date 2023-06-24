#include "special_units/poh.hpp"

#include "util/types.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace msci
{
	pOH::pOH() : value(0)
	{}

	pOH::pOH(const pOH& x) : value(x.get_value())
	{}

	pOH::pOH(pOH&& x) : value(move(x.get_value()))
	{}

	pOH::pOH(float x) : value(x)
	{
		normalize_value();
	}
	
	pOH::pOH(const string& init_pOH) : value()
	{
		value = stof(init_pOH);
		normalize_value();
	}

	pOH::pOH(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = float(x);
			normalize_value();
		}
		else
		{
			cerr << "A pOH cannot be initialized with dimensions";
			value = 0;
		}
	}
	
	pOH& pOH::operator=(const pOH& x)
	{
		value = x.get_value();
		return *this;
	}
	
	pOH& pOH::operator=(pOH&& x)
	{
		value = move(x.get_value());
		return *this;
	}

	pOH& pOH::operator=(float x)
	{
		value = x;
		normalize_value();
		return *this;
	}

	pOH& pOH::operator=(const string& x)
	{
		value = stof(x);
		normalize_value();
		return *this;
	}

	pOH& pOH::operator=(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = x.get_value();
			normalize_value();
		}
		else
		{
			cerr << "A pOH cannot be initialized with dimensions";
		}
		return *this;
	}

	pOH pOH::operator +(const pOH& x) const
	{
		return pOH(value + x.get_value());
	}

	pOH pOH::operator -(const pOH& x) const
	{
		return pOH(value - x.get_value());
	}

	void pOH::operator +=(const pOH& x)
	{
		value += x.get_value();
		normalize_value();
	}

	void pOH::operator -=(const pOH& x)
	{
		value -= x.get_value();
		normalize_value();
	}

	pOH& pOH::operator++()
	{
		value++;
		return *this;
	}

	pOH pOH::operator++(int)
	{
		pOH tmp = pOH(*this);
		operator++();
		return tmp;
	}

	pOH& pOH::operator--()
	{
		value--;
		return *this;
	}

	pOH pOH::operator--(int)
	{
		pOH tmp = pOH(*this);
		operator--();
		return tmp;
	}
	
	concentration pOH::get_H() const
	{
		return concentration(std::pow(10,-float(14 - value)),"M");
	}
	
	concentration pOH::get_OH() const
	{
		return concentration(std::pow(10,-value),"M");
	}

	pH pOH::get_pH() const
	{
		float pH_value = 14 - value;
		return pH(pH_value);
	}

	bool pOH::is_acidic() const
	{
		return (value > 7);
	}

	bool pOH::is_basic() const
	{
		return (value < 7);
	}

	bool pOH::is_neutral() const
	{
		return (value == 7);
	}

	string pOH::display(int number_of_decimals) const
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

	void pOH::normalize_value()
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

	string to_string(const pOH& x)
	{
		ostringstream output;
		output << x.display(2);
		return output.str();
	}
}

bool operator ==(const msci::pOH& x, const msci::pOH& y)
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

bool operator !=(const msci::pOH& x, const msci::pOH& y)
{
	return !(x == y);
}

bool operator <(const msci::pOH& x, const msci::pOH& y)
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

bool operator >(const msci::pOH& x, const msci::pOH& y)
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

bool operator <=(const msci::pOH& x, const msci::pOH& y)
{
	return !(x > y);
}

bool operator >=(const msci::pOH& x, const msci::pOH& y)
{
	return !(x < y);
}

bool operator ==(const msci::pOH& x, const string& y)
{
	msci::pOH y_pOH = msci::pOH(y);
	return (x == y_pOH);
}

bool operator !=(const msci::pOH& x, const string& y)
{
	return !(x == y);
}

bool operator ==(const string& x, const msci::pOH& y)
{
	msci::pOH x_pOH = msci::pOH(x);
	return (x_pOH == y);
}

bool operator !=(const string& x, const msci::pOH& y)
{
	return !(x == y);
}

void operator +=(string& x, const msci::pOH& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const msci::pOH& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const msci::pOH& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const msci::pOH& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, msci::pOH& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::pOH c(b);
	x = c;
	return is;
}


