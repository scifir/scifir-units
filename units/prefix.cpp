#include "./prefix.hpp"

#include <iostream>

using namespace std;

namespace scifir
{
	prefix::prefix(): prefix_type(prefix::no_prefix)
	{}

	prefix::prefix(const prefix& x) : prefix_type(x.prefix_type)
	{}

	prefix::prefix(prefix&& x) : prefix_type(std::move(x.prefix_type))
	{}

	prefix::prefix(prefix::type new_type) : prefix_type(new_type)
	{}

	prefix::prefix(const string& new_type) : prefix_type(prefix_string(new_type))
	{}

	prefix& prefix::operator=(const prefix& x)
	{
		prefix_type = x.prefix_type;
		return *this;
	}

	prefix& prefix::operator=(prefix&& x)
	{
		prefix_type = std::move(x.prefix_type);
		return *this;
	}

	int prefix::get_conversion_factor() const
	{
		switch (prefix_type)
		{
			case prefix::Y:
				return 24;
			case prefix::Z:
				return 21;
			case prefix::E:
				return 18;
			case prefix::P:
				return 15;
			case prefix::T:
				return 12;
			case prefix::G:
				return 9;
			case prefix::M:
				return 6;
			case prefix::k:
				return 3;
			case prefix::h:
				return 2;
			case prefix::da:
				return 1;
			case prefix::no_prefix:
				return 0;
			case prefix::d:
				return -1;
			case prefix::c:
				return -2;
			case prefix::m:
				return -3;
			case prefix::u:
				return -6;
			case prefix::n:
				return -9;
			case prefix::p:
				return -12;
			case prefix::f:
				return -15;
			case prefix::a:
				return -18;
			case prefix::z:
				return -21;
			case prefix::y:
				return -24;
		}
		return 0;
	}

	string prefix::get_name() const
	{
		switch (prefix_type)
		{
			case prefix::Y:
				return "yotta";
			case prefix::Z:
				return "zetta";
			case prefix::E:
				return "exa";
			case prefix::P:
				return "peta";
			case prefix::T:
				return "tera";
			case prefix::G:
				return "giga";
			case prefix::M:
				return "mega";
			case prefix::k:
				return "kilo";
			case prefix::h:
				return "hecto";
			case prefix::da:
				return "deca";
			case prefix::no_prefix:
				return "";
			case prefix::d:
				return "deci";
			case prefix::c:
				return "centi";
			case prefix::m:
				return "milli";
			case prefix::u:
				return "micro";
			case prefix::n:
				return "nano";
			case prefix::p:
				return "pico";
			case prefix::f:
				return "femto";
			case prefix::a:
				return "atto";
			case prefix::z:
				return "zepto";
			case prefix::y:
				return "yocto";
		}
		return "";
	}

	string prefix::get_symbol() const
	{
		switch (prefix_type)
		{
			case prefix::Y:
				return "Y";
			case prefix::Z:
				return "Z";
			case prefix::E:
				return "E";
			case prefix::P:
				return "P";
			case prefix::T:
				return "T";
			case prefix::G:
				return "G";
			case prefix::M:
				return "M";
			case prefix::k:
				return "k";
			case prefix::h:
				return "h";
			case prefix::da:
				return "da";
			case prefix::no_prefix:
				return "";
			case prefix::d:
				return "d";
			case prefix::c:
				return "c";
			case prefix::m:
				return "m";
			case prefix::u:
				return "\u00B5";
			case prefix::n:
				return "n";
			case prefix::p:
				return "p";
			case prefix::f:
				return "f";
			case prefix::a:
				return "a";
			case prefix::z:
				return "z";
			case prefix::y:
				return "y";
		}
		return "";
	}
	
	bool prefix::operator<(const scifir::prefix& y) const
	{
		return (get_conversion_factor() < y.get_conversion_factor());
	}

