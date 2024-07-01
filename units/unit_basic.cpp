#include "./unit_basic.hpp"

#include "./scalar_unit.hpp"
#include "./dimension.hpp"
#include "./prefix.hpp"
#include "../topology/constants.hpp"

#include "boost/algorithm/string.hpp"

#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	SCALAR_UNIT_CPP(length,"m");
	SCALAR_UNIT_CPP(time_duration,"s");

	time_duration::time_duration(const string& init_time) : scalar_unit()
	{
		if(!isdigit(init_time[0]))
		{
			return;
		}
		else
		{
			vector<string> init_values;
			boost::split(init_values,init_time,boost::is_any_of(" "));
			value = 0;
			for (unsigned int i = 0; i < init_values.size(); i++)
			{
				int j = 0;
				while(isdigit(init_values[i][j]) || init_values[i][j] == '.' || init_values[i][j] == ' ' || init_values[i][j] == '*' || init_values[i][j] == '^' || init_values[i][j] == 'e' || init_values[i][j] == 'E')
				{
					if (init_values[i][j] == ' ')
					{
						break;
					}
					j++;
				}
				string string_value = init_values[i].substr(0, j);
				boost::algorithm::erase_all(string_value, " ");
				size_t search_e = string_value.find("E");
				if (search_e != string::npos)
				{
					string_value.replace(search_e,1,"e");
				}
				size_t search_10 = string_value.find("*10^");
				if (search_10 != string::npos)
				{
					string_value.replace(search_10,4,"e");
				}
				stringstream ss(string_value);
				float init_value_float;
				ss >> init_value_float;
				string init_value_dimension = init_values[i].substr(j);
				float init_value_dimension_quantity = 0.0f;
				if (init_value_dimension == "d")
				{
					init_value_dimension_quantity = 86400.0f;
				}
				else if(init_value_dimension == "h")
				{
					init_value_dimension_quantity = 3600.0f;
				}
				else if(init_value_dimension == "min")
				{
					init_value_dimension_quantity = 60.0f;
				}
				else if(init_value_dimension == "s")
				{
					init_value_dimension_quantity = 1.0f;
				}
				value += init_value_float * init_value_dimension_quantity;
			}
			dimensions = create_dimensions("s");
		}
	}

	time_duration::operator std::chrono::seconds() const
	{
		scifir::time_duration a = *this;
		a.change_dimensions("s");
		return std::chrono::seconds(int(a.get_value()));
	}

	int time_duration::get_years() const
	{
		scifir::time_duration one_year ("365d");
		if (*this >= one_year)
		{
			return int(trunc((*this / one_year).get_value()));
		}
		else
		{
			return 0;
		}
	}

	int time_duration::get_months() const
	{
		scifir::time_duration one_month("30d");
		if (*this >= one_month)
		{
			return int(trunc((*this / one_month).get_value()));
		}
		else
		{
			return 0;
		}
	}

	int time_duration::get_weeks() const
	{
		scifir::time_duration one_week("7d");
		if (*this >= one_week)
		{
			return int(trunc((*this / one_week).get_value()));
		}
		else
		{
			return 0;
		}
	}

	int time_duration::get_days() const
	{
		scifir::time_duration one_day("1d");
		if (*this >= one_day)
		{
			return int(trunc((*this / one_day).get_value()));
		}
		else
		{
			return 0;
		}
	}

	int time_duration::get_hours() const
	{
		scifir::time_duration one_hour("1h");
		if (*this >= one_hour)
		{
			return int(trunc((*this / one_hour).get_value()));
		}
		else
		{
			return 0;
		}
	}

	int time_duration::get_minutes() const
	{
		scifir::time_duration one_minute = scifir::time_duration("1min");
		if (*this >= one_minute)
		{
			return int(trunc((*this / one_minute).get_value()));
		}
		else
		{
			return 0;
		}
	}

	int time_duration::get_seconds() const
	{
		scifir::time_duration one_second("1s");
		if (*this >= one_second)
		{
			return int(trunc((*this / one_second).get_value()));
		}
		else
		{
			return 0;
		}
	}

#ifdef IS_UNIX
	string time_duration::get_finish_date() const
	{
		chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
		start += chrono::seconds(*this);
		std::time_t start_time = std::chrono::system_clock::to_time_t(start);
		stringstream output;
		output << ctime(&start_time);
		return output.str();
	}
#elif IS_WINDOWS
	string time_duration::get_finish_date() const
	{
		chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
		start += chrono::seconds(*this);
		std::time_t start_time = std::chrono::system_clock::to_time_t(start);
		stringstream output;
		char str[26];
		ctime_s(str,sizeof str,&start_time);
		output << str;
		return output.str();
	}
