#ifndef COORDINATES_2D_HPP_INCLUDED
#define COORDINATES_2D_HPP_INCLUDED

#include "topology/topology.hpp"
#include "meca_number/angle_number.hpp"

#include <cmath>

using namespace std;
using namespace msci;

namespace msci
{
	class coordinates_2d
	{
		public:
			coordinates_2d();

			virtual const space_type x_projection() const = 0;
			virtual const space_type y_projection() const = 0;
			virtual space_type get_value() const = 0;
	};

	inline space_type cartesian_2d_to_polar_r(space_type x,space_type y)
	{
		return std::sqrt(pow(x,2) + pow(y,2));
	}

	inline angle_type cartesian_2d_to_polar_angle(space_type x,space_type y)
	{
		return msci::atan_grade(y/x);
	}

	inline space_type polar_to_cartesian_2d_x(space_type r,const angle_number& angle)
	{
		return r*msci::cos(angle);
	}

	inline space_type polar_to_cartesian_2d_y(space_type r,const angle_number& angle)
	{
		return r*msci::sin(angle);
	}
}

#endif // COORDINATES_2D_HPP_INCLUDED
