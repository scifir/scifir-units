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

	tuple<space_type,space_type,space_type> spherical_to_cartesian(space_type r,angle_type angle1,angle_type angle2)
	{
		space_type x = r * math::cos(angle1) * math::sin(angle2);
		space_type y = r * math::sin(angle1) * math::sin(angle2);
		space_type z = r * math::cos(angle2);
		return tuple<space_type,space_type,space_type>(x,y,z);
	}
}
