#include "unit_basic.hpp"
#include "unit.hpp"
#include "dimension.hpp"
#include "prefix.hpp"
#include "math/number/unit_number.hpp"

#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <type_traits>

using namespace std;

namespace physics::units
{
	const string length::dimensions_match = "m";
	const vector_real_dimensions length::real_dimensions = create_real_dimensions(length::dimensions_match);

	const string time::dimensions_match = "s";
	const vector_real_dimensions time::real_dimensions = create_real_dimensions(time::dimensions_match);

	void time::change_display(physics::units::display_mode new_display_mode)
	{
		display_mode = new_display_mode;
	}

	const string mass::dimensions_match = "g";
	const vector_real_dimensions mass::real_dimensions = create_real_dimensions(mass::dimensions_match);

	const string charge::dimensions_match = "C";
	const vector_real_dimensions charge::real_dimensions = create_real_dimensions(charge::dimensions_match);

	temperature::temperature(string init_value) : scalar_unit_crtp<temperature>(init_value)
	{
		if(!isdigit(init_value[0]))
		{
			throw invalid_argument("Temperature string doesn't start with a digit");
		}
		else
		{
			int i = 0;
			while(isdigit(init_value[i]) || init_value[i] == '.')
			{
				i++;
			}
			if(init_value[i] != ' ')
			{
				throw invalid_argument("Temperature string must have the value separated from units with a single space");
			}
			string unit_string = init_value.substr(i+1);
			int j = 0;
			prefix* new_prefix;
			string final_string;
			if (unit_string.size() > 2)
			{
				while(unit_string.substr(j).size() != 2)
				{
					j++;
				}
				new_prefix = create_prefix(unit_string.substr(0,j));
				final_string = unit_string.substr(j);
			}
			else
			{
				new_prefix = new prefix_normal();
				final_string = unit_string;
			}
			math::number::unit_number new_value = 0;
			vector_real_dimensions new_real_dimensions = vector_real_dimensions();
			vector_actual_dimensions new_actual_dimensions = vector_actual_dimensions();
			dimension* new_real_dimension = new dimension_temperature(*new_prefix);
			dimension_abstract* new_actual_dimension = new dimension_temperature(*new_prefix);
			if (final_string == "°C")
			{
				new_value = stold(init_value.substr(0,i)) + 273.15;
				new_real_dimensions[K] = shared_ptr<dimension>(new_real_dimension);
				new_actual_dimensions[K] = shared_ptr<dimension_abstract>(new_actual_dimension);
			}
			else if (final_string == "°F")
			{
				new_value = (stold(init_value.substr(0,i)) - 32)*5/9 + 273.15;
				new_real_dimensions[K] = shared_ptr<dimension>(new_real_dimension);
				new_actual_dimensions[K] = shared_ptr<dimension_abstract>(new_actual_dimension);
			}
			else
			{
				throw invalid_argument("Temperature string does not contains °C or °F");
			}
			*this = auto_unit(new_value,new_real_dimensions,new_actual_dimensions);
		}
	}

	const string temperature::dimensions_match = "K";
	const vector_real_dimensions temperature::real_dimensions = create_real_dimensions(temperature::dimensions_match);

	void temperature::add_prefix(shared_ptr<prefix> prefix)
	{
		if(prefix->get_conversion_factor() > 0)
		{
			add_prefix(prefix);
		}
		else
		{
			invalidate(12);
		}
	}

	const string mole::dimensions_match = "mol";
	const vector_real_dimensions mole::real_dimensions = create_real_dimensions(mole::dimensions_match);

	const string light::dimensions_match = "cd";
	const vector_real_dimensions light::real_dimensions = create_real_dimensions(light::dimensions_match);

	const string data::dimensions_match = "B";
	const vector_real_dimensions data::real_dimensions = create_real_dimensions(data::dimensions_match);
}

