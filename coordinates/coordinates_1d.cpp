#include "coordinates/coordinates_1d.hpp"

using namespace std;

namespace scifir
{
	float distance(const coordinates_1d<float>& x,const coordinates_1d<float>& y)
	{
		return std::sqrt(std::pow(x.x - y.x,2));
	}

	float distance(const coordinates_1d<float>& x,const point_1d<float>& y)
	{
		return std::sqrt(std::pow(x.x - y.x,2));
	}

	float distance(const point_1d<float>& x,const coordinates_1d<float>& y)
	{
		return std::sqrt(std::pow(x.x - y.x,2));
	}
}
