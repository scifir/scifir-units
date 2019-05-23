#ifndef MSCI_UNITS_COORDINATES_LIGHT_CARTESIAN_2DR_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_LIGHT_CARTESIAN_2DR_HPP_INCLUDED

#include "msci/units/topology/point_2d.hpp"
#include "msci/units/meca_number/angle_number.hpp"
#include "msci/units/coordinates/light/cartesian_2d.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class cartesian_2dr
	{
		public:
			cartesian_2dr();
			cartesian_2dr(float,float,float);
			cartesian_2dr(const string&);

			inline float& get_x()
			{
				return x;
			}

			inline const float& get_x() const
			{
				return x;
			}

			inline float& get_y()
			{
				return y;
			}

			inline const float& get_y() const
			{
				return y;
			}

			inline angle_number& get_angle()
			{
				return angle;
			}

			inline const angle_number& get_angle() const
			{
				return angle;
			}

			string display() const;

		private:
			float x;
			float y;
			angle_number angle;
	};

	float coordinates_distance(const cartesian_2dr&,const cartesian_2dr&);
}

bool operator ==(const msci::cartesian_2dr&,const msci::cartesian_2dr&);
bool operator !=(const msci::cartesian_2dr&,const msci::cartesian_2dr&);

bool operator ==(const msci::cartesian_2dr&,const msci::cartesian_2d&);
bool operator !=(const msci::cartesian_2dr&,const msci::cartesian_2d&);
bool operator ==(const msci::cartesian_2d&,const msci::cartesian_2dr&);
bool operator !=(const msci::cartesian_2d&,const msci::cartesian_2dr&);

bool operator ==(const msci::cartesian_2dr&,const msci::point_2d&);
bool operator !=(const msci::cartesian_2dr&,const msci::point_2d&);
bool operator ==(const msci::point_2d&,const msci::cartesian_2dr&);
bool operator !=(const msci::point_2d&,const msci::cartesian_2dr&);

ostream& operator << (ostream&, const msci::cartesian_2dr&);

#endif // MSCI_UNITS_COORDINATES_LIGHT_CARTESIAN_2DR_HPP_INCLUDED
