#include "./dimension.hpp"

#include "../topology/constants.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

namespace scifir
{
	map<string,vector<dimension>> dimension::base_dimensions = map<string,vector<dimension>>();
	map<int,string> dimension::full_symbols = map<int,string>();
	int dimension::total_full_symbols = 0;
	set<string> dimension::prefixes_options {"Y", "Z", "E", "P", "T", "G", "M", "k", "h", "d", "c", "m", "\u00B5", "u", "n", "p", "f", "a", "z", "y"};

	dimension::dimension() : prefix(),dimension_type(dimension::none),dimension_sign(dimension::NO_SIGN),symbol()
	{}

	dimension::dimension(const dimension& x) : prefix(x.prefix),dimension_type(x.dimension_type),dimension_sign(x.dimension_sign)
	{
		std::strcpy(symbol, x.symbol);
	}

	dimension::dimension(dimension&& x) : prefix(move(x.prefix)),dimension_type(move(x.dimension_type)),dimension_sign(move(x.dimension_sign))
	{
		std::strcpy(symbol, move(x.symbol));
	}

	dimension::dimension(dimension::type new_dimension_type,scifir::prefix::type new_prefix,dimension::sign new_sign) : prefix(new_prefix),dimension_type(new_dimension_type),dimension_sign(new_sign),symbol()
	{}

	dimension::dimension(dimension::type new_dimension_type,const scifir::prefix& new_prefix,dimension::sign new_sign) : prefix(new_prefix),dimension_type(new_dimension_type),dimension_sign(new_sign),symbol()
	{}

	dimension::dimension(const string& init_dimension,dimension::sign new_sign) : prefix(),dimension_type(dimension::none),dimension_sign(new_sign),symbol()
	{
		string dimension_name;
		string prefix_name;
		if(dimension::prefixes_options.count(init_dimension.substr(0,1)) and init_dimension != "rad" and init_dimension != "sr" and init_dimension != "m" and init_dimension.substr(0,2) != "da" and init_dimension.substr(0,3) != "mol" and init_dimension != "h" and init_dimension != "d" and init_dimension != "cd" and init_dimension != "money" and init_dimension != "memo")
		{
			prefix_name = init_dimension.substr(0,1);
			dimension_name = init_dimension.substr(1);
		}
		else if(init_dimension.substr(0,2) == "da")
		{
			prefix_name = "da";
			dimension_name = init_dimension.substr(2);
		}
		else
		{
			prefix_name = "";
			dimension_name = init_dimension;
		}
		prefix = scifir::prefix(prefix_name);
		if(dimension_name == "m")
		{
			dimension_type = dimension::m;
		}
		else if(dimension_name == "rad")
		{
			dimension_type = dimension::radian;
		}
		else if(dimension_name == "sr")
		{
			dimension_type = dimension::steradian;
		}
		else if(dimension_name == "s")
		{
			dimension_type = dimension::s;
		}
		else if(dimension_name == "g")
		{
			dimension_type = dimension::g;
		}
		else if(dimension_name == "C")
		{
			dimension_type = dimension::C;
		}
		else if(dimension_name == "K")
		{
			dimension_type = dimension::K;
		}
		else if(dimension_name == "mol")
		{
			dimension_type = dimension::mol;
		}
		else if(dimension_name == "cd")
		{
			dimension_type = dimension::cd;
		}
		else if(dimension_name == "B")
		{
			dimension_type = dimension::B;
		}
		else if(dimension_name == "Hz")
		{
			dimension_type = dimension::Hz;
		}
		else if(dimension_name == "N")
		{
			dimension_type = dimension::N;
		}
		else if(dimension_name == "Pa")
		{
			dimension_type = dimension::Pa;
		}
		else if(dimension_name == "J")
		{
			dimension_type = dimension::J;
		}
		else if(dimension_name == "W")
		{
			dimension_type = dimension::W;
		}
		else if(dimension_name == "A")
		{
			dimension_type = dimension::A;
		}
		else if(dimension_name == "V")
		{
			dimension_type = dimension::V;
		}
		else if(dimension_name == "F")
		{
			dimension_type = dimension::F;
		}
		else if(dimension_name == "ohm" or dimension_name == "Ohm" or dimension_name == "\u03A9")
		{
			dimension_type = dimension::Ohm;
		}
		else if(dimension_name == "S")
		{
			dimension_type = dimension::S;
		}
		else if(dimension_name == "Wb")
		{
			dimension_type = dimension::Wb;
		}
		else if(dimension_name == "T")
		{
			dimension_type = dimension::T;
		}
		else if(dimension_name == "H")
		{
			dimension_type = dimension::H;
		}
		else if(dimension_name == "lm")
		{
			dimension_type = dimension::lm;
		}
		else if(dimension_name == "lx")
		{
			dimension_type = dimension::lx;
		}
		else if(dimension_name == "Bq")
		{
			dimension_type = dimension::Bq;
		}
		else if(dimension_name == "Gy")
		{
			dimension_type = dimension::Gy;
		}
		else if(dimension_name == "Sv")
		{
			dimension_type = dimension::Sv;
		}
		else if(dimension_name == "kat")
		{
			dimension_type = dimension::kat;
		}
		else if(dimension_name == "angstrom" or dimension_name == "\u212B")
		{
			dimension_type = dimension::angstrom;
		}
		else if(dimension_name == "L")
		{
			dimension_type = dimension::L;
		}
		else if(dimension_name == "min")
		{
			dimension_type = dimension::minute;
		}
		else if(dimension_name == "h")
		{
			dimension_type = dimension::h;
		}
		else if(dimension_name == "d")
		{
			dimension_type = dimension::d;
		}
		else if(dimension_name == "AU")
		{
			dimension_type = dimension::AU;
		}
		else if(dimension_name == "pc")
		{
			dimension_type = dimension::pc;
		}
		else if(dimension_name == "eV")
		{
			dimension_type = dimension::eV;
		}
		else if(dimension_name == "Da")
		{
			dimension_type = dimension::Da;
		}
		else if(dimension_name == "amu")
		{
			dimension_type = dimension::amu;
		}
		else if(dimension_name == "barn")
		{
			dimension_type = dimension::barn;
		}
		else if(dimension_name == "M")
		{
			dimension_type = dimension::M;
		}
		else if(dimension_name == "particles")
		{
			dimension_type = dimension::particles;
		}
		else if(dimension_name == "money")
		{
			dimension_type = dimension::money;
		}
		else if(dimension_name == "px")
		{
			dimension_type = dimension::pixel;
		}
		else if(dimension_name == "memo")
		{
			dimension_type = dimension::memo;
		}
		else if(dimension_name == "")
		{
			dimension_type = dimension::none;
		}
		else
		{
			prefix = scifir::prefix(prefix::no_prefix);
			if (init_dimension.size() > 3)
			{
				string symbol_abreviation = dimension::create_full_symbol(init_dimension);
				symbol_abreviation.copy(symbol, init_dimension.length());
				dimension_type = dimension::custom_full_symbol;
			}
			else
			{
				init_dimension.copy(symbol, init_dimension.length());
				dimension_type = dimension::custom;
			}
		}
	}

