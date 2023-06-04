#include "coordinates/coordinates_2d.hpp"

#include <cmath>
#include <sstream>

#include "boost/algorithm/string.hpp"

using namespace std;

namespace msci
{
	coordinates_2d::coordinates_2d() : x(),y()
	{}
	
	coordinates_2d::coordinates_2d(const coordinates_2d& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y)
	{}

	coordinates_2d::coordinates_2d(coordinates_2d&& x_coordinates) : x(move(x_coordinates.x)),y(move(x_coordinates.y))
	{}

	coordinates_2d::coordinates_2d(const length& new_x,const length& new_y) : x(new_x),y(new_y)
	{}
	
	coordinates_2d::coordinates_2d(const length& new_p,const msci::angle& new_theta)
	{
		set_position(new_p,new_theta);
	}

	coordinates_2d::coordinates_2d(const msci::point_2d& new_point) : x(new_point.x),y(new_point.y)
	{}

	coordinates_2d::coordinates_2d(string init_coordinates_2d) : coordinates_2d()
	{
		vector<string> values;
		if (init_coordinates_2d.front() == '(')
		{
			init_coordinates_2d.erase(0,1);
		}
		if (init_coordinates_2d.back() == ')')
		{
			init_coordinates_2d.erase(init_coordinates_2d.size()-1,1);
		}
		boost::split(values,init_coordinates_2d,boost::is_any_of(","));
		x = length(values[0]);
		y = length(values[1]);
	}
	
	coordinates_2d& coordinates_2d::operator=(const coordinates_2d& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		return *this;
	}
	
	coordinates_2d& coordinates_2d::operator=(coordinates_2d&& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		return *this;
	}

	coordinates_2d& coordinates_2d::operator=(const point_2d& x_point)
	{
		x = x_point.x;
		y = x_point.y;
		return *this;
	}

	length coordinates_2d::get_p() const
	{
		return msci::sqrt(msci::pow(x,2) + msci::pow(y,2));
	}

	angle coordinates_2d::get_angle() const
	{
		return angle(std::atan2(y.get_value(),x.get_value()));
	}
	
	void coordinates_2d::set_position(const length& new_x,const length& new_y)
	{
		x = new_x;
		y = new_y;
	}
	
	void coordinates_2d::set_position(const length& new_p,const angle& new_theta)
	{
		x = length(float(new_p * msci::cos(new_theta)),new_p.get_dimensions());
		y = length(float(new_p * msci::sin(new_theta)),new_p.get_dimensions());
	}

	void coordinates_2d::rotate(const angle& x_angle)
	{
		length x_coord = x;
		length y_coord = y;
		x = x_coord * msci::cos(x_angle) - y_coord * msci::sin(x_angle);
		y = x_coord * msci::sin(x_angle) + y_coord * msci::cos(x_angle);
	}
	
	void coordinates_2d::move_in_direction(const displacement_2d& x_displacement)
	{
		x += x_displacement.x_projection();
		y += x_displacement.y_projection();
	}

	void coordinates_2d::move_in_direction(const length& x_value,const angle& x_angle)
	{
		x = x + x_value * msci::cos(x_angle);
		y = y + x_value * msci::sin(x_angle);
	}
	
	void coordinates_2d::move_in_direction(const length& x_value,float x_angle)
	{
		move_in_direction(x_value,angle(x_angle));
	}
	
	length coordinates_2d::distance_to_origin() const
	{
		return msci::sqrt(msci::pow(x,2) + msci::pow(y,2));
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
	
	length distance(const coordinates_2d& x,const point_2d& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2) + msci::pow(x.y - y.y,2));
	}
	
	length distance(const point_2d& x,const coordinates_2d& y)
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

ostream& operator << (ostream& os,const msci::coordinates_2d& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is,msci::coordinates_2d& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::coordinates_2d c(b);
	x = c;
	return is;
}