wostream& operator <<(wostream& os, const physics::units::time& x)
{
	if (x.get_display_mode() == physics::units::display_mode::time_display)
	{
		wostringstream output;
		physics::units::time remaining_time = x;
		physics::units::time one_year("365 day");
		/*if (x > one_year)
		{
			output << int(trunc(x / one_year)) << L"y ";
			remaining_time -= one_year;
		}
		physics::units::time one_month("30 day");
		if (remaining_time > one_month)
		{
			output << int(trunc(remaining_time / one_month)) << L"m ";
			remaining_time -= one_month;
		}
		physics::units::time one_day("1 day");
		if (remaining_time > one_day)
		{
			output << int(trunc(remaining_time / one_day)) << L"d ";
			remaining_time -= one_day;
		}
		physics::units::time one_hour("1 hour");
		if (remaining_time > one_hour)
		{
			remaining_time.change_dimensions("hour");
			output << int(remaining_time.get_value()) << L"h ";
			remaining_time -= one_hour;
		}
		physics::units::time one_minute("1 min");
		if (remaining_time > one_minute)
		{
			remaining_time.change_dimensions("min");
			output << int(remaining_time.get_value()) << L"min ";
			remaining_time -= one_minute;
		}
		remaining_time.change_dimensions("s");
		output << remaining_time.get_value() << L"s ";*/

		return os << output.str();
	}
	else
	{
		return os << static_cast<const physics::units::unit&>(x);
	}
}

physics::units::auto_unit operator"" _Ym(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Ym");
}

physics::units::auto_unit operator"" _Zm(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Zm");
}

physics::units::auto_unit operator"" _Em(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Em");
}

physics::units::auto_unit operator"" _Pm(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Pm");
}

physics::units::auto_unit operator"" _Tm(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Tm");
}

physics::units::auto_unit operator"" _Gm(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Gm");
}

physics::units::auto_unit operator"" _Mm(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Mm");
}

physics::units::auto_unit operator"" _km(unsigned long long int x)
{
	return physics::units::auto_unit(x, "km");
}

physics::units::auto_unit operator"" _hm(unsigned long long int x)
{
	return physics::units::auto_unit(x, "hm");
}

physics::units::auto_unit operator"" _dam(unsigned long long int x)
{
	return physics::units::auto_unit(x, "dam");
}

physics::units::auto_unit operator"" _m(unsigned long long int x)
{
	return physics::units::auto_unit(x, "m");
}

physics::units::auto_unit operator"" _dm(unsigned long long int x)
{
	return physics::units::auto_unit(x, "dm");
}

physics::units::auto_unit operator"" _cm(unsigned long long int x)
{
	return physics::units::auto_unit(x, "cm");
}

physics::units::auto_unit operator"" _mm(unsigned long long int x)
{
	return physics::units::auto_unit(x, "mm");
}

physics::units::auto_unit operator"" _um(unsigned long long int x)
{
	return physics::units::auto_unit(x, "um");
}

physics::units::auto_unit operator"" _nm(unsigned long long int x)
{
	return physics::units::auto_unit(x, "nm");
}

physics::units::auto_unit operator"" _pm(unsigned long long int x)
{
	return physics::units::auto_unit(x, "pm");
}

physics::units::auto_unit operator"" _fm(unsigned long long int x)
{
	return physics::units::auto_unit(x, "fm");
}

physics::units::auto_unit operator"" _am(unsigned long long int x)
{
	return physics::units::auto_unit(x, "am");
}

physics::units::auto_unit operator"" _zm(unsigned long long int x)
{
	return physics::units::auto_unit(x, "zm");
}

physics::units::auto_unit operator"" _ym(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ym");
}

physics::units::auto_unit operator"" _s(unsigned long long int x)
{
	return physics::units::auto_unit(x, "s");
}

physics::units::auto_unit operator"" _ds(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ds");
}

physics::units::auto_unit operator"" _cs(unsigned long long int x)
{
	return physics::units::auto_unit(x, "cs");
}

physics::units::auto_unit operator"" _ss(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ss");
}

physics::units::auto_unit operator"" _us(unsigned long long int x)
{
	return physics::units::auto_unit(x, "us");
}

physics::units::auto_unit operator"" _ns(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ns");
}

physics::units::auto_unit operator"" _ps(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ps");
}

physics::units::auto_unit operator"" _fs(unsigned long long int x)
{
	return physics::units::auto_unit(x, "fs");
}

physics::units::auto_unit operator"" _as(unsigned long long int x)
{
	return physics::units::auto_unit(x, "as");
}

physics::units::auto_unit operator"" _zs(unsigned long long int x)
{
	return physics::units::auto_unit(x, "zs");
}

physics::units::auto_unit operator"" _ys(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ys");
}

physics::units::auto_unit operator"" _Yg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Yg");
}

physics::units::auto_unit operator"" _Zg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Zg");
}

physics::units::auto_unit operator"" _Eg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Eg");
}

