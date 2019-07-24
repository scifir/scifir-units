#ifndef CARTESIAN_3D_HPP_INCLUDED
#define CARTESIAN_3D_HPP_INCLUDED

#include "msci/units/coordinates/coordinates_3d.hpp"

using namespace std;

namespace msci
{
	class cartesian_coordinates_3d : public coordinates_3d
	{
		public:
			cartesian_coordinates_3d(float,float,float);

			virtual float get_value() const;
			virtual const float x_projection() const;
			virtual const float y_projection() const;
			virtual const float z_projection() const;

		private:
			float x;
			float y;
			float z;
	};
}

#endif // CARTESIAN_3D_HPP_INCLUDED
