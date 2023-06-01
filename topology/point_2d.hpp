#ifndef MSCI_UNITS_TOPOLOGY_POINT_2D_HPP_INCLUDED
#define MSCI_UNITS_TOPOLOGY_POINT_2D_HPP_INCLUDED

#include "units.hpp"

#include <string>

using namespace std;

namespace msci
{
	class point_2d
	{
		public:
			point_2d();
			point_2d(const length&,const length&);

			void move_in_direction(const length&,const angle&);

			length distance_to_origin() const;

			length x;
			length y;
	};

	string to_string(const point_2d&);
	length distance(const point_2d&,const point_2d&);
}

bool operator ==(const msci::point_2d&,const msci::point_2d&);
bool operator !=(const msci::point_2d&,const msci::point_2d&);
ostream& operator <<(ostream&,const msci::point_2d&);

#endif // MSCI_UNITS_TOPOLOGY_POINT_2D_HPP_INCLUDED
