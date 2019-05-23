#include "msci/units/coordinates/polar_coordinates.hpp"

#include <cmath>

using namespace std;

namespace msci
{
	polar_coordinates::polar_coordinates() : r(),angle()
	{
	}

	polar_coordinates::polar_coordinates(function<space_type()> new_r,angle_type new_angle) : coordinates_2d()
	{
		r = new_r;
		angle = msci::angle_number(new_angle);
	}

	space_type polar_coordinates::get_value() const
	{
		return r();
	}

	const space_type polar_coordinates::x_projection() const
	{
		return polar_to_cartesian_2d_x(r(),angle);
	}

	const space_type polar_coordinates::y_projection() const
	{
		return polar_to_cartesian_2d_y(r(),angle);
	}
}
