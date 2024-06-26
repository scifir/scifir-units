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

	point_1d<float>& point_1d<float>::operator=(const coordinates_1d<float>& x_coordinates)
	{
		x = x_coordinates.x;
		return *this;
	}

	point_1d<float>& point_1d<float>::operator=(coordinates_1d<float>&& x_coordinates)
	{
		x = std::move(x_coordinates.x);
		return *this;
	}

	string to_string(const point_1d<float>& x)
	{
		ostringstream out;
		out << "(" << display_float(x.x) << ")";
		return out.str();
	}

	float distance(const point_1d<float>& x1,const point_1d<float>& x2)
	{
		return float(std::sqrt(std::pow(x1.x - x2.x,2)));
	}
}

ostream& operator <<(ostream& os,const scifir::point_1d<float>& x)
{
	return os << scifir::to_string(x);
}