#endif

	string time_duration::display_as_time() const
	{
		ostringstream output;
		scifir::time_duration remaining_time = *this;
		scifir::time_duration one_year ("365d");
		if (*this >= one_year)
		{
			int total_of_years = int(trunc((*this / one_year).get_value()));
			output << total_of_years << "y ";
			remaining_time -= scifir::time_duration(float(total_of_years) * 365,"d");
		}
		scifir::time_duration one_month("30d");
		if (remaining_time >= one_month)
		{
			int total_of_months = int(trunc((remaining_time / one_month).get_value()));
			output << total_of_months << "m ";
			remaining_time -= scifir::time_duration(float(total_of_months) * 30,"d");
		}
		scifir::time_duration one_day("1d");
		if (remaining_time >= one_day)
		{
			int total_of_days = int(trunc((remaining_time / one_day).get_value()));
			output << total_of_days << "d ";
			remaining_time -= scifir::time_duration(float(total_of_days),"d");
		}
		scifir::time_duration one_hour("1h");
		if (remaining_time >= one_hour)
		{
			int total_of_hours = int(trunc((remaining_time / one_hour).get_value()));
			output << total_of_hours << "h ";
			remaining_time -= scifir::time_duration(float(total_of_hours),"h");
		}
		scifir::time_duration one_minute("1min");
		if (remaining_time >= one_minute)
		{
			int total_of_minutes = int(trunc((remaining_time / one_minute).get_value()));
			output << total_of_minutes << "min ";
			remaining_time -= scifir::time_duration(float(total_of_minutes),"min");
		}
		scifir::time_duration one_second("1s");
		if (remaining_time >= one_second)
		{
			remaining_time.change_dimensions("s");
			float total_of_seconds = float(remaining_time.get_value());
			output << total_of_seconds << "s";
		}
		return output.str();
	}

	string time_duration::display_years() const
	{
		ostringstream out;
		out << get_years() << " y";
		return out.str();
	}

	string time_duration::display_months() const
	{
		ostringstream out;
		out << get_months() << " months";
		return out.str();
	}

	string time_duration::display_weeks() const
	{
		ostringstream out;
		out << get_weeks() << " weeks";
		return out.str();
	}

	string time_duration::display_days() const
	{
		ostringstream out;
		out << get_days() << " d";
		return out.str();
	}

	string time_duration::display_hours() const
	{
		ostringstream out;
		out << get_hours() << " h";
		return out.str();
	}

	string time_duration::display_minutes() const
	{
		ostringstream out;
		out << get_minutes() << " min";
		return out.str();
	}

	string time_duration::display_seconds() const
	{
		ostringstream out;
		out << get_seconds() << " s";
		return out.str();
	}

	SCALAR_UNIT_CPP(mass,"g");

	mass::mass(const percentage& new_percentage,const mass& new_mass) : scalar_unit()
	{
		dimensions = new_mass.get_dimensions();
		value = new_percentage * new_mass.get_value();
	}

	mass::mass(const string& init_percentage,const string& init_mass) : scalar_unit()
	{
		initialize_from_string(init_mass);
		percentage new_percentage = percentage(init_percentage);
		value = new_percentage * value;
	}

	SCALAR_UNIT_CPP(charge,"C");
	SCALAR_UNIT_CPP(temperature,"K");
	SCALAR_UNIT_CPP(mole,"mol");

	mole::mole(const percentage& new_percentage,const mole& new_mole) : scalar_unit()
	{
		dimensions = new_mole.get_dimensions();
		value = new_percentage * new_mole.get_value();
	}

	mole::mole(const string& init_percentage,const string& init_mole) : scalar_unit()
	{
		initialize_from_string(init_mole);
		percentage new_percentage = percentage(init_percentage);
		value = new_percentage * value;
	}

	int mole::number_of_particles() const
	{
		return 1;
		/*if (scalar_unit::actual_dimensions.count(particles))
		{
			return scalar_unit::value;
		}
		else
		{
			return scalar_unit::value * scifir::AVOGADRO_CONSTANT;
		}*/
	}

	SCALAR_UNIT_CPP(light,"cd");
	SCALAR_UNIT_CPP(data,"B");
}

scifir::length operator"" _Ym(unsigned long long int x)
{
	return scifir::length((long double)x, "Ym");
}

scifir::length operator"" _Zm(unsigned long long int x)
{
	return scifir::length((long double)x, "Zm");
}

scifir::length operator"" _Em(unsigned long long int x)
{
	return scifir::length((long double)x, "Em");
}

scifir::length operator"" _Pm(unsigned long long int x)
{
	return scifir::length((long double)x, "Pm");
}

scifir::length operator"" _Tm(unsigned long long int x)
{
	return scifir::length((long double)x, "Tm");
}

scifir::length operator"" _Gm(unsigned long long int x)
{
	return scifir::length((long double)x, "Gm");
}

