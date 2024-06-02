#include "./point_2d.hpp"

#include "../coordinates/coordinates_2d.hpp"

using namespace std;

namespace scifir
{
	point_2d<float>::point_2d(const coordinates_2d<float>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y)
	{}

	point_2d<float>& point_2d<float>::operator=(const coordinates_2d<float>& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		return *this;
	}

	float distance(const point_2d<float>& x1,const point_2d<float>& x2)
	{
		return float(std::sqrt(std::pow(x1.x - x2.x,2) + std::pow(x1.y - x2.y,2)));
	}
}
