#include "abbreviation.hpp"
#include "dimension.hpp"
#include "dimension_container.hpp"
#include "prefix.hpp"

#include "chemistry/constants.hpp"

#include <iostream>
#include <set>
#include <string>

using namespace std;

namespace physics::units
{
	abbreviation::abbreviation() : dimension_abstract(normal_prefix, 1)
	{
	}

	abbreviation::abbreviation(prefix_symbol new_prefix, int new_scale) : dimension_abstract(new_prefix, new_scale)
	{
	}

	abbreviation::abbreviation(prefix& new_prefix, int new_scale) : dimension_abstract(new_prefix, new_scale)
	{
	}

	abbreviation_normal::abbreviation_normal(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_normal>(new_prefix, new_scale)
	{
	}

	abbreviation_normal::abbreviation_normal(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_normal>(new_prefix, new_scale)
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

	abbreviation_hertz::abbreviation_hertz(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_hertz>(new_prefix, new_scale)
	{
	}

	abbreviation_hertz::abbreviation_hertz(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_hertz>(new_prefix, new_scale)
	{
	}

	int abbreviation_hertz::get_enum_type() const
	{
		return abbreviation_symbol::Hz;
	}

	const string abbreviation_hertz::dimensions_match = "1/s";
	const float abbreviation_hertz::factor = 1;
	const string abbreviation_hertz::name = "hertz";
	const string abbreviation_hertz::symbol = "Hz";

	abbreviation_newton::abbreviation_newton(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_newton>(new_prefix, new_scale)
	{
	}

	abbreviation_newton::abbreviation_newton(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_newton>(new_prefix, new_scale)
	{
	}

	int abbreviation_newton::get_enum_type() const
	{
		return abbreviation_symbol::N;
	}

	const string abbreviation_newton::dimensions_match = "kg*m/s2";
	const float abbreviation_newton::factor = 1;
	const string abbreviation_newton::name = "newton";
	const string abbreviation_newton::symbol = "N";

	abbreviation_pascal::abbreviation_pascal(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_pascal>(new_prefix, new_scale)
	{
	}

	abbreviation_pascal::abbreviation_pascal(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_pascal>(new_prefix, new_scale)
	{
	}

	int abbreviation_pascal::get_enum_type() const
	{
		return abbreviation_symbol::Pa;
	}

	const string abbreviation_pascal::dimensions_match = "kg/m*s2";
	const float abbreviation_pascal::factor = 1;
	const string abbreviation_pascal::name = "pascal";
	const string abbreviation_pascal::symbol = "Pa";

	abbreviation_joule::abbreviation_joule(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_joule>(new_prefix, new_scale)
	{
	}

	abbreviation_joule::abbreviation_joule(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_joule>(new_prefix, new_scale)
	{
	}

	int abbreviation_joule::get_enum_type() const
	{
		return abbreviation_symbol::J;
	}

	const string abbreviation_joule::dimensions_match = "kg/m2*s2";
	const float abbreviation_joule::factor = 1;
	const string abbreviation_joule::name = "joule";
	const string abbreviation_joule::symbol = "J";

	abbreviation_watt::abbreviation_watt(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_watt>(new_prefix, new_scale)
	{
	}

	abbreviation_watt::abbreviation_watt(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_watt>(new_prefix, new_scale)
	{
	}

	int abbreviation_watt::get_enum_type() const
	{
		return abbreviation_symbol::W;
	}

	const string abbreviation_watt::dimensions_match = "kg/m2*s3";
	const float abbreviation_watt::factor = 1;
	const string abbreviation_watt::name = "watt";
	const string abbreviation_watt::symbol = "W";

	abbreviation_ampere::abbreviation_ampere(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_ampere>(new_prefix, new_scale)
	{
	}

	abbreviation_ampere::abbreviation_ampere(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_ampere>(new_prefix, new_scale)
	{
	}

	int abbreviation_ampere::get_enum_type() const
	{
		return abbreviation_symbol::A;
	}

	const string abbreviation_ampere::dimensions_match = "C/s";
	const float abbreviation_ampere::factor = 1;
	const string abbreviation_ampere::name = "ampere";
	const string abbreviation_ampere::symbol = "A";

	abbreviation_volt::abbreviation_volt(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_volt>(new_prefix, new_scale)
	{
	}

	abbreviation_volt::abbreviation_volt(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_volt>(new_prefix, new_scale)
	{
	}

	int abbreviation_volt::get_enum_type() const
	{
		return abbreviation_symbol::V;
	}

	const string abbreviation_volt::dimensions_match = "kg*m2/s3*A";
	const float abbreviation_volt::factor = 1;
	const string abbreviation_volt::name = "volt";
	const string abbreviation_volt::symbol = "V";

	abbreviation_farad::abbreviation_farad(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_farad>(new_prefix, new_scale)
	{
	}

	abbreviation_farad::abbreviation_farad(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_farad>(new_prefix, new_scale)
	{
	}

	int abbreviation_farad::get_enum_type() const
	{
		return abbreviation_symbol::F;
	}

	const string abbreviation_farad::dimensions_match = "s4*A2/kg*m2";
	const float abbreviation_farad::factor = 1;
	const string abbreviation_farad::name = "farad";
	const string abbreviation_farad::symbol = "F";

	abbreviation_ohm::abbreviation_ohm(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_ohm>(new_prefix, new_scale)
	{
	}

	abbreviation_ohm::abbreviation_ohm(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_ohm>(new_prefix, new_scale)
	{
	}

	int abbreviation_ohm::get_enum_type() const
	{
		return abbreviation_symbol::Ohm;
	}

	const string abbreviation_ohm::dimensions_match = "kg*m2/s3*A2";
	const float abbreviation_ohm::factor = 1;
	const string abbreviation_ohm::name = "ohm";
	const string abbreviation_ohm::symbol = "Ω";

	abbreviation_siemens::abbreviation_siemens(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_siemens>(new_prefix, new_scale)
	{
	}

	abbreviation_siemens::abbreviation_siemens(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_siemens>(new_prefix, new_scale)
	{
	}

	int abbreviation_siemens::get_enum_type() const
	{
		return abbreviation_symbol::S;
	}

	const string abbreviation_siemens::dimensions_match = "s3*A2/kg*m2";
	const float abbreviation_siemens::factor = 1;
	const string abbreviation_siemens::name = "siemens";
	const string abbreviation_siemens::symbol = "S";

	abbreviation_weber::abbreviation_weber(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_weber>(new_prefix, new_scale)
	{
	}

	abbreviation_weber::abbreviation_weber(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_weber>(new_prefix, new_scale)
	{
	}

	int abbreviation_weber::get_enum_type() const
	{
		return abbreviation_symbol::Wb;
	}

	const string abbreviation_weber::dimensions_match = "kg*m2/s2*A";
	const float abbreviation_weber::factor = 1;
	const string abbreviation_weber::name = "weber";
	const string abbreviation_weber::symbol = "Wb";

	abbreviation_tesla::abbreviation_tesla(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_tesla>(new_prefix, new_scale)
	{
	}

	abbreviation_tesla::abbreviation_tesla(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_tesla>(new_prefix, new_scale)
	{
	}

	int abbreviation_tesla::get_enum_type() const
	{
		return abbreviation_symbol::T;
	}

	const string abbreviation_tesla::dimensions_match = "kg/s2*A";
	const float abbreviation_tesla::factor = 1;
	const string abbreviation_tesla::name = "tesla";
	const string abbreviation_tesla::symbol = "T";

	abbreviation_henry::abbreviation_henry(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_henry>(new_prefix, new_scale)
	{
	}

	abbreviation_henry::abbreviation_henry(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_henry>(new_prefix, new_scale)
	{
	}

	int abbreviation_henry::get_enum_type() const
	{
		return abbreviation_symbol::H;
	}

	const string abbreviation_henry::dimensions_match = "kg*m2/s2*A2";
	const float abbreviation_henry::factor = 1;
	const string abbreviation_henry::name = "henry";
	const string abbreviation_henry::symbol = "H";

	abbreviation_lumen::abbreviation_lumen(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_lumen>(new_prefix, new_scale)
	{
	}

	abbreviation_lumen::abbreviation_lumen(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_lumen>(new_prefix, new_scale)
	{
	}

	int abbreviation_lumen::get_enum_type() const
	{
		return abbreviation_symbol::lm;
	}

	const string abbreviation_lumen::dimensions_match = "cd";
	const float abbreviation_lumen::factor = 1;
	const string abbreviation_lumen::name = "lumen";
	const string abbreviation_lumen::symbol = "lm";

	abbreviation_lux::abbreviation_lux(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_lux>(new_prefix, new_scale)
	{
	}

	abbreviation_lux::abbreviation_lux(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_lux>(new_prefix, new_scale)
	{
	}

	int abbreviation_lux::get_enum_type() const
	{
		return abbreviation_symbol::lx;
	}

	const string abbreviation_lux::dimensions_match = "cd/m2";
	const float abbreviation_lux::factor = 1;
	const string abbreviation_lux::name = "lux";
	const string abbreviation_lux::symbol = "lx";

	abbreviation_becquerel::abbreviation_becquerel(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_becquerel>(new_prefix, new_scale)
	{
	}

	abbreviation_becquerel::abbreviation_becquerel(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_becquerel>(new_prefix, new_scale)
	{
	}

	int abbreviation_becquerel::get_enum_type() const
	{
		return abbreviation_symbol::Bq;
	}

	const string abbreviation_becquerel::dimensions_match = "1/s";
	const float abbreviation_becquerel::factor = 1;
	const string abbreviation_becquerel::name = "becquerel";
	const string abbreviation_becquerel::symbol = "Bq";

	abbreviation_gray::abbreviation_gray(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_gray>(new_prefix, new_scale)
	{
	}

	abbreviation_gray::abbreviation_gray(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_gray>(new_prefix, new_scale)
	{
	}

	int abbreviation_gray::get_enum_type() const
	{
		return abbreviation_symbol::Gy;
	}

	const string abbreviation_gray::dimensions_match = "m2/s2";
	const float abbreviation_gray::factor = 1;
	const string abbreviation_gray::name = "gray";
	const string abbreviation_gray::symbol = "Gy";

	abbreviation_sievert::abbreviation_sievert(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_sievert>(new_prefix, new_scale)
	{
	}

	abbreviation_sievert::abbreviation_sievert(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_sievert>(new_prefix, new_scale)
	{
	}

	int abbreviation_sievert::get_enum_type() const
	{
		return abbreviation_symbol::Sv;
	}

	const string abbreviation_sievert::dimensions_match = "m2/s2";
	const float abbreviation_sievert::factor = 1;
	const string abbreviation_sievert::name = "sievert";
	const string abbreviation_sievert::symbol = "Sv";

	abbreviation_katal::abbreviation_katal(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_katal>(new_prefix, new_scale)
	{
	}

	abbreviation_katal::abbreviation_katal(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_katal>(new_prefix, new_scale)
	{
	}

	int abbreviation_katal::get_enum_type() const
	{
		return abbreviation_symbol::kat;
	}

	const string abbreviation_katal::dimensions_match = "mol/s";
	const float abbreviation_katal::factor = 1;
	const string abbreviation_katal::name = "katal";
	const string abbreviation_katal::symbol = "kat";

	abbreviation_angstrom::abbreviation_angstrom(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_angstrom>(new_prefix, new_scale)
	{
	}

	abbreviation_angstrom::abbreviation_angstrom(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_angstrom>(new_prefix, new_scale)
	{
	}

	int abbreviation_angstrom::get_enum_type() const
	{
		return abbreviation_symbol::angstrom;
	}

	const string abbreviation_angstrom::dimensions_match = "1/m10";
	const float abbreviation_angstrom::factor = 1;
	const string abbreviation_angstrom::name = "angstrom";
	const string abbreviation_angstrom::symbol = "Å";

	abbreviation_litre::abbreviation_litre(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_litre>(new_prefix, new_scale)
	{
	}

	abbreviation_litre::abbreviation_litre(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_litre>(new_prefix, new_scale)
	{
	}

	int abbreviation_litre::get_enum_type() const
	{
		return abbreviation_symbol::L;
	}

	const string abbreviation_litre::dimensions_match = "dm3";
	const float abbreviation_litre::factor = 1;
	const string abbreviation_litre::name = "litre";
	const string abbreviation_litre::symbol = "L";

	abbreviation_minute::abbreviation_minute(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_minute>(new_prefix, new_scale)
	{
	}

	abbreviation_minute::abbreviation_minute(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_minute>(new_prefix, new_scale)
	{
	}

	int abbreviation_minute::get_enum_type() const
	{
		return abbreviation_symbol::minute;
	}

	const string abbreviation_minute::dimensions_match = "s";
	const float abbreviation_minute::factor = 60;
	const string abbreviation_minute::name = "minute";
	const string abbreviation_minute::symbol = "min";

	abbreviation_hour::abbreviation_hour(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_hour>(new_prefix, new_scale)
	{
	}

	abbreviation_hour::abbreviation_hour(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_hour>(new_prefix, new_scale)
	{
	}

	int abbreviation_hour::get_enum_type() const
	{
		return abbreviation_symbol::h;
	}

	const string abbreviation_hour::dimensions_match = "s";
	const float abbreviation_hour::factor = 3600;
	const string abbreviation_hour::name = "hour";
	const string abbreviation_hour::symbol = "h";

	abbreviation_day::abbreviation_day(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_day>(new_prefix, new_scale)
	{
	}

	abbreviation_day::abbreviation_day(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_day>(new_prefix, new_scale)
	{
	}

	int abbreviation_day::get_enum_type() const
	{
		return abbreviation_symbol::d;
	}

	const string abbreviation_day::dimensions_match = "s";
	const float abbreviation_day::factor = 86400;
	const string abbreviation_day::name = "day";
	const string abbreviation_day::symbol = "d";

	abbreviation_astronomical_unit::abbreviation_astronomical_unit(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_astronomical_unit>(new_prefix, new_scale)
	{
	}

	abbreviation_astronomical_unit::abbreviation_astronomical_unit(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_astronomical_unit>(new_prefix, new_scale)
	{
	}

	int abbreviation_astronomical_unit::get_enum_type() const
	{
		return abbreviation_symbol::AU;
	}

	const string abbreviation_astronomical_unit::dimensions_match = "m";
	const float abbreviation_astronomical_unit::factor = 149597870700;
	const string abbreviation_astronomical_unit::name = "astronomical_unit";
	const string abbreviation_astronomical_unit::symbol = "AU";

	abbreviation_parsec::abbreviation_parsec(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_parsec>(new_prefix, new_scale)
	{
	}

	abbreviation_parsec::abbreviation_parsec(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_parsec>(new_prefix, new_scale)
	{
	}

	int abbreviation_parsec::get_enum_type() const
	{
		return abbreviation_symbol::pc;
	}

	const string abbreviation_parsec::dimensions_match = "m";
	const float abbreviation_parsec::factor = 30856775814913700;
	const string abbreviation_parsec::name = "parsec";
	const string abbreviation_parsec::symbol = "pc";

	abbreviation_electron_volt::abbreviation_electron_volt(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_electron_volt>(new_prefix, new_scale)
	{
	}

	abbreviation_electron_volt::abbreviation_electron_volt(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_electron_volt>(new_prefix, new_scale)
	{
	}

	int abbreviation_electron_volt::get_enum_type() const
	{
		return abbreviation_symbol::eV;
	}

	const string abbreviation_electron_volt::dimensions_match = "kg*m2/s2";
	const float abbreviation_electron_volt::factor = 1.60217656535/*e−19*/;
	const string abbreviation_electron_volt::name = "electron_volt";
	const string abbreviation_electron_volt::symbol = "eV";

	abbreviation_dalton::abbreviation_dalton(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_dalton>(new_prefix, new_scale)
	{
	}

	abbreviation_dalton::abbreviation_dalton(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_dalton>(new_prefix, new_scale)
	{
	}

	int abbreviation_dalton::get_enum_type() const
	{
		return abbreviation_symbol::Da;
	}

	const string abbreviation_dalton::dimensions_match = "kg";
	const float abbreviation_dalton::factor = 1.6605388628/*e−27*/;
	const string abbreviation_dalton::name = "dalton";
	const string abbreviation_dalton::symbol = "Da";

	abbreviation_amu::abbreviation_amu(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_amu>(new_prefix, new_scale)
	{
	}

	abbreviation_amu::abbreviation_amu(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_amu>(new_prefix, new_scale)
	{
	}

	int abbreviation_amu::get_enum_type() const
	{
		return abbreviation_symbol::amu;
	}

	const string abbreviation_amu::dimensions_match = "g";
	const float abbreviation_amu::factor = 1.6605388628/*e−27*/;
	const string abbreviation_amu::name = "amu";
	const string abbreviation_amu::symbol = "amu";

	abbreviation_barn::abbreviation_barn(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_barn>(new_prefix, new_scale)
	{
	}

	abbreviation_barn::abbreviation_barn(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_barn>(new_prefix, new_scale)
	{
	}

	int abbreviation_barn::get_enum_type() const
	{
		return abbreviation_symbol::barn;
	}

	const string abbreviation_barn::dimensions_match = "m2";
	const float abbreviation_barn::factor = 10 ^ -28;
	const string abbreviation_barn::name = "barn";
	const string abbreviation_barn::symbol = "b";

	abbreviation_molarity::abbreviation_molarity(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_molarity>(new_prefix, new_scale)
	{
	}

	abbreviation_molarity::abbreviation_molarity(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_molarity>(new_prefix, new_scale)
	{
	}

	int abbreviation_molarity::get_enum_type() const
	{
		return abbreviation_symbol::M;
	}

	const string abbreviation_molarity::dimensions_match = "mol/L";
	const float abbreviation_molarity::factor = 1;
	const string abbreviation_molarity::name = "molarity";
	const string abbreviation_molarity::symbol = "M";

	abbreviation_particles::abbreviation_particles(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_particles>(new_prefix, new_scale)
	{
	}

	abbreviation_particles::abbreviation_particles(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_particles>(new_prefix, new_scale)
	{
	}

	int abbreviation_particles::get_enum_type() const
	{
		return abbreviation_symbol::particles;
	}

	const string abbreviation_particles::dimensions_match = "mol";
	const float abbreviation_particles::factor = 1/chemistry::avogadro_constant;
	const string abbreviation_particles::name = "particles";
	const string abbreviation_particles::symbol = "particles";

	abbreviation_ppm::abbreviation_ppm(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_ppm>(new_prefix, new_scale)
	{
	}

	abbreviation_ppm::abbreviation_ppm(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_ppm>(new_prefix, new_scale)
	{
	}

	int abbreviation_ppm::get_enum_type() const
	{
		return abbreviation_symbol::ppm;
	}

	const string abbreviation_ppm::dimensions_match = "g/g";
	const float abbreviation_ppm::factor = 1/10^6;
	const string abbreviation_ppm::name = "parts per million";
	const string abbreviation_ppm::symbol = "ppm";

	abbreviation_ppb::abbreviation_ppb(prefix_symbol new_prefix, int new_scale) : abbreviation_crtp<abbreviation_ppb>(new_prefix, new_scale)
	{
	}

	abbreviation_ppb::abbreviation_ppb(prefix& new_prefix, int new_scale) : abbreviation_crtp<abbreviation_ppb>(new_prefix, new_scale)
	{
	}

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

	abbreviation* create_abbreviation(string x)
	{
		prefix* new_prefix;
		string abbreviation_name;
		string prefix_name;
		set<string> prefixes_options {"Y", "E", "P", "T", "G", "M", "k", "h", "d", "c", "m", "u", "n", "p", "f", "a", "z", "y"};
		if(prefixes_options.count(x.substr(0,1)) and x.substr(0,9) != "particles" and x.substr(0,3) != "ppm" and x.substr(0,3) != "ppb" and x.substr(0,3) != "min" and x != "h" and x != "d")
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
		else if(abbreviation_name == "L")
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
