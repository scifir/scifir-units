#ifndef MATH_TOPOLOGY_FIGURE_3D_FIGURE_3D_HPP_INCLUDED
#define MATH_TOPOLOGY_FIGURE_3D_FIGURE_3D_HPP_INCLUDED

#include "units.hpp"
#include "math/topology/point_3d.hpp"

using namespace std;

namespace math
{
	class figure_3d
	{
		public:
			figure_3d();

			inline const point_3d& get_center() const
			{
				return center;
			}

			virtual area get_surface() const = 0;
			virtual volume get_volume() const = 0;
			virtual bool is_inside(const point_3d&) const = 0;
			virtual bool is_inside(const figure_3d&) const = 0;
			virtual bool is_partially_inside(const figure_3d&) const = 0;
			virtual bool is_totally_inside(const figure_3d&) const = 0;

			inline bool is_outside(const point_3d& x) const
			{
				return !is_inside(x);
			}

			inline bool is_outside(const figure_3d& x) const
			{
				return !is_inside(x);
			}

		private:
			point_3d center;
	};
}

#endif // MATH_TOPOLOGY_FIGURE_3D_FIGURE_3D_HPP_INCLUDED
