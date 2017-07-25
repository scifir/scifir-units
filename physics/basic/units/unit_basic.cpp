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

	const string time::dimensions_match = "s";


	const string mass::dimensions_match = "g";

	const string charge::dimensions_match = "C";

	temperature::temperature(string init_value) : scalar_unit<temperature>()
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
			unit_real_dimensions new_real_dimensions = unit_real_dimensions();
			unit_actual_dimensions new_actual_dimensions = unit_actual_dimensions();
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
			*this = unit(new_value,new_real_dimensions,new_actual_dimensions);
		}
	}

	const string temperature::dimensions_match = "K";

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

	const string light::dimensions_match = "cd";

	const string data::dimensions_match = "B";
}

physics::units::unit operator"" _Ym(unsigned long long int x)
{
	return physics::units::unit(x, "Ym");
}

physics::units::unit operator"" _Zm(unsigned long long int x)
{
	return physics::units::unit(x, "Zm");
}

physics::units::unit operator"" _Em(unsigned long long int x)
{
	return physics::units::unit(x, "Em");
}

physics::units::unit operator"" _Pm(unsigned long long int x)
{
	return physics::units::unit(x, "Pm");
}

physics::units::unit operator"" _Tm(unsigned long long int x)
{
	return physics::units::unit(x, "Tm");
}

physics::units::unit operator"" _Gm(unsigned long long int x)
{
	return physics::units::unit(x, "Gm");
}

physics::units::unit operator"" _Mm(unsigned long long int x)
{
	return physics::units::unit(x, "Mm");
}

physics::units::unit operator"" _km(unsigned long long int x)
{
	return physics::units::unit(x, "km");
}

physics::units::unit operator"" _hm(unsigned long long int x)
{
	return physics::units::unit(x, "hm");
}

physics::units::unit operator"" _dam(unsigned long long int x)
{
	return physics::units::unit(x, "dam");
}

physics::units::unit operator"" _m(unsigned long long int x)
{
	return physics::units::unit(x, "m");
}

physics::units::unit operator"" _dm(unsigned long long int x)
{
	return physics::units::unit(x, "dm");
}

physics::units::unit operator"" _cm(unsigned long long int x)
{
	return physics::units::unit(x, "cm");
}

physics::units::unit operator"" _mm(unsigned long long int x)
{
	return physics::units::unit(x, "mm");
}

physics::units::unit operator"" _um(unsigned long long int x)
{
	return physics::units::unit(x, "um");
}

physics::units::unit operator"" _nm(unsigned long long int x)
{
	return physics::units::unit(x, "nm");
}

physics::units::unit operator"" _pm(unsigned long long int x)
{
	return physics::units::unit(x, "pm");
}

physics::units::unit operator"" _fm(unsigned long long int x)
{
	return physics::units::unit(x, "fm");
}

physics::units::unit operator"" _am(unsigned long long int x)
{
	return physics::units::unit(x, "am");
}

physics::units::unit operator"" _zm(unsigned long long int x)
{
	return physics::units::unit(x, "zm");
}

physics::units::unit operator"" _ym(unsigned long long int x)
{
	return physics::units::unit(x, "ym");
}

physics::units::unit operator"" _s(unsigned long long int x)
{
	return physics::units::unit(x, "s");
}

physics::units::unit operator"" _ds(unsigned long long int x)
{
	return physics::units::unit(x, "ds");
}

physics::units::unit operator"" _cs(unsigned long long int x)
{
	return physics::units::unit(x, "cs");
}

physics::units::unit operator"" _ss(unsigned long long int x)
{
	return physics::units::unit(x, "ss");
}

physics::units::unit operator"" _us(unsigned long long int x)
{
	return physics::units::unit(x, "us");
}

physics::units::unit operator"" _ns(unsigned long long int x)
{
	return physics::units::unit(x, "ns");
}

physics::units::unit operator"" _ps(unsigned long long int x)
{
	return physics::units::unit(x, "ps");
}

physics::units::unit operator"" _fs(unsigned long long int x)
{
	return physics::units::unit(x, "fs");
}

physics::units::unit operator"" _as(unsigned long long int x)
{
	return physics::units::unit(x, "as");
}

