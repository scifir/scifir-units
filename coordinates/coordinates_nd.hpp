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
			explicit coordinates_nd(const vector<length>&);
			explicit coordinates_nd(const length&);
			explicit coordinates_nd(const length&,const length&);
			explicit coordinates_nd(const length&,const angle&);
			explicit coordinates_nd(const length&,const length&,const length&);
			explicit coordinates_nd(const length&,const angle&,length);
			explicit coordinates_nd(const length&,const angle&,const angle&);
			explicit coordinates_nd(const angle&,const angle&,const length&);
			explicit coordinates_nd(const point_nd&);
			explicit coordinates_nd(string);

			coordinates_nd& operator=(const coordinates_nd&);
			coordinates_nd& operator=(coordinates_nd&&);
			coordinates_nd& operator=(const point_nd&);
			
			bool is_nd(int i) const;
			int get_nd() const;
			
			length get_p() const;
			angle get_theta() const;
			length get_r() const;
			angle get_phi() const;
			angle get_latitude() const;
			angle get_longitude() const;
			length get_altitude() const;

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
			
			string display_polar() const;
			string display_cylindrical() const;
			string display_spherical() const;
			string display_geographical() const;

			vector<length> values;
	};

	string to_string(const coordinates_nd&);
	length distance(const coordinates_nd&,const coordinates_nd&);
	length distance(const coordinates_nd&,const point_nd&);
	length distance(const point_nd&,const coordinates_nd&);
}

bool operator ==(const msci::coordinates_nd&,const msci::coordinates_nd&);
bool operator !=(const msci::coordinates_nd&,const msci::coordinates_nd&);

bool operator ==(const msci::coordinates_nd&,const msci::point_nd&);
bool operator !=(const msci::coordinates_nd&,const msci::point_nd&);
bool operator ==(const msci::point_nd&,const msci::coordinates_nd&);
bool operator !=(const msci::point_nd&,const msci::coordinates_nd&);

bool operator ==(const msci::coordinates_nd&, const string&);
bool operator !=(const msci::coordinates_nd&, const string&);

bool operator ==(const string&, const msci::coordinates_nd&);
bool operator !=(const string&, const msci::coordinates_nd&);

void operator +=(string&, const msci::coordinates_nd&);
string operator +(const string&,const msci::coordinates_nd&);
string operator +(const msci::coordinates_nd&,const string&);

ostream& operator <<(ostream&,const msci::coordinates_nd&);
istream& operator >>(istream&, msci::coordinates_nd&);

#endif // MSCI_UNITS_COORDINATES_COORDINATES_ND_HPP_INCLUDED
