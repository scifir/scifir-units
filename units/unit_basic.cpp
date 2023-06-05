#include "units/unit_basic.hpp"

#include "units/scalar_unit.hpp"
#include "units/dimension.hpp"
#include "units/prefix.hpp"
#include "topology/constants.hpp"

#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace msci
{
	SCALAR_UNIT_CPP(length,"m");
	SCALAR_UNIT_CPP(time,"s");

	time::operator std::chrono::seconds() const
	{
		msci::time a = *this;
		a.change_dimensions("s");
		return std::chrono::seconds(int(a.get_value()));
	}

	string time::get_finish_date() const
	{
		chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
		start += chrono::seconds(*this);
		std::time_t start_time = std::chrono::system_clock::to_time_t(start);
		stringstream output;
		output << ctime(&start_time);
		return output.str();
	}
	
	string time::display_as_time() const
	{
		ostringstream output;
		msci::time remaining_time = *this;
		msci::time one_year ("365 d");
		if (*this >= one_year)
		{
			int total_of_years = int(trunc((*this / one_year).get_value()));
			output << total_of_years << "y ";
			remaining_time -= msci::time(total_of_years * 365,"d");
		}
		msci::time one_month("30 d");
		if (remaining_time >= one_month)
		{
			int total_of_months = int(trunc((remaining_time / one_month).get_value()));
			output << total_of_months << "m ";
			remaining_time -= msci::time(total_of_months * 30,"d");
		}
		msci::time one_day("1 d");
		if (remaining_time >= one_day)
		{
			int total_of_days = int(trunc((remaining_time / one_day).get_value()));
			output << total_of_days << "d ";
			remaining_time -= msci::time(total_of_days,"d");
		}
		msci::time one_hour("1 h");
		if (remaining_time >= one_hour)
		{
			int total_of_hours = int(trunc((remaining_time / one_hour).get_value()));
			output << total_of_hours << "h ";
			remaining_time -= msci::time(total_of_hours,"h");
		}
		msci::time one_minute("1 min");
		if (remaining_time >= one_minute)
		{
			int total_of_minutes = int(trunc((remaining_time / one_minute).get_value()));
			output << total_of_minutes << "min ";
			remaining_time -= msci::time(total_of_minutes,"min");
		}
		msci::time one_second("1 s");
		if (remaining_time >= one_second)
		{
			remaining_time.change_dimensions("s");
			float total_of_seconds = float(remaining_time.get_value());
			output << total_of_seconds << "s";
		}
		return output.str();
	}

	SCALAR_UNIT_CPP(mass,"g");
	SCALAR_UNIT_CPP(charge,"C");

	void temperature::add_prefix(const prefix& prefix)
	{
		if(prefix.get_conversion_factor() > 0)
		{
			scalar_unit::add_prefix(prefix);
		}
		else
		{
			cerr << "Temperature can't have negative prefixes";
		}
	}

	SCALAR_UNIT_CPP(mole,"mol");

	int mole::number_of_particles() const
	{
		return 1;
		/*if (scalar_unit::actual_dimensions.count(particles))
		{
			return scalar_unit::value;
		}
		else
		{
			return scalar_unit::value * msci::avogadro_constant;
		}*/
	}

	SCALAR_UNIT_CPP(light,"cd");
	SCALAR_UNIT_CPP(data,"B");
}

msci::length operator"" _Ym(unsigned long long int x)
{
	return msci::length(x, "Ym");
}

msci::length operator"" _Zm(unsigned long long int x)
{
	return msci::length(x, "Zm");
}

msci::length operator"" _Em(unsigned long long int x)
{
	return msci::length(x, "Em");
}

msci::length operator"" _Pm(unsigned long long int x)
{
	return msci::length(x, "Pm");
}

msci::length operator"" _Tm(unsigned long long int x)
{
	return msci::length(x, "Tm");
}

msci::length operator"" _Gm(unsigned long long int x)
{
	return msci::length(x, "Gm");
}

msci::length operator"" _Mm(unsigned long long int x)
{
	return msci::length(x, "Mm");
}

