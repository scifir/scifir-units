#ifndef SCIFIR_UNITS_PHYSICS_CHARGE_POINT_3D_INCLUDED
#define SCIFIR_UNITS_PHYSICS_CHARGE_POINT_3D_INCLUDED

#include "../coordinates/coordinates_3d.hpp"
#include "../units/base_units.hpp"

using namespace std;

namespace scifir
{
	template<typename T = length>
	class charge_point_3d
	{
		public:
		charge_point_3d() : charge(),coordinates()
			{}

			charge_point_3d(const charge_point_3d<T>& x) : charge(x.charge),coordinates(x.coordinates)
			{}

			charge_point_3d(charge_point_3d<T>&& x) : charge(std::move(x.charge)),coordinates(std::move(x.coordinates))
			{}

			template<typename U, typename V>
			explicit charge_point_3d(const U& new_charge,const coordinates_3d<V>& new_coordinates) : charge(new_charge),coordinates(new_coordinates)
			{}

			charge_point_3d<T>& operator =(const charge_point_3d<T>& x)
			{
				charge = x.charge;
				coordinates = x.coordinates;
				return *this;
			}

			charge_point_3d<T>& operator =(charge_point_3d<T>&& x)
			{
				charge = std::move(x.charge);
				coordinates = std::move(x.coordinates);
				return *this;
			}

			string display() const
			{
				ostringstream out;
				out << charge << " " << coordinates;
				return out.str();
			}

			scifir::charge charge;
			scifir::coordinates_3d<T> coordinates;
	};
}

template<typename T,typename U>
bool operator ==(const scifir::charge_point_3d<T>& x,const scifir::charge_point_3d<U>& y)
{
	if (x.charge == y.charge and x.coordinates == y.coordinates)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T,typename U>
bool operator !=(const scifir::charge_point_3d<T>& x,const scifir::charge_point_3d<U>& y)
{
	return !(x == y);
}

#endif // SCIFIR_UNITS_PHYSICS_CHARGE_POINT_3D_INCLUDED