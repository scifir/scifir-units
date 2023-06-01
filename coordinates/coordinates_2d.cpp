#include "coordinates/coordinates_2d.hpp"

#include "util/types.hpp"

#include <cmath>
#include <sstream>

#include "boost/algorithm/string.hpp"

using namespace std;

namespace msci
{
	coordinates_2d::coordinates_2d() : x(),y()
	{}

	coordinates_2d::coordinates_2d(const length& new_x,const length& new_y) : x(new_x),y(new_y)
	{}

	coordinates_2d::coordinates_2d(const msci::point_2d& new_point) : x(new_point.x),y(new_point.y)
	{}

	coordinates_2d::coordinates_2d(const string& init) : coordinates_2d()
	{
		vector<string> values;
		if (init[0] == '(' and init[init.length() - 1] == ')')
		{
			string init2 = init.substr(1,init.length() - 2);
			boost::split(values,init2,boost::is_any_of(","));
			x = length(values[0]);
			y = length(values[1]);
		}
	}

	void coordinates_2d::operator= (const point_2d& x_point)
	{
		x = x_point.x;
		y = x_point.y;
	}

	length coordinates_2d::get_p() const
	{
		return msci::sqrt(msci::pow(x,2) + msci::pow(y,2));
	}

	angle coordinates_2d::get_angle() const
	{
		return angle(std::atan2(y.get_value(),x.get_value()));
	}

	void coordinates_2d::move_angle(const angle& x_angle)
	{
		x = x * msci::cos(x_angle);
		y = y * msci::sin(x_angle);
	}

	void coordinates_2d::move_in_direction(const length& x_value,const angle& x_angle)
	{
		x = x + x_value * msci::cos(x_angle);
		y = y + x_value * msci::sin(x_angle);
	}

	string to_string(const coordinates_2d& x)
	{
		ostringstream out;
		out << "(" << x.x << "," << x.y << ")";
		return out.str();
	}

	length distance(const coordinates_2d& x,const coordinates_2d& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2) + msci::pow(x.y - y.y,2));
	}
}

string operator +(const string& x,const msci::coordinates_2d& y)
{
	return x + to_string(y);
}

string operator +(const msci::coordinates_2d& x,const string& y)
{
	return to_string(x) + y;
}

bool operator ==(const msci::coordinates_2d& x,const msci::coordinates_2d& y)
{
	if (x.x == y.x and x.y == y.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::coordinates_2d& x,const msci::coordinates_2d& y)
{
	return !(x == y);
}

bool operator ==(const msci::coordinates_2d& x,const msci::point_2d& y)
{
	if (x.x == y.x and x.y == y.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::coordinates_2d& x,const msci::point_2d& y)
{
	return !(x == y);
}

bool operator ==(const msci::point_2d& x,const msci::coordinates_2d& y)
{
	if (x.x == y.x and x.y == y.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::point_2d& x,const msci::coordinates_2d& y)
{
	return !(x == y);
}

ostream& operator << (ostream& os, const msci::coordinates_2d& x)
{
	return os << to_string(x);
}
