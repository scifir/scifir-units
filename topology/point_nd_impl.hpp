#ifndef MSCI_UNITS_TOPOLOGY_POINT_ND_IMPL_HPP_INCLUDED
#define MSCI_UNITS_TOPOLOGY_POINT_ND_IMPL_HPP_INCLUDED

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
}

#endif // MSCI_UNITS_TOPOLOGY_POINT_ND_IMPL_HPP_INCLUDED
