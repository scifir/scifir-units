#include "coordinates/coordinates_1d.hpp"

#include <cmath>
#include <sstream>

#include "boost/algorithm/string.hpp"

using namespace std;

namespace msci
{
	coordinates_1d::coordinates_1d() : x()
	{}
	
	coordinates_1d::coordinates_1d(const coordinates_1d& x_coordinates) : x(x_coordinates.x)
	{}

	coordinates_1d::coordinates_1d(coordinates_1d&& x_coordinates) : x(move(x_coordinates.x))
	{}

	coordinates_1d::coordinates_1d(const length& new_x) : x(new_x)
	{}

	coordinates_1d::coordinates_1d(const point_1d& new_point) : x(new_point.x)
	{}

	coordinates_1d::coordinates_1d(string init_coordinates_1d) : coordinates_1d()
	{
		if (init_coordinates_1d.front() == '(')
		{
			init_coordinates_1d.erase(0,1);
		}
		if (init_coordinates_1d.back() == ')')
		{
			init_coordinates_1d.erase(init_coordinates_1d.size()-1,1);
		}
		x = length(init_coordinates_1d);
	}
	
	coordinates_1d& coordinates_1d::operator=(const coordinates_1d& x_coordinates)
	{
		x = x_coordinates.x;
		return *this;
	}
	
	coordinates_1d& coordinates_1d::operator=(coordinates_1d&& x_coordinates)
	{
		x = x_coordinates.x;
		return *this;
	}

	coordinates_1d& coordinates_1d::operator=(const point_1d& x_point)
	{
		x = x_point.x;
		return *this;
	}

	
	void coordinates_1d::set_position(const length& new_x)
	{
		x = new_x;
	}

	void coordinates_1d::move_in_direction(const length& x_value)
	{
		x += x_value;
	}
	
	length coordinates_1d::distance_to_origin() const
	{
		return length(std::abs(x.get_value()),x.get_dimensions());
	}

	string to_string(const coordinates_1d& x)
	{
		ostringstream out;
		out << "(" << x.x <<  ")";
		return out.str();
	}

	length distance(const coordinates_1d& x,const coordinates_1d& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2));
	}
	
	length distance(const coordinates_1d& x,const point_1d& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2));
	}
	
	length distance(const point_1d& x,const coordinates_1d& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2));
	}
}

string operator +(const string& x,const msci::coordinates_1d& y)
{
	return x + to_string(y);
}

string operator +(const msci::coordinates_1d& x,const string& y)
{
	return to_string(x) + y;
}

bool operator ==(const msci::coordinates_1d& x,const msci::coordinates_1d& y)
{
	if (x.x == y.x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::coordinates_1d& x,const msci::coordinates_1d& y)
{
	return !(x == y);
}

bool operator ==(const msci::coordinates_1d& x,const msci::point_1d& y)
{
	if (x.x == y.x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::coordinates_1d& x,const msci::point_1d& y)
{
	return !(x == y);
}

bool operator ==(const msci::point_1d& x,const msci::coordinates_1d& y)
{
	if (x.x == y.x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::point_1d& x,const msci::coordinates_1d& y)
{
	return !(x == y);
}

ostream& operator << (ostream& os,const msci::coordinates_1d& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is,msci::coordinates_1d& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::coordinates_1d c(b);
	x = c;
	return is;
}
