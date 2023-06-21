#include "topology/point_3d.hpp"

#include "coordinates/coordinates_3d.hpp"

using namespace std;

namespace msci
{
	template<typename T>
	point_3d<T>::point_3d(const coordinates_3d<T>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z)
	{}

	template<typename T>
	point_3d<T>& point_3d<T>::operator=(const coordinates_3d<T>& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		z = x_coordinates.z;
		return *this;
	}

	point_3d<float>::point_3d(const coordinates_3d<float>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z)
	{}

	point_3d<float>& point_3d<float>::operator=(const coordinates_3d<float>& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		z = x_coordinates.z;
		return *this;
	}
}
