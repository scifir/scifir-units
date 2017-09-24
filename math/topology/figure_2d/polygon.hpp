#ifndef MATH_TOPOLOGY_POLYGON_HPP_INCLUDED
#define MATH_TOPOLOGY_POLYGON_HPP_INCLUDED

#include "linear_figure_2d.hpp"

using namespace std;

namespace math
{
	/// \class polygon
	/// The polygon class represents normal polygons, formed by vertices and straight lines
	class polygon : public linear_figure_2d
	{
		public:
			polygon();
			explicit polygon(const vector<point_2d>&);
			polygon(initializer_list<point_2d>&);

			virtual area get_area() const;
			virtual bool is_inside(const point_2d&) const;

			bool is_at_left(const point_2d&) const;
			bool is_at_right(const point_2d&) const;
			bool is_at_top(const point_2d&) const;
			bool is_at_bottom(const point_2d&) const;

			virtual bool is_regular() const;
			virtual bool is_irregular() const;

			virtual wstring display() const;
	};
}

#endif // MATH_TOPOLOGY_POLYGON_HPP_INCLUDED
