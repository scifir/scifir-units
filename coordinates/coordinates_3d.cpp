#include "coordinates_3d.hpp"

#include "meca_number/angle_number.hpp"

#include <cmath>

using namespace std;

namespace msci
{
	coordinates_3d::coordinates_3d()
	{
	}

	tuple<space_type,angle_type,angle_type> cartesian_to_spherical(space_type x,space_type y,space_type z)
	{
		space_type new_value = std::sqrt(pow(x,2) + pow(y,2) + pow(z,2));
		angle_type angle2 = msci::acos_grade(z/new_value);
		angle_type angle1 = msci::atan_grade(y/x);
		return tuple<space_type,angle_type,angle_type>(new_value,angle1,angle2);
	}

	tuple<space_type,space_type,space_type> spherical_to_cartesian(space_type r,angle_type angle1,angle_type angle2)
	{
		space_type x = r * msci::cos(angle1) * msci::sin(angle2);
		space_type y = r * msci::sin(angle1) * msci::sin(angle2);
		space_type z = r * msci::cos(angle2);
		return tuple<space_type,space_type,space_type>(x,y,z);
	}
}
