#include "prefix.hpp"

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

namespace msci::units
{
	prefix::prefix(): scale(1)
	{
	}

	const int prefix_yotta::conversion_factor = 24;
	const string prefix_yotta::name = "yotta";
	const string prefix_yotta::symbol = "Y";

	prefix_symbol prefix_yotta::get_enum_type() const
	{
		return prefix_symbol::yotta;
	}

	const int prefix_zetta::conversion_factor = 21;
	const string prefix_zetta::name = "zetta";
	const string prefix_zetta::symbol = "Z";

	prefix_symbol prefix_zetta::get_enum_type() const
	{
		return prefix_symbol::zetta;
	}

	const int prefix_exa::conversion_factor = 18;
	const string prefix_exa::name = "exa";
	const string prefix_exa::symbol = "E";

	prefix_symbol prefix_exa::get_enum_type() const
	{
		return prefix_symbol::exa;
	}

	const int prefix_peta::conversion_factor = 15;
	const string prefix_peta::name = "peta";
	const string prefix_peta::symbol = "P";

	prefix_symbol prefix_peta::get_enum_type() const
	{
		return prefix_symbol::peta;
	}

	const int prefix_tera::conversion_factor = 12;
	const string prefix_tera::name = "tera";
	const string prefix_tera::symbol = "T";

	prefix_symbol prefix_tera::get_enum_type() const
	{
		return prefix_symbol::tera;
	}

	const int prefix_giga::conversion_factor = 9;
	const string prefix_giga::name = "giga";
	const string prefix_giga::symbol = "G";

	prefix_symbol prefix_giga::get_enum_type() const
	{
		return prefix_symbol::giga;
	}

	const int prefix_mega::conversion_factor = 6;
	const string prefix_mega::name = "mega";
	const string prefix_mega::symbol = "M";

	prefix_symbol prefix_mega::get_enum_type() const
	{
		return prefix_symbol::mega;
	}

	const int prefix_kilo::conversion_factor = 3;
	const string prefix_kilo::name = "kilo";
	const string prefix_kilo::symbol = "k";

	prefix_symbol prefix_kilo::get_enum_type() const
	{
		return prefix_symbol::kilo;
	}

	const int prefix_hecto::conversion_factor = 2;
	const string prefix_hecto::name = "hecto";
	const string prefix_hecto::symbol = "h";

	prefix_symbol prefix_hecto::get_enum_type() const
	{
		return prefix_symbol::hecto;
	}

	const int prefix_deca::conversion_factor = 1;
	const string prefix_deca::name = "deca";
	const string prefix_deca::symbol = "da";

	prefix_symbol prefix_deca::get_enum_type() const
	{
		return prefix_symbol::deca;
	}

	const int prefix_normal::conversion_factor = 0;
	const string prefix_normal::name = "";
	const string prefix_normal::symbol = "";

	prefix_symbol prefix_normal::get_enum_type() const
	{
		return prefix_symbol::normal_prefix;
	}

	const int prefix_deci::conversion_factor = -1;
	const string prefix_deci::name = "deci";
	const string prefix_deci::symbol = "d";

	prefix_symbol prefix_deci::get_enum_type() const
	{
		return prefix_symbol::deci;
	}

	const int prefix_centi::conversion_factor = -2;
	const string prefix_centi::name = "centi";
	const string prefix_centi::symbol = "c";

	prefix_symbol prefix_centi::get_enum_type() const
	{
		return prefix_symbol::centi;
	}

	const int prefix_milli::conversion_factor = -3;
	const string prefix_milli::name = "milli";
	const string prefix_milli::symbol = "m";

	prefix_symbol prefix_milli::get_enum_type() const
	{
		return prefix_symbol::milli;
	}

	const int prefix_micro::conversion_factor = -6;
	const string prefix_micro::name = "micro";
	const string prefix_micro::symbol = "μ";

	prefix_symbol prefix_micro::get_enum_type() const
	{
		return prefix_symbol::micro;
	}

