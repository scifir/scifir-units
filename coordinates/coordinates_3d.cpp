#include "coordinates/coordinates_3d.hpp"

#include "util/types.hpp"

#include <sstream>
#include <vector>

#include "boost/algorithm/string.hpp"

using namespace std;

namespace msci
{
	coordinates_3d::coordinates_3d() : x(),y(),z()
	{}
	
	coordinates_3d::coordinates_3d(const coordinates_3d& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z)
	{}
	
	coordinates_3d::coordinates_3d(coordinates_3d&& x_coordinates) : x(move(x_coordinates.x)),y(move(x_coordinates.y)),z(move(x_coordinates.z))
	{}
	
	coordinates_3d::coordinates_3d(const length& new_x,const length& new_y,const length& new_z) : x(new_x),y(new_y),z(new_z)
	{}
	
	coordinates_3d::coordinates_3d(const length& new_p,const msci::angle& new_theta,length new_z)
	{
		set_position(new_p,new_theta,new_z);
	}
	
	coordinates_3d::coordinates_3d(const length& new_r,const msci::angle& new_theta,const msci::angle& new_phi)
	{
		set_position(new_r,new_theta,new_phi);
	}
	
	coordinates_3d::coordinates_3d(const msci::angle& new_latitude,const msci::angle& new_longitude,const length& new_altitude)
	{
		set_position(new_latitude,new_longitude,new_altitude);
	}
	
	coordinates_3d::coordinates_3d(const point_3d& x_point) : x(x_point.x),y(x_point.y),z(x_point.z)
	{}

	coordinates_3d::coordinates_3d(string init_coordinates_3d) : coordinates_3d()
	{
		vector<string> values;
		if (init_coordinates_3d.front() == '(')
		{
			init_coordinates_3d.erase(0,1);
		}
		if (init_coordinates_3d.back() == ')')
		{
			init_coordinates_3d.erase(init_coordinates_3d.size()-1,1);
		}
		boost::split(values,init_coordinates_3d,boost::is_any_of(","));
		x = length(values[0]);
		y = length(values[1]);
		z = length(values[2]);
	}
	
	coordinates_3d& coordinates_3d::operator=(const coordinates_3d& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		z = x_coordinates.z;
		return *this;
	}
	
	coordinates_3d& coordinates_3d::operator=(coordinates_3d&& x_coordinates)
	{
		x = move(x_coordinates.x);
		y = move(x_coordinates.y);
		z = move(x_coordinates.z);
		return *this;
	}
	
	coordinates_3d& coordinates_3d::operator=(const point_3d& x_point)
	{
		x = x_point.x;
		y = x_point.y;
		z = x_point.z;
		return *this;
	}
	
	length coordinates_3d::get_p() const
	{
		return msci::sqrt(msci::pow(x,2) + msci::pow(y,2));
	}

	angle coordinates_3d::get_theta() const
	{
		return msci::angle(msci::atan_grade(float(y/x)));
	}

	length coordinates_3d::get_r() const
	{
		return msci::sqrt(msci::pow(x,2) + msci::pow(y,2) + msci::pow(z,2));
	}

	angle coordinates_3d::get_phi() const
	{
		return msci::angle(msci::acos_grade(float(z/msci::sqrt(msci::pow(x,2) + msci::pow(y,2) + msci::pow(z,2)))));
	}
	
	void coordinates_3d::set_position(const length& new_x,const length& new_y,const length& new_z)
	{
		x = new_x;
		y = new_y;
		z = new_z;
	}
	
	void coordinates_3d::set_position(const length& new_p,const msci::angle& new_theta,length new_z)
	{
		new_z.set_same_prefix(new_p);
		x = length(new_p * msci::cos(new_theta));
		y = length(new_p * msci::sin(new_theta));
		z = new_z;
	}
	
