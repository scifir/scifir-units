#ifndef SCIFIR_UNITS_SPECIAL_UNITS_ADDRESS_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_ADDRESS_HPP_INCLUDED

#include "../special_units/zid.hpp"

#include <cstdint>
#include <sstream>
#include <string>

using namespace std;

namespace scifir
{
	class address
	{
		public:
			enum type { EXTERNAL, INTERNAL };

			address();
			address(const address& x);
			address(address&& x);
			explicit address(const scifir::zid& new_zid,const string& new_location,const string& new_inner_location,const string& new_postal_code);

			address& operator =(const address& x);
			address& operator =(address&& x);

			address::type get_type() const;

			string display() const;
			string partial_display() const;
			string text_display() const;

			scifir::zid zid;
			string location;
			string inner_location;
			string postal_code;
	};
}

bool operator ==(const scifir::address& x, const scifir::address& y);
bool operator !=(const scifir::address& x, const scifir::address& y);

ostream& operator <<(ostream& os, const scifir::address& x);

#endif // SCIFIR_UNITS_SPECIAL_UNITS_ADDRESS_HPP_INCLUDED
