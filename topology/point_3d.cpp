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

	float distance(const point_3d<float>& x,const point_3d<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2) + std::pow(x.z - y.z,2)));
	}
}

ostream& operator <<(ostream& os,const scifir::point_3d<float>& x)
{
	return os << scifir::to_string(x);
}