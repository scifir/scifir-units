#include "abbreviation.hpp"
#include "conversion.hpp"
#include "dimension_abstract.hpp"
#include "dimension_container.hpp"
#include "dimension.hpp"

#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
using namespace std;

namespace physics::units
{
	dimension::dimension() : dimension_abstract(normal_prefix, 1)
	{
	}

	dimension::dimension(prefix_symbol prefix_name, int new_scale) : dimension_abstract(prefix_name, new_scale)
	{
	}

	dimension::dimension(prefix& prefix_name, int new_scale) : dimension_abstract(prefix_name, new_scale)
	{
	}

	dimension_length::dimension_length(prefix_symbol new_prefix) :
		dimension_crtp<dimension_length>(new_prefix)
	{
	}

	dimension_length::dimension_length(prefix& new_prefix) : dimension_crtp<dimension_length>(new_prefix)
	{
	}

	const string dimension_length::name = "meter";
	const string dimension_length::symbol = "m";

	int dimension_length::get_enum_type() const
	{
		return m;
	}

	dimension_angle::dimension_angle(prefix_symbol new_prefix) :
		dimension_crtp<dimension_angle>(new_prefix)
	{
	}

	dimension_angle::dimension_angle(prefix& new_prefix) : dimension_crtp<dimension_angle>(new_prefix)
	{
	}

	const string dimension_angle::name = "angle";
	const string dimension_angle::symbol = "angle";

	int dimension_angle::get_enum_type() const
	{
		return angle;
	}

	dimension_solid_angle::dimension_solid_angle(prefix_symbol new_prefix) :
		dimension_crtp<dimension_solid_angle>(new_prefix)
	{
	}

	dimension_solid_angle::dimension_solid_angle(prefix& new_prefix) : dimension_crtp<dimension_solid_angle>(new_prefix)
	{
	}

	const string dimension_solid_angle::name = "solid angle";
	const string dimension_solid_angle::symbol = "solid_angle";

	int dimension_solid_angle::get_enum_type() const
	{
		return solid_angle;
	}

	dimension_mass::dimension_mass(prefix_symbol new_prefix) :
		dimension_crtp<dimension_mass>(new_prefix)
	{
	}

	dimension_mass::dimension_mass(prefix& new_prefix) : dimension_crtp<dimension_mass>(new_prefix)
	{
	}

	const string dimension_mass::name = "gram";
	const string dimension_mass::symbol = "g";

	int dimension_mass::get_enum_type() const
	{
		return g;
	}

	dimension_time::dimension_time(prefix_symbol new_prefix) :
		dimension_crtp<dimension_time>(new_prefix)
	{
	}

	dimension_time::dimension_time(prefix& new_prefix) : dimension_crtp<dimension_time>(new_prefix)
	{
	}

	const string dimension_time::name = "second";
	const string dimension_time::symbol = "s";

	int dimension_time::get_enum_type() const
	{
		return s;
	}

	dimension_charge::dimension_charge(prefix_symbol new_prefix) :
		dimension_crtp<dimension_charge>(new_prefix)
	{
	}

	dimension_charge::dimension_charge(prefix& new_prefix) : dimension_crtp<dimension_charge>(new_prefix)
	{
	}

	const string dimension_charge::name = "coulomb";
	const string dimension_charge::symbol = "C";

	int dimension_charge::get_enum_type() const
	{
		return A;
	}

	dimension_temperature::dimension_temperature(prefix_symbol new_prefix) :
		dimension_crtp<dimension_temperature>(new_prefix)
	{
	}

	dimension_temperature::dimension_temperature(prefix& new_prefix) : dimension_crtp<dimension_temperature>(new_prefix)
	{
	}

	const string dimension_temperature::name = "kelvin";
	const string dimension_temperature::symbol = "K";

	int dimension_temperature::get_enum_type() const
	{
		return K;
	}