	dimension::~dimension()
	{
		//free(symbol);
	}

	dimension& dimension::operator=(const dimension& x)
	{
		prefix = x.prefix;
		dimension_type = x.dimension_type;
		dimension_sign = x.dimension_sign;
		strcpy(symbol,x.symbol);
		return *this;
	}
	
	dimension& dimension::operator=(dimension&& x)
	{
		prefix = move(x.prefix);
		dimension_type = move(x.dimension_type);
		dimension_sign = move(x.dimension_sign);
		strcpy(symbol,move(x.symbol));
		return *this;
	}

	string dimension::get_name() const
	{
		switch(dimension_type)
		{
			case dimension::m:
				return "meter";
			case dimension::radian:
				return "radian";
			case dimension::steradian:
				return "steradian";
			case dimension::g:
				return "gram";
			case dimension::s:
				return "second";
			case dimension::C:
				return "coulomb";
			case dimension::K:
				return "kelvin";
			case dimension::mol:
				return "mole";
			case dimension::cd:
				return "candela";
			case dimension::B:
				return "byte";
			case dimension::Hz:
				return "hertz";
			case dimension::N:
				return "newton";
			case dimension::Pa:
				return "pascal";
			case dimension::J:
				return "joule";
			case dimension::W:
				return "watt";
			case dimension::A:
				return "ampere";
			case dimension::V:
				return "volt";
			case dimension::F:
				return "faraday";
			case dimension::Ohm:
				return "ohm";
			case dimension::S:
				return "siemens";
			case dimension::Wb:
				return "weber";
			case dimension::T:
				return "tesla";
			case dimension::H:
				return "henry";
			case dimension::lm:
				return "lumen";
			case dimension::lx:
				return "lux";
			case dimension::Bq:
				return "becquerel";
			case dimension::Gy:
				return "gray";
			case dimension::Sv:
				return "sievert";
			case dimension::kat:
				return "katal";
			case dimension::angstrom:
				return "angstrom";
			case dimension::L:
				return "liter";
			case dimension::minute:
				return "minute";
			case dimension::h:
				return "hour";
			case dimension::d:
				return "day";
			case dimension::AU:
				return "astronomical unit";
			case dimension::pc:
				return "parsec";
			case dimension::eV:
				return "electronvolt";
			case dimension::Da:
				return "dalton";
			case dimension::amu:
				return "atomic mass unit";
			case dimension::barn:
				return "barn";
			case dimension::M:
				return "molarity";
			case dimension::particles:
				return "particles";
			case dimension::custom:
				return "custom-dimension";
			case dimension::custom_basic:
				return "custom-basic";
			case dimension::custom_full_symbol:
				return "custom-full-symbol";
			case dimension::money:
				return "money";
			case dimension::pixel:
				return "pixel";
			case dimension::memo:
				return "memo";
			case dimension::none:
				return "none";
		}
		return "";
	}

