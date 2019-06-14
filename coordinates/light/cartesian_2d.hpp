#ifndef MSCI_UNITS_COORDINATES_LIGHT_CARTESIAN_2D_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_LIGHT_CARTESIAN_2D_HPP_INCLUDED

#include "msci/units/topology/point_2d.hpp"
#include "msci/units/units/unit_basic.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class cartesian_2d
	{
		public:
			cartesian_2d();
			cartesian_2d(const length&,const length&);
			cartesian_2d(const point_2d&);
			cartesian_2d(const string&);

			void operator= (const point_2d&);

			inline length& get_x()
			{
				return x;
			}

			inline const length& get_x() const
			{
				return x;
			}

			inline length& get_y()
			{
				return y;
			}

			inline const length& get_y() const
			{
				return y;
			}

			length get_p() const;
			angle_number get_angle() const;

			void set_x(const length&);
			void set_y(const length&);
			void move_angle(const angle_number&);
			void move_in_direction(const length&,const angle_number&);

			string display() const;

		private:
			length x;
			length y;
	};

	float coordinates_distance(const cartesian_2d&,const cartesian_2d&);
}

string operator +(const string&,const msci::cartesian_2d&);
string operator +(const msci::cartesian_2d&,const string&);

bool operator ==(const msci::cartesian_2d&,const msci::cartesian_2d&);
bool operator !=(const msci::cartesian_2d&,const msci::cartesian_2d&);

bool operator ==(const msci::cartesian_2d&,const msci::point_2d&);
bool operator !=(const msci::cartesian_2d&,const msci::point_2d&);
bool operator ==(const msci::point_2d&,const msci::cartesian_2d&);
bool operator !=(const msci::point_2d&,const msci::cartesian_2d&);

ostream& operator << (ostream&, const msci::cartesian_2d&);

#endif // MSCI_UNITS_COORDINATES_LIGHT_CARTESIAN_2D_HPP_INCLUDED
