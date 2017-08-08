#include "auto_vector.hpp"

using namespace std;

namespace physics::units
{
	auto_vector::auto_vector(const unit& new_value) : unit(new_value),auto_unit(new_value),vector_unit(new_value)
	{
	}

	auto_vector::auto_vector(const unit& new_value,direction_symbol new_direction) : unit(new_value),auto_unit(new_value),vector_unit(new_value,new_direction)
	{
	}

	auto_vector::auto_vector(const unit& new_value,angle_type new_angle1) : unit(new_value),auto_unit(new_value),vector_unit(new_value,new_angle1)
	{
	}

	auto_vector::auto_vector(const unit& new_value,angle_type new_angle1,angle_type new_angle2) : unit(new_value),auto_unit(new_value),vector_unit(new_value,new_angle1,new_angle2)
	{
	}

	auto_vector::auto_vector(const unit& new_value,math::topology::angle_container new_angles) : unit(new_value),auto_unit(new_value),vector_unit(new_value,new_angles)
	{
	}

	auto_vector::auto_vector(string init_value) : unit(init_value),auto_unit(init_value),vector_unit(init_value)
	{
	}

	auto_vector::auto_vector(string init_value,angle_type new_angle1) : unit(init_value),auto_unit(init_value),vector_unit(init_value,new_angle1)
	{
	}

	auto_vector::auto_vector(string init_value,angle_type new_angle1,angle_type new_angle2) : unit(init_value),auto_unit(init_value),vector_unit(init_value,new_angle1,new_angle2)
	{
	}

	auto_vector::auto_vector(string init_value,math::topology::angle_container new_angles) : unit(init_value),auto_unit(init_value),vector_unit(init_value,new_angles)
	{
	}

	auto_vector::auto_vector(const vector_unit& x) : unit(x),auto_unit(x),vector_unit(x)
	{
	}
}
