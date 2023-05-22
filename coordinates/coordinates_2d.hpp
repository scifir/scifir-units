#ifndef COORDINATES_2D_HPP_INCLUDED
#define COORDINATES_2D_HPP_INCLUDED

#include "msci/units/meca_number/angle.hpp"

#include <cmath>

using namespace std;
using namespace msci;

namespace msci
{
	class coordinates_2d
	{
		public:
			coordinates_2d();

			virtual const float x_projection() const = 0;
			virtual const float y_projection() const = 0;
			virtual float get_value() const = 0;
	};

	inline float cartesian_2d_to_polar_r(float x,float y)
	{
		return std::sqrt(std::pow(x,2) + std::pow(y,2));
	}

	inline float cartesian_2d_to_polar_angle(float x,float y)
	{
		return msci::atan_grade(y/x);
	}

	inline float polar_to_cartesian_2d_x(float r,const angle& angle)
	{
		return r*msci::cos(angle);
	}

	inline float polar_to_cartesian_2d_y(float r,const angle& angle)
	{
		return r*msci::sin(angle);
	}
}

#endif // COORDINATES_2D_HPP_INCLUDED
