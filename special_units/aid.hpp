#ifndef SCIFIR_UNITS_SPECIAL_UNITS_AID_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_AID_HPP_INCLUDED

#include <cstdint>
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
			aid(const aid& x);
			aid(aid&& x);
			explicit aid(const astronomical_body& predefined_astronomical_body);
			explicit aid(const string& new_universe,const string& new_galaxy);
			explicit aid(const string& new_universe,const string& new_galaxy,const string& new_solar_system);
			explicit aid(const aid::type& new_astronomical_type,const string& new_universe,const string& new_galaxy,const string& new_solar_system,const string& new_astronomical_body);
			explicit aid(const string& init_aid);

			aid& operator =(const aid& x);
			aid& operator =(aid&& x);
			aid& operator =(const string& init_aid);

			bool has_unknown_universe() const;
			bool has_unknown_galaxy() const;
			bool has_unknown_solar_system() const;
			bool has_unknown_planet() const;
			bool has_unknown_moon() const;
			bool has_unknown_star() const;
			bool has_unknown_asteroid() const;

			string display() const;

			string universe;
			string galaxy;
			string solar_system;
			string astronomical_body;
			aid::type astronomical_type;

		private:
			void initialize_from_string(const string& init_aid);
	};

	string to_string(const aid& x);
	string to_string(const aid::type& x);
	aid::type create_astronomical_type(const string& astronomical_type_abbreviation);
}

bool operator ==(const scifir::aid& x, const scifir::aid& y);
bool operator !=(const scifir::aid& x, const scifir::aid& y);

bool operator ==(const scifir::aid& x, const string& init_aid);
bool operator !=(const scifir::aid& x, const string& init_aid);

bool operator ==(const string& init_aid, const scifir::aid& x);
bool operator !=(const string& init_aid, const scifir::aid& x);

void operator +=(string& x, const scifir::aid& y);
string operator +(const string& x, const scifir::aid& y);
string operator +(const scifir::aid& y, const string& x);

ostream& operator <<(ostream& os, const scifir::aid& x);
istream& operator >>(istream& is, scifir::aid& x);

#endif // SCIFIR_UNITS_SPECIAL_UNITS_AID_HPP_INCLUDED
