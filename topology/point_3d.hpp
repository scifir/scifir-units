#ifndef MSCI_UNITS_TOPOLOGY_POINT_3D_HPP_INCLUDED
#define MSCI_UNITS_TOPOLOGY_POINT_3D_HPP_INCLUDED

#include "predefined_units/kinematics_units.hpp"
#include "units/unit_basic.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class coordinates_3d;

	class point_3d
	{
		public:
			point_3d();
			point_3d(const point_3d&);
			point_3d(point_3d&&);
			explicit point_3d(const length&,const length&,const length&);
			explicit point_3d(const length&,const angle&,length);
			explicit point_3d(const length&,const angle&,const angle&);
			explicit point_3d(const angle&,const angle&,const length&);
			explicit point_3d(const coordinates_3d&);
			explicit point_3d(string);

			point_3d& operator=(const point_3d&);
			point_3d& operator=(point_3d&&);
			point_3d& operator=(const coordinates_3d&);

			void set_position(const length&,const length&,const length&);
			void set_position(const length&,const angle&,length);
			void set_position(const length&,const angle&,const angle&);
			void set_position(const angle&,const angle&,const length&);

			void rotate_in_x(const angle&);
			void rotate_in_y(const angle&);
			void rotate_in_z(const angle&);
			void move(const displacement_3d&);
			void move(const length&,const length&,const length&);
			void move(const length&,const angle&,length);
			void move(const length&,const angle&,const angle&);

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

bool operator ==(const msci::point_3d&, const string&);
bool operator !=(const msci::point_3d&, const string&);

bool operator ==(const string&, const msci::point_3d&);
bool operator !=(const string&, const msci::point_3d&);

void operator +=(string&, const msci::point_3d&);
string operator +(const string&,const msci::point_3d&);
string operator +(const msci::point_3d&,const string&);

ostream& operator <<(ostream&,const msci::point_3d&);
istream& operator >>(istream&, msci::point_3d&);

#endif // MSCI_UNITS_TOPOLOGY_POINT_3D_HPP_INCLUDED
