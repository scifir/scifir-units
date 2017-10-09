#ifndef PHYSICS_BASIC_UNITS_AUTO_VECTOR_HPP_INCLUDED
#define PHYSICS_BASIC_UNITS_AUTO_VECTOR_HPP_INCLUDED

#include "auto_unit.hpp"
#include "vector_unit.hpp"
#include "math/number/angle_number.hpp"

using namespace std;

namespace msci
{
	class auto_vector : public auto_unit, public vector_unit
	{
		public:
			auto_vector(const auto_vector&);
			auto_vector(auto_vector&&);
			explicit auto_vector(const unit&,direction_symbol);
			explicit auto_vector(const unit&,angle_type);
			explicit auto_vector(const unit&,angle_type,angle_type);
			explicit auto_vector(const unit&,msci::angle_container);
			explicit auto_vector(unit&&,direction_symbol);
			explicit auto_vector(unit&&,angle_type);
			explicit auto_vector(unit&&,angle_type,angle_type);
			explicit auto_vector(unit&&,msci::angle_container);
			explicit auto_vector(const unit&,direction_symbol,const string&);
			explicit auto_vector(const unit&,angle_type,const string&);
			explicit auto_vector(const unit&,angle_type,angle_type,const string&);
			explicit auto_vector(const unit&,msci::angle_container,const string&);
			explicit auto_vector(unit&&,direction_symbol,const string&);
			explicit auto_vector(unit&&,angle_type,const string&);
			explicit auto_vector(unit&&,angle_type,angle_type,const string&);
			explicit auto_vector(unit&&,msci::angle_container,const string&);
			explicit auto_vector(const string&,direction_symbol);
			explicit auto_vector(const string&,angle_type);
			explicit auto_vector(const string&,angle_type,angle_type);
			explicit auto_vector(const string&,msci::angle_container);
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
			msci::angle_container new_angles = msci::angle_container();
			new_angles.push_back(directions.angles[0]);
			new_angles.push_back(directions.angles[1]);
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

msci::auto_vector operator +(const msci::scalar_unit&,const msci::vector_unit&);
msci::auto_vector operator -(const msci::scalar_unit&,const msci::vector_unit&);
msci::auto_vector operator *(const msci::scalar_unit&,const msci::vector_unit&);
msci::auto_vector operator +(const msci::scalar_unit&,const msci::auto_unit&);
msci::auto_vector operator -(const msci::scalar_unit&,const msci::auto_unit&);
msci::auto_vector operator *(const msci::scalar_unit&,const msci::auto_unit&);
template<typename T>
msci::auto_vector operator +(const msci::scalar_unit&,const msci::vector_unit_crtp<T>&);
template<typename T>
msci::auto_vector operator -(const msci::scalar_unit&,const msci::vector_unit_crtp<T>&);
template<typename T>
msci::auto_vector operator *(const msci::scalar_unit&,const msci::vector_unit_crtp<T>&);

template<typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_vector operator +(U x,const msci::vector_unit& y)
{
	return msci::auto_vector(y+x,y.get_angles());
}

template<typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_vector operator -(U x,const msci::vector_unit& y)
{
	msci::auto_vector z = y;
	z.invert();
	z = x;
	return msci::auto_vector(z-y);
}

template<typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_vector operator *(U x,const msci::vector_unit& y)
{
	return msci::auto_vector(y*x,y.get_angles());
}

template<typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_vector operator +(U x,const msci::auto_vector& y)
{
	return x + static_cast<const msci::vector_unit&>(y);
}

template<typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_vector operator -(U x,const msci::auto_vector& y)
{
	return x - static_cast<const msci::vector_unit&>(y);
}

template<typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_vector operator *(U x,const msci::auto_vector& y)
{
	return x * static_cast<const msci::vector_unit&>(y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_vector operator +(U x,const msci::vector_unit_crtp<T>& y)
{
	return x + static_cast<const msci::vector_unit&>(y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_vector operator -(U x,const msci::vector_unit_crtp<T>& y)
{
	return x - static_cast<const msci::vector_unit&>(y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_vector operator *(U x,const msci::vector_unit_crtp<T>& y)
{
	return x * static_cast<const msci::vector_unit&>(y);
}

#endif // PHYSICS_BASIC_UNITS_AUTO_VECTOR_HPP_INCLUDED
