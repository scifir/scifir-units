#ifndef MSCI_UNITS_SPECIAL_UNITS_ZID_HPP_INCLUDED
#define MSCI_UNITS_SPECIAL_UNITS_ZID_HPP_INCLUDED

#include "special_units/aid.hpp"

#include <string>
#include <vector>

using namespace std;

namespace msci
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

			msci::aid aid;
			vector<string> regions;
			string country;
			string zone;
	};

	string to_string(const zid&);
}

bool operator ==(const msci::zid&, const msci::zid&);
bool operator !=(const msci::zid&, const msci::zid&);

bool operator ==(const msci::zid&, const string&);
bool operator !=(const msci::zid&, const string&);

bool operator ==(const string&, const msci::zid&);
bool operator !=(const string&, const msci::zid&);

void operator +=(string&, const msci::zid&);
string operator +(const string&, const msci::zid&);
string operator +(const msci::zid&, const string&);

ostream& operator <<(ostream&, const msci::zid&);
istream& operator >>(istream&, msci::zid&);

#endif // MSCI_UNITS_SPECIAL_UNITS_ZID_HPP_INCLUDED
