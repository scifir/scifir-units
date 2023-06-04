#include "coordinates/coordinates_3dr.hpp"

#include "util/types.hpp"

#include <cmath>
#include <sstream>

#include "boost/algorithm/string.hpp"

using namespace std;

namespace msci
{
	coordinates_3dr::coordinates_3dr() : x(),y(),z(),theta(),phi()
	{}

	coordinates_3dr::coordinates_3dr(const length& new_x,const length& new_y,const length& new_z,const angle& new_theta,const angle& new_phi) : x(new_x),y(new_y),z(new_z),theta(new_theta),phi(new_phi)
	{}

	coordinates_3dr::coordinates_3dr(const string& init) : coordinates_3dr()
	{
		vector<string> values;
		boost::split(values,init,boost::is_any_of(","));
		x = length(values[0]);
		y = length(values[1]);
		z = length(values[2]);
		theta = angle(values[3].size() - 1);
		phi = angle(values[4].size() - 1);
	}

	string to_string(const coordinates_3dr& x)
	{
		ostringstream out;
		out << "(" << x.x << "," << x.y << "," << x.z << "," << x.theta << "°," << x.phi << "°)";
		return out.str();
	}

	float distance(const coordinates_3dr& x,const coordinates_3dr& y)
	{
		return float(msci::sqrt(msci::pow(x.x - y.x,2) + msci::pow(x.y - y.y,2) + msci::pow(x.z - y.z,2)));
	}
}

bool operator ==(const msci::coordinates_3dr& x,const msci::coordinates_3dr& y)
{
	if (x.x == y.x and x.y == y.y and x.z == y.z and x.theta == y.theta and x.phi == y.phi)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::coordinates_3dr& x,const msci::coordinates_3dr& y)
{
	return !(x == y);
}

bool operator ==(const msci::coordinates_3dr& x,const msci::coordinates_3d& y)
{
	if (x.x == y.x and x.y == y.y and x.z == y.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::coordinates_3dr& x,const msci::coordinates_3d& y)
{
	return !(x == y);
}

bool operator ==(const msci::coordinates_3d& x,const msci::coordinates_3dr& y)
{
	if (x.x == y.x and x.y == y.y and x.z == y.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::coordinates_3d& x,const msci::coordinates_3dr& y)
{
	return !(x == y);
}

bool operator ==(const msci::coordinates_3dr& x,const msci::point_3d& y)
{
	if (x.x == y.x and x.y == y.y and x.z == y.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::coordinates_3dr& x,const msci::point_3d& y)
{
	return !(x == y);
}

bool operator ==(const msci::point_3d& x,const msci::coordinates_3dr& y)
{
	if (x.x == y.x and x.y == y.y and x.z == y.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::point_3d& x,const msci::coordinates_3dr& y)
{
	return !(x == y);
}

ostream& operator << (ostream& os, const msci::coordinates_3dr& x)
{
	return os << to_string(x);
}
