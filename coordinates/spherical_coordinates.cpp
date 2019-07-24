#include "msci/units/coordinates/spherical_coordinates.hpp"

#include <cmath>

using namespace std;

namespace msci
{
	spherical_coordinates::spherical_coordinates() : r(),angle1(),angle2()
	{
	}

	spherical_coordinates::spherical_coordinates(function<float()> new_value,float new_angle1,float new_angle2) : coordinates_3d()
	{
		r = new_value;
		angle1 = msci::angle(new_angle1);
		angle2 = msci::angle(new_angle2);
	}

	float spherical_coordinates::get_value() const
	{
		return r();
	}

	const float spherical_coordinates::x_projection() const
	{
		return spherical_to_cartesian_3d_x(r(),angle1,angle2);
	}

	const float spherical_coordinates::y_projection() const
	{
		return spherical_to_cartesian_3d_y(r(),angle1,angle2);
	}

	const float spherical_coordinates::z_projection() const
	{
		return spherical_to_cartesian_3d_z(r(),angle1,angle2);
	}
}