physics::units::unit operator"" _zs(unsigned long long int x)
{
	return physics::units::unit(x, "zs");
}

physics::units::unit operator"" _ys(unsigned long long int x)
{
	return physics::units::unit(x, "ys");
}

physics::units::unit operator"" _Yg(unsigned long long int x)
{
	return physics::units::unit(x, "Yg");
}

physics::units::unit operator"" _Zg(unsigned long long int x)
{
	return physics::units::unit(x, "Zg");
}

physics::units::unit operator"" _Eg(unsigned long long int x)
{
	return physics::units::unit(x, "Eg");
}

physics::units::unit operator"" _Pg(unsigned long long int x)
{
	return physics::units::unit(x, "Pg");
}

physics::units::unit operator"" _Tg(unsigned long long int x)
{
	return physics::units::unit(x, "Tg");
}

physics::units::unit operator"" _Gg(unsigned long long int x)
{
	return physics::units::unit(x, "Gg");
}

physics::units::unit operator"" _Mg(unsigned long long int x)
{
	return physics::units::unit(x, "Mg");
}

physics::units::unit operator"" _kg(unsigned long long int x)
{
	return physics::units::unit(x, "kg");
}

physics::units::unit operator"" _hg(unsigned long long int x)
{
	return physics::units::unit(x, "hg");
}

physics::units::unit operator"" _dag(unsigned long long int x)
{
	return physics::units::unit(x, "dag");
}

physics::units::unit operator"" _g(unsigned long long int x)
{
	return physics::units::unit(x, "g");
}

physics::units::unit operator"" _dg(unsigned long long int x)
{
	return physics::units::unit(x, "dg");
}

physics::units::unit operator"" _cg(unsigned long long int x)
{
	return physics::units::unit(x, "cg");
}

physics::units::unit operator"" _gg(unsigned long long int x)
{
	return physics::units::unit(x, "gg");
}

physics::units::unit operator"" _ug(unsigned long long int x)
{
	return physics::units::unit(x, "ug");
}

physics::units::unit operator"" _ng(unsigned long long int x)
{
	return physics::units::unit(x, "ng");
}

physics::units::unit operator"" _pg(unsigned long long int x)
{
	return physics::units::unit(x, "pg");
}

physics::units::unit operator"" _fg(unsigned long long int x)
{
	return physics::units::unit(x, "fg");
}

physics::units::unit operator"" _ag(unsigned long long int x)
{
	return physics::units::unit(x, "ag");
}

physics::units::unit operator"" _zg(unsigned long long int x)
{
	return physics::units::unit(x, "zg");
}

physics::units::unit operator"" _yg(unsigned long long int x)
{
	return physics::units::unit(x, "yg");
}

physics::units::unit operator"" _YC(unsigned long long int x)
{
	return physics::units::unit(x, "YC");
}

physics::units::unit operator"" _ZC(unsigned long long int x)
{
	return physics::units::unit(x, "ZC");
}

physics::units::unit operator"" _EC(unsigned long long int x)
{
	return physics::units::unit(x, "EC");
}

physics::units::unit operator"" _PC(unsigned long long int x)
{
	return physics::units::unit(x, "PC");
}

physics::units::unit operator"" _TC(unsigned long long int x)
{
	return physics::units::unit(x, "TC");
}

physics::units::unit operator"" _GC(unsigned long long int x)
{
	return physics::units::unit(x, "GC");
}

physics::units::unit operator"" _MC(unsigned long long int x)
{
	return physics::units::unit(x, "MC");
}

physics::units::unit operator"" _kC(unsigned long long int x)
{
	return physics::units::unit(x, "kC");
}

physics::units::unit operator"" _hC(unsigned long long int x)
{
	return physics::units::unit(x, "hC");
}

physics::units::unit operator"" _daC(unsigned long long int x)
{
	return physics::units::unit(x, "daC");
}

physics::units::unit operator"" _C(unsigned long long int x)
{
	return physics::units::unit(x, "C");
}

physics::units::unit operator"" _dC(unsigned long long int x)
{
	return physics::units::unit(x, "dC");
}

physics::units::unit operator"" _cC(unsigned long long int x)
{
	return physics::units::unit(x, "cC");
}