	dimension_mole::dimension_mole(prefix_symbol new_prefix) :
		dimension_crtp<dimension_mole>(new_prefix)
	{
	}

	dimension_mole::dimension_mole(prefix& new_prefix) : dimension_crtp<dimension_mole>(new_prefix)
	{
	}

	const string dimension_mole::name = "mole";
	const string dimension_mole::symbol = "mol";

	int dimension_mole::get_enum_type() const
	{
		return mol;
	}

	dimension_light::dimension_light(prefix_symbol new_prefix) :
		dimension_crtp<dimension_light>(new_prefix)
	{
	}

	dimension_light::dimension_light(prefix& new_prefix) : dimension_crtp<dimension_light>(new_prefix)
	{
	}

	const string dimension_light::name = "candela";
	const string dimension_light::symbol = "cd";

	int dimension_light::get_enum_type() const
	{
		return cd;
	}

	dimension_byte::dimension_byte(prefix_symbol new_prefix) :
		dimension_crtp<dimension_byte>(new_prefix)
	{
	}

	dimension_byte::dimension_byte(prefix& new_prefix) : dimension_crtp<dimension_byte>(new_prefix)
	{
	}

	const string dimension_byte::name = "byte";
	const string dimension_byte::symbol = "B";

	int dimension_byte::get_enum_type() const
	{
		return cd;
	}

	float dimension_byte::get_prefix_base() const
	{
		return 10.0793684;
	}

	dimension* create_dimension(dimension_symbol x)
	{
		switch(x)
		{
			case m:
				return new dimension_length();
			case angle:
				return new dimension_angle();
			case solid_angle:
				return new dimension_solid_angle();
			case g:
				return new dimension_mass();
			case s:
				return new dimension_time();
			case A:
				return new dimension_charge();
			case K:
				return new dimension_temperature();
			case mol:
				return new dimension_mole();
			case cd:
				return new dimension_light();
			case B:
				return new dimension_byte();
		}
		return nullptr;
	}

	dimension* create_dimension(string x)
	{
		prefix* new_prefix;
		string dimension_name;
		string prefix_name;
		set<string> prefixes_options {"Y", "E", "P", "T", "G", "M", "k", "h", "d", "c", "m", "u", "n", "p", "f", "a", "z", "y"};
		if(prefixes_options.count(x.substr(0,1)) and x != "angle" and x != "solid_angle" and x != "m" and x.substr(0,2) != "da" and x.substr(0,3) != "mol")
		{
			prefix_name = x.substr(0,1);
			dimension_name = x.substr(1);
			new_prefix = create_prefix(prefix_name);
		}
		else if(x.substr(0,2) == "da")
		{
			prefix_name = "da";
			dimension_name = x.substr(2);
			new_prefix = create_prefix(prefix_name);
		}
		else
		{
			new_prefix = new prefix_normal();
			dimension_name = x;
		}
		if(dimension_name == "m")
		{
			return new dimension_length(*new_prefix);
		}
		else if(dimension_name == "angle")
		{
			return new dimension_angle(*new_prefix);
		}
		else if(dimension_name == "solid_angle")
		{
			return new dimension_solid_angle(*new_prefix);
		}
		else if(dimension_name == "g")
		{
			return new dimension_mass(*new_prefix);
		}
		else if(dimension_name == "s")
		{
			return new dimension_time(*new_prefix);
		}
		else if(dimension_name == "C")
		{
			return new dimension_charge(*new_prefix);
		}
		else if(dimension_name == "K")
		{
			return new dimension_temperature(*new_prefix);
		}
		else if(dimension_name == "mol")
		{
			return new dimension_mole(*new_prefix);
		}
		else if(dimension_name == "cd")
		{
			return new dimension_light(*new_prefix);
		}
		else if(dimension_name == "B")
		{
			return new dimension_byte(*new_prefix);
		}
		else
		{
			return nullptr;
		}
	}
}
