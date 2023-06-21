#include "topology/point_nd.hpp"

#include "coordinates/coordinates_nd.hpp"

using namespace std;

namespace msci
{
	template<typename T>
	point_nd<T>::point_nd(const coordinates_nd<T>& new_coordinates) : values(new_coordinates.values)
	{}

	template<typename T>
	point_nd<T>& point_nd<T>::operator=(const coordinates_nd<T>& x_coordinates)
	{
		values = x_coordinates.values;
		return *this;
	}

	template<>
	point_nd<float>::point_nd(const coordinates_nd<float>& new_coordinates) : values(new_coordinates.values)
	{}

	template<>
	point_nd<float>& point_nd<float>::operator=(const coordinates_nd<float>& x_coordinates)
	{
		values = x_coordinates.values;
		return *this;
	}
}