physics::units::unit operator"" _CC(unsigned long long int x)
{
	return physics::units::unit(x, "CC");
}

physics::units::unit operator"" _uC(unsigned long long int x)
{
	return physics::units::unit(x, "uC");
}

physics::units::unit operator"" _nC(unsigned long long int x)
{
	return physics::units::unit(x, "nC");
}

physics::units::unit operator"" _pC(unsigned long long int x)
{
	return physics::units::unit(x, "pC");
}

physics::units::unit operator"" _fC(unsigned long long int x)
{
	return physics::units::unit(x, "fC");
}

physics::units::unit operator"" _aC(unsigned long long int x)
{
	return physics::units::unit(x, "aC");
}

physics::units::unit operator"" _zC(unsigned long long int x)
{
	return physics::units::unit(x, "zC");
}

physics::units::unit operator"" _yC(unsigned long long int x)
{
	return physics::units::unit(x, "yC");
}

physics::units::unit operator"" _YK(unsigned long long int x)
{
	return physics::units::unit(x, "YK");
}

physics::units::unit operator"" _ZK(unsigned long long int x)
{
	return physics::units::unit(x, "ZK");
}

physics::units::unit operator"" _EK(unsigned long long int x)
{
	return physics::units::unit(x, "EK");
}

physics::units::unit operator"" _PK(unsigned long long int x)
{
	return physics::units::unit(x, "PK");
}

physics::units::unit operator"" _TK(unsigned long long int x)
{
	return physics::units::unit(x, "TK");
}

physics::units::unit operator"" _GK(unsigned long long int x)
{
	return physics::units::unit(x, "GK");
}

physics::units::unit operator"" _MK(unsigned long long int x)
{
	return physics::units::unit(x, "MK");
}

physics::units::unit operator"" _kK(unsigned long long int x)
{
	return physics::units::unit(x, "kK");
}

physics::units::unit operator"" _hK(unsigned long long int x)
{
	return physics::units::unit(x, "hK");
}

physics::units::unit operator"" _daK(unsigned long long int x)
{
	return physics::units::unit(x, "daK");
}

physics::units::unit operator"" _K(unsigned long long int x)
{
	return physics::units::unit(x, "K");
}

physics::units::unit operator"" _dK(unsigned long long int x)
{
	return physics::units::unit(x, "dK");
}

physics::units::unit operator"" _cK(unsigned long long int x)
{
	return physics::units::unit(x, "cK");
}

physics::units::unit operator"" _KK(unsigned long long int x)
{
	return physics::units::unit(x, "KK");
}

physics::units::unit operator"" _uK(unsigned long long int x)
{
	return physics::units::unit(x, "uK");
}

physics::units::unit operator"" _nK(unsigned long long int x)
{
	return physics::units::unit(x, "nK");
}

physics::units::unit operator"" _pK(unsigned long long int x)
{
	return physics::units::unit(x, "pK");
}

physics::units::unit operator"" _fK(unsigned long long int x)
{
	return physics::units::unit(x, "fK");
}

physics::units::unit operator"" _aK(unsigned long long int x)
{
	return physics::units::unit(x, "aK");
}

physics::units::unit operator"" _zK(unsigned long long int x)
{
	return physics::units::unit(x, "zK");
}

physics::units::unit operator"" _yK(unsigned long long int x)
{
	return physics::units::unit(x, "yK");
}

physics::units::unit operator"" _Ymol(unsigned long long int x)
{
	return physics::units::unit(x, "Ymol");
}

physics::units::unit operator"" _Zmol(unsigned long long int x)
{
	return physics::units::unit(x, "Zmol");
}

physics::units::unit operator"" _Emol(unsigned long long int x)
{
	return physics::units::unit(x, "Emol");
}

physics::units::unit operator"" _Pmol(unsigned long long int x)
{
	return physics::units::unit(x, "Pmol");
}

physics::units::unit operator"" _Tmol(unsigned long long int x)
{
	return physics::units::unit(x, "Tmol");
}

physics::units::unit operator"" _Gmol(unsigned long long int x)
{
	return physics::units::unit(x, "Gmol");
}

physics::units::unit operator"" _Mmol(unsigned long long int x)
{
	return physics::units::unit(x, "Mmol");
}

