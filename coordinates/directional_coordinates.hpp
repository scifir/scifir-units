#ifndef DIRECTIONAL_COORDINATES_HPP_INCLUDED
#define DIRECTIONAL_COORDINATES_HPP_INCLUDED

#include "msci/units/coordinates/coordinates_1d.hpp"
#include "msci/units/topology/direction.hpp"

#include <functional>

using namespace std;

namespace msci
{
	class directional_coordinates : public coordinates_1d
	{
		public:
			directional_coordinates();
			directional_coordinates(function<float()>,direction_symbol = right);

			virtual const float x_projection() const;
			virtual float get_value() const;

		private:
			function<float()> r;
			direction_lr direction;
	};
}

#endif // DIRECTIONAL_COORDINATES_HPP_INCLUDED
