#include "./point_2d.hpp"

#include "../coordinates/coordinates_2d.hpp"
#include "../util/types.hpp"

using namespace std;

namespace scifir
{
	point_2d<float>::point_2d(const coordinates_2d<float>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y)
	{}

	point_2d<float>::point_2d(coordinates_2d<float>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y))
	{}

	point_2d<float>& point_2d<float>::operator=(const coordinates_2d<float>& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		return *this;
	}

	point_2d<float>& point_2d<float>::operator=(coordinates_2d<float>&& x_coordinates)
	{
		x = std::move(x_coordinates.x);
		y = std::move(x_coordinates.y);
		return *this;
	}

	string to_string(const point_2d<float>& x)
	{
		return x.display_cartesian();
	}

	float distance(const point_2d<float>& x,const point_2d<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2)));
	}
}

ostream& operator <<(ostream& os,const scifir::point_2d<float>& x)
{
	return os << scifir::to_string(x);
}