physics::units::auto_unit operator"" _Pg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Pg");
}

physics::units::auto_unit operator"" _Tg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Tg");
}

physics::units::auto_unit operator"" _Gg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Gg");
}

physics::units::auto_unit operator"" _Mg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Mg");
}

physics::units::auto_unit operator"" _kg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "kg");
}

physics::units::auto_unit operator"" _hg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "hg");
}

physics::units::auto_unit operator"" _dag(unsigned long long int x)
{
	return physics::units::auto_unit(x, "dag");
}

physics::units::auto_unit operator"" _g(unsigned long long int x)
{
	return physics::units::auto_unit(x, "g");
}

physics::units::auto_unit operator"" _dg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "dg");
}

physics::units::auto_unit operator"" _cg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "cg");
}

physics::units::auto_unit operator"" _gg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "gg");
}

physics::units::auto_unit operator"" _ug(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ug");
}

physics::units::auto_unit operator"" _ng(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ng");
}

physics::units::auto_unit operator"" _pg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "pg");
}

physics::units::auto_unit operator"" _fg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "fg");
}

physics::units::auto_unit operator"" _ag(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ag");
}

physics::units::auto_unit operator"" _zg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "zg");
}

physics::units::auto_unit operator"" _yg(unsigned long long int x)
{
	return physics::units::auto_unit(x, "yg");
}

physics::units::auto_unit operator"" _YC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "YC");
}

physics::units::auto_unit operator"" _ZC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ZC");
}

physics::units::auto_unit operator"" _EC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "EC");
}

physics::units::auto_unit operator"" _PC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "PC");
}

physics::units::auto_unit operator"" _TC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "TC");
}

physics::units::auto_unit operator"" _GC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "GC");
}

physics::units::auto_unit operator"" _MC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "MC");
}

physics::units::auto_unit operator"" _kC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "kC");
}

physics::units::auto_unit operator"" _hC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "hC");
}

physics::units::auto_unit operator"" _daC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "daC");
}

physics::units::auto_unit operator"" _C(unsigned long long int x)
{
	return physics::units::auto_unit(x, "C");
}

physics::units::auto_unit operator"" _dC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "dC");
}

physics::units::auto_unit operator"" _cC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "cC");
}

physics::units::auto_unit operator"" _CC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "CC");
}

physics::units::auto_unit operator"" _uC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "uC");
}

physics::units::auto_unit operator"" _nC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "nC");
}

physics::units::auto_unit operator"" _pC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "pC");
}

physics::units::auto_unit operator"" _fC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "fC");
}

physics::units::auto_unit operator"" _aC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "aC");
}

physics::units::auto_unit operator"" _zC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "zC");
}

physics::units::auto_unit operator"" _yC(unsigned long long int x)
{
	return physics::units::auto_unit(x, "yC");
}

physics::units::auto_unit operator"" _YK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "YK");
}

physics::units::auto_unit operator"" _ZK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ZK");
}

physics::units::auto_unit operator"" _EK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "EK");
}

physics::units::auto_unit operator"" _PK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "PK");
}

physics::units::auto_unit operator"" _TK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "TK");
}

physics::units::auto_unit operator"" _GK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "GK");
}

physics::units::auto_unit operator"" _MK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "MK");
}

physics::units::auto_unit operator"" _kK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "kK");
}

physics::units::auto_unit operator"" _hK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "hK");
}

physics::units::auto_unit operator"" _daK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "daK");
}

physics::units::auto_unit operator"" _K(unsigned long long int x)
{
	return physics::units::auto_unit(x, "K");
}

physics::units::auto_unit operator"" _dK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "dK");
}

physics::units::auto_unit operator"" _cK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "cK");
}

physics::units::auto_unit operator"" _KK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "KK");
}

physics::units::auto_unit operator"" _uK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "uK");
}

physics::units::auto_unit operator"" _nK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "nK");
}

physics::units::auto_unit operator"" _pK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "pK");
}

physics::units::auto_unit operator"" _fK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "fK");
}

physics::units::auto_unit operator"" _aK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "aK");
}

physics::units::auto_unit operator"" _zK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "zK");
}

physics::units::auto_unit operator"" _yK(unsigned long long int x)
{
	return physics::units::auto_unit(x, "yK");
}

physics::units::auto_unit operator"" _Ymol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Ymol");
}

physics::units::auto_unit operator"" _Zmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Zmol");
}

