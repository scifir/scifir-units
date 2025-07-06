#include "./dimension.hpp"

#include "./constants.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iostream>
#include <numbers>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <codecvt>

#ifdef IS_WINDOWS
#include <cstring>
//	#define UNICODE
//	#define _UNICODE
#endif

using namespace std;

namespace scifir
{
	map<string,vector<dimension>> dimension::base_dimensions = map<string,vector<dimension>>();
	map<int,string> dimension::full_symbols = map<int,string>();
	int dimension::total_full_symbols = 0;
	
	/*bool dimension::CaseInsensitiveCompare::operator()(const std::string& a, const std::string& b) const {
		return _stricmp(a.c_str(), b.c_str()) < 0;
	}*/
	vector<string> dimension::prefixes_options {"Q", "R", "Y", "Z", "E", "P", "T", "G", "M", "k", "h", "d", "c", "m", "n", "p", "f", "a", "z", "y", "r", "q"};

	dimension::dimension() : prefix(),dimension_type(dimension::NONE),dimension_position(dimension::NO_POSITION),symbol()
	{}

#ifdef IS_UNIX
	dimension::dimension(const dimension& x) : prefix(x.prefix),dimension_type(x.dimension_type),dimension_position(x.dimension_position)
	{
		std::strncpy(symbol, x.symbol, 3);
	}

	dimension::dimension(dimension&& x) : prefix(std::move(x.prefix)),dimension_type(std::move(x.dimension_type)),dimension_position(std::move(x.dimension_position))
	{
		std::strncpy(symbol, std::move(x.symbol), 3);
	}
#elif IS_WINDOWS
	dimension::dimension(const dimension& x) : prefix(x.prefix),dimension_type(x.dimension_type),dimension_position(x.dimension_position)
	{
		strncpy_s(symbol, x.symbol, 3);
	}

	dimension::dimension(dimension&& x) : prefix(std::move(x.prefix)),dimension_type(std::move(x.dimension_type)),dimension_position(std::move(x.dimension_position))
	{
		strncpy_s(symbol, std::move(x.symbol), 3);
	}
#endif

	dimension::dimension(dimension::type new_dimension_type,scifir::prefix::type new_prefix,dimension::position new_position) : prefix(new_prefix),dimension_type(new_dimension_type),dimension_position(new_position),symbol()
	{}

	dimension::dimension(dimension::type new_dimension_type,const scifir::prefix& new_prefix,dimension::position new_position) : prefix(new_prefix),dimension_type(new_dimension_type),dimension_position(new_position),symbol()
	{}

	dimension::dimension(const string& init_dimension,dimension::position new_position) : prefix(),dimension_type(dimension::NONE),dimension_position(new_position),symbol()
	{
		string dimension_name;
		if (init_dimension.length() > 1 and std::find(dimension::prefixes_options.begin(),dimension::prefixes_options.end(),init_dimension.substr(0,1)) != dimension::prefixes_options.end() and init_dimension.compare("deg") != 0 and init_dimension.compare("rad") != 0 and init_dimension.compare("sr") != 0 and init_dimension.compare("m") != 0 and init_dimension.compare("Hz") != 0 and init_dimension.compare("Pa") != 0 and (init_dimension.length() < 2 or init_dimension.substr(0,2) != "da") and init_dimension.compare("°C") != 0 and (init_dimension.length() < 3 or init_dimension.substr(0,3) != "mol") and init_dimension.compare("cd") != 0 and init_dimension.compare("Ω") != 0 and init_dimension.compare("ohm") != 0 and init_dimension.compare("T") != 0 and init_dimension.compare("Gy") != 0 and init_dimension.compare("kat") != 0 and init_dimension.compare("Å") != 0 and init_dimension.compare("min") != 0 and init_dimension.compare("hour") != 0 and init_dimension.compare("day") != 0 and init_dimension.compare("pc") != 0 and init_dimension.compare("amu") != 0 and init_dimension.compare("M") != 0 and init_dimension.compare("particles") != 0 and init_dimension.compare("money") != 0 and init_dimension.compare("px") != 0 and init_dimension.compare("memo") != 0 and init_dimension.compare("mEq") != 0 and init_dimension.compare("dB") != 0)
		{
			prefix = scifir::prefix(init_dimension.substr(0,1));
			dimension_name = init_dimension.substr(1);
		}
		else if (init_dimension.length() >= 2 and init_dimension.substr(0,2).compare("µ") == 0)
		{
			prefix = scifir::prefix(prefix::MICRO);
			dimension_name = init_dimension.substr(2);
		}
		else if (init_dimension == "day")
		{
			prefix = scifir::prefix();
			dimension_name = init_dimension;
		}
		else if (init_dimension.length() >= 2 and init_dimension.substr(0,2) == "da")
		{
			prefix = scifir::prefix(prefix::DECA);
			dimension_name = init_dimension.substr(2);
		}
		else
		{
			prefix = scifir::prefix();
			dimension_name = init_dimension;
		}
		if (dimension_name == "m")
		{
			dimension_type = dimension::METRE;
		}
		else if (dimension_name == "deg" or dimension_name.compare("θ") == 0)
		{
			dimension_type = dimension::DEGREE;
		}
		else if (dimension_name == "rad")
		{
			dimension_type = dimension::RADIAN;
		}
		else if (dimension_name == "sr")
		{
			dimension_type = dimension::STERADIAN;
		}
		else if (dimension_name == "s")
		{
			dimension_type = dimension::SECOND;
		}
		else if (dimension_name == "g")
		{
			dimension_type = dimension::GRAM;
		}
		else if (dimension_name == "C")
		{
			dimension_type = dimension::COULOMB;
		}
		else if (dimension_name == "K")
		{
			dimension_type = dimension::KELVIN;
		}
		else if (dimension_name.compare("°C") == 0)
		{
			dimension_type = dimension::CELSIUS;
		}
		else if (dimension_name == "mol")
		{
			dimension_type = dimension::MOLE;
		}
		else if (dimension_name == "cd")
		{
			dimension_type = dimension::CANDELA;
		}
		else if (dimension_name == "B")
		{
			dimension_type = dimension::BYTE;
		}
		else if (dimension_name == "bit")
		{
			dimension_type = dimension::BIT;
		}
		else if (dimension_name == "Hz")
		{
			dimension_type = dimension::HERTZ;
		}
		else if (dimension_name == "N")
		{
			dimension_type = dimension::NEWTON;
		}
		else if (dimension_name == "Pa")
		{
			dimension_type = dimension::DIMENSION_PASCAL;
		}
		else if (dimension_name == "J")
		{
			dimension_type = dimension::JOULE;
		}
		else if (dimension_name == "W")
		{
			dimension_type = dimension::WATT;
		}
		else if (dimension_name == "A")
		{
			dimension_type = dimension::AMPERE;
		}
		else if (dimension_name == "V")
		{
			dimension_type = dimension::VOLT;
		}
		else if (dimension_name == "F")
		{
			dimension_type = dimension::FARAD;
		}
		else if (dimension_name == "ohm" or dimension_name.compare("Ω") == 0)
		{
			dimension_type = dimension::OHM;
		}
		else if (dimension_name == "S")
		{
			dimension_type = dimension::SIEMENS;
		}
		else if (dimension_name == "Wb")
		{
			dimension_type = dimension::WEBER;
		}
		else if (dimension_name == "T")
		{
			dimension_type = dimension::TESLA;
		}
		else if (dimension_name == "H")
		{
			dimension_type = dimension::HENRY;
		}
		else if (dimension_name == "lm")
		{
			dimension_type = dimension::LUMEN;
		}
		else if (dimension_name == "lx")
		{
			dimension_type = dimension::LUX;
		}
		else if (dimension_name == "Bq")
		{
			dimension_type = dimension::BECQUEREL;
		}
		else if (dimension_name == "Gy")
		{
			dimension_type = dimension::GRAY;
		}
		else if (dimension_name == "Sv")
		{
			dimension_type = dimension::SIEVERT;
		}
		else if (dimension_name == "kat")
		{
			dimension_type = dimension::KATAL;
		}
		else if (dimension_name.compare("Å") == 0)
		{
			dimension_type = dimension::ANGSTROM;
		}
		else if (dimension_name == "L")
		{
			dimension_type = dimension::LITRE;
		}
		else if (dimension_name == "min")
		{
			dimension_type = dimension::MINUTE;
		}
		else if (dimension_name == "hour")
		{
			dimension_type = dimension::HOUR;
		}
		else if (dimension_name == "day")
		{
			dimension_type = dimension::DAY;
		}
		else if (dimension_name == "ly")
		{
			dimension_type = dimension::LIGHT_YEAR;
		}
		else if (dimension_name == "AU")
		{
			dimension_type = dimension::ASTRONOMICAL_UNIT;
		}
		else if (dimension_name == "pc")
		{
			dimension_type = dimension::PARSEC;
		}
		else if (dimension_name == "eV")
		{
			dimension_type = dimension::ELECTRON_VOLT;
		}
		else if (dimension_name == "Da")
		{
			dimension_type = dimension::DALTON;
		}
		else if (dimension_name == "amu")
		{
			dimension_type = dimension::ATOMIC_MASS_UNIT;
		}
		else if (dimension_name == "barn")
		{
			dimension_type = dimension::BARN;
		}
		else if (dimension_name == "M")
		{
			dimension_type = dimension::MOLARITY;
		}
		else if (dimension_name == "particles")
		{
			dimension_type = dimension::PARTICLES;
		}
		else if (dimension_name == "money")
		{
			dimension_type = dimension::MONEY;
		}
		else if (dimension_name == "px")
		{
			dimension_type = dimension::PIXEL;
		}
		else if (dimension_name == "memo")
		{
			dimension_type = dimension::MEMO;
		}
		else if (dimension_name == "IU")
		{
			dimension_type = dimension::INTERNATIONAL_UNIT;
		}
		else if (dimension_name == "mEq")
		{
			dimension_type = dimension::MILLIEQUIVALENT;
		}
		else if (dimension_name == "dB")
		{
			dimension_type = dimension::DECIBEL;
		}
		else if (dimension_name == "")
		{
			dimension_type = dimension::NONE;
		}
		else
		{
			prefix = scifir::prefix(prefix::NONE);
			if (init_dimension.size() > 2)
			{
				string symbol_abreviation = dimension::create_full_symbol(init_dimension);
#ifdef IS_UNIX
				std::strncpy(symbol, symbol_abreviation.c_str(), 2);
#elif IS_WINDOWS
				strncpy_s(symbol, 3, symbol_abreviation.c_str(), 2);
#endif
				dimension_type = dimension::CUSTOM_FULL_SYMBOL;
			}
			else
			{
#ifdef IS_UNIX
				std::strncpy(symbol, init_dimension.c_str(), 2);
#elif IS_WINDOWS
				strncpy_s(symbol, 3, init_dimension.c_str(), 2);
#endif
				dimension_type = dimension::CUSTOM;
			}
		}
	}

#ifdef IS_UNIX
	dimension& dimension::operator =(const dimension& x)
	{
		prefix = x.prefix;
		dimension_type = x.dimension_type;
		dimension_position = x.dimension_position;
		std::strncpy(symbol,x.symbol,3);
		return *this;
	}
	
