#ifndef SCIFIR_UNITS_TOPOLOGY_POINT_ND_IMPL_HPP_INCLUDED
#define SCIFIR_UNITS_TOPOLOGY_POINT_ND_IMPL_HPP_INCLUDED

#include "./point_nd.hpp"

#include "../coordinates/coordinates_nd.hpp"

using namespace std;

namespace scifir
{
	template<typename T>
	point_nd<T>::point_nd(const coordinates_nd<T>& x_coordinates) : values(x_coordinates.values)
	{}

	template<typename T>
	point_nd<T>::point_nd(coordinates_nd<T>&& x_coordinates) : values(std::move(x_coordinates.values))
	{}

	template<typename T>
	point_nd<T>& point_nd<T>::operator =(const coordinates_nd<T>& x_coordinates)
	{
		values = x_coordinates.values;
		return *this;
	}

	template<typename T>
	point_nd<T>& point_nd<T>::operator =(coordinates_nd<T>&& x_coordinates)
	{
		values = std::move(x_coordinates.values);
		return *this;
	}
}

#endif // SCIFIR_UNITS_TOPOLOGY_POINT_ND_IMPL_HPP_INCLUDED
