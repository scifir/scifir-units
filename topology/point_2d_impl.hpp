#ifndef SCIFIR_UNITS_TOPOLOGY_POINT_2D_IMPL_HPP_INCLUDED
#define SCIFIR_UNITS_TOPOLOGY_POINT_2D_IMPL_HPP_INCLUDED

#include "./point_2d.hpp"

#include "../coordinates/coordinates_2d.hpp"

using namespace std;

namespace scifir
{
	template<typename T>
	point_2d<T>::point_2d(const coordinates_2d<T>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y)
	{}

	template<typename T>
	point_2d<T>::point_2d(coordinates_2d<T>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y))
	{}

	template<typename T>
	point_2d<T>& point_2d<T>::operator =(const coordinates_2d<T>& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		return *this;
	}

	template<typename T>
	point_2d<T>& point_2d<T>::operator =(coordinates_2d<T>&& x_coordinates)
	{
		x = std::move(x_coordinates.x);
		y = std::move(x_coordinates.y);
		return *this;
	}
}

#endif // SCIFIR_UNITS_TOPOLOGY_POINT_2D_IMPL_HPP_INCLUDED
