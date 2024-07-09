#include "./prefix.hpp"

#include <iostream>

using namespace std;

namespace scifir
{
	prefix::prefix(): prefix_type(prefix::NONE)
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
			case prefix::YOTTA:
				return 24;
			case prefix::ZETTA:
				return 21;
			case prefix::EXA:
				return 18;
			case prefix::PETA:
				return 15;
			case prefix::TERA:
				return 12;
			case prefix::GIGA:
				return 9;
			case prefix::MEGA:
				return 6;
			case prefix::KILO:
				return 3;
			case prefix::HECTO:
				return 2;
			case prefix::DECA:
				return 1;
			case prefix::NONE:
				return 0;
			case prefix::DECI:
				return -1;
			case prefix::CENTI:
				return -2;
			case prefix::MILLI:
				return -3;
			case prefix::MICRO:
				return -6;
			case prefix::NANO:
				return -9;
			case prefix::PICO:
				return -12;
			case prefix::FEMTO:
				return -15;
			case prefix::ATTO:
				return -18;
			case prefix::ZEPTO:
				return -21;
			case prefix::YOCTO:
				return -24;
		}
		return 0;
	}

	string prefix::get_name() const
	{
		switch (prefix_type)
		{
			case prefix::YOTTA:
				return "yotta";
			case prefix::ZETTA:
				return "zetta";
			case prefix::EXA:
				return "exa";
			case prefix::PETA:
				return "peta";
			case prefix::TERA:
				return "tera";
			case prefix::GIGA:
				return "giga";
			case prefix::MEGA:
				return "mega";
			case prefix::KILO:
				return "kilo";
			case prefix::HECTO:
				return "hecto";
			case prefix::DECA:
				return "deca";
			case prefix::NONE:
				return "";
			case prefix::DECI:
				return "deci";
			case prefix::CENTI:
				return "centi";
			case prefix::MILLI:
				return "milli";
			case prefix::MICRO:
				return "micro";
			case prefix::NANO:
				return "nano";
			case prefix::PICO:
				return "pico";
			case prefix::FEMTO:
				return "femto";
			case prefix::ATTO:
				return "atto";
			case prefix::ZEPTO:
				return "zepto";
			case prefix::YOCTO:
				return "yocto";
		}
		return "";
	}

	string prefix::get_symbol() const
	{
		switch (prefix_type)
		{
			case prefix::YOTTA:
				return "Y";
			case prefix::ZETTA:
				return "Z";
			case prefix::EXA:
				return "E";
			case prefix::PETA:
				return "P";
			case prefix::TERA:
				return "T";
			case prefix::GIGA:
				return "G";
			case prefix::MEGA:
				return "M";
			case prefix::KILO:
				return "k";
			case prefix::HECTO:
				return "h";
			case prefix::DECA:
				return "da";
			case prefix::NONE:
				return "";
			case prefix::DECI:
				return "d";
			case prefix::CENTI:
				return "c";
			case prefix::MILLI:
				return "m";
			case prefix::MICRO:
				return "\u00B5";
			case prefix::NANO:
				return "n";
			case prefix::PICO:
				return "p";
			case prefix::FEMTO:
				return "f";
			case prefix::ATTO:
				return "a";
			case prefix::ZEPTO:
				return "z";
			case prefix::YOCTO:
				return "y";
		}
		return "";
	}

	bool prefix::operator<(const scifir::prefix& x) const
	{
		return (get_conversion_factor() < x.get_conversion_factor());
	}

	prefix::type prefix_string(const string& x)
	{
		if (x == "Y")
		{
			return prefix::YOTTA;
		}
		else if (x == "Z")
		{
			return prefix::ZETTA;
		}
		else if (x == "E")
		{
			return prefix::EXA;
		}
		else if (x == "P")
		{
			return prefix::PETA;
		}
		else if (x == "T")
		{
			return prefix::TERA;
		}
		else if(x == "G")
		{
			return prefix::GIGA;
		}
		else if(x == "M")
		{
			return prefix::MEGA;
		}
		else if(x == "k")
		{
			return prefix::KILO;
		}
		else if(x == "h")
		{
			return prefix::HECTO;
		}
		else if(x == "da")
		{
			return prefix::DECA;
		}
		else if(x == "d")
		{
			return prefix::DECI;
		}
		else if(x == "c")
		{
			return prefix::CENTI;
		}
		else if(x == "m")
		{
			return prefix::MILLI;
		}
		else if(x == "u" or x == "\u00B5")
		{
			return prefix::MICRO;
		}
		else if(x == "n")
		{
			return prefix::NANO;
		}
		else if(x == "p")
		{
			return prefix::PICO;
		}
		else if(x == "f")
		{
			return prefix::FEMTO;
		}
		else if(x == "a")
		{
			return prefix::ATTO;
		}
		else if(x == "z")
		{
			return prefix::ZEPTO;
		}
		else if(x == "y")
		{
			return prefix::YOCTO;
		}
		else if (x == "")
		{
			return prefix::NONE;
		}
		else
		{
			return prefix::NONE;
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
			return prefix(prefix::NONE);
		}
		else if (factor == 1)
		{
			return prefix(prefix::DECA);
		}
		else if (factor == 2)
		{
			return prefix(prefix::HECTO);
		}
		else if (factor == -1)
		{
			return prefix(prefix::DECI);
		}
		else if (factor == -2)
		{
			return prefix(prefix::CENTI);
		}
		else if (factor >= 3 and factor < 6)
		{
			return prefix(prefix::KILO);
		}
		else if (factor >= 6 and factor < 9)
		{
			return prefix(prefix::MEGA);
		}
		else if (factor >= 9 and factor < 12)
		{
			return prefix(prefix::GIGA);
		}
		else if (factor >= 12 and factor < 15)
		{
			return prefix(prefix::TERA);
		}
		else if (factor >= 15 and factor < 18)
		{
			return prefix(prefix::PETA);
		}
		else if (factor >= 18 and factor < 21)
		{
			return prefix(prefix::EXA);
		}
		else if (factor >= 21 and factor < 24)
		{
			return prefix(prefix::ZETTA);
		}
		else if (factor >= 24)
		{
			return prefix(prefix::YOTTA);
		}
		else if (factor <= -3 and factor > -6)
		{
			return prefix(prefix::MILLI);
		}
		else if (factor <= -6 and factor > -9)
		{
			return prefix(prefix::MICRO);
		}
		else if (factor <= -9 and factor > -12)
		{
			return prefix(prefix::NANO);
		}
		else if (factor <= -12 and factor > -15)
		{
			return prefix(prefix::PICO);
		}
		else if (factor <= -15 and factor > -18)
		{
			return prefix(prefix::FEMTO);
		}
		else if (factor <= -18 and factor > -21)
		{
			return prefix(prefix::ATTO);
		}
		else if (factor <= -21 and factor > -24)
		{
			return prefix(prefix::ZEPTO);
		}
		else if (factor <= -24)
		{
			return prefix(prefix::YOCTO);
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
