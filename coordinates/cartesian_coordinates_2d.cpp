#include "msci/units/coordinates/cartesian_coordinates_2d.hpp"

#include <cmath>

using namespace std;

namespace msci
{
	cartesian_coordinates_2d::cartesian_coordinates_2d(float new_x,float new_y) : coordinates_2d(),x(new_x),y(new_y)
	{
	}

	float cartesian_coordinates_2d::get_value() const
	{
		return sqrt(pow(x,2) + pow(y,2));
	}

	const float cartesian_coordinates_2d::x_projection() const
	{
		return x;
	}

	const float cartesian_coordinates_2d::y_projection() const
	{
		return y;
	}
}
