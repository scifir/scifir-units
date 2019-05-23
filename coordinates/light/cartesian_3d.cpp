#include "msci/units/coordinates/light/cartesian_3d.hpp"

#include "msci/units/util/types.hpp"

#include <cmath>
#include <sstream>

#include "boost/algorithm/string.hpp"

using namespace std;

namespace msci
{
	cartesian_3d::cartesian_3d() : x(),y(),z()
	{
	}

	cartesian_3d::cartesian_3d(float new_x,float new_y,float new_z) : x(new_x),y(new_y),z(new_z)
	{
	}

	cartesian_3d::cartesian_3d(const string& init) : cartesian_3d()
	{
		vector<string> values;
		boost::split(values,init,boost::is_any_of(","));
		x = parse_float(values[0]);
		y = parse_float(values[1]);
		z = parse_float(values[2]);
	}

	string cartesian_3d::display() const
	{
		ostringstream out;
		out << "(" << x << "," << y << "," << z << ")";
		return out.str();
	}

	float coordinates_distance(const cartesian_3d& x,const cartesian_3d& y)
	{
		return sqrt(pow(x.get_x() - y.get_x(),2) + pow(x.get_y() - y.get_y(),2) + pow(x.get_z() - y.get_z(),2));
	}
}

bool operator ==(const msci::cartesian_3d& x,const msci::cartesian_3d& y)
{
	if (x.get_x() == y.get_x() and x.get_y() == y.get_y() and x.get_z() == y.get_z())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::cartesian_3d& x,const msci::cartesian_3d& y)
{
	return !(x == y);
}

bool operator ==(const msci::cartesian_3d& x,const msci::point_3d& y)
{
	if (x.get_x() == y.get_x() and x.get_y() == y.get_y() and x.get_z() == y.get_z())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::cartesian_3d& x,const msci::point_3d& y)
{
	return !(x == y);
}

bool operator ==(const msci::point_3d& x,const msci::cartesian_3d& y)
{
	if (x.get_x() == y.get_x() and x.get_y() == y.get_y() and x.get_z() == y.get_z())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::point_3d& x,const msci::cartesian_3d& y)
{
	return !(x == y);
}

ostream& operator << (ostream& os, const msci::cartesian_3d& x)
{
	return os << x.display();
}
