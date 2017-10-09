#include "parallelogram.hpp"

using namespace std;

namespace msci
{
	parallelogram::parallelogram() : linear_figure_2d(),width(),height()
	{
	}

	parallelogram::parallelogram(space_type new_x,space_type new_y,space_type new_width,space_type new_height) : linear_figure_2d(point_2d(new_x + width/2,new_y + height/2)),width(new_width),height(new_height)
	{
		point_2d x1(new_x,new_y);
		point_2d x2(new_x + width,new_y);
		point_2d x3(new_x,new_y + height);
		point_2d x4(new_x + width,new_y + height);
		vertices.push_back(x1);
		vertices.push_back(x2);
		vertices.push_back(x3);
		vertices.push_back(x4);
		create_edges();
	}

	parallelogram::parallelogram(const point_2d& new_center,space_type new_width,space_type new_height) : linear_figure_2d(new_center),width(new_width),height(new_height)
	{
		point_2d x1(figure_2d::center.get_x() - width/2,figure_2d::center.get_y() - height/2);
		point_2d x2(figure_2d::center.get_x() + width/2,figure_2d::center.get_y() - height/2);
		point_2d x3(figure_2d::center.get_x() - width/2,figure_2d::center.get_y() + height/2);
		point_2d x4(figure_2d::center.get_x() + width/2,figure_2d::center.get_y() + height/2);
		vertices.push_back(x1);
		vertices.push_back(x2);
		vertices.push_back(x3);
		vertices.push_back(x4);
		create_edges();
	}

	parallelogram::parallelogram(const vector<point_2d>& new_vertices) : linear_figure_2d(new_vertices),width(distance_between_points(vertices[0],vertices[1])),height(distance_between_points(vertices[2],vertices[3]))
	{
	}

	area parallelogram::get_area() const
	{
		return area(width * height,"m2");
	}
}
