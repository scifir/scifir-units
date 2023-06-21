#include "topology/point_1d.hpp"

#include "coordinates/coordinates_1d.hpp"

using namespace std;

namespace msci
{
	template<typename T>
	point_1d<T>::point_1d(const coordinates_1d<T>& x_coordinates) : x(x_coordinates.x)
	{}

	template<typename T>
	point_1d<T>& point_1d<T>::operator=(const coordinates_1d<T>& x_coordinates)
	{
		x = x_coordinates.x;
		return *this;
	}

	template<>
	point_1d<float>::point_1d(const coordinates_1d<float>& x_coordinates) : x(x_coordinates.x)
	{}

	template<>
	point_1d<float>& point_1d<float>::operator=(const coordinates_1d<float>& x_coordinates)
	{
		x = x_coordinates.x;
		return *this;
	}
}
