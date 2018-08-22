#include "msci/units/coordinates/directional_coordinates.hpp"

using namespace std;

namespace msci
{
	directional_coordinates::directional_coordinates() : coordinates_1d(),r(),direction()
	{
	}

	directional_coordinates::directional_coordinates(function<space_type()> new_r,direction_symbol new_direction) : coordinates_1d(),r(new_r),direction(new_direction)
	{

	}

	const space_type directional_coordinates::x_projection() const
	{
		if (direction == right)
		{
			return r();
		}
		else
		{
			return -r();
		}
	}

	space_type directional_coordinates::get_value() const
	{
		return r();
	}
}