scifir::length operator"" _Mm(unsigned long long int x)
{
	return scifir::length((long double)x, "Mm");
}

scifir::length operator"" _km(unsigned long long int x)
{
	return scifir::length((long double)x, "km");
}

scifir::length operator"" _hm(unsigned long long int x)
{
	return scifir::length((long double)x, "hm");
}

scifir::length operator"" _dam(unsigned long long int x)
{
	return scifir::length((long double)x, "dam");
}

scifir::length operator"" _m(unsigned long long int x)
{
	return scifir::length((long double)x, "m");
}

scifir::length operator"" _dm(unsigned long long int x)
{
	return scifir::length((long double)x, "dm");
}

scifir::length operator"" _cm(unsigned long long int x)
{
	return scifir::length((long double)x, "cm");
}

scifir::length operator"" _mm(unsigned long long int x)
{
	return scifir::length((long double)x, "mm");
}

scifir::length operator"" _um(unsigned long long int x)
{
	return scifir::length((long double)x, "um");
}

scifir::length operator"" _nm(unsigned long long int x)
{
	return scifir::length((long double)x, "nm");
}

scifir::length operator"" _pm(unsigned long long int x)
{
	return scifir::length((long double)x, "pm");
}

scifir::length operator"" _fm(unsigned long long int x)
{
	return scifir::length((long double)x, "fm");
}

scifir::length operator"" _am(unsigned long long int x)
{
	return scifir::length((long double)x, "am");
}

scifir::length operator"" _zm(unsigned long long int x)
{
	return scifir::length((long double)x, "zm");
}

scifir::length operator"" _ym(unsigned long long int x)
{
	return scifir::length((long double)x, "ym");
}

scifir::time_duration operator"" _s(unsigned long long int x)
{
	return scifir::time_duration((long double)x, "s");
}

scifir::time_duration operator"" _ms(unsigned long long int x)
{
	return scifir::time_duration((long double)x, "ms");
}

scifir::time_duration operator"" _us(unsigned long long int x)
{
	return scifir::time_duration((long double)x, "us");
}

scifir::time_duration operator"" _ns(unsigned long long int x)
{
	return scifir::time_duration((long double)x, "ns");
}

scifir::time_duration operator"" _ps(unsigned long long int x)
{
	return scifir::time_duration((long double)x, "ps");
}

scifir::time_duration operator"" _fs(unsigned long long int x)
{
	return scifir::time_duration((long double)x, "fs");
}

scifir::time_duration operator"" _as(unsigned long long int x)
{
	return scifir::time_duration((long double)x, "as");
}

scifir::time_duration operator"" _zs(unsigned long long int x)
{
	return scifir::time_duration((long double)x, "zs");
}

scifir::time_duration operator"" _ys(unsigned long long int x)
{
	return scifir::time_duration((long double)x, "ys");
}

scifir::mass operator"" _Yg(unsigned long long int x)
{
	return scifir::mass((long double)x, "Yg");
}

scifir::mass operator"" _Zg(unsigned long long int x)
{
	return scifir::mass((long double)x, "Zg");
}

scifir::mass operator"" _Eg(unsigned long long int x)
{
	return scifir::mass((long double)x, "Eg");
}

scifir::mass operator"" _Pg(unsigned long long int x)
{
	return scifir::mass((long double)x, "Pg");
}

scifir::mass operator"" _Tg(unsigned long long int x)
{
	return scifir::mass((long double)x, "Tg");
}

scifir::mass operator"" _Gg(unsigned long long int x)
{
	return scifir::mass((long double)x, "Gg");
}

scifir::mass operator"" _Mg(unsigned long long int x)
{
	return scifir::mass((long double)x, "Mg");
}

scifir::mass operator"" _kg(unsigned long long int x)
{
	return scifir::mass((long double)x, "kg");
}

scifir::mass operator"" _hg(unsigned long long int x)
{
	return scifir::mass((long double)x, "hg");
}

scifir::mass operator"" _dag(unsigned long long int x)
{
	return scifir::mass((long double)x, "dag");
}

scifir::mass operator"" _g(unsigned long long int x)
{
	return scifir::mass((long double)x, "g");
}

scifir::mass operator"" _dg(unsigned long long int x)
{
	return scifir::mass((long double)x, "dg");
}

scifir::mass operator"" _cg(unsigned long long int x)
{
	return scifir::mass((long double)x, "cg");
}

scifir::mass operator"" _mg(unsigned long long int x)
{
	return scifir::mass((long double)x, "mg");
}

scifir::mass operator"" _ug(unsigned long long int x)
{
	return scifir::mass((long double)x, "ug");
}

scifir::mass operator"" _ng(unsigned long long int x)
{
	return scifir::mass((long double)x, "ng");
}

