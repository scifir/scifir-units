#include "msci/units/coordinates/directional_coordinates.hpp"

using namespace std;

namespace msci
{
	directional_coordinates::directional_coordinates() : coordinates_1d(),r(),direction()
	{
	}

	directional_coordinates::directional_coordinates(function<float()> new_r,direction_symbol new_direction) : coordinates_1d(),r(new_r),direction(new_direction)
	{

	}

	const float directional_coordinates::x_projection() const
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

	float directional_coordinates::get_value() const
	{
		return r();
	}
}
