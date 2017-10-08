#include "figure_2d.hpp"
#include "linear_figure_2d.hpp"
#include "circle.hpp"

using namespace std;

namespace msci
{
	figure_2d::figure_2d() : center()
	{
	}

	figure_2d::figure_2d(const point_2d& new_center) : center(new_center)
	{
	}

	bool figure_2d::is_partially_inside(const figure_2d& f1) const
	{
		if (f1.has_vertices())
		{
			const linear_figure_2d& f1_linear = static_cast<const linear_figure_2d&>(f1);
			for (const point_2d& vertex : f1_linear.get_vertices())
			{
				if (is_inside(vertex))
				{
					return true;
				}
			}
		}
		else
		{
			const circle& f1_circle = static_cast<const circle&>(f1);
			return f1_circle.is_partially_inside(*this);
		}
		return false;
	}

	bool figure_2d::is_totally_inside(const figure_2d& f1) const
	{
		if (f1.has_vertices())
		{
			const linear_figure_2d& f1_linear = static_cast<const linear_figure_2d&>(f1);
			for (const point_2d& vertex : f1_linear.get_vertices())
			{
				if (!is_inside(vertex))
				{
					return false;
				}
			}
		}
		else
		{
			const circle& f1_circle = static_cast<const circle&>(f1);
			return f1_circle.is_totally_inside(*this);
		}
		return true;
	}

	void figure_2d::translate_x(space_type x_translation)
	{
		center.get_x() += x_translation;
	}

	void figure_2d::translate_y(space_type y_translation)
	{
		center.get_y() += y_translation;
	}

	void figure_2d::print() const
	{
		wcout << display() << endl;
	}
}

wostream& operator <<(wostream& os,const msci::figure_2d& x)
{
	return os << x.display();
}
