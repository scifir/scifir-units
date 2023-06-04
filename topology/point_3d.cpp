#include "topology/point_3d.hpp"

#include "coordinates/coordinates_3d.hpp"

#include <cmath>
#include <sstream>
#include <vector>

using namespace std;

namespace msci
{
	point_3d::point_3d() : x(),y(),z()
	{}
	
	point_3d::point_3d(const point_3d& x_point) : x(x_point.x),y(x_point.y),z(x_point.z)
	{}
	
	point_3d::point_3d(point_3d&& x_point) : x(std::move(x_point.x)),y(std::move(x_point.y)),z(std::move(x_point.z))
	{}

	point_3d::point_3d(const length& new_x,const length& new_y,const length& new_z) : x(new_x),y(new_y),z(new_z)
	{}
	
	point_3d::point_3d(const length& new_p,const angle& new_theta,length new_z)
	{
		set_position(new_p,new_theta,new_z);
	}
	
	point_3d::point_3d(const length& new_r,const angle& new_theta,const angle& new_phi)
	{
		set_position(new_r,new_theta,new_phi);
	}
	
	point_3d::point_3d(const angle& new_latitude,const angle& new_longitude,const length& new_altitude)
	{
		set_position(new_latitude,new_longitude,new_altitude);
	}
	
	point_3d::point_3d(const coordinates_3d& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z)
	{}
	
	point_3d::point_3d(string init_point_3d) : point_3d()
	{
		vector<string> values;
		if (init_point_3d.front() == '(')
		{
			init_point_3d.erase(0,1);
		}
		if (init_point_3d.back() == ')')
		{
			init_point_3d.erase(init_point_3d.size()-1,1);
		}
		boost::split(values,init_point_3d,boost::is_any_of(","));
		x = length(values[0]);
		y = length(values[1]);
		z = length(values[2]);
	}
	
	point_3d& point_3d::operator=(const point_3d& x_point)
	{
		x = x_point.x;
		y = x_point.y;
		z = x_point.z;
		return *this;
	}
	
	point_3d& point_3d::operator=(point_3d&& x_point)
	{
		x = std::move(x_point.x);
		y = std::move(x_point.y);
		z = std::move(x_point.z);
		return *this;
	}
	
	point_3d& point_3d::operator=(const coordinates_3d& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		z = x_coordinates.z;
		return *this;
	}
	
	void point_3d::set_position(const length& new_x,const length& new_y,const length& new_z)
	{
		x = new_x;
		y = new_y;
		z = new_z;
	}
	
	void point_3d::set_position(const length& new_p,const angle& new_theta,length new_z)
	{
		new_z.set_same_prefix(new_p);
		x = length(new_p * msci::cos(new_theta));
		y = length(new_p * msci::sin(new_theta));
		z = new_z;
	}
	
	void point_3d::set_position(const length& new_r,const angle& new_theta,const angle& new_phi)
	{
		x = length(new_r * msci::cos(new_theta) * msci::sin(new_phi));
		y = length(new_r * msci::sin(new_theta) * msci::sin(new_phi));
		z = length(new_r * msci::cos(new_phi));
	}
	
	void point_3d::set_position(const angle& new_latitude,const angle& new_longitude,const length& new_altitude)
	{
		x = length(new_altitude * msci::cos(new_latitude) * msci::cos(new_longitude));
		y = length(new_altitude * msci::cos(new_latitude) * msci::sin(new_longitude));
		z = length(new_altitude * msci::sin(new_latitude));
	}
	
	void point_3d::rotate_in_x(const angle& x_angle)
	{
		length y_coord = y;
		length z_coord = z;
		y = y_coord * msci::cos(x_angle) - z_coord * msci::sin(x_angle);
		z = y_coord * msci::sin(x_angle) + z_coord * msci::cos(x_angle);
	}
	
	void point_3d::rotate_in_y(const angle& x_angle)
	{
		length x_coord = x;
		length z_coord = z;
		x = x_coord * msci::cos(x_angle) - z_coord * msci::sin(x_angle);
		z = x_coord * msci::sin(x_angle) + z_coord * msci::cos(x_angle);
	}
	
	void point_3d::rotate_in_z(const angle& x_angle)
	{
		length x_coord = x;
		length y_coord = y;
		x = x_coord * msci::cos(x_angle) - y_coord * msci::sin(x_angle);
		y = x_coord * msci::sin(x_angle) + y_coord * msci::cos(x_angle);
	}
	
	void point_3d::move(const displacement_3d& x_displacement)
	{
		x += x_displacement.x_projection();
		y += x_displacement.y_projection();
		z += x_displacement.z_projection();
	}
	
	void point_3d::move(const length& new_x,const length& new_y,const length& new_z)
	{
		x += new_x;
		y += new_y;
		z += new_z;
	}
	
	void point_3d::move(const length& new_p,const angle& new_theta,length new_z)
	{
		new_z.set_same_prefix(new_p);
		x += length(new_p * msci::cos(new_theta));
		y += length(new_p * msci::sin(new_theta));
		z += new_z;
	}
	
	void point_3d::move(const length& new_r,const angle& new_theta,const angle& new_phi)
	{
		x += length(new_r * msci::cos(new_theta) * msci::sin(new_phi));
		y += length(new_r * msci::sin(new_theta) * msci::sin(new_phi));
		z += length(new_r * msci::cos(new_phi));
	}

	length point_3d::distance_to_origin() const
	{
		return msci::sqrt(msci::pow(x,2) + msci::pow(y,2) + msci::pow(z,2));
	}

	string to_string(const point_3d& x)
	{
		ostringstream out;
		out << "(" << x.x << "," << x.y << "," << x.z << ")";
		return out.str();
	}

	length distance(const point_3d& x1,const point_3d& x2)
	{
		return msci::sqrt(msci::pow(x1.x - x2.x,2) + msci::pow(x1.y - x2.y,2) + msci::pow(x1.z - x2.z,2));
	}
}

bool operator ==(const msci::point_3d& x,const msci::point_3d& y)
{
	return (x.x == y.x and x.y == y.y and x.z == y.z);
}

bool operator !=(const msci::point_3d& x,const msci::point_3d& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const msci::point_3d& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, msci::point_3d& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::point_3d c(b);
	x = c;
	return is;
}
