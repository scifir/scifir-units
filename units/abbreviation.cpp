#include "msci/units/units/abbreviation.hpp"
#include "msci/units/units/dimension.hpp"
#include "msci/units/units/dimension_container.hpp"
#include "msci/units/units/prefix.hpp"

#include "msci/units/topology/constants.hpp"

#include <iostream>
#include <set>
#include <string>

using namespace std;

namespace msci
{
	abbreviation::abbreviation() : abstract_dimension(normal_prefix, 1)
	{
	}

	abbreviation::abbreviation(prefix_symbol new_prefix, int new_scale) : abstract_dimension(new_prefix, new_scale)
	{
	}

	abbreviation::abbreviation(prefix& new_prefix, int new_scale) : abstract_dimension(new_prefix, new_scale)
	{
	}

	int abbreviation_normal::get_enum_type() const
	{
		return abbreviation_symbol::normal_abbreviation;
	}

	const string abbreviation_normal::dimensions_match = "";
	const float abbreviation_normal::factor = 1;
	const string abbreviation_normal::name = "";
	const string abbreviation_normal::symbol = "";

	int abbreviation_hertz::get_enum_type() const
	{
		return abbreviation_symbol::Hz;
	}

	const string abbreviation_hertz::dimensions_match = "1/s";
	const float abbreviation_hertz::factor = 1;
	const string abbreviation_hertz::name = "hertz";
	const string abbreviation_hertz::symbol = "Hz";

	int abbreviation_newton::get_enum_type() const
	{
		return abbreviation_symbol::N;
	}

	const string abbreviation_newton::dimensions_match = "kg*m/s2";
	const float abbreviation_newton::factor = 1;
	const string abbreviation_newton::name = "newton";
	const string abbreviation_newton::symbol = "N";

	int abbreviation_pascal::get_enum_type() const
	{
		return abbreviation_symbol::Pa;
	}

	const string abbreviation_pascal::dimensions_match = "kg/m*s2";
	const float abbreviation_pascal::factor = 1;
	const string abbreviation_pascal::name = "pascal";
	const string abbreviation_pascal::symbol = "Pa";

	int abbreviation_joule::get_enum_type() const
	{
		return abbreviation_symbol::J;
	}

	const string abbreviation_joule::dimensions_match = "kg/m2*s2";
	const float abbreviation_joule::factor = 1;
	const string abbreviation_joule::name = "joule";
	const string abbreviation_joule::symbol = "J";

	int abbreviation_watt::get_enum_type() const
	{
		return abbreviation_symbol::W;
	}

	const string abbreviation_watt::dimensions_match = "kg/m2*s3";
	const float abbreviation_watt::factor = 1;
	const string abbreviation_watt::name = "watt";
	const string abbreviation_watt::symbol = "W";

	int abbreviation_ampere::get_enum_type() const
	{
		return abbreviation_symbol::A;
	}

	const string abbreviation_ampere::dimensions_match = "C/s";
	const float abbreviation_ampere::factor = 1;
	const string abbreviation_ampere::name = "ampere";
	const string abbreviation_ampere::symbol = "A";

	int abbreviation_volt::get_enum_type() const
	{
		return abbreviation_symbol::V;
	}

	const string abbreviation_volt::dimensions_match = "kg*m2/s3*A";
	const float abbreviation_volt::factor = 1;
	const string abbreviation_volt::name = "volt";
	const string abbreviation_volt::symbol = "V";

	int abbreviation_farad::get_enum_type() const
	{
		return abbreviation_symbol::F;
	}

	const string abbreviation_farad::dimensions_match = "s4*A2/kg*m2";
	const float abbreviation_farad::factor = 1;
	const string abbreviation_farad::name = "farad";
	const string abbreviation_farad::symbol = "F";

	int abbreviation_ohm::get_enum_type() const
	{
		return abbreviation_symbol::Ohm;
	}

