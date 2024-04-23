#ifndef SCIFIR_UNITS_SPECIAL_UNITS_AID_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_AID_HPP_INCLUDED

#include <string>

using namespace std;

namespace scifir
{
	enum class astronomical_body : int8_t {NONE,MILKY_WAY,ANDROMEDA,SOLAR_SYSTEM,SUN,MOON,MERCURY,VENUS,EARTH,MARS,JUPITER,SATURN,URANUS,NEPTUNE,CERES,ORCUS,PLUTO,HAUMEA,QUAOAR,MAKEMAKE,GONGGONG,ERIS,SEDNA,IO,EUROPA,GANYMEDE,CALLISTO,MIMAS,ENCELADUS,TETHYS,DIONE,RHEA,TITAN,IAPETUS,MIRANDA,ARIEL,UMBRIEL,TITANIA,OBERON,TRITON,CHARON,DYSNOMIA};

	class aid
	{
		public:
			enum type : int8_t {NONE,UNIVERSE,GALAXY,SOLAR_SYSTEM,PLANET,STAR,ASTEROID,MOON,METEOR};

			aid();
			aid(const aid&);
			aid(aid&&);
			explicit aid(const astronomical_body&);
			explicit aid(const string&,const string&);
			explicit aid(const string&,const string&,const string&);
			explicit aid(const aid::type&,const string&,const string&,const string&,const string&);
			explicit aid(const string&);

			aid& operator=(const aid&);
			aid& operator=(aid&&);

			string universe;
			string galaxy;
			string solar_system;
			string astronomical_body;
			aid::type astronomical_type;
	};
	
	string to_string(const aid&);
	string to_string(const aid::type&);
	aid::type create_astronomical_type(const string&);
}

bool operator ==(const scifir::aid&, const scifir::aid&);
bool operator !=(const scifir::aid&, const scifir::aid&);

bool operator ==(const scifir::aid&, const string&);
bool operator !=(const scifir::aid&, const string&);

bool operator ==(const string&, const scifir::aid&);
bool operator !=(const string&, const scifir::aid&);

void operator +=(string&, const scifir::aid&);
string operator +(const string&, const scifir::aid&);
string operator +(const scifir::aid&, const string&);

ostream& operator <<(ostream&, const scifir::aid&);
istream& operator >>(istream&, scifir::aid&);

#endif // SCIFIR_UNITS_SPECIAL_UNITS_AID_HPP_INCLUDED
