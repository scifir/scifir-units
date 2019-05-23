#include "msci/units/coordinates/light/cartesian_2dr.hpp"

#include "msci/units/util/types.hpp"

#include <cmath>
#include <sstream>

#include "boost/algorithm/string.hpp"

using namespace std;

namespace msci
{
	cartesian_2dr::cartesian_2dr() : x(),y(),angle()
	{
	}

	cartesian_2dr::cartesian_2dr(float new_x,float new_y,float new_angle) : x(new_x),y(new_y),angle(new_angle)
	{
	}

	cartesian_2dr::cartesian_2dr(const string& init) : cartesian_2dr()
	{
		vector<string> values;
		boost::split(values,init,boost::is_any_of(","));
		x = parse_float(values[0]);
		y = parse_float(values[1]);
		angle = angle_number(values[2].size() - 1);
	}

	string cartesian_2dr::display() const
	{
		ostringstream out;
		out << "(" << x << "," << y << "," << angle << "°)";
		return out.str();
	}

	float coordinates_distance(const cartesian_2dr& x,const cartesian_2dr& y)
	{
		return sqrt(pow(x.get_x() - y.get_x(),2) + pow(x.get_y() - y.get_y(),2));
	}
}

bool operator ==(const msci::cartesian_2dr& x,const msci::cartesian_2dr& y)
{
	if (x.get_x() == y.get_x() and x.get_y() == y.get_y() and x.get_angle() == y.get_angle())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::cartesian_2dr& x,const msci::cartesian_2dr& y)
{
	return !(x == y);
}

bool operator ==(const msci::cartesian_2dr& x,const msci::cartesian_2d& y)
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

bool operator !=(const msci::cartesian_2dr& x,const msci::cartesian_2d& y)
{
	return !(x == y);
}

bool operator ==(const msci::cartesian_2d& x,const msci::cartesian_2dr& y)
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

bool operator !=(const msci::cartesian_2d& x,const msci::cartesian_2dr& y)
{
	return !(x == y);
}

bool operator ==(const msci::cartesian_2dr& x,const msci::point_2d& y)
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

bool operator !=(const msci::cartesian_2dr& x,const msci::point_2d& y)
{
	return !(x == y);
}

bool operator ==(const msci::point_2d& x,const msci::cartesian_2dr& y)
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

bool operator !=(const msci::point_2d& x,const msci::cartesian_2dr& y)
{
	return !(x == y);
}

ostream& operator << (ostream& os, const msci::cartesian_2dr& x)
{
	return os << x.display();
}
