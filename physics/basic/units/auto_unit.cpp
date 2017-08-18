#include "auto_unit.hpp"

#include <sstream>

using namespace std;

namespace physics::units
{
	auto_unit::auto_unit(math::topology::space_type new_value, string dimension_structure) : real_dimensions(create_real_dimensions(dimension_structure)),unit(new_value,dimension_structure)
	{
	}

	auto_unit::auto_unit(math::number::unit_number new_value, const vector_real_dimensions& new_real_dimensions, const vector_actual_dimensions& new_actual_dimensions) : real_dimensions(new_real_dimensions),unit(new_value,new_actual_dimensions)
	{
	}

	auto_unit::auto_unit(const unit& new_value) : real_dimensions(new_value.get_real_dimensions()),unit(new_value)
	{
	}

	auto_unit::auto_unit(const unit& new_value,string init_value) : real_dimensions(create_real_dimensions(init_value)),unit(new_value)
	{
		change_dimensions(init_value);
	}

	auto_unit::auto_unit(string init_value) : real_dimensions(create_real_dimensions(initial_dimensions_get_structure(init_value))),unit(init_value)
	{
	}

	auto_unit::auto_unit(const auto_unit& x) : real_dimensions(x.get_real_dimensions()),unit(static_cast<const unit&>(x))
	{
	}

	auto_unit& auto_unit::operator =(const auto_unit& x)
	{
		unit::operator=(x);
	}

	auto_unit& auto_unit::operator =(auto_unit&& x)
	{
		value = move(x.get_value());
		actual_dimensions = move(x.get_actual_dimensions());
	}

	auto_unit& auto_unit::operator =(const unit& x)
	{
		unit::operator=(x);
	}

	string auto_unit::get_dimensions_match() const
	{
		return get_dimension_structure(real_dimensions);
	}

	vector_real_dimensions auto_unit::get_real_dimensions() const
	{
		return real_dimensions;
	}
}