physics::units::auto_unit operator"" _Emol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Emol");
}

physics::units::auto_unit operator"" _Pmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Pmol");
}

physics::units::auto_unit operator"" _Tmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Tmol");
}

physics::units::auto_unit operator"" _Gmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Gmol");
}

physics::units::auto_unit operator"" _Mmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Mmol");
}

physics::units::auto_unit operator"" _kmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "kmol");
}

physics::units::auto_unit operator"" _hmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "hmol");
}

physics::units::auto_unit operator"" _damol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "damol");
}

physics::units::auto_unit operator"" _mol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "mol");
}

physics::units::auto_unit operator"" _dmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "dmol");
}

physics::units::auto_unit operator"" _cmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "cmol");
}

physics::units::auto_unit operator"" _molmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "molmol");
}

physics::units::auto_unit operator"" _umol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "umol");
}

physics::units::auto_unit operator"" _nmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "nmol");
}

physics::units::auto_unit operator"" _pmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "pmol");
}

physics::units::auto_unit operator"" _fmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "fmol");
}

physics::units::auto_unit operator"" _amol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "amol");
}

physics::units::auto_unit operator"" _zmol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "zmol");
}

physics::units::auto_unit operator"" _ymol(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ymol");
}

physics::units::auto_unit operator"" _Ycd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Ycd");
}

physics::units::auto_unit operator"" _Zcd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Zcd");
}

physics::units::auto_unit operator"" _Ecd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Ecd");
}

physics::units::auto_unit operator"" _Pcd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Pcd");
}

physics::units::auto_unit operator"" _Tcd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Tcd");
}

physics::units::auto_unit operator"" _Gcd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Gcd");
}

physics::units::auto_unit operator"" _Mcd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "Mcd");
}

physics::units::auto_unit operator"" _kcd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "kcd");
}

physics::units::auto_unit operator"" _hcd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "hcd");
}

physics::units::auto_unit operator"" _dacd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "dacd");
}

physics::units::auto_unit operator"" _cd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "cd");
}

physics::units::auto_unit operator"" _dcd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "dcd");
}

physics::units::auto_unit operator"" _ccd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ccd");
}

physics::units::auto_unit operator"" _cdcd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "cdcd");
}

physics::units::auto_unit operator"" _ucd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ucd");
}

physics::units::auto_unit operator"" _ncd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ncd");
}

physics::units::auto_unit operator"" _pcd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "pcd");
}

physics::units::auto_unit operator"" _fcd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "fcd");
}

physics::units::auto_unit operator"" _acd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "acd");
}

physics::units::auto_unit operator"" _zcd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "zcd");
}

physics::units::auto_unit operator"" _ycd(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ycd");
}

physics::units::auto_unit operator"" _angle(unsigned long long int x)
{
	return physics::units::auto_unit(x, "angle");
}

physics::units::auto_unit operator"" _solid_angle(unsigned long long int x)
{
	return physics::units::auto_unit(x, "solid_angle");
}

physics::units::auto_unit operator"" _YB(unsigned long long int x)
{
	return physics::units::auto_unit(x, "YB");
}

physics::units::auto_unit operator"" _ZB(unsigned long long int x)
{
	return physics::units::auto_unit(x, "ZB");
}

physics::units::auto_unit operator"" _EB(unsigned long long int x)
{
	return physics::units::auto_unit(x, "EB");
}

physics::units::auto_unit operator"" _PB(unsigned long long int x)
{
	return physics::units::auto_unit(x, "PB");
}

physics::units::auto_unit operator"" _TB(unsigned long long int x)
{
	return physics::units::auto_unit(x, "TB");
}

physics::units::auto_unit operator"" _GB(unsigned long long int x)
{
	return physics::units::auto_unit(x, "GB");
}

physics::units::auto_unit operator"" _MB(unsigned long long int x)
{
	return physics::units::auto_unit(x, "MB");
}

physics::units::auto_unit operator"" _kB(unsigned long long int x)
{
	return physics::units::auto_unit(x, "kB");
}

physics::units::auto_unit operator"" _B(unsigned long long int x)
{
	return physics::units::auto_unit(x, "B");
}

physics::units::auto_unit operator"" _Ym(long double x)
{
	return physics::units::auto_unit(x, "Ym");
}

physics::units::auto_unit operator"" _Zm(long double x)
{
	return physics::units::auto_unit(x, "Zm");
}