	string dimension::get_symbol() const
	{
		switch(dimension_type)
		{
			case dimension::m:
				return "m";
			case dimension::radian:
				return "rad";
			case dimension::steradian:
				return "sr";
			case dimension::g:
				return "g";
			case dimension::s:
				return "s";
			case dimension::C:
				return "C";
			case dimension::K:
				return "K";
			case dimension::mol:
				return "mol";
			case dimension::cd:
				return "cd";
			case dimension::B:
				return "B";
			case dimension::Hz:
				return "Hz";
			case dimension::N:
				return "N";
			case dimension::Pa:
				return "Pa";
			case dimension::J:
				return "J";
			case dimension::W:
				return "W";
			case dimension::A:
				return "A";
			case dimension::V:
				return "V";
			case dimension::F:
				return "F";
			case dimension::Ohm:
				return "\u03A9";
			case dimension::S:
				return "S";
			case dimension::Wb:
				return "Wb";
			case dimension::T:
				return "T";
			case dimension::H:
				return "H";
			case dimension::lm:
				return "lm";
			case dimension::lx:
				return "lx";
			case dimension::Bq:
				return "Bq";
			case dimension::Gy:
				return "Gy";
			case dimension::Sv:
				return "Sv";
			case dimension::kat:
				return "kat";
			case dimension::angstrom:
				return "\u212B";
			case dimension::L:
				return "L";
			case dimension::minute:
				return "min";
			case dimension::h:
				return "h";
			case dimension::d:
				return "d";
			case dimension::AU:
				return "AU";
			case dimension::pc:
				return "pc";
			case dimension::eV:
				return "eV";
			case dimension::Da:
				return "Da";
			case dimension::amu:
				return "amu";
			case dimension::barn:
				return "barn";
			case dimension::M:
				return "M";
			case dimension::particles:
				return "particles";
			case dimension::custom:
				return string("").assign(symbol, symbol + 3);
			case dimension::custom_basic:
				return "custom-basic";
			case dimension::custom_full_symbol:
				return dimension::get_full_symbol(symbol);
			case dimension::money:
				return "money";
			case dimension::pixel:
				return "px";
			case dimension::memo:
				return "memo";
			case dimension::none:
				return "empty";
		}
		return "";
	}

	long double dimension::get_conversion_factor() const
	{
		switch(dimension_type)
		{
			case dimension::m:
				return 1l;
			case dimension::radian:
				return 1l;
			case dimension::steradian:
				return 1l;
			case dimension::g:
				return 1l;
			case dimension::s:
				return 1l;
			case dimension::C:
				return 1l;
			case dimension::K:
				return 1l;
			case dimension::mol:
				return 1l;
			case dimension::cd:
				return 1l;
			case dimension::B:
				return 1l;
			case dimension::Hz:
				return 1l;
			case dimension::N:
				return 1l;
			case dimension::Pa:
				return 1l;
			case dimension::J:
				return 1l;
			case dimension::W:
				return 1l;
			case dimension::A:
				return 1l;
			case dimension::V:
				return 1l;
			case dimension::F:
				return 1;
			case dimension::Ohm:
				return 1l;
			case dimension::S:
				return 1l;
			case dimension::Wb:
				return 1l;
			case dimension::T:
				return 1l;
			case dimension::H:
				return 1l;
			case dimension::lm:
				return 1l;
			case dimension::lx:
				return 1l;
			case dimension::Bq:
				return 1l;
			case dimension::Gy:
				return 1l;
			case dimension::Sv:
				return 1l;
			case dimension::kat:
				return 1l;
			case dimension::angstrom:
				return 1l;
			case dimension::L:
				return 1l;
			case dimension::minute:
				return 60l;
			case dimension::h:
				return 3600l;
			case dimension::d:
				return 86400l;
			case dimension::AU:
				return 149597870700.0l;
			case dimension::pc:
				return 30856775814913673.0l;
			case dimension::eV:
				return 0.0000000000000000001602176634l;
			case dimension::Da:
				return 0.00000000000000000000000000166053886l;
			case dimension::amu:
				return 0.00000000000000000000000000166053886l;
			case dimension::barn:
				return 0.0000000000000000000000000001l;
			case dimension::M:
				return 1l;
			case dimension::particles:
				return 1l/AVOGADRO_CONSTANT;
			case dimension::custom:
				return 1l;
			case dimension::custom_basic:
				return 1l;
			case dimension::custom_full_symbol:
				return 1l;
			case dimension::money:
				return 1l;
			case dimension::pixel:
				return 0.00026l;
			case dimension::memo:
				return 1l;
			case dimension::none:
				return 1l;
		}
		return 1l;
	}

