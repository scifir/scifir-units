#include "cylindrical_coordinates.hpp"

#include <cmath>

using namespace std;

namespace msci
{
	cylindrical_coordinates::cylindrical_coordinates(space_type new_r,angle_type new_angle,space_type new_z) : coordinates_3d(),r(new_r),angle(new_angle),z(new_z)
	{
	}

	space_type cylindrical_coordinates::get_r() const
	{
		return r;
	}

	const msci::angle_number& cylindrical_coordinates::get_angle() const
	{
		return angle;
	}

	const space_type& cylindrical_coordinates::get_z() const
	{
		return z;
	}

	space_type cylindrical_coordinates::get_value() const
	{
		return sqrt(pow(r,2) + pow(z,2));
	}

	const space_type cylindrical_coordinates::x_projection() const
	{
		return cylindrical_to_cartesian_3d_x(r,angle,z);
	}

	const space_type cylindrical_coordinates::y_projection() const
	{
		return cylindrical_to_cartesian_3d_y(r,angle,z);
	}

	const space_type cylindrical_coordinates::z_projection() const
	{
		return cylindrical_to_cartesian_3d_z(r,angle,z);
	}
}
