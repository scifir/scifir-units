#include "msci/units/coordinates/light/cartesian_3d.hpp"

#include "msci/units/util/types.hpp"

#include <sstream>
#include <vector>

#include "boost/algorithm/string.hpp"

using namespace std;

namespace msci
{
	cartesian_3d::cartesian_3d() : x(),y(),z()
	{
	}

	cartesian_3d::cartesian_3d(coordinates_system new_coordinates_system,float coord_1,float coord_2,float coord_3)
	{
		set_position(new_coordinates_system,coord_1,coord_2,coord_3);
	}

	cartesian_3d::cartesian_3d(coordinates_system new_coordinates_system,string init) : cartesian_3d()
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
		set_position(new_coordinates_system,coord_1,coord_2,coord_3);
	}

	string cartesian_3d::display() const
	{
		ostringstream out;
		out << "(" << x << "," << y << "," << z << ")";
		return out.str();
	}
	
	void cartesian_3d::set_position(coordinates_system new_coordinates_system,float coord_1,float coord_2,float coord_3)
	{
		if (new_coordinates_system == CARTESIAN)
		{
			x = coord_1;
			y = coord_2;
			z = coord_3;
		}
		else if (new_coordinates_system == CYLINDRICAL)
		{
			msci::angle coord_angle = angle(coord_2);
			x = coord_1 * msci::cos(coord_angle);
			y = coord_1 * msci::sin(coord_angle);
			z = coord_3;
		}
		else if (new_coordinates_system == SPHERICAL)
		{
			msci::angle coord_angle = angle(coord_2);
			msci::angle coord_angle_2 = angle(coord_3);
			x = coord_1 * msci::cos(coord_angle) * msci::sin(coord_angle_2);
			y = coord_1 * msci::sin(coord_angle) * msci::sin(coord_angle_2);
			z = coord_1 * msci::cos(coord_angle_2);
		}
		else if (new_coordinates_system == GEOGRAPHICAL)
		{
			msci::angle coord_angle = angle(coord_1);
			msci::angle coord_angle_2 = angle(coord_2);
			x = coord_3 * msci::cos(coord_angle) * msci::cos(coord_angle_2);
			y = coord_3 * msci::cos(coord_angle) * msci::sin(coord_angle_2);
			z = coord_3 * msci::sin(coord_angle);
		}
	}

	float distance(const cartesian_3d& x,const cartesian_3d& y)
	{
		return std::sqrt(std::pow(x.get_x() - y.get_x(),2) + std::pow(x.get_y() - y.get_y(),2) + std::pow(x.get_z() - y.get_z(),2));
	}
}

bool operator ==(const msci::cartesian_3d& x,const msci::cartesian_3d& y)
{
	if (x.get_x() == y.get_x() and x.get_y() == y.get_y() and x.get_z() == y.get_z())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::cartesian_3d& x,const msci::cartesian_3d& y)
{
	return !(x == y);
}

bool operator ==(const msci::cartesian_3d& x,const msci::point_3d& y)
{
	if (x.get_x() == y.get_x() and x.get_y() == y.get_y() and x.get_z() == y.get_z())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::cartesian_3d& x,const msci::point_3d& y)
{
	return !(x == y);
}

bool operator ==(const msci::point_3d& x,const msci::cartesian_3d& y)
{
	if (x.get_x() == y.get_x() and x.get_y() == y.get_y() and x.get_z() == y.get_z())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::point_3d& x,const msci::cartesian_3d& y)
{
	return !(x == y);
}

ostream& operator << (ostream& os, const msci::cartesian_3d& x)
{
	return os << x.display();
}