msci::length operator"" _km(unsigned long long int x)
{
	return msci::length(x, "km");
}

msci::length operator"" _hm(unsigned long long int x)
{
	return msci::length(x, "hm");
}

msci::length operator"" _dam(unsigned long long int x)
{
	return msci::length(x, "dam");
}

msci::length operator"" _m(unsigned long long int x)
{
	return msci::length(x, "m");
}

msci::length operator"" _dm(unsigned long long int x)
{
	return msci::length(x, "dm");
}

msci::length operator"" _cm(unsigned long long int x)
{
	return msci::length(x, "cm");
}

msci::length operator"" _mm(unsigned long long int x)
{
	return msci::length(x, "mm");
}

msci::length operator"" _um(unsigned long long int x)
{
	return msci::length(x, "um");
}

msci::length operator"" _nm(unsigned long long int x)
{
	return msci::length(x, "nm");
}

msci::length operator"" _pm(unsigned long long int x)
{
	return msci::length(x, "pm");
}

msci::length operator"" _fm(unsigned long long int x)
{
	return msci::length(x, "fm");
}

msci::length operator"" _am(unsigned long long int x)
{
	return msci::length(x, "am");
}

msci::length operator"" _zm(unsigned long long int x)
{
	return msci::length(x, "zm");
}

msci::length operator"" _ym(unsigned long long int x)
{
	return msci::length(x, "ym");
}

msci::time operator"" _s(unsigned long long int x)
{
	return msci::time(x, "s");
}

msci::time operator"" _ms(unsigned long long int x)
{
	return msci::time(x, "ms");
}

msci::time operator"" _us(unsigned long long int x)
{
	return msci::time(x, "us");
}

msci::time operator"" _ns(unsigned long long int x)
{
	return msci::time(x, "ns");
}

msci::time operator"" _ps(unsigned long long int x)
{
	return msci::time(x, "ps");
}

msci::time operator"" _fs(unsigned long long int x)
{
	return msci::time(x, "fs");
}

msci::time operator"" _as(unsigned long long int x)
{
	return msci::time(x, "as");
}

msci::time operator"" _zs(unsigned long long int x)
{
	return msci::time(x, "zs");
}

msci::time operator"" _ys(unsigned long long int x)
{
	return msci::time(x, "ys");
}

msci::mass operator"" _Yg(unsigned long long int x)
{
	return msci::mass(x, "Yg");
}

msci::mass operator"" _Zg(unsigned long long int x)
{
	return msci::mass(x, "Zg");
}

msci::mass operator"" _Eg(unsigned long long int x)
{
	return msci::mass(x, "Eg");
}

msci::mass operator"" _Pg(unsigned long long int x)
{
	return msci::mass(x, "Pg");
}

msci::mass operator"" _Tg(unsigned long long int x)
{
	return msci::mass(x, "Tg");
}

msci::mass operator"" _Gg(unsigned long long int x)
{
	return msci::mass(x, "Gg");
}

msci::mass operator"" _Mg(unsigned long long int x)
{
	return msci::mass(x, "Mg");
}

msci::mass operator"" _kg(unsigned long long int x)
{
	return msci::mass(x, "kg");
}

msci::mass operator"" _hg(unsigned long long int x)
{
	return msci::mass(x, "hg");
}

msci::mass operator"" _dag(unsigned long long int x)
{
	return msci::mass(x, "dag");
}

msci::mass operator"" _g(unsigned long long int x)
{
	return msci::mass(x, "g");
}

msci::mass operator"" _dg(unsigned long long int x)
{
	return msci::mass(x, "dg");
}

msci::mass operator"" _cg(unsigned long long int x)
{
	return msci::mass(x, "cg");
}

msci::mass operator"" _mg(unsigned long long int x)
{
	return msci::mass(x, "mg");
}

msci::mass operator"" _ug(unsigned long long int x)
{
	return msci::mass(x, "ug");
}

msci::mass operator"" _ng(unsigned long long int x)
{
	return msci::mass(x, "ng");
}

