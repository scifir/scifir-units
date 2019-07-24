#include "msci/units/coordinates/cartesian_coordinates_3d.hpp"

#include <cmath>

using namespace std;

namespace msci
{
    cartesian_coordinates_3d::cartesian_coordinates_3d(float new_x,float new_y,float new_z) : coordinates_3d(),x(new_x),y(new_y),z(new_z)
    {
    }

    float cartesian_coordinates_3d::get_value() const
	{
		return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	}

	const float cartesian_coordinates_3d::x_projection() const
	{
		return x;
	}

	const float cartesian_coordinates_3d::y_projection() const
	{
		return y;
	}

	const float cartesian_coordinates_3d::z_projection() const
	{
		return z;
	}
}
