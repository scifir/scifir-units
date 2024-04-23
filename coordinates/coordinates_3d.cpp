#include "./coordinates_3d.hpp"

using namespace std;

namespace scifir
{
	float distance(const coordinates_3d<float>& x,const coordinates_3d<float>& y)
	{
		return std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2) + std::pow(x.z - y.z,2));
	}

	float distance(const coordinates_3d<float>& x,const point_3d<float>& y)
	{
		return std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2) + std::pow(x.z - y.z,2));
	}

	float distance(const point_3d<float>& x,const coordinates_3d<float>& y)
	{
		return std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2) + std::pow(x.z - y.z,2));
	}
}
