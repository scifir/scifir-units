#include "msci/units/topology/point_2d.hpp"

#include <cmath>
#include <sstream>

using namespace std;

namespace msci
{
	point_2d::point_2d() : x(),y()
	{
	}

	point_2d::point_2d(space_type new_x,space_type new_y) : x(new_x),y(new_y)
	{
	}

	space_type point_2d::distance_to_origin() const
	{
		return sqrt(pow(x,2) + pow(y,2));
	}

	string point_2d::display() const
	{
		ostringstream out;
		out << "(" << x << "," << y << ")";
		return out.str().c_str();
	}

	void point_2d::print() const
	{
		cout << display() << endl;
	}

	space_type distance_between_points(const point_2d& x1,const point_2d& x2)
	{
		return sqrt(pow(x1.get_x() - x2.get_x(),2) + pow(x1.get_y() - x2.get_y(),2));
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
