#ifndef PHYSICS_BASIC_UNITS_AUTO_UNIT_HPP_INCLUDED
#define PHYSICS_BASIC_UNITS_AUTO_UNIT_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"

using namespace std;

namespace physics::units
{
	class auto_unit : public virtual unit
	{
		public:
			auto_unit(const auto_unit&);
			auto_unit(auto_unit&&);
			explicit auto_unit(math::space_type, string = "");
			explicit auto_unit(math::unit_number, const vector_real_dimensions&, const vector_actual_dimensions&);
			explicit auto_unit(const unit&,string);
			explicit auto_unit(unit&&,string);
			explicit auto_unit(string);
			auto_unit(const unit&);
			auto_unit(unit&&);

			auto_unit& operator =(const auto_unit&);
			auto_unit& operator =(auto_unit&&);
			auto_unit& operator =(const unit&);
			auto_unit& operator =(unit&&);

			virtual unit* clone() const;

			vector_real_dimensions initialize_real_dimensions(string);

			virtual string get_dimensions_match() const;
			virtual vector_real_dimensions get_real_dimensions() const;

		private:
			const vector_real_dimensions real_dimensions;
	};

	template<typename T, typename>
	auto_unit unit::operator +(T y) const
	{
		auto_unit z = *this;
		z += y;
		return move(z);
	}

	template<typename T, typename>
	auto_unit unit::operator -(T y) const
	{
		auto_unit z = *this;
		z -= y;
		return move(z);
	}

	template<typename T, typename>
	auto_unit unit::operator *(T y) const
	{
		auto_unit z = *this;
		z *= y;
		return move(z);
	}

	template<typename T, typename>
	auto_unit unit::operator /(T y) const
	{
		auto_unit z = *this;
		z /= y;
		return move(z);
	}

	template<typename T, typename>
	auto_unit unit::operator ^(T y) const
	{
		math::unit_number new_value = value ^ y;
		vector_real_dimensions new_real_dimensions = power_real_dimensions(get_real_dimensions(),y);
		vector_actual_dimensions new_actual_dimensions = power_actual_dimensions(actual_dimensions,y);
		return move(auto_unit(new_value, new_real_dimensions, new_actual_dimensions));
	}
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
physics::units::auto_unit operator +(T x, const physics::units::unit& y)
{
	math::unit_number new_value = y.get_value();
	physics::units::vector_real_dimensions new_real_dimensions = y.get_real_dimensions();
	physics::units::vector_actual_dimensions new_actual_dimensions = y.get_actual_dimensions();
	return physics::units::auto_unit(x + new_value, new_real_dimensions, new_actual_dimensions);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
physics::units::auto_unit operator -(T x, const physics::units::unit& y)
{
	math::unit_number new_value = y.get_value();
	physics::units::vector_real_dimensions new_real_dimensions = y.get_real_dimensions();
	physics::units::vector_actual_dimensions new_actual_dimensions = y.get_actual_dimensions();
	return physics::units::auto_unit(x - new_value, new_real_dimensions, new_actual_dimensions);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
physics::units::auto_unit operator *(T x, const physics::units::unit& y)
{
	math::unit_number new_value = y.get_value();
	physics::units::vector_real_dimensions new_real_dimensions = y.get_real_dimensions();
	physics::units::vector_actual_dimensions new_actual_dimensions = y.get_actual_dimensions();
	return physics::units::auto_unit(x * new_value, new_real_dimensions, new_actual_dimensions);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
physics::units::auto_unit operator /(T x, const physics::units::unit& y)
{
	math::unit_number new_value = y.get_value();
	physics::units::vector_real_dimensions new_real_dimensions = power_real_dimensions(y.get_real_dimensions(),-1);
	physics::units::vector_actual_dimensions new_actual_dimensions = power_actual_dimensions(y.get_actual_dimensions(),-1);
	return physics::units::auto_unit(x / new_value, new_real_dimensions, new_actual_dimensions);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
physics::units::auto_unit operator ^(T x, const physics::units::unit& y)
{
	if (y.empty_dimensions())
	{
		math::unit_number new_value = y.get_value();
		physics::units::vector_real_dimensions new_real_dimensions = power_real_dimensions(y.get_real_dimensions(),new_value);
		physics::units::vector_actual_dimensions new_actual_dimensions = power_actual_dimensions(y.get_actual_dimensions(),new_value);
		return physics::units::auto_unit(x ^ new_value, new_real_dimensions, new_actual_dimensions);
	}
	else
	{
		physics::units::auto_unit y = physics::units::auto_unit(0);
		y.invalidate(10);
		return move(y);
	}
}

#endif // PHYSICS_BASIC_UNITS_AUTO_UNIT_HPP_INCLUDED
