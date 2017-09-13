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
			auto_vector(const auto_vector&);
			auto_vector(auto_vector&&);
			explicit auto_vector(const unit&,direction_symbol);
			explicit auto_vector(const unit&,angle_type);
			explicit auto_vector(const unit&,angle_type,angle_type);
			explicit auto_vector(const unit&,math::angle_container);
			explicit auto_vector(unit&&,direction_symbol);
			explicit auto_vector(unit&&,angle_type);
			explicit auto_vector(unit&&,angle_type,angle_type);
			explicit auto_vector(unit&&,math::angle_container);
			explicit auto_vector(const unit&,direction_symbol,string);
			explicit auto_vector(const unit&,angle_type,string);
			explicit auto_vector(const unit&,angle_type,angle_type,string);
			explicit auto_vector(const unit&,math::angle_container,string);
			explicit auto_vector(unit&&,direction_symbol,string);
			explicit auto_vector(unit&&,angle_type,string);
			explicit auto_vector(unit&&,angle_type,angle_type,string);
			explicit auto_vector(unit&&,math::angle_container,string);
			explicit auto_vector(string,direction_symbol);
			explicit auto_vector(string,angle_type);
			explicit auto_vector(string,angle_type,angle_type);
			explicit auto_vector(string,math::angle_container);
			auto_vector(const vector_unit&);
			auto_vector(vector_unit&&);

			auto_vector& operator =(const auto_vector&);
			auto_vector& operator =(auto_vector&&);
			auto_vector& operator =(const vector_unit&);
			auto_vector& operator =(vector_unit&&);
			auto_vector& operator =(const unit&);
			auto_vector& operator =(unit&&);

			auto_vector operator +(const vector_unit&) const;
			auto_vector operator -(const vector_unit&) const;
			void operator +=(const vector_unit&);
			void operator -=(const vector_unit&);

			auto_vector operator *(const scalar_unit&) const;
			auto_vector operator /(const scalar_unit&) const;
			auto_vector operator ^(const scalar_unit&) const;

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator +(U x) const
			{
				return vector_unit::operator+(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator -(U x) const
			{
				return vector_unit::operator-(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator *(U x) const
			{
				return vector_unit::operator*(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator /(U x) const
			{
				return vector_unit::operator/(x);
			}

			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			auto_vector operator ^(U x) const
			{
				return vector_unit::operator^(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator +=(U y)
			{
				vector_unit::operator+=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator -=(U y)
			{
				vector_unit::operator-=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator *=(U y)
			{
				vector_unit::operator*=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator /=(U y)
			{
				vector_unit::operator/=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator ^=(U y)
			{
				vector_unit::operator^=(y);
			}
	};

	template<typename U,typename>
	auto_vector vector_unit::operator +(U y) const
	{
		auto_vector z = *this;
		z += y;
		return z;
	}

	template<typename U,typename>
	auto_vector vector_unit::operator -(U y) const
	{
		auto_vector z = *this;
		z -= y;
		return z;
	}

	template<typename U,typename>
	auto_vector vector_unit::operator *(U y) const
	{
		auto_vector z = *this;
		z *= y;
		return z;
	}

	template<typename U,typename>
	auto_vector vector_unit::operator /(U y) const
	{
		auto_vector z = *this;
		z /= y;
		return z;
	}

	template<typename U,typename>
	auto_vector vector_unit::operator ^(U y) const
	{
		auto_unit new_value = auto_unit(unit::operator^(*this,y));
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

	template<typename T>
	auto_vector vector_unit_crtp<T>::operator +(const vector_unit& x) const
	{
		return vector_unit::operator+(x);
	}

	template<typename T>
	auto_vector vector_unit_crtp<T>::operator -(const vector_unit& x) const
	{
		return vector_unit::operator-(x);
	}

	template<typename T>
	auto_vector vector_unit_crtp<T>::operator *(const scalar_unit& x) const
	{
		return vector_unit::operator*(x);
	}

	template<typename T>
	auto_vector vector_unit_crtp<T>::operator /(const scalar_unit& x) const
	{
		return vector_unit::operator/(x);
	}

	template<typename T>
	auto_vector vector_unit_crtp<T>::operator ^(const scalar_unit& x) const
	{
		return vector_unit::operator^(x);
	}

	template<typename T>
	template<typename U, typename>
	auto_vector vector_unit_crtp<T>::operator +(U y) const
	{
		return vector_unit::operator+(y);
	}

	template<typename T>
	template<typename U, typename>
	auto_vector vector_unit_crtp<T>::operator -(U y) const
	{
		return vector_unit::operator-(y);
	}

	template<typename T>
	template<typename U, typename>
	auto_vector vector_unit_crtp<T>::operator *(U y) const
	{
		return vector_unit::operator*(y);
	}

	template<typename T>
	template<typename U, typename>
	auto_vector vector_unit_crtp<T>::operator /(U y) const
	{
		return vector_unit::operator/(y);
	}

	template<typename T>
	template<typename U, typename>
	auto_vector vector_unit_crtp<T>::operator ^(U y) const
	{
		return vector_unit::operator^(y);
	}
}

physics::units::auto_vector operator +(const physics::units::scalar_unit&,const physics::units::vector_unit&);
physics::units::auto_vector operator -(const physics::units::scalar_unit&,const physics::units::vector_unit&);
physics::units::auto_vector operator *(const physics::units::scalar_unit&,const physics::units::vector_unit&);
physics::units::auto_vector operator +(const physics::units::scalar_unit&,const physics::units::auto_unit&);
physics::units::auto_vector operator -(const physics::units::scalar_unit&,const physics::units::auto_unit&);
physics::units::auto_vector operator *(const physics::units::scalar_unit&,const physics::units::auto_unit&);
template<typename T>
physics::units::auto_vector operator +(const physics::units::scalar_unit&,const physics::units::vector_unit_crtp<T>&);
template<typename T>
physics::units::auto_vector operator -(const physics::units::scalar_unit&,const physics::units::vector_unit_crtp<T>&);
template<typename T>
physics::units::auto_vector operator *(const physics::units::scalar_unit&,const physics::units::vector_unit_crtp<T>&);

template<typename U, typename = typename enable_if<is_number<U>::value>::type>
physics::units::auto_vector operator +(U x,const physics::units::vector_unit& y)
{
	return physics::units::auto_vector(y+x,y.get_angles());
}

template<typename U, typename = typename enable_if<is_number<U>::value>::type>
physics::units::auto_vector operator -(U x,const physics::units::vector_unit& y)
{
	physics::units::auto_vector z = y;
	z.invert();
	z = x;
	return physics::units::auto_vector(z-y);
}

template<typename U, typename = typename enable_if<is_number<U>::value>::type>
physics::units::auto_vector operator *(U x,const physics::units::vector_unit& y)
{
	return physics::units::auto_vector(y*x,y.get_angles());
}

template<typename U, typename = typename enable_if<is_number<U>::value>::type>
physics::units::auto_vector operator +(U x,const physics::units::auto_vector& y)
{
	return x + static_cast<const physics::units::vector_unit&>(y);
}

template<typename U, typename = typename enable_if<is_number<U>::value>::type>
physics::units::auto_vector operator -(U x,const physics::units::auto_vector& y)
{
	return x - static_cast<const physics::units::vector_unit&>(y);
}

template<typename U, typename = typename enable_if<is_number<U>::value>::type>
physics::units::auto_vector operator *(U x,const physics::units::auto_vector& y)
{
	return x * static_cast<const physics::units::vector_unit&>(y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
physics::units::auto_vector operator +(U x,const physics::units::vector_unit_crtp<T>& y)
{
	return x + static_cast<const physics::units::vector_unit&>(y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
physics::units::auto_vector operator -(U x,const physics::units::vector_unit_crtp<T>& y)
{
	return x - static_cast<const physics::units::vector_unit&>(y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
physics::units::auto_vector operator *(U x,const physics::units::vector_unit_crtp<T>& y)
{
	return x * static_cast<const physics::units::vector_unit&>(y);
}

#endif // PHYSICS_BASIC_UNITS_AUTO_VECTOR_HPP_INCLUDED
