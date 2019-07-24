#ifndef MSCI_UNITS_COORDINATES_LIGHT_CARTESIAN_3DR_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_LIGHT_CARTESIAN_3DR_HPP_INCLUDED

#include "msci/units/topology/point_3d.hpp"
#include "msci/units/meca_number/angle.hpp"
#include "msci/units/coordinates/light/cartesian_3d.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace msci
{
	class cartesian_3dr
	{
		public:
			cartesian_3dr();
			cartesian_3dr(float,float,float,float,float);
			cartesian_3dr(const string&);

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

			inline float& get_z()
			{
				return z;
			}

			inline const float& get_z() const
			{
				return z;
			}

			inline msci::angle& get_angle()
			{
				return angle;
			}

			inline const msci::angle& get_angle() const
			{
				return angle;
			}

			inline msci::angle& get_angle2()
			{
				return angle2;
			}

			inline const msci::angle& get_angle2() const
			{
				return angle2;
			}

			string display() const;

		private:
			float x;
			float y;
			float z;
			msci::angle angle;
			msci::angle angle2;
	};

	float coordinates_distance(const cartesian_3dr&,const cartesian_3dr&);
}

bool operator ==(const msci::cartesian_3dr&,const msci::cartesian_3dr&);
bool operator !=(const msci::cartesian_3dr&,const msci::cartesian_3dr&);

bool operator ==(const msci::cartesian_3dr&,const msci::cartesian_3d&);
bool operator !=(const msci::cartesian_3dr&,const msci::cartesian_3d&);
bool operator ==(const msci::cartesian_3d&,const msci::cartesian_3dr&);
bool operator !=(const msci::cartesian_3d&,const msci::cartesian_3dr&);

bool operator ==(const msci::cartesian_3dr&,const msci::point_3d&);
bool operator !=(const msci::cartesian_3dr&,const msci::point_3d&);
bool operator ==(const msci::point_3d&,const msci::cartesian_3dr&);
bool operator !=(const msci::point_3d&,const msci::cartesian_3dr&);

ostream& operator << (ostream&, const msci::cartesian_3dr&);

#endif // MSCI_UNITS_COORDINATES_LIGHT_CARTESIAN_3DR_HPP_INCLUDED
