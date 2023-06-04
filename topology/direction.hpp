#ifndef MSCI_UNITS_TOPOLOGY_DIRECTION_HPP_INCLUDED
#define MSCI_UNITS_TOPOLOGY_DIRECTION_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class direction;
	
	class direction
	{
		public:
			enum name {LEFT, RIGHT, TOP, BOTTOM, FRONT, BACK, LEFT_TOP, LEFT_BOTTOM, RIGHT_TOP, RIGHT_BOTTOM, LEFT_FRONT, LEFT_BACK, RIGHT_FRONT, RIGHT_BACK, TOP_FRONT, TOP_BACK, BOTTOM_FRONT, BOTTOM_BACK, LEFT_TOP_FRONT, LEFT_TOP_BACK, LEFT_BOTTOM_FRONT, LEFT_BOTTOM_BACK, RIGHT_TOP_FRONT, RIGHT_TOP_BACK, RIGHT_BOTTOM_FRONT, RIGHT_BOTTOM_BACK};
			
			direction();
			direction(const direction&);
			direction(direction&&);
			direction(direction::name);
			
			void operator=(const direction&);
			void operator=(direction&&);
			void operator=(direction::name);

			void invert();

			direction::name value;
	};
	
	string to_string(direction::name);
	string to_string(const direction&);
	direction::name invert(direction::name);
}

bool operator ==(const msci::direction& x, const msci::direction& y);
bool operator !=(const msci::direction& x, const msci::direction& y);
bool operator ==(const msci::direction& x, msci::direction::name y);
bool operator !=(const msci::direction& x, msci::direction::name y);
bool operator ==(msci::direction::name y, const msci::direction& x);
bool operator !=(msci::direction::name y, const msci::direction& x);

ostream& operator <<(ostream& os, const msci::direction& x);

#endif // MSCI_UNITS_TOPOLOGY_DIRECTION_HPP_INCLUDED