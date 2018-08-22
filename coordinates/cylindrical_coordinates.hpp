#ifndef CYLINDRICAL_COORDINATES_HPP_INCLUDED
#define CYLINDRICAL_COORDINATES_HPP_INCLUDED

#include "msci/units/coordinates/coordinates_3d.hpp"
#include "msci/units/meca_number/angle_number.hpp"

using namespace std;

namespace msci
{
	class cylindrical_coordinates : public coordinates_3d
	{
		public:
			cylindrical_coordinates();
			cylindrical_coordinates(space_type,angle_type,space_type);

			inline space_type get_r() const
			{
				return r;
			}

			inline const msci::angle_number& get_angle() const
			{
				return angle;
			}

			inline const space_type& get_z() const
			{
				return z;
			}

			virtual space_type get_value() const;
			virtual const space_type x_projection() const;
			virtual const space_type y_projection() const;
			virtual const space_type z_projection() const;

		private:
			space_type r;
			msci::angle_number angle;
			space_type z;
	};
}

#endif // CYLINDRICAL_COORDINATES_HPP_INCLUDED
