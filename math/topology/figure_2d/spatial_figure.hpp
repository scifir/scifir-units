#ifndef MATH_TOPOLOGY_FIGURE_2D_SPATIAL_FIGURE_HPP_INCLUDED
#define MATH_TOPOLOGY_FIGURE_2D_SPATIAL_FIGURE_HPP_INCLUDED

#include "math/topology/coordinates/cartesian_coordinates_2d.hpp"
#include "figure_2d.hpp"

using namespace std;

namespace msci
{
	template<typename T>
	class spatial_figure : public T,public cartesian_coordinates_2d
	{
		public:
			using T::T;
	};
}

#endif // MATH_TOPOLOGY_FIGURE_2D_SPATIAL_FIGURE_HPP_INCLUDED
