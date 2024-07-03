#include "./pOH.hpp"

#include "../util/types.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace scifir
{
	pOH::pOH() : value(0.0f)
	{}

	pOH::pOH(const pOH& x) : value(x.get_value())
	{}

	pOH::pOH(pOH&& x) : value(std::move(x.get_value()))
	{}

	pOH::pOH(float new_value) : value(new_value)
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
			cerr << "A pOH cannot be initialized with dimensions" << endl;
			value = 0;
		}
	}
	
	pOH& pOH::operator =(const pOH& x)
	{
		value = x.get_value();
		return *this;
	}
	
	pOH& pOH::operator =(pOH&& x)
	{
		value = std::move(x.get_value());
		return *this;
	}

	pOH& pOH::operator =(float new_value)
	{
		value = new_value;
		normalize_value();
		return *this;
	}

	pOH& pOH::operator =(const string& init_pOH)
	{
		value = stof(init_pOH);
		normalize_value();
		return *this;
	}

	pOH& pOH::operator =(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = x.get_value();
			normalize_value();
		}
		else
		{
			cerr << "A pOH cannot be initialized with dimensions" << endl;
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

	molarity pOH::get_H() const
	{
		return molarity(std::pow(10.0f,-float(14.0f - value)),"M");
	}
	
	molarity pOH::get_OH() const
	{
		return molarity(std::pow(10.0f,-value),"M");
	}

	pH pOH::get_pH() const
	{
		float pH_value = 14.0f - value;
		return pH(pH_value);
	}

	bool pOH::is_acidic() const
	{
		return (value > 7.0f);
	}

	bool pOH::is_basic() const
	{
		return (value < 7.0f);
	}

	bool pOH::is_neutral() const
	{
		return (value == 7.0f);
	}

	string pOH::display(int number_of_decimals) const
	{
		ostringstream output;
		if (value == -0.0f)
		{
			output << 0;
		}
		else
		{
			output << display_float(value,number_of_decimals);
		}
		return output.str();
	}

	void pOH::normalize_value()
	{
		if(isfinite(value))
		{
			if (value > 14.0f)
			{
				value = 0.0f;
			}
			else if (value < 1.0f)
			{
				value = 0.0f;
			}
		}
	}

	string to_string(const pOH& x)
	{
		ostringstream output;
		output << x.display(2);
		return output.str();
	}
}

bool operator ==(const scifir::pOH& x, const scifir::pOH& y)
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

bool operator !=(const scifir::pOH& x, const scifir::pOH& y)
{
	return !(x == y);
}

bool operator <(const scifir::pOH& x, const scifir::pOH& y)
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

bool operator >(const scifir::pOH& x, const scifir::pOH& y)
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

bool operator <=(const scifir::pOH& x, const scifir::pOH& y)
{
	return !(x > y);
}

bool operator >=(const scifir::pOH& x, const scifir::pOH& y)
{
	return !(x < y);
}

bool operator ==(const scifir::pOH& x, const string& init_pOH)
{
	scifir::pOH y = scifir::pOH(init_pOH);
	return (x == y);
}

bool operator !=(const scifir::pOH& x, const string& init_pOH)
{
	return !(x == init_pOH);
}

bool operator ==(const string& init_pOH, const scifir::pOH& x)
{
	scifir::pOH y = scifir::pOH(init_pOH);
	return (x == y);
}

bool operator !=(const string& init_pOH, const scifir::pOH& x)
{
	return !(init_pOH == x);
}

void operator +=(string& x, const scifir::pOH& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const scifir::pOH& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const scifir::pOH& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const scifir::pOH& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, scifir::pOH& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	x = scifir::pOH(b);
	return is;
}