	const string abbreviation_ohm::dimensions_match = "kg*m2/s3*A2";
	const float abbreviation_ohm::factor = 1;
	const string abbreviation_ohm::name = "ohm";
	const string abbreviation_ohm::symbol = "Ω";

	int abbreviation_siemens::get_enum_type() const
	{
		return abbreviation_symbol::S;
	}

	const string abbreviation_siemens::dimensions_match = "s3*A2/kg*m2";
	const float abbreviation_siemens::factor = 1;
	const string abbreviation_siemens::name = "siemens";
	const string abbreviation_siemens::symbol = "S";

	int abbreviation_weber::get_enum_type() const
	{
		return abbreviation_symbol::Wb;
	}

	const string abbreviation_weber::dimensions_match = "kg*m2/s2*A";
	const float abbreviation_weber::factor = 1;
	const string abbreviation_weber::name = "weber";
	const string abbreviation_weber::symbol = "Wb";

	int abbreviation_tesla::get_enum_type() const
	{
		return abbreviation_symbol::T;
	}

	const string abbreviation_tesla::dimensions_match = "kg/s2*A";
	const float abbreviation_tesla::factor = 1;
	const string abbreviation_tesla::name = "tesla";
	const string abbreviation_tesla::symbol = "T";

	int abbreviation_henry::get_enum_type() const
	{
		return abbreviation_symbol::H;
	}

	const string abbreviation_henry::dimensions_match = "kg*m2/s2*A2";
	const float abbreviation_henry::factor = 1;
	const string abbreviation_henry::name = "henry";
	const string abbreviation_henry::symbol = "H";

	int abbreviation_lumen::get_enum_type() const
	{
		return abbreviation_symbol::lm;
	}

	const string abbreviation_lumen::dimensions_match = "cd";
	const float abbreviation_lumen::factor = 1;
	const string abbreviation_lumen::name = "lumen";
	const string abbreviation_lumen::symbol = "lm";

	int abbreviation_lux::get_enum_type() const
	{
		return abbreviation_symbol::lx;
	}

	const string abbreviation_lux::dimensions_match = "cd/m2";
	const float abbreviation_lux::factor = 1;
	const string abbreviation_lux::name = "lux";
	const string abbreviation_lux::symbol = "lx";

	int abbreviation_becquerel::get_enum_type() const
	{
		return abbreviation_symbol::Bq;
	}

	const string abbreviation_becquerel::dimensions_match = "1/s";
	const float abbreviation_becquerel::factor = 1;
	const string abbreviation_becquerel::name = "becquerel";
	const string abbreviation_becquerel::symbol = "Bq";

	int abbreviation_gray::get_enum_type() const
	{
		return abbreviation_symbol::Gy;
	}

	const string abbreviation_gray::dimensions_match = "m2/s2";
	const float abbreviation_gray::factor = 1;
	const string abbreviation_gray::name = "gray";
	const string abbreviation_gray::symbol = "Gy";

	int abbreviation_sievert::get_enum_type() const
	{
		return abbreviation_symbol::Sv;
	}

	const string abbreviation_sievert::dimensions_match = "m2/s2";
	const float abbreviation_sievert::factor = 1;
	const string abbreviation_sievert::name = "sievert";
	const string abbreviation_sievert::symbol = "Sv";

	int abbreviation_katal::get_enum_type() const
	{
		return abbreviation_symbol::kat;
	}

	const string abbreviation_katal::dimensions_match = "mol/s";
	const float abbreviation_katal::factor = 1;
	const string abbreviation_katal::name = "katal";
	const string abbreviation_katal::symbol = "kat";

	int abbreviation_angstrom::get_enum_type() const
	{
		return abbreviation_symbol::angstrom;
	}

	const string abbreviation_angstrom::dimensions_match = "1/m10";
	const float abbreviation_angstrom::factor = 1;
	const string abbreviation_angstrom::name = "angstrom";
	const string abbreviation_angstrom::symbol = "Å";

