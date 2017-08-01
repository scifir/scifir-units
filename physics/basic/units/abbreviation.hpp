#ifndef ABBREVIATION_HPP_INCLUDED
#define ABBREVIATION_HPP_INCLUDED

#include "dimension_abstract.hpp"
#include "dimension.hpp"
#include "prefix.hpp"

#include <map>
#include <string>

using namespace std;

namespace physics::units
{
	enum abbreviation_symbol
	{
		Hz = 9, N, Pa, J, W, A, V, F, Ohm, S, Wb, T, H, lm, lx, Bq, Gy, Sv, kat, angstrom, normal_abbreviation, L, minute, h, d, AU, pc, eV, Da, amu, barn, M
	};

	class abbreviation : public dimension_abstract
	{
		public:
			abbreviation();
			abbreviation(prefix_symbol, int = 1);
			abbreviation(prefix&, int = 1);
			virtual abbreviation* clone() const = 0;

			virtual const string& get_dimensions_match() const = 0;
			virtual int get_enum_type() const = 0;
			virtual const long long& get_factor() const = 0;
	};

	template<typename T>
	class abbreviation_crtp : public abbreviation
	{
		public:
			abbreviation_crtp(prefix_symbol new_prefix, int new_scale = 1) : abbreviation(new_prefix, new_scale)
			{
			}

			abbreviation_crtp(prefix& new_prefix, int new_scale = 1) : abbreviation(new_prefix, new_scale)
			{
			}

			virtual abbreviation* clone() const
			{
				return new T(static_cast<T const &>(*this));
			}

			virtual const string& get_dimensions_match() const
			{
				return T::dimensions_match;
			}

			virtual const long long& get_factor() const
			{
				return T::factor;
			}

			virtual const string& get_name() const
			{
				return T::name;
			}

			virtual const string& get_symbol() const
			{
				return T::symbol;
			}
	};

