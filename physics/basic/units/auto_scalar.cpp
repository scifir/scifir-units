#include "auto_scalar.hpp"

#include <iostream>

using namespace std;

namespace physics::units
{
	auto_scalar::auto_scalar(const auto_scalar& x) : unit(x),auto_unit(x),scalar_unit(x)
	{
	}

	auto_scalar::auto_scalar(auto_scalar&& x) : unit(move(x)),auto_unit(move(x)),scalar_unit(move(x))
	{
	}

	auto_scalar::auto_scalar(math::space_type new_value, string dimension_structure) : unit(new_value,dimension_structure),auto_unit(new_value,dimension_structure),scalar_unit(new_value,dimension_structure)
	{
	}

	auto_scalar::auto_scalar(math::unit_number new_value, const vector_real_dimensions& new_real_dimensions, const vector_actual_dimensions& new_actual_dimensions) : unit(new_value,new_actual_dimensions),auto_unit(new_value,new_real_dimensions,new_actual_dimensions),scalar_unit(new_value,new_actual_dimensions)
	{
	}

	auto_scalar::auto_scalar(const unit& new_value,string init_value) : unit(new_value,init_value),auto_unit(new_value,init_value),scalar_unit(new_value,init_value)
	{
	}

	auto_scalar::auto_scalar(unit&& new_value,string init_value) : unit(move(new_value),init_value),auto_unit(move(new_value),init_value),scalar_unit(move(new_value),init_value)
	{
	}

	auto_scalar::auto_scalar(string init_value) : unit(init_value),auto_unit(init_value),scalar_unit(init_value)
	{
	}

	auto_scalar::auto_scalar(const unit& x) : unit(x),auto_unit(x),scalar_unit(x)
	{
	}

	auto_scalar::auto_scalar(unit&& x) : unit(move(x)),auto_unit(move(x)),scalar_unit(move(x))
	{
	}

	auto_scalar& auto_scalar::operator =(const auto_scalar& x)
	{
		scalar_unit::operator=(x);
		return *this;
	}

	auto_scalar& auto_scalar::operator =(auto_scalar&& x)
	{
		scalar_unit::operator=(move(x));
		return *this;
	}

	auto_scalar& auto_scalar::operator =(const unit& x)
	{
		scalar_unit::operator=(x);
		return *this;
	}

	auto_scalar& auto_scalar::operator =(unit&& x)
	{
		scalar_unit::operator=(move(x));
		return *this;
	}

	auto_scalar auto_scalar::operator +(const scalar_unit& x) const
	{
		return scalar_unit::operator+(x);
	}

	auto_scalar auto_scalar::operator -(const scalar_unit& x) const
	{
		return scalar_unit::operator-(x);
	}

	auto_scalar auto_scalar::operator *(const scalar_unit& x) const
	{
		return scalar_unit::operator*(x);
	}

	auto_scalar auto_scalar::operator /(const scalar_unit& x) const
	{
		return scalar_unit::operator/(x);
	}

	auto_scalar auto_scalar::operator ^(const scalar_unit& x) const
	{
		return scalar_unit::operator^(x);
	}

	void auto_scalar::operator +=(const scalar_unit& x)
	{
		scalar_unit::operator+=(x);
	}

	void auto_scalar::operator -=(const scalar_unit& x)
	{
		scalar_unit::operator-=(x);
	}
}
