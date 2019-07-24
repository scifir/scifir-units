#ifndef SPHERICAL_HPP_INCLUDED
#define SPHERICAL_HPP_INCLUDED

#include "msci/units/meca_number/angle.hpp"
#include "msci/units/coordinates/coordinates_3d.hpp"

using namespace std;

namespace msci
{
	class spherical_coordinates : public coordinates_3d
	{
		public:
			spherical_coordinates();
			spherical_coordinates(function<float()>, float, float);

			inline float get_r() const
			{
				return r();
			}

			inline const msci::angle& get_angle1() const
			{
				return angle1;
			}

			inline const msci::angle& get_angle2() const
			{
				return angle2;
			}

			virtual float get_value() const;
			virtual const float x_projection() const;
			virtual const float y_projection() const;
			virtual const float z_projection() const;

		private:
			function<float()> r;
			msci::angle angle1;
			msci::angle angle2;
	};
}

#endif // SPHERICAL_HPP_INCLUDED