scifir::mass operator"" _pg(unsigned long long int x)
{
	return scifir::mass((long double)x, "pg");
}

scifir::mass operator"" _fg(unsigned long long int x)
{
	return scifir::mass((long double)x, "fg");
}

scifir::mass operator"" _ag(unsigned long long int x)
{
	return scifir::mass((long double)x, "ag");
}

scifir::mass operator"" _zg(unsigned long long int x)
{
	return scifir::mass((long double)x, "zg");
}

scifir::mass operator"" _yg(unsigned long long int x)
{
	return scifir::mass((long double)x, "yg");
}

scifir::charge operator"" _YC(unsigned long long int x)
{
	return scifir::charge((long double)x, "YC");
}

scifir::charge operator"" _ZC(unsigned long long int x)
{
	return scifir::charge((long double)x, "ZC");
}

scifir::charge operator"" _EC(unsigned long long int x)
{
	return scifir::charge((long double)x, "EC");
}

scifir::charge operator"" _PC(unsigned long long int x)
{
	return scifir::charge((long double)x, "PC");
}

scifir::charge operator"" _TC(unsigned long long int x)
{
	return scifir::charge((long double)x, "TC");
}

scifir::charge operator"" _GC(unsigned long long int x)
{
	return scifir::charge((long double)x, "GC");
}

scifir::charge operator"" _MC(unsigned long long int x)
{
	return scifir::charge((long double)x, "MC");
}

scifir::charge operator"" _kC(unsigned long long int x)
{
	return scifir::charge((long double)x, "kC");
}

scifir::charge operator"" _hC(unsigned long long int x)
{
	return scifir::charge((long double)x, "hC");
}

scifir::charge operator"" _daC(unsigned long long int x)
{
	return scifir::charge((long double)x, "daC");
}

scifir::charge operator"" _C(unsigned long long int x)
{
	return scifir::charge((long double)x, "C");
}

scifir::charge operator"" _dC(unsigned long long int x)
{
	return scifir::charge((long double)x, "dC");
}

scifir::charge operator"" _cC(unsigned long long int x)
{
	return scifir::charge((long double)x, "cC");
}

scifir::charge operator"" _mC(unsigned long long int x)
{
	return scifir::charge((long double)x, "mC");
}

scifir::charge operator"" _uC(unsigned long long int x)
{
	return scifir::charge((long double)x, "uC");
}

scifir::charge operator"" _nC(unsigned long long int x)
{
	return scifir::charge((long double)x, "nC");
}

scifir::charge operator"" _pC(unsigned long long int x)
{
	return scifir::charge((long double)x, "pC");
}

scifir::charge operator"" _fC(unsigned long long int x)
{
	return scifir::charge((long double)x, "fC");
}

scifir::charge operator"" _aC(unsigned long long int x)
{
	return scifir::charge((long double)x, "aC");
}

scifir::charge operator"" _zC(unsigned long long int x)
{
	return scifir::charge((long double)x, "zC");
}

scifir::charge operator"" _yC(unsigned long long int x)
{
	return scifir::charge((long double)x, "yC");
}

scifir::temperature operator"" _YK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "YK");
}

scifir::temperature operator"" _ZK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "ZK");
}

scifir::temperature operator"" _EK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "EK");
}

scifir::temperature operator"" _PK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "PK");
}

scifir::temperature operator"" _TK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "TK");
}

scifir::temperature operator"" _GK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "GK");
}

scifir::temperature operator"" _MK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "MK");
}

scifir::temperature operator"" _kK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "kK");
}

scifir::temperature operator"" _hK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "hK");
}

scifir::temperature operator"" _daK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "daK");
}

scifir::temperature operator"" _K(unsigned long long int x)
{
	return scifir::temperature((long double)x, "K");
}

scifir::temperature operator"" _dK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "dK");
}

scifir::temperature operator"" _cK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "cK");
}

scifir::temperature operator"" _mK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "mK");
}

scifir::temperature operator"" _uK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "uK");
}

scifir::temperature operator"" _nK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "nK");
}

scifir::temperature operator"" _pK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "pK");
}

scifir::temperature operator"" _fK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "fK");
}

scifir::temperature operator"" _aK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "aK");
}

scifir::temperature operator"" _zK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "zK");
}

scifir::temperature operator"" _yK(unsigned long long int x)
{
	return scifir::temperature((long double)x, "yK");
}

scifir::mole operator"" _Ymol(unsigned long long int x)
{
	return scifir::mole((long double)x, "Ymol");
}

scifir::mole operator"" _Zmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "Zmol");
}

scifir::mole operator"" _Emol(unsigned long long int x)
{
	return scifir::mole((long double)x, "Emol");
}

scifir::mole operator"" _Pmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "Pmol");
}

scifir::mole operator"" _Tmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "Tmol");
}