msci::mass operator"" _pg(unsigned long long int x)
{
	return msci::mass(x, "pg");
}

msci::mass operator"" _fg(unsigned long long int x)
{
	return msci::mass(x, "fg");
}

msci::mass operator"" _ag(unsigned long long int x)
{
	return msci::mass(x, "ag");
}

msci::mass operator"" _zg(unsigned long long int x)
{
	return msci::mass(x, "zg");
}

msci::mass operator"" _yg(unsigned long long int x)
{
	return msci::mass(x, "yg");
}

msci::charge operator"" _YC(unsigned long long int x)
{
	return msci::charge(x, "YC");
}

msci::charge operator"" _ZC(unsigned long long int x)
{
	return msci::charge(x, "ZC");
}

msci::charge operator"" _EC(unsigned long long int x)
{
	return msci::charge(x, "EC");
}

msci::charge operator"" _PC(unsigned long long int x)
{
	return msci::charge(x, "PC");
}

msci::charge operator"" _TC(unsigned long long int x)
{
	return msci::charge(x, "TC");
}

msci::charge operator"" _GC(unsigned long long int x)
{
	return msci::charge(x, "GC");
}

msci::charge operator"" _MC(unsigned long long int x)
{
	return msci::charge(x, "MC");
}

msci::charge operator"" _kC(unsigned long long int x)
{
	return msci::charge(x, "kC");
}

msci::charge operator"" _hC(unsigned long long int x)
{
	return msci::charge(x, "hC");
}

msci::charge operator"" _daC(unsigned long long int x)
{
	return msci::charge(x, "daC");
}

msci::charge operator"" _C(unsigned long long int x)
{
	return msci::charge(x, "C");
}

msci::charge operator"" _dC(unsigned long long int x)
{
	return msci::charge(x, "dC");
}

msci::charge operator"" _cC(unsigned long long int x)
{
	return msci::charge(x, "cC");
}

msci::charge operator"" _mC(unsigned long long int x)
{
	return msci::charge(x, "mC");
}

msci::charge operator"" _uC(unsigned long long int x)
{
	return msci::charge(x, "uC");
}

msci::charge operator"" _nC(unsigned long long int x)
{
	return msci::charge(x, "nC");
}

msci::charge operator"" _pC(unsigned long long int x)
{
	return msci::charge(x, "pC");
}

msci::charge operator"" _fC(unsigned long long int x)
{
	return msci::charge(x, "fC");
}

msci::charge operator"" _aC(unsigned long long int x)
{
	return msci::charge(x, "aC");
}

msci::charge operator"" _zC(unsigned long long int x)
{
	return msci::charge(x, "zC");
}

msci::charge operator"" _yC(unsigned long long int x)
{
	return msci::charge(x, "yC");
}

msci::temperature operator"" _YK(unsigned long long int x)
{
	return msci::temperature(x, "YK");
}

msci::temperature operator"" _ZK(unsigned long long int x)
{
	return msci::temperature(x, "ZK");
}

msci::temperature operator"" _EK(unsigned long long int x)
{
	return msci::temperature(x, "EK");
}

msci::temperature operator"" _PK(unsigned long long int x)
{
	return msci::temperature(x, "PK");
}

msci::temperature operator"" _TK(unsigned long long int x)
{
	return msci::temperature(x, "TK");
}

msci::temperature operator"" _GK(unsigned long long int x)
{
	return msci::temperature(x, "GK");
}

msci::temperature operator"" _MK(unsigned long long int x)
{
	return msci::temperature(x, "MK");
}

msci::temperature operator"" _kK(unsigned long long int x)
{
	return msci::temperature(x, "kK");
}

msci::temperature operator"" _hK(unsigned long long int x)
{
	return msci::temperature(x, "hK");
}

msci::temperature operator"" _daK(unsigned long long int x)
{
	return msci::temperature(x, "daK");
}

msci::temperature operator"" _K(unsigned long long int x)
{
	return msci::temperature(x, "K");
}

