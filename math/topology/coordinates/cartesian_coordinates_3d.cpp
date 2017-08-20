#include "cartesian_coordinates_3d.hpp"

#include <cmath>

using namespace std;

namespace math
{
    cartesian_coordinates_3d::cartesian_coordinates_3d(space_type new_x,space_type new_y,space_type new_z) : coordinates_3d()
    {
    	x = new_x;
    	y = new_y;
    	z = new_z;
    }

    space_type cartesian_coordinates_3d::get_value() const
	{
		return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	}

	const space_type cartesian_coordinates_3d::x_projection() const
	{
		return x;
	}

	const space_type cartesian_coordinates_3d::y_projection() const
	{
		return y;
	}

	const space_type cartesian_coordinates_3d::z_projection() const
	{
		return z;
	}
}
