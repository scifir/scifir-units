#include "msci/units/coordinates/polar_coordinates.hpp"

#include <cmath>

using namespace std;

namespace msci
{
	polar_coordinates::polar_coordinates() : r(),angle()
	{
	}

	polar_coordinates::polar_coordinates(function<float()> new_r,float new_angle) : coordinates_2d()
	{
		r = new_r;
		angle = msci::angle(new_angle);
	}

	float polar_coordinates::get_value() const
	{
		return r();
	}

	const float polar_coordinates::x_projection() const
	{
		return polar_to_cartesian_2d_x(r(),angle);
	}

	const float polar_coordinates::y_projection() const
	{
		return polar_to_cartesian_2d_y(r(),angle);
	}
}
