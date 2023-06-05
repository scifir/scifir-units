#ifndef MSCI_UNITS_TOPOLOGY_POINT_ND_HPP_INCLUDED
#define MSCI_UNITS_TOPOLOGY_POINT_ND_HPP_INCLUDED

#include "predefined_units/kinematics_units.hpp"
#include "units/unit_basic.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace msci
{
	class coordinates_nd;
	class displacement_nd;

	class point_nd
	{
		public:
			point_nd();
			point_nd(const point_nd&);
			point_nd(point_nd&&);
			explicit point_nd(const vector<length>&);
			explicit point_nd(const length&);
			explicit point_nd(const length&,const length&);
			explicit point_nd(const length&,const angle&);
			explicit point_nd(const length&,const length&,const length&);
			explicit point_nd(const length&,const angle&,length);
			explicit point_nd(const length&,const angle&,const angle&);
			explicit point_nd(const angle&,const angle&,const length&);
			explicit point_nd(const coordinates_nd&);
			explicit point_nd(string);

			point_nd& operator=(const point_nd&);
			point_nd& operator=(point_nd&&);
			point_nd& operator=(const coordinates_nd&);
			
			bool is_nd(int i) const;
			int get_nd() const;

			void set_position(const length&);
			void set_position(const length&,const length&);
			void set_position(const length&,const angle&);
			void set_position(const length&,const length&,const length&);
			void set_position(const length&,const angle&,length);
			void set_position(const length&,const angle&,const angle&);
			void set_position(const angle&,const angle&,const length&);
			void set_position(const vector<length>&);

			void rotate(int,int,const angle&);
			void move(const length&);
			void move(const displacement_2d&);
			void move(const length&,const length&);
			void move(const length&,const angle&);
			void move(const displacement_3d&);
			void move(const length&,const length&,const length&);
			void move(const length&,const angle&,length);
			void move(const length&,const angle&,const angle&);
			void move(const displacement_nd&);
			void move(const length&,const vector<angle>&);

			length distance_to_origin() const;

			vector<length> values;
	};

	string to_string(const point_nd&);
	length distance(const point_nd&,const point_nd&);
}

bool operator ==(const msci::point_nd&,const msci::point_nd&);
bool operator !=(const msci::point_nd&,const msci::point_nd&);

bool operator ==(const msci::point_nd&, const string&);
bool operator !=(const msci::point_nd&, const string&);

bool operator ==(const string&, const msci::point_nd&);
bool operator !=(const string&, const msci::point_nd&);

void operator +=(string&, const msci::point_nd&);
string operator +(const string&,const msci::point_nd&);
string operator +(const msci::point_nd&,const string&);

ostream& operator <<(ostream&,const msci::point_nd&);
istream& operator >>(istream&, msci::point_nd&);

#endif // MSCI_UNITS_TOPOLOGY_POINT_ND_HPP_INCLUDED

