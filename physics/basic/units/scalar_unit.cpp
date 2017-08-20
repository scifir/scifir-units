#include "scalar_unit.hpp"
#include "auto_scalar.hpp"

using namespace std;

namespace physics::units
{
	scalar_unit::scalar_unit(math::space_type new_value, string init_value) : unit(new_value, init_value)
	{
	}

	scalar_unit::scalar_unit(string init_value) : unit(init_value)
	{
	}

	scalar_unit::scalar_unit(const unit& new_unit) : unit(new_unit)
	{
	}

	scalar_unit::scalar_unit(const unit& new_value,string init_value) : unit(new_value, init_value)
	{
	}

	void scalar_unit::operator =(const scalar_unit& x)
	{
		if(x.is_defined())
		{
			if(x.equal_dimensions(get_dimensions_match()))
			{
				unit::value = x.get_value();
				unit::actual_dimensions = x.get_actual_dimensions();
			}
			else
			{
				unit::invalidate(7);
			}
		}
		else
		{
			unit::invalidate(1);
		}
	}

	auto_scalar scalar_unit::operator +(const scalar_unit& x) const
	{
		return auto_scalar(unit::operator+(x));
	}

	auto_scalar scalar_unit::operator -(const scalar_unit& x) const
	{
		return auto_scalar(unit::operator-(x));
	}

	auto_scalar scalar_unit::operator *(const scalar_unit& x) const
	{
		return auto_scalar(unit::operator*(x));
	}

	auto_scalar scalar_unit::operator /(const scalar_unit& x) const
	{
		return auto_scalar(unit::operator/(x));
	}

	auto_scalar scalar_unit::operator ^(const scalar_unit& x) const
	{
		return auto_scalar(unit::operator^(x));
	}

	void scalar_unit::operator +=(const scalar_unit& x)
	{
		unit::operator+=(x);
	}

	void scalar_unit::operator -=(const scalar_unit& x)
	{
		unit::operator-=(x);
	}
}
