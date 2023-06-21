#include "units/dimension.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

namespace msci
{
	map<int,string> dimension::full_symbols = map<int,string>();
	int dimension::total_full_symbols = 0;
	
	dimension::dimension() : prefix(),dimension_type(),dimension_sign(),symbol()
	{}

	dimension::dimension(const dimension& x) : prefix(x.prefix),dimension_type(x.dimension_type),dimension_sign(x.dimension_sign)
	{
		std::strcpy(symbol, x.symbol);
	}

	dimension::dimension(dimension&& x) : prefix(move(x.prefix)),dimension_type(move(x.dimension_type)),dimension_sign(move(x.dimension_sign))
	{
		std::strcpy(symbol, move(x.symbol));
	}

	dimension::dimension(dimension::type new_dimension_type,msci::prefix::type new_prefix,dimension::sign new_sign) : prefix(new_prefix),dimension_type(new_dimension_type),dimension_sign(new_sign),symbol()
	{}

	dimension::dimension(dimension::type new_dimension_type,const msci::prefix& new_prefix,dimension::sign new_sign) : prefix(new_prefix),dimension_type(new_dimension_type),dimension_sign(new_sign),symbol()
	{}

	dimension::dimension(const string& new_symbol,const msci::prefix& new_prefix,dimension::sign new_sign) : prefix(new_prefix),dimension_type(dimension::custom),dimension_sign(new_sign)//,symbol{char[new_symbol.size()]}
	{
		if (new_symbol.size() > 3)
		{
			string symbol_abreviation = dimension::create_full_symbol(new_symbol);
			symbol_abreviation.copy(symbol, new_symbol.length());
			dimension_type = dimension::custom_full_symbol;
		}
		else
		{
			new_symbol.copy(symbol, new_symbol.length());
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
		return *this;
	}
	
	dimension& dimension::operator=(dimension&& x)
	{
		prefix = move(x.prefix);
		dimension_type = move(x.dimension_type);
		dimension_sign = move(x.dimension_sign);
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
			case dimension::ppm:
				return "parts per million";
			case dimension::ppb:
				return "parts per billion";
			case dimension::custom:
				return "custom-dimension";
//				return static_cast<msci::custom_dimension&>(const_cast<dimension&>(*this)).symbol;
			case dimension::custom_basic:
				return "custom-basic";
			case dimension::custom_full_symbol:
				return "custom-full-symbol";
			case dimension::money:
				return "money";
			case dimension::pixel:
				return "pixel";
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
			case dimension::ppm:
				return "ppm";
			case dimension::ppb:
				return "ppb";
			case dimension::custom:
				return symbol;
			case dimension::custom_basic:
				return "custom-basic";
			case dimension::custom_full_symbol:
				return dimension::get_full_symbol(symbol);
			case dimension::money:
				return "money";
			case dimension::pixel:
				return "px";
		}
		return "";
	}

	int dimension::get_scale() const
	{
		if (is_basic_dimension())
		{
			return 1;
		}
		else
		{
			switch(dimension_type)
			{
				case dimension::Hz:
					return 1;
				case dimension::N:
					return 2;
				case dimension::Pa:
					return 2;
				case dimension::J:
					return 2;
				case dimension::W:
					return 2;
				case dimension::A:
					return 2;
				case dimension::V:
					return 2;
				case dimension::F:
					return 2;
				case dimension::Ohm:
					return 2;
				case dimension::S:
					return 2;
				case dimension::Wb:
					return 2;
				case dimension::T:
					return 2;
				case dimension::H:
					return 2;
				case dimension::lm:
					return 2;
				case dimension::lx:
					return 2;
				case dimension::Bq:
					return 2;
				case dimension::Gy:
					return 2;
				case dimension::Sv:
					return 2;
				case dimension::kat:
					return 2;
				case dimension::angstrom:
					return 2;
				case dimension::L:
					return 2;
				case dimension::minute:
					return 2;
				case dimension::h:
					return 2;
				case dimension::d:
					return 2;
				case dimension::AU:
					return 2;
				case dimension::pc:
					return 2;
				case dimension::eV:
					return 2;
				case dimension::Da:
					return 2;
				case dimension::amu:
					return 2;
				case dimension::barn:
					return 2;
				case dimension::M:
					return 2;
				case dimension::particles:
					return 2;
				case dimension::ppm:
					return 2;
				case dimension::ppb:
					return 2;
			}
			return 0;
		}
	}

