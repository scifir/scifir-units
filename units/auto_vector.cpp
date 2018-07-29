#include "auto_vector.hpp"

using namespace std;

namespace msci
{
	auto_vector::auto_vector() : unit(),auto_unit(),vector_unit()
	{
	}

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

	auto_vector::auto_vector(const unit& new_value,msci::angle_container new_angles) : unit(new_value),auto_unit(new_value),vector_unit(new_value,new_angles)
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

	auto_vector::auto_vector(unit&& new_value,msci::angle_container new_angles) : unit(move(new_value)),auto_unit(move(new_value)),vector_unit(move(new_value),new_angles)
	{
	}

	auto_vector::auto_vector(const unit& new_value,direction_symbol new_direction, const string& init_value) : unit(new_value,init_value),auto_unit(new_value,init_value),vector_unit(new_value,new_direction,init_value)
	{
	}

	auto_vector::auto_vector(const unit& new_value,angle_type new_angle1, const string& init_value) : unit(new_value,init_value),auto_unit(new_value,init_value),vector_unit(new_value,new_angle1,init_value)
	{
	}

	auto_vector::auto_vector(const unit& new_value,angle_type new_angle1,angle_type new_angle2, const string& init_value) : unit(new_value,init_value),auto_unit(new_value,init_value),vector_unit(new_value,new_angle1,new_angle2,init_value)
	{
	}

	auto_vector::auto_vector(const unit& new_value,msci::angle_container new_angles, const string& init_value) : unit(new_value,init_value),auto_unit(new_value,init_value),vector_unit(new_value,new_angles,init_value)
	{
	}

	auto_vector::auto_vector(unit&& new_value,direction_symbol new_direction, const string& init_value) : unit(move(new_value),init_value),auto_unit(move(new_value),init_value),vector_unit(move(new_value),new_direction,init_value)
	{
	}

	auto_vector::auto_vector(unit&& new_value,angle_type new_angle1, const string& init_value) : unit(move(new_value),init_value),auto_unit(move(new_value),init_value),vector_unit(move(new_value),new_angle1,init_value)
	{
	}

	auto_vector::auto_vector(unit&& new_value,angle_type new_angle1,angle_type new_angle2, const string& init_value) : unit(move(new_value),init_value),auto_unit(move(new_value),init_value),vector_unit(move(new_value),new_angle1,new_angle2,init_value)
	{
	}

	auto_vector::auto_vector(unit&& new_value,msci::angle_container new_angles, const string& init_value) : unit(move(new_value),init_value),auto_unit(move(new_value),init_value),vector_unit(move(new_value),new_angles,init_value)
	{
	}

	auto_vector::auto_vector(const string& init_value,direction_symbol new_direction) : unit(init_value),auto_unit(init_value),vector_unit(init_value,new_direction)
	{
	}

	auto_vector::auto_vector(const string& init_value,angle_type new_angle1) : unit(init_value),auto_unit(init_value),vector_unit(init_value,new_angle1)
	{
	}

	auto_vector::auto_vector(const string& init_value,angle_type new_angle1,angle_type new_angle2) : unit(init_value),auto_unit(init_value),vector_unit(init_value,new_angle1,new_angle2)
	{
	}

	auto_vector::auto_vector(const string& init_value,msci::angle_container new_angles) : unit(init_value),auto_unit(init_value),vector_unit(init_value,new_angles)
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

msci::auto_vector operator +(const msci::scalar_unit& x,const msci::vector_unit& y)
{
	msci::auto_vector z = msci::auto_vector(x,y.get_angles());
	return z + y;
}

msci::auto_vector operator -(const msci::scalar_unit& x,const msci::vector_unit& y)
{
	msci::auto_vector z = msci::auto_vector(x,y.get_angles());
	return z - y;
}

msci::auto_vector operator *(const msci::scalar_unit& x,const msci::vector_unit& y)
{
	return y * x;
}

msci::auto_vector operator +(const msci::scalar_unit& x,const msci::auto_unit& y)
{
	return x + dynamic_cast<const msci::vector_unit&>(y);
}

msci::auto_vector operator -(const msci::scalar_unit& x,const msci::auto_unit& y)
{
	return x - dynamic_cast<const msci::vector_unit&>(y);
}

msci::auto_vector operator *(const msci::scalar_unit& x,const msci::auto_unit& y)
{
	return x * dynamic_cast<const msci::vector_unit&>(y);
}

template<typename T>
msci::auto_vector operator +(const msci::scalar_unit& x,const msci::vector_unit_crtp<T>& y)
{
	return x + dynamic_cast<const msci::vector_unit&>(y);
}

template<typename T>
msci::auto_vector operator -(const msci::scalar_unit& x,const msci::vector_unit_crtp<T>& y)
{
	return x - dynamic_cast<const msci::vector_unit&>(y);
}

template<typename T>
msci::auto_vector operator *(const msci::scalar_unit& x,const msci::vector_unit_crtp<T>& y)
{
	return x * dynamic_cast<const msci::vector_unit&>(y);
}
