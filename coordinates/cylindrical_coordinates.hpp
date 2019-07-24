#ifndef CYLINDRICAL_COORDINATES_HPP_INCLUDED
#define CYLINDRICAL_COORDINATES_HPP_INCLUDED

#include "msci/units/coordinates/coordinates_3d.hpp"
#include "msci/units/meca_number/angle.hpp"

using namespace std;

namespace msci
{
	class cylindrical_coordinates : public coordinates_3d
	{
		public:
			cylindrical_coordinates();
			cylindrical_coordinates(float,float,float);

			inline float get_r() const
			{
				return r;
			}

			inline const msci::angle& get_angle() const
			{
				return angle;
			}

			inline const float& get_z() const
			{
				return z;
			}

			virtual float get_value() const;
			virtual const float x_projection() const;
			virtual const float y_projection() const;
			virtual const float z_projection() const;

		private:
			float r;
			msci::angle angle;
			float z;
	};
}

#endif // CYLINDRICAL_COORDINATES_HPP_INCLUDED
