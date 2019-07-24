#ifndef CARTESIAN_HPP_INCLUDED
#define CARTESIAN_HPP_INCLUDED

#include "msci/units/coordinates/coordinates_2d.hpp"

using namespace std;

namespace msci
{
	class cartesian_coordinates_2d : public coordinates_2d
	{
		public:
			cartesian_coordinates_2d(float,float);

			virtual float get_value() const;
			virtual const float x_projection() const;
			virtual const float y_projection() const;

		private:
			float x;
			float y;
	};
}

#endif // CARTESIAN_HPP_INCLUDED
