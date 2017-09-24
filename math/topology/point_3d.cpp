#include "point_3d.hpp"

#include <cmath>
#include <sstream>

using namespace std;

namespace math
{
	point_3d::point_3d() : x(),y(),z()
	{
	}

	point_3d::point_3d(space_type new_x,space_type new_y,space_type new_z) : x(new_x),y(new_y),z(new_z)
	{
	}

	space_type point_3d::distance_to_origin() const
	{
		return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	}

	wstring point_3d::display() const
	{
		wostringstream out;
		out << "(" << x << "," << y << "," << z << ")";
		return out.str().c_str();
	}

	void point_3d::print() const
	{
		wcout << display() << endl;
	}

	space_type distance(const point_3d& x1,const point_3d& x2)
	{
		return sqrt(pow(x1.get_x() - x2.get_x(),2) + pow(x1.get_y() - x2.get_y(),2) + pow(x1.get_z() - x2.get_z(),2));
	}
}

bool operator ==(const math::point_3d& x,const math::point_3d& y)
{
	return (x.get_x() == y.get_x() and x.get_y() == y.get_y() and x.get_z() == y.get_z());
}

bool operator !=(const math::point_3d& x,const math::point_3d& y)
{
	return !(x == y);
}

wostream& operator <<(wostream& os,const math::point_3d& x)
{
	return os << x.display();
}