scifir::mole operator"" _Gmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "Gmol");
}

scifir::mole operator"" _Mmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "Mmol");
}

scifir::mole operator"" _kmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "kmol");
}

scifir::mole operator"" _hmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "hmol");
}

scifir::mole operator"" _damol(unsigned long long int x)
{
	return scifir::mole((long double)x, "damol");
}

scifir::mole operator"" _mol(unsigned long long int x)
{
	return scifir::mole((long double)x, "mol");
}

scifir::mole operator"" _dmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "dmol");
}

scifir::mole operator"" _cmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "cmol");
}

scifir::mole operator"" _mmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "mmol");
}

scifir::mole operator"" _umol(unsigned long long int x)
{
	return scifir::mole((long double)x, "umol");
}

scifir::mole operator"" _nmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "nmol");
}

scifir::mole operator"" _pmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "pmol");
}

scifir::mole operator"" _fmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "fmol");
}

scifir::mole operator"" _amol(unsigned long long int x)
{
	return scifir::mole((long double)x, "amol");
}

scifir::mole operator"" _zmol(unsigned long long int x)
{
	return scifir::mole((long double)x, "zmol");
}

scifir::mole operator"" _ymol(unsigned long long int x)
{
	return scifir::mole((long double)x, "ymol");
}

scifir::light operator"" _Ycd(unsigned long long int x)
{
	return scifir::light((long double)x, "Ycd");
}

scifir::light operator"" _Zcd(unsigned long long int x)
{
	return scifir::light((long double)x, "Zcd");
}

scifir::light operator"" _Ecd(unsigned long long int x)
{
	return scifir::light((long double)x, "Ecd");
}

scifir::light operator"" _Pcd(unsigned long long int x)
{
	return scifir::light((long double)x, "Pcd");
}

scifir::light operator"" _Tcd(unsigned long long int x)
{
	return scifir::light((long double)x, "Tcd");
}

scifir::light operator"" _Gcd(unsigned long long int x)
{
	return scifir::light((long double)x, "Gcd");
}

scifir::light operator"" _Mcd(unsigned long long int x)
{
	return scifir::light((long double)x, "Mcd");
}

scifir::light operator"" _kcd(unsigned long long int x)
{
	return scifir::light((long double)x, "kcd");
}

scifir::light operator"" _hcd(unsigned long long int x)
{
	return scifir::light((long double)x, "hcd");
}

scifir::light operator"" _dacd(unsigned long long int x)
{
	return scifir::light((long double)x, "dacd");
}

scifir::light operator"" _cd(unsigned long long int x)
{
	return scifir::light((long double)x, "cd");
}

scifir::light operator"" _dcd(unsigned long long int x)
{
	return scifir::light((long double)x, "dcd");
}

scifir::light operator"" _ccd(unsigned long long int x)
{
	return scifir::light((long double)x, "ccd");
}

scifir::light operator"" _mcd(unsigned long long int x)
{
	return scifir::light((long double)x, "mcd");
}

scifir::light operator"" _ucd(unsigned long long int x)
{
	return scifir::light((long double)x, "ucd");
}

scifir::light operator"" _ncd(unsigned long long int x)
{
	return scifir::light((long double)x, "ncd");
}

scifir::light operator"" _pcd(unsigned long long int x)
{
	return scifir::light((long double)x, "pcd");
}

scifir::light operator"" _fcd(unsigned long long int x)
{
	return scifir::light((long double)x, "fcd");
}

scifir::light operator"" _acd(unsigned long long int x)
{
	return scifir::light((long double)x, "acd");
}

scifir::light operator"" _zcd(unsigned long long int x)
{
	return scifir::light((long double)x, "zcd");
}

scifir::light operator"" _ycd(unsigned long long int x)
{
	return scifir::light((long double)x, "ycd");
}

scifir::data operator"" _YB(unsigned long long int x)
{
	return scifir::data((long double)x, "YB");
}

scifir::data operator"" _ZB(unsigned long long int x)
{
	return scifir::data((long double)x, "ZB");
}

scifir::data operator"" _EB(unsigned long long int x)
{
	return scifir::data((long double)x, "EB");
}

scifir::data operator"" _PB(unsigned long long int x)
{
	return scifir::data((long double)x, "PB");
}

scifir::data operator"" _TB(unsigned long long int x)
{
	return scifir::data((long double)x, "TB");
}

scifir::data operator"" _GB(unsigned long long int x)
{
	return scifir::data((long double)x, "GB");
}

scifir::data operator"" _MB(unsigned long long int x)
{
	return scifir::data((long double)x, "MB");
}

scifir::data operator"" _kB(unsigned long long int x)
{
	return scifir::data((long double)x, "kB");
}

scifir::data operator"" _B(unsigned long long int x)
{
	return scifir::data((long double)x, "B");
}

