#include "./point_3d.hpp"

#include "../coordinates/coordinates_3d.hpp"

using namespace std;

namespace scifir
{
	point_3d<float>::point_3d(const coordinates_3d<float>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z)
	{}

	point_3d<float>& point_3d<float>::operator=(const coordinates_3d<float>& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		z = x_coordinates.z;
		return *this;
	}

	float distance(const point_3d<float>& x1,const point_3d<float>& x2)
	{
		return float(std::sqrt(std::pow(x1.x - x2.x,2) + std::pow(x1.y - x2.y,2) + std::pow(x1.z - x2.z,2)));
	}
}
