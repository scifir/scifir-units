#ifndef SCIFIR_UNITS_PHYSICS_POINT_3D_INCLUDED
#define SCIFIR_UNITS_PHYSICS_POINT_3D_INCLUDED

#include "../coordinates/coordinates_3d.hpp"
#include "../units/base_units.hpp"

using namespace std;

namespace scifir
{
	template<typename T = length>
	class mass_point_3d
	{
		public:
		mass_point_3d() : mass(),coordinates_3d()
			{}

			mass_point_3d(const mass_point_3d<T>& x) : mass(x.mass),coordinates_3d(x.coordinates_3d)
			{}

			mass_point_3d(mass_point_3d<T>&& x) : mass(std::move(x.mass)),coordinates_3d(std::move(x.coordinates_3d))
			{}

			template<typename U, typename V>
			explicit mass_point_3d(const U& new_mass,const coordinates_3d<V>& new_coordinates_3d) : mass(new_mass),coordinates_3d(new_coordinates_3d)
			{}

			template<typename U>
			mass_point_3d<T> operator +(const mass_point_3d<U>& x_mass_coordinates_3d) const
			{
				T new_mass_x = T((mass * coordinates_3d.x + x_mass_coordinates_3d.mass * x_mass_coordinates_3d.coordinates_3d.x) / (mass + x_mass_coordinates_3d.mass));
				T new_mass_y = T((mass * coordinates_3d.y + x_mass_coordinates_3d.mass * x_mass_coordinates_3d.coordinates_3d.y) / (mass + x_mass_coordinates_3d.mass));
				T new_mass_z = T((mass * coordinates_3d.z + x_mass_coordinates_3d.mass * x_mass_coordinates_3d.coordinates_3d.z) / (mass + x_mass_coordinates_3d.mass));
				scifir::coordinates_3d<T> new_coordinates_3d(new_mass_x,new_mass_y,new_mass_z);
				return mass_point_3d<T>(mass + x_mass_coordinates_3d.mass,new_coordinates_3d);
			}

			template<typename U>
			mass_point_3d<T> operator -(const mass_point_3d<U>& x_mass_coordinates_3d) const
			{
				T new_mass_x = T((mass * coordinates_3d.x - x_mass_coordinates_3d.mass * x_mass_coordinates_3d.coordinates_3d.x) / (mass - x_mass_coordinates_3d.mass));
				T new_mass_y = T((mass * coordinates_3d.y - x_mass_coordinates_3d.mass * x_mass_coordinates_3d.coordinates_3d.y) / (mass - x_mass_coordinates_3d.mass));
				T new_mass_z = T((mass * coordinates_3d.z - x_mass_coordinates_3d.mass * x_mass_coordinates_3d.coordinates_3d.z) / (mass - x_mass_coordinates_3d.mass));
				scifir::coordinates_3d<T> new_coordinates_3d(new_mass_x,new_mass_y,new_mass_z);
				return mass_point_3d<T>(mass - x_mass_coordinates_3d.mass,new_coordinates_3d);
			}

			scifir::mass mass;
			scifir::coordinates_3d<T> coordinates_3d;
	};
}

template<typename T,typename U>
bool operator ==(const scifir::mass_point_3d<T>& x,const scifir::mass_point_3d<U>& y)
{
	if (x.mass == y.mass and x.coordinates_3d == y.coordinates_3d)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T,typename U>
bool operator !=(const scifir::mass_point_3d<T>& x,const scifir::mass_point_3d<U>& y)
{
	return !(x == y);
}

#endif // SCIFIR_UNITS_PHYSICS_POINT_3D_INCLUDED