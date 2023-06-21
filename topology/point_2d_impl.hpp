#include "topology/point_2d.hpp"

#include "coordinates/coordinates_2d.hpp"

using namespace std;

namespace msci
{
	template<typename T>
	point_2d<T>::point_2d(const coordinates_2d<T>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y)
	{}

	template<typename T>
	point_2d<T>& point_2d<T>::operator=(const coordinates_2d<T>& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		return *this;
	}

	template<>
	point_2d<float>::point_2d(const coordinates_2d<float>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y)
	{}

	template<>
	point_2d<float>& point_2d<float>::operator=(const coordinates_2d<float>& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		return *this;
	}
}
