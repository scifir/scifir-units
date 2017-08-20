#include "point_2d.hpp"

#include <cmath>

using namespace std;

namespace math
{
	point_2d::point_2d(space_type new_x,space_type new_y) : x(new_x),y(new_y)
	{
	}

	space_type point_2d::distance_to_origin() const
	{
		return sqrt(pow(x,2) + pow(y,2));
	}

	space_type distance(point_2d x1,point_2d x2)
	{
		return sqrt(pow(x1.get_x() - x2.get_x(),2) + pow(x1.get_y() - x2.get_y(),2));
	}
}
