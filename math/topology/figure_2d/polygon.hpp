#ifndef MATH_TOPOLOGY_POLYGON_HPP_INCLUDED
#define MATH_TOPOLOGY_POLYGON_HPP_INCLUDED

#include "figure_2d.hpp"

using namespace std;

namespace math
{
	/// The polygon class represents normal polygons, formed by vertices and straight lines
	class polygon : public figure_2d
	{
		public:
			polygon();

			inline vector<point_2d> get_vertices() const
			{
				return vertices;
			}

			virtual length get_perimeter() const;
			virtual area get_area() const;
			virtual bool is_inside(point_2d) const;
			virtual bool is_inside(const figure_2d&) const;
			virtual bool is_partially_inside(const figure_2d&) const;
			virtual bool is_totally_inside(const figure_2d&) const;

			bool is_regular() const;

			inline bool is_irregular() const
			{
				return !is_regular();
			}

		private:
			vector<point_2d> vertices;
	};
}

#endif // MATH_TOPOLOGY_POLYGON_HPP_INCLUDED
