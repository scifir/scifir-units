#include "./base_units.hpp"

#include "./scalar_unit.hpp"
#include "./dimension.hpp"
#include "./prefix.hpp"
#include "./constants.hpp"

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

	SCALAR_UNIT_CPP(light_intensity,"cd");
	SCALAR_UNIT_CPP(data,"B");
}

scifir::length operator"" _Qm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Rm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Ym(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Zm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Em(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Pm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Tm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Gm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Mm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _km(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _hm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _dam(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _m(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _dm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _cm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _mm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _um(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _nm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _pm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _fm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _am(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _zm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _ym(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _rm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _qm(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _s(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _ms(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _us(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _ns(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _ps(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _fs(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _as(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _zs(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _ys(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _rs(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _qs(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Qg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Rg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Yg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Zg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Eg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Pg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Tg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Gg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Mg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _kg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _hg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _dag(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _g(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _dg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _cg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _mg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _ug(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _ng(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _pg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _fg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _ag(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _zg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _yg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _rg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _qg(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _QC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _RC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _YC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _ZC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _EC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _PC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _TC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _GC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _MC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _kC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _hC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _daC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _C(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _dC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _cC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _mC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _uC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _nC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _pC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _fC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _aC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _zC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _yC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _rC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _qC(unsigned long long int x)
{
	return scifir::charge((long double)x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _QK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _RK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _YK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _ZK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _EK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _PK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _TK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _GK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _MK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _kK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _hK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _daK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _K(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _dK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _cK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _mK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _uK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _nK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _pK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _fK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _aK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _zK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _yK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _rK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _qK(unsigned long long int x)
{
	return scifir::temperature((long double)x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Qmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Rmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Ymol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Zmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Emol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Pmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Tmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Gmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Mmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _kmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _hmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _damol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _mol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _dmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _cmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _mmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _umol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _nmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _pmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _fmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _amol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _zmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _ymol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _rmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _qmol(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Qcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Rcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Ycd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Zcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Ecd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Pcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Tcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Gcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Mcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _kcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _hcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _dacd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _cd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _dcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _ccd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _mcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _ucd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _ncd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _pcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _fcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _acd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _zcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _ycd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _rcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _qcd(unsigned long long int x)
{
	return scifir::light_intensity((long double)x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _QB(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _RB(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _YB(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _ZB(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _EB(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _PB(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _TB(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _GB(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _MB(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _kB(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _B(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Qbit(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Rbit(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Ybit(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Zbit(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Ebit(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Pbit(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Tbit(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Gbit(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Mbit(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _kbit(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _bit(unsigned long long int x)
{
	return scifir::data((long double)x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Qm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Rm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Ym(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Zm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Em(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Pm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Tm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Gm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Mm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _km(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _hm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _dam(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _m(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _dm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _cm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _mm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _um(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _nm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _pm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _fm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _am(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _zm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _ym(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _rm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _qm(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::METRE,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _s(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _ms(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _us(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _ns(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _ps(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _fs(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _as(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _zs(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _ys(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _rs(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _qs(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::SECOND,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Qg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Rg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Yg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Zg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Eg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Pg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Tg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Gg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Mg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _kg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _hg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _dag(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _g(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _dg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _cg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _mg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _ug(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _ng(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _pg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _fg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _ag(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _zg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _yg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _rg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _qg(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::GRAM,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _QC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _RC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _YC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _ZC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _EC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _PC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _TC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _GC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _MC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _kC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _hC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _daC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _C(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _dC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _cC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _mC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _uC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _nC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _pC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _fC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _aC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _zC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _yC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _rC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::charge operator"" _qC(long double x)
{
	return scifir::charge(x, { scifir::dimension(scifir::dimension::COULOMB,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _QK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _RK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _YK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _ZK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _EK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _PK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _TK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _GK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _MK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _kK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _hK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _daK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _K(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _dK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _cK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _mK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _uK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _nK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _pK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _fK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _aK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _zK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _yK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _rK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::temperature operator"" _qK(long double x)
{
	return scifir::temperature(x, { scifir::dimension(scifir::dimension::KELVIN,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Qmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Rmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Ymol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Zmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Emol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Pmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Tmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Gmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _Mmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _kmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _hmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _damol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _mol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _dmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _cmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _mmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _umol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _nmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _pmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _fmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _amol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _zmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _ymol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _rmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _qmol(long double x)
{
	return scifir::mole(x, { scifir::dimension(scifir::dimension::MOLE,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Qcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Rcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Ycd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Zcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Ecd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Pcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Tcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Gcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _Mcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _kcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _hcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _dacd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _cd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _dcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _ccd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _mcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _ucd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _ncd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _pcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _fcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _acd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _zcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _ycd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _rcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::light_intensity operator"" _qcd(long double x)
{
	return scifir::light_intensity(x, { scifir::dimension(scifir::dimension::CANDELA,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _QB(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _RB(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _YB(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _ZB(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _EB(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _PB(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _TB(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _GB(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _MB(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _kB(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _B(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BYTE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Qbit(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Rbit(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Ybit(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Zbit(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Ebit(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Pbit(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Tbit(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Gbit(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _Mbit(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _kbit(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::data operator"" _bit(long double x)
{
	return scifir::data(x, { scifir::dimension(scifir::dimension::BIT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}