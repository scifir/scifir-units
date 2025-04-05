#ifndef SCIFIR_UNITS_PHYSICS_CHARGE_POINT_2D_INCLUDED
#define SCIFIR_UNITS_PHYSICS_CHARGE_POINT_2D_INCLUDED

#include "../coordinates/coordinates_2d.hpp"
#include "../units/base_units.hpp"

using namespace std;

namespace scifir
{
	template<typename T = length>
	class charge_point_2d
	{
		public:
		charge_point_2d() : charge(),coordinates()
			{}

			charge_point_2d(const charge_point_2d<T>& x) : charge(x.charge),coordinates(x.coordinates)
			{}

			charge_point_2d(charge_point_2d<T>&& x) : charge(std::move(x.charge)),coordinates(std::move(x.coordinates))
			{}

			template<typename U, typename V>
			explicit charge_point_2d(const U& new_charge,const coordinates_2d<V>& new_coordinates) : charge(new_charge),coordinates(new_coordinates)
			{}

			charge_point_2d<T>& operator =(const charge_point_2d<T>& x)
			{
				charge = x.charge;
				coordinates = x.coordinates;
				return *this;
			}

			charge_point_2d<T>& operator =(charge_point_2d<T>&& x)
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
			scifir::coordinates_2d<T> coordinates;
	};
}

template<typename T,typename U>
bool operator ==(const scifir::charge_point_2d<T>& x,const scifir::charge_point_2d<U>& y)
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
bool operator !=(const scifir::charge_point_2d<T>& x,const scifir::charge_point_2d<U>& y)
{
	return !(x == y);
}

#endif // SCIFIR_UNITS_PHYSICS_CHARGE_POINT_2D_INCLUDED