#include "point_3d.hpp"

#include <cmath>

using namespace std;

namespace math
{
	point_3d::point_3d(space_type new_x,space_type new_y,space_type new_z) : x(new_x),y(new_y),z(new_z)
	{
	}

	space_type point_3d::distance_to_origin() const
	{
		return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	}

	space_type distance(point_3d x1,point_3d x2)
	{
		return sqrt(pow(x1.get_x() - x2.get_x(),2) + pow(x1.get_y() - x2.get_y(),2) + pow(x1.get_z() - x2.get_z(),2));
	}
}
