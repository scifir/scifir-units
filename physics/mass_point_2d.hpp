#ifndef SCIFIR_UNITS_PHYSICS_MASS_POINT_2D_INCLUDED
#define SCIFIR_UNITS_PHYSICS_MASS_POINT_2D_INCLUDED

#include "../coordinates/coordinates_2d.hpp"
#include "../units/base_units.hpp"

using namespace std;

namespace scifir
{
	template<typename T = length>
	class mass_point_2d
	{
		public:
		mass_point_2d() : mass(),coordinates()
			{}

			mass_point_2d(const mass_point_2d<T>& x) : mass(x.mass),coordinates(x.coordinates)
			{}

			mass_point_2d(mass_point_2d<T>&& x) : mass(std::move(x.mass)),coordinates(std::move(x.coordinates))
			{}

			template<typename U, typename V>
			explicit mass_point_2d(const U& new_mass,const coordinates_2d<V>& new_coordinates) : mass(new_mass),coordinates(new_coordinates)
			{}

			mass_point_2d<T>& operator =(const mass_point_2d<T>& x)
			{
				mass = x.mass;
				coordinates = x.coordinates;
				return *this;
			}

			mass_point_2d<T>& operator =(mass_point_2d<T>&& x)
			{
				mass = std::move(x.mass);
				coordinates = std::move(x.coordinates);
				return *this;
			}

			template<typename U>
			mass_point_2d<T> operator +(const mass_point_2d<U>& x_mass_coordinates_2d) const
			{
				T new_mass_x = T((mass * coordinates.x + x_mass_coordinates_2d.mass * x_mass_coordinates_2d.coordinates.x) / (mass + x_mass_coordinates_2d.mass));
				T new_mass_y = T((mass * coordinates.y + x_mass_coordinates_2d.mass * x_mass_coordinates_2d.coordinates.y) / (mass + x_mass_coordinates_2d.mass));
				scifir::coordinates_2d<T> new_coordinates_2d(new_mass_x,new_mass_y);
				return mass_point_2d<T>(mass + x_mass_coordinates_2d.mass,new_coordinates_2d);
			}

			template<typename U>
			mass_point_2d<T> operator -(const mass_point_2d<U>& x_mass_coordinates_2d) const
			{
				T new_mass_x = T((mass * coordinates.x - x_mass_coordinates_2d.mass * x_mass_coordinates_2d.coordinates.x) / (mass - x_mass_coordinates_2d.mass));
				T new_mass_y = T((mass * coordinates.y - x_mass_coordinates_2d.mass * x_mass_coordinates_2d.coordinates.y) / (mass - x_mass_coordinates_2d.mass));
				scifir::coordinates_2d<T> new_coordinates_2d(new_mass_x,new_mass_y);
				return mass_point_2d<T>(mass - x_mass_coordinates_2d.mass,new_coordinates_2d);
			}

			string display() const
			{
				ostringstream out;
				out << mass << " " << coordinates;
				return out.str();
			}

			scifir::mass mass;
			scifir::coordinates_2d<T> coordinates;
	};
}

template<typename T,typename U>
bool operator ==(const scifir::mass_point_2d<T>& x,const scifir::mass_point_2d<U>& y)
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
bool operator !=(const scifir::mass_point_2d<T>& x,const scifir::mass_point_2d<U>& y)
{
	return !(x == y);
}

#endif // SCIFIR_UNITS_PHYSICS_MASS_POINT_2D_INCLUDED