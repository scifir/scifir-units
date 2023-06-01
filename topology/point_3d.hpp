#ifndef MSCI_UNITS_TOPOLOGY_POINT_3D_HPP_INCLUDED
#define MSCI_UNITS_TOPOLOGY_POINT_3D_HPP_INCLUDED

#include "units.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class point_3d
	{
		public:
			point_3d();
			point_3d(const length&,const length&,const length&);

			length distance_to_origin() const;

			length x;
			length y;
			length z;
	};

	string to_string(const point_3d&);
	length distance(const point_3d&,const point_3d&);
}

bool operator ==(const msci::point_3d&,const msci::point_3d&);
bool operator !=(const msci::point_3d&,const msci::point_3d&);
ostream& operator <<(ostream&,const msci::point_3d&);

#endif // MSCI_UNITS_TOPOLOGY_POINT_3D_HPP_INCLUDED
