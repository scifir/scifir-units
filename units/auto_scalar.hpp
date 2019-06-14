#ifndef AUTO_SCALAR_HPP_INCLUDED
#define AUTO_SCALAR_HPP_INCLUDED

#include "msci/units/units/scalar_unit.hpp"

using namespace std;

namespace msci
{
	class auto_scalar: public scalar_unit
	{
		public:
			auto_scalar();
			auto_scalar(const auto_scalar&);
			auto_scalar(auto_scalar&&);
			explicit auto_scalar(msci::space_type, const string& = "");
			explicit auto_scalar(msci::unit_number, const vector_real_dimensions&, const vector_actual_dimensions&);
			explicit auto_scalar(const scalar_unit&,const string&);
			explicit auto_scalar(scalar_unit&&,const string&);
			explicit auto_scalar(const string&);
			auto_scalar(const scalar_unit&);
			auto_scalar(scalar_unit&&);

			virtual scalar_unit* clone() const;

			void initialize_real_dimensions(string);

			virtual string get_dimensions_match() const;
			virtual vector_real_dimensions get_real_dimensions() const;

		private:
			const vector_real_dimensions real_dimensions;
	};

	/*template<typename U, typename>
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
		auto_scalar a = scalar_unit::operator^(y);
		return a;
	}

	template<typename T>
	auto_scalar scalar_unit_crtp<T>::operator +(const scalar_unit& x) const
	{
		return scalar_unit::operator+(x);
	}

	template<typename T>
	auto_scalar scalar_unit_crtp<T>::operator -(const scalar_unit& x) const
	{
		return scalar_unit::operator-(x);
	}

	template<typename T>
	auto_scalar scalar_unit_crtp<T>::operator *(const scalar_unit& x) const
	{
		return scalar_unit::operator*(x);
	}

	template<typename T>
	auto_scalar scalar_unit_crtp<T>::operator /(const scalar_unit& x) const
	{
		return scalar_unit::operator/(x);
	}

	template<typename T>
	auto_scalar scalar_unit_crtp<T>::operator ^(const scalar_unit& x) const
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
	}*/
}

/*template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_scalar operator +(T x, const msci::scalar_unit& y)
{
	return msci::auto_scalar(x + static_cast<const msci::unit&>(y));
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_scalar operator -(T x, const msci::scalar_unit& y)
{
	return msci::auto_scalar(x - static_cast<const msci::unit&>(y));
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_scalar operator *(T x, const msci::scalar_unit& y)
{
	return msci::auto_scalar(x * static_cast<const msci::unit&>(y));
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_scalar operator /(T x, const msci::scalar_unit& y)
{
	return msci::auto_scalar(x / static_cast<const msci::unit&>(y));
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_scalar operator ^(T x, const msci::scalar_unit& y)
{
	return msci::auto_scalar(x ^ static_cast<const msci::unit&>(y));
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_scalar operator +(T x, const msci::auto_scalar& y)
{
	return x + static_cast<const msci::scalar_unit&>(y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_scalar operator -(T x, const msci::auto_scalar& y)
{
	return x - static_cast<const msci::scalar_unit&>(y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_scalar operator *(T x, const msci::auto_scalar& y)
{
	return x * static_cast<const msci::scalar_unit&>(y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_scalar operator /(T x, const msci::auto_scalar& y)
{
	return x / static_cast<const msci::scalar_unit&>(y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_scalar operator ^(T x, const msci::auto_scalar& y)
{
	return x ^ static_cast<const msci::scalar_unit&>(y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_scalar operator +(U x, const msci::scalar_unit_crtp<T>& y)
{
	return x + static_cast<const msci::scalar_unit&>(y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_scalar operator -(U x, const msci::scalar_unit_crtp<T>& y)
{
	return x - static_cast<const msci::scalar_unit&>(y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_scalar operator *(U x, const msci::scalar_unit_crtp<T>& y)
{
	return x * static_cast<const msci::scalar_unit&>(y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_scalar operator /(U x, const msci::scalar_unit_crtp<T>& y)
{
	return x / static_cast<const msci::scalar_unit&>(y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
msci::auto_scalar operator ^(U x, const msci::scalar_unit_crtp<T>& y)
{
	return x ^ static_cast<const msci::scalar_unit&>(y);
}*/

#endif // AUTO_SCALAR_HPP_INCLUDED
