#ifndef COORDINATES_3D_HPP_INCLUDED
#define COORDINATES_3D_HPP_INCLUDED

#include "msci/units/meca_number/angle.hpp"

#include <cmath>
#include <tuple>

using namespace std;
using namespace msci;

namespace msci
{
	class coordinates_3d
	{
		public:
			coordinates_3d();

			virtual const float x_projection() const = 0;
			virtual const float y_projection() const = 0;
			virtual const float z_projection() const = 0;
			virtual float get_value() const = 0;
			virtual string display_parameters() const = 0;
			virtual string display_position() const = 0;
	};

	inline float cartesian_3d_to_cylindrical_r(float x,float y,float z)
	{
		return std::sqrt(std::pow(x,2) + std::pow(y,2));
	}

	inline float cartesian_3d_to_cylindrical_angle(float x,float y,float z)
	{
		return std::atan(y/x);
	}

	inline float cartesian_3d_to_cylindrical_z(float x,float y,float z)
	{
		return z;
	}

	inline float cartesian_3d_to_spherical_r(float x,float y,float z)
	{
		return std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2));
	}

	inline float cartesian_3d_to_spherical_angle1(float x,float y,float z)
	{
		return std::atan(y/x);
	}

	inline float cartesian_3d_to_spherical_angle2(float x,float y,float z)
	{
		return std::acos(z/std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2)));
	}

	inline float spherical_to_cartesian_3d_x(float r,const angle& angle1, const angle& angle2)
	{
		return r * msci::cos(angle1) * msci::sin(angle2);
	}

	inline float spherical_to_cartesian_3d_y(float r,const angle& angle1, const angle& angle2)
	{
		return r * msci::sin(angle1) * msci::sin(angle2);
	}

	inline float spherical_to_cartesian_3d_z(float r,const angle& angle1, const angle& angle2)
	{
		return r * msci::cos(angle2);
	}

	inline float spherical_to_cylindrical_r(float r,const angle& angle1, const angle& angle2)
	{
		return r * msci::sin(angle2);
	}

	inline float spherical_to_cylindrical_angle(float r,const angle& angle1, const angle& angle2)
	{
		return angle1.get_value();
	}

	inline float spherical_to_cylindrical_z(float r,const angle& angle1, const angle& angle2)
	{
		return r * msci::cos(angle2);
	}

	inline float cylindrical_to_cartesian_3d_x(float r,const angle& angle, float z)
	{
		return r * msci::cos(angle);
	}

	inline float cylindrical_to_cartesian_3d_y(float r,const angle& angle, float z)
	{
		return r * msci::sin(angle);
	}

	inline float cylindrical_to_cartesian_3d_z(float r,const angle& angle, float z)
	{
		return z;
	}

	inline float cylindrical_to_spherical_r(float r,const angle& angle, float z)
	{
		return std::sqrt(std::pow(r,2) + std::pow(z,2));
	}

	inline float cylindrical_to_spherical_angle1(float r,const angle& angle, float z)
	{
		return angle.get_value();
	}

	inline float cylindrical_to_spherical_angle2(float r,const angle& angle, float z)
	{
		return std::atan(r/z);
	}

	tuple<float,float,float> cartesian_to_spherical(float,float,float);
	tuple<float,float,float> spherical_to_cartesian(float,float,float);
}

#endif // COORDINATES_3D_HPP_INCLUDED
