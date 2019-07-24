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

	cartesian_2d::cartesian_2d(const length& new_x,const length& new_y) : x(new_x),y(new_y)
	{
	}

	cartesian_2d::cartesian_2d(const point_2d& x_point) : x(x_point.get_x()),y(x_point.get_y())
	{
	}

	cartesian_2d::cartesian_2d(const string& init) : cartesian_2d()
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

	void cartesian_2d::operator= (const point_2d& x_point)
	{
		x = x_point.get_x();
		y = x_point.get_y();
	}

	length cartesian_2d::get_p() const
	{
		return length("1 m");
		//return length(sqrt(x ^ 2 + y ^ 2));
	}

	angle cartesian_2d::get_angle() const
	{
		return angle(atan2(y.get_value().get_value(),x.get_value().get_value()));
	}

	void cartesian_2d::set_x(const length& x_length)
	{
		x = x_length;
	}

	void cartesian_2d::set_y(const length& y_length)
	{
		y = y_length;
	}

	void cartesian_2d::move_angle(const angle& x_angle)
	{
		x = x*cos(x_angle);
		y = y*sin(x_angle);
	}

	void cartesian_2d::move_in_direction(const length& x_value,const angle& x_angle)
	{
		x = x + x_value*cos(x_angle);
		y = y + x_value*sin(x_angle);
	}

	string cartesian_2d::display() const
	{
		ostringstream out;
		out << "(" << x << "," << y << ")";
		return out.str();
	}

	float coordinates_distance(const cartesian_2d& x,const cartesian_2d& y)
	{
		return sqrt(pow(x.get_x().get_value().get_value() - y.get_x().get_value().get_value(),2) + pow(x.get_y().get_value().get_value() - y.get_y().get_value().get_value(),2));
	}
}

string operator +(const string& x,const msci::cartesian_2d& y)
{
	return x + y.display();
}

string operator +(const msci::cartesian_2d& x,const string& y)
{
	return x.display() + y;
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
