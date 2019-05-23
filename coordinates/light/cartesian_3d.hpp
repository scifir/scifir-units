#ifndef MSCI_UNITS_COORDINATES_LIGHT_CARTESIAN_3D_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_LIGHT_CARTESIAN_3D_HPP_INCLUDED

#include "msci/units/topology/point_3d.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class cartesian_3d
	{
		public:
			cartesian_3d();
			cartesian_3d(float,float,float);
			cartesian_3d(const string&);

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

			string display() const;

		private:
			float x;
			float y;
			float z;
	};

	float coordinates_distance(const cartesian_3d&,const cartesian_3d&);
}

bool operator ==(const msci::cartesian_3d&,const msci::cartesian_3d&);
bool operator !=(const msci::cartesian_3d&,const msci::cartesian_3d&);

bool operator ==(const msci::cartesian_3d&,const msci::point_3d&);
bool operator !=(const msci::cartesian_3d&,const msci::point_3d&);
bool operator ==(const msci::point_3d&,const msci::cartesian_3d&);
bool operator !=(const msci::point_3d&,const msci::cartesian_3d&);

ostream& operator << (ostream&, const msci::cartesian_3d&);

#endif // MSCI_UNITS_COORDINATES_LIGHT_CARTESIAN_3D_HPP_INCLUDED