	int abbreviation_litre::get_enum_type() const
	{
		return abbreviation_symbol::L;
	}

	const string abbreviation_litre::dimensions_match = "dm3";
	const float abbreviation_litre::factor = 1;
	const string abbreviation_litre::name = "litre";
	const string abbreviation_litre::symbol = "";

	int abbreviation_minute::get_enum_type() const
	{
		return abbreviation_symbol::minute;
	}

	const string abbreviation_minute::dimensions_match = "s";
	const float abbreviation_minute::factor = 60;
	const string abbreviation_minute::name = "minute";
	const string abbreviation_minute::symbol = "min";

	int abbreviation_hour::get_enum_type() const
	{
		return abbreviation_symbol::h;
	}

	const string abbreviation_hour::dimensions_match = "s";
	const float abbreviation_hour::factor = 3600;
	const string abbreviation_hour::name = "hour";
	const string abbreviation_hour::symbol = "h";

	int abbreviation_day::get_enum_type() const
	{
		return abbreviation_symbol::d;
	}

	const string abbreviation_day::dimensions_match = "s";
	const float abbreviation_day::factor = 86400;
	const string abbreviation_day::name = "day";
	const string abbreviation_day::symbol = "d";

	int abbreviation_astronomical_unit::get_enum_type() const
	{
		return abbreviation_symbol::AU;
	}

	const string abbreviation_astronomical_unit::dimensions_match = "m";
	const float abbreviation_astronomical_unit::factor = 149597870700;
	const string abbreviation_astronomical_unit::name = "astronomical_unit";
	const string abbreviation_astronomical_unit::symbol = "AU";

	int abbreviation_parsec::get_enum_type() const
	{
		return abbreviation_symbol::pc;
	}

	const string abbreviation_parsec::dimensions_match = "m";
	const float abbreviation_parsec::factor = 30856775814913700;
	const string abbreviation_parsec::name = "parsec";
	const string abbreviation_parsec::symbol = "pc";

	int abbreviation_electron_volt::get_enum_type() const
	{
		return abbreviation_symbol::eV;
	}

	const string abbreviation_electron_volt::dimensions_match = "kg*m2/s2";
	const float abbreviation_electron_volt::factor = 1.60217656535/*e−19*/;
	const string abbreviation_electron_volt::name = "electron_volt";
	const string abbreviation_electron_volt::symbol = "eV";

	int abbreviation_dalton::get_enum_type() const
	{
		return abbreviation_symbol::Da;
	}

	const string abbreviation_dalton::dimensions_match = "kg";
	const float abbreviation_dalton::factor = 1.6605388628/*e−27*/;
	const string abbreviation_dalton::name = "dalton";
	const string abbreviation_dalton::symbol = "Da";

	int abbreviation_amu::get_enum_type() const
	{
		return abbreviation_symbol::amu;
	}

	const string abbreviation_amu::dimensions_match = "g";
	const float abbreviation_amu::factor = 1.6605388628/*e−27*/;
	const string abbreviation_amu::name = "amu";
	const string abbreviation_amu::symbol = "amu";

	int abbreviation_barn::get_enum_type() const
	{
		return abbreviation_symbol::barn;
	}

	const string abbreviation_barn::dimensions_match = "m2";
	const float abbreviation_barn::factor = 10 ^ -28;
	const string abbreviation_barn::name = "barn";
	const string abbreviation_barn::symbol = "b";

	int abbreviation_molarity::get_enum_type() const
	{
		return abbreviation_symbol::M;
	}

	const string abbreviation_molarity::dimensions_match = "mol/";
	const float abbreviation_molarity::factor = 1;
	const string abbreviation_molarity::name = "molarity";
	const string abbreviation_molarity::symbol = "M";

	int abbreviation_particles::get_enum_type() const
	{
		return abbreviation_symbol::particles;
	}

