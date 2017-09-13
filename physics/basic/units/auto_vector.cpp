#include "auto_vector.hpp"

using namespace std;

namespace physics::units
{
	auto_vector::auto_vector(const auto_vector& x) : unit(x),auto_unit(x),vector_unit(x)
	{
	}

	auto_vector::auto_vector(auto_vector&& x) : unit(move(x)),auto_unit(move(x)),vector_unit(move(x))
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

	auto_vector::auto_vector(const unit& new_value,math::angle_container new_angles) : unit(new_value),auto_unit(new_value),vector_unit(new_value,new_angles)
	{
	}

	auto_vector::auto_vector(unit&& new_value,direction_symbol new_direction) : unit(move(new_value)),auto_unit(move(new_value)),vector_unit(move(new_value),new_direction)
	{
	}

	auto_vector::auto_vector(unit&& new_value,angle_type new_angle1) : unit(move(new_value)),auto_unit(move(new_value)),vector_unit(move(new_value),new_angle1)
	{
	}

	auto_vector::auto_vector(unit&& new_value,angle_type new_angle1,angle_type new_angle2) : unit(move(new_value)),auto_unit(move(new_value)),vector_unit(move(new_value),new_angle1,new_angle2)
	{
	}

	auto_vector::auto_vector(unit&& new_value,math::angle_container new_angles) : unit(move(new_value)),auto_unit(move(new_value)),vector_unit(move(new_value),new_angles)
	{
	}

	auto_vector::auto_vector(const unit& new_value,direction_symbol new_direction, string init_value) : unit(new_value,init_value),auto_unit(new_value,init_value),vector_unit(new_value,new_direction,init_value)
	{
	}

	auto_vector::auto_vector(const unit& new_value,angle_type new_angle1, string init_value) : unit(new_value,init_value),auto_unit(new_value,init_value),vector_unit(new_value,new_angle1,init_value)
	{
	}

	auto_vector::auto_vector(const unit& new_value,angle_type new_angle1,angle_type new_angle2, string init_value) : unit(new_value,init_value),auto_unit(new_value,init_value),vector_unit(new_value,new_angle1,new_angle2,init_value)
	{
	}

	auto_vector::auto_vector(const unit& new_value,math::angle_container new_angles, string init_value) : unit(new_value,init_value),auto_unit(new_value,init_value),vector_unit(new_value,new_angles,init_value)
	{
	}

	auto_vector::auto_vector(unit&& new_value,direction_symbol new_direction, string init_value) : unit(move(new_value),init_value),auto_unit(move(new_value),init_value),vector_unit(move(new_value),new_direction,init_value)
	{
	}

	auto_vector::auto_vector(unit&& new_value,angle_type new_angle1, string init_value) : unit(move(new_value),init_value),auto_unit(move(new_value),init_value),vector_unit(move(new_value),new_angle1,init_value)
	{
	}

	auto_vector::auto_vector(unit&& new_value,angle_type new_angle1,angle_type new_angle2, string init_value) : unit(move(new_value),init_value),auto_unit(move(new_value),init_value),vector_unit(move(new_value),new_angle1,new_angle2,init_value)
	{
	}

	auto_vector::auto_vector(unit&& new_value,math::angle_container new_angles, string init_value) : unit(move(new_value),init_value),auto_unit(move(new_value),init_value),vector_unit(move(new_value),new_angles,init_value)
	{
	}

	auto_vector::auto_vector(string init_value,direction_symbol new_direction) : unit(init_value),auto_unit(init_value),vector_unit(init_value,new_direction)
	{
	}

	auto_vector::auto_vector(string init_value,angle_type new_angle1) : unit(init_value),auto_unit(init_value),vector_unit(init_value,new_angle1)
	{
	}

	auto_vector::auto_vector(string init_value,angle_type new_angle1,angle_type new_angle2) : unit(init_value),auto_unit(init_value),vector_unit(init_value,new_angle1,new_angle2)
	{
	}

