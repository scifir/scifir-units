#include "topology/point_2d.hpp"

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
		return msci::sqrt(msci::pow(x,2) + msci::pow(y,2));
	}

	string to_string(const point_2d& x)
	{
		ostringstream out;
		out << "(" << x.x << "," << x.y << ")";
		return out.str();
	}

	length distance(const point_2d& x1,const point_2d& x2)
	{
		return msci::sqrt(msci::pow(x1.x - x2.x,2) + msci::pow(x1.y - x2.y,2));
	}
}

bool operator ==(const msci::point_2d& x,const msci::point_2d& y)
{
	return (x.x == y.x and x.y == y.y);
}

bool operator !=(const msci::point_2d& x,const msci::point_2d& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const msci::point_2d& x)
{
	return os << to_string(x);
}