	class abbreviation_normal: public abbreviation_crtp<abbreviation_normal>
	{
		public:
			abbreviation_normal(prefix_symbol = normal_prefix, int = 1);
			abbreviation_normal(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_hertz: public abbreviation_crtp<abbreviation_hertz>
	{
		public:
			abbreviation_hertz(prefix_symbol = normal_prefix, int = 1);
			abbreviation_hertz(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_newton: public abbreviation_crtp<abbreviation_newton>
	{
		public:
			abbreviation_newton(prefix_symbol = normal_prefix, int = 1);
			abbreviation_newton(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_pascal: public abbreviation_crtp<abbreviation_pascal>
	{
		public:
			abbreviation_pascal(prefix_symbol = normal_prefix, int = 1);
			abbreviation_pascal(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_joule: public abbreviation_crtp<abbreviation_joule>
	{
		public:
			abbreviation_joule(prefix_symbol = normal_prefix, int = 1);
			abbreviation_joule(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_watt: public abbreviation_crtp<abbreviation_watt>
	{
		public:
			abbreviation_watt(prefix_symbol = normal_prefix, int = 1);
			abbreviation_watt(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_ampere: public abbreviation_crtp<abbreviation_ampere>
	{
		public:
			abbreviation_ampere(prefix_symbol = normal_prefix, int = 1);
			abbreviation_ampere(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_volt: public abbreviation_crtp<abbreviation_volt>
	{
		public:
			abbreviation_volt(prefix_symbol = normal_prefix, int = 1);
			abbreviation_volt(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_farad: public abbreviation_crtp<abbreviation_farad>
	{
		public:
			abbreviation_farad(prefix_symbol = normal_prefix, int = 1);
			abbreviation_farad(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_ohm: public abbreviation_crtp<abbreviation_ohm>
	{
		public:
			abbreviation_ohm(prefix_symbol = normal_prefix, int = 1);
			abbreviation_ohm(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_siemens: public abbreviation_crtp<abbreviation_siemens>
	{
		public:
			abbreviation_siemens(prefix_symbol = normal_prefix, int = 1);
			abbreviation_siemens(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_weber: public abbreviation_crtp<abbreviation_weber>
	{
		public:
			abbreviation_weber(prefix_symbol = normal_prefix, int = 1);
			abbreviation_weber(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_tesla: public abbreviation_crtp<abbreviation_tesla>
	{
		public:
			abbreviation_tesla(prefix_symbol = normal_prefix, int = 1);
			abbreviation_tesla(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_henry: public abbreviation_crtp<abbreviation_henry>
	{
		public:
			abbreviation_henry(prefix_symbol = normal_prefix, int = 1);
			abbreviation_henry(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_lumen: public abbreviation_crtp<abbreviation_lumen>
	{
		public:
			abbreviation_lumen(prefix_symbol = normal_prefix, int = 1);
			abbreviation_lumen(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_lux: public abbreviation_crtp<abbreviation_lux>
	{
		public:
			abbreviation_lux(prefix_symbol = normal_prefix, int = 1);
			abbreviation_lux(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_becquerel: public abbreviation_crtp<abbreviation_becquerel>
	{
		public:
			abbreviation_becquerel(prefix_symbol = normal_prefix, int = 1);
			abbreviation_becquerel(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_gray: public abbreviation_crtp<abbreviation_gray>
	{
		public:
			abbreviation_gray(prefix_symbol = normal_prefix, int = 1);
			abbreviation_gray(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_sievert: public abbreviation_crtp<abbreviation_sievert>
	{
		public:
			abbreviation_sievert(prefix_symbol = normal_prefix, int = 1);
			abbreviation_sievert(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_katal: public abbreviation_crtp<abbreviation_katal>
	{
		public:
			abbreviation_katal(prefix_symbol = normal_prefix, int = 1);
			abbreviation_katal(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_angstrom: public abbreviation_crtp<abbreviation_angstrom>
	{
		public:
			abbreviation_angstrom(prefix_symbol = normal_prefix, int = 1);
			abbreviation_angstrom(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_litre: public abbreviation_crtp<abbreviation_litre>
	{
		public:
			abbreviation_litre(prefix_symbol = normal_prefix, int = 1);
			abbreviation_litre(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_minute: public abbreviation_crtp<abbreviation_minute>
	{
		public:
			abbreviation_minute(prefix_symbol = normal_prefix, int = 1);
			abbreviation_minute(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_hour: public abbreviation_crtp<abbreviation_hour>
	{
		public:
			abbreviation_hour(prefix_symbol = normal_prefix, int = 1);
			abbreviation_hour(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_day: public abbreviation_crtp<abbreviation_day>
	{
		public:
			abbreviation_day(prefix_symbol = normal_prefix, int = 1);
			abbreviation_day(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_astronomical_unit: public abbreviation_crtp<abbreviation_astronomical_unit>
	{
		public:
			abbreviation_astronomical_unit(prefix_symbol = normal_prefix, int = 1);
			abbreviation_astronomical_unit(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_parsec: public abbreviation_crtp<abbreviation_parsec>
	{
		public:
			abbreviation_parsec(prefix_symbol = normal_prefix, int = 1);
			abbreviation_parsec(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_electron_volt: public abbreviation_crtp<abbreviation_electron_volt>
	{
		public:
			abbreviation_electron_volt(prefix_symbol = normal_prefix, int = 1);
			abbreviation_electron_volt(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_dalton: public abbreviation_crtp<abbreviation_dalton>
	{
		public:
			abbreviation_dalton(prefix_symbol = normal_prefix, int = 1);
			abbreviation_dalton(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_amu: public abbreviation_crtp<abbreviation_amu>
	{
		public:
			abbreviation_amu(prefix_symbol = normal_prefix, int = 1);
			abbreviation_amu(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_barn: public abbreviation_crtp<abbreviation_barn>
	{
		public:
			abbreviation_barn(prefix_symbol = normal_prefix, int = 1);
			abbreviation_barn(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_molarity: public abbreviation_crtp<abbreviation_molarity>
	{
		public:
			abbreviation_molarity(prefix_symbol = normal_prefix, int = 1);
			abbreviation_molarity(prefix&, int = 1);

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const long long factor;
			static const string name;
			static const string symbol;
	};

	abbreviation* create_abbreviation(abbreviation_symbol);
	abbreviation* create_abbreviation(string);
}

#endif // ABBREVIATION_HPP_INCLUDED
