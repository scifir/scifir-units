#include "msci/units/coordinates/coordinates_3d.hpp"

#include "msci/units/meca_number/angle.hpp"

#include <cmath>

using namespace std;

namespace msci
{
	coordinates_3d::coordinates_3d()
	{
	}

	tuple<float,float,float> cartesian_to_spherical(float x,float y,float z)
	{
		float new_value = std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2));
		float angle2 = std::acos(z/new_value);
		float angle1 = std::atan(y/x);
		return tuple<float,float,float>(new_value,angle1,angle2);
	}

	tuple<float,float,float> spherical_to_cartesian(float r,float angle1,float angle2)
	{
		float x = r * std::cos(angle1) * std::sin(angle2);
		float y = r * std::sin(angle1) * std::sin(angle2);
		float z = r * std::cos(angle2);
		return tuple<float,float,float>(x,y,z);
	}
}
