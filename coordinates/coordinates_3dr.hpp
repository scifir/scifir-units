#ifndef MSCI_UNITS_COORDINATES_COORDINATES_3DR_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_COORDINATES_3DR_HPP_INCLUDED

#include "topology/point_3d.hpp"
#include "meca_number/angle.hpp"
#include "coordinates/coordinates_3d.hpp"
#include "units/unit_basic.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace msci
{
	class coordinates_3dr
	{
		public:
			coordinates_3dr();
			coordinates_3dr(const length&,const length&,const length&,const angle&,const angle&);
			coordinates_3dr(const string&);

			length x;
			length y;
			length z;
			angle theta;
			angle phi;
	};

	string to_string(const coordinates_3dr&);
	float distance(const coordinates_3dr&,const coordinates_3dr&);
}

bool operator ==(const msci::coordinates_3dr&,const msci::coordinates_3dr&);
bool operator !=(const msci::coordinates_3dr&,const msci::coordinates_3dr&);

bool operator ==(const msci::coordinates_3dr&,const msci::coordinates_3d&);
bool operator !=(const msci::coordinates_3dr&,const msci::coordinates_3d&);
bool operator ==(const msci::coordinates_3d&,const msci::coordinates_3dr&);
bool operator !=(const msci::coordinates_3d&,const msci::coordinates_3dr&);

bool operator ==(const msci::coordinates_3dr&,const msci::point_3d&);
bool operator !=(const msci::coordinates_3dr&,const msci::point_3d&);
bool operator ==(const msci::point_3d&,const msci::coordinates_3dr&);
bool operator !=(const msci::point_3d&,const msci::coordinates_3dr&);

ostream& operator << (ostream&, const msci::coordinates_3dr&);

#endif // MSCI_UNITS_COORDINATES_COORDINATES_3DR_HPP_INCLUDED
