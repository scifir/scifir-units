#ifndef COORDINATES_1D_HPP_INCLUDED
#define COORDINATES_1D_HPP_INCLUDED

#include "msci/units/topology/topology.hpp"

using namespace std;

namespace msci
{
	class coordinates_1d
	{
		public:
			coordinates_1d();

			virtual const space_type x_projection() const = 0;
			virtual space_type get_value() const = 0;
	};
}

#endif // COORDINATES_1D_HPP_INCLUDED
