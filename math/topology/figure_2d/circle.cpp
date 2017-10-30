#include "circle.hpp"

#include <cmath>
#include <sstream>

using namespace std;

namespace msci
{
	circle::circle() : figure_2d(),r()
	{
	}

	circle::circle(const point_2d& new_center,space_type new_r) : figure_2d(new_center),r(new_r)
	{
	}

	circle::circle(space_type new_x,space_type new_y,space_type new_r) : figure_2d(point_2d(new_x,new_y)),r(new_r)
	{
	}

	bool circle::has_vertices() const
	{
		return false;
	}

	length circle::get_perimeter() const
	{
		return length(2*PI*r,"m");
	}

	area circle::get_area() const
	{
		return area(PI*std::pow(r,2),"m");
	}

	bool circle::is_inside(const point_2d& x1) const
	{
		if (distance_between_points(x1,figure_2d::center) <= r)
		{
			return true;
		}
		return false;
	}

	void circle::rotate(angle_type x)
	{
		return;
	}

	void circle::rotate(const msci::angle_number& x)
	{
		return;
	}

	void circle::scale(space_type x)
	{
		r += x;
	}

	string circle::display() const
	{
		ostringstream out;
		out << "circle: " << "r " << r << " center" << figure_2d::center;
		return out.str().c_str();
	}
}

bool operator ==(const msci::circle& x,const msci::circle& y)
{
	return (x.get_r() == y.get_r());
}

bool operator !=(const msci::circle& x,const msci::circle& y)
{
	return !(x == y);
}
