#ifndef AUTO_SCALAR_HPP_INCLUDED
#define AUTO_SCALAR_HPP_INCLUDED

#include "auto_unit.hpp"
#include "scalar_unit.hpp"

using namespace std;

namespace physics::units
{
	class auto_scalar : public auto_unit, public scalar_unit
	{
		public:
			explicit auto_scalar(math::topology::space_type, string = "");
			explicit auto_scalar(const unit&,string);
			explicit auto_scalar(string);
			auto_scalar(const auto_unit&);
			auto_scalar(const unit&);

			auto_scalar& operator =(const auto_unit&);
			auto_scalar& operator =(auto_unit&&);
			auto_scalar& operator =(const unit&);

			void operator =(const scalar_unit&);
			auto_scalar operator +(const scalar_unit&) const;
			auto_scalar operator -(const scalar_unit&) const;
			auto_scalar operator *(const scalar_unit&) const;
			auto_scalar operator /(const scalar_unit&) const;
			auto_scalar operator ^(const scalar_unit&) const;
			void operator +=(const scalar_unit&);
			void operator -=(const scalar_unit&);

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_scalar operator +(U x) const
			{
				return scalar_unit::operator+(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_scalar operator -(U x) const
			{
				return scalar_unit::operator-(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_scalar operator *(U x) const
			{
				return scalar_unit::operator*(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_scalar operator /(U x) const
			{
				return scalar_unit::operator/(x);
			}

			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			auto_scalar operator ^(U x) const
			{
				return scalar_unit::operator^(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator +=(U y)
			{
				scalar_unit::operator+=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator -=(U y)
			{
				scalar_unit::operator-=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator *=(U y)
			{
				scalar_unit::operator*=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator /=(U y)
			{
				scalar_unit::operator/=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator ^=(U y)
			{
				scalar_unit::operator^=(y);
			}
	};

	template<typename U, typename>
	auto_scalar scalar_unit::operator +(U y) const
	{
		auto_scalar z = *this;
		z += y;
		return z;
	}

	template<typename U, typename>
	auto_scalar scalar_unit::operator -(U y) const
	{
		auto_scalar z = *this;
		z -= y;
		return z;
	}

	template<typename U, typename>
	auto_scalar scalar_unit::operator *(U y) const
	{
		auto_scalar z = *this;
		z *= y;
		return z;
	}

	template<typename U, typename>
	auto_scalar scalar_unit::operator /(U y) const
	{
		auto_scalar z = *this;
		z /= y;
		return z;
	}

	template<typename U, typename>
	auto_scalar scalar_unit::operator ^(U y) const
	{
		auto_scalar a = unit::operator^(y);
		return a;
	}

	template<typename T>
	template<typename U>
	auto_scalar scalar_unit_crtp<T>::operator +(const scalar_unit_crtp<U>& x) const
	{
		return scalar_unit::operator+(x);
	}

	template<typename T>
	template<typename U>
	auto_scalar scalar_unit_crtp<T>::operator -(const scalar_unit_crtp<U>& x) const
	{
		return scalar_unit::operator-(x);
	}

	template<typename T>
	template<typename U>
	auto_scalar scalar_unit_crtp<T>::operator *(const scalar_unit_crtp<U>& x) const
	{
		return scalar_unit::operator*(x);
	}

	template<typename T>
	template<typename U>
	auto_scalar scalar_unit_crtp<T>::operator /(const scalar_unit_crtp<U>& x) const
	{
		return scalar_unit::operator/(x);
	}

	template<typename T>
	template<typename U>
	auto_scalar scalar_unit_crtp<T>::operator ^(const scalar_unit_crtp<U>& x) const
	{
		return scalar_unit::operator^(x);
	}

	template<typename T>
	template<typename U, typename>
	auto_scalar scalar_unit_crtp<T>::operator +(U y) const
	{
		return scalar_unit::operator+(y);
	}

	template<typename T>
	template<typename U, typename>
	auto_scalar scalar_unit_crtp<T>::operator -(U y) const
	{
		return scalar_unit::operator-(y);
	}

	template<typename T>
	template<typename U, typename>
	auto_scalar scalar_unit_crtp<T>::operator *(U y) const
	{
		return scalar_unit::operator*(y);
	}

	template<typename T>
	template<typename U, typename>
	auto_scalar scalar_unit_crtp<T>::operator /(U y) const
	{
		return scalar_unit::operator/(y);
	}

	template<typename T>
	template<typename U, typename>
	auto_scalar scalar_unit_crtp<T>::operator ^(U y) const
	{
		return scalar_unit::operator^(y);
	}
}

#endif // AUTO_SCALAR_HPP_INCLUDED
