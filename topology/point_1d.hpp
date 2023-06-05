#ifndef MSCI_UNITS_TOPOLOGY_POINT_1D_HPP_INCLUDED
#define MSCI_UNITS_TOPOLOGY_POINT_1D_HPP_INCLUDED

#include "predefined_units/kinematics_units.hpp"
#include "units/unit_basic.hpp"

#include <string>

using namespace std;

namespace msci
{
	class coordinates_1d;

	class point_1d
	{
		public:
			point_1d();
			point_1d(const point_1d&);
			point_1d(point_1d&&);
			explicit point_1d(const length&);
			explicit point_1d(const coordinates_1d&);
			explicit point_1d(string);

			point_1d& operator=(const point_1d&);
			point_1d& operator=(point_1d&&);
			point_1d& operator=(const coordinates_1d&);

			void set_position(const length&);

			void move(const length&);

			length distance_to_origin() const;

			length x;
	};

	string to_string(const point_1d&);
	length distance(const point_1d&,const point_1d&);
}

bool operator ==(const msci::point_1d&,const msci::point_1d&);
bool operator !=(const msci::point_1d&,const msci::point_1d&);

bool operator ==(const msci::point_1d&, const string&);
bool operator !=(const msci::point_1d&, const string&);

bool operator ==(const string&, const msci::point_1d&);
bool operator !=(const string&, const msci::point_1d&);

void operator +=(string&, const msci::point_1d&);
string operator +(const string&,const msci::point_1d&);
string operator +(const msci::point_1d&,const string&);

ostream& operator <<(ostream&,const msci::point_1d&);
istream& operator >>(istream&,msci::point_1d&);

#endif // MSCI_UNITS_TOPOLOGY_POINT_1D_HPP_INCLUDED
