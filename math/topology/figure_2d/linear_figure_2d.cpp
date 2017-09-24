#include "linear_figure_2d.hpp"

using namespace std;
using namespace physics::units;

namespace math
{
	linear_figure_2d::linear_figure_2d() : figure_2d(),vertices(),edges()
	{
	}

	linear_figure_2d::linear_figure_2d(const point_2d& new_center) : figure_2d(new_center),vertices(),edges()
	{
	}

	linear_figure_2d::linear_figure_2d(const vector<point_2d>& new_vertices) : figure_2d(point_2d((new_vertices[1].get_x() - new_vertices[0].get_x())/2,(new_vertices[1].get_y() - new_vertices[2].get_y())/2)),vertices(new_vertices),edges(create_edges())
	{

	}

	bool linear_figure_2d::has_vertices() const
	{
		return true;
	}

	length linear_figure_2d::get_perimeter() const
	{
		length value (0,"m");
		for (const line_2d& edge : edges)
		{
			value += edge.get_length();
		}
		return value;
	}

	void linear_figure_2d::translate_x(space_type x_translation)
	{
		figure_2d::translate_x(x_translation);
		for (point_2d& vertex : vertices)
		{
			vertex.get_x() += x_translation;
		}
	}

	void linear_figure_2d::translate_y(space_type y_translation)
	{
		figure_2d::translate_y(y_translation);
		for (point_2d& vertex : vertices)
		{
			vertex.get_y() += y_translation;
		}
	}

	void linear_figure_2d::rotate(angle_type x)
	{
		rotate(angle_number(x));
	}

	void linear_figure_2d::rotate(const math::angle_number& x)
	{
		for (point_2d& vertex : vertices)
		{
			vertex.get_x() = vertex.get_x()*math::sin(x);
			vertex.get_y() = vertex.get_y()*math::cos(x);
		}
	}

	void linear_figure_2d::scale(space_type x)
	{
		for (point_2d& vertex : vertices)
		{
			line_2d new_line (vertex,figure_2d::center);
			vertex.get_x() = vertex.get_x() + new_line.get_x_slope() * x;
			vertex.get_y() = vertex.get_y() + new_line.get_y_slope() * x;
		}
	}

	/*void linear_figure_2d::scale(const math::percentage_number& x)
	{
		for (point_2d& vertex : vertices)
		{
			space_type center_distance = distance(vertex,figure_2d::center);
			line_2d new_line (vertex,figure_2d::center);
			vertex.get_x() = vertex.get_x() + vertex.get_x() * new_line.get_x_slope() * x;
			vertex.get_y() = vertex.get_y() + vertex.get_y() * new_line.get_y_slope() * x;
		}
	}*/

	vector<line_2d> linear_figure_2d::create_edges()
	{
		vector<line_2d> new_edges = vector<line_2d>();
		for (unsigned int i = 0; i < vertices.size(); i++)
		{
			line_2d new_edge;
			if ((i + 1) != vertices.size())
			{
				new_edge = line_2d(vertices[i],vertices[i + 1]);
			}
			else
			{
				new_edge = line_2d(vertices[i],vertices[0]);
			}
			new_edges.push_back(new_edge);
		}
		return new_edges;
	}
}

bool operator ==(const math::linear_figure_2d& x,const math::linear_figure_2d& y)
{
	const vector<line_2d>& x_edges = x.get_edges();
	const vector<line_2d>& y_edges = y.get_edges();
	if (x_edges.size() == y_edges.size())
	{
		for (const line_2d& x_edge : x_edges)
		{
			bool edge_present = false;
			for (const line_2d& y_edge : y_edges)
			{
				if (x_edge.get_length() == y_edge.get_length())
				{
					edge_present = true;
				}
			}
			if (!edge_present)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const math::linear_figure_2d& x,const math::linear_figure_2d& y)
{
	return !(x == y);
}