physics::units::auto_unit operator"" _Em(long double x)
{
	return physics::units::auto_unit(x, "Em");
}

physics::units::auto_unit operator"" _Pm(long double x)
{
	return physics::units::auto_unit(x, "Pm");
}

physics::units::auto_unit operator"" _Tm(long double x)
{
	return physics::units::auto_unit(x, "Tm");
}

physics::units::auto_unit operator"" _Gm(long double x)
{
	return physics::units::auto_unit(x, "Gm");
}

physics::units::auto_unit operator"" _Mm(long double x)
{
	return physics::units::auto_unit(x, "Mm");
}

physics::units::auto_unit operator"" _km(long double x)
{
	return physics::units::auto_unit(x, "km");
}

physics::units::auto_unit operator"" _hm(long double x)
{
	return physics::units::auto_unit(x, "hm");
}

physics::units::auto_unit operator"" _dam(long double x)
{
	return physics::units::auto_unit(x, "dam");
}

physics::units::auto_unit operator"" _m(long double x)
{
	return physics::units::auto_unit(x, "m");
}

physics::units::auto_unit operator"" _dm(long double x)
{
	return physics::units::auto_unit(x, "dm");
}

physics::units::auto_unit operator"" _cm(long double x)
{
	return physics::units::auto_unit(x, "cm");
}

physics::units::auto_unit operator"" _mm(long double x)
{
	return physics::units::auto_unit(x, "mm");
}

physics::units::auto_unit operator"" _um(long double x)
{
	return physics::units::auto_unit(x, "um");
}

physics::units::auto_unit operator"" _nm(long double x)
{
	return physics::units::auto_unit(x, "nm");
}

physics::units::auto_unit operator"" _pm(long double x)
{
	return physics::units::auto_unit(x, "pm");
}

physics::units::auto_unit operator"" _fm(long double x)
{
	return physics::units::auto_unit(x, "fm");
}

physics::units::auto_unit operator"" _am(long double x)
{
	return physics::units::auto_unit(x, "am");
}

physics::units::auto_unit operator"" _zm(long double x)
{
	return physics::units::auto_unit(x, "zm");
}

physics::units::auto_unit operator"" _ym(long double x)
{
	return physics::units::auto_unit(x, "ym");
}

physics::units::auto_unit operator"" _s(long double x)
{
	return physics::units::auto_unit(x, "s");
}

physics::units::auto_unit operator"" _ds(long double x)
{
	return physics::units::auto_unit(x, "ds");
}

physics::units::auto_unit operator"" _cs(long double x)
{
	return physics::units::auto_unit(x, "cs");
}

physics::units::auto_unit operator"" _ss(long double x)
{
	return physics::units::auto_unit(x, "ss");
}

physics::units::auto_unit operator"" _us(long double x)
{
	return physics::units::auto_unit(x, "us");
}

physics::units::auto_unit operator"" _ns(long double x)
{
	return physics::units::auto_unit(x, "ns");
}

physics::units::auto_unit operator"" _ps(long double x)
{
	return physics::units::auto_unit(x, "ps");
}

physics::units::auto_unit operator"" _fs(long double x)
{
	return physics::units::auto_unit(x, "fs");
}

physics::units::auto_unit operator"" _as(long double x)
{
	return physics::units::auto_unit(x, "as");
}

physics::units::auto_unit operator"" _zs(long double x)
{
	return physics::units::auto_unit(x, "zs");
}

physics::units::auto_unit operator"" _ys(long double x)
{
	return physics::units::auto_unit(x, "ys");
}

physics::units::auto_unit operator"" _Yg(long double x)
{
	return physics::units::auto_unit(x, "Yg");
}

physics::units::auto_unit operator"" _Zg(long double x)
{
	return physics::units::auto_unit(x, "Zg");
}

physics::units::auto_unit operator"" _Eg(long double x)
{
	return physics::units::auto_unit(x, "Eg");
}

physics::units::auto_unit operator"" _Pg(long double x)
{
	return physics::units::auto_unit(x, "Pg");
}

physics::units::auto_unit operator"" _Tg(long double x)
{
	return physics::units::auto_unit(x, "Tg");
}

physics::units::auto_unit operator"" _Gg(long double x)
{
	return physics::units::auto_unit(x, "Gg");
}

physics::units::auto_unit operator"" _Mg(long double x)
{
	return physics::units::auto_unit(x, "Mg");
}

