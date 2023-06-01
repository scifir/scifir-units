#include "coordinates/coordinates_3d.hpp"

#include "util/types.hpp"

#include <sstream>
#include <vector>

#include "boost/algorithm/string.hpp"

using namespace std;

namespace msci
{
	coordinates_3d::coordinates_3d() : x(),y(),z()
	{
	}

	coordinates_3d::coordinates_3d(coordinates_system new_coordinates_system,float coord_1,float coord_2,float coord_3)
	{
		set_position(new_coordinates_system,coord_1,coord_2,coord_3);
	}
	
	coordinates_3d::coordinates_3d(const length& new_x,const length& new_y,const length& new_z) : x(new_x),y(new_y),z(new_z)
	{}
	
	coordinates_3d::coordinates_3d(const length& new_p,const msci::angle& new_theta,const length& new_z)
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

	coordinates_3d::coordinates_3d(string init) : coordinates_3d()
	{
		vector<string> values;
		if (init.front() == '(')
		{
			init.erase(0,1);
		}
		if (init.back() == ')')
		{
			init.erase(init.size()-1,1);
		}
		boost::split(values,init,boost::is_any_of(","));
		float coord_1 = parse_float(values[0]);
		float coord_2 = parse_float(values[1]);
		float coord_3 = parse_float(values[2]);
		set_position(CARTESIAN,coord_1,coord_2,coord_3);
	}
	
	void coordinates_3d::set_position(coordinates_system new_coordinates_system,float coord_1,float coord_2,float coord_3)
	{
		if (new_coordinates_system == CARTESIAN)
		{
			x = length(coord_1,"m");
			y = length(coord_2,"m");
			z = length(coord_3,"m");
		}
		else if (new_coordinates_system == CYLINDRICAL)
		{
			msci::angle coord_angle = angle(coord_2);
			x = length(coord_1 * msci::cos(coord_angle),"m");
			y = length(coord_1 * msci::sin(coord_angle),"m");
			z = length(coord_3,"m");
		}
		else if (new_coordinates_system == SPHERICAL)
		{
			msci::angle coord_angle = angle(coord_2);
			msci::angle coord_angle_2 = angle(coord_3);
			x = length(coord_1 * msci::cos(coord_angle) * msci::sin(coord_angle_2),"m");
			y = length(coord_1 * msci::sin(coord_angle) * msci::sin(coord_angle_2),"m");
			z = length(coord_1 * msci::cos(coord_angle_2),"m");
		}
		else if (new_coordinates_system == GEOGRAPHICAL)
		{
			msci::angle coord_angle = angle(coord_1);
			msci::angle coord_angle_2 = angle(coord_2);
			x = length(coord_3 * msci::cos(coord_angle) * msci::cos(coord_angle_2),"m");
			y = length(coord_3 * msci::cos(coord_angle) * msci::sin(coord_angle_2),"m");
			z = length(coord_3 * msci::sin(coord_angle),"m");
		}
	}
	
	void coordinates_3d::set_position(const length& new_x,const length& new_y,const length& new_z)
	{}
	
	void coordinates_3d::set_position(const length& new_p,const msci::angle& new_theta,const length& new_z)
	{}
	
	void coordinates_3d::set_position(const length& new_r,const msci::angle& new_theta,const msci::angle& new_phi)
	{}
	
	void coordinates_3d::set_position(const msci::angle& new_latitude,const msci::angle& new_longitude,const length& new_altitude)
	{}
	
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