	long double dimension::prefix_math() const
	{
		return scifir::prefix_math(*this, prefix);
	}

	bool dimension::is_simple_dimension() const
	{
		switch(dimension_type)
		{
			case dimension::m:
				return true;
			case dimension::radian:
				return true;
			case dimension::steradian:
				return true;
			case dimension::g:
				return true;
			case dimension::s:
				return true;
			case dimension::C:
				return true;
			case dimension::K:
				return true;
			case dimension::mol:
				return true;
			case dimension::cd:
				return true;
			case dimension::B:
				return true;
			case dimension::Hz:
				return true;
			case dimension::N:
				return false;
			case dimension::Pa:
				return false;
			case dimension::J:
				return false;
			case dimension::W:
				return false;
			case dimension::A:
				return true;
			case dimension::V:
				return false;
			case dimension::F:
				return false;
			case dimension::Ohm:
				return false;
			case dimension::S:
				return false;
			case dimension::Wb:
				return false;
			case dimension::T:
				return false;
			case dimension::H:
				return false;
			case dimension::lm:
				return false;
			case dimension::lx:
				return false;
			case dimension::Bq:
				return true;
			case dimension::Gy:
				return false;
			case dimension::Sv:
				return false;
			case dimension::kat:
				return false;
			case dimension::angstrom:
				return true;
			case dimension::L:
				return false;
			case dimension::minute:
				return true;
			case dimension::h:
				return true;
			case dimension::d:
				return true;
			case dimension::AU:
				return true;
			case dimension::pc:
				return true;
			case dimension::eV:
				return false;
			case dimension::Da:
				return true;
			case dimension::amu:
				return true;
			case dimension::barn:
				return false;
			case dimension::M:
				return false;
			case dimension::particles:
				return true;
			case dimension::custom:
				return false;
			case dimension::custom_basic:
				return true;
			case dimension::custom_full_symbol:
				return false;
			case dimension::money:
				return true;
			case dimension::pixel:
				return true;
			case dimension::memo:
				return true;
			case dimension::none:
				return true;
		}
		return false;
	}

	bool dimension::is_basic_dimension() const
	{
		switch(dimension_type)
		{
			case dimension::m:
				return true;
			case dimension::radian:
				return true;
			case dimension::steradian:
				return true;
			case dimension::g:
				return true;
			case dimension::s:
				return true;
			case dimension::C:
				return true;
			case dimension::K:
				return true;
			case dimension::mol:
				return true;
			case dimension::cd:
				return true;
			case dimension::B:
				return true;
			case dimension::Hz:
				return false;
			case dimension::N:
				return false;
			case dimension::Pa:
				return false;
			case dimension::J:
				return false;
			case dimension::W:
				return false;
			case dimension::A:
				return false;
			case dimension::V:
				return false;
			case dimension::F:
				return false;
			case dimension::Ohm:
				return false;
			case dimension::S:
				return false;
			case dimension::Wb:
				return false;
			case dimension::T:
				return false;
			case dimension::H:
				return false;
			case dimension::lm:
				return false;
			case dimension::lx:
				return false;
			case dimension::Bq:
				return false;
			case dimension::Gy:
				return false;
			case dimension::Sv:
				return false;
			case dimension::kat:
				return false;
			case dimension::angstrom:
				return false;
			case dimension::L:
				return false;
			case dimension::minute:
				return false;
			case dimension::h:
				return false;
			case dimension::d:
				return false;
			case dimension::AU:
				return false;
			case dimension::pc:
				return false;
			case dimension::eV:
				return false;
			case dimension::Da:
				return false;
			case dimension::amu:
				return false;
			case dimension::barn:
				return false;
			case dimension::M:
				return false;
			case dimension::particles:
				return false;
			case dimension::custom:
				return false;
			case dimension::custom_basic:
				return true;
			case dimension::custom_full_symbol:
				return false;
			case dimension::money:
				return true;
			case dimension::pixel:
				return false;
			case dimension::memo:
				return true;
			case dimension::none:
				return true;
		}
		return true;
	}

