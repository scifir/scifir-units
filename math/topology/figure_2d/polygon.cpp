#include "polygon.hpp"

using namespace std;

namespace math
{
	polygon::polygon() : figure_2d(),vertices()
	{
	}

	length polygon::get_perimeter() const
	{
		return length("0 m");
	}

	area polygon::get_area() const
	{
		return area("0 m2");
	}

	bool polygon::is_inside(point_2d) const
	{
		return true;
	}

	bool polygon::is_inside(const figure_2d&) const
	{
		return true;
	}

	bool polygon::is_partially_inside(const figure_2d&) const
	{
		return true;
	}

	bool polygon::is_totally_inside(const figure_2d&) const
	{
		return true;
	}
}
