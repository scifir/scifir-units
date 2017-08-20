#ifndef COORDINATES_3D_HPP_INCLUDED
#define COORDINATES_3D_HPP_INCLUDED

#include "math/number/angle_number.hpp"
#include "math/topology/topology.hpp"

#include <cmath>
#include <tuple>

using namespace std;
using namespace math;

namespace math
{
	class coordinates_3d
	{
		public:
			coordinates_3d();

			virtual const space_type x_projection() const = 0;
			virtual const space_type y_projection() const = 0;
			virtual const space_type z_projection() const = 0;
			virtual space_type get_value() const = 0;
	};

	inline space_type cartesian_3d_to_cylindrical_r(space_type x,space_type y,space_type z)
	{
		return std::sqrt(pow(x,2) + pow(y,2));
	}

	inline angle_type cartesian_3d_to_cylindrical_angle(space_type x,space_type y,space_type z)
	{
		return math::atan_grade(y/x);
	}

	inline angle_type cartesian_3d_to_cylindrical_z(space_type x,space_type y,space_type z)
	{
		return z;
	}

	inline space_type cartesian_3d_to_spherical_r(space_type x,space_type y,space_type z)
	{
		return std::sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	}

	inline angle_type cartesian_3d_to_spherical_angle1(space_type x,space_type y,space_type z)
	{
		return math::atan_grade(y/x);
	}

	inline angle_type cartesian_3d_to_spherical_angle2(space_type x,space_type y,space_type z)
	{
		return math::acos_grade(z/std::sqrt(pow(x,2) + pow(y,2) + pow(z,2)));
	}

	inline space_type spherical_to_cartesian_3d_x(space_type r,const angle_number& angle1, const angle_number& angle2)
	{
		return r * math::cos(angle1) * math::sin(angle2);
	}

	inline space_type spherical_to_cartesian_3d_y(space_type r,const angle_number& angle1, const angle_number& angle2)
	{
		return r * math::sin(angle1) * math::sin(angle2);
	}

	inline space_type spherical_to_cartesian_3d_z(space_type r,const angle_number& angle1, const angle_number& angle2)
	{
		return r * math::cos(angle2);
	}

	inline space_type spherical_to_cylindrical_r(space_type r,const angle_number& angle1, const angle_number& angle2)
	{
		return r * math::sin(angle2);
	}

	inline angle_type spherical_to_cylindrical_angle(space_type r,const angle_number& angle1, const angle_number& angle2)
	{
		return angle1.get_value();
	}

	inline space_type spherical_to_cylindrical_z(space_type r,const angle_number& angle1, const angle_number& angle2)
	{
		return r * math::cos(angle2);
	}

	inline space_type cylindrical_to_cartesian_3d_x(space_type r,const angle_number& angle, space_type z)
	{
		return r * math::cos(angle);
	}

	inline space_type cylindrical_to_cartesian_3d_y(space_type r,const angle_number& angle, space_type z)
	{
		return r * math::sin(angle);
	}

	inline space_type cylindrical_to_cartesian_3d_z(space_type r,const angle_number& angle, space_type z)
	{
		return z;
	}

	inline space_type cylindrical_to_spherical_r(space_type r,const angle_number& angle, space_type z)
	{
		return std::sqrt(pow(r,2) + pow(z,2));
	}

	inline space_type cylindrical_to_spherical_angle1(space_type r,const angle_number& angle, space_type z)
	{
		return angle.get_value();
	}

	inline space_type cylindrical_to_spherical_angle2(space_type r,const angle_number& angle, space_type z)
	{
		return std::atan(r/z);
	}

	tuple<space_type,angle_type,angle_type> cartesian_to_spherical(space_type,space_type,space_type);
	tuple<space_type,space_type,space_type> spherical_to_cartesian(space_type,angle_type,angle_type);
}

#endif // COORDINATES_3D_HPP_INCLUDED