msci::temperature operator"" _dK(unsigned long long int x)
{
	return msci::temperature(x, "dK");
}

msci::temperature operator"" _cK(unsigned long long int x)
{
	return msci::temperature(x, "cK");
}

msci::temperature operator"" _mK(unsigned long long int x)
{
	return msci::temperature(x, "mK");
}

msci::temperature operator"" _uK(unsigned long long int x)
{
	return msci::temperature(x, "uK");
}

msci::temperature operator"" _nK(unsigned long long int x)
{
	return msci::temperature(x, "nK");
}

msci::temperature operator"" _pK(unsigned long long int x)
{
	return msci::temperature(x, "pK");
}

msci::temperature operator"" _fK(unsigned long long int x)
{
	return msci::temperature(x, "fK");
}

msci::temperature operator"" _aK(unsigned long long int x)
{
	return msci::temperature(x, "aK");
}

msci::temperature operator"" _zK(unsigned long long int x)
{
	return msci::temperature(x, "zK");
}

msci::temperature operator"" _yK(unsigned long long int x)
{
	return msci::temperature(x, "yK");
}

msci::mole operator"" _Ymol(unsigned long long int x)
{
	return msci::mole(x, "Ymol");
}

msci::mole operator"" _Zmol(unsigned long long int x)
{
	return msci::mole(x, "Zmol");
}

msci::mole operator"" _Emol(unsigned long long int x)
{
	return msci::mole(x, "Emol");
}

msci::mole operator"" _Pmol(unsigned long long int x)
{
	return msci::mole(x, "Pmol");
}

msci::mole operator"" _Tmol(unsigned long long int x)
{
	return msci::mole(x, "Tmol");
}

msci::mole operator"" _Gmol(unsigned long long int x)
{
	return msci::mole(x, "Gmol");
}

msci::mole operator"" _Mmol(unsigned long long int x)
{
	return msci::mole(x, "Mmol");
}

msci::mole operator"" _kmol(unsigned long long int x)
{
	return msci::mole(x, "kmol");
}

msci::mole operator"" _hmol(unsigned long long int x)
{
	return msci::mole(x, "hmol");
}

msci::mole operator"" _damol(unsigned long long int x)
{
	return msci::mole(x, "damol");
}

msci::mole operator"" _mol(unsigned long long int x)
{
	return msci::mole(x, "mol");
}

msci::mole operator"" _dmol(unsigned long long int x)
{
	return msci::mole(x, "dmol");
}

msci::mole operator"" _cmol(unsigned long long int x)
{
	return msci::mole(x, "cmol");
}

msci::mole operator"" _mmol(unsigned long long int x)
{
	return msci::mole(x, "mmol");
}

msci::mole operator"" _umol(unsigned long long int x)
{
	return msci::mole(x, "umol");
}

msci::mole operator"" _nmol(unsigned long long int x)
{
	return msci::mole(x, "nmol");
}

msci::mole operator"" _pmol(unsigned long long int x)
{
	return msci::mole(x, "pmol");
}

msci::mole operator"" _fmol(unsigned long long int x)
{
	return msci::mole(x, "fmol");
}

msci::mole operator"" _amol(unsigned long long int x)
{
	return msci::mole(x, "amol");
}

msci::mole operator"" _zmol(unsigned long long int x)
{
	return msci::mole(x, "zmol");
}

msci::mole operator"" _ymol(unsigned long long int x)
{
	return msci::mole(x, "ymol");
}

msci::light operator"" _Ycd(unsigned long long int x)
{
	return msci::light(x, "Ycd");
}

msci::light operator"" _Zcd(unsigned long long int x)
{
	return msci::light(x, "Zcd");
}

msci::light operator"" _Ecd(unsigned long long int x)
{
	return msci::light(x, "Ecd");
}

msci::light operator"" _Pcd(unsigned long long int x)
{
	return msci::light(x, "Pcd");
}

msci::light operator"" _Tcd(unsigned long long int x)
{
	return msci::light(x, "Tcd");
}