physics::units::unit operator"" _kmol(unsigned long long int x)
{
	return physics::units::unit(x, "kmol");
}

physics::units::unit operator"" _hmol(unsigned long long int x)
{
	return physics::units::unit(x, "hmol");
}

physics::units::unit operator"" _damol(unsigned long long int x)
{
	return physics::units::unit(x, "damol");
}

physics::units::unit operator"" _mol(unsigned long long int x)
{
	return physics::units::unit(x, "mol");
}

physics::units::unit operator"" _dmol(unsigned long long int x)
{
	return physics::units::unit(x, "dmol");
}

physics::units::unit operator"" _cmol(unsigned long long int x)
{
	return physics::units::unit(x, "cmol");
}

physics::units::unit operator"" _molmol(unsigned long long int x)
{
	return physics::units::unit(x, "molmol");
}

physics::units::unit operator"" _umol(unsigned long long int x)
{
	return physics::units::unit(x, "umol");
}

physics::units::unit operator"" _nmol(unsigned long long int x)
{
	return physics::units::unit(x, "nmol");
}

physics::units::unit operator"" _pmol(unsigned long long int x)
{
	return physics::units::unit(x, "pmol");
}

physics::units::unit operator"" _fmol(unsigned long long int x)
{
	return physics::units::unit(x, "fmol");
}

physics::units::unit operator"" _amol(unsigned long long int x)
{
	return physics::units::unit(x, "amol");
}

physics::units::unit operator"" _zmol(unsigned long long int x)
{
	return physics::units::unit(x, "zmol");
}

physics::units::unit operator"" _ymol(unsigned long long int x)
{
	return physics::units::unit(x, "ymol");
}

physics::units::unit operator"" _Ycd(unsigned long long int x)
{
	return physics::units::unit(x, "Ycd");
}

physics::units::unit operator"" _Zcd(unsigned long long int x)
{
	return physics::units::unit(x, "Zcd");
}

physics::units::unit operator"" _Ecd(unsigned long long int x)
{
	return physics::units::unit(x, "Ecd");
}

physics::units::unit operator"" _Pcd(unsigned long long int x)
{
	return physics::units::unit(x, "Pcd");
}

physics::units::unit operator"" _Tcd(unsigned long long int x)
{
	return physics::units::unit(x, "Tcd");
}

physics::units::unit operator"" _Gcd(unsigned long long int x)
{
	return physics::units::unit(x, "Gcd");
}

physics::units::unit operator"" _Mcd(unsigned long long int x)
{
	return physics::units::unit(x, "Mcd");
}

physics::units::unit operator"" _kcd(unsigned long long int x)
{
	return physics::units::unit(x, "kcd");
}

physics::units::unit operator"" _hcd(unsigned long long int x)
{
	return physics::units::unit(x, "hcd");
}

physics::units::unit operator"" _dacd(unsigned long long int x)
{
	return physics::units::unit(x, "dacd");
}

physics::units::unit operator"" _cd(unsigned long long int x)
{
	return physics::units::unit(x, "cd");
}

physics::units::unit operator"" _dcd(unsigned long long int x)
{
	return physics::units::unit(x, "dcd");
}

physics::units::unit operator"" _ccd(unsigned long long int x)
{
	return physics::units::unit(x, "ccd");
}

physics::units::unit operator"" _cdcd(unsigned long long int x)
{
	return physics::units::unit(x, "cdcd");
}

physics::units::unit operator"" _ucd(unsigned long long int x)
{
	return physics::units::unit(x, "ucd");
}

physics::units::unit operator"" _ncd(unsigned long long int x)
{
	return physics::units::unit(x, "ncd");
}

physics::units::unit operator"" _pcd(unsigned long long int x)
{
	return physics::units::unit(x, "pcd");
}

physics::units::unit operator"" _fcd(unsigned long long int x)
{
	return physics::units::unit(x, "fcd");
}

physics::units::unit operator"" _acd(unsigned long long int x)
{
	return physics::units::unit(x, "acd");
}

physics::units::unit operator"" _zcd(unsigned long long int x)
{
	return physics::units::unit(x, "zcd");
}

physics::units::unit operator"" _ycd(unsigned long long int x)
{
	return physics::units::unit(x, "ycd");
}