	const string abbreviation_particles::dimensions_match = "mol";
	const float abbreviation_particles::factor = 1/msci::avogadro_constant;
	const string abbreviation_particles::name = "particles";
	const string abbreviation_particles::symbol = "particles";

	int abbreviation_ppm::get_enum_type() const
	{
		return abbreviation_symbol::ppm;
	}

	const string abbreviation_ppm::dimensions_match = "g/g";
	const float abbreviation_ppm::factor = 1/10^6;
	const string abbreviation_ppm::name = "parts per million";
	const string abbreviation_ppm::symbol = "ppm";

	int abbreviation_ppb::get_enum_type() const
	{
		return abbreviation_symbol::ppb;
	}

	const string abbreviation_ppb::dimensions_match = "g/g";
	const float abbreviation_ppb::factor = 1/10^9;
	const string abbreviation_ppb::name = "parts per billion";
	const string abbreviation_ppb::symbol = "ppb";

	abbreviation* create_abbreviation(abbreviation_symbol new_abbreviation)
	{
		switch(new_abbreviation)
		{
			case normal_abbreviation:
				return new abbreviation_normal();
			case Hz:
				return new abbreviation_hertz();
			case N:
				return new abbreviation_newton();
			case Pa:
				return new abbreviation_pascal();
			case J:
				return new abbreviation_joule();
			case W:
				return new abbreviation_watt();
			case A:
				return new abbreviation_ampere();
			case V:
				return new abbreviation_volt();
			case F:
				return new abbreviation_farad();
			case Ohm:
				return new abbreviation_ohm();
			case S:
				return new abbreviation_siemens();
			case Wb:
				return new abbreviation_weber();
			case T:
				return new abbreviation_tesla();
			case H:
				return new abbreviation_henry();
			case lm:
				return new abbreviation_lumen();
			case lx:
				return new abbreviation_lux();
			case Bq:
				return new abbreviation_becquerel();
			case Gy:
				return new abbreviation_gray();
			case Sv:
				return new abbreviation_sievert();
			case kat:
				return new abbreviation_katal();
			case angstrom:
				return new abbreviation_angstrom();
			case L:
				return new abbreviation_litre();
			case minute:
				return new abbreviation_minute();
			case h:
				return new abbreviation_hour();
			case d:
				return new abbreviation_day();
			case AU:
				return new abbreviation_astronomical_unit();
			case pc:
				return new abbreviation_parsec();
			case eV:
				return new abbreviation_electron_volt();
			case Da:
				return new abbreviation_dalton();
			case amu:
				return new abbreviation_amu();
			case barn:
				return new abbreviation_barn();
			case M:
				return new abbreviation_molarity();
			case particles:
				return new abbreviation_particles();
			case ppm:
				return new abbreviation_ppm();
			case ppb:
				return new abbreviation_ppb();
		}
		return nullptr;
	}

