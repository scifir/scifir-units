#include "unit_basic.hpp"
#include "unit.hpp"
#include "dimension.hpp"
#include "prefix.hpp"
#include "math/number/unit_number.hpp"
#include "chemistry/constants.hpp"

#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <type_traits>

using namespace std;

namespace msci::units
{
	SCALAR_UNIT_CPP(length,"m");
	SCALAR_UNIT_CPP(time,"s");

	time::operator std::chrono::seconds() const
	{
		msci::units::time a = *this;
		a.change_dimensions("s");
		return std::chrono::seconds(int(a.get_value()));
	}

	wstring time::get_finish_date() const
	{
		chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
		start += chrono::seconds(*this);
		std::time_t start_time = std::chrono::system_clock::to_time_t(start);
		wstringstream output;
		output << ctime(&start_time);
		return output.str();
	}

	SCALAR_UNIT_CPP(mass,"g");
	SCALAR_UNIT_CPP(charge,"C");

	temperature::temperature(msci::space_type new_value,const string& init_value) : unit(new_value,init_value),scalar_unit_crtp<temperature>(new_value,init_value)
	{
	}

	temperature::temperature(const string& init_value) : unit(),scalar_unit_crtp<temperature>()
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
			msci::unit_number new_value = 0;
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
			else if (final_string == "K")
			{
				new_value = stold(init_value.substr(0,i));
				new_real_dimensions[K] = shared_ptr<dimension>(new_real_dimension);
				new_actual_dimensions[K] = shared_ptr<dimension_abstract>(new_actual_dimension);
			}
			else
			{
				throw invalid_argument("Temperature string does not contains °C or °F");
			}
			//value = new_value;
			//actual_dimensions = new_actual_dimensions;
			*this = auto_scalar(new_value,new_real_dimensions,new_actual_dimensions);
		}
	}

	temperature::temperature(const unit& x) : unit(x),scalar_unit_crtp<temperature>(x)
	{
	}

	temperature::temperature(unit&& x) : unit(move(x)),scalar_unit_crtp<temperature>(move(x))
	{
	}

	temperature::temperature(const unit& new_unit,const string& init_value) : unit(new_unit,init_value),scalar_unit_crtp<temperature>(new_unit,init_value)
	{
	}

	temperature::temperature(unit&& new_unit,const string& init_value) : unit(move(new_unit),init_value),scalar_unit_crtp<temperature>(move(new_unit),init_value)
	{
	}

	temperature::temperature(const temperature& x) : unit(x),scalar_unit_crtp<temperature>(x)
	{
	}

	temperature::temperature(temperature&& x) : unit(move(x)),scalar_unit_crtp<temperature>(move(x))
	{
	}

	temperature& temperature::operator =(const temperature& x)
	{
		scalar_unit_crtp<temperature>::operator=(x);
		return *this;
	}

	temperature& temperature::operator =(temperature&& x)
	{
		scalar_unit_crtp<temperature>::operator=(move(x));
		return *this;
	}

	temperature& temperature::operator =(const unit& x)
	{
		unit::operator=(x);
		return *this;
	}

	temperature& temperature::operator =(unit&& x)
	{
		unit::operator=(move(x));
		return *this;
	}

	const string temperature::dimensions_match = "K";
	const vector_real_dimensions temperature::real_dimensions = create_real_dimensions("K");

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

	SCALAR_UNIT_CPP(mole,"mol");

	int mole::number_of_particles() const
	{
		if (unit::actual_dimensions.count(particles))
		{
			return unit::value;
		}
		else
		{
			return unit::value*msci::avogadro_constant;
		}
	}

	SCALAR_UNIT_CPP(light,"cd");
	SCALAR_UNIT_CPP(data,"B");
}