physics::units::unit operator"" _angle(unsigned long long int x)
{
	return physics::units::unit(x, "angle");
}

physics::units::unit operator"" _solid_angle(unsigned long long int x)
{
	return physics::units::unit(x, "solid_angle");
}

physics::units::unit operator"" _YB(unsigned long long int x)
{
	return physics::units::unit(x, "YB");
}

physics::units::unit operator"" _ZB(unsigned long long int x)
{
	return physics::units::unit(x, "ZB");
}

physics::units::unit operator"" _EB(unsigned long long int x)
{
	return physics::units::unit(x, "EB");
}

physics::units::unit operator"" _PB(unsigned long long int x)
{
	return physics::units::unit(x, "PB");
}

physics::units::unit operator"" _TB(unsigned long long int x)
{
	return physics::units::unit(x, "TB");
}

physics::units::unit operator"" _GB(unsigned long long int x)
{
	return physics::units::unit(x, "GB");
}

physics::units::unit operator"" _MB(unsigned long long int x)
{
	return physics::units::unit(x, "MB");
}

physics::units::unit operator"" _kB(unsigned long long int x)
{
	return physics::units::unit(x, "kB");
}

physics::units::unit operator"" _B(unsigned long long int x)
{
	return physics::units::unit(x, "B");
}

physics::units::unit operator"" _Ym(long double x)
{
	return physics::units::unit(x, "Ym");
}

physics::units::unit operator"" _Zm(long double x)
{
	return physics::units::unit(x, "Zm");
}

physics::units::unit operator"" _Em(long double x)
{
	return physics::units::unit(x, "Em");
}

physics::units::unit operator"" _Pm(long double x)
{
	return physics::units::unit(x, "Pm");
}

physics::units::unit operator"" _Tm(long double x)
{
	return physics::units::unit(x, "Tm");
}

physics::units::unit operator"" _Gm(long double x)
{
	return physics::units::unit(x, "Gm");
}

physics::units::unit operator"" _Mm(long double x)
{
	return physics::units::unit(x, "Mm");
}

physics::units::unit operator"" _km(long double x)
{
	return physics::units::unit(x, "km");
}

physics::units::unit operator"" _hm(long double x)
{
	return physics::units::unit(x, "hm");
}

physics::units::unit operator"" _dam(long double x)
{
	return physics::units::unit(x, "dam");
}

physics::units::unit operator"" _m(long double x)
{
	return physics::units::unit(x, "m");
}

physics::units::unit operator"" _dm(long double x)
{
	return physics::units::unit(x, "dm");
}

physics::units::unit operator"" _cm(long double x)
{
	return physics::units::unit(x, "cm");
}

physics::units::unit operator"" _mm(long double x)
{
	return physics::units::unit(x, "mm");
}

physics::units::unit operator"" _um(long double x)
{
	return physics::units::unit(x, "um");
}

physics::units::unit operator"" _nm(long double x)
{
	return physics::units::unit(x, "nm");
}

physics::units::unit operator"" _pm(long double x)
{
	return physics::units::unit(x, "pm");
}

physics::units::unit operator"" _fm(long double x)
{
	return physics::units::unit(x, "fm");
}

physics::units::unit operator"" _am(long double x)
{
	return physics::units::unit(x, "am");
}

physics::units::unit operator"" _zm(long double x)
{
	return physics::units::unit(x, "zm");
}

physics::units::unit operator"" _ym(long double x)
{
	return physics::units::unit(x, "ym");
}

physics::units::unit operator"" _s(long double x)
{
	return physics::units::unit(x, "s");
}

physics::units::unit operator"" _ds(long double x)
{
	return physics::units::unit(x, "ds");
}

physics::units::unit operator"" _cs(long double x)
{
	return physics::units::unit(x, "cs");
}

physics::units::unit operator"" _ss(long double x)
{
	return physics::units::unit(x, "ss");
}

physics::units::unit operator"" _us(long double x)
{
	return physics::units::unit(x, "us");
}

physics::units::unit operator"" _ns(long double x)
{
	return physics::units::unit(x, "ns");
}

physics::units::unit operator"" _ps(long double x)
{
	return physics::units::unit(x, "ps");
}