scifir::length operator"" _Ym(long double x)
{
	return scifir::length(x, "Ym");
}

scifir::length operator"" _Zm(long double x)
{
	return scifir::length(x, "Zm");
}

scifir::length operator"" _Em(long double x)
{
	return scifir::length(x, "Em");
}

scifir::length operator"" _Pm(long double x)
{
	return scifir::length(x, "Pm");
}

scifir::length operator"" _Tm(long double x)
{
	return scifir::length(x, "Tm");
}

scifir::length operator"" _Gm(long double x)
{
	return scifir::length(x, "Gm");
}

scifir::length operator"" _Mm(long double x)
{
	return scifir::length(x, "Mm");
}

scifir::length operator"" _km(long double x)
{
	return scifir::length(x, "km");
}

scifir::length operator"" _hm(long double x)
{
	return scifir::length(x, "hm");
}

scifir::length operator"" _dam(long double x)
{
	return scifir::length(x, "dam");
}

scifir::length operator"" _m(long double x)
{
	return scifir::length(x, "m");
}

scifir::length operator"" _dm(long double x)
{
	return scifir::length(x, "dm");
}

scifir::length operator"" _cm(long double x)
{
	return scifir::length(x, "cm");
}

scifir::length operator"" _mm(long double x)
{
	return scifir::length(x, "mm");
}

scifir::length operator"" _um(long double x)
{
	return scifir::length(x, "um");
}

scifir::length operator"" _nm(long double x)
{
	return scifir::length(x, "nm");
}

scifir::length operator"" _pm(long double x)
{
	return scifir::length(x, "pm");
}

scifir::length operator"" _fm(long double x)
{
	return scifir::length(x, "fm");
}

scifir::length operator"" _am(long double x)
{
	return scifir::length(x, "am");
}

scifir::length operator"" _zm(long double x)
{
	return scifir::length(x, "zm");
}

scifir::length operator"" _ym(long double x)
{
	return scifir::length(x, "ym");
}

scifir::time_duration operator"" _s(long double x)
{
	return scifir::time_duration(x, "s");
}

scifir::time_duration operator"" _ms(long double x)
{
	return scifir::time_duration(x, "ms");
}

scifir::time_duration operator"" _us(long double x)
{
	return scifir::time_duration(x, "us");
}

scifir::time_duration operator"" _ns(long double x)
{
	return scifir::time_duration(x, "ns");
}

scifir::time_duration operator"" _ps(long double x)
{
	return scifir::time_duration(x, "ps");
}

scifir::time_duration operator"" _fs(long double x)
{
	return scifir::time_duration(x, "fs");
}

scifir::time_duration operator"" _as(long double x)
{
	return scifir::time_duration(x, "as");
}

scifir::time_duration operator"" _zs(long double x)
{
	return scifir::time_duration(x, "zs");
}

scifir::time_duration operator"" _ys(long double x)
{
	return scifir::time_duration(x, "ys");
}

scifir::mass operator"" _Yg(long double x)
{
	return scifir::mass(x, "Yg");
}

scifir::mass operator"" _Zg(long double x)
{
	return scifir::mass(x, "Zg");
}

scifir::mass operator"" _Eg(long double x)
{
	return scifir::mass(x, "Eg");
}

scifir::mass operator"" _Pg(long double x)
{
	return scifir::mass(x, "Pg");
}

scifir::mass operator"" _Tg(long double x)
{
	return scifir::mass(x, "Tg");
}

scifir::mass operator"" _Gg(long double x)
{
	return scifir::mass(x, "Gg");
}

scifir::mass operator"" _Mg(long double x)
{
	return scifir::mass(x, "Mg");
}

scifir::mass operator"" _kg(long double x)
{
	return scifir::mass(x, "kg");
}

scifir::mass operator"" _hg(long double x)
{
	return scifir::mass(x, "hg");
}

scifir::mass operator"" _dag(long double x)
{
	return scifir::mass(x, "dag");
}

scifir::mass operator"" _g(long double x)
{
	return scifir::mass(x, "g");
}

scifir::mass operator"" _dg(long double x)
{
	return scifir::mass(x, "dg");
}

scifir::mass operator"" _cg(long double x)
{
	return scifir::mass(x, "cg");
}

scifir::mass operator"" _mg(long double x)
{
	return scifir::mass(x, "mg");
}

scifir::mass operator"" _ug(long double x)
{
	return scifir::mass(x, "ug");
}

scifir::mass operator"" _ng(long double x)
{
	return scifir::mass(x, "ng");
}

scifir::mass operator"" _pg(long double x)
{
	return scifir::mass(x, "pg");
}

scifir::mass operator"" _fg(long double x)
{
	return scifir::mass(x, "fg");
}

scifir::mass operator"" _ag(long double x)
{
	return scifir::mass(x, "ag");
}

