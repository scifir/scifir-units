#ifndef CARTESIAN_HPP_INCLUDED
#define CARTESIAN_HPP_INCLUDED

#include "msci/units/coordinates/coordinates_2d.hpp"
#include "msci/units/topology/topology.hpp"

using namespace std;

namespace msci
{
	class cartesian_coordinates_2d : public coordinates_2d
	{
		public:
			cartesian_coordinates_2d(space_type,space_type);

			virtual space_type get_value() const;
			virtual const space_type x_projection() const;
			virtual const space_type y_projection() const;

		private:
			space_type x;
			space_type y;
	};
}

#endif // CARTESIAN_HPP_INCLUDED
