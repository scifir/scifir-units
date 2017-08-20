#include "coordinates_3d.hpp"

#include "math/number/angle_number.hpp"

#include <cmath>

using namespace std;

namespace math
{
	coordinates_3d::coordinates_3d()
	{
	}

	tuple<space_type,angle_type,angle_type> cartesian_to_spherical(space_type x,space_type y,space_type z)
	{
		space_type new_value = std::sqrt(pow(x,2) + pow(y,2) + pow(z,2));
		angle_type angle2 = math::acos_grade(z/new_value);
		angle_type angle1 = math::atan_grade(y/x);
		return tuple<space_type,angle_type,angle_type>(new_value,angle1,angle2);
	}

	tuple<space_type,angle_type,angle_type> spherical_to_cartesian(space_type x,angle_type y,angle_type z)
	{
	}
}
