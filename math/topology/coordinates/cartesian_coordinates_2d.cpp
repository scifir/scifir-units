#include "cartesian_coordinates_2d.hpp"

#include <cmath>

using namespace std;

namespace math
{
	cartesian_coordinates_2d::cartesian_coordinates_2d(space_type new_x,space_type new_y) : coordinates_2d(),x(new_x),y(new_y)
	{
	}

	space_type cartesian_coordinates_2d::get_value() const
	{
		return sqrt(pow(x,2) + pow(y,2));
	}

	const space_type cartesian_coordinates_2d::x_projection() const
	{
		return x;
	}

	const space_type cartesian_coordinates_2d::y_projection() const
	{
		return y;
	}
}
