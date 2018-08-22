#ifndef ABBREVIATION_HPP_INCLUDED
#define ABBREVIATION_HPP_INCLUDED

#include "msci/units/units/abstract_dimension.hpp"
#include "msci/units/units/dimension.hpp"
#include "msci/units/units/prefix.hpp"

#include <map>
#include <string>

using namespace std;

namespace msci
{
	enum abbreviation_symbol
	{
		Hz = 9, N, Pa, J, W, A, V, F, Ohm, S, Wb, T, H, lm, lx, Bq, Gy, Sv, kat, angstrom, normal_abbreviation, L, minute, h, d, AU, pc, eV, Da, amu, barn, M, particles, ppm, ppb
	};

	class abbreviation : public abstract_dimension
	{
		public:
			abbreviation();
			abbreviation(prefix_symbol, int = 1);
			abbreviation(prefix&, int = 1);
			virtual abbreviation* clone() const = 0;

			virtual const string& get_dimensions_match() const = 0;
			virtual int get_enum_type() const = 0;
			virtual const float& get_factor() const = 0;
	};

	template<typename T>
	class abbreviation_crtp : public abbreviation
	{
		public:
			abbreviation_crtp(prefix_symbol new_prefix = normal_prefix, int new_scale = 1) : abbreviation(new_prefix, new_scale)
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

			virtual const float& get_factor() const
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
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_hertz: public abbreviation_crtp<abbreviation_hertz>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_newton: public abbreviation_crtp<abbreviation_newton>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_pascal: public abbreviation_crtp<abbreviation_pascal>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_joule: public abbreviation_crtp<abbreviation_joule>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_watt: public abbreviation_crtp<abbreviation_watt>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_ampere: public abbreviation_crtp<abbreviation_ampere>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_volt: public abbreviation_crtp<abbreviation_volt>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_farad: public abbreviation_crtp<abbreviation_farad>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_ohm: public abbreviation_crtp<abbreviation_ohm>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_siemens: public abbreviation_crtp<abbreviation_siemens>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_weber: public abbreviation_crtp<abbreviation_weber>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_tesla: public abbreviation_crtp<abbreviation_tesla>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_henry: public abbreviation_crtp<abbreviation_henry>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_lumen: public abbreviation_crtp<abbreviation_lumen>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_lux: public abbreviation_crtp<abbreviation_lux>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_becquerel: public abbreviation_crtp<abbreviation_becquerel>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_gray: public abbreviation_crtp<abbreviation_gray>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_sievert: public abbreviation_crtp<abbreviation_sievert>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_katal: public abbreviation_crtp<abbreviation_katal>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_angstrom: public abbreviation_crtp<abbreviation_angstrom>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_litre: public abbreviation_crtp<abbreviation_litre>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_minute: public abbreviation_crtp<abbreviation_minute>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_hour: public abbreviation_crtp<abbreviation_hour>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_day: public abbreviation_crtp<abbreviation_day>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_astronomical_unit: public abbreviation_crtp<abbreviation_astronomical_unit>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_parsec: public abbreviation_crtp<abbreviation_parsec>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_electron_volt: public abbreviation_crtp<abbreviation_electron_volt>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_dalton: public abbreviation_crtp<abbreviation_dalton>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_amu: public abbreviation_crtp<abbreviation_amu>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_barn: public abbreviation_crtp<abbreviation_barn>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_molarity: public abbreviation_crtp<abbreviation_molarity>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_particles: public abbreviation_crtp<abbreviation_particles>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_ppm: public abbreviation_crtp<abbreviation_ppm>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	class abbreviation_ppb: public abbreviation_crtp<abbreviation_ppb>
	{
		public:
			using abbreviation_crtp::abbreviation_crtp;

			virtual int get_enum_type() const;

			static const string dimensions_match;
			static const float factor;
			static const string name;
			static const string symbol;
	};

	abbreviation* create_abbreviation(abbreviation_symbol);
	abbreviation* create_abbreviation(const string&);
}

#endif // ABBREVIATION_HPP_INCLUDED
