#include "./abv.hpp"

#include "../util/types.hpp"

using namespace std;

namespace scifir
{
	abv::abv() : value(0.0f)
	{}
	
	abv::abv(const abv& x) : value(x.get_value())
	{}
	
	abv::abv(abv&& x) : value(std::move(x.get_value()))
	{}

	abv::abv(float new_value,abv::type init_type) : value()
	{
		if (init_type == abv::PERCENTAGE)
		{
			value = new_value;
		}
		else if (init_type == abv::RATIO)
		{
			value = new_value * 100.0f;
		}
	}

	abv::abv(double new_value,abv::type init_type) : value()
	{
		if (init_type == abv::PERCENTAGE)
		{
			value = float(new_value);
		}
		else if (init_type == abv::RATIO)
		{
			value = float(new_value) * 100.0f;
		}
	}

	abv::abv(long double new_value,abv::type init_type) : value()
	{
		if (init_type == abv::PERCENTAGE)
		{
			value = float(new_value);
		}
		else if (init_type == abv::RATIO)
		{
			value = float(new_value) * 100.0f;
		}
	}

	abv::abv(int new_value,abv::type init_type) : value()
	{
		if (init_type == abv::PERCENTAGE)
		{
			value = float(new_value);
		}
		else if (init_type == abv::RATIO)
		{
			value = float(new_value) * 100.0f;
		}
	}

	abv::abv(const string& init_abv) : value()
	{
		initialize_from_string(init_abv);
	}

	abv::abv(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = float(x);
		}
		else
		{
			cerr << "A abv cannot be initialized with dimensions" << endl;
			value = 0.0f;
		}
	}

	abv& abv::operator =(const abv& x)
	{
		value = x.get_value();
		return *this;
	}

	abv& abv::operator =(abv&& x)
	{
		value = std::move(x.get_value());
		return *this;
	}

	abv& abv::operator =(float new_value)
	{
		value = new_value;
		return *this;
	}

	abv& abv::operator =(double new_value)
	{
		value = float(new_value);
		return *this;
	}

	abv& abv::operator =(long double new_value)
	{
		value = float(new_value);
		return *this;
	}

	abv& abv::operator =(int new_value)
	{
		value = float(new_value);
		return *this;
	}

	abv& abv::operator =(const string& init_abv)
	{
		initialize_from_string(init_abv);
		return *this;
	}

	abv& abv::operator =(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = x.get_value();
		}
		else
		{
			cerr << "A abv cannot be initialized with dimensions" << endl;
			value = 0.0f;
		}
		return *this;
	}

	abv abv::operator +(const abv& x) const
	{
		return abv(value + x.get_value());
	}

	abv abv::operator -(const abv& x) const
	{
		return abv(value - x.get_value());
	}

	void abv::operator +=(const abv& x)
	{
		value += x.get_value();
	}

	void abv::operator -=(const abv& x)
	{
		value -= x.get_value();
	}

	abv& abv::operator ++()
	{
		value++;
		return *this;
	}

	abv abv::operator ++(int)
	{
		abv tmp = abv(*this);
		operator ++();
		return tmp;
	}

	abv& abv::operator --()
	{
		value--;
		return *this;
	}

	abv abv::operator --(int)
	{
		abv tmp = abv(*this);
		operator --();
		return tmp;
	}

	string abv::display() const
	{
		ostringstream out;
		out << display_float(value) << "% ABV";
		return out.str();
	}

	void abv::initialize_from_string(const string& init_abv)
	{
		if (init_abv.length() > 5)
		{
			if (init_abv.substr(init_abv.length() - 5,5) == "% ABV")
			{
				value = stof(init_abv.substr(0,init_abv.length() - 5));
			}
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

	string to_string(const abv& x)
	{
		return x.display();
	}

	bool is_abv(const string& init_abv)
	{
		if (init_abv.length() > 5)
		{
			if (init_abv.substr(init_abv.length() - 5,5) != "% ABV")
			{
				return false;
			}
			int iteration_limit = int(init_abv.length()) - 5;
			bool dot_present = false;
			for (int i = 0; i < iteration_limit; i++)
			{
				if (init_abv[i] == '.')
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
				else if (!std::isdigit(init_abv[i]))
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool operator ==(const scifir::abv& x, const scifir::abv& y)
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

bool operator !=(const scifir::abv& x, const scifir::abv& y)
{
	return !(x == y);
}

bool operator <(const scifir::abv& x, const scifir::abv& y)
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

bool operator >(const scifir::abv& x, const scifir::abv& y)
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

bool operator <=(const scifir::abv& x, const scifir::abv& y)
{
	return !(x > y);
}

bool operator >=(const scifir::abv& x, const scifir::abv& y)
{
	return !(x < y);
}

bool operator ==(const scifir::abv& x, const string& init_abv)
{
	scifir::abv y = scifir::abv(init_abv);
	return (x == y);
}

bool operator !=(const scifir::abv& x, const string& init_abv)
{
	return !(x == init_abv);
}

bool operator ==(const string& init_abv, const scifir::abv& x)
{
	scifir::abv y = scifir::abv(init_abv);
	return (x == y);
}

bool operator !=(const string& init_abv, const scifir::abv& x)
{
	return !(init_abv == x);
}

void operator +=(string& x, const scifir::abv& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const scifir::abv& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const scifir::abv& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const scifir::abv& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, scifir::abv& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	x = scifir::abv(b);
	return is;
}
