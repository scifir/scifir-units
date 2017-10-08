#ifndef DIMENSION_HPP_
#define DIMENSION_HPP_

#include "dimension_abstract.hpp"
#include "prefix.hpp"

#include <map>
#include <string>
using namespace std;

namespace physics::units
{
	enum dimension_symbol
	{
		m = 0, angle_symbol, solid_angle_symbol, s, g, C, K, mol, cd, B
	};

	class dimension : public dimension_abstract
	{
		public:
			dimension();
			dimension(prefix_symbol, int = 1);
			dimension(prefix&, int = 1);
			virtual dimension* clone() const = 0;

			virtual int get_enum_type() const = 0;
	};

	template<typename T>
	class dimension_crtp : public dimension
	{
		public:
			dimension_crtp(prefix_symbol new_prefix = normal_prefix, int new_scale = 1) : dimension(new_prefix, new_scale)
			{
			}

			dimension_crtp(prefix& new_prefix, int new_scale = 1) : dimension(new_prefix, new_scale)
			{
			}

			virtual dimension* clone() const
			{
				return new T(static_cast<const T&>(*this));
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

	class dimension_length: public dimension_crtp<dimension_length>
	{
		public:
			using dimension_crtp::dimension_crtp;

			virtual int get_enum_type() const;

			static const string name;
			static const string symbol;
	};

	class dimension_angle: public dimension_crtp<dimension_angle>
	{
		public:
			using dimension_crtp::dimension_crtp;

			virtual int get_enum_type() const;

			static const string name;
			static const string symbol;
	};

	class dimension_solid_angle: public dimension_crtp<dimension_solid_angle>
	{
		public:
			using dimension_crtp::dimension_crtp;

			virtual int get_enum_type() const;

			static const string name;
			static const string symbol;
	};

	class dimension_time: public dimension_crtp<dimension_time>
	{
		public:
			using dimension_crtp::dimension_crtp;

			virtual int get_enum_type() const;

			static const string name;
			static const string symbol;
	};

	class dimension_mass: public dimension_crtp<dimension_mass>
	{
		public:
			using dimension_crtp::dimension_crtp;

			virtual int get_enum_type() const;

			static const string name;
			static const string symbol;
	};

	class dimension_charge: public dimension_crtp<dimension_charge>
	{
		public:
			using dimension_crtp::dimension_crtp;

			virtual int get_enum_type() const;

			static const string name;
			static const string symbol;
	};

	class dimension_temperature: public dimension_crtp<dimension_temperature>
	{
		public:
			using dimension_crtp::dimension_crtp;

			virtual int get_enum_type() const;

			static const string name;
			static const string symbol;
	};

	class dimension_mole: public dimension_crtp<dimension_mole>
	{
		public:
			using dimension_crtp::dimension_crtp;

			virtual int get_enum_type() const;

			static const string name;
			static const string symbol;
	};

	class dimension_light: public dimension_crtp<dimension_light>
	{
		public:
			using dimension_crtp::dimension_crtp;

			virtual int get_enum_type() const;

			static const string name;
			static const string symbol;
	};

	class dimension_byte: public dimension_crtp<dimension_byte>
	{
		public:
			using dimension_crtp::dimension_crtp;

			virtual int get_enum_type() const;
			virtual float get_prefix_base() const;

			static const string name;
			static const string symbol;
	};

	dimension* create_dimension(dimension_symbol);
	dimension* create_dimension(const string&);
}

#endif
