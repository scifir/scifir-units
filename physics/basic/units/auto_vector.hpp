#ifndef PHYSICS_BASIC_UNITS_AUTO_VECTOR_HPP_INCLUDED
#define PHYSICS_BASIC_UNITS_AUTO_VECTOR_HPP_INCLUDED

#include "auto_unit.hpp"
#include "vector_unit.hpp"
#include "math/number/angle_number.hpp"

using namespace std;

namespace physics::units
{
	class auto_vector : public auto_unit, public vector_unit
	{
		public:
			auto_vector(const unit&);
			explicit auto_vector(const unit&,direction_symbol);
			explicit auto_vector(const unit&,angle_type);
			explicit auto_vector(const unit&,angle_type,angle_type);
			explicit auto_vector(const unit&,math::topology::angle_container);
			explicit auto_vector(string);
			explicit auto_vector(string,angle_type);
			explicit auto_vector(string,angle_type,angle_type);
			explicit auto_vector(string,math::topology::angle_container);
			auto_vector(const vector_unit&);
	};

	template<typename U,typename>
	auto_vector vector_unit::operator +(U y)
	{
		auto_vector z = *this;
		z += y;
		return z;
	}

	template<typename U,typename>
	auto_vector vector_unit::operator -(U y)
	{
		auto_vector z = *this;
		z -= y;
		return z;
	}

	template<typename U,typename>
	auto_vector vector_unit::operator *(U y)
	{
		auto_vector z = *this;
		z *= y;
		return z;
	}

	template<typename U,typename>
	auto_vector vector_unit::operator /(U y)
	{
		auto_vector z = *this;
		z /= y;
		return z;
	}

	template<typename U,typename>
	auto_vector vector_unit::operator ^(U y)
	{
		auto_unit new_value = auto_unit(float(unit::value ^ y));
		if (is_1d())
		{
			return auto_vector(new_value, get_direction());
		}
		else
		{
			list<angle_type> new_angles = list<angle_type>();
			new_angles.push_back(float(directions.angles[0]));
			new_angles.push_back(float(directions.angles[1]));
			return auto_vector(new_value, new_angles);
		}
	}
}

#endif // PHYSICS_BASIC_UNITS_AUTO_VECTOR_HPP_INCLUDED
