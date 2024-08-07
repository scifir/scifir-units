#ifndef SCIFIR_UNITS_TOPOLOGY_POINT_3D_IMPL_HPP_INCLUDED
#define SCIFIR_UNITS_TOPOLOGY_POINT_3D_IMPL_HPP_INCLUDED

#include "./point_3d.hpp"

#include "../coordinates/coordinates_3d.hpp"

using namespace std;

namespace scifir
{
	template<typename T>
	point_3d<T>::point_3d(const coordinates_3d<T>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z)
	{}

	template<typename T>
	point_3d<T>::point_3d(coordinates_3d<T>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y)),z(std::move(x_coordinates.z))
	{}

	template<typename T>
	point_3d<T>& point_3d<T>::operator =(const coordinates_3d<T>& x_coordinates)
	{
		x = x_coordinates.x;
		y = x_coordinates.y;
		z = x_coordinates.z;
		return *this;
	}

	template<typename T>
	point_3d<T>& point_3d<T>::operator =(coordinates_3d<T>&& x_coordinates)
	{
		x = std::move(x_coordinates.x);
		y = std::move(x_coordinates.y);
		z = std::move(x_coordinates.z);
		return *this;
	}
}

#endif // SCIFIR_UNITS_TOPOLOGY_POINT_3D_IMPL_HPP_INCLUDED