	int dimension::get_absolute_scale() const
	{
		if (is_basic_dimension())
		{
			return 1;
		}
		else
		{
			switch(dimension_type)
			{
				case dimension::Hz:
					return 1;
				case dimension::N:
					return 4;
				case dimension::Pa:
					return 2;
				case dimension::J:
					return 2;
				case dimension::W:
					return 2;
				case dimension::A:
					return 2;
				case dimension::V:
					return 2;
				case dimension::F:
					return 2;
				case dimension::Ohm:
					return 2;
				case dimension::S:
					return 2;
				case dimension::Wb:
					return 2;
				case dimension::T:
					return 2;
				case dimension::H:
					return 2;
				case dimension::lm:
					return 2;
				case dimension::lx:
					return 2;
				case dimension::Bq:
					return 2;
				case dimension::Gy:
					return 2;
				case dimension::Sv:
					return 2;
				case dimension::kat:
					return 2;
				case dimension::angstrom:
					return 2;
				case dimension::L:
					return 2;
				case dimension::minute:
					return 2;
				case dimension::h:
					return 2;
				case dimension::d:
					return 2;
				case dimension::AU:
					return 2;
				case dimension::pc:
					return 2;
				case dimension::eV:
					return 2;
				case dimension::Da:
					return 2;
				case dimension::amu:
					return 2;
				case dimension::barn:
					return 2;
				case dimension::M:
					return 2;
				case dimension::particles:
					return 2;
				case dimension::ppm:
					return 2;
				case dimension::ppb:
					return 2;
			}
			return 0;
		}
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
			case dimension::ppm:
				return true;
			case dimension::ppb:
				return true;
			case dimension::custom:
				return false;
				//return static_cast<msci::custom_dimension&>(const_cast<dimension&>(*this)).is_basic_dimension();
			case dimension::custom_basic:
				return true;
			case dimension::custom_full_symbol:
				return false;
			case dimension::money:
				return true;
			case dimension::pixel:
				return true;
		}
		return false;
	}

	bool dimension::is_derived_dimension() const
	{
		return !is_basic_dimension();
	}

	vector<dimension> dimension::get_basic_dimensions() const
	{
		int basic_dimensions_count = get_absolute_scale();
		vector<dimension> basic_dimensions = vector<dimension>();
		switch (dimension_type)
		{
			case dimension::N:
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::positive));
				basic_dimensions.push_back(dimension(dimension::g,prefix::no_prefix,dimension::positive));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::negative));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::negative));
				break;
		}
		return basic_dimensions;
	}

	void dimension::invert()
	{
		if (dimension_sign == dimension::positive)
		{
			dimension_sign = dimension::negative;
		}
		else
		{
			dimension_sign = dimension::positive;
		}
	}

	/*float dimension_byte::get_prefix_base() const
	{
		return 10.0793684;
	}*/

	dimension create_dimension(const string& x,dimension::sign new_sign)
	{
		if (x == "")
		{
			return dimension();
		}
		string dimension_name;
		string prefix_name;
		set<string> prefixes_options {"Y", "E", "P", "T", "G", "M", "k", "h", "d", "c", "m", "u", "n", "p", "f", "a", "z", "y"};
		if(prefixes_options.count(x.substr(0,1)) and x != "rad" and x != "sr" and x != "m" and x.substr(0,2) != "da" and x.substr(0,3) != "mol")
		{
			prefix_name = x.substr(0,1);
			dimension_name = x.substr(1);
		}
		else if(x.substr(0,2) == "da")
		{
			prefix_name = "da";
			dimension_name = x.substr(2);
		}
		else
		{
			prefix_name = "";
			dimension_name = x;
		}
		prefix new_prefix = create_prefix(prefix_name);
		if(dimension_name == "m")
		{
			return dimension(dimension::m,new_prefix,new_sign);
		}
		else if(dimension_name == "rad")
		{
			return dimension(dimension::radian,new_prefix,new_sign);
		}
		else if(dimension_name == "sr")
		{
			return dimension(dimension::steradian,new_prefix,new_sign);
		}
		else if(dimension_name == "s")
		{
			return dimension(dimension::s,new_prefix,new_sign);
		}
		else if(dimension_name == "g")
		{
			return dimension(dimension::g,new_prefix,new_sign);
		}
		else if(dimension_name == "C")
		{
			return dimension(dimension::C,new_prefix,new_sign);
		}
		else if(dimension_name == "K")
		{
			return dimension(dimension::K,new_prefix,new_sign);
		}
		else if(dimension_name == "mol")
		{
			return dimension(dimension::mol,new_prefix,new_sign);
		}
		else if(dimension_name == "cd")
		{
			return dimension(dimension::cd,new_prefix,new_sign);
		}
		else if(dimension_name == "B")
		{
			return dimension(dimension::B,new_prefix,new_sign);
		}
		else if(dimension_name == "Hz")
		{
			return dimension(dimension::Hz,new_prefix,new_sign);
		}
		else if(dimension_name == "N")
		{
			return dimension(dimension::N,new_prefix,new_sign);
		}
		else if(dimension_name == "Pa")
		{
			return dimension(dimension::Pa,new_prefix,new_sign);
		}
		else if(dimension_name == "J")
		{
			return dimension(dimension::J,new_prefix,new_sign);
		}
		else if(dimension_name == "W")
		{
			return dimension(dimension::W,new_prefix,new_sign);
		}
		else if(dimension_name == "A")
		{
			return dimension(dimension::A,new_prefix,new_sign);
		}
		else if(dimension_name == "V")
		{
			return dimension(dimension::V,new_prefix,new_sign);
		}
		else if(dimension_name == "F")
		{
			return dimension(dimension::F,new_prefix,new_sign);
		}
		else if(dimension_name == "ohm" or dimension_name == "Ohm" or dimension_name == "\u03A9")
		{
			return dimension(dimension::Ohm,new_prefix,new_sign);
		}
		else if(dimension_name == "S")
		{
			return dimension(dimension::S,new_prefix,new_sign);
		}
		else if(dimension_name == "Wb")
		{
			return dimension(dimension::Wb,new_prefix,new_sign);
		}
		else if(dimension_name == "T")
		{
			return dimension(dimension::T,new_prefix,new_sign);
		}
		else if(dimension_name == "H")
		{
			return dimension(dimension::H,new_prefix,new_sign);
		}
		else if(dimension_name == "lm")
		{
			return dimension(dimension::lm,new_prefix,new_sign);
		}
		else if(dimension_name == "lx")
		{
			return dimension(dimension::lx,new_prefix,new_sign);
		}
		else if(dimension_name == "Bq")
		{
			return dimension(dimension::Bq,new_prefix,new_sign);
		}
		else if(dimension_name == "Gy")
		{
			return dimension(dimension::Gy,new_prefix,new_sign);
		}
		else if(dimension_name == "Sv")
		{
			return dimension(dimension::Sv,new_prefix,new_sign);
		}
		else if(dimension_name == "kat")
		{
			return dimension(dimension::kat,new_prefix,new_sign);
		}
		else if(dimension_name == "angstrom" or dimension_name == "\u212B")
		{
			return dimension(dimension::angstrom,new_prefix,new_sign);
		}
		else if(dimension_name == "L")
		{
			return dimension(dimension::L,new_prefix,new_sign);
		}
		else if(dimension_name == "min")
		{
			return dimension(dimension::minute,new_prefix,new_sign);
		}
		else if(dimension_name == "h")
		{
			return dimension(dimension::h,new_prefix,new_sign);
		}
		else if(dimension_name == "d")
		{
			return dimension(dimension::d,new_prefix,new_sign);
		}
		else if(dimension_name == "AU")
		{
			return dimension(dimension::AU,new_prefix,new_sign);
		}
		else if(dimension_name == "pc")
		{
			return dimension(dimension::pc,new_prefix,new_sign);
		}
		else if(dimension_name == "eV")
		{
			return dimension(dimension::eV,new_prefix,new_sign);
		}
		else if(dimension_name == "Da")
		{
			return dimension(dimension::Da,new_prefix,new_sign);
		}
		else if(dimension_name == "amu")
		{
			return dimension(dimension::amu,new_prefix,new_sign);
		}
		else if(dimension_name == "barn")
		{
			return dimension(dimension::barn,new_prefix,new_sign);
		}
		else if(dimension_name == "M")
		{
			return dimension(dimension::M,new_prefix,new_sign);
		}
		else if(dimension_name == "particles")
		{
			return dimension(dimension::particles,new_prefix,new_sign);
		}
		else if(dimension_name == "ppm")
		{
			return dimension(dimension::ppm,new_prefix,new_sign);
		}
		else if(dimension_name == "ppb")
		{
			return dimension(dimension::ppb,new_prefix,new_sign);
		}
		else if(dimension_name == "money")
		{
			return dimension(dimension::money,new_prefix,new_sign);
		}
		else if(dimension_name == "px")
		{
			return dimension(dimension::pixel,new_prefix,new_sign);
		}
		else
		{
			return dimension(dimension_name,new_prefix,new_sign);
		}
	}

	string to_string(const vector<dimension>& x_dimensions)
	{
		ostringstream out;
		vector<dimension::type> printed_dimensions = vector<dimension::type>();
		map<prefix,int> counted_prefixes = map<prefix,int>();
		for (const dimension& x_dimension : x_dimensions)
		{
			if (x_dimension.dimension_sign == dimension::positive)
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
			if (x_dimension.dimension_sign == dimension::negative)
			{
				if (first_negative_iteration == true)
				{
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
		return out.str();
	}

	vector<dimension> create_dimensions(string init_value)
	{
		boost::algorithm::erase_all(init_value, " ");
		dimension::sign new_sign = dimension::positive;
		int new_scale = 1;
		int new_size = 1;
		int new_start = 0;
		string new_dimension_str;
		vector<dimension> dimensions = vector<dimension>();
		for(int j = 0; j < init_value.size(); j++)
		{
			/*if(isdigit(init_value[j]))
			{
				new_dimension_str = init_value.substr(new_start, new_size);
				new_scale = stoi(init_value.substr(j, 1));
				cout << "new_dimension_str: " << new_dimension_str << endl;
				cout << "new_scale: " << new_scale << endl;
				cout << "j: " << j << endl;
				cout << "new_size: " << new_size << endl;
			}
			else */if(isalpha(init_value[j]) and (!isalpha(init_value[j + 1]) or (j + 1) == init_value.size()))
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
				new_sign = dimension::negative;
				new_size = 0;
				new_start = j + 1;
			}
			if(!new_dimension_str.empty())
			{
				dimension new_dimension = create_dimension(new_dimension_str,new_sign);
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

	vector<dimension> create_derived_dimensions(string init_value)
	{
		boost::algorithm::erase_all(init_value, " ");
		dimension::sign new_sign = dimension::positive;
		int new_scale = 1;
		int new_size = 1;
		int new_start = 0;
		string new_dimension_str;
		vector<dimension> dimensions = vector<dimension>();
		for(int j = 0; j < init_value.size(); j++)
		{
			if(isdigit(init_value[j]))
			{
				new_dimension_str = init_value.substr(new_start, new_size - 1);
				new_scale = stoi(init_value.substr(new_start, 1));
			}
			else if(isalpha(init_value[j]) and (!isalpha(init_value[j + 1]) or (j + 1) == init_value.size()))
			{
				new_dimension_str = init_value.substr(new_start, new_size);
			}
			if(init_value[j] == '*')
			{
				new_size = 0;
				new_start = j + 1;
			}
			else if(init_value[j] == '/')
			{
				new_sign = dimension::negative;
				new_size = 0;
				new_start = j + 1;
			}
			if(!new_dimension_str.empty())
			{
				dimension new_dimension = create_dimension(new_dimension_str,new_sign);
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

	vector<dimension> create_derived_dimensions(const vector<dimension>& x)
	{
		vector<dimension> new_x = vector<dimension>();
		for(int i = 0; i < x.size(); i++)
		{
			if (x[i].is_derived_dimension())
			{
				vector<dimension> x_subdimensions = x[i].get_basic_dimensions();
				for (const dimension& x_subdimension : x_subdimensions)
				{
					new_x.push_back(x_subdimension);
				}
			}
			else
			{
				new_x.push_back(x[i]);
			}
		}
		return new_x;
	}

	vector<dimension> multiply_dimensions(const vector<dimension>& x,const vector<dimension>& y)
	{
		vector<dimension> new_dimensions = vector<dimension>();
		for(const dimension& x_dimension: x)
		{
			new_dimensions.push_back(x_dimension);
		}
		for(const dimension& y_dimension : y)
		{
			new_dimensions.push_back(y_dimension);
		}
		return new_dimensions;
	}

	vector<dimension> divide_dimensions(const vector<dimension>& x,const vector<dimension>& y)
	{
		vector<dimension> new_dimensions = vector<dimension>();
		for(const dimension& x_dimension: x)
		{
			new_dimensions.push_back(x_dimension);
		}
		for(dimension y_dimension : y)
		{
			y_dimension.invert();
			new_dimensions.push_back(y_dimension);
		}
		return normalize_dimensions(new_dimensions);
	}
	
	vector<dimension> square_dimensions(const vector<dimension>& x,int scale)
	{
		vector<dimension> new_dimensions = vector<dimension>();
		vector<dimension::type> counted_dimensions = vector<dimension::type>();
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
			int i = 1;
			for (const dimension& y_dimension : x)
			{
				if (x_dimension.dimension_type == y_dimension.dimension_type)
				{
					i++;
				}
			}
			int total_dimensions = std::sqrt(i);
			for (int j = 0; j < total_dimensions; j++)
			{
				new_dimensions.push_back(dimension(x_dimension.dimension_type,x_dimension.prefix,x_dimension.dimension_sign));
			}
			counted_dimensions.push_back(x_dimension.dimension_type);
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
		vector<int> skip_dimensions = vector<int>();
		vector<dimension> new_x = create_derived_dimensions(x);
		for(int i = 0; i < new_x.size(); i++)
		{
			dimension x_dimension = new_x[i];
			for(int j = i; j < new_x.size(); j++)
			{
				dimension y_dimension = new_x[j];
				if (x_dimension.dimension_type == y_dimension.dimension_type and x_dimension.dimension_sign != y_dimension.dimension_sign)
				{
					skip_dimensions.push_back(i);
					skip_dimensions.push_back(j);
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
	
	int prefix_square_difference(const vector<dimension>& x)
	{
		int prefix_scale = 0;
		vector<int> checked_dimensions = vector<int>();
		for(int i = 0; i < x.size(); i++)
		{
			dimension x_dimension = x[i];
			bool skip = false;
			for (const int& j_checked_dimension : checked_dimensions)
			{
				if (i == j_checked_dimension)
				{
					skip = true;
					break;
				}
			}
			if (skip == true)
			{
				continue;
			}
			if ((i + 1) != x.size())
			{
				for(int j = i + 1; j < x.size(); j++)
				{
					dimension y_dimension = x[j];
					if (common_dimmension(x_dimension,y_dimension) and x_dimension.prefix.get_conversion_factor() != y_dimension.prefix.get_conversion_factor())
					{
						if (x_dimension.dimension_sign == dimension::positive)
						{
							prefix_scale += x_dimension.prefix.get_conversion_factor() - y_dimension.prefix.get_conversion_factor();
						}
						else
						{
							prefix_scale -= x_dimension.prefix.get_conversion_factor() - y_dimension.prefix.get_conversion_factor();
						}
						checked_dimensions.push_back(i);
						checked_dimensions.push_back(j);
						break;
					}
				}
			}
		}
		return prefix_scale;
	}
	
	bool common_dimmension(const dimension& x,const dimension& y)
	{
		for (const dimension& x_dimension : x.get_basic_dimensions())
		{
			for (const dimension& y_dimension : y.get_basic_dimensions())
			{
				if (x.dimension_type == y.dimension_type)
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
		vector<int> skip = vector<int>();
		for (const dimension& x_dimension: x)
		{
			bool is_equal = false;
			for (int j = 0; j < y.size(); j++)
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
				if (x_dimension == y[j])
				{
					skip.push_back(j);
					is_equal = true;
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

bool operator==(const msci::dimension& x,const msci::dimension& y)
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

bool operator!=(const msci::dimension& x,const msci::dimension& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os, const msci::dimension& x)
{
	return os << x.prefix.get_symbol() << x.get_symbol();
}