	dimension& dimension::operator =(dimension&& x)
	{
		prefix = std::move(x.prefix);
		dimension_type = std::move(x.dimension_type);
		dimension_position = std::move(x.dimension_position);
		std::strncpy(symbol,std::move(x.symbol),3);
		return *this;
	}
#elif IS_WINDOWS
	dimension& dimension::operator =(const dimension& x)
	{
		prefix = x.prefix;
		dimension_type = x.dimension_type;
		dimension_position = x.dimension_position;
		strncpy_s(symbol,x.symbol,3);
		return *this;
	}
	
	dimension& dimension::operator =(dimension&& x)
	{
		prefix = std::move(x.prefix);
		dimension_type = std::move(x.dimension_type);
		dimension_position = std::move(x.dimension_position);
		strncpy_s(symbol,std::move(x.symbol),3);
		return *this;
	}
#endif

	string dimension::get_name() const
	{
		switch(dimension_type)
		{
			case dimension::NONE:
				return "empty";
			case dimension::METRE:
				return "metre";
			case dimension::DEGREE:
				return "degree";
			case dimension::RADIAN:
				return "radian";
			case dimension::STERADIAN:
				return "steradian";
			case dimension::SECOND:
				return "second";
			case dimension::GRAM:
				return "gram";
			case dimension::COULOMB:
				return "coulomb";
			case dimension::KELVIN:
				return "kelvin";
			case dimension::CELSIUS:
				return "celsius";
			case dimension::MOLE:
				return "mole";
			case dimension::CANDELA:
				return "candela";
			case dimension::BYTE:
				return "byte";
			case dimension::BIT:
				return "bit";
			case dimension::HERTZ:
				return "hertz";
			case dimension::NEWTON:
				return "newton";
			case dimension::DIMENSION_PASCAL:
				return "pascal";
			case dimension::JOULE:
				return "joule";
			case dimension::WATT:
				return "watt";
			case dimension::AMPERE:
				return "ampere";
			case dimension::VOLT:
				return "volt";
			case dimension::FARAD:
				return "farad";
			case dimension::OHM:
				return "ohm";
			case dimension::SIEMENS:
				return "siemens";
			case dimension::WEBER:
				return "weber";
			case dimension::TESLA:
				return "tesla";
			case dimension::HENRY:
				return "henry";
			case dimension::LUMEN:
				return "lumen";
			case dimension::LUX:
				return "lux";
			case dimension::BECQUEREL:
				return "becquerel";
			case dimension::GRAY:
				return "gray";
			case dimension::SIEVERT:
				return "sievert";
			case dimension::KATAL:
				return "katal";
			case dimension::ANGSTROM:
				return "angstrom";
			case dimension::LITRE:
				return "litre";
			case dimension::MINUTE:
				return "minute";
			case dimension::HOUR:
				return "hour";
			case dimension::DAY:
				return "day";
			case dimension::LIGHT_YEAR:
				return "light year";
			case dimension::ASTRONOMICAL_UNIT:
				return "astronomical unit";
			case dimension::PARSEC:
				return "parsec";
			case dimension::ELECTRON_VOLT:
				return "electron volt";
			case dimension::DALTON:
				return "dalton";
			case dimension::ATOMIC_MASS_UNIT:
				return "atomic mass unit";
			case dimension::BARN:
				return "barn";
			case dimension::MOLARITY:
				return "molarity";
			case dimension::PARTICLES:
				return "particles";
			case dimension::CUSTOM:
				return "custom-dimension";
			case dimension::CUSTOM_BASIC:
				return "custom-basic";
			case dimension::CUSTOM_FULL_SYMBOL:
				return "custom-full-symbol";
			case dimension::MONEY:
				return "money";
			case dimension::PIXEL:
				return "pixel";
			case dimension::MEMO:
				return "memo";
			case dimension::INTERNATIONAL_UNIT:
				return "international-unit";
			case dimension::MILLIEQUIVALENT:
				return "milliequivalent";
				case dimension::DECIBEL:
				return "decibel";
		}
		return "";
	}

	string dimension::get_fullname() const
	{
		return prefix.get_name() + get_name();
	}

