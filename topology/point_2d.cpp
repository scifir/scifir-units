#include "topology/point_2d.hpp"

#include "coordinates/coordinates_2d.hpp"

#include <cmath>
#include <sstream>

using namespace std;

namespace msci
{
	point_2d::point_2d() : x(),y()
	{}
	
	point_2d::point_2d(const point_2d& x_point) : x(x_point.x),y(x_point.y)
	{}
	
	point_2d::point_2d(point_2d&& x_point) : x(std::move(x_point.x)),y(std::move(x_point.y))
	{}

	point_2d::point_2d(const length& new_x,const length& new_y) : x(new_x),y(new_y)
	{}
	
	point_2d::point_2d(const length& new_p,const angle& new_theta)
	{
		set_position(new_p,new_theta);
	}

	point_2d::point_2d(const coordinates_2d& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y)
	{}
	
	point_2d::point_2d(string init_point_2d) : point_2d()
	{
		vector<string> values;
		if (init_point_2d.front() == '(')
		{
			init_point_2d.erase(0,1);
		}
		if (init_point_2d.back() == ')')
		{
			init_point_2d.erase(init_point_2d.size()-1,1);
		}
		boost::split(values,init_point_2d,boost::is_any_of(","));
		x = length(values[0]);
		y = length(values[1]);
	}
	
	point_2d& point_2d::operator=(const point_2d& x_point)
	{
		x = x_point.x;
		y = x_point.y;
		return *this;
	}
	
	point_2d& point_2d::operator=(point_2d&& x_point)
	{
		x = std::move(x_point.x);
		y = std::move(x_point.y);
		return *this;
	}
	
	point_2d& point_2d::operator=(const coordinates_2d& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		return *this;
	}
	
	void point_2d::set_position(const length& new_x,const length& new_y)
	{
		x = new_x;
		y = new_y;
	}
	
	void point_2d::set_position(const length& new_p,const angle& new_theta)
	{
		x = length(new_p * msci::cos(new_theta));
		y = length(new_p * msci::sin(new_theta));
	}

	void point_2d::rotate(const angle& x_angle)
	{
		length x_coord = x;
		length y_coord = y;
		x = x_coord * msci::cos(x_angle) - y_coord * msci::sin(x_angle);
		y = x_coord * msci::sin(x_angle) + y_coord * msci::cos(x_angle);
	}
	
	void point_2d::move(const displacement_2d& x_displacement)
	{
		x += x_displacement.x_projection();
		y += x_displacement.y_projection();
	}
	
	void point_2d::move(const length& new_x,const length& new_y)
	{
		x += new_x;
		y += new_y;
	}

	void point_2d::move(const length& new_p,const angle& new_theta)
	{
		x += new_p * msci::cos(new_theta);
		y += new_p * msci::sin(new_theta);
	}

	length point_2d::distance_to_origin() const
	{
		return msci::sqrt(msci::pow(x,2) + msci::pow(y,2));
	}

	string to_string(const point_2d& x)
	{
		ostringstream out;
		out << "(" << x.x << "," << x.y << ")";
		return out.str();
	}

	length distance(const point_2d& x1,const point_2d& x2)
	{
		return msci::sqrt(msci::pow(x1.x - x2.x,2) + msci::pow(x1.y - x2.y,2));
	}
}

bool operator ==(const msci::point_2d& x,const msci::point_2d& y)
{
	return (x.x == y.x and x.y == y.y);
}

bool operator !=(const msci::point_2d& x,const msci::point_2d& y)
{
	return !(x == y);
}

bool operator ==(const msci::point_2d& x, const string& y)
{
	point_2d y_point = point_2d(y);
	return (x == y_point);
}

bool operator !=(const msci::point_2d& x, const string& y)
{
	return !(x == y);
}

bool operator ==(const string& x, const msci::point_2d& y)
{
	point_2d x_point = point_2d(x);
	return (x_point == y);
}

bool operator !=(const string& x, const msci::point_2d& y)
{
	return !(x == y);
}

void operator +=(string& x, const msci::point_2d& y)
{
	x += to_string(y);
}

string operator +(const string& x,const msci::point_2d& y)
{
	return x + to_string(y);
}

string operator +(const msci::point_2d& x,const string& y)
{
	return to_string(x) + y;
}

ostream& operator <<(ostream& os,const msci::point_2d& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, msci::point_2d& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::point_2d c(b);
	x = c;
	return is;
}
