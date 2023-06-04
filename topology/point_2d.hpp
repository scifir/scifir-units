#ifndef MSCI_UNITS_TOPOLOGY_POINT_2D_HPP_INCLUDED
#define MSCI_UNITS_TOPOLOGY_POINT_2D_HPP_INCLUDED

#include "units.hpp"

#include <string>

using namespace std;

namespace msci
{
	class coordinates_2d;

	class point_2d
	{
		public:
			point_2d();
			point_2d(const point_2d&);
			point_2d(point_2d&&);
			point_2d(const length&,const length&);
			point_2d(const length&,const msci::angle&);
			point_2d(const coordinates_2d&);
			point_2d(string);

			point_2d& operator=(const point_2d&);
			point_2d& operator=(point_2d&&);
			point_2d& operator=(const coordinates_2d&);

			void set_position(const length&,const length&);
			void set_position(const length&,const angle&);

			void rotate(const angle&);
			void move_in_direction(const displacement_2d&);
			void move_in_direction(const length&,const msci::angle&);

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
istream& operator >>(istream&, msci::point_2d&);

#endif // MSCI_UNITS_TOPOLOGY_POINT_2D_HPP_INCLUDED