wostream& operator <<(wostream& os, const msci::units::time& x)
{
	if (x.get_display_mode() == msci::units::display_mode::time_display)
	{
		wostringstream output;
		msci::units::time remaining_time = x;
		msci::units::time one_year ("365 d");
		if (x >= one_year)
		{
			int total_of_years = int(trunc((x / one_year).get_value()));
			output << total_of_years << L"y ";
			remaining_time -= msci::units::time(total_of_years * 365,"d");
		}
		msci::units::time one_month("30 d");
		if (remaining_time >= one_month)
		{
			int total_of_months = int(trunc((remaining_time / one_month).get_value()));
			output << total_of_months << L"m ";
			remaining_time -= msci::units::time(total_of_months * 30,"d");
		}
		msci::units::time one_day("1 d");
		if (remaining_time >= one_day)
		{
			int total_of_days = int(trunc((remaining_time / one_day).get_value()));
			output << total_of_days << L"d ";
			remaining_time -= msci::units::time(total_of_days,"d");
		}
		msci::units::time one_hour("1 h");
		if (remaining_time >= one_hour)
		{
			int total_of_hours = int(trunc((remaining_time / one_hour).get_value()));
			output << total_of_hours << L"h ";
			remaining_time -= msci::units::time(total_of_hours,"h");
		}
		msci::units::time one_minute("1 min");
		if (remaining_time >= one_minute)
		{
			int total_of_minutes = int(trunc((remaining_time / one_minute).get_value()));
			output << total_of_minutes << L"min ";
			remaining_time -= msci::units::time(total_of_minutes,"min");
		}
		msci::units::time one_second("1 s");
		if (remaining_time >= one_second)
		{
			remaining_time.change_dimensions("s");
			float total_of_seconds = float(remaining_time.get_value());
			output << total_of_seconds << L"s";
		}
		return os << output.str();
	}
	else
	{
		return os << static_cast<const msci::units::unit&>(x);
	}
}

msci::units::length operator"" _Ym(unsigned long long int x)
{
	return msci::units::length(x, "Ym");
}

msci::units::length operator"" _Zm(unsigned long long int x)
{
	return msci::units::length(x, "Zm");
}

msci::units::length operator"" _Em(unsigned long long int x)
{
	return msci::units::length(x, "Em");
}

msci::units::length operator"" _Pm(unsigned long long int x)
{
	return msci::units::length(x, "Pm");
}

msci::units::length operator"" _Tm(unsigned long long int x)
{
	return msci::units::length(x, "Tm");
}

msci::units::length operator"" _Gm(unsigned long long int x)
{
	return msci::units::length(x, "Gm");
}

msci::units::length operator"" _Mm(unsigned long long int x)
{
	return msci::units::length(x, "Mm");
}

msci::units::length operator"" _km(unsigned long long int x)
{
	return msci::units::length(x, "km");
}

msci::units::length operator"" _hm(unsigned long long int x)
{
	return msci::units::length(x, "hm");
}

msci::units::length operator"" _dam(unsigned long long int x)
{
	return msci::units::length(x, "dam");
}

msci::units::length operator"" _m(unsigned long long int x)
{
	return msci::units::length(x, "m");
}

msci::units::length operator"" _dm(unsigned long long int x)
{
	return msci::units::length(x, "dm");
}

msci::units::length operator"" _cm(unsigned long long int x)
{
	return msci::units::length(x, "cm");
}

msci::units::length operator"" _mm(unsigned long long int x)
{
	return msci::units::length(x, "mm");
}

msci::units::length operator"" _um(unsigned long long int x)
{
	return msci::units::length(x, "um");
}

msci::units::length operator"" _nm(unsigned long long int x)
{
	return msci::units::length(x, "nm");
}

msci::units::length operator"" _pm(unsigned long long int x)
{
	return msci::units::length(x, "pm");
}

msci::units::length operator"" _fm(unsigned long long int x)
{
	return msci::units::length(x, "fm");
}

msci::units::length operator"" _am(unsigned long long int x)
{
	return msci::units::length(x, "am");
}

msci::units::length operator"" _zm(unsigned long long int x)
{
	return msci::units::length(x, "zm");
}

msci::units::length operator"" _ym(unsigned long long int x)
{
	return msci::units::length(x, "ym");
}

msci::units::time operator"" _s(unsigned long long int x)
{
	return msci::units::time(x, "s");
}

msci::units::time operator"" _ms(unsigned long long int x)
{
	return msci::units::time(x, "ms");
}

msci::units::time operator"" _us(unsigned long long int x)
{
	return msci::units::time(x, "us");
}

msci::units::time operator"" _ns(unsigned long long int x)
{
	return msci::units::time(x, "ns");
}

msci::units::time operator"" _ps(unsigned long long int x)
{
	return msci::units::time(x, "ps");
}

msci::units::time operator"" _fs(unsigned long long int x)
{
	return msci::units::time(x, "fs");
}

msci::units::time operator"" _as(unsigned long long int x)
{
	return msci::units::time(x, "as");
}

msci::units::time operator"" _zs(unsigned long long int x)
{
	return msci::units::time(x, "zs");
}

msci::units::time operator"" _ys(unsigned long long int x)
{
	return msci::units::time(x, "ys");
}

msci::units::mass operator"" _Yg(unsigned long long int x)
{
	return msci::units::mass(x, "Yg");
}

msci::units::mass operator"" _Zg(unsigned long long int x)
{
	return msci::units::mass(x, "Zg");
}

msci::units::mass operator"" _Eg(unsigned long long int x)
{
	return msci::units::mass(x, "Eg");
}

