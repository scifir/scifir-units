#ifndef SCIFIR_UNITS_PHYSICS_POINT_3D_INCLUDED
#define SCIFIR_UNITS_PHYSICS_POINT_3D_INCLUDED

#include "../topology/point_3d.hpp"
#include "../units/base_units.hpp"

using namespace std;

namespace scifir
{
	template<typename T = scifir::length>
	class mass_point_3d
	{
		public:
			mass_point_3d() : mass(),point_3d()
			{}

			mass_point_3d(const mass_point_3d& x) : mass(x.mass),point_3d(x.point_3d)
			{}

			mass_point_3d(mass_point_3d&& x) : mass(std::move(x.mass)),point_3d(std::move(x.point_3d))
			{}

			explicit mass_point_3d(const scalar_unit& new_mass,const point_3d<T>& new_point_3d) : mass(new_mass),point_3d(new_point_3d)
			{}

			mass_point_3d<T> operator +(const mass_point_3d<T>& x_mass_point_3d) const
			{
				T new_mass_x = (mass * point_3d.x + x_mass_point_3d.mass * x_mass_point_3d.point_3d.x) / (mass + x_mass_point_3d.mass);
				T new_mass_y = (mass * point_3d.y + x_mass_point_3d.mass * x_mass_point_3d.point_3d.y) / (mass + x_mass_point_3d.mass);
				T new_mass_z = (mass * point_3d.z + x_mass_point_3d.mass * x_mass_point_3d.point_3d.z) / (mass + x_mass_point_3d.mass);
				scifir::point_3d<T> new_point_3d(new_mass_x,new_mass_y,new_mass_z);
				return mass_point_3d<T>(mass + x_mass_point_3d.mass,new_point_3d);
			}

			mass_point_3d<T> operator -(const mass_point_3d<T>& x_mass_point_3d) const
			{
				T new_mass_x = (mass * point_3d.x - x_mass_point_3d.mass * x_mass_point_3d.point_3d.x) / (mass - x_mass_point_3d.mass);
				T new_mass_y = (mass * point_3d.y - x_mass_point_3d.mass * x_mass_point_3d.point_3d.y) / (mass - x_mass_point_3d.mass);
				T new_mass_z = (mass * point_3d.z - x_mass_point_3d.mass * x_mass_point_3d.point_3d.z) / (mass - x_mass_point_3d.mass);
				scifir::point_3d<T> new_point_3d(new_mass_x,new_mass_y,new_mass_z);
				return mass_point_3d<T>(mass - x_mass_point_3d.mass,new_point_3d);
			}

			scifir::mass mass;
			scifir::point_3d<T> point_3d;
	};
}

template<typename T,typename U>
bool operator ==(const scifir::mass_point_3d<T>& x,const scifir::mass_point_3d<U>& y)
{
	if (x.mass == y.mass and x.point_3d == y.point_3d)
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