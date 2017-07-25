#ifndef CARTESIAN_3D_HPP_INCLUDED
#define CARTESIAN_3D_HPP_INCLUDED

#include "coordinates_3d.hpp"

using namespace std;

namespace math::topology
{
	class cartesian_coordinates_3d : public coordinates_3d
	{
		public:
			cartesian_coordinates_3d(space_type,space_type,space_type);

			virtual space_type get_value() const;
			virtual const space_type x_projection() const;
			virtual const space_type y_projection() const;
			virtual const space_type z_projection() const;

		private:
			space_type x;
			space_type y;
			space_type z;
	};
}

#endif // CARTESIAN_3D_HPP_INCLUDED