msci::units::mass operator"" _Pg(unsigned long long int x)
{
	return msci::units::mass(x, "Pg");
}

msci::units::mass operator"" _Tg(unsigned long long int x)
{
	return msci::units::mass(x, "Tg");
}

msci::units::mass operator"" _Gg(unsigned long long int x)
{
	return msci::units::mass(x, "Gg");
}

msci::units::mass operator"" _Mg(unsigned long long int x)
{
	return msci::units::mass(x, "Mg");
}

msci::units::mass operator"" _kg(unsigned long long int x)
{
	return msci::units::mass(x, "kg");
}

msci::units::mass operator"" _hg(unsigned long long int x)
{
	return msci::units::mass(x, "hg");
}

msci::units::mass operator"" _dag(unsigned long long int x)
{
	return msci::units::mass(x, "dag");
}

msci::units::mass operator"" _g(unsigned long long int x)
{
	return msci::units::mass(x, "g");
}

msci::units::mass operator"" _dg(unsigned long long int x)
{
	return msci::units::mass(x, "dg");
}

msci::units::mass operator"" _cg(unsigned long long int x)
{
	return msci::units::mass(x, "cg");
}

msci::units::mass operator"" _mg(unsigned long long int x)
{
	return msci::units::mass(x, "mg");
}

msci::units::mass operator"" _ug(unsigned long long int x)
{
	return msci::units::mass(x, "ug");
}

msci::units::mass operator"" _ng(unsigned long long int x)
{
	return msci::units::mass(x, "ng");
}

msci::units::mass operator"" _pg(unsigned long long int x)
{
	return msci::units::mass(x, "pg");
}

msci::units::mass operator"" _fg(unsigned long long int x)
{
	return msci::units::mass(x, "fg");
}

msci::units::mass operator"" _ag(unsigned long long int x)
{
	return msci::units::mass(x, "ag");
}

msci::units::mass operator"" _zg(unsigned long long int x)
{
	return msci::units::mass(x, "zg");
}

msci::units::mass operator"" _yg(unsigned long long int x)
{
	return msci::units::mass(x, "yg");
}

msci::units::charge operator"" _YC(unsigned long long int x)
{
	return msci::units::charge(x, "YC");
}

msci::units::charge operator"" _ZC(unsigned long long int x)
{
	return msci::units::charge(x, "ZC");
}

msci::units::charge operator"" _EC(unsigned long long int x)
{
	return msci::units::charge(x, "EC");
}

msci::units::charge operator"" _PC(unsigned long long int x)
{
	return msci::units::charge(x, "PC");
}

msci::units::charge operator"" _TC(unsigned long long int x)
{
	return msci::units::charge(x, "TC");
}

msci::units::charge operator"" _GC(unsigned long long int x)
{
	return msci::units::charge(x, "GC");
}

msci::units::charge operator"" _MC(unsigned long long int x)
{
	return msci::units::charge(x, "MC");
}

msci::units::charge operator"" _kC(unsigned long long int x)
{
	return msci::units::charge(x, "kC");
}

msci::units::charge operator"" _hC(unsigned long long int x)
{
	return msci::units::charge(x, "hC");
}

msci::units::charge operator"" _daC(unsigned long long int x)
{
	return msci::units::charge(x, "daC");
}

msci::units::charge operator"" _C(unsigned long long int x)
{
	return msci::units::charge(x, "C");
}

msci::units::charge operator"" _dC(unsigned long long int x)
{
	return msci::units::charge(x, "dC");
}

msci::units::charge operator"" _cC(unsigned long long int x)
{
	return msci::units::charge(x, "cC");
}

msci::units::charge operator"" _mC(unsigned long long int x)
{
	return msci::units::charge(x, "mC");
}

msci::units::charge operator"" _uC(unsigned long long int x)
{
	return msci::units::charge(x, "uC");
}

msci::units::charge operator"" _nC(unsigned long long int x)
{
	return msci::units::charge(x, "nC");
}

msci::units::charge operator"" _pC(unsigned long long int x)
{
	return msci::units::charge(x, "pC");
}

msci::units::charge operator"" _fC(unsigned long long int x)
{
	return msci::units::charge(x, "fC");
}

msci::units::charge operator"" _aC(unsigned long long int x)
{
	return msci::units::charge(x, "aC");
}

msci::units::charge operator"" _zC(unsigned long long int x)
{
	return msci::units::charge(x, "zC");
}

msci::units::charge operator"" _yC(unsigned long long int x)
{
	return msci::units::charge(x, "yC");
}

msci::units::temperature operator"" _YK(unsigned long long int x)
{
	return msci::units::temperature(x, "YK");
}

