#ifndef SCIFIR_UNITS_UNITS_PREFIX_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_PREFIX_HPP_INCLUDED

#include <cstdint>
#include <iostream>
#include <map>
#include <string>

using namespace std;

namespace scifir
{
	class prefix
	{
		public:
			enum type : int8_t {NONE,YOTTA,ZETTA,EXA,PETA,TERA,GIGA,MEGA,KILO,HECTO,DECA,DECI,CENTI,MILLI,MICRO,NANO,PICO,FEMTO,ATTO,ZEPTO,YOCTO};

			prefix();
			prefix(const prefix& x);
			prefix(prefix&& x);
			explicit prefix(prefix::type new_type);
			explicit prefix(const string& new_type);

			prefix& operator=(const prefix& x);
			prefix& operator=(prefix&& x);

			int get_conversion_factor() const;
			string get_name() const;
			string get_symbol() const;

			bool operator<(const scifir::prefix& x) const;

			prefix::type prefix_type;
	};

	prefix::type prefix_string(const string& x);

	prefix closest_prefix(const prefix& actual_prefix,int actual_scale);
	prefix create_prefix_by_factor(int factor);
}

bool operator ==(const scifir::prefix& x,const scifir::prefix& y);
bool operator !=(const scifir::prefix& x,const scifir::prefix& y);
bool operator <=(const scifir::prefix& x,const scifir::prefix& y);
bool operator >(const scifir::prefix& x,const scifir::prefix& y);
bool operator >=(const scifir::prefix& x,const scifir::prefix& y);

ostream& operator <<(ostream& os, const scifir::prefix& x);

#endif // SCIFIR_UNITS_UNITS_PREFIX_HPP_INCLUDED