	void coordinates_3d::set_position(const length& new_r,const msci::angle& new_theta,const msci::angle& new_phi)
	{
		x = length(new_r * msci::cos(new_theta) * msci::sin(new_phi));
		y = length(new_r * msci::sin(new_theta) * msci::sin(new_phi));
		z = length(new_r * msci::cos(new_phi));
	}
	
	void coordinates_3d::set_position(const msci::angle& new_latitude,const msci::angle& new_longitude,const length& new_altitude)
	{
		x = length(new_altitude * msci::cos(new_latitude) * msci::cos(new_longitude));
		y = length(new_altitude * msci::cos(new_latitude) * msci::sin(new_longitude));
		z = length(new_altitude * msci::sin(new_latitude));
	}
	
	void coordinates_3d::rotate_in_x(const angle& x_angle)
	{
		length y_coord = y;
		length z_coord = z;
		y = y_coord * msci::cos(x_angle) - z_coord * msci::sin(x_angle);
		z = y_coord * msci::sin(x_angle) + z_coord * msci::cos(x_angle);
	}
	
	void coordinates_3d::rotate_in_y(const angle& x_angle)
	{
		length x_coord = x;
		length z_coord = z;
		x = x_coord * msci::cos(x_angle) - z_coord * msci::sin(x_angle);
		z = x_coord * msci::sin(x_angle) + z_coord * msci::cos(x_angle);
	}
	
	void coordinates_3d::rotate_in_z(const angle& x_angle)
	{
		length x_coord = x;
		length y_coord = y;
		x = x_coord * msci::cos(x_angle) - y_coord * msci::sin(x_angle);
		y = x_coord * msci::sin(x_angle) + y_coord * msci::cos(x_angle);
	}
	
	void coordinates_3d::move_in_direction(const displacement_3d& x_displacement)
	{
		x += x_displacement.x_projection();
		y += x_displacement.y_projection();
		z += x_displacement.z_projection();
	}
	
	void coordinates_3d::move_in_direction(const length& x_length,const msci::angle& x_theta,const msci::angle& x_phi)
	{
		displacement_3d x_displacement = displacement_3d(x_length,x_theta,x_phi);
		move_in_direction(x_displacement);
	}
	
	void coordinates_3d::move_in_direction(const length& x_length,float x_theta,float x_phi)
	{
		displacement_3d x_displacement = displacement_3d(x_length,x_theta,x_phi);
		move_in_direction(x_displacement);
	}
	
	length coordinates_3d::distance_to_origin() const
	{
		return msci::sqrt(msci::pow(x,2) + msci::pow(y,2) + msci::pow(z,2));
	}
	
	string to_string(const coordinates_3d& x)
	{
		ostringstream out;
		out << "(" << x.x << "," << x.y << "," << x.z << ")";
		return out.str();
	}

	length distance(const coordinates_3d& x,const coordinates_3d& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2) + msci::pow(x.y - y.y,2) + msci::pow(x.z - y.z,2));
	}
	
	length distance(const coordinates_3d& x,const point_3d& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2) + msci::pow(x.y - y.y,2) + msci::pow(x.z - y.z,2));
	}
	
	length distance(const point_3d& x,const coordinates_3d& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2) + msci::pow(x.y - y.y,2) + msci::pow(x.z - y.z,2));
	}
}

bool operator ==(const msci::coordinates_3d& x,const msci::coordinates_3d& y)
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

bool operator !=(const msci::coordinates_3d& x,const msci::coordinates_3d& y)
{
	return !(x == y);
}

bool operator ==(const msci::coordinates_3d& x,const msci::point_3d& y)
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

bool operator !=(const msci::coordinates_3d& x,const msci::point_3d& y)
{
	return !(x == y);
}

bool operator ==(const msci::point_3d& x,const msci::coordinates_3d& y)
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

bool operator !=(const msci::point_3d& x,const msci::coordinates_3d& y)
{
	return !(x == y);
}

ostream& operator << (ostream& os, const msci::coordinates_3d& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, msci::coordinates_3d& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::coordinates_3d c(b);
	x = c;
	return is;
}