msci::units::temperature operator"" _ZK(unsigned long long int x)
{
	return msci::units::temperature(x, "ZK");
}

msci::units::temperature operator"" _EK(unsigned long long int x)
{
	return msci::units::temperature(x, "EK");
}

msci::units::temperature operator"" _PK(unsigned long long int x)
{
	return msci::units::temperature(x, "PK");
}

msci::units::temperature operator"" _TK(unsigned long long int x)
{
	return msci::units::temperature(x, "TK");
}

msci::units::temperature operator"" _GK(unsigned long long int x)
{
	return msci::units::temperature(x, "GK");
}

msci::units::temperature operator"" _MK(unsigned long long int x)
{
	return msci::units::temperature(x, "MK");
}

msci::units::temperature operator"" _kK(unsigned long long int x)
{
	return msci::units::temperature(x, "kK");
}

msci::units::temperature operator"" _hK(unsigned long long int x)
{
	return msci::units::temperature(x, "hK");
}

msci::units::temperature operator"" _daK(unsigned long long int x)
{
	return msci::units::temperature(x, "daK");
}

msci::units::temperature operator"" _K(unsigned long long int x)
{
	return msci::units::temperature(x, "K");
}

msci::units::temperature operator"" _dK(unsigned long long int x)
{
	return msci::units::temperature(x, "dK");
}

msci::units::temperature operator"" _cK(unsigned long long int x)
{
	return msci::units::temperature(x, "cK");
}

msci::units::temperature operator"" _mK(unsigned long long int x)
{
	return msci::units::temperature(x, "mK");
}

msci::units::temperature operator"" _uK(unsigned long long int x)
{
	return msci::units::temperature(x, "uK");
}

msci::units::temperature operator"" _nK(unsigned long long int x)
{
	return msci::units::temperature(x, "nK");
}

msci::units::temperature operator"" _pK(unsigned long long int x)
{
	return msci::units::temperature(x, "pK");
}

msci::units::temperature operator"" _fK(unsigned long long int x)
{
	return msci::units::temperature(x, "fK");
}

msci::units::temperature operator"" _aK(unsigned long long int x)
{
	return msci::units::temperature(x, "aK");
}

msci::units::temperature operator"" _zK(unsigned long long int x)
{
	return msci::units::temperature(x, "zK");
}

msci::units::temperature operator"" _yK(unsigned long long int x)
{
	return msci::units::temperature(x, "yK");
}

msci::units::mole operator"" _Ymol(unsigned long long int x)
{
	return msci::units::mole(x, "Ymol");
}

msci::units::mole operator"" _Zmol(unsigned long long int x)
{
	return msci::units::mole(x, "Zmol");
}

msci::units::mole operator"" _Emol(unsigned long long int x)
{
	return msci::units::mole(x, "Emol");
}

msci::units::mole operator"" _Pmol(unsigned long long int x)
{
	return msci::units::mole(x, "Pmol");
}

msci::units::mole operator"" _Tmol(unsigned long long int x)
{
	return msci::units::mole(x, "Tmol");
}

msci::units::mole operator"" _Gmol(unsigned long long int x)
{
	return msci::units::mole(x, "Gmol");
}

msci::units::mole operator"" _Mmol(unsigned long long int x)
{
	return msci::units::mole(x, "Mmol");
}

msci::units::mole operator"" _kmol(unsigned long long int x)
{
	return msci::units::mole(x, "kmol");
}

msci::units::mole operator"" _hmol(unsigned long long int x)
{
	return msci::units::mole(x, "hmol");
}

msci::units::mole operator"" _damol(unsigned long long int x)
{
	return msci::units::mole(x, "damol");
}

msci::units::mole operator"" _mol(unsigned long long int x)
{
	return msci::units::mole(x, "mol");
}

msci::units::mole operator"" _dmol(unsigned long long int x)
{
	return msci::units::mole(x, "dmol");
}

msci::units::mole operator"" _cmol(unsigned long long int x)
{
	return msci::units::mole(x, "cmol");
}

msci::units::mole operator"" _mmol(unsigned long long int x)
{
	return msci::units::mole(x, "mmol");
}

msci::units::mole operator"" _umol(unsigned long long int x)
{
	return msci::units::mole(x, "umol");
}

msci::units::mole operator"" _nmol(unsigned long long int x)
{
	return msci::units::mole(x, "nmol");
}

msci::units::mole operator"" _pmol(unsigned long long int x)
{
	return msci::units::mole(x, "pmol");
}

msci::units::mole operator"" _fmol(unsigned long long int x)
{
	return msci::units::mole(x, "fmol");
}

msci::units::mole operator"" _amol(unsigned long long int x)
{
	return msci::units::mole(x, "amol");
}