	string dimension::get_plural() const
	{
		switch(dimension_type)
		{
			case dimension::NONE:
				return "empty";
			case dimension::METRE:
				return "metres";
			case dimension::DEGREE:
				return "degrees";
			case dimension::RADIAN:
				return "radians";
			case dimension::STERADIAN:
				return "steradians";
			case dimension::SECOND:
				return "seconds";
			case dimension::GRAM:
				return "grams";
			case dimension::COULOMB:
				return "coulombs";
			case dimension::KELVIN:
				return "kelvins";
			case dimension::CELSIUS:
				return "celsius";
			case dimension::MOLE:
				return "moles";
			case dimension::CANDELA:
				return "candelas";
			case dimension::BYTE:
				return "bytes";
			case dimension::BIT:
				return "bits";
			case dimension::HERTZ:
				return "hertz";
			case dimension::NEWTON:
				return "newtons";
			case dimension::DIMENSION_PASCAL:
				return "pascals";
			case dimension::JOULE:
				return "joules";
			case dimension::WATT:
				return "watts";
			case dimension::AMPERE:
				return "amperes";
			case dimension::VOLT:
				return "volts";
			case dimension::FARAD:
				return "farads";
			case dimension::OHM:
				return "ohms";
			case dimension::SIEMENS:
				return "siemens";
			case dimension::WEBER:
				return "webers";
			case dimension::TESLA:
				return "teslas";
			case dimension::HENRY:
				return "henries";
			case dimension::LUMEN:
				return "lumens";
			case dimension::LUX:
				return "luxes";
			case dimension::BECQUEREL:
				return "becquerels";
			case dimension::GRAY:
				return "grays";
			case dimension::SIEVERT:
				return "sieverts";
			case dimension::KATAL:
				return "katals";
			case dimension::ANGSTROM:
				return "angstroms";
			case dimension::LITRE:
				return "litres";
			case dimension::MINUTE:
				return "minutes";
			case dimension::HOUR:
				return "hours";
			case dimension::DAY:
				return "days";
			case dimension::LIGHT_YEAR:
				return "light years";
			case dimension::ASTRONOMICAL_UNIT:
				return "astronomical units";
			case dimension::PARSEC:
				return "parsecs";
			case dimension::ELECTRON_VOLT:
				return "electron volts";
			case dimension::DALTON:
				return "daltons";
			case dimension::ATOMIC_MASS_UNIT:
				return "atomic mass units";
			case dimension::BARN:
				return "barns";
			case dimension::MOLARITY:
				return "molarities";
			case dimension::PARTICLES:
				return "particles";
			case dimension::CUSTOM:
				return "custom-dimension";
			case dimension::CUSTOM_BASIC:
				return "custom-basic";
			case dimension::CUSTOM_FULL_SYMBOL:
				return "custom-full-symbol";
			case dimension::MONEY:
				return "money";
			case dimension::PIXEL:
				return "pixels";
			case dimension::MEMO:
				return "memos";
			case dimension::INTERNATIONAL_UNIT:
				return "international-units";
			case dimension::MILLIEQUIVALENT:
				return "milliequivalents";
			case dimension::DECIBEL:
				return "decibels";
		}
		return "";
	}

	string dimension::get_fullplural() const
	{
		return prefix.get_name() + get_plural();
	}

	string dimension::get_symbol() const
	{
		switch(dimension_type)
		{
			case dimension::NONE:
				return "empty";
			case dimension::METRE:
				return "m";
#ifdef IS_UNIX
			case dimension::DEGREE:
				return "θ";
#elif IS_WINDOWS
			case dimension::DEGREE:
				return "θ";
#endif
			case dimension::RADIAN:
				return "rad";
			case dimension::STERADIAN:
				return "sr";
			case dimension::SECOND:
				return "s";
			case dimension::GRAM:
				return "g";
			case dimension::COULOMB:
				return "C";
			case dimension::KELVIN:
				return "K";
			case dimension::CELSIUS:
				return "°C";
			case dimension::MOLE:
				return "mol";
			case dimension::CANDELA:
				return "cd";
			case dimension::BYTE:
				return "B";
			case dimension::BIT:
				return "bit";
			case dimension::HERTZ:
				return "Hz";
			case dimension::NEWTON:
				return "N";
			case dimension::DIMENSION_PASCAL:
				return "Pa";
			case dimension::JOULE:
				return "J";
			case dimension::WATT:
				return "W";
			case dimension::AMPERE:
				return "A";
			case dimension::VOLT:
				return "V";
			case dimension::FARAD:
				return "F";
#ifdef IS_UNIX
			case dimension::OHM:
				return "Ω";
#elif IS_WINDOWS
			case dimension::OHM:
				return "Ω";
#endif
			case dimension::SIEMENS:
				return "S";
			case dimension::WEBER:
				return "Wb";
			case dimension::TESLA:
				return "T";
			case dimension::HENRY:
				return "H";
			case dimension::LUMEN:
				return "lm";
			case dimension::LUX:
				return "lx";
			case dimension::BECQUEREL:
				return "Bq";
			case dimension::GRAY:
				return "Gy";
			case dimension::SIEVERT:
				return "Sv";
			case dimension::KATAL:
				return "kat";
#ifdef IS_UNIX
			case dimension::ANGSTROM:
				return "Å";
#elif IS_WINDOWS
			case dimension::ANGSTROM:
				return "Å";
#endif
			case dimension::LITRE:
				return "L";
			case dimension::MINUTE:
				return "min";
			case dimension::HOUR:
				return "hour";
			case dimension::DAY:
				return "day";
			case dimension::LIGHT_YEAR:
				return "ly";
			case dimension::ASTRONOMICAL_UNIT:
				return "AU";
			case dimension::PARSEC:
				return "pc";
			case dimension::ELECTRON_VOLT:
				return "eV";
			case dimension::DALTON:
				return "Da";
			case dimension::ATOMIC_MASS_UNIT:
				return "amu";
			case dimension::BARN:
				return "barn";
			case dimension::MOLARITY:
				return "M";
			case dimension::PARTICLES:
				return "particles";
			case dimension::CUSTOM:
				return string("").assign(symbol, symbol + 3);
			case dimension::CUSTOM_BASIC:
				return "custom-basic";
			case dimension::CUSTOM_FULL_SYMBOL:
				return dimension::get_full_symbol(symbol);
			case dimension::MONEY:
				return "money";
			case dimension::PIXEL:
				return "px";
			case dimension::MEMO:
				return "memo";
			case dimension::INTERNATIONAL_UNIT:
				return "IU";
			case dimension::MILLIEQUIVALENT:
				return "mEq";
				case dimension::DECIBEL:
				return "dB";
		}
		return "";
	}

