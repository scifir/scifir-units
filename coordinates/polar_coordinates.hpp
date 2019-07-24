#ifndef POLAR_COORDINATES_HPP_INCLUDED
#define POLAR_COORDINATES_HPP_INCLUDED

#include "msci/units/coordinates/coordinates_2d.hpp"
#include "msci/units/meca_number/angle.hpp"

using namespace std;

namespace msci
{
	class polar_coordinates : public coordinates_2d
	{
		public:
			polar_coordinates();
			polar_coordinates(function<float()>,float);

			inline float get_r() const
			{
				return r();
			}

			inline const msci::angle& get_angle() const
			{
				return angle;
			}

			virtual float get_value() const;
			virtual const float x_projection() const;
			virtual const float y_projection() const;

		private:
			function<float()> r;
			msci::angle angle;
	};
}

#endif // POLAR_COORDINATES_HPP_INCLUDED
