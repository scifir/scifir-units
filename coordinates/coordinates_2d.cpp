#include "./coordinates_2d.hpp"

#include "../util/types.hpp"

using namespace std;

namespace scifir
{
	string to_string(const coordinates_2d<float>& x)
	{
		return x.display_cartesian();
	}

	float distance(const coordinates_2d<float>& x,const coordinates_2d<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2)));
	}

	float distance(const coordinates_2d<float>& x,const point_2d<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2)));
	}

	float distance(const point_2d<float>& x,const coordinates_2d<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2)));
	}
}

ostream& operator <<(ostream& os,const scifir::coordinates_2d<float>& x)
{
	return os << scifir::to_string(x);
}