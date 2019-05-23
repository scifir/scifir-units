#include "msci/units/coordinates/light/cartesian_2d.hpp"

#include "msci/units/util/types.hpp"

#include <cmath>
#include <sstream>

#include "boost/algorithm/string.hpp"

using namespace std;

namespace msci
{
	cartesian_2d::cartesian_2d() : x(),y()
	{
	}

	cartesian_2d::cartesian_2d(float new_x,float new_y) : x(new_x),y(new_y)
	{
	}

	cartesian_2d::cartesian_2d(const string& init) : cartesian_2d()
	{
		vector<string> values;
		boost::split(values,init,boost::is_any_of(","));
		x = parse_float(values[0]);
		y = parse_float(values[1]);
	}

	string cartesian_2d::display() const
	{
		ostringstream out;
		out << "(" << x << "," << y << ")";
		return out.str();
	}

	float coordinates_distance(const cartesian_2d& x,const cartesian_2d& y)
	{
		return sqrt(pow(x.get_x() - y.get_x(),2) + pow(x.get_y() - y.get_y(),2));
	}
}

bool operator ==(const msci::cartesian_2d& x,const msci::cartesian_2d& y)
{
	if (x.get_x() == y.get_x() and x.get_y() == y.get_y())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::cartesian_2d& x,const msci::cartesian_2d& y)
{
	return !(x == y);
}

bool operator ==(const msci::cartesian_2d& x,const msci::point_2d& y)
{
	if (x.get_x() == y.get_x() and x.get_y() == y.get_y())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::cartesian_2d& x,const msci::point_2d& y)
{
	return !(x == y);
}

bool operator ==(const msci::point_2d& x,const msci::cartesian_2d& y)
{
	if (x.get_x() == y.get_x() and x.get_y() == y.get_y())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::point_2d& x,const msci::cartesian_2d& y)
{
	return !(x == y);
}

ostream& operator << (ostream& os, const msci::cartesian_2d& x)
{
	return os << x.display();
}
