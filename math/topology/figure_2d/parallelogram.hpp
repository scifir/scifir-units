#ifndef MATH_TOPOLOGY_FIGURE_2D_PARALLELOGRAM_HPP_INCLUDED
#define MATH_TOPOLOGY_FIGURE_2D_PARALLELOGRAM_HPP_INCLUDED

#include "linear_figure_2d.hpp"

using namespace std;

namespace math
{
	class parallelogram : public linear_figure_2d
	{
		public:
			parallelogram();
			explicit parallelogram(space_type,space_type,space_type,space_type);
			explicit parallelogram(const point_2d&,space_type,space_type);
			explicit parallelogram(const vector<point_2d>&);

			inline space_type get_width() const
			{
				return width;
			}

			inline space_type get_height() const
			{
				return height;
			}

			virtual area get_area() const;

		private:
			space_type width;
			space_type height;
	};
}

#endif // MATH_TOPOLOGY_FIGURE_2D_PARALLELOGRAM_HPP_INCLUDED