physics::units::auto_unit operator"" _kg(long double x)
{
	return physics::units::auto_unit(x, "kg");
}

physics::units::auto_unit operator"" _hg(long double x)
{
	return physics::units::auto_unit(x, "hg");
}

physics::units::auto_unit operator"" _dag(long double x)
{
	return physics::units::auto_unit(x, "dag");
}

physics::units::auto_unit operator"" _g(long double x)
{
	return physics::units::auto_unit(x, "g");
}

physics::units::auto_unit operator"" _dg(long double x)
{
	return physics::units::auto_unit(x, "dg");
}

physics::units::auto_unit operator"" _cg(long double x)
{
	return physics::units::auto_unit(x, "cg");
}

physics::units::auto_unit operator"" _gg(long double x)
{
	return physics::units::auto_unit(x, "gg");
}

physics::units::auto_unit operator"" _ug(long double x)
{
	return physics::units::auto_unit(x, "ug");
}

physics::units::auto_unit operator"" _ng(long double x)
{
	return physics::units::auto_unit(x, "ng");
}

physics::units::auto_unit operator"" _pg(long double x)
{
	return physics::units::auto_unit(x, "pg");
}

physics::units::auto_unit operator"" _fg(long double x)
{
	return physics::units::auto_unit(x, "fg");
}

physics::units::auto_unit operator"" _ag(long double x)
{
	return physics::units::auto_unit(x, "ag");
}

physics::units::auto_unit operator"" _zg(long double x)
{
	return physics::units::auto_unit(x, "zg");
}

physics::units::auto_unit operator"" _yg(long double x)
{
	return physics::units::auto_unit(x, "yg");
}

physics::units::auto_unit operator"" _YC(long double x)
{
	return physics::units::auto_unit(x, "YC");
}

physics::units::auto_unit operator"" _ZC(long double x)
{
	return physics::units::auto_unit(x, "ZC");
}

physics::units::auto_unit operator"" _EC(long double x)
{
	return physics::units::auto_unit(x, "EC");
}

physics::units::auto_unit operator"" _PC(long double x)
{
	return physics::units::auto_unit(x, "PC");
}

physics::units::auto_unit operator"" _TC(long double x)
{
	return physics::units::auto_unit(x, "TC");
}

physics::units::auto_unit operator"" _GC(long double x)
{
	return physics::units::auto_unit(x, "GC");
}

physics::units::auto_unit operator"" _MC(long double x)
{
	return physics::units::auto_unit(x, "MC");
}

physics::units::auto_unit operator"" _kC(long double x)
{
	return physics::units::auto_unit(x, "kC");
}

physics::units::auto_unit operator"" _hC(long double x)
{
	return physics::units::auto_unit(x, "hC");
}

physics::units::auto_unit operator"" _daC(long double x)
{
	return physics::units::auto_unit(x, "daC");
}

physics::units::auto_unit operator"" _C(long double x)
{
	return physics::units::auto_unit(x, "C");
}

physics::units::auto_unit operator"" _dC(long double x)
{
	return physics::units::auto_unit(x, "dC");
}

physics::units::auto_unit operator"" _cC(long double x)
{
	return physics::units::auto_unit(x, "cC");
}

physics::units::auto_unit operator"" _CC(long double x)
{
	return physics::units::auto_unit(x, "CC");
}

physics::units::auto_unit operator"" _uC(long double x)
{
	return physics::units::auto_unit(x, "uC");
}

physics::units::auto_unit operator"" _nC(long double x)
{
	return physics::units::auto_unit(x, "nC");
}

physics::units::auto_unit operator"" _pC(long double x)
{
	return physics::units::auto_unit(x, "pC");
}

physics::units::auto_unit operator"" _fC(long double x)
{
	return physics::units::auto_unit(x, "fC");
}

physics::units::auto_unit operator"" _aC(long double x)
{
	return physics::units::auto_unit(x, "aC");
}

physics::units::auto_unit operator"" _zC(long double x)
{
	return physics::units::auto_unit(x, "zC");
}

physics::units::auto_unit operator"" _yC(long double x)
{
	return physics::units::auto_unit(x, "yC");
}

physics::units::auto_unit operator"" _YK(long double x)
{
	return physics::units::auto_unit(x, "YK");
}

physics::units::auto_unit operator"" _ZK(long double x)
{
	return physics::units::auto_unit(x, "ZK");
}