msci::units::mole operator"" _zmol(unsigned long long int x)
{
	return msci::units::mole(x, "zmol");
}

msci::units::mole operator"" _ymol(unsigned long long int x)
{
	return msci::units::mole(x, "ymol");
}

msci::units::light operator"" _Ycd(unsigned long long int x)
{
	return msci::units::light(x, "Ycd");
}

msci::units::light operator"" _Zcd(unsigned long long int x)
{
	return msci::units::light(x, "Zcd");
}

msci::units::light operator"" _Ecd(unsigned long long int x)
{
	return msci::units::light(x, "Ecd");
}

msci::units::light operator"" _Pcd(unsigned long long int x)
{
	return msci::units::light(x, "Pcd");
}

msci::units::light operator"" _Tcd(unsigned long long int x)
{
	return msci::units::light(x, "Tcd");
}

msci::units::light operator"" _Gcd(unsigned long long int x)
{
	return msci::units::light(x, "Gcd");
}

msci::units::light operator"" _Mcd(unsigned long long int x)
{
	return msci::units::light(x, "Mcd");
}

msci::units::light operator"" _kcd(unsigned long long int x)
{
	return msci::units::light(x, "kcd");
}

msci::units::light operator"" _hcd(unsigned long long int x)
{
	return msci::units::light(x, "hcd");
}

msci::units::light operator"" _dacd(unsigned long long int x)
{
	return msci::units::light(x, "dacd");
}

msci::units::light operator"" _cd(unsigned long long int x)
{
	return msci::units::light(x, "cd");
}

msci::units::light operator"" _dcd(unsigned long long int x)
{
	return msci::units::light(x, "dcd");
}

msci::units::light operator"" _ccd(unsigned long long int x)
{
	return msci::units::light(x, "ccd");
}

msci::units::light operator"" _mcd(unsigned long long int x)
{
	return msci::units::light(x, "mcd");
}

msci::units::light operator"" _ucd(unsigned long long int x)
{
	return msci::units::light(x, "ucd");
}

msci::units::light operator"" _ncd(unsigned long long int x)
{
	return msci::units::light(x, "ncd");
}

msci::units::light operator"" _pcd(unsigned long long int x)
{
	return msci::units::light(x, "pcd");
}

msci::units::light operator"" _fcd(unsigned long long int x)
{
	return msci::units::light(x, "fcd");
}

msci::units::light operator"" _acd(unsigned long long int x)
{
	return msci::units::light(x, "acd");
}

msci::units::light operator"" _zcd(unsigned long long int x)
{
	return msci::units::light(x, "zcd");
}

msci::units::light operator"" _ycd(unsigned long long int x)
{
	return msci::units::light(x, "ycd");
}

msci::units::data operator"" _YB(unsigned long long int x)
{
	return msci::units::data(x, "YB");
}

msci::units::data operator"" _ZB(unsigned long long int x)
{
	return msci::units::data(x, "ZB");
}

msci::units::data operator"" _EB(unsigned long long int x)
{
	return msci::units::data(x, "EB");
}

msci::units::data operator"" _PB(unsigned long long int x)
{
	return msci::units::data(x, "PB");
}

msci::units::data operator"" _TB(unsigned long long int x)
{
	return msci::units::data(x, "TB");
}

msci::units::data operator"" _GB(unsigned long long int x)
{
	return msci::units::data(x, "GB");
}

msci::units::data operator"" _MB(unsigned long long int x)
{
	return msci::units::data(x, "MB");
}

msci::units::data operator"" _kB(unsigned long long int x)
{
	return msci::units::data(x, "kB");
}

msci::units::data operator"" _B(unsigned long long int x)
{
	return msci::units::data(x, "B");
}

msci::units::length operator"" _Ym(long double x)
{
	return msci::units::length(x, "Ym");
}

msci::units::length operator"" _Zm(long double x)
{
	return msci::units::length(x, "Zm");
}

msci::units::length operator"" _Em(long double x)
{
	return msci::units::length(x, "Em");
}

msci::units::length operator"" _Pm(long double x)
{
	return msci::units::length(x, "Pm");
}

msci::units::length operator"" _Tm(long double x)
{
	return msci::units::length(x, "Tm");
}

msci::units::length operator"" _Gm(long double x)
{
	return msci::units::length(x, "Gm");
}

msci::units::length operator"" _Mm(long double x)
{
	return msci::units::length(x, "Mm");
}

msci::units::length operator"" _km(long double x)
{
	return msci::units::length(x, "km");
}

msci::units::length operator"" _hm(long double x)
{
	return msci::units::length(x, "hm");
}

