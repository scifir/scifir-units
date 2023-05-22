#include "msci/units/coordinates/light/cartesian_3dr.hpp"

#include "msci/units/util/types.hpp"

#include <cmath>
#include <sstream>

#include "boost/algorithm/string.hpp"

using namespace std;

namespace msci
{
	cartesian_3dr::cartesian_3dr() : x(),y(),z(),angle(),angle2()
	{
	}

	cartesian_3dr::cartesian_3dr(float new_x,float new_y,float new_z,float new_angle,float new_angle2) : x(new_x),y(new_y),z(new_z),angle(new_angle),angle2(new_angle2)
	{
	}

	cartesian_3dr::cartesian_3dr(const string& init) : cartesian_3dr()
	{
		vector<string> values;
		boost::split(values,init,boost::is_any_of(","));
		x = parse_float(values[0]);
		y = parse_float(values[1]);
		z = parse_float(values[2]);
		angle = msci::angle(values[3].size() - 1);
		angle2 = msci::angle(values[4].size() - 1);
	}

	string cartesian_3dr::display() const
	{
		ostringstream out;
		out << "(" << x << "," << y << "," << z << "," << angle << "°," << angle2 << "°)";
		return out.str();
	}

	float coordinates_distance(const cartesian_3dr& x,const cartesian_3dr& y)
	{
		return std::sqrt(std::pow(x.get_x() - y.get_x(),2) + std::pow(x.get_y() - y.get_y(),2) + std::pow(x.get_z() - y.get_z(),2));
	}
}

bool operator ==(const msci::cartesian_3dr& x,const msci::cartesian_3dr& y)
{
	if (x.get_x() == y.get_x() and x.get_y() == y.get_y() and x.get_z() == y.get_z() and x.get_angle() == y.get_angle() and x.get_angle2() == y.get_angle2())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::cartesian_3dr& x,const msci::cartesian_3dr& y)
{
	return !(x == y);
}

bool operator ==(const msci::cartesian_3dr& x,const msci::cartesian_3d& y)
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

bool operator !=(const msci::cartesian_3dr& x,const msci::cartesian_3d& y)
{
	return !(x == y);
}

bool operator ==(const msci::cartesian_3d& x,const msci::cartesian_3dr& y)
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

bool operator !=(const msci::cartesian_3d& x,const msci::cartesian_3dr& y)
{
	return !(x == y);
}

bool operator ==(const msci::cartesian_3dr& x,const msci::point_3d& y)
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

bool operator !=(const msci::cartesian_3dr& x,const msci::point_3d& y)
{
	return !(x == y);
}

bool operator ==(const msci::point_3d& x,const msci::cartesian_3dr& y)
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

bool operator !=(const msci::point_3d& x,const msci::cartesian_3dr& y)
{
	return !(x == y);
}

ostream& operator << (ostream& os, const msci::cartesian_3dr& x)
{
	return os << x.display();
}
