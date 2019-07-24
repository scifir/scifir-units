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
		float new_value = std::sqrt(pow(x,2) + pow(y,2) + pow(z,2));
		float angle2 = msci::acos_grade(z/new_value);
		float angle1 = msci::atan_grade(y/x);
		return tuple<float,float,float>(new_value,angle1,angle2);
	}

	tuple<float,float,float> spherical_to_cartesian(float r,float angle1,float angle2)
	{
		float x = r * msci::cos(angle1) * msci::sin(angle2);
		float y = r * msci::sin(angle1) * msci::sin(angle2);
		float z = r * msci::cos(angle2);
		return tuple<float,float,float>(x,y,z);
	}
}
