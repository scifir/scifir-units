#ifndef MATH_TOPOLOGY_FIGURE_2D_HPP_INCLUDED
#define MATH_TOPOLOGY_FIGURE_2D_HPP_INCLUDED

#include "math/topology/point_2d.hpp"
#include "units.hpp"

#include <vector>

using namespace std;
using namespace physics::units;

namespace math
{
	class figure_2d
	{
		public:
			figure_2d();

			inline point_2d get_center() const
			{
				return center;
			}

			virtual length get_perimeter() const = 0;
			virtual area get_area() const = 0;
			virtual bool is_inside(point_2d) const = 0;
			virtual bool is_inside(const figure_2d&) const = 0;
			virtual bool is_partially_inside(const figure_2d&) const = 0;
			virtual bool is_totally_inside(const figure_2d&) const = 0;

			inline bool is_outside(point_2d x) const
			{
				return !is_inside(x);
			}

			inline bool is_outside(const figure_2d& x) const
			{
				return !is_inside(x);
			}

		private:
			point_2d center;
	};
}

#endif // MATH_TOPOLOGY_FIGURE_2D_HPP_INCLUDED
