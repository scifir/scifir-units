#ifndef CYLINDRICAL_COORDINATES_HPP_INCLUDED
#define CYLINDRICAL_COORDINATES_HPP_INCLUDED

#include "coordinates_3d.hpp"
#include "math/number/angle_number.hpp"

using namespace std;

namespace math::topology
{
	class cylindrical_coordinates : public coordinates_3d
	{
		public:
			cylindrical_coordinates(space_type,angle_type,space_type);

			space_type get_r() const;
			const math::number::angle_number& get_angle() const;
			const space_type& get_z() const;

			virtual space_type get_value() const;
			virtual const space_type x_projection() const;
			virtual const space_type y_projection() const;
			virtual const space_type z_projection() const;

		private:
			space_type r;
			math::number::angle_number angle;
			space_type z;
	};
}

#endif // CYLINDRICAL_COORDINATES_HPP_INCLUDED