	long double dimension::get_conversion_factor() const
	{
		switch(dimension_type)
		{
			case dimension::NONE:
				return 1.0l;
			case dimension::METRE:
				return 1.0l;
			case dimension::DEGREE:
				return std::numbers::pi_v<float> / 180.0l;
			case dimension::RADIAN:
				return 1.0l;
			case dimension::STERADIAN:
				return 1.0l;
			case dimension::GRAM:
				return 1.0l;
			case dimension::SECOND:
				return 1.0l;
			case dimension::COULOMB:
				return 1.0l;
			case dimension::KELVIN:
				return 1.0l;
			case dimension::CELSIUS:
				return 1.0l;
			case dimension::MOLE:
				return 1.0l;
			case dimension::CANDELA:
				return 1.0l;
			case dimension::BYTE:
				return 1.0l;
			case dimension::BIT:
				return 0.125l;
			case dimension::HERTZ:
				return 1.0l;
			case dimension::NEWTON:
				return 1.0l;
			case dimension::DIMENSION_PASCAL:
				return 1.0l;
			case dimension::JOULE:
				return 1.0l;
			case dimension::WATT:
				return 1.0l;
			case dimension::AMPERE:
				return 1.0l;
			case dimension::VOLT:
				return 1.0l;
			case dimension::FARAD:
				return 1;
			case dimension::OHM:
				return 1.0l;
			case dimension::SIEMENS:
				return 1.0l;
			case dimension::WEBER:
				return 1.0l;
			case dimension::TESLA:
				return 1.0l;
			case dimension::HENRY:
				return 1.0l;
			case dimension::LUMEN:
				return 1.0l;
			case dimension::LUX:
				return 1.0l;
			case dimension::BECQUEREL:
				return 1.0l;
			case dimension::GRAY:
				return 1.0l;
			case dimension::SIEVERT:
				return 1.0l;
			case dimension::KATAL:
				return 1.0l;
			case dimension::ANGSTROM:
				return 1.0l;
			case dimension::LITRE:
				return 1.0l;
			case dimension::MINUTE:
				return 60l;
			case dimension::HOUR:
				return 3600l;
			case dimension::DAY:
				return 86400l;
			case dimension::LIGHT_YEAR:
				return 9.4607379375591e15;
			case dimension::ASTRONOMICAL_UNIT:
				return 149597870700.0l;
			case dimension::PARSEC:
				return 30856775814913673.0l;
			case dimension::ELECTRON_VOLT:
				return 0.0000000000000000001602176634l;
			case dimension::DALTON:
				return 0.00000000000000000000000000166053886l;
			case dimension::ATOMIC_MASS_UNIT:
				return 0.00000000000000000000000000166053886l;
			case dimension::BARN:
				return 0.0000000000000000000000000001l;
			case dimension::MOLARITY:
				return 1.0l;
			case dimension::PARTICLES:
				return 1.0l/AVOGADRO_CONSTANT;
			case dimension::CUSTOM:
				return 1.0l;
			case dimension::CUSTOM_BASIC:
				return 1.0l;
			case dimension::CUSTOM_FULL_SYMBOL:
				return 1.0l;
			case dimension::MONEY:
				return 1.0l;
			case dimension::PIXEL:
				return 1.0l;
			case dimension::MEMO:
				return 1.0l;
			case dimension::INTERNATIONAL_UNIT:
				return 1.0l;
			case dimension::MILLIEQUIVALENT:
				return 1.0l;
			case dimension::DECIBEL:
				return 1.0l;
		}
		return 1.0l;
	}

	long double dimension::prefix_math() const
	{
		return prefix_math(prefix);
	}

	long double dimension::prefix_math(const scifir::prefix& x_prefix) const
	{
		if (dimension_type == dimension::BYTE or dimension_type == dimension::BIT)
		{
			return std::pow(1024, x_prefix.get_conversion_factor() / 3);
		}
		else
		{
			return std::pow(10, x_prefix.get_conversion_factor());
		}
	}

	bool dimension::is_simple_dimension() const
	{
		switch(dimension_type)
		{
			case dimension::NONE:
				return false;
			case dimension::METRE:
				return true;
			case dimension::DEGREE:
				return true;
			case dimension::RADIAN:
				return true;
			case dimension::STERADIAN:
				return true;
			case dimension::GRAM:
				return true;
			case dimension::SECOND:
				return true;
			case dimension::COULOMB:
				return true;
			case dimension::KELVIN:
				return true;
			case dimension::CELSIUS:
				return true;
			case dimension::MOLE:
				return true;
			case dimension::CANDELA:
				return true;
			case dimension::BYTE:
				return true;
			case dimension::BIT:
				return true;
			case dimension::HERTZ:
				return true;
			case dimension::NEWTON:
				return false;
			case dimension::DIMENSION_PASCAL:
				return false;
			case dimension::JOULE:
				return false;
			case dimension::WATT:
				return false;
			case dimension::AMPERE:
				return true;
			case dimension::VOLT:
				return false;
			case dimension::FARAD:
				return false;
			case dimension::OHM:
				return false;
			case dimension::SIEMENS:
				return false;
			case dimension::WEBER:
				return false;
			case dimension::TESLA:
				return false;
			case dimension::HENRY:
				return false;
			case dimension::LUMEN:
				return false;
			case dimension::LUX:
				return false;
			case dimension::BECQUEREL:
				return true;
			case dimension::GRAY:
				return false;
			case dimension::SIEVERT:
				return false;
			case dimension::KATAL:
				return false;
			case dimension::ANGSTROM:
				return true;
			case dimension::LITRE:
				return false;
			case dimension::MINUTE:
				return true;
			case dimension::HOUR:
				return true;
			case dimension::DAY:
				return true;
			case dimension::LIGHT_YEAR:
				return true;
			case dimension::ASTRONOMICAL_UNIT:
				return true;
			case dimension::PARSEC:
				return true;
			case dimension::ELECTRON_VOLT:
				return false;
			case dimension::DALTON:
				return true;
			case dimension::ATOMIC_MASS_UNIT:
				return true;
			case dimension::BARN:
				return false;
			case dimension::MOLARITY:
				return false;
			case dimension::PARTICLES:
				return true;
			case dimension::CUSTOM:
				return false;
			case dimension::CUSTOM_BASIC:
				return true;
			case dimension::CUSTOM_FULL_SYMBOL:
				return false;
			case dimension::MONEY:
				return true;
			case dimension::PIXEL:
				return true;
			case dimension::MEMO:
				return true;
			case dimension::INTERNATIONAL_UNIT:
				return true;
			case dimension::MILLIEQUIVALENT:
				return true;
			case dimension::DECIBEL:
				return true;
		}
		return false;
	}

	bool dimension::is_composite_dimension() const
	{
		if (dimension_type == dimension::NONE)
		{
			return false;
		}
		else
		{
			return !is_simple_dimension();
		}
	}

	bool dimension::is_base_dimension() const
	{
		switch(dimension_type)
		{
			case dimension::NONE:
				return false;
			case dimension::METRE:
				return true;
			case dimension::DEGREE:
				return false;
			case dimension::RADIAN:
				return true;
			case dimension::STERADIAN:
				return true;
			case dimension::GRAM:
				return true;
			case dimension::SECOND:
				return true;
			case dimension::COULOMB:
				return true;
			case dimension::KELVIN:
				return true;
			case dimension::CELSIUS:
				return false;
			case dimension::MOLE:
				return true;
			case dimension::CANDELA:
				return true;
			case dimension::BYTE:
				return true;
			case dimension::BIT:
				return false;
			case dimension::HERTZ:
				return false;
			case dimension::NEWTON:
				return false;
			case dimension::DIMENSION_PASCAL:
				return false;
			case dimension::JOULE:
				return false;
			case dimension::WATT:
				return false;
			case dimension::AMPERE:
				return false;
			case dimension::VOLT:
				return false;
			case dimension::FARAD:
				return false;
			case dimension::OHM:
				return false;
			case dimension::SIEMENS:
				return false;
			case dimension::WEBER:
				return false;
			case dimension::TESLA:
				return false;
			case dimension::HENRY:
				return false;
			case dimension::LUMEN:
				return false;
			case dimension::LUX:
				return false;
			case dimension::BECQUEREL:
				return false;
			case dimension::GRAY:
				return false;
			case dimension::SIEVERT:
				return false;
			case dimension::KATAL:
				return false;
			case dimension::ANGSTROM:
				return false;
			case dimension::LITRE:
				return false;
			case dimension::MINUTE:
				return false;
			case dimension::HOUR:
				return false;
			case dimension::DAY:
				return false;
			case dimension::LIGHT_YEAR:
				return false;
			case dimension::ASTRONOMICAL_UNIT:
				return false;
			case dimension::PARSEC:
				return false;
			case dimension::ELECTRON_VOLT:
				return false;
			case dimension::DALTON:
				return false;
			case dimension::ATOMIC_MASS_UNIT:
				return false;
			case dimension::BARN:
				return false;
			case dimension::MOLARITY:
				return false;
			case dimension::PARTICLES:
				return false;
			case dimension::CUSTOM:
				return false;
			case dimension::CUSTOM_BASIC:
				return true;
			case dimension::CUSTOM_FULL_SYMBOL:
				return false;
			case dimension::MONEY:
				return true;
			case dimension::PIXEL:
				return true;
			case dimension::MEMO:
				return true;
			case dimension::INTERNATIONAL_UNIT:
				return true;
			case dimension::MILLIEQUIVALENT:
				return true;
			case dimension::DECIBEL:
				return true;
		}
		return false;
	}

