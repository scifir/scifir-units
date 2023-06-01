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
			enum value {left, right, top, bottom, front, back, left_top, left_bottom, right_top, right_bottom, left_front, left_back, right_front, right_back, top_front, top_back, bottom_front, bottom_back, left_top_front, left_top_back, left_bottom_front, left_bottom_back, right_top_front, right_top_back, right_bottom_front, right_bottom_back};
			
			direction();
			direction(direction::value);

			inline const direction::value& get_direction() const
			{
				return direction_value;
			}

			void invert();

			void operator =(direction::value);

			string display() const;

		private:
			direction::value direction_value;
	};
	
	string direction_string(direction::value);
	direction::value opposite_direction(direction::value);
}

bool operator ==(const msci::direction& x, const msci::direction& y);
bool operator !=(const msci::direction& x, const msci::direction& y);
bool operator ==(const msci::direction& x, msci::direction::value y);
bool operator !=(const msci::direction& x, msci::direction::value y);
bool operator ==(msci::direction::value y, const msci::direction& x);
bool operator !=(msci::direction::value y, const msci::direction& x);

ostream& operator <<(ostream& os, const msci::direction& x);

#endif // MSCI_UNITS_TOPOLOGY_DIRECTION_HPP_INCLUDED