msci::units::length operator"" _dam(long double x)
{
	return msci::units::length(x, "dam");
}

msci::units::length operator"" _m(long double x)
{
	return msci::units::length(x, "m");
}

msci::units::length operator"" _dm(long double x)
{
	return msci::units::length(x, "dm");
}

msci::units::length operator"" _cm(long double x)
{
	return msci::units::length(x, "cm");
}

msci::units::length operator"" _mm(long double x)
{
	return msci::units::length(x, "mm");
}

msci::units::length operator"" _um(long double x)
{
	return msci::units::length(x, "um");
}

msci::units::length operator"" _nm(long double x)
{
	return msci::units::length(x, "nm");
}

msci::units::length operator"" _pm(long double x)
{
	return msci::units::length(x, "pm");
}

msci::units::length operator"" _fm(long double x)
{
	return msci::units::length(x, "fm");
}

msci::units::length operator"" _am(long double x)
{
	return msci::units::length(x, "am");
}

msci::units::length operator"" _zm(long double x)
{
	return msci::units::length(x, "zm");
}

msci::units::length operator"" _ym(long double x)
{
	return msci::units::length(x, "ym");
}

msci::units::time operator"" _s(long double x)
{
	return msci::units::time(x, "s");
}

msci::units::time operator"" _ms(long double x)
{
	return msci::units::time(x, "ms");
}

msci::units::time operator"" _us(long double x)
{
	return msci::units::time(x, "us");
}

msci::units::time operator"" _ns(long double x)
{
	return msci::units::time(x, "ns");
}

msci::units::time operator"" _ps(long double x)
{
	return msci::units::time(x, "ps");
}

msci::units::time operator"" _fs(long double x)
{
	return msci::units::time(x, "fs");
}

msci::units::time operator"" _as(long double x)
{
	return msci::units::time(x, "as");
}

msci::units::time operator"" _zs(long double x)
{
	return msci::units::time(x, "zs");
}

msci::units::time operator"" _ys(long double x)
{
	return msci::units::time(x, "ys");
}

msci::units::mass operator"" _Yg(long double x)
{
	return msci::units::mass(x, "Yg");
}

msci::units::mass operator"" _Zg(long double x)
{
	return msci::units::mass(x, "Zg");
}

msci::units::mass operator"" _Eg(long double x)
{
	return msci::units::mass(x, "Eg");
}

msci::units::mass operator"" _Pg(long double x)
{
	return msci::units::mass(x, "Pg");
}

msci::units::mass operator"" _Tg(long double x)
{
	return msci::units::mass(x, "Tg");
}

msci::units::mass operator"" _Gg(long double x)
{
	return msci::units::mass(x, "Gg");
}

msci::units::mass operator"" _Mg(long double x)
{
	return msci::units::mass(x, "Mg");
}

msci::units::mass operator"" _kg(long double x)
{
	return msci::units::mass(x, "kg");
}

msci::units::mass operator"" _hg(long double x)
{
	return msci::units::mass(x, "hg");
}

msci::units::mass operator"" _dag(long double x)
{
	return msci::units::mass(x, "dag");
}

msci::units::mass operator"" _g(long double x)
{
	return msci::units::mass(x, "g");
}

msci::units::mass operator"" _dg(long double x)
{
	return msci::units::mass(x, "dg");
}

msci::units::mass operator"" _cg(long double x)
{
	return msci::units::mass(x, "cg");
}

msci::units::mass operator"" _mg(long double x)
{
	return msci::units::mass(x, "mg");
}

msci::units::mass operator"" _ug(long double x)
{
	return msci::units::mass(x, "ug");
}

msci::units::mass operator"" _ng(long double x)
{
	return msci::units::mass(x, "ng");
}

msci::units::mass operator"" _pg(long double x)
{
	return msci::units::mass(x, "pg");
}

msci::units::mass operator"" _fg(long double x)
{
	return msci::units::mass(x, "fg");
}

msci::units::mass operator"" _ag(long double x)
{
	return msci::units::mass(x, "ag");
}

msci::units::mass operator"" _zg(long double x)
{
	return msci::units::mass(x, "zg");
}

msci::units::mass operator"" _yg(long double x)
{
	return msci::units::mass(x, "yg");
}

msci::units::charge operator"" _YC(long double x)
{
	return msci::units::charge(x, "YC");
}

msci::units::charge operator"" _ZC(long double x)
{
	return msci::units::charge(x, "ZC");
}

msci::units::charge operator"" _EC(long double x)
{
	return msci::units::charge(x, "EC");
}

msci::units::charge operator"" _PC(long double x)
{
	return msci::units::charge(x, "PC");
}

