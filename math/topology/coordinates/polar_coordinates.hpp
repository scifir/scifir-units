#ifndef POLAR_COORDINATES_HPP_INCLUDED
#define POLAR_COORDINATES_HPP_INCLUDED

#include "coordinates_2d.hpp"
#include "math/number/angle_number.hpp"

using namespace std;

namespace msci
{
	class polar_coordinates : public coordinates_2d
	{
		public:
			polar_coordinates(function<space_type()>,angle_type);

			space_type get_r() const;
			const msci::angle_number& get_angle() const;

			virtual space_type get_value() const;
			virtual const space_type x_projection() const;
			virtual const space_type y_projection() const;

		private:
			function<space_type()> r;
			msci::angle_number angle;
	};
}

#endif // POLAR_COORDINATES_HPP_INCLUDED
