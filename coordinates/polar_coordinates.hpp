#ifndef POLAR_COORDINATES_HPP_INCLUDED
#define POLAR_COORDINATES_HPP_INCLUDED

#include "msci/units/coordinates/coordinates_2d.hpp"
#include "msci/units/meca_number/angle_number.hpp"

using namespace std;

namespace msci
{
	class polar_coordinates : public coordinates_2d
	{
		public:
			polar_coordinates();
			polar_coordinates(function<space_type()>,angle_type);

			inline space_type get_r() const
			{
				return r();
			}

			inline const msci::angle_number& get_angle() const
			{
				return angle;
			}

			virtual space_type get_value() const;
			virtual const space_type x_projection() const;
			virtual const space_type y_projection() const;

		private:
			function<space_type()> r;
			msci::angle_number angle;
	};
}

#endif // POLAR_COORDINATES_HPP_INCLUDED
