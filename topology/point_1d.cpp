#include "topology/point_1d.hpp"

#include "coordinates/coordinates_1d.hpp"

#include <cmath>
#include <sstream>

using namespace std;

namespace msci
{
	point_1d::point_1d() : x()
	{}
	
	point_1d::point_1d(const point_1d& x_point) : x(x_point.x)
	{}
	
	point_1d::point_1d(point_1d&& x_point) : x(move(x_point.x))
	{}

	point_1d::point_1d(const length& new_x) : x(new_x)
	{}

	point_1d::point_1d(const coordinates_1d& x_coordinates) : x(x_coordinates.x)
	{}
	
	point_1d::point_1d(string init_point_1d) : point_1d()
	{
		if (init_point_1d.front() == '(')
		{
			init_point_1d.erase(0,1);
		}
		if (init_point_1d.back() == ')')
		{
			init_point_1d.erase(init_point_1d.size()-1,1);
		}
		x = length(init_point_1d);
	}
	
	point_1d& point_1d::operator=(const point_1d& x_point)
	{
		x = x_point.x;
		return *this;
	}
	
	point_1d& point_1d::operator=(point_1d&& x_point)
	{
		x = move(x_point.x);
		return *this;
	}
	
	point_1d& point_1d::operator=(const coordinates_1d& x_coordinates)
	{
		x = x_coordinates.x;
		return *this;
	}
	
	void point_1d::set_position(const length& new_x)
	{
		x = new_x;
	}

	void point_1d::move_in_direction(const length& x_value)
	{
		x += x_value;
	}

	length point_1d::distance_to_origin() const
	{
		return length(std::abs(x.get_value()),x.get_dimensions());
	}

	string to_string(const point_1d& x)
	{
		ostringstream out;
		out << "(" << x.x << ")";
		return out.str();
	}

	length distance(const point_1d& x1,const point_1d& x2)
	{
		return msci::sqrt(msci::pow(x1.x - x2.x,2));
	}
}

bool operator ==(const msci::point_1d& x,const msci::point_1d& y)
{
	return (x.x == y.x);
}

bool operator !=(const msci::point_1d& x,const msci::point_1d& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const msci::point_1d& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, msci::point_1d& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::point_1d c(b);
	x = c;
	return is;
} 