msci::light operator"" _Gcd(unsigned long long int x)
{
	return msci::light(x, "Gcd");
}

msci::light operator"" _Mcd(unsigned long long int x)
{
	return msci::light(x, "Mcd");
}

msci::light operator"" _kcd(unsigned long long int x)
{
	return msci::light(x, "kcd");
}

msci::light operator"" _hcd(unsigned long long int x)
{
	return msci::light(x, "hcd");
}

msci::light operator"" _dacd(unsigned long long int x)
{
	return msci::light(x, "dacd");
}

msci::light operator"" _cd(unsigned long long int x)
{
	return msci::light(x, "cd");
}

msci::light operator"" _dcd(unsigned long long int x)
{
	return msci::light(x, "dcd");
}

msci::light operator"" _ccd(unsigned long long int x)
{
	return msci::light(x, "ccd");
}

msci::light operator"" _mcd(unsigned long long int x)
{
	return msci::light(x, "mcd");
}

msci::light operator"" _ucd(unsigned long long int x)
{
	return msci::light(x, "ucd");
}

msci::light operator"" _ncd(unsigned long long int x)
{
	return msci::light(x, "ncd");
}

msci::light operator"" _pcd(unsigned long long int x)
{
	return msci::light(x, "pcd");
}

msci::light operator"" _fcd(unsigned long long int x)
{
	return msci::light(x, "fcd");
}

msci::light operator"" _acd(unsigned long long int x)
{
	return msci::light(x, "acd");
}

msci::light operator"" _zcd(unsigned long long int x)
{
	return msci::light(x, "zcd");
}

msci::light operator"" _ycd(unsigned long long int x)
{
	return msci::light(x, "ycd");
}

msci::data operator"" _YB(unsigned long long int x)
{
	return msci::data(x, "YB");
}

msci::data operator"" _ZB(unsigned long long int x)
{
	return msci::data(x, "ZB");
}

msci::data operator"" _EB(unsigned long long int x)
{
	return msci::data(x, "EB");
}

msci::data operator"" _PB(unsigned long long int x)
{
	return msci::data(x, "PB");
}

msci::data operator"" _TB(unsigned long long int x)
{
	return msci::data(x, "TB");
}

msci::data operator"" _GB(unsigned long long int x)
{
	return msci::data(x, "GB");
}

msci::data operator"" _MB(unsigned long long int x)
{
	return msci::data(x, "MB");
}

msci::data operator"" _kB(unsigned long long int x)
{
	return msci::data(x, "kB");
}

msci::data operator"" _B(unsigned long long int x)
{
	return msci::data(x, "B");
}

msci::length operator"" _Ym(long double x)
{
	return msci::length(x, "Ym");
}

msci::length operator"" _Zm(long double x)
{
	return msci::length(x, "Zm");
}

msci::length operator"" _Em(long double x)
{
	return msci::length(x, "Em");
}

msci::length operator"" _Pm(long double x)
{
	return msci::length(x, "Pm");
}

msci::length operator"" _Tm(long double x)
{
	return msci::length(x, "Tm");
}

msci::length operator"" _Gm(long double x)
{
	return msci::length(x, "Gm");
}

msci::length operator"" _Mm(long double x)
{
	return msci::length(x, "Mm");
}

msci::length operator"" _km(long double x)
{
	return msci::length(x, "km");
}

msci::length operator"" _hm(long double x)
{
	return msci::length(x, "hm");
}

msci::length operator"" _dam(long double x)
{
	return msci::length(x, "dam");
}

msci::length operator"" _m(long double x)
{
	return msci::length(x, "m");
}

msci::length operator"" _dm(long double x)
{
	return msci::length(x, "dm");
}

msci::length operator"" _cm(long double x)
{
	return msci::length(x, "cm");
}

msci::length operator"" _mm(long double x)
{
	return msci::length(x, "mm");
}

msci::length operator"" _um(long double x)
{
	return msci::length(x, "um");
}

msci::length operator"" _nm(long double x)
{
	return msci::length(x, "nm");
}