physics::units::unit operator"" _fs(long double x)
{
	return physics::units::unit(x, "fs");
}

physics::units::unit operator"" _as(long double x)
{
	return physics::units::unit(x, "as");
}

physics::units::unit operator"" _zs(long double x)
{
	return physics::units::unit(x, "zs");
}

physics::units::unit operator"" _ys(long double x)
{
	return physics::units::unit(x, "ys");
}

physics::units::unit operator"" _Yg(long double x)
{
	return physics::units::unit(x, "Yg");
}

physics::units::unit operator"" _Zg(long double x)
{
	return physics::units::unit(x, "Zg");
}

physics::units::unit operator"" _Eg(long double x)
{
	return physics::units::unit(x, "Eg");
}

physics::units::unit operator"" _Pg(long double x)
{
	return physics::units::unit(x, "Pg");
}

physics::units::unit operator"" _Tg(long double x)
{
	return physics::units::unit(x, "Tg");
}

physics::units::unit operator"" _Gg(long double x)
{
	return physics::units::unit(x, "Gg");
}

physics::units::unit operator"" _Mg(long double x)
{
	return physics::units::unit(x, "Mg");
}

physics::units::unit operator"" _kg(long double x)
{
	return physics::units::unit(x, "kg");
}

physics::units::unit operator"" _hg(long double x)
{
	return physics::units::unit(x, "hg");
}

physics::units::unit operator"" _dag(long double x)
{
	return physics::units::unit(x, "dag");
}

physics::units::unit operator"" _g(long double x)
{
	return physics::units::unit(x, "g");
}

physics::units::unit operator"" _dg(long double x)
{
	return physics::units::unit(x, "dg");
}

physics::units::unit operator"" _cg(long double x)
{
	return physics::units::unit(x, "cg");
}

physics::units::unit operator"" _gg(long double x)
{
	return physics::units::unit(x, "gg");
}

physics::units::unit operator"" _ug(long double x)
{
	return physics::units::unit(x, "ug");
}

physics::units::unit operator"" _ng(long double x)
{
	return physics::units::unit(x, "ng");
}

physics::units::unit operator"" _pg(long double x)
{
	return physics::units::unit(x, "pg");
}

physics::units::unit operator"" _fg(long double x)
{
	return physics::units::unit(x, "fg");
}

physics::units::unit operator"" _ag(long double x)
{
	return physics::units::unit(x, "ag");
}

physics::units::unit operator"" _zg(long double x)
{
	return physics::units::unit(x, "zg");
}

physics::units::unit operator"" _yg(long double x)
{
	return physics::units::unit(x, "yg");
}

physics::units::unit operator"" _YC(long double x)
{
	return physics::units::unit(x, "YC");
}

physics::units::unit operator"" _ZC(long double x)
{
	return physics::units::unit(x, "ZC");
}

physics::units::unit operator"" _EC(long double x)
{
	return physics::units::unit(x, "EC");
}

physics::units::unit operator"" _PC(long double x)
{
	return physics::units::unit(x, "PC");
}

physics::units::unit operator"" _TC(long double x)
{
	return physics::units::unit(x, "TC");
}

physics::units::unit operator"" _GC(long double x)
{
	return physics::units::unit(x, "GC");
}

physics::units::unit operator"" _MC(long double x)
{
	return physics::units::unit(x, "MC");
}

physics::units::unit operator"" _kC(long double x)
{
	return physics::units::unit(x, "kC");
}

physics::units::unit operator"" _hC(long double x)
{
	return physics::units::unit(x, "hC");
}

physics::units::unit operator"" _daC(long double x)
{
	return physics::units::unit(x, "daC");
}

physics::units::unit operator"" _C(long double x)
{
	return physics::units::unit(x, "C");
}

physics::units::unit operator"" _dC(long double x)
{
	return physics::units::unit(x, "dC");
}

physics::units::unit operator"" _cC(long double x)
{
	return physics::units::unit(x, "cC");
}

physics::units::unit operator"" _CC(long double x)
{
	return physics::units::unit(x, "CC");
}

physics::units::unit operator"" _uC(long double x)
{
	return physics::units::unit(x, "uC");
}

physics::units::unit operator"" _nC(long double x)
{
	return physics::units::unit(x, "nC");
}