physics::units::auto_unit operator"" _EK(long double x)
{
	return physics::units::auto_unit(x, "EK");
}

physics::units::auto_unit operator"" _PK(long double x)
{
	return physics::units::auto_unit(x, "PK");
}

physics::units::auto_unit operator"" _TK(long double x)
{
	return physics::units::auto_unit(x, "TK");
}

physics::units::auto_unit operator"" _GK(long double x)
{
	return physics::units::auto_unit(x, "GK");
}

physics::units::auto_unit operator"" _MK(long double x)
{
	return physics::units::auto_unit(x, "MK");
}

physics::units::auto_unit operator"" _kK(long double x)
{
	return physics::units::auto_unit(x, "kK");
}

physics::units::auto_unit operator"" _hK(long double x)
{
	return physics::units::auto_unit(x, "hK");
}

physics::units::auto_unit operator"" _daK(long double x)
{
	return physics::units::auto_unit(x, "daK");
}

physics::units::auto_unit operator"" _K(long double x)
{
	return physics::units::auto_unit(x, "K");
}

physics::units::auto_unit operator"" _dK(long double x)
{
	return physics::units::auto_unit(x, "dK");
}

physics::units::auto_unit operator"" _cK(long double x)
{
	return physics::units::auto_unit(x, "cK");
}

physics::units::auto_unit operator"" _KK(long double x)
{
	return physics::units::auto_unit(x, "KK");
}

physics::units::auto_unit operator"" _uK(long double x)
{
	return physics::units::auto_unit(x, "uK");
}

physics::units::auto_unit operator"" _nK(long double x)
{
	return physics::units::auto_unit(x, "nK");
}

physics::units::auto_unit operator"" _pK(long double x)
{
	return physics::units::auto_unit(x, "pK");
}

physics::units::auto_unit operator"" _fK(long double x)
{
	return physics::units::auto_unit(x, "fK");
}

physics::units::auto_unit operator"" _aK(long double x)
{
	return physics::units::auto_unit(x, "aK");
}

physics::units::auto_unit operator"" _zK(long double x)
{
	return physics::units::auto_unit(x, "zK");
}

physics::units::auto_unit operator"" _yK(long double x)
{
	return physics::units::auto_unit(x, "yK");
}

physics::units::auto_unit operator"" _Ymol(long double x)
{
	return physics::units::auto_unit(x, "Ymol");
}

physics::units::auto_unit operator"" _Zmol(long double x)
{
	return physics::units::auto_unit(x, "Zmol");
}

physics::units::auto_unit operator"" _Emol(long double x)
{
	return physics::units::auto_unit(x, "Emol");
}

physics::units::auto_unit operator"" _Pmol(long double x)
{
	return physics::units::auto_unit(x, "Pmol");
}

physics::units::auto_unit operator"" _Tmol(long double x)
{
	return physics::units::auto_unit(x, "Tmol");
}

physics::units::auto_unit operator"" _Gmol(long double x)
{
	return physics::units::auto_unit(x, "Gmol");
}

physics::units::auto_unit operator"" _Mmol(long double x)
{
	return physics::units::auto_unit(x, "Mmol");
}

physics::units::auto_unit operator"" _kmol(long double x)
{
	return physics::units::auto_unit(x, "kmol");
}

physics::units::auto_unit operator"" _hmol(long double x)
{
	return physics::units::auto_unit(x, "hmol");
}

physics::units::auto_unit operator"" _damol(long double x)
{
	return physics::units::auto_unit(x, "damol");
}

physics::units::auto_unit operator"" _mol(long double x)
{
	return physics::units::auto_unit(x, "mol");
}

physics::units::auto_unit operator"" _dmol(long double x)
{
	return physics::units::auto_unit(x, "dmol");
}

physics::units::auto_unit operator"" _cmol(long double x)
{
	return physics::units::auto_unit(x, "cmol");
}

physics::units::auto_unit operator"" _molmol(long double x)
{
	return physics::units::auto_unit(x, "molmol");
}

physics::units::auto_unit operator"" _umol(long double x)
{
	return physics::units::auto_unit(x, "umol");
}

physics::units::auto_unit operator"" _nmol(long double x)
{
	return physics::units::auto_unit(x, "nmol");
}

physics::units::auto_unit operator"" _pmol(long double x)
{
	return physics::units::auto_unit(x, "pmol");
}