	prefix::type prefix_string(const string& x)
	{
		if (x == "Y")
		{
			return prefix::Y;
		}
		else if (x == "Z")
		{
			return prefix::Z;
		}
		else if (x == "E")
		{
			return prefix::E;
		}
		else if (x == "P")
		{
			return prefix::P;
		}
		else if (x == "T")
		{
			return prefix::T;
		}
		else if(x == "G")
		{
			return prefix::G;
		}
		else if(x == "M")
		{
			return prefix::M;
		}
		else if(x == "k")
		{
			return prefix::k;
		}
		else if(x == "h")
		{
			return prefix::h;
		}
		else if(x == "da")
		{
			return prefix::da;
		}
		else if(x == "d")
		{
			return prefix::d;
		}
		else if(x == "c")
		{
			return prefix::c;
		}
		else if(x == "m")
		{
			return prefix::m;
		}
		else if(x == "u" or x == "\u00B5")
		{
			return prefix::u;
		}
		else if(x == "n")
		{
			return prefix::n;
		}
		else if(x == "p")
		{
			return prefix::p;
		}
		else if(x == "f")
		{
			return prefix::f;
		}
		else if(x == "a")
		{
			return prefix::a;
		}
		else if(x == "z")
		{
			return prefix::z;
		}
		else if(x == "y")
		{
			return prefix::y;
		}
		else if (x == "")
		{
			return prefix::no_prefix;
		}
		else
		{
			return prefix::no_prefix;
		}
	}

	prefix closest_prefix(const prefix& actual_prefix,int actual_scale)
	{
		int factor_difference = actual_scale + actual_prefix.get_conversion_factor();
		return create_prefix_by_factor(factor_difference);
		
	}

	prefix create_prefix_by_factor(int factor)
	{
		if (factor == 0)
		{
			return prefix(prefix::no_prefix);
		}
		else if (factor == 1)
		{
			return prefix(prefix::da);
		}
		else if (factor == 2)
		{
			return prefix(prefix::h);
		}
		else if (factor == -1)
		{
			return prefix(prefix::d);
		}
		else if (factor == -2)
		{
			return prefix(prefix::c);
		}
		else if (factor >= 3 and factor < 6)
		{
			return prefix(prefix::k);
		}
		else if (factor >= 6 and factor < 9)
		{
			return prefix(prefix::M);
		}
		else if (factor >= 9 and factor < 12)
		{
			return prefix(prefix::G);
		}
		else if (factor >= 12 and factor < 15)
		{
			return prefix(prefix::T);
		}
		else if (factor >= 15 and factor < 18)
		{
			return prefix(prefix::P);
		}
		else if (factor >= 18 and factor < 21)
		{
			return prefix(prefix::E);
		}
		else if (factor >= 21 and factor < 24)
		{
			return prefix(prefix::Z);
		}
		else if (factor >= 24)
		{
			return prefix(prefix::Y);
		}
		else if (factor <= -3 and factor > -6)
		{
			return prefix(prefix::m);
		}
		else if (factor <= -6 and factor > -9)
		{
			return prefix(prefix::u);
		}
		else if (factor <= -9 and factor > -12)
		{
			return prefix(prefix::n);
		}
		else if (factor <= -12 and factor > -15)
		{
			return prefix(prefix::p);
		}
		else if (factor <= -15 and factor > -18)
		{
			return prefix(prefix::f);
		}
		else if (factor <= -18 and factor > -21)
		{
			return prefix(prefix::a);
		}
		else if (factor <= -21 and factor > -24)
		{
			return prefix(prefix::z);
		}
		else if (factor < -24)
		{
			return prefix(prefix::y);
		}
		return prefix();
	}
}

bool operator ==(const scifir::prefix& x,const scifir::prefix& y)
{
	return (x.get_conversion_factor() == y.get_conversion_factor());
}

bool operator !=(const scifir::prefix& x,const scifir::prefix& y)
{
	return !(x == y);
}

bool operator <=(const scifir::prefix& x,const scifir::prefix& y)
{
	return (x.get_conversion_factor() <= y.get_conversion_factor());
}

bool operator >(const scifir::prefix& x,const scifir::prefix& y)
{
	return (x.get_conversion_factor() > y.get_conversion_factor());
}

bool operator >=(const scifir::prefix& x,const scifir::prefix& y)
{
	return (x.get_conversion_factor() >= y.get_conversion_factor());
}

ostream& operator <<(ostream& os, const scifir::prefix& x)
{
	return os << x.get_symbol();
}
