#ifndef MATH_TOPOLOGY_POINT_3D_HPP_INCLUDED
#define MATH_TOPOLOGY_POINT_3D_HPP_INCLUDED

#include "topology.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class point_3d
	{
		public:
			point_3d();
			point_3d(space_type,space_type,space_type);

			inline space_type get_x() const
			{
				return x;
			}

			inline space_type get_y() const
			{
				return y;
			}

			inline space_type get_z() const
			{
				return z;
			}

			space_type distance_to_origin() const;

			wstring display() const;
			void print() const;

		private:
			space_type x;
			space_type y;
			space_type z;
	};

	space_type distance_between_points(const point_3d&,const point_3d&);
}

bool operator ==(const msci::point_3d&,const msci::point_3d&);
bool operator !=(const msci::point_3d&,const msci::point_3d&);
wostream& operator <<(wostream&,const msci::point_3d&);

#endif // MATH_TOPOLOGY_POINT_3D_HPP_INCLUDED
