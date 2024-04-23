#ifndef SCIFIR_UNITS_SPECIAL_UNITS_ZID_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_ZID_HPP_INCLUDED

#include "../special_units/aid.hpp"

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class zid
	{
		public:
			zid();
			zid(const zid&);
			zid(zid&&);
			explicit zid(const string&);

			zid& operator=(const zid&);
			zid& operator=(zid&&);

			scifir::aid aid;
			vector<string> regions;
			string country;
			string zone;
	};

	string to_string(const zid&);
}

bool operator ==(const scifir::zid&, const scifir::zid&);
bool operator !=(const scifir::zid&, const scifir::zid&);

bool operator ==(const scifir::zid&, const string&);
bool operator !=(const scifir::zid&, const string&);

bool operator ==(const string&, const scifir::zid&);
bool operator !=(const string&, const scifir::zid&);

void operator +=(string&, const scifir::zid&);
string operator +(const string&, const scifir::zid&);
string operator +(const scifir::zid&, const string&);

ostream& operator <<(ostream&, const scifir::zid&);
istream& operator >>(istream&, scifir::zid&);

#endif // SCIFIR_UNITS_SPECIAL_UNITS_ZID_HPP_INCLUDED
