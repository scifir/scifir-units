#include "./point_3d.hpp"

#include "../coordinates/coordinates_3d.hpp"
#include "../util/types.hpp"

using namespace std;

namespace scifir
{
	point_3d<float>::point_3d(const coordinates_3d<float>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z)
	{}

	point_3d<float>::point_3d(coordinates_3d<float>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y)),z(std::move(x_coordinates.z))
	{}

	point_3d<float>& point_3d<float>::operator=(const coordinates_3d<float>& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		z = x_coordinates.z;
		return *this;
	}

	point_3d<float>& point_3d<float>::operator=(coordinates_3d<float>&& x_coordinates)
	{
		x = std::move(x_coordinates.x);
		y = std::move(x_coordinates.y);
		z = std::move(x_coordinates.z);
		return *this;
	}

	string to_string(const point_3d<float>& x)
	{
		ostringstream out;
		out << "(" << display_float(x.x,2) << "," << display_float(x.y,2) << "," << display_float(x.z,2) << ")";
		return out.str();
	}

	float distance(const point_3d<float>& x1,const point_3d<float>& x2)
	{
		return float(std::sqrt(std::pow(x1.x - x2.x,2) + std::pow(x1.y - x2.y,2) + std::pow(x1.z - x2.z,2)));
	}
}

ostream& operator <<(ostream& os,const scifir::point_3d<float>& x)
{
	return os << scifir::to_string(x);
}