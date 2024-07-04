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
			zid(const zid& x);
			zid(zid&& x);
			explicit zid(const scifir::aid& new_aid,const string& new_country,const vector<string>& new_regions,const string& new_zone);
			explicit zid(const scifir::aid& new_aid,const string& init_zid);
			explicit zid(const string& init_zid_full);

			zid& operator =(const zid& x);
			zid& operator =(zid&& x);
			zid& operator =(const string& init_zid_full);

			bool has_no_country() const;
			bool has_unknown_country() const;

			scifir::aid aid;
			vector<string> regions;
			string country;
			string zone;

		private:
			void initialize_from_string(const string& init_zid_full);
	};

	string to_string(const zid& x);
}

bool operator ==(const scifir::zid& x, const scifir::zid& y);
bool operator !=(const scifir::zid& x, const scifir::zid& y);

bool operator ==(const scifir::zid& x, const string& init_zid_full);
bool operator !=(const scifir::zid& x, const string& init_zid_full);

bool operator ==(const string& init_zid_full, const scifir::zid& x);
bool operator !=(const string& init_zid_full, const scifir::zid& x);

void operator +=(string& x, const scifir::zid& y);
string operator +(const string& x, const scifir::zid& y);
string operator +(const scifir::zid& y, const string& x);

ostream& operator <<(ostream& os, const scifir::zid& x);
istream& operator >>(istream& is, scifir::zid& x);

#endif // SCIFIR_UNITS_SPECIAL_UNITS_ZID_HPP_INCLUDED
