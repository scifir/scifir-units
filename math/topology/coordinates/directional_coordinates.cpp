#include "directional_coordinates.hpp"

using namespace std;

namespace math::topology
{
	directional_coordinates::directional_coordinates(function<space_type()> new_r,direction_symbol new_direction) : r(new_r),direction(new_direction), coordinates_1d()
	{

	}

	const space_type directional_coordinates::x_projection() const
	{
		if (direction == right)
		{
			return r();
		}
		else if (direction == left)
		{
			return -r();
		}
	}

	space_type directional_coordinates::get_value() const
	{
		return r();
	}
}
