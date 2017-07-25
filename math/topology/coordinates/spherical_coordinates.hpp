#ifndef SPHERICAL_HPP_INCLUDED
#define SPHERICAL_HPP_INCLUDED

#include "math/number/angle_number.hpp"
#include "coordinates_3d.hpp"

using namespace std;

namespace math::topology
{
	class spherical_coordinates : public coordinates_3d
	{
		public:
			spherical_coordinates(function<space_type()>, angle_type, angle_type);

			space_type get_r() const;
			const math::number::angle_number& get_angle1() const;
			const math::number::angle_number& get_angle2() const;

			virtual space_type get_value() const;
			virtual const space_type x_projection() const;
			virtual const space_type y_projection() const;
			virtual const space_type z_projection() const;

		private:
			function<space_type()> r;
			math::number::angle_number angle1;
			math::number::angle_number angle2;
	};
}

#endif // SPHERICAL_HPP_INCLUDED
