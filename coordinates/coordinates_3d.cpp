#include "./coordinates_3d.hpp"

using namespace std;

namespace scifir
{
	string to_string(cardinale_point x)
	{
		switch(x)
		{
			case cardinale_point::NORTH:
				return "NORTH";
			case cardinale_point::SOUTH:
				return "SOUTH";
			case cardinale_point::EAST:
				return "EAST";
			case cardinale_point::WEST:
				return "WEST";
		}
		return "";
	}

	string to_string(const coordinates_3d<float>& x)
	{
		return x.display_cartesian();
	}

	cardinale_point create_cardinale_point(const string& x)
	{
		if (x == "NORTH")
		{
			return cardinale_point::NORTH;
		}
		else if (x == "SOUTH")
		{
			return cardinale_point::SOUTH;
		}
		else if (x == "EAST")
		{
			return cardinale_point::EAST;
		}
		else if (x == "WEST")
		{
			return cardinale_point::WEST;
		}
		return cardinale_point::NORTH;
	}

	float distance(const coordinates_3d<float>& x,const coordinates_3d<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2) + std::pow(x.z - y.z,2)));
	}

	float distance(const coordinates_3d<float>& x,const point_3d<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2) + std::pow(x.z - y.z,2)));
	}

	float distance(const point_3d<float>& x,const coordinates_3d<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2) + std::pow(x.z - y.z,2)));
	}
}

ostream& operator <<(ostream& os,const scifir::coordinates_3d<float>& x)
{
	return os << scifir::to_string(x);
}