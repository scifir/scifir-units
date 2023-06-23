#include "topology/point_1d.hpp"

#include "coordinates/coordinates_1d.hpp"

using namespace std;

namespace msci
{
	point_1d<float>::point_1d(const coordinates_1d<float>& x_coordinates) : x(x_coordinates.x)
	{}

	point_1d<float>& point_1d<float>::operator=(const coordinates_1d<float>& x_coordinates)
	{
		x = x_coordinates.x;
		return *this;
	}

	float distance(const point_1d<float>& x1,const point_1d<float>& x2)
	{
		return std::sqrt(std::pow(x1.x - x2.x,2));
	}
}