	bool dimension::is_derived_dimension() const
	{
		if (dimension_type == dimension::NONE)
		{
			return false;
		}
		else
		{
			return !is_base_dimension();
		}
	}

	bool dimension::is_SI_base_dimension() const
	{
		switch(dimension_type)
		{
			case dimension::NONE:
				return false;
			case dimension::METRE:
				return true;
			case dimension::DEGREE:
				return false;
			case dimension::RADIAN:
				return false;
			case dimension::STERADIAN:
				return false;
			case dimension::GRAM:
				return true;
			case dimension::SECOND:
				return true;
			case dimension::COULOMB:
				return false;
			case dimension::KELVIN:
				return true;
			case dimension::CELSIUS:
				return false;
			case dimension::MOLE:
				return true;
			case dimension::CANDELA:
				return true;
			case dimension::BYTE:
				return false;
			case dimension::BIT:
				return false;
			case dimension::HERTZ:
				return false;
			case dimension::NEWTON:
				return false;
			case dimension::DIMENSION_PASCAL:
				return false;
			case dimension::JOULE:
				return false;
			case dimension::WATT:
				return false;
			case dimension::AMPERE:
				return true;
			case dimension::VOLT:
				return false;
			case dimension::FARAD:
				return false;
			case dimension::OHM:
				return false;
			case dimension::SIEMENS:
				return false;
			case dimension::WEBER:
				return false;
			case dimension::TESLA:
				return false;
			case dimension::HENRY:
				return false;
			case dimension::LUMEN:
				return false;
			case dimension::LUX:
				return false;
			case dimension::BECQUEREL:
				return false;
			case dimension::GRAY:
				return false;
			case dimension::SIEVERT:
				return false;
			case dimension::KATAL:
				return false;
			case dimension::ANGSTROM:
				return false;
			case dimension::LITRE:
				return false;
			case dimension::MINUTE:
				return false;
			case dimension::HOUR:
				return false;
			case dimension::DAY:
				return false;
			case dimension::LIGHT_YEAR:
				return false;
			case dimension::ASTRONOMICAL_UNIT:
				return false;
			case dimension::PARSEC:
				return false;
			case dimension::ELECTRON_VOLT:
				return false;
			case dimension::DALTON:
				return false;
			case dimension::ATOMIC_MASS_UNIT:
				return false;
			case dimension::BARN:
				return false;
			case dimension::MOLARITY:
				return false;
			case dimension::PARTICLES:
				return false;
			case dimension::CUSTOM:
				return false;
			case dimension::CUSTOM_BASIC:
				return false;
			case dimension::CUSTOM_FULL_SYMBOL:
				return false;
			case dimension::MONEY:
				return false;
			case dimension::PIXEL:
				return false;
			case dimension::MEMO:
				return false;
			case dimension::INTERNATIONAL_UNIT:
				return false;
			case dimension::MILLIEQUIVALENT:
				return false;
			case dimension::DECIBEL:
				return false;
		}
		return false;
	}

	bool dimension::is_SI_derived_dimension() const
	{
		switch(dimension_type)
		{
			case dimension::NONE:
				return false;
			case dimension::METRE:
				return false;
			case dimension::DEGREE:
				return true;
			case dimension::RADIAN:
				return true;
			case dimension::STERADIAN:
				return true;
			case dimension::GRAM:
				return false;
			case dimension::SECOND:
				return false;
			case dimension::COULOMB:
				return true;
			case dimension::KELVIN:
				return false;
			case dimension::CELSIUS:
				return true;
			case dimension::MOLE:
				return false;
			case dimension::CANDELA:
				return false;
			case dimension::BYTE:
				return false;
			case dimension::BIT:
				return false;
			case dimension::HERTZ:
				return true;
			case dimension::NEWTON:
				return true;
			case dimension::DIMENSION_PASCAL:
				return true;
			case dimension::JOULE:
				return true;
			case dimension::WATT:
				return true;
			case dimension::AMPERE:
				return false;
			case dimension::VOLT:
				return true;
			case dimension::FARAD:
				return true;
			case dimension::OHM:
				return true;
			case dimension::SIEMENS:
				return true;
			case dimension::WEBER:
				return true;
			case dimension::TESLA:
				return true;
			case dimension::HENRY:
				return true;
			case dimension::LUMEN:
				return true;
			case dimension::LUX:
				return true;
			case dimension::BECQUEREL:
				return true;
			case dimension::GRAY:
				return true;
			case dimension::SIEVERT:
				return true;
			case dimension::KATAL:
				return true;
			case dimension::ANGSTROM:
				return false;
			case dimension::LITRE:
				return false;
			case dimension::MINUTE:
				return false;
			case dimension::HOUR:
				return false;
			case dimension::DAY:
				return false;
			case dimension::LIGHT_YEAR:
				return false;
			case dimension::ASTRONOMICAL_UNIT:
				return false;
			case dimension::PARSEC:
				return false;
			case dimension::ELECTRON_VOLT:
				return false;
			case dimension::DALTON:
				return false;
			case dimension::ATOMIC_MASS_UNIT:
				return false;
			case dimension::BARN:
				return false;
			case dimension::MOLARITY:
				return false;
			case dimension::PARTICLES:
				return false;
			case dimension::CUSTOM:
				return false;
			case dimension::CUSTOM_BASIC:
				return false;
			case dimension::CUSTOM_FULL_SYMBOL:
				return false;
			case dimension::MONEY:
				return false;
			case dimension::PIXEL:
				return false;
			case dimension::MEMO:
				return false;
			case dimension::INTERNATIONAL_UNIT:
				return false;
			case dimension::MILLIEQUIVALENT:
				return false;
			case dimension::DECIBEL:
				return false;
		}
		return false;
	}