physics::units::auto_unit operator"" _fmol(long double x)
{
	return physics::units::auto_unit(x, "fmol");
}

physics::units::auto_unit operator"" _amol(long double x)
{
	return physics::units::auto_unit(x, "amol");
}

physics::units::auto_unit operator"" _zmol(long double x)
{
	return physics::units::auto_unit(x, "zmol");
}

physics::units::auto_unit operator"" _ymol(long double x)
{
	return physics::units::auto_unit(x, "ymol");
}

physics::units::auto_unit operator"" _Ycd(long double x)
{
	return physics::units::auto_unit(x, "Ycd");
}

physics::units::auto_unit operator"" _Zcd(long double x)
{
	return physics::units::auto_unit(x, "Zcd");
}

physics::units::auto_unit operator"" _Ecd(long double x)
{
	return physics::units::auto_unit(x, "Ecd");
}

physics::units::auto_unit operator"" _Pcd(long double x)
{
	return physics::units::auto_unit(x, "Pcd");
}

physics::units::auto_unit operator"" _Tcd(long double x)
{
	return physics::units::auto_unit(x, "Tcd");
}

physics::units::auto_unit operator"" _Gcd(long double x)
{
	return physics::units::auto_unit(x, "Gcd");
}

physics::units::auto_unit operator"" _Mcd(long double x)
{
	return physics::units::auto_unit(x, "Mcd");
}

physics::units::auto_unit operator"" _kcd(long double x)
{
	return physics::units::auto_unit(x, "kcd");
}

physics::units::auto_unit operator"" _hcd(long double x)
{
	return physics::units::auto_unit(x, "hcd");
}

physics::units::auto_unit operator"" _dacd(long double x)
{
	return physics::units::auto_unit(x, "dacd");
}

physics::units::auto_unit operator"" _cd(long double x)
{
	return physics::units::auto_unit(x, "cd");
}

physics::units::auto_unit operator"" _dcd(long double x)
{
	return physics::units::auto_unit(x, "dcd");
}

physics::units::auto_unit operator"" _ccd(long double x)
{
	return physics::units::auto_unit(x, "ccd");
}

physics::units::auto_unit operator"" _cdcd(long double x)
{
	return physics::units::auto_unit(x, "cdcd");
}

physics::units::auto_unit operator"" _ucd(long double x)
{
	return physics::units::auto_unit(x, "ucd");
}

physics::units::auto_unit operator"" _ncd(long double x)
{
	return physics::units::auto_unit(x, "ncd");
}

physics::units::auto_unit operator"" _pcd(long double x)
{
	return physics::units::auto_unit(x, "pcd");
}

physics::units::auto_unit operator"" _fcd(long double x)
{
	return physics::units::auto_unit(x, "fcd");
}

physics::units::auto_unit operator"" _acd(long double x)
{
	return physics::units::auto_unit(x, "acd");
}

physics::units::auto_unit operator"" _zcd(long double x)
{
	return physics::units::auto_unit(x, "zcd");
}

physics::units::auto_unit operator"" _ycd(long double x)
{
	return physics::units::auto_unit(x, "ycd");
}

physics::units::auto_unit operator"" _angle(long double x)
{
	return physics::units::auto_unit(x, "angle");
}

physics::units::auto_unit operator"" _solid_angle(long double x)
{
	return physics::units::auto_unit(x, "solid_angle");
}

physics::units::auto_unit operator"" _YB(long double x)
{
	return physics::units::auto_unit(x, "YB");
}

physics::units::auto_unit operator"" _ZB(long double x)
{
	return physics::units::auto_unit(x, "ZB");
}

physics::units::auto_unit operator"" _EB(long double x)
{
	return physics::units::auto_unit(x, "EB");
}

physics::units::auto_unit operator"" _PB(long double x)
{
	return physics::units::auto_unit(x, "PB");
}

physics::units::auto_unit operator"" _TB(long double x)
{
	return physics::units::auto_unit(x, "TB");
}

physics::units::auto_unit operator"" _GB(long double x)
{
	return physics::units::auto_unit(x, "GB");
}

physics::units::auto_unit operator"" _MB(long double x)
{
	return physics::units::auto_unit(x, "MB");
}

physics::units::auto_unit operator"" _kB(long double x)
{
	return physics::units::auto_unit(x, "kB");
}

physics::units::auto_unit operator"" _B(long double x)
{
	return physics::units::auto_unit(x, "B");
}
