#include "coordinates/coordinates_2dr.hpp"

#include "util/types.hpp"

#include <cmath>
#include <sstream>

#include "boost/algorithm/string.hpp"

using namespace std;

namespace msci
{
	coordinates_2dr::coordinates_2dr() : x(),y(),theta()
	{}

	coordinates_2dr::coordinates_2dr(const length& new_x,const length& new_y,const angle& new_angle) : x(new_x),y(new_y),theta(angle(new_angle))
	{}

	coordinates_2dr::coordinates_2dr(const string& init) : coordinates_2dr()
	{
		vector<string> values;
		boost::split(values,init,boost::is_any_of(","));
		if (values.size() == 3)
		{
			x = length(values[0]);
			y = length(values[1]);
			theta = angle(values[2]);
		}
	}

	string to_string(const coordinates_2dr& x)
	{
		ostringstream out;
		out << "(" << x.x << "," << x.y << "," << x.theta << "°)";
		return out.str();
	}

	length distance(const coordinates_2dr& x,const coordinates_2dr& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2) + msci::pow(x.y - y.y,2));
	}
}

bool operator ==(const msci::coordinates_2dr& x,const msci::coordinates_2dr& y)
{
	if (x.x == y.x and x.y == y.y and x.theta == y.theta)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::coordinates_2dr& x,const msci::coordinates_2dr& y)
{
	return !(x == y);
}

ostream& operator << (ostream& os, const msci::coordinates_2dr& x)
{
	return os << to_string(x);
}
