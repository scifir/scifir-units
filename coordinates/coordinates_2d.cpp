#include "coordinates/coordinates_2d.hpp"

using namespace std;

namespace scifir
{
	float distance(const coordinates_2d<float>& x,const coordinates_2d<float>& y)
	{
		return std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2));
	}

	float distance(const coordinates_2d<float>& x,const point_2d<float>& y)
	{
		return std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2));
	}

	float distance(const point_2d<float>& x,const coordinates_2d<float>& y)
	{
		return std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2));
	}
}