	bool dimension::is_derived_dimension() const
	{
		return !is_basic_dimension();
	}

	vector<dimension> dimension::get_basic_dimensions() const
	{
		vector<dimension> basic_dimensions = vector<dimension>();
		switch (dimension_type)
		{
			case dimension::m:
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::radian:
				basic_dimensions.push_back(dimension(dimension::radian,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::steradian:
				basic_dimensions.push_back(dimension(dimension::steradian,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::s:
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::g:
				basic_dimensions.push_back(dimension(dimension::g,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::C:
				basic_dimensions.push_back(dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::K:
				basic_dimensions.push_back(dimension(dimension::K,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::mol:
				basic_dimensions.push_back(dimension(dimension::mol,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::cd:
				basic_dimensions.push_back(dimension(dimension::cd,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::B:
				basic_dimensions.push_back(dimension(dimension::B,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::Hz:
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::N:
				basic_dimensions.push_back(dimension(dimension::g,prefix::k,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::Pa:
				basic_dimensions.push_back(dimension(dimension::g,prefix::k,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::J:
				basic_dimensions.push_back(dimension(dimension::g,prefix::k,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::W:
				basic_dimensions.push_back(dimension(dimension::g,prefix::k,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::A:
				basic_dimensions.push_back(dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::V:
				basic_dimensions.push_back(dimension(dimension::g,prefix::k,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::F:
				basic_dimensions.push_back(dimension(dimension::g,prefix::k,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::Ohm:
				basic_dimensions.push_back(dimension(dimension::g,prefix::k,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::S:
				basic_dimensions.push_back(dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::g,prefix::k,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::Wb:
				basic_dimensions.push_back(dimension(dimension::g,prefix::k,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::T:
				basic_dimensions.push_back(dimension(dimension::g,prefix::k,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::H:
				basic_dimensions.push_back(dimension(dimension::g,prefix::k,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::lm:
				basic_dimensions.push_back(dimension(dimension::cd,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::steradian,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::lx:
				basic_dimensions.push_back(dimension(dimension::cd,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::steradian,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::Bq:
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::Gy:
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::Sv:
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::kat:
				basic_dimensions.push_back(dimension(dimension::mol,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::angstrom:
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::L:
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::minute:
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::h:
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::d:
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::AU:
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::pc:
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::eV:
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::g,prefix::k,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::Da:
				basic_dimensions.push_back(dimension(dimension::g,prefix::k,dimension::POSITIVE));
				break;
			case dimension::amu:
				basic_dimensions.push_back(dimension(dimension::g,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::barn:
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::M:
				basic_dimensions.push_back(dimension(dimension::mol,prefix::no_prefix,dimension::POSITIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE));
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE));
				break;
			case dimension::particles:
				basic_dimensions.push_back(dimension(dimension::mol,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::custom:
			{
				return dimension::base_dimensions[symbol];
			}
			case dimension::custom_basic:
			{
				basic_dimensions.push_back(*this);
				break;
			}
			case dimension::custom_full_symbol:
			{
				return dimension::base_dimensions[dimension::get_full_symbol(symbol)];
			}
			case dimension::money:
				basic_dimensions.push_back(dimension(dimension::money,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::pixel:
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::memo:
				basic_dimensions.push_back(dimension(dimension::memo,prefix::no_prefix,dimension::POSITIVE));
				break;
			case dimension::none:
				basic_dimensions.push_back(dimension(dimension::none,prefix::no_prefix,dimension::POSITIVE));
				break;
		}
		return basic_dimensions;
	}

	void dimension::invert()
	{
		if (dimension_sign == dimension::POSITIVE)
		{
			dimension_sign = dimension::NEGATIVE;
		}
		else
		{
			dimension_sign = dimension::POSITIVE;
		}
	}

	string to_string(const dimension& x)
	{
		ostringstream out;
		out << x.prefix << x.get_symbol();
		return out.str();
	}

	string to_string(const vector<dimension>& x_dimensions,bool with_brackets)
	{
		ostringstream out;
		if (x_dimensions.size() > 0)
		{
			if (with_brackets)
			{
				out << "[";
			}
			vector<dimension::type> printed_dimensions = vector<dimension::type>();
			map<prefix,int> counted_prefixes = map<prefix,int>();
			for (const dimension& x_dimension : x_dimensions)
			{
				if (x_dimension.dimension_sign == dimension::POSITIVE)
				{
					bool printed = false;
					for (const dimension::type& print_dimension : printed_dimensions)
					{
						if (print_dimension == x_dimension.dimension_type)
						{
							printed = true;
						}
					}
					if (printed == true)
					{
						continue;
					}
					counted_prefixes = map<prefix,int>();
					for (const dimension& y_dimension : x_dimensions)
					{
						if (x_dimension.dimension_type == y_dimension.dimension_type)
						{
							counted_prefixes[y_dimension.prefix]++;
						}
					}
					for (const auto& x_prefix : counted_prefixes)
					{
						if (out.str() != "")
						{
							out << "*";
						}
						out << x_prefix.first << x_dimension.get_symbol();
						if (x_prefix.second > 1)
						{
							out << x_prefix.second;
						}
					}
					printed_dimensions.push_back(x_dimension.dimension_type);
				}
			}
			printed_dimensions.clear();
			bool first_negative_iteration = true;
			bool first_negative_prefix = true;
			for (const dimension& x_dimension : x_dimensions)
			{
				if (x_dimension.dimension_sign == dimension::NEGATIVE)
				{
					if (first_negative_iteration == true)
					{
						if (out.tellp() == std::streampos(0))
						{
							out << "1";
						}
						out << "/";
						first_negative_iteration = false;
					}
					bool printed = false;
					for (const dimension::type& print_dimension : printed_dimensions)
					{
						if (print_dimension == x_dimension.dimension_type)
						{
							printed = true;
						}
					}
					if (printed == true)
					{
						continue;
					}
					counted_prefixes = map<prefix,int>();
					for (const dimension& y_dimension : x_dimensions)
					{
						if (x_dimension.dimension_type == y_dimension.dimension_type)
						{
							counted_prefixes[y_dimension.prefix]++;
						}
					}
					for (const auto& x_prefix : counted_prefixes)
					{
						if (first_negative_prefix == false)
						{
							out << "*";
						}
						out << x_prefix.first << x_dimension.get_symbol();
						if (x_prefix.second > 1)
						{
							out << x_prefix.second;
						}
						first_negative_prefix = false;
					}
					printed_dimensions.push_back(x_dimension.dimension_type);
				}
			}
			if (with_brackets)
			{
				out << "]";
			}
		}
		else
		{
			out << "[empty]";
		}
		return out.str();
	}

	vector<dimension> create_dimensions(string init_value)
	{
		boost::algorithm::erase_all(init_value, " ");
		dimension::sign new_sign = dimension::POSITIVE;
		int new_scale = 1;
		int new_size = 1;
		int new_start = 0;
		string new_dimension_str;
		vector<dimension> dimensions = vector<dimension>();
		for(int j = 0; j < init_value.size(); j++)
		{
			if(init_value[j] == '1' and init_value[j + 1] == '/')
			{
				new_sign = dimension::NEGATIVE;
			}
			if(isalpha(init_value[j]) and (!isalpha(init_value[j + 1]) or (j + 1) == init_value.size()))
			{
				new_dimension_str = init_value.substr(new_start, new_size);
				if(isdigit(init_value[j + 1]))
				{
					new_scale = stoi(init_value.substr(j + 1, 1));
				}
			}
			if(init_value[j] == '*')
			{
				new_size = 0;
				new_start = j + 1;
			}
			else if(init_value[j] == '/')
			{
				new_sign = dimension::NEGATIVE;
				new_size = 0;
				new_start = j + 1;
			}
			if(!new_dimension_str.empty())
			{
				dimension new_dimension = dimension(new_dimension_str,new_sign);
				for (int k = 0; k < new_scale; k++)
				{
					dimensions.push_back(new_dimension);
				}
				new_dimension_str.clear();
				new_scale = 1;
				new_size = 0;
			}
			new_size++;
		}
		return dimensions;
	}

	vector<dimension> create_derived_dimensions(const string& init_value)
	{
		vector<dimension> new_dimensions = create_dimensions(init_value);
		return create_derived_dimensions(new_dimensions);
	}

	vector<dimension> create_derived_dimensions(const vector<dimension>& x)
	{
		vector<dimension> new_x = vector<dimension>();
		for(int i = 0; i < x.size(); i++)
		{
			vector<dimension> x_subdimensions = x[i].get_basic_dimensions();
			for (dimension& x_subdimension : x_subdimensions)
			{
				if (x[i].dimension_sign == dimension::NEGATIVE)
				{
					x_subdimension.invert();
				}
				new_x.push_back(x_subdimension);
			}
		}
		return new_x;
	}

	vector<dimension> create_derived_dimensions(const vector<dimension>& x,long double& value)
	{
		vector<dimension> new_x = vector<dimension>();
		for(int i = 0; i < x.size(); i++)
		{
			if (x[i].dimension_sign == dimension::POSITIVE)
			{
				value *= x[i].get_conversion_factor();
				value *= x[i].prefix_math();
			}
			else if (x[i].dimension_sign == dimension::NEGATIVE)
			{
				value /= x[i].get_conversion_factor();
				value /= x[i].prefix_math();
			}
			vector<dimension> x_subdimensions = x[i].get_basic_dimensions();
			for (dimension& x_subdimension : x_subdimensions)
			{
				if (x[i].dimension_sign == dimension::NEGATIVE)
				{
					x_subdimension.invert();
				}
				new_x.push_back(x_subdimension);
			}
		}
		return new_x;
	}

	long double prefix_math(const dimension& x_dimension,const prefix& x_prefix)
	{
		if (x_dimension.dimension_type == dimension::B)
		{
			return std::pow(1024, x_prefix.get_conversion_factor() / 3);
		}
		else
		{
			return std::pow(10, x_prefix.get_conversion_factor());
		}
	}

	vector<dimension> multiply_dimensions(const vector<dimension>& x,const vector<dimension>& y)
	{
		vector<dimension> new_dimensions = x;
		for(const dimension& y_dimension : y)
		{
			new_dimensions.push_back(y_dimension);
		}
		return new_dimensions;
	}

	vector<dimension> multiply_dimensions(vector<dimension> new_dimensions,const vector<dimension>& y,long double& value)
	{
		for(const dimension& y_dimension : y)
		{
			new_dimensions.push_back(y_dimension);
		}
		return normalize_dimensions(new_dimensions,value);
	}

	vector<dimension> divide_dimensions(vector<dimension> new_dimensions,const vector<dimension>& y,long double& value)
	{
		for(dimension y_dimension : y)
		{
			y_dimension.invert();
			new_dimensions.push_back(y_dimension);
		}
		return normalize_dimensions(new_dimensions,value);
	}

	vector<dimension> square_dimensions(vector<dimension> x,long double& value,int scale)
	{
		map<dimension::type,int> dimensions_count = map<dimension::type,int>();
		for (const dimension& x_dimension : x)
		{
			dimensions_count[x_dimension.dimension_type]++;
		}
		for (const auto& x_count : dimensions_count)
		{
			if ((x_count.second % scale) != 0)
			{
				return vector<dimension>();
			}
		}
		vector<dimension> new_dimensions = vector<dimension>();
		if (dimensions_count.size() == 1) // If there's only one type of dimension, square it and conserve its type
		{
			for (int i = 0; i < dimensions_count[x[0].dimension_type]; i++)
			{
				if (x[i].dimension_sign == dimension::POSITIVE)
				{
					value *= x[i].get_conversion_factor();
					value *= x[i].prefix_math();
				}
				else if (x[i].dimension_sign == dimension::NEGATIVE)
				{
					value /= x[i].get_conversion_factor();
					value /= x[i].prefix_math();
				}
			}
			int total_dimensions = std::pow(dimensions_count[x[0].dimension_type], 1.0 / scale);
			x[0].prefix.prefix_type = prefix::no_prefix;
			for (int j = 0; j < total_dimensions; j++)
			{
				new_dimensions.push_back(x[0]);
			}
			return new_dimensions;
		}
		else // If there's more than one type of dimension, creates the derived dimensions of them, and squares the total. If there are abbreviations, they are losed
		{
			x = normalize_dimensions(x,value);
			vector<dimension::type> counted_dimensions = vector<dimension::type>();
			dimensions_count.clear();
			for (const dimension& x_dimension : x)
			{
				dimensions_count[x_dimension.dimension_type]++;
			}
			for (const dimension& x_dimension : x)
			{
				bool counted = false;
				for (const dimension::type& counted_dimension : counted_dimensions)
				{
					if (counted_dimension == x_dimension.dimension_type)
					{
						counted = true;
					}
				}
				if (counted == true)
				{
					continue;
				}
				int total_dimensions = std::pow(dimensions_count[x_dimension.dimension_type], 1.0 / scale);
				for (int j = 0; j < total_dimensions; j++)
				{
					new_dimensions.push_back(x_dimension);
				}
				counted_dimensions.push_back(x_dimension.dimension_type);
			}
		}
		return new_dimensions;
	}

	vector<dimension> power_dimensions(const vector<dimension>& x,int scale)
	{
		vector<dimension> new_dimensions = vector<dimension>();
		for (const dimension& x_dimension: x)
		{
			for (int j = 1; j <= scale; j++)
			{
				new_dimensions.push_back(x_dimension);
			}
		}
		return new_dimensions;
	}

	vector<dimension> normalize_dimensions(const vector<dimension>& x)
	{
		vector<dimension> new_x = create_derived_dimensions(x);
		vector<int> skip_dimensions = vector<int>();
		for(int i = 0; i < new_x.size(); i++)
		{
			bool skip = false;
			for(int j = i + 1; j < new_x.size(); j++)
			{
				if (skip_dimensions.size() > 0)
				{
					bool skip = false;
					for(int k = 0; k < skip_dimensions.size(); k++)
					{
						if (j == skip_dimensions[k])
						{
							skip = true;
						}
					}
					if (skip)
					{
						continue;
					}
				}
				if (new_x[i].dimension_type == new_x[j].dimension_type and new_x[i].dimension_sign != new_x[j].dimension_sign)
				{
					skip_dimensions.push_back(i);
					skip_dimensions.push_back(j);
					break;
				}
			}
		}
		vector<dimension> new_dimensions = vector<dimension>();
		for(int i = 0; i < new_x.size(); i++)
		{
			bool skip = false;
			for(int j = 0; j < skip_dimensions.size(); j++)
			{
				if (i == skip_dimensions[j])
				{
					skip = true;
				}
			}
			if (!skip)
			{
				new_dimensions.push_back(new_x[i]);
			}
		}
		return new_dimensions;
	}

	vector<dimension> normalize_dimensions(const vector<dimension>& x,long double& value)
	{
		vector<dimension> new_x = create_derived_dimensions(x,value);
		vector<int> skip_dimensions = vector<int>();
		for(int i = 0; i < new_x.size(); i++)
		{
			bool skip = false;
			for(int j = i + 1; j < new_x.size(); j++)
			{
				if (skip_dimensions.size() > 0)
				{
					bool skip = false;
					for(int k = 0; k < skip_dimensions.size(); k++)
					{
						if (j == skip_dimensions[k])
						{
							skip = true;
						}
					}
					if (skip)
					{
						continue;
					}
				}
				if (new_x[i].dimension_type == new_x[j].dimension_type and new_x[i].dimension_sign != new_x[j].dimension_sign)
				{
					skip_dimensions.push_back(i);
					skip_dimensions.push_back(j);
					break;
				}
			}
		}
		vector<dimension> new_dimensions = vector<dimension>();
		for(int i = 0; i < new_x.size(); i++)
		{
			bool skip = false;
			for(int j = 0; j < skip_dimensions.size(); j++)
			{
				if (i == skip_dimensions[j])
				{
					skip = true;
				}
			}
			if (!skip)
			{
				new_dimensions.push_back(new_x[i]);
			}
		}
		return new_dimensions;
	}

	bool common_dimension(const dimension& x,const dimension& y)
	{
		for (const dimension& x_dimension : x.get_basic_dimensions())
		{
			for (const dimension& y_dimension : y.get_basic_dimensions())
			{
				if (x_dimension == y_dimension)
				{
					return true;
				}
			}
		}
		return false;
	}

	bool equal_dimensions(const string& x,const string& y)
	{
		vector<dimension> x_dimensions = create_dimensions(x);
		vector<dimension> y_dimensions = create_dimensions(y);
		return equal_dimensions(x_dimensions,y_dimensions);
	}

	bool equal_dimensions(const vector<dimension>& x,const vector<dimension>& y)
	{
		vector<dimension> x_derived_dimensions = create_derived_dimensions(x);
		vector<dimension> y_derived_dimensions = create_derived_dimensions(y);
		vector<int> skip = vector<int>();
		for (const dimension& x_dimension: x_derived_dimensions)
		{
			bool is_equal = false;
			for (int j = 0; j < y_derived_dimensions.size(); j++)
			{
				bool skip_j = false;
				if (skip.size() > 0)
				{
					for (int k = 0; k < skip.size(); k++)
					{
						if (j == skip[k])
						{
							skip_j = true;
						}
					}
				}
				if (skip_j)
				{
					continue;
				}
				if (x_dimension == y_derived_dimensions[j])
				{
					skip.push_back(j);
					is_equal = true;
					break;
				}
			}
			if (!is_equal)
			{
				return false;
			}
		}
		return true;
	}
}

bool operator==(const scifir::dimension& x,const scifir::dimension& y)
{
	if (x.dimension_type == y.dimension_type and x.dimension_sign == y.dimension_sign)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const scifir::dimension& x,const scifir::dimension& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os, const scifir::dimension& x)
{
	return os << x.prefix.get_symbol() << x.get_symbol();
}
