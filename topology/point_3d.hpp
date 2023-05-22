#ifndef MSCI_UNITS_TOPOLOGY_POINT_3D_HPP_INCLUDED
#define MSCI_UNITS_TOPOLOGY_POINT_3D_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class point_3d
	{
		public:
			point_3d();
			point_3d(float,float,float);

			inline float get_x() const
			{
				return x;
			}

			inline float get_y() const
			{
				return y;
			}

			inline float get_z() const
			{
				return z;
			}

			float distance_to_origin() const;

			string display() const;

		private:
			float x;
			float y;
			float z;
	};

	float distance_between_points(const point_3d&,const point_3d&);
}

bool operator ==(const msci::point_3d&,const msci::point_3d&);
bool operator !=(const msci::point_3d&,const msci::point_3d&);
ostream& operator <<(ostream&,const msci::point_3d&);

#endif // MSCI_UNITS_TOPOLOGY_POINT_3D_HPP_INCLUDED
