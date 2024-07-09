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
			direction(const direction& x);
			direction(direction&& x);
			explicit direction(direction::name new_direction);
			explicit direction(const string& init_direction);

			direction& operator =(const direction& x);
			direction& operator =(direction&& x);
			direction& operator =(direction::name new_direction);
			direction& operator =(const string& init_direction);

			void invert();

			direction::name value;
	};

	string to_string(direction::name x);
	string to_string(const direction& x);
	direction::name create_direction(const string& x);
	direction::name invert(direction::name x);
}

bool operator ==(const scifir::direction& x, const scifir::direction& y);
bool operator !=(const scifir::direction& x, const scifir::direction& y);

bool operator ==(const scifir::direction& x, scifir::direction::name y);
bool operator !=(const scifir::direction& x, scifir::direction::name y);
bool operator ==(scifir::direction::name y, const scifir::direction& x);
bool operator !=(scifir::direction::name y, const scifir::direction& x);

bool operator ==(const scifir::direction& x, const string& init_direction);
bool operator !=(const scifir::direction& x, const string& init_direction);

bool operator ==(const string& init_direction, const scifir::direction& x);
bool operator !=(const string& init_direction, const scifir::direction& x);

void operator +=(string& x, const scifir::direction& y);
string operator +(const string& x, const scifir::direction& y);
string operator +(const scifir::direction& y, const string& x);

ostream& operator <<(ostream& os, const scifir::direction& x);
istream& operator >>(istream& is, scifir::direction& x);

#endif // SCIFIR_UNITS_TOPOLOGY_DIRECTION_HPP_INCLUDED