	abbreviation* create_abbreviation(const string& x)
	{
		prefix* new_prefix;
		string abbreviation_name;
		string prefix_name;
		set<string> prefixes_options {"Y", "E", "P", "T", "G", "M", "k", "h", "d", "c", "m", "u", "n", "p", "f", "a", "z", "y"};
		if(prefixes_options.count(x.substr(0,1)) and x.substr(0,9) != "particles" and x.substr(0,3) != "ppm" and x.substr(0,3) != "ppb" and x.substr(0,3) != "min" and x != "h" and x != "d" and x != "Pa")
		{
			prefix_name = x.substr(0, 1);
			abbreviation_name = x.substr(1);
			new_prefix = create_prefix(prefix_name);
		}
		else if(x.substr(0,2) == "da")
		{
			prefix_name = "da";
			abbreviation_name = x.substr(2);
			new_prefix = create_prefix(prefix_name);
		}
		else
		{
			new_prefix = new prefix_normal();
			abbreviation_name = x;
		}
		if(abbreviation_name == "Hz")
		{
			return new abbreviation_hertz(*new_prefix);
		}
		else if(abbreviation_name == "N")
		{
			return new abbreviation_newton(*new_prefix);
		}
		else if(abbreviation_name == "Pa")
		{
			return new abbreviation_pascal(*new_prefix);
		}
		else if(abbreviation_name == "J")
		{
			return new abbreviation_joule(*new_prefix);
		}
		else if(abbreviation_name == "W")
		{
			return new abbreviation_watt(*new_prefix);
		}
		else if(abbreviation_name == "A")
		{
			return new abbreviation_ampere(*new_prefix);
		}
		else if(abbreviation_name == "V")
		{
			return new abbreviation_volt(*new_prefix);
		}
		else if(abbreviation_name == "F")
		{
			return new abbreviation_farad(*new_prefix);
		}
		else if(abbreviation_name == "Ohm")
		{
			return new abbreviation_ohm(*new_prefix);
		}
		else if(abbreviation_name == "Ω")
		{
			return new abbreviation_ohm(*new_prefix);
		}
		else if(abbreviation_name == "S")
		{
			return new abbreviation_siemens(*new_prefix);
		}
		else if(abbreviation_name == "Wb")
		{
			return new abbreviation_weber(*new_prefix);
		}
		else if(abbreviation_name == "T")
		{
			return new abbreviation_tesla(*new_prefix);
		}
		else if(abbreviation_name == "H")
		{
			return new abbreviation_henry(*new_prefix);
		}
		else if(abbreviation_name == "lm")
		{
			return new abbreviation_lumen(*new_prefix);
		}
		else if(abbreviation_name == "lx")
		{
			return new abbreviation_lux(*new_prefix);
		}
		else if(abbreviation_name == "Bq")
		{
			return new abbreviation_becquerel(*new_prefix);
		}
		else if(abbreviation_name == "Gy")
		{
			return new abbreviation_gray(*new_prefix);
		}
		else if(abbreviation_name == "Sv")
		{
			return new abbreviation_sievert(*new_prefix);
		}
		else if(abbreviation_name == "kat")
		{
			return new abbreviation_katal(*new_prefix);
		}
		else if(abbreviation_name == "angstrom")
		{
			return new abbreviation_angstrom(*new_prefix);
		}
		else if(abbreviation_name == "Å")
		{
			return new abbreviation_angstrom(*new_prefix);
		}
		else if(abbreviation_name == "")
		{
			return new abbreviation_litre(*new_prefix);
		}
		else if(abbreviation_name == "min")
		{
			return new abbreviation_minute(*new_prefix);
		}
		else if(abbreviation_name == "h")
		{
			return new abbreviation_hour(*new_prefix);
		}
		else if(abbreviation_name == "d")
		{
			return new abbreviation_day(*new_prefix);
		}
		else if(abbreviation_name == "AU")
		{
			return new abbreviation_astronomical_unit(*new_prefix);
		}
		else if(abbreviation_name == "pc")
		{
			return new abbreviation_parsec(*new_prefix);
		}
		else if(abbreviation_name == "eV")
		{
			return new abbreviation_electron_volt(*new_prefix);
		}
		else if(abbreviation_name == "Da")
		{
			return new abbreviation_dalton(*new_prefix);
		}
		else if(abbreviation_name == "amu")
		{
			return new abbreviation_amu(*new_prefix);
		}
		else if(abbreviation_name == "barn")
		{
			return new abbreviation_barn(*new_prefix);
		}
		else if(abbreviation_name == "M")
		{
			return new abbreviation_molarity(*new_prefix);
		}
		else if(abbreviation_name == "particles")
		{
			return new abbreviation_particles(*new_prefix);
		}
		else if(abbreviation_name == "ppm")
		{
			return new abbreviation_ppm(*new_prefix);
		}
		else if(abbreviation_name == "ppb")
		{
			return new abbreviation_ppb(*new_prefix);
		}
		else
		{
			return nullptr;
		}
	}
}