msci::length operator"" _pm(long double x)
{
	return msci::length(x, "pm");
}

msci::length operator"" _fm(long double x)
{
	return msci::length(x, "fm");
}

msci::length operator"" _am(long double x)
{
	return msci::length(x, "am");
}

msci::length operator"" _zm(long double x)
{
	return msci::length(x, "zm");
}

msci::length operator"" _ym(long double x)
{
	return msci::length(x, "ym");
}

msci::time operator"" _s(long double x)
{
	return msci::time(x, "s");
}

msci::time operator"" _ms(long double x)
{
	return msci::time(x, "ms");
}

msci::time operator"" _us(long double x)
{
	return msci::time(x, "us");
}

msci::time operator"" _ns(long double x)
{
	return msci::time(x, "ns");
}

msci::time operator"" _ps(long double x)
{
	return msci::time(x, "ps");
}

msci::time operator"" _fs(long double x)
{
	return msci::time(x, "fs");
}

msci::time operator"" _as(long double x)
{
	return msci::time(x, "as");
}

msci::time operator"" _zs(long double x)
{
	return msci::time(x, "zs");
}

msci::time operator"" _ys(long double x)
{
	return msci::time(x, "ys");
}

msci::mass operator"" _Yg(long double x)
{
	return msci::mass(x, "Yg");
}

msci::mass operator"" _Zg(long double x)
{
	return msci::mass(x, "Zg");
}

msci::mass operator"" _Eg(long double x)
{
	return msci::mass(x, "Eg");
}

msci::mass operator"" _Pg(long double x)
{
	return msci::mass(x, "Pg");
}

msci::mass operator"" _Tg(long double x)
{
	return msci::mass(x, "Tg");
}

msci::mass operator"" _Gg(long double x)
{
	return msci::mass(x, "Gg");
}

msci::mass operator"" _Mg(long double x)
{
	return msci::mass(x, "Mg");
}

msci::mass operator"" _kg(long double x)
{
	return msci::mass(x, "kg");
}

msci::mass operator"" _hg(long double x)
{
	return msci::mass(x, "hg");
}

msci::mass operator"" _dag(long double x)
{
	return msci::mass(x, "dag");
}

msci::mass operator"" _g(long double x)
{
	return msci::mass(x, "g");
}

msci::mass operator"" _dg(long double x)
{
	return msci::mass(x, "dg");
}

msci::mass operator"" _cg(long double x)
{
	return msci::mass(x, "cg");
}

msci::mass operator"" _mg(long double x)
{
	return msci::mass(x, "mg");
}

msci::mass operator"" _ug(long double x)
{
	return msci::mass(x, "ug");
}

msci::mass operator"" _ng(long double x)
{
	return msci::mass(x, "ng");
}

msci::mass operator"" _pg(long double x)
{
	return msci::mass(x, "pg");
}

msci::mass operator"" _fg(long double x)
{
	return msci::mass(x, "fg");
}

msci::mass operator"" _ag(long double x)
{
	return msci::mass(x, "ag");
}

msci::mass operator"" _zg(long double x)
{
	return msci::mass(x, "zg");
}

msci::mass operator"" _yg(long double x)
{
	return msci::mass(x, "yg");
}

msci::charge operator"" _YC(long double x)
{
	return msci::charge(x, "YC");
}

msci::charge operator"" _ZC(long double x)
{
	return msci::charge(x, "ZC");
}

msci::charge operator"" _EC(long double x)
{
	return msci::charge(x, "EC");
}

msci::charge operator"" _PC(long double x)
{
	return msci::charge(x, "PC");
}

msci::charge operator"" _TC(long double x)
{
	return msci::charge(x, "TC");
}

msci::charge operator"" _GC(long double x)
{
	return msci::charge(x, "GC");
}

msci::charge operator"" _MC(long double x)
{
	return msci::charge(x, "MC");
}

msci::charge operator"" _kC(long double x)
{
	return msci::charge(x, "kC");
}

msci::charge operator"" _hC(long double x)
{
	return msci::charge(x, "hC");
}

