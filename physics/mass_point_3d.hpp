#ifndef SCIFIR_UNITS_PHYSICS_MASS_POINT_3D_INCLUDED
#define SCIFIR_UNITS_PHYSICS_MASS_POINT_3D_INCLUDED

#include "../coordinates/coordinates_3d.hpp"
#include "../units/base_units.hpp"

using namespace std;

namespace scifir
{
	template<typename T = length>
	class mass_point_3d
	{
		public:
		mass_point_3d() : mass(),coordinates()
			{}

			mass_point_3d(const mass_point_3d<T>& x) : mass(x.mass),coordinates(x.coordinates)
			{}

			mass_point_3d(mass_point_3d<T>&& x) : mass(std::move(x.mass)),coordinates(std::move(x.coordinates))
			{}

			template<typename U, typename V>
			explicit mass_point_3d(const U& new_mass,const coordinates_3d<V>& new_coordinates) : mass(new_mass),coordinates(new_coordinates)
			{}

			mass_point_3d<T>& operator =(const mass_point_3d<T>& x)
			{
				mass = x.mass;
				coordinates = x.coordinates;
				return *this;
			}

			mass_point_3d<T>& operator =(mass_point_3d<T>&& x)
			{
				mass = std::move(x.mass);
				coordinates = std::move(x.coordinates);
				return *this;
			}

			template<typename U>
			mass_point_3d<T> operator +(const mass_point_3d<U>& x_mass_coordinates_3d) const
			{
				T new_mass_x = T((mass * coordinates.x + x_mass_coordinates_3d.mass * x_mass_coordinates_3d.coordinates.x) / (mass + x_mass_coordinates_3d.mass));
				T new_mass_y = T((mass * coordinates.y + x_mass_coordinates_3d.mass * x_mass_coordinates_3d.coordinates.y) / (mass + x_mass_coordinates_3d.mass));
				T new_mass_z = T((mass * coordinates.z + x_mass_coordinates_3d.mass * x_mass_coordinates_3d.coordinates.z) / (mass + x_mass_coordinates_3d.mass));
				scifir::coordinates_3d<T> new_coordinates_3d(new_mass_x,new_mass_y,new_mass_z);
				return mass_point_3d<T>(mass + x_mass_coordinates_3d.mass,new_coordinates_3d);
			}

			template<typename U>
			mass_point_3d<T> operator -(const mass_point_3d<U>& x_mass_coordinates_3d) const
			{
				T new_mass_x = T((mass * coordinates.x - x_mass_coordinates_3d.mass * x_mass_coordinates_3d.coordinates.x) / (mass - x_mass_coordinates_3d.mass));
				T new_mass_y = T((mass * coordinates.y - x_mass_coordinates_3d.mass * x_mass_coordinates_3d.coordinates.y) / (mass - x_mass_coordinates_3d.mass));
				T new_mass_z = T((mass * coordinates.z - x_mass_coordinates_3d.mass * x_mass_coordinates_3d.coordinates.z) / (mass - x_mass_coordinates_3d.mass));
				scifir::coordinates_3d<T> new_coordinates_3d(new_mass_x,new_mass_y,new_mass_z);
				return mass_point_3d<T>(mass - x_mass_coordinates_3d.mass,new_coordinates_3d);
			}

			string display() const
			{
				ostringstream out;
				out << mass << " " << coordinates;
				return out.str();
			}

			scifir::mass mass;
			scifir::coordinates_3d<T> coordinates;
	};
}

template<typename T,typename U>
bool operator ==(const scifir::mass_point_3d<T>& x,const scifir::mass_point_3d<U>& y)
{
	if (x.mass == y.mass and x.coordinates == y.coordinates)
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

#endif // SCIFIR_UNITS_PHYSICS_MASS_POINT_3D_INCLUDED