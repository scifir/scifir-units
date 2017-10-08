#include "scalar_unit.hpp"
#include "auto_scalar.hpp"

using namespace std;

namespace msci::units
{
	scalar_unit::scalar_unit() : unit()
	{
	}

	scalar_unit::scalar_unit(const scalar_unit& x) : unit(x)
	{
	}

	scalar_unit::scalar_unit(scalar_unit&& x) : unit(move(x))
	{
	}

	scalar_unit::scalar_unit(msci::space_type new_value, const string& init_value) : unit(new_value, init_value)
	{
	}

	scalar_unit::scalar_unit(msci::unit_number new_value, const vector_actual_dimensions& new_actual_dimensions) : unit(new_value,new_actual_dimensions)
	{
	}

	scalar_unit::scalar_unit(const string& init_value) : unit(init_value)
	{
	}

	scalar_unit::scalar_unit(const unit& new_value,const string& init_value) : unit(new_value, init_value)
	{
	}

	scalar_unit::scalar_unit(unit&& new_value,const string& init_value) : unit(move(new_value), init_value)
	{
	}

	scalar_unit::scalar_unit(const unit& x) : unit(x)
	{
	}

	scalar_unit::scalar_unit(unit&& x) : unit(move(x))
	{
	}

	scalar_unit& scalar_unit::operator =(const scalar_unit& x)
	{
		unit::operator=(x);
		return *this;
	}

	scalar_unit& scalar_unit::operator =(scalar_unit&& x)
	{
		unit::operator=(move(x));
		return *this;
	}

	scalar_unit& scalar_unit::operator =(const unit& x)
	{
		unit::operator=(x);
		return *this;
	}

	scalar_unit& scalar_unit::operator =(unit&& x)
	{
		unit::operator=(move(x));
		return *this;
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
