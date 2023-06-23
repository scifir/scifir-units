#ifndef MSCI_UNITS_TOPOLOGY_POINT_2D_IMPL_HPP_INCLUDED
#define MSCI_UNITS_TOPOLOGY_POINT_2D_IMPL_HPP_INCLUDED

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
}

#endif // MSCI_UNITS_TOPOLOGY_POINT_2D_IMPL_HPP_INCLUDED