msci::units::charge operator"" _TC(long double x)
{
	return msci::units::charge(x, "TC");
}

msci::units::charge operator"" _GC(long double x)
{
	return msci::units::charge(x, "GC");
}

msci::units::charge operator"" _MC(long double x)
{
	return msci::units::charge(x, "MC");
}

msci::units::charge operator"" _kC(long double x)
{
	return msci::units::charge(x, "kC");
}

msci::units::charge operator"" _hC(long double x)
{
	return msci::units::charge(x, "hC");
}

msci::units::charge operator"" _daC(long double x)
{
	return msci::units::charge(x, "daC");
}

msci::units::charge operator"" _C(long double x)
{
	return msci::units::charge(x, "C");
}

msci::units::charge operator"" _dC(long double x)
{
	return msci::units::charge(x, "dC");
}

msci::units::charge operator"" _cC(long double x)
{
	return msci::units::charge(x, "cC");
}

msci::units::charge operator"" _mC(long double x)
{
	return msci::units::charge(x, "mC");
}

msci::units::charge operator"" _uC(long double x)
{
	return msci::units::charge(x, "uC");
}

msci::units::charge operator"" _nC(long double x)
{
	return msci::units::charge(x, "nC");
}

msci::units::charge operator"" _pC(long double x)
{
	return msci::units::charge(x, "pC");
}

msci::units::charge operator"" _fC(long double x)
{
	return msci::units::charge(x, "fC");
}

msci::units::charge operator"" _aC(long double x)
{
	return msci::units::charge(x, "aC");
}

msci::units::charge operator"" _zC(long double x)
{
	return msci::units::charge(x, "zC");
}

msci::units::charge operator"" _yC(long double x)
{
	return msci::units::charge(x, "yC");
}

msci::units::temperature operator"" _YK(long double x)
{
	return msci::units::temperature(x, "YK");
}

msci::units::temperature operator"" _ZK(long double x)
{
	return msci::units::temperature(x, "ZK");
}

msci::units::temperature operator"" _EK(long double x)
{
	return msci::units::temperature(x, "EK");
}

msci::units::temperature operator"" _PK(long double x)
{
	return msci::units::temperature(x, "PK");
}

msci::units::temperature operator"" _TK(long double x)
{
	return msci::units::temperature(x, "TK");
}

msci::units::temperature operator"" _GK(long double x)
{
	return msci::units::temperature(x, "GK");
}

msci::units::temperature operator"" _MK(long double x)
{
	return msci::units::temperature(x, "MK");
}

msci::units::temperature operator"" _kK(long double x)
{
	return msci::units::temperature(x, "kK");
}

msci::units::temperature operator"" _hK(long double x)
{
	return msci::units::temperature(x, "hK");
}

msci::units::temperature operator"" _daK(long double x)
{
	return msci::units::temperature(x, "daK");
}

msci::units::temperature operator"" _K(long double x)
{
	return msci::units::temperature(x, "K");
}

msci::units::temperature operator"" _dK(long double x)
{
	return msci::units::temperature(x, "dK");
}

msci::units::temperature operator"" _cK(long double x)
{
	return msci::units::temperature(x, "cK");
}

msci::units::temperature operator"" _mK(long double x)
{
	return msci::units::temperature(x, "mK");
}

msci::units::temperature operator"" _uK(long double x)
{
	return msci::units::temperature(x, "uK");
}

msci::units::temperature operator"" _nK(long double x)
{
	return msci::units::temperature(x, "nK");
}

msci::units::temperature operator"" _pK(long double x)
{
	return msci::units::temperature(x, "pK");
}

msci::units::temperature operator"" _fK(long double x)
{
	return msci::units::temperature(x, "fK");
}

msci::units::temperature operator"" _aK(long double x)
{
	return msci::units::temperature(x, "aK");
}

msci::units::temperature operator"" _zK(long double x)
{
	return msci::units::temperature(x, "zK");
}

msci::units::temperature operator"" _yK(long double x)
{
	return msci::units::temperature(x, "yK");
}

msci::units::mole operator"" _Ymol(long double x)
{
	return msci::units::mole(x, "Ymol");
}

msci::units::mole operator"" _Zmol(long double x)
{
	return msci::units::mole(x, "Zmol");
}

msci::units::mole operator"" _Emol(long double x)
{
	return msci::units::mole(x, "Emol");
}

msci::units::mole operator"" _Pmol(long double x)
{
	return msci::units::mole(x, "Pmol");
}

msci::units::mole operator"" _Tmol(long double x)
{
	return msci::units::mole(x, "Tmol");
}

msci::units::mole operator"" _Gmol(long double x)
{
	return msci::units::mole(x, "Gmol");
}