msci::charge operator"" _daC(long double x)
{
	return msci::charge(x, "daC");
}

msci::charge operator"" _C(long double x)
{
	return msci::charge(x, "C");
}

msci::charge operator"" _dC(long double x)
{
	return msci::charge(x, "dC");
}

msci::charge operator"" _cC(long double x)
{
	return msci::charge(x, "cC");
}

msci::charge operator"" _mC(long double x)
{
	return msci::charge(x, "mC");
}

msci::charge operator"" _uC(long double x)
{
	return msci::charge(x, "uC");
}

msci::charge operator"" _nC(long double x)
{
	return msci::charge(x, "nC");
}

msci::charge operator"" _pC(long double x)
{
	return msci::charge(x, "pC");
}

msci::charge operator"" _fC(long double x)
{
	return msci::charge(x, "fC");
}

msci::charge operator"" _aC(long double x)
{
	return msci::charge(x, "aC");
}

msci::charge operator"" _zC(long double x)
{
	return msci::charge(x, "zC");
}

msci::charge operator"" _yC(long double x)
{
	return msci::charge(x, "yC");
}

msci::temperature operator"" _YK(long double x)
{
	return msci::temperature(x, "YK");
}

msci::temperature operator"" _ZK(long double x)
{
	return msci::temperature(x, "ZK");
}

msci::temperature operator"" _EK(long double x)
{
	return msci::temperature(x, "EK");
}

msci::temperature operator"" _PK(long double x)
{
	return msci::temperature(x, "PK");
}

msci::temperature operator"" _TK(long double x)
{
	return msci::temperature(x, "TK");
}

msci::temperature operator"" _GK(long double x)
{
	return msci::temperature(x, "GK");
}

msci::temperature operator"" _MK(long double x)
{
	return msci::temperature(x, "MK");
}

msci::temperature operator"" _kK(long double x)
{
	return msci::temperature(x, "kK");
}

msci::temperature operator"" _hK(long double x)
{
	return msci::temperature(x, "hK");
}

msci::temperature operator"" _daK(long double x)
{
	return msci::temperature(x, "daK");
}

msci::temperature operator"" _K(long double x)
{
	return msci::temperature(x, "K");
}

msci::temperature operator"" _dK(long double x)
{
	return msci::temperature(x, "dK");
}

msci::temperature operator"" _cK(long double x)
{
	return msci::temperature(x, "cK");
}

msci::temperature operator"" _mK(long double x)
{
	return msci::temperature(x, "mK");
}

msci::temperature operator"" _uK(long double x)
{
	return msci::temperature(x, "uK");
}

msci::temperature operator"" _nK(long double x)
{
	return msci::temperature(x, "nK");
}

msci::temperature operator"" _pK(long double x)
{
	return msci::temperature(x, "pK");
}

msci::temperature operator"" _fK(long double x)
{
	return msci::temperature(x, "fK");
}

msci::temperature operator"" _aK(long double x)
{
	return msci::temperature(x, "aK");
}

msci::temperature operator"" _zK(long double x)
{
	return msci::temperature(x, "zK");
}

msci::temperature operator"" _yK(long double x)
{
	return msci::temperature(x, "yK");
}

msci::mole operator"" _Ymol(long double x)
{
	return msci::mole(x, "Ymol");
}

msci::mole operator"" _Zmol(long double x)
{
	return msci::mole(x, "Zmol");
}

msci::mole operator"" _Emol(long double x)
{
	return msci::mole(x, "Emol");
}

msci::mole operator"" _Pmol(long double x)
{
	return msci::mole(x, "Pmol");
}

msci::mole operator"" _Tmol(long double x)
{
	return msci::mole(x, "Tmol");
}

msci::mole operator"" _Gmol(long double x)
{
	return msci::mole(x, "Gmol");
}

msci::mole operator"" _Mmol(long double x)
{
	return msci::mole(x, "Mmol");
}

msci::mole operator"" _kmol(long double x)
{
	return msci::mole(x, "kmol");
}

