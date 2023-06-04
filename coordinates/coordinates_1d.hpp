#ifndef MSCI_UNITS_COORDINATES_COORDINATES_1D_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_COORDINATES_1D_HPP_INCLUDED

#include "topology/point_1d.hpp"
#include "units/unit_basic.hpp"

#include "predefined_units/kinematics_units.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class coordinates_1d
	{
		public:
			coordinates_1d();
			coordinates_1d(const coordinates_1d&);
			coordinates_1d(coordinates_1d&&);
			coordinates_1d(const length&);
			coordinates_1d(const point_1d&);
			coordinates_1d(string);

			coordinates_1d& operator=(const coordinates_1d&);
			coordinates_1d& operator=(coordinates_1d&&);
			coordinates_1d& operator=(const point_1d&);

			void set_position(const length&);

			void move_in_direction(const length&);
			
			length distance_to_origin() const;

			length x;
	};

	string to_string(const coordinates_1d&);
	length distance(const coordinates_1d&,const coordinates_1d&);
	length distance(const coordinates_1d&,const point_1d&);
	length distance(const point_1d&,const coordinates_1d&);
}

string operator +(const string&,const msci::coordinates_1d&);
string operator +(const msci::coordinates_1d&,const string&);

bool operator ==(const msci::coordinates_1d&,const msci::coordinates_1d&);
bool operator !=(const msci::coordinates_1d&,const msci::coordinates_1d&);

bool operator ==(const msci::coordinates_1d&,const msci::point_1d&);
bool operator !=(const msci::coordinates_1d&,const msci::point_1d&);
bool operator ==(const msci::point_1d&,const msci::coordinates_1d&);
bool operator !=(const msci::point_1d&,const msci::coordinates_1d&);

ostream& operator << (ostream&,const msci::coordinates_1d&);
istream& operator >>(istream&,msci::coordinates_1d&);

#endif // MSCI_UNITS_COORDINATES_COORDINATES_1D_HPP_INCLUDED
