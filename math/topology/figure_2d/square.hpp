#ifndef MATH_TOPOLOGY_FIGURE_2D_SQUARE_HPP_INCLUDED
#define MATH_TOPOLOGY_FIGURE_2D_SQUARE_HPP_INCLUDED

#include "figure_2d.hpp"

using namespace std;

namespace msci
{
	class square : public figure_2d
	{
		public:
			square();
			square(space_type);
	};
}

#endif // MATH_TOPOLOGY_FIGURE_2D_SQUARE_HPP_INCLUDED
