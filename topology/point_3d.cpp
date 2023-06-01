#include "topology/point_3d.hpp"

#include <cmath>
#include <sstream>

using namespace std;

namespace msci
{
	point_3d::point_3d() : x(),y(),z()
	{
	}

	point_3d::point_3d(const length& new_x,const length& new_y,const length& new_z) : x(new_x),y(new_y),z(new_z)
	{
	}

	length point_3d::distance_to_origin() const
	{
		return msci::sqrt(msci::pow(x,2) + msci::pow(y,2) + msci::pow(z,2));
	}

	string to_string(const point_3d& x)
	{
		ostringstream out;
		out << "(" << x.x << "," << x.y << "," << x.z << ")";
		return out.str();
	}

	length distance(const point_3d& x1,const point_3d& x2)
	{
		return msci::sqrt(msci::pow(x1.x - x2.x,2) + msci::pow(x1.y - x2.y,2) + msci::pow(x1.z - x2.z,2));
	}
}

bool operator ==(const msci::point_3d& x,const msci::point_3d& y)
{
	return (x.x == y.x and x.y == y.y and x.z == y.z);
}

bool operator !=(const msci::point_3d& x,const msci::point_3d& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const msci::point_3d& x)
{
	return os << to_string(x);
}
