#ifndef SPHERICAL_HPP_INCLUDED
#define SPHERICAL_HPP_INCLUDED

#include "msci/units/meca_number/angle_number.hpp"
#include "msci/units/coordinates/coordinates_3d.hpp"

using namespace std;

namespace msci
{
	class spherical_coordinates : public coordinates_3d
	{
		public:
			spherical_coordinates();
			spherical_coordinates(function<space_type()>, angle_type, angle_type);

			inline space_type get_r() const
			{
				return r();
			}

			inline const msci::angle_number& get_angle1() const
			{
				return angle1;
			}

			inline const msci::angle_number& get_angle2() const
			{
				return angle2;
			}

			virtual space_type get_value() const;
			virtual const space_type x_projection() const;
			virtual const space_type y_projection() const;
			virtual const space_type z_projection() const;

		private:
			function<space_type()> r;
			msci::angle_number angle1;
			msci::angle_number angle2;
	};
}

#endif // SPHERICAL_HPP_INCLUDED
