#include "spherical_coordinates.hpp"

#include <cmath>

using namespace std;

namespace math
{
	spherical_coordinates::spherical_coordinates(function<space_type()> new_value,angle_type new_angle1,angle_type new_angle2) : coordinates_3d()
	{
		r = new_value;
		angle1 = math::angle_number(new_angle1);
		angle2 = math::angle_number(new_angle2);
	}

	space_type spherical_coordinates::get_r() const
	{
		return r();
	}

	const math::angle_number& spherical_coordinates::get_angle1() const
	{
		return angle1;
	}

	const math::angle_number& spherical_coordinates::get_angle2() const
	{
		return angle2;
	}

	space_type spherical_coordinates::get_value() const
	{
		return r();
	}

	const space_type spherical_coordinates::x_projection() const
	{
		return spherical_to_cartesian_3d_x(r(),angle1,angle2);
	}

	const space_type spherical_coordinates::y_projection() const
	{
		return spherical_to_cartesian_3d_y(r(),angle1,angle2);
	}

	const space_type spherical_coordinates::z_projection() const
	{
		return spherical_to_cartesian_3d_z(r(),angle1,angle2);
	}
}
