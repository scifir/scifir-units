#ifndef PREFIX_HPP_
#define PREFIX_HPP_

#include <map>
#include <memory>
#include <string>
using namespace std;

namespace physics::units
{
	enum prefix_symbol
	{
		yotta,
		zetta,
		exa,
		peta,
		tera,
		giga,
		mega,
		kilo,
		hecto,
		deca,
		normal_prefix,
		deci,
		centi,
		milli,
		micro,
		nano,
		pico,
		femto,
		atto,
		zepto,
		yocto
	};

	class prefix
	{
		public:
			int scale;

			prefix();
			virtual prefix* clone() const = 0;

			virtual const int& get_conversion_factor() const = 0;
			virtual prefix_symbol get_enum_type() const = 0;
			virtual const string& get_name() const = 0;
			virtual const string& get_symbol() const = 0;
	};

	template<typename T>
	class prefix_crtp : public prefix
	{
		public:
			prefix_crtp() : prefix()
			{
			}

			virtual prefix* clone() const
			{
				return new T(static_cast<T const &>(*this));
			}

			virtual const int& get_conversion_factor() const
			{
				return T::conversion_factor;
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

	class prefix_yotta: public prefix_crtp<prefix_yotta>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_zetta: public prefix_crtp<prefix_zetta>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_exa: public prefix_crtp<prefix_exa>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_peta: public prefix_crtp<prefix_peta>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_tera: public prefix_crtp<prefix_tera>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_giga: public prefix_crtp<prefix_giga>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_mega: public prefix_crtp<prefix_mega>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_kilo: public prefix_crtp<prefix_kilo>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_hecto: public prefix_crtp<prefix_hecto>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_deca: public prefix_crtp<prefix_deca>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_normal: public prefix_crtp<prefix_normal>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_deci: public prefix_crtp<prefix_deci>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_centi: public prefix_crtp<prefix_centi>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_milli: public prefix_crtp<prefix_milli>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_micro: public prefix_crtp<prefix_micro>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_nano: public prefix_crtp<prefix_nano>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_pico: public prefix_crtp<prefix_pico>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_femto: public prefix_crtp<prefix_femto>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_atto: public prefix_crtp<prefix_atto>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_zepto: public prefix_crtp<prefix_zepto>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	class prefix_yocto: public prefix_crtp<prefix_yocto>
	{
		public:
			using prefix_crtp::prefix_crtp;

			virtual prefix_symbol get_enum_type() const;

			static const int conversion_factor;
			static const string name;
			static const string symbol;
	};

	prefix* create_prefix(prefix_symbol);
	prefix* create_prefix(const string&);
}

#endif