msci::mole operator"" _hmol(long double x)
{
	return msci::mole(x, "hmol");
}

msci::mole operator"" _damol(long double x)
{
	return msci::mole(x, "damol");
}

msci::mole operator"" _mol(long double x)
{
	return msci::mole(x, "mol");
}

msci::mole operator"" _dmol(long double x)
{
	return msci::mole(x, "dmol");
}

msci::mole operator"" _cmol(long double x)
{
	return msci::mole(x, "cmol");
}

msci::mole operator"" _mmol(long double x)
{
	return msci::mole(x, "mmol");
}

msci::mole operator"" _umol(long double x)
{
	return msci::mole(x, "umol");
}

msci::mole operator"" _nmol(long double x)
{
	return msci::mole(x, "nmol");
}

msci::mole operator"" _pmol(long double x)
{
	return msci::mole(x, "pmol");
}

msci::mole operator"" _fmol(long double x)
{
	return msci::mole(x, "fmol");
}

msci::mole operator"" _amol(long double x)
{
	return msci::mole(x, "amol");
}

msci::mole operator"" _zmol(long double x)
{
	return msci::mole(x, "zmol");
}

msci::mole operator"" _ymol(long double x)
{
	return msci::mole(x, "ymol");
}

msci::light operator"" _Ycd(long double x)
{
	return msci::light(x, "Ycd");
}

msci::light operator"" _Zcd(long double x)
{
	return msci::light(x, "Zcd");
}

msci::light operator"" _Ecd(long double x)
{
	return msci::light(x, "Ecd");
}

msci::light operator"" _Pcd(long double x)
{
	return msci::light(x, "Pcd");
}

msci::light operator"" _Tcd(long double x)
{
	return msci::light(x, "Tcd");
}

msci::light operator"" _Gcd(long double x)
{
	return msci::light(x, "Gcd");
}

msci::light operator"" _Mcd(long double x)
{
	return msci::light(x, "Mcd");
}

msci::light operator"" _kcd(long double x)
{
	return msci::light(x, "kcd");
}

msci::light operator"" _hcd(long double x)
{
	return msci::light(x, "hcd");
}

msci::light operator"" _dacd(long double x)
{
	return msci::light(x, "dacd");
}

msci::light operator"" _cd(long double x)
{
	return msci::light(x, "cd");
}

msci::light operator"" _dcd(long double x)
{
	return msci::light(x, "dcd");
}

msci::light operator"" _ccd(long double x)
{
	return msci::light(x, "ccd");
}

msci::light operator"" _mcd(long double x)
{
	return msci::light(x, "mcd");
}

msci::light operator"" _ucd(long double x)
{
	return msci::light(x, "ucd");
}

msci::light operator"" _ncd(long double x)
{
	return msci::light(x, "ncd");
}

msci::light operator"" _pcd(long double x)
{
	return msci::light(x, "pcd");
}

msci::light operator"" _fcd(long double x)
{
	return msci::light(x, "fcd");
}

msci::light operator"" _acd(long double x)
{
	return msci::light(x, "acd");
}

msci::light operator"" _zcd(long double x)
{
	return msci::light(x, "zcd");
}

msci::light operator"" _ycd(long double x)
{
	return msci::light(x, "ycd");
}

msci::data operator"" _YB(long double x)
{
	return msci::data(x, "YB");
}

msci::data operator"" _ZB(long double x)
{
	return msci::data(x, "ZB");
}

msci::data operator"" _EB(long double x)
{
	return msci::data(x, "EB");
}

msci::data operator"" _PB(long double x)
{
	return msci::data(x, "PB");
}

msci::data operator"" _TB(long double x)
{
	return msci::data(x, "TB");
}

msci::data operator"" _GB(long double x)
{
	return msci::data(x, "GB");
}

msci::data operator"" _MB(long double x)
{
	return msci::data(x, "MB");
}

msci::data operator"" _kB(long double x)
{
	return msci::data(x, "kB");
}

msci::data operator"" _B(long double x)
{
	return msci::data(x, "B");
}
