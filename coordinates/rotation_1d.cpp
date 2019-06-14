#include "msci/units/coordinates/rotation_1d.hpp"

using namespace std;

namespace msci
{
	rotation_1d::rotation_1d() : x_angle()
	{
	}

	void rotation_1d::move_angle(const angle_number& new_angle)
	{
		x_angle += new_angle;
	}

	string complete_display(const msci::cartesian_2d& x,const msci::rotation_1d& y)
	{
		return "(" + x.get_x() + "," + x.get_y() + "," + y.get_angle() + ")";
	}
}

bool operator == (const msci::rotation_1d& x,const msci::rotation_1d& y)
{
	return (x.get_angle() == y.get_angle());
}

bool operator != (const msci::rotation_1d& x,const msci::rotation_1d& y)
{
	return !(x == y);
}