msci::units::mole operator"" _Mmol(long double x)
{
	return msci::units::mole(x, "Mmol");
}

msci::units::mole operator"" _kmol(long double x)
{
	return msci::units::mole(x, "kmol");
}

msci::units::mole operator"" _hmol(long double x)
{
	return msci::units::mole(x, "hmol");
}

msci::units::mole operator"" _damol(long double x)
{
	return msci::units::mole(x, "damol");
}

msci::units::mole operator"" _mol(long double x)
{
	return msci::units::mole(x, "mol");
}

msci::units::mole operator"" _dmol(long double x)
{
	return msci::units::mole(x, "dmol");
}

msci::units::mole operator"" _cmol(long double x)
{
	return msci::units::mole(x, "cmol");
}

msci::units::mole operator"" _mmol(long double x)
{
	return msci::units::mole(x, "mmol");
}

msci::units::mole operator"" _umol(long double x)
{
	return msci::units::mole(x, "umol");
}

msci::units::mole operator"" _nmol(long double x)
{
	return msci::units::mole(x, "nmol");
}

msci::units::mole operator"" _pmol(long double x)
{
	return msci::units::mole(x, "pmol");
}

msci::units::mole operator"" _fmol(long double x)
{
	return msci::units::mole(x, "fmol");
}

msci::units::mole operator"" _amol(long double x)
{
	return msci::units::mole(x, "amol");
}

msci::units::mole operator"" _zmol(long double x)
{
	return msci::units::mole(x, "zmol");
}

msci::units::mole operator"" _ymol(long double x)
{
	return msci::units::mole(x, "ymol");
}

msci::units::light operator"" _Ycd(long double x)
{
	return msci::units::light(x, "Ycd");
}

msci::units::light operator"" _Zcd(long double x)
{
	return msci::units::light(x, "Zcd");
}

msci::units::light operator"" _Ecd(long double x)
{
	return msci::units::light(x, "Ecd");
}

msci::units::light operator"" _Pcd(long double x)
{
	return msci::units::light(x, "Pcd");
}

msci::units::light operator"" _Tcd(long double x)
{
	return msci::units::light(x, "Tcd");
}

msci::units::light operator"" _Gcd(long double x)
{
	return msci::units::light(x, "Gcd");
}

msci::units::light operator"" _Mcd(long double x)
{
	return msci::units::light(x, "Mcd");
}

msci::units::light operator"" _kcd(long double x)
{
	return msci::units::light(x, "kcd");
}

msci::units::light operator"" _hcd(long double x)
{
	return msci::units::light(x, "hcd");
}

msci::units::light operator"" _dacd(long double x)
{
	return msci::units::light(x, "dacd");
}

msci::units::light operator"" _cd(long double x)
{
	return msci::units::light(x, "cd");
}

msci::units::light operator"" _dcd(long double x)
{
	return msci::units::light(x, "dcd");
}

msci::units::light operator"" _ccd(long double x)
{
	return msci::units::light(x, "ccd");
}

msci::units::light operator"" _mcd(long double x)
{
	return msci::units::light(x, "mcd");
}

msci::units::light operator"" _ucd(long double x)
{
	return msci::units::light(x, "ucd");
}

msci::units::light operator"" _ncd(long double x)
{
	return msci::units::light(x, "ncd");
}

msci::units::light operator"" _pcd(long double x)
{
	return msci::units::light(x, "pcd");
}

msci::units::light operator"" _fcd(long double x)
{
	return msci::units::light(x, "fcd");
}

msci::units::light operator"" _acd(long double x)
{
	return msci::units::light(x, "acd");
}

msci::units::light operator"" _zcd(long double x)
{
	return msci::units::light(x, "zcd");
}

msci::units::light operator"" _ycd(long double x)
{
	return msci::units::light(x, "ycd");
}

msci::units::data operator"" _YB(long double x)
{
	return msci::units::data(x, "YB");
}

msci::units::data operator"" _ZB(long double x)
{
	return msci::units::data(x, "ZB");
}

msci::units::data operator"" _EB(long double x)
{
	return msci::units::data(x, "EB");
}

msci::units::data operator"" _PB(long double x)
{
	return msci::units::data(x, "PB");
}

msci::units::data operator"" _TB(long double x)
{
	return msci::units::data(x, "TB");
}

msci::units::data operator"" _GB(long double x)
{
	return msci::units::data(x, "GB");
}

msci::units::data operator"" _MB(long double x)
{
	return msci::units::data(x, "MB");
}

msci::units::data operator"" _kB(long double x)
{
	return msci::units::data(x, "kB");
}

msci::units::data operator"" _B(long double x)
{
	return msci::units::data(x, "B");
}
