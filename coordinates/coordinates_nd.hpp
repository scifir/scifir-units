#ifndef MSCI_UNITS_COORDINATES_COORDINATES_ND_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_COORDINATES_ND_HPP_INCLUDED

#include "topology/point_nd.hpp"

#include "predefined_units/kinematics_units.hpp"
#include "units.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace msci
{
	class coordinates_nd
	{
		public:
			coordinates_nd();
			coordinates_nd(const coordinates_nd&);
			coordinates_nd(coordinates_nd&&);
			coordinates_nd(const vector<length>&);
			coordinates_nd(const length&);
			coordinates_nd(const length&,const length&);
			coordinates_nd(const length&,const angle&);
			coordinates_nd(const length&,const length&,const length&);
			coordinates_nd(const length&,const angle&,length);
			coordinates_nd(const length&,const angle&,const angle&);
			coordinates_nd(const angle&,const angle&,const length&);
			coordinates_nd(const point_nd&);
			coordinates_nd(string);

			coordinates_nd& operator=(const coordinates_nd&);
			coordinates_nd& operator=(coordinates_nd&&);
			coordinates_nd& operator=(const point_nd&);
			
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

	string to_string(const coordinates_nd&);
	length distance(const coordinates_nd&,const coordinates_nd&);
}

bool operator ==(const msci::coordinates_nd&,const msci::coordinates_nd&);
bool operator !=(const msci::coordinates_nd&,const msci::coordinates_nd&);

ostream& operator <<(ostream&,const msci::coordinates_nd&);
istream& operator >>(istream&, msci::coordinates_nd&);

#endif // MSCI_UNITS_COORDINATES_COORDINATES_ND_HPP_INCLUDED