scifir::mass operator"" _zg(long double x)
{
	return scifir::mass(x, "zg");
}

scifir::mass operator"" _yg(long double x)
{
	return scifir::mass(x, "yg");
}

scifir::charge operator"" _YC(long double x)
{
	return scifir::charge(x, "YC");
}

scifir::charge operator"" _ZC(long double x)
{
	return scifir::charge(x, "ZC");
}

scifir::charge operator"" _EC(long double x)
{
	return scifir::charge(x, "EC");
}

scifir::charge operator"" _PC(long double x)
{
	return scifir::charge(x, "PC");
}

scifir::charge operator"" _TC(long double x)
{
	return scifir::charge(x, "TC");
}

scifir::charge operator"" _GC(long double x)
{
	return scifir::charge(x, "GC");
}

scifir::charge operator"" _MC(long double x)
{
	return scifir::charge(x, "MC");
}

scifir::charge operator"" _kC(long double x)
{
	return scifir::charge(x, "kC");
}

scifir::charge operator"" _hC(long double x)
{
	return scifir::charge(x, "hC");
}

scifir::charge operator"" _daC(long double x)
{
	return scifir::charge(x, "daC");
}

scifir::charge operator"" _C(long double x)
{
	return scifir::charge(x, "C");
}

scifir::charge operator"" _dC(long double x)
{
	return scifir::charge(x, "dC");
}

scifir::charge operator"" _cC(long double x)
{
	return scifir::charge(x, "cC");
}

scifir::charge operator"" _mC(long double x)
{
	return scifir::charge(x, "mC");
}

scifir::charge operator"" _uC(long double x)
{
	return scifir::charge(x, "uC");
}

scifir::charge operator"" _nC(long double x)
{
	return scifir::charge(x, "nC");
}

scifir::charge operator"" _pC(long double x)
{
	return scifir::charge(x, "pC");
}

scifir::charge operator"" _fC(long double x)
{
	return scifir::charge(x, "fC");
}

scifir::charge operator"" _aC(long double x)
{
	return scifir::charge(x, "aC");
}

scifir::charge operator"" _zC(long double x)
{
	return scifir::charge(x, "zC");
}

scifir::charge operator"" _yC(long double x)
{
	return scifir::charge(x, "yC");
}

scifir::temperature operator"" _YK(long double x)
{
	return scifir::temperature(x, "YK");
}

scifir::temperature operator"" _ZK(long double x)
{
	return scifir::temperature(x, "ZK");
}

scifir::temperature operator"" _EK(long double x)
{
	return scifir::temperature(x, "EK");
}

scifir::temperature operator"" _PK(long double x)
{
	return scifir::temperature(x, "PK");
}

scifir::temperature operator"" _TK(long double x)
{
	return scifir::temperature(x, "TK");
}

scifir::temperature operator"" _GK(long double x)
{
	return scifir::temperature(x, "GK");
}

scifir::temperature operator"" _MK(long double x)
{
	return scifir::temperature(x, "MK");
}

scifir::temperature operator"" _kK(long double x)
{
	return scifir::temperature(x, "kK");
}

scifir::temperature operator"" _hK(long double x)
{
	return scifir::temperature(x, "hK");
}

scifir::temperature operator"" _daK(long double x)
{
	return scifir::temperature(x, "daK");
}

scifir::temperature operator"" _K(long double x)
{
	return scifir::temperature(x, "K");
}

scifir::temperature operator"" _dK(long double x)
{
	return scifir::temperature(x, "dK");
}

scifir::temperature operator"" _cK(long double x)
{
	return scifir::temperature(x, "cK");
}

scifir::temperature operator"" _mK(long double x)
{
	return scifir::temperature(x, "mK");
}

scifir::temperature operator"" _uK(long double x)
{
	return scifir::temperature(x, "uK");
}

scifir::temperature operator"" _nK(long double x)
{
	return scifir::temperature(x, "nK");
}

scifir::temperature operator"" _pK(long double x)
{
	return scifir::temperature(x, "pK");
}

scifir::temperature operator"" _fK(long double x)
{
	return scifir::temperature(x, "fK");
}

scifir::temperature operator"" _aK(long double x)
{
	return scifir::temperature(x, "aK");
}

scifir::temperature operator"" _zK(long double x)
{
	return scifir::temperature(x, "zK");
}

scifir::temperature operator"" _yK(long double x)
{
	return scifir::temperature(x, "yK");
}

scifir::mole operator"" _Ymol(long double x)
{
	return scifir::mole(x, "Ymol");
}

scifir::mole operator"" _Zmol(long double x)
{
	return scifir::mole(x, "Zmol");
}

scifir::mole operator"" _Emol(long double x)
{
	return scifir::mole(x, "Emol");
}

