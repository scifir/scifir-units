#ifndef SCIFIR_UNITS_TOPOLOGY_DIRECTION_HPP_INCLUDED
#define SCIFIR_UNITS_TOPOLOGY_DIRECTION_HPP_INCLUDED

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

namespace scifir
{
	class direction;
	
	class direction
	{
		public:
			enum name : int8_t {NONE, LEFT, RIGHT, TOP, BOTTOM, FRONT, BACK, LEFT_TOP, LEFT_BOTTOM, RIGHT_TOP, RIGHT_BOTTOM, LEFT_FRONT, LEFT_BACK, RIGHT_FRONT, RIGHT_BACK, TOP_FRONT, TOP_BACK, BOTTOM_FRONT, BOTTOM_BACK, LEFT_TOP_FRONT, LEFT_TOP_BACK, LEFT_BOTTOM_FRONT, LEFT_BOTTOM_BACK, RIGHT_TOP_FRONT, RIGHT_TOP_BACK, RIGHT_BOTTOM_FRONT, RIGHT_BOTTOM_BACK};
			
			direction();
			direction(const direction&);
			direction(direction&&);
			explicit direction(direction::name);
			explicit direction(const string&);
			
			void operator=(const direction&);
			void operator=(direction&&);
			void operator=(direction::name);

			void invert();

			direction::name value;
	};

	string to_string(direction::name);
	string to_string(const direction&);
	direction::name create_direction(const string&);
	direction::name invert(direction::name);
}

bool operator ==(const scifir::direction& x, const scifir::direction& y);
bool operator !=(const scifir::direction& x, const scifir::direction& y);
bool operator ==(const scifir::direction& x, scifir::direction::name y);
bool operator !=(const scifir::direction& x, scifir::direction::name y);
bool operator ==(scifir::direction::name y, const scifir::direction& x);
bool operator !=(scifir::direction::name y, const scifir::direction& x);

bool operator ==(const scifir::direction&, const string&);
bool operator !=(const scifir::direction&, const string&);

bool operator ==(const string&, const scifir::direction&);
bool operator !=(const string&, const scifir::direction&);

void operator +=(string&, const scifir::direction&);
string operator +(const string&, const scifir::direction&);
string operator +(const scifir::direction&, const string&);

ostream& operator <<(ostream& os, const scifir::direction& x);
istream& operator >>(istream&, scifir::direction&);

#endif // SCIFIR_UNITS_TOPOLOGY_DIRECTION_HPP_INCLUDED
