#ifndef MSCI_UNITS_TOPOLOGY_POINT_1D_IMPL_HPP_INCLUDED
#define MSCI_UNITS_TOPOLOGY_POINT_1D_IMPL_HPP_INCLUDED

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
}

#endif // MSCI_UNITS_TOPOLOGY_POINT_1D_IMPL_HPP_INCLUDED