scifir::mole operator"" _Pmol(long double x)
{
	return scifir::mole(x, "Pmol");
}

scifir::mole operator"" _Tmol(long double x)
{
	return scifir::mole(x, "Tmol");
}

scifir::mole operator"" _Gmol(long double x)
{
	return scifir::mole(x, "Gmol");
}

scifir::mole operator"" _Mmol(long double x)
{
	return scifir::mole(x, "Mmol");
}

scifir::mole operator"" _kmol(long double x)
{
	return scifir::mole(x, "kmol");
}

scifir::mole operator"" _hmol(long double x)
{
	return scifir::mole(x, "hmol");
}

scifir::mole operator"" _damol(long double x)
{
	return scifir::mole(x, "damol");
}

scifir::mole operator"" _mol(long double x)
{
	return scifir::mole(x, "mol");
}

scifir::mole operator"" _dmol(long double x)
{
	return scifir::mole(x, "dmol");
}

scifir::mole operator"" _cmol(long double x)
{
	return scifir::mole(x, "cmol");
}

scifir::mole operator"" _mmol(long double x)
{
	return scifir::mole(x, "mmol");
}

scifir::mole operator"" _umol(long double x)
{
	return scifir::mole(x, "umol");
}

scifir::mole operator"" _nmol(long double x)
{
	return scifir::mole(x, "nmol");
}

scifir::mole operator"" _pmol(long double x)
{
	return scifir::mole(x, "pmol");
}

scifir::mole operator"" _fmol(long double x)
{
	return scifir::mole(x, "fmol");
}

scifir::mole operator"" _amol(long double x)
{
	return scifir::mole(x, "amol");
}

scifir::mole operator"" _zmol(long double x)
{
	return scifir::mole(x, "zmol");
}

scifir::mole operator"" _ymol(long double x)
{
	return scifir::mole(x, "ymol");
}

scifir::light operator"" _Ycd(long double x)
{
	return scifir::light(x, "Ycd");
}

scifir::light operator"" _Zcd(long double x)
{
	return scifir::light(x, "Zcd");
}

scifir::light operator"" _Ecd(long double x)
{
	return scifir::light(x, "Ecd");
}

scifir::light operator"" _Pcd(long double x)
{
	return scifir::light(x, "Pcd");
}

scifir::light operator"" _Tcd(long double x)
{
	return scifir::light(x, "Tcd");
}

scifir::light operator"" _Gcd(long double x)
{
	return scifir::light(x, "Gcd");
}

scifir::light operator"" _Mcd(long double x)
{
	return scifir::light(x, "Mcd");
}

scifir::light operator"" _kcd(long double x)
{
	return scifir::light(x, "kcd");
}

scifir::light operator"" _hcd(long double x)
{
	return scifir::light(x, "hcd");
}

scifir::light operator"" _dacd(long double x)
{
	return scifir::light(x, "dacd");
}

scifir::light operator"" _cd(long double x)
{
	return scifir::light(x, "cd");
}

scifir::light operator"" _dcd(long double x)
{
	return scifir::light(x, "dcd");
}

scifir::light operator"" _ccd(long double x)
{
	return scifir::light(x, "ccd");
}

scifir::light operator"" _mcd(long double x)
{
	return scifir::light(x, "mcd");
}

scifir::light operator"" _ucd(long double x)
{
	return scifir::light(x, "ucd");
}

scifir::light operator"" _ncd(long double x)
{
	return scifir::light(x, "ncd");
}

scifir::light operator"" _pcd(long double x)
{
	return scifir::light(x, "pcd");
}

scifir::light operator"" _fcd(long double x)
{
	return scifir::light(x, "fcd");
}

scifir::light operator"" _acd(long double x)
{
	return scifir::light(x, "acd");
}

scifir::light operator"" _zcd(long double x)
{
	return scifir::light(x, "zcd");
}

scifir::light operator"" _ycd(long double x)
{
	return scifir::light(x, "ycd");
}

scifir::data operator"" _YB(long double x)
{
	return scifir::data(x, "YB");
}

scifir::data operator"" _ZB(long double x)
{
	return scifir::data(x, "ZB");
}

scifir::data operator"" _EB(long double x)
{
	return scifir::data(x, "EB");
}

scifir::data operator"" _PB(long double x)
{
	return scifir::data(x, "PB");
}

scifir::data operator"" _TB(long double x)
{
	return scifir::data(x, "TB");
}

scifir::data operator"" _GB(long double x)
{
	return scifir::data(x, "GB");
}

scifir::data operator"" _MB(long double x)
{
	return scifir::data(x, "MB");
}

scifir::data operator"" _kB(long double x)
{
	return scifir::data(x, "kB");
}

scifir::data operator"" _B(long double x)
{
	return scifir::data(x, "B");
}