	auto_vector::auto_vector(string init_value,math::angle_container new_angles) : unit(init_value),auto_unit(init_value),vector_unit(init_value,new_angles)
	{
	}

	auto_vector::auto_vector(const vector_unit& x) : unit(x),auto_unit(x),vector_unit(x)
	{
	}

	auto_vector::auto_vector(vector_unit&& x) : unit(move(x)),auto_unit(move(x)),vector_unit(move(x))
	{
	}

	auto_vector& auto_vector::operator =(const auto_vector& x)
	{
		vector_unit::operator=(x);
		return *this;
	}

	auto_vector& auto_vector::operator =(auto_vector&& x)
	{
		vector_unit::operator=(move(x));
		return *this;
	}

	auto_vector& auto_vector::operator =(const vector_unit& x)
	{
		vector_unit::operator=(x);
		return *this;
	}

	auto_vector& auto_vector::operator =(vector_unit&& x)
	{
		vector_unit::operator=(move(x));
		return *this;
	}

	auto_vector& auto_vector::operator =(const unit& x)
	{
		unit::operator=(x);
		return *this;
	}

	auto_vector& auto_vector::operator =(unit&& x)
	{
		unit::operator=(move(x));
		return *this;
	}

	auto_vector auto_vector::operator +(const vector_unit& x) const
	{
		return vector_unit::operator+(x);
	}

	auto_vector auto_vector::operator -(const vector_unit& x) const
	{
		return vector_unit::operator-(x);
	}

	void auto_vector::operator +=(const vector_unit& x)
	{
		vector_unit::operator+=(x);
	}

	void auto_vector::operator -=(const vector_unit& x)
	{
		vector_unit::operator-=(x);
	}

	auto_vector auto_vector::operator *(const scalar_unit& x) const
	{
		return vector_unit::operator*(x);
	}

	auto_vector auto_vector::operator /(const scalar_unit& x) const
	{
		return vector_unit::operator/(x);
	}

	auto_vector auto_vector::operator ^(const scalar_unit& x) const
	{
		return vector_unit::operator^(x);
	}
}

physics::units::auto_vector operator +(const physics::units::scalar_unit& x,const physics::units::vector_unit& y)
{
	physics::units::auto_vector z = physics::units::auto_vector(x,y.get_angles());
	return z + y;
}

physics::units::auto_vector operator -(const physics::units::scalar_unit& x,const physics::units::vector_unit& y)
{
	physics::units::auto_vector z = physics::units::auto_vector(x,y.get_angles());
	return z - y;
}

physics::units::auto_vector operator *(const physics::units::scalar_unit& x,const physics::units::vector_unit& y)
{
	return y * x;
}

physics::units::auto_vector operator +(const physics::units::scalar_unit& x,const physics::units::auto_unit& y)
{
	return x + dynamic_cast<const physics::units::vector_unit&>(y);
}

physics::units::auto_vector operator -(const physics::units::scalar_unit& x,const physics::units::auto_unit& y)
{
	return x - dynamic_cast<const physics::units::vector_unit&>(y);
}

physics::units::auto_vector operator *(const physics::units::scalar_unit& x,const physics::units::auto_unit& y)
{
	return x * dynamic_cast<const physics::units::vector_unit&>(y);
}

template<typename T>
physics::units::auto_vector operator +(const physics::units::scalar_unit& x,const physics::units::vector_unit_crtp<T>& y)
{
	return x + dynamic_cast<const physics::units::vector_unit&>(y);
}

template<typename T>
physics::units::auto_vector operator -(const physics::units::scalar_unit& x,const physics::units::vector_unit_crtp<T>& y)
{
	return x - dynamic_cast<const physics::units::vector_unit&>(y);
}

template<typename T>
physics::units::auto_vector operator *(const physics::units::scalar_unit& x,const physics::units::vector_unit_crtp<T>& y)
{
	return x * dynamic_cast<const physics::units::vector_unit&>(y);
}