physics::units::unit operator"" _pC(long double x)
{
	return physics::units::unit(x, "pC");
}

physics::units::unit operator"" _fC(long double x)
{
	return physics::units::unit(x, "fC");
}

physics::units::unit operator"" _aC(long double x)
{
	return physics::units::unit(x, "aC");
}

physics::units::unit operator"" _zC(long double x)
{
	return physics::units::unit(x, "zC");
}

physics::units::unit operator"" _yC(long double x)
{
	return physics::units::unit(x, "yC");
}

physics::units::unit operator"" _YK(long double x)
{
	return physics::units::unit(x, "YK");
}

physics::units::unit operator"" _ZK(long double x)
{
	return physics::units::unit(x, "ZK");
}

physics::units::unit operator"" _EK(long double x)
{
	return physics::units::unit(x, "EK");
}

physics::units::unit operator"" _PK(long double x)
{
	return physics::units::unit(x, "PK");
}

physics::units::unit operator"" _TK(long double x)
{
	return physics::units::unit(x, "TK");
}

physics::units::unit operator"" _GK(long double x)
{
	return physics::units::unit(x, "GK");
}

physics::units::unit operator"" _MK(long double x)
{
	return physics::units::unit(x, "MK");
}

physics::units::unit operator"" _kK(long double x)
{
	return physics::units::unit(x, "kK");
}

physics::units::unit operator"" _hK(long double x)
{
	return physics::units::unit(x, "hK");
}

physics::units::unit operator"" _daK(long double x)
{
	return physics::units::unit(x, "daK");
}

physics::units::unit operator"" _K(long double x)
{
	return physics::units::unit(x, "K");
}

physics::units::unit operator"" _dK(long double x)
{
	return physics::units::unit(x, "dK");
}

physics::units::unit operator"" _cK(long double x)
{
	return physics::units::unit(x, "cK");
}

physics::units::unit operator"" _KK(long double x)
{
	return physics::units::unit(x, "KK");
}

physics::units::unit operator"" _uK(long double x)
{
	return physics::units::unit(x, "uK");
}

physics::units::unit operator"" _nK(long double x)
{
	return physics::units::unit(x, "nK");
}

physics::units::unit operator"" _pK(long double x)
{
	return physics::units::unit(x, "pK");
}

physics::units::unit operator"" _fK(long double x)
{
	return physics::units::unit(x, "fK");
}

physics::units::unit operator"" _aK(long double x)
{
	return physics::units::unit(x, "aK");
}

physics::units::unit operator"" _zK(long double x)
{
	return physics::units::unit(x, "zK");
}

physics::units::unit operator"" _yK(long double x)
{
	return physics::units::unit(x, "yK");
}

physics::units::unit operator"" _Ymol(long double x)
{
	return physics::units::unit(x, "Ymol");
}

physics::units::unit operator"" _Zmol(long double x)
{
	return physics::units::unit(x, "Zmol");
}

physics::units::unit operator"" _Emol(long double x)
{
	return physics::units::unit(x, "Emol");
}

physics::units::unit operator"" _Pmol(long double x)
{
	return physics::units::unit(x, "Pmol");
}

physics::units::unit operator"" _Tmol(long double x)
{
	return physics::units::unit(x, "Tmol");
}

physics::units::unit operator"" _Gmol(long double x)
{
	return physics::units::unit(x, "Gmol");
}

physics::units::unit operator"" _Mmol(long double x)
{
	return physics::units::unit(x, "Mmol");
}

physics::units::unit operator"" _kmol(long double x)
{
	return physics::units::unit(x, "kmol");
}

physics::units::unit operator"" _hmol(long double x)
{
	return physics::units::unit(x, "hmol");
}

physics::units::unit operator"" _damol(long double x)
{
	return physics::units::unit(x, "damol");
}

physics::units::unit operator"" _mol(long double x)
{
	return physics::units::unit(x, "mol");
}

physics::units::unit operator"" _dmol(long double x)
{
	return physics::units::unit(x, "dmol");
}

physics::units::unit operator"" _cmol(long double x)
{
	return physics::units::unit(x, "cmol");
}

physics::units::unit operator"" _molmol(long double x)
{
	return physics::units::unit(x, "molmol");
}