	const int prefix_nano::conversion_factor = -9;
	const string prefix_nano::name = "nano";
	const string prefix_nano::symbol = "n";

	prefix_symbol prefix_nano::get_enum_type() const
	{
		return prefix_symbol::nano;
	}

	const int prefix_pico::conversion_factor = -12;
	const string prefix_pico::name = "pico";
	const string prefix_pico::symbol = "p";

	prefix_symbol prefix_pico::get_enum_type() const
	{
		return prefix_symbol::pico;
	}

	const int prefix_femto::conversion_factor = -15;
	const string prefix_femto::name = "femto";
	const string prefix_femto::symbol = "f";

	prefix_symbol prefix_femto::get_enum_type() const
	{
		return prefix_symbol::femto;
	}

	const int prefix_atto::conversion_factor = -18;
	const string prefix_atto::name = "atto";
	const string prefix_atto::symbol = "a";

	prefix_symbol prefix_atto::get_enum_type() const
	{
		return prefix_symbol::atto;
	}

	const int prefix_zepto::conversion_factor = -21;
	const string prefix_zepto::name = "zepto";
	const string prefix_zepto::symbol = "z";

	prefix_symbol prefix_zepto::get_enum_type() const
	{
		return prefix_symbol::zepto;
	}

	const int prefix_yocto::conversion_factor = -24;
	const string prefix_yocto::name = "yocto";
	const string prefix_yocto::symbol = "y";

	prefix_symbol prefix_yocto::get_enum_type() const
	{
		return prefix_symbol::yocto;
	}

	prefix* create_prefix(prefix_symbol x)
	{
		switch(x)
		{
			case yotta:
				return new prefix_yotta();
			case zetta:
				return new prefix_zetta();
			case exa:
				return new prefix_exa();
			case peta:
				return new prefix_peta();
			case tera:
				return new prefix_tera();
			case giga:
				return new prefix_giga();
			case mega:
				return new prefix_mega();
			case kilo:
				return new prefix_kilo();
			case hecto:
				return new prefix_hecto();
			case deca:
				return new prefix_deca();
			case normal_prefix:
				return new prefix_normal();
			case deci:
				return new prefix_deci();
			case centi:
				return new prefix_centi();
			case milli:
				return new prefix_milli();
			case micro:
				return new prefix_micro();
			case nano:
				return new prefix_nano();
			case pico:
				return new prefix_pico();
			case femto:
				return new prefix_femto();
			case atto:
				return new prefix_atto();
			case zepto:
				return new prefix_zepto();
			case yocto:
				return new prefix_yocto();
		}
		return nullptr;
	}

	prefix* create_prefix(const string& x)
	{
		if(x == "Y")
		{
			return new prefix_yotta();
		}
		else if(x == "Z")
		{
			return new prefix_zetta();
		}
		else if(x == "E")
		{
			return new prefix_exa();
		}
		else if(x == "P")
		{
			return new prefix_peta();
		}
		else if(x == "T")
		{
			return new prefix_tera();
		}
		else if(x == "M")
		{
			return new prefix_mega();
		}
		else if(x == "k")
		{
			return new prefix_kilo();
		}
		else if(x == "h")
		{
			return new prefix_hecto();
		}
		else if(x == "da")
		{
			return new prefix_deca();
		}
		else if(x == "d")
		{
			return new prefix_deci();
		}
		else if(x == "c")
		{
			return new prefix_centi();
		}
		else if(x == "m")
		{
			return new prefix_milli();
		}
		else if(x == "u")
		{
			return new prefix_micro();
		}
		else if(x == "n")
		{
			return new prefix_nano();
		}
		else if(x == "p")
		{
			return new prefix_pico();
		}
		else if(x == "f")
		{
			return new prefix_femto();
		}
		else if(x == "a")
		{
			return new prefix_atto();
		}
		else if(x == "z")
		{
			return new prefix_zepto();
		}
		else if(x == "y")
		{
			return new prefix_yocto();
		}
		else
		{
			return nullptr;
		}
	}
}
