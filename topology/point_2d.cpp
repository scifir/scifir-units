#include "msci/units/topology/point_2d.hpp"

#include <cmath>
#include <sstream>

using namespace std;

namespace msci
{
	point_2d::point_2d() : x(),y()
	{
	}

	point_2d::point_2d(const length& new_x,const length& new_y) : x(new_x),y(new_y)
	{
	}

	void point_2d::move_in_direction(const length& x_value,const angle& x_angle)
	{
		x = x + x_value*cos(x_angle);
		y = y + x_value*sin(x_angle);
	}

	length point_2d::distance_to_origin() const
	{
		return length("1 m");
		//return sqrt(pow(x,2) + pow(y,2));
	}

	string point_2d::display() const
	{
		ostringstream out;
		out << "(" << x << "," << y << ")";
		return out.str();
	}

	length distance_between_points(const point_2d& x1,const point_2d& x2)
	{
		return length("1 m");
		//return length(sqrt(pow(x1.get_x() - x2.get_x(),2) + pow(x1.get_y() - x2.get_y(),2)));
	}
}

bool operator ==(const msci::point_2d& x,const msci::point_2d& y)
{
	return (x.get_x() == y.get_x() and x.get_y() == y.get_y());
}

bool operator !=(const msci::point_2d& x,const msci::point_2d& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const msci::point_2d& x)
{
	return os << x.display();
}