	bool dimension::is_dimensionless() const
	{
		if (dimension_type == dimension::DEGREE or dimension_type == dimension::RADIAN or dimension_type == dimension::STERADIAN)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	vector<dimension> dimension::get_base_dimensions() const
	{
		vector<dimension> basic_dimensions = vector<dimension>();
		switch (dimension_type)
		{
			case dimension::NONE:
				basic_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::METRE:
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::DEGREE:
				basic_dimensions.push_back(dimension(dimension::RADIAN,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::RADIAN:
				basic_dimensions.push_back(dimension(dimension::RADIAN,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::STERADIAN:
				basic_dimensions.push_back(dimension(dimension::STERADIAN,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::SECOND:
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::GRAM:
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::COULOMB:
				basic_dimensions.push_back(dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::KELVIN:
				basic_dimensions.push_back(dimension(dimension::KELVIN,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::CELSIUS:
				basic_dimensions.push_back(dimension(dimension::KELVIN,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::MOLE:
				basic_dimensions.push_back(dimension(dimension::MOLE,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::CANDELA:
				basic_dimensions.push_back(dimension(dimension::CANDELA,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::BYTE:
				basic_dimensions.push_back(dimension(dimension::BYTE,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::BIT:
				basic_dimensions.push_back(dimension(dimension::BYTE,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::HERTZ:
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::NEWTON:
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::DIMENSION_PASCAL:
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::JOULE:
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::WATT:
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::AMPERE:
				basic_dimensions.push_back(dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::VOLT:
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::FARAD:
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::KILO,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::OHM:
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::SIEMENS:
				basic_dimensions.push_back(dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::KILO,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::WEBER:
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::TESLA:
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::HENRY:
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::LUMEN:
				basic_dimensions.push_back(dimension(dimension::CANDELA,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::STERADIAN,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::LUX:
				basic_dimensions.push_back(dimension(dimension::CANDELA,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::STERADIAN,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::BECQUEREL:
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::GRAY:
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::SIEVERT:
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::KATAL:
				basic_dimensions.push_back(dimension(dimension::MOLE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::ANGSTROM:
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::LITRE:
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::MINUTE:
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::HOUR:
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::DAY:
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::LIGHT_YEAR:
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::ASTRONOMICAL_UNIT:
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::PARSEC:
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::ELECTRON_VOLT:
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::DALTON:
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR));
				break;
			case dimension::ATOMIC_MASS_UNIT:
				basic_dimensions.push_back(dimension(dimension::GRAM,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::BARN:
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::MOLARITY:
				basic_dimensions.push_back(dimension(dimension::MOLE,prefix::NONE,dimension::NUMERATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR));
				basic_dimensions.push_back(dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR));
				break;
			case dimension::PARTICLES:
				basic_dimensions.push_back(dimension(dimension::MOLE,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::CUSTOM:
			{
				//return dimension::base_dimensions[symbol];
				break;
			}
			case dimension::CUSTOM_BASIC:
			{
				basic_dimensions.push_back(*this);
				break;
			}
			case dimension::CUSTOM_FULL_SYMBOL:
			{
				break;
				//return dimension::base_dimensions[dimension::get_full_symbol(symbol)];
			}
			case dimension::MONEY:
				basic_dimensions.push_back(dimension(dimension::MONEY,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::PIXEL:
				basic_dimensions.push_back(dimension(dimension::PIXEL,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::MEMO:
				basic_dimensions.push_back(dimension(dimension::MEMO,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::INTERNATIONAL_UNIT:
				basic_dimensions.push_back(dimension(dimension::INTERNATIONAL_UNIT,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::MILLIEQUIVALENT:
				basic_dimensions.push_back(dimension(dimension::MILLIEQUIVALENT,prefix::NONE,dimension::NUMERATOR));
				break;
			case dimension::DECIBEL:
				basic_dimensions.push_back(dimension(dimension::DECIBEL,prefix::NONE,dimension::NUMERATOR));
				break;
		}
		return basic_dimensions;
	}

	void dimension::invert()
	{
		if (dimension_position == dimension::NUMERATOR)
		{
			dimension_position = dimension::DENOMINATOR;
		}
		else
		{
			dimension_position = dimension::NUMERATOR;
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
			bool first_print = true;
			for (const dimension& x_dimension : x_dimensions)
			{
				if (x_dimension.dimension_position == dimension::NUMERATOR)
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
						if (!first_print)
						{
							out << "*";
						}
						out << x_prefix.first << x_dimension.get_symbol();
						if (x_prefix.second > 1)
						{
							out << x_prefix.second;
						}
						first_print = false;
					}
					printed_dimensions.push_back(x_dimension.dimension_type);
				}
			}
			printed_dimensions.clear();
			bool first_negative_iteration = true;
			bool first_negative_prefix = true;
			for (const dimension& x_dimension : x_dimensions)
			{
				if (x_dimension.dimension_position == dimension::DENOMINATOR)
				{
					if (first_negative_iteration == true)
					{
						if (first_print)
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

	string to_latex(const vector<dimension>& x_dimensions,bool with_brackets)
	{
		ostringstream out;
		bool is_fraction = false;
		if (x_dimensions.size() > 0)
		{
			vector<dimension::type> printed_dimensions = vector<dimension::type>();
			map<prefix,int> counted_prefixes = map<prefix,int>();
			bool first_print = true;
			for (const dimension& x_dimension : x_dimensions)
			{
				if (x_dimension.dimension_position == dimension::NUMERATOR)
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
						if (!first_print)
						{
							out << "*";
						}
						out << x_prefix.first << x_dimension.get_symbol();
						if (x_prefix.second > 1)
						{
							out << "^" << x_prefix.second;
						}
						first_print = false;
					}
					printed_dimensions.push_back(x_dimension.dimension_type);
				}
			}
			printed_dimensions.clear();
			bool first_negative_iteration = true;
			bool first_negative_prefix = true;
			for (const dimension& x_dimension : x_dimensions)
			{
				if (x_dimension.dimension_position == dimension::DENOMINATOR)
				{
					is_fraction = true;
					if (first_negative_iteration == true)
					{
						if (first_print)
						{
							out << "1";
						}
						out << "}{";
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
							out << "^" << x_prefix.second;
						}
						first_negative_prefix = false;
					}
					printed_dimensions.push_back(x_dimension.dimension_type);
				}
			}
			if (is_fraction)
			{
				out << "}";
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
		if (is_fraction)
		{
			if (with_brackets)
			{
				return "[\frac{" + out.str();
			}
			else
			{
				return "\frac{" + out.str();
			}
		}
		else
		{
			if (with_brackets)
			{
				return "[" + out.str();
			}
			else
			{
				return out.str();
			}
		}
	}

	vector<dimension> create_dimensions(string init_dimensions)
	{
		if (init_dimensions.length() == 0)
		{
			return vector<dimension>();
		}
		boost::algorithm::erase_all(init_dimensions, " ");
		dimension::position new_sign = dimension::NUMERATOR;
		int new_scale = 1;
		int position = 0;
		string new_dimension_str;
		vector<dimension> dimensions = vector<dimension>();
		for (int i = 0; i < init_dimensions.length(); i++)
		{
			if (init_dimensions[i] == '1' and init_dimensions[i + 1] == '/')
			{
				new_sign = dimension::DENOMINATOR;
				i++;
				continue;
			}
			if (init_dimensions.substr(i,2).compare("µ") == 0 or init_dimensions.substr(i,2) == "da")
			{
				position = i + 1;
			}
			else
			{
				position = i;
			}
			if (init_dimensions[i] == '*')
			{
				continue;
			}
			else if (init_dimensions[i] == '/')
			{
				new_sign = dimension::DENOMINATOR;
				continue;
			}
			else if ((1 <= init_dimensions[i] and init_dimensions[i] <= 255 and std::isalpha(init_dimensions[i])) or ((i + 1) < init_dimensions.length() and (init_dimensions.substr(i,2).compare("µ") == 0 or init_dimensions.substr(i,2).compare("Ω") == 0 or init_dimensions.substr(i,2).compare("Å") or init_dimensions.substr(i,2).compare("θ") == 0 or (init_dimensions.substr(i,2).compare("°") == 0 and init_dimensions.substr(i + 2,1) == "C"))))
			{
				if ((position + 1) < init_dimensions.length() and init_dimensions[position + 1] != '*' and init_dimensions[position + 1] != '/')
				{
					for (int j = position + 1; j < init_dimensions.length(); j++)
					{
						if (j < init_dimensions.length() and 1 <= init_dimensions[j] and init_dimensions[j] <= 255 and std::isdigit(init_dimensions[j]))
						{
							new_dimension_str = init_dimensions.substr(i,j - i);
							for (int k = j; k < init_dimensions.length(); k++)
							{
								if ((1 <= init_dimensions[k + 1] and init_dimensions[k + 1] <= 255 and !std::isdigit(init_dimensions[k + 1])) or (k + 1) == init_dimensions.length())
								{
									new_scale = stoi(init_dimensions.substr(j,k - j + 1));
									break;
								}
							}
							break;
						}
						else if (init_dimensions.substr(j,2).compare("Ω") == 0 or init_dimensions.substr(j,2).compare("Å") == 0 or init_dimensions.substr(j,2).compare("θ") == 0)
						{
							new_dimension_str = init_dimensions.substr(i,j + 2 - i);
							if ((j + 2) < init_dimensions.length() and 1 <= init_dimensions[j + 2] and init_dimensions[j + 2] <= 255 and std::isdigit(init_dimensions[j + 2]))
							{
								for (int k = (j + 2); k < init_dimensions.length(); k++)
								{
									if ((k + 1) < init_dimensions.length() and 1 <= init_dimensions[k + 1] and init_dimensions[k + 1] <= 255 and !std::isdigit(init_dimensions[k + 1]))
									{
										new_scale = stoi(init_dimensions.substr(j + 2,k - j + 1));
										break;
									}
								}
							}
							else
							{
								new_scale = 1;
							}
							break;
						}
						else if (init_dimensions.substr(j,2).compare("°") == 0 and init_dimensions.substr(j + 2,1) == "C")
						{
							new_dimension_str = init_dimensions.substr(i,j + 3 - i);
							if ((j + 3) < init_dimensions.length() and 1 <= init_dimensions[j + 3] and init_dimensions[j + 3] <= 255 and std::isdigit(init_dimensions[j + 3]))
							{
								for (int k = (j + 3); k < init_dimensions.length(); k++)
								{
									if ((k + 1) < init_dimensions.length() and 1 <= init_dimensions[k + 1] and init_dimensions[k + 1] <= 255 and !std::isdigit(init_dimensions[k + 1]))
									{
										new_scale = stoi(init_dimensions.substr(j + 3,k - j + 1));
										break;
									}
								}
							}
							else
							{
								new_scale = 1;
							}
							break;
						}
						else if (j < init_dimensions.length() and 1 <= init_dimensions[j] and init_dimensions[j] <= 255 and std::isalpha(init_dimensions[j]))
						{
							if ((j + 1) == init_dimensions.length() or init_dimensions[j + 1] == '*' or init_dimensions[j + 1] == '/')
							{
								new_dimension_str = init_dimensions.substr(i,j - i + 1);
								new_scale = 1;
								break;
							}
							else
							{
								continue;
							}
						}
						else if ((j + 1) == init_dimensions.length() or init_dimensions[j] == '*' or init_dimensions[j] == '/')
						{
							new_dimension_str = init_dimensions.substr(i,j - i + 1);
							new_scale = 1;
							break;
						}
					}
				}
				else
				{
					if (position < init_dimensions.length() and 1 <= init_dimensions[position] and init_dimensions[position] <= 255 and std::isdigit(init_dimensions[position]))
					{
						new_dimension_str = init_dimensions.substr(i,position - i + 1);
						new_scale = stoi(init_dimensions.substr(position,1));
					}
					else if (init_dimensions.substr(position,2).compare("Ω") == 0 or init_dimensions.substr(position,2).compare("Å") == 0 or init_dimensions.substr(position,2).compare("θ") == 0)
					{
						new_dimension_str = init_dimensions.substr(position,2);
						new_scale = 1;
						for (int k = (position + 2); k < init_dimensions.length(); k++)
						{
							if ((1 <= init_dimensions[k + 1] and init_dimensions[k + 1] <= 255 and !std::isdigit(init_dimensions[k + 1])) or (k + 1) == init_dimensions.length())
							{
								new_scale = stoi(init_dimensions.substr(position + 2,k - position - 1));
								break;
							}
						}
						break;
					}
					else if (position < init_dimensions.length() and 1 <= init_dimensions[position] and init_dimensions[position] <= 255 and std::isalpha(init_dimensions[position]))
					{
						new_dimension_str = init_dimensions.substr(position,position - i + 1);
						new_scale = 1;
					}
					else
					{
						new_dimension_str = init_dimensions.substr(position,1);
						new_scale = 1;
					}
				}
			}
			if (!new_dimension_str.length() == 0)
			{
				dimension new_dimension;
				if (new_dimension_str.substr(0,2).compare("Ω") == 0)
				{
					new_dimension = dimension(dimension::OHM,prefix::NONE,new_sign);
				}
				else if (new_dimension_str.substr(0,2).compare("Å") == 0)
				{
					new_dimension = dimension(dimension::ANGSTROM,prefix::NONE,new_sign);
				}
				else if (new_dimension_str.substr(0,2).compare("θ") == 0)
				{
					new_dimension = dimension(dimension::DEGREE,prefix::NONE,new_sign);
				}
				else if (new_dimension_str.substr(0,2).compare("°") == 0 && new_dimension_str.substr(2) == "C")
				{
					prefix new_prefix(new_dimension_str.substr(0,new_dimension_str.length() - 3));
					new_dimension = dimension(dimension::CELSIUS,new_prefix,new_sign);
				}
				else
				{
					new_dimension = dimension(new_dimension_str,new_sign);
				}
				for (int j = 0; j < new_scale; j++)
				{
					dimensions.push_back(new_dimension);
				}
				i += int(new_dimension_str.length()) - 1;
				if (new_scale > 1)
				{
					i += int(std::to_string(new_scale).length());
				}
				new_dimension_str = "";
				new_scale = 1;
			}
		}
		return dimensions;
	}

	vector<dimension> create_base_dimensions(const string& init_dimensions)
	{
		vector<dimension> new_dimensions = create_dimensions(init_dimensions);
		return create_base_dimensions(new_dimensions);
	}

	vector<dimension> create_base_dimensions(const vector<dimension>& x)
	{
		vector<dimension> new_x = vector<dimension>();
		for (unsigned int i = 0; i < x.size(); i++)
		{
			vector<dimension> x_subdimensions = x[i].get_base_dimensions();
			for (dimension& x_subdimension : x_subdimensions)
			{
				if (x[i].dimension_position == dimension::DENOMINATOR)
				{
					x_subdimension.invert();
				}
				new_x.push_back(x_subdimension);
			}
		}
		return new_x;
	}

	vector<dimension> create_base_dimensions(const vector<dimension>& x,long double& value)
	{
		vector<dimension> new_x = vector<dimension>();
		for (unsigned int i = 0; i < x.size(); i++)
		{
			if (x[i].dimension_position == dimension::NUMERATOR)
			{
				value *= x[i].get_conversion_factor();
				value *= x[i].prefix_math();
			}
			else if (x[i].dimension_position == dimension::DENOMINATOR)
			{
				value /= x[i].get_conversion_factor();
				value /= x[i].prefix_math();
			}
			vector<dimension> x_subdimensions = x[i].get_base_dimensions();
			for (dimension& x_subdimension : x_subdimensions)
			{
				if (x[i].dimension_position == dimension::DENOMINATOR)
				{
					x_subdimension.invert();
				}
				new_x.push_back(x_subdimension);
			}
		}
		if (x.size() == 1 and x[0].dimension_type == dimension::CELSIUS and x[0].dimension_position == dimension::NUMERATOR)
		{
			value += 273.15l;
		}
		return new_x;
	}

	vector<dimension> multiply_dimensions(const vector<dimension>& x,const vector<dimension>& y)
	{
		vector<dimension> new_dimensions = x;
		for (const dimension& y_dimension : y)
		{
			new_dimensions.push_back(y_dimension);
		}
		return new_dimensions;
	}

	vector<dimension> multiply_dimensions(vector<dimension> x,const vector<dimension>& y,long double& value)
	{
		for (const dimension& y_dimension : y)
		{
			x.push_back(y_dimension);
		}
		return normalize_dimensions(x,value);
	}

	vector<dimension> divide_dimensions(vector<dimension> x,const vector<dimension>& y,long double& value)
	{
		for (dimension y_dimension : y)
		{
			y_dimension.invert();
			x.push_back(y_dimension);
		}
		return normalize_dimensions(x,value);
	}

	vector<dimension> square_dimensions(vector<dimension> x,int index,long double& value)
	{
		map<dimension::type,int> dimensions_count = map<dimension::type,int>();
		for (const dimension& x_dimension : x)
		{
			dimensions_count[x_dimension.dimension_type]++;
		}
		for (const auto& x_count : dimensions_count)
		{
			if ((x_count.second % index) != 0)
			{
				return vector<dimension>();
			}
		}
		vector<dimension> new_dimensions = vector<dimension>();
		if (dimensions_count.size() == 1) // If there's only one type of dimension, square it and conserve its type
		{
			for (int i = 0; i < dimensions_count[x[0].dimension_type]; i++)
			{
				if (x[i].dimension_position == dimension::NUMERATOR)
				{
					value *= x[i].get_conversion_factor();
					value *= x[i].prefix_math();
				}
				else if (x[i].dimension_position == dimension::DENOMINATOR)
				{
					value /= x[i].get_conversion_factor();
					value /= x[i].prefix_math();
				}
			}
			int total_dimensions = int(std::pow(dimensions_count[x[0].dimension_type], 1.0f / index));
			x[0].prefix.prefix_type = prefix::NONE;
			for (int j = 0; j < total_dimensions; j++)
			{
				new_dimensions.push_back(x[0]);
			}
			return new_dimensions;
		}
		else // If there's more than one type of dimension, creates the simple dimensions of them, and squares the total. If there are special names, they are changed by their simple dimensions
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
				int total_dimensions = int(std::pow(dimensions_count[x_dimension.dimension_type], 1.0f / index));
				for (int j = 0; j < total_dimensions; j++)
				{
					new_dimensions.push_back(x_dimension);
				}
				counted_dimensions.push_back(x_dimension.dimension_type);
			}
		}
		return new_dimensions;
	}

	vector<dimension> power_dimensions(const vector<dimension>& x,int exponent)
	{
		vector<dimension> new_dimensions = vector<dimension>();
		for (const dimension& x_dimension: x)
		{
			for (int j = 1; j <= exponent; j++)
			{
				new_dimensions.push_back(x_dimension);
			}
		}
		return new_dimensions;
	}

	vector<dimension> normalize_dimensions(const vector<dimension>& x)
	{
		vector<dimension> new_x = create_base_dimensions(x);
		if (new_x.size() == 1)
		{
			return x;
		}
		vector<unsigned int> skip_dimensions = vector<unsigned int>();
		for(unsigned int i = 0; i < new_x.size(); i++)
		{
			for(unsigned int j = i + 1; j < new_x.size(); j++)
			{
				if (skip_dimensions.size() > 0)
				{
					bool skip = false;
					for(unsigned int k = 0; k < skip_dimensions.size(); k++)
					{
						if (j == skip_dimensions[k])
						{
							skip = true;
							break;
						}
					}
					if (skip)
					{
						continue;
					}
				}
				if (new_x[i].dimension_type == new_x[j].dimension_type and new_x[i].dimension_position != new_x[j].dimension_position)
				{
					skip_dimensions.push_back(i);
					skip_dimensions.push_back(j);
					break;
				}
			}
		}
		vector<dimension> new_dimensions = vector<dimension>();
		for(unsigned int i = 0; i < new_x.size(); i++)
		{
			bool skip = false;
			for(unsigned int j = 0; j < skip_dimensions.size(); j++)
			{
				if (i == skip_dimensions[j])
				{
					skip = true;
					break;
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
		vector<dimension> new_x = create_base_dimensions(x,value);
		if (new_x.size() == 1)
		{
			return x;
		}
		vector<unsigned int> skip_dimensions = vector<unsigned int>();
		for(unsigned int i = 0; i < new_x.size(); i++)
		{
			for(unsigned int j = i + 1; j < new_x.size(); j++)
			{
				if (skip_dimensions.size() > 0)
				{
					bool skip = false;
					for(unsigned int k = 0; k < skip_dimensions.size(); k++)
					{
						if (j == skip_dimensions[k])
						{
							skip = true;
							break;
						}
					}
					if (skip)
					{
						continue;
					}
				}
				if (new_x[i].dimension_type == new_x[j].dimension_type and new_x[i].dimension_position != new_x[j].dimension_position)
				{
					if (new_x[i].dimension_position == dimension::NUMERATOR)
					{
						value *= float(new_x[i].get_conversion_factor());
						value *= float(new_x[i].prefix_math());
					}
					else if (new_x[i].dimension_position == dimension::DENOMINATOR)
					{
						value /= float(new_x[i].get_conversion_factor());
						value /= float(new_x[i].prefix_math());
					}
					if (new_x[j].dimension_position == dimension::NUMERATOR)
					{
						value *= float(new_x[j].get_conversion_factor());
						value *= float(new_x[j].prefix_math());
					}
					else if (new_x[j].dimension_position == dimension::DENOMINATOR)
					{
						value /= float(new_x[j].get_conversion_factor());
						value /= float(new_x[j].prefix_math());
					}
					skip_dimensions.push_back(i);
					skip_dimensions.push_back(j);
					break;
				}
			}
		}
		vector<dimension> new_dimensions = vector<dimension>();
		for(unsigned int i = 0; i < new_x.size(); i++)
		{
			bool skip = false;
			for(unsigned int j = 0; j < skip_dimensions.size(); j++)
			{
				if (i == skip_dimensions[j])
				{
					skip = true;
					break;
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
		for (const dimension& x_dimension : x.get_base_dimensions())
		{
			for (const dimension& y_dimension : y.get_base_dimensions())
			{
				if (x_dimension.dimension_type == y_dimension.dimension_type and x_dimension.dimension_position == y_dimension.dimension_position)
				{
					return true;
				}
			}
		}
		return false;
	}

	bool equal_dimensions(const string& init_dimensions_x,const string& init_dimensions_y)
	{
		vector<dimension> x_dimensions = create_dimensions(init_dimensions_x);
		vector<dimension> y_dimensions = create_dimensions(init_dimensions_y);
		return equal_dimensions(x_dimensions,y_dimensions);
	}

	bool equal_dimensions(const vector<dimension>& x,const vector<dimension>& y)
	{
		vector<dimension> x_base_dimensions = create_base_dimensions(x);
		vector<dimension> y_base_dimensions = create_base_dimensions(y);
		if (x_base_dimensions.size() == y_base_dimensions.size())
		{
			if (x_base_dimensions.size() == 0)
			{
				return true;
			}
			vector<unsigned int> skip = vector<unsigned int>();
			for (const dimension& x_dimension: x_base_dimensions)
			{
				bool is_equal = false;
				for (unsigned int j = 0; j < y_base_dimensions.size(); j++)
				{
					bool skip_j = false;
					if (skip.size() > 0)
					{
						for (unsigned int k = 0; k < skip.size(); k++)
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
					if (x_dimension.dimension_type == y_base_dimensions[j].dimension_type and x_dimension.dimension_position == y_base_dimensions[j].dimension_position)
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
		else
		{
			return false;
		}
	}

	bool equal_dimensions_and_prefixes(const vector<dimension>& x,const vector<dimension>& y)
	{
		vector<unsigned int> skip = vector<unsigned int>();
		if (x.size() == y.size())
		{
			for (const dimension& x_dimension: x)
			{
				bool is_equal = false;
				for (unsigned int j = 0; j < y.size(); j++)
				{
					bool skip_j = false;
					if (skip.size() > 0)
					{
						for (unsigned int k = 0; k < skip.size(); k++)
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
					if (x_dimension == y[j])
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
		else
		{
			return false;
		}
	}
}

bool operator ==(const scifir::dimension& x,const scifir::dimension& y)
{
	if (x.dimension_type == y.dimension_type and x.dimension_position == y.dimension_position and x.prefix == y.prefix)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const scifir::dimension& x,const scifir::dimension& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os, const scifir::dimension& x)
{
	return os << x.prefix.get_symbol() << x.get_symbol();
}