physics::units::unit operator"" _umol(long double x)
{
	return physics::units::unit(x, "umol");
}

physics::units::unit operator"" _nmol(long double x)
{
	return physics::units::unit(x, "nmol");
}

physics::units::unit operator"" _pmol(long double x)
{
	return physics::units::unit(x, "pmol");
}

physics::units::unit operator"" _fmol(long double x)
{
	return physics::units::unit(x, "fmol");
}

physics::units::unit operator"" _amol(long double x)
{
	return physics::units::unit(x, "amol");
}

physics::units::unit operator"" _zmol(long double x)
{
	return physics::units::unit(x, "zmol");
}

physics::units::unit operator"" _ymol(long double x)
{
	return physics::units::unit(x, "ymol");
}

physics::units::unit operator"" _Ycd(long double x)
{
	return physics::units::unit(x, "Ycd");
}

physics::units::unit operator"" _Zcd(long double x)
{
	return physics::units::unit(x, "Zcd");
}

physics::units::unit operator"" _Ecd(long double x)
{
	return physics::units::unit(x, "Ecd");
}

physics::units::unit operator"" _Pcd(long double x)
{
	return physics::units::unit(x, "Pcd");
}

physics::units::unit operator"" _Tcd(long double x)
{
	return physics::units::unit(x, "Tcd");
}

physics::units::unit operator"" _Gcd(long double x)
{
	return physics::units::unit(x, "Gcd");
}

physics::units::unit operator"" _Mcd(long double x)
{
	return physics::units::unit(x, "Mcd");
}

physics::units::unit operator"" _kcd(long double x)
{
	return physics::units::unit(x, "kcd");
}

physics::units::unit operator"" _hcd(long double x)
{
	return physics::units::unit(x, "hcd");
}

physics::units::unit operator"" _dacd(long double x)
{
	return physics::units::unit(x, "dacd");
}

physics::units::unit operator"" _cd(long double x)
{
	return physics::units::unit(x, "cd");
}

physics::units::unit operator"" _dcd(long double x)
{
	return physics::units::unit(x, "dcd");
}

physics::units::unit operator"" _ccd(long double x)
{
	return physics::units::unit(x, "ccd");
}

physics::units::unit operator"" _cdcd(long double x)
{
	return physics::units::unit(x, "cdcd");
}

physics::units::unit operator"" _ucd(long double x)
{
	return physics::units::unit(x, "ucd");
}

physics::units::unit operator"" _ncd(long double x)
{
	return physics::units::unit(x, "ncd");
}

physics::units::unit operator"" _pcd(long double x)
{
	return physics::units::unit(x, "pcd");
}

physics::units::unit operator"" _fcd(long double x)
{
	return physics::units::unit(x, "fcd");
}

physics::units::unit operator"" _acd(long double x)
{
	return physics::units::unit(x, "acd");
}

physics::units::unit operator"" _zcd(long double x)
{
	return physics::units::unit(x, "zcd");
}

physics::units::unit operator"" _ycd(long double x)
{
	return physics::units::unit(x, "ycd");
}

physics::units::unit operator"" _angle(long double x)
{
	return physics::units::unit(x, "angle");
}

physics::units::unit operator"" _solid_angle(long double x)
{
	return physics::units::unit(x, "solid_angle");
}

physics::units::unit operator"" _YB(long double x)
{
	return physics::units::unit(x, "YB");
}

physics::units::unit operator"" _ZB(long double x)
{
	return physics::units::unit(x, "ZB");
}

physics::units::unit operator"" _EB(long double x)
{
	return physics::units::unit(x, "EB");
}

physics::units::unit operator"" _PB(long double x)
{
	return physics::units::unit(x, "PB");
}

physics::units::unit operator"" _TB(long double x)
{
	return physics::units::unit(x, "TB");
}

physics::units::unit operator"" _GB(long double x)
{
	return physics::units::unit(x, "GB");
}

physics::units::unit operator"" _MB(long double x)
{
	return physics::units::unit(x, "MB");
}

physics::units::unit operator"" _kB(long double x)
{
	return physics::units::unit(x, "kB");
}

physics::units::unit operator"" _B(long double x)
{
	return physics::units::unit(x, "B");
}
