#include "./point_2d.hpp"

#include "../coordinates/coordinates_2d.hpp"
#include "../util/types.hpp"

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

	string to_string(const point_2d<float>& x)
	{
		ostringstream out;
		out << "(" << display_float(x.x,2) << "," << display_float(x.y,2) << ")";
		return out.str();
	}

	float distance(const point_2d<float>& x1,const point_2d<float>& x2)
	{
		return float(std::sqrt(std::pow(x1.x - x2.x,2) + std::pow(x1.y - x2.y,2)));
	}
}

ostream& operator <<(ostream& os,const scifir::point_2d<float>& x)
{
	return os << scifir::to_string(x);
}