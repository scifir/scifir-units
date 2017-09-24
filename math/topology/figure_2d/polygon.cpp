#include "polygon.hpp"

#include <sstream>

using namespace std;

namespace math
{
	polygon::polygon() : linear_figure_2d()
	{
	}

	polygon::polygon(const vector<point_2d>& new_vertices) : linear_figure_2d(new_vertices)
	{
	}

	polygon::polygon(initializer_list<point_2d>& new_vertices) : linear_figure_2d(new_vertices)
	{
	}

	area polygon::get_area() const
	{
		return area("0 m2");
	}

	bool polygon::is_inside(const point_2d& x1) const
	{
		return (is_at_left(x1) and is_at_right(x1) and is_at_top(x1) and is_at_bottom(x1));
	}

	bool polygon::is_at_left(const point_2d& x1) const
	{
		for (const line_2d& edge : linear_figure_2d::edges)
		{
			if (edge.is_vertically_centered(x1) and edge.is_at_horizontal_left(x1))
			{
				return true;
			}
		}
		return false;
	}

	bool polygon::is_at_right(const point_2d& x1) const
	{
		for (const line_2d& edge : linear_figure_2d::edges)
		{
			if (edge.is_vertically_centered(x1) and edge.is_at_horizontal_right(x1))
			{
				return true;
			}
		}
		return false;
	}

	bool polygon::is_at_top(const point_2d& x1) const
	{
		for (const line_2d& edge : linear_figure_2d::edges)
		{
			if (edge.is_horizontally_centered(x1) and edge.is_vertical_upper(x1))
			{
				return true;
			}
		}
		return false;
	}

	bool polygon::is_at_bottom(const point_2d& x1) const
	{
		for (const line_2d& edge : linear_figure_2d::edges)
		{
			if (edge.is_horizontally_centered(x1) and edge.is_vertical_lower(x1))
			{
				return true;
			}
		}
		return false;
	}

	bool polygon::is_regular() const
	{
		return true;
	}

	bool polygon::is_irregular() const
	{
		return false;
	}

	wstring polygon::display() const
	{
		wostringstream out;
		out << "polygon: ";
		for (unsigned int i = 0; i < (vertices.size() - 1); i++)
		{
			out << vertices[i] << " ";
		}
		out << vertices[vertices.size() - 1];
		return out.str().c_str();
	}
}
