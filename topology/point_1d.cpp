#include "./point_1d.hpp"

#include "../coordinates/coordinates_1d.hpp"
#include "../util/types.hpp"

using namespace std;

namespace scifir
{
	point_1d<float>::point_1d(const coordinates_1d<float>& x_coordinates) : x(x_coordinates.x)
	{}

	point_1d<float>::point_1d(coordinates_1d<float>&& x_coordinates) : x(std::move(x_coordinates.x))
	{}

	point_1d<float>& point_1d<float>::operator =(const coordinates_1d<float>& x_coordinates)
	{
		x = x_coordinates.x;
		return *this;
	}

	point_1d<float>& point_1d<float>::operator =(coordinates_1d<float>&& x_coordinates)
	{
		x = std::move(x_coordinates.x);
		return *this;
	}

	string to_string(const point_1d<float>& x)
	{
		return x.display_cartesian();
	}

	float distance(const point_1d<float>& x,const point_1d<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2)));
	}
}

ostream& operator <<(ostream& os,const scifir::point_1d<float>& x)
{
	return os << scifir::to_string(x);
}