#ifndef DIRECTIONAL_COORDINATES_HPP_INCLUDED
#define DIRECTIONAL_COORDINATES_HPP_INCLUDED

#include "coordinates_1d.hpp"
#include "math/topology/direction.hpp"

#include <functional>

using namespace std;

namespace math
{
	class directional_coordinates : public coordinates_1d
	{
		public:
			directional_coordinates(function<space_type()>,direction_symbol = right);

			virtual const space_type x_projection() const;
			virtual space_type get_value() const;

		private:
			function<space_type()> r;
			direction_lr direction;
	};
}

#endif // DIRECTIONAL_COORDINATES_HPP_INCLUDED
