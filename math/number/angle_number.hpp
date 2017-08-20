#ifndef ANGLE_NUMBER_HPP_INCLUDED
#define ANGLE_NUMBER_HPP_INCLUDED

#include "math/constants.hpp"
#include "math/topology/topology.hpp"
#include "informatics/types/is_number.hpp"

#include "boost/math/constants/constants.hpp"

#include <cmath>
#include <string>
#include <type_traits>

using namespace std;

namespace math
{
	class angle_number
	{
		public:
			angle_number();
			angle_number(math::angle_type);

			virtual angle_number* clone() const
			{
				return new angle_number(static_cast<angle_number const &>(*this));
			}

			operator float() const
			{
				return float(value);
			}

			angle_number operator +(const angle_number&) const;
			angle_number operator -(const angle_number&) const;
			void operator +=(const angle_number&);
			void operator -=(const angle_number&);

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator =(T y)
			{
				value = y;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			angle_number operator +(T y) const
			{
				return angle_number(value + y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			angle_number operator -(T y) const
			{
				return angle_number(value - y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			angle_number operator *(T y) const
			{
				return angle_number(value * y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			angle_number operator /(T y) const
			{
				return angle_number(value / y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			angle_number operator ^(T y) const
			{
				return angle_number(std::pow(value, y));
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator +=(T y)
			{
				value += y;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator -=(T y)
			{
				value -= y;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator *=(T y)
			{
				value *= y;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator /=(T y)
			{
				value /= y;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator ^=(T y)
			{
				value = std::pow(value, y);
				normalize_value();
			}

			angle_number& operator++()
			{
				value++;
				return *clone();
			}

			angle_number operator++(int)
			{
				angle_number tmp = *clone();
				operator++();
				return tmp;
			}

			angle_number& operator--()
			{
				value--;
				return *clone();
			}

			angle_number operator--(int)
			{
				angle_number tmp = *clone();
				operator--();
				return tmp;
			}

			const math::angle_type& get_value() const;

			void invert();

			math::angle_type get_radian_value() const;

		private:
			math::angle_type value;

			void normalize_value();
	};

	bool parallel(const angle_number&, const angle_number&);
	bool orthogonal(const angle_number&, const angle_number&);

	angle_number sqrt(const angle_number&);
	angle_number sqrt_nth(const angle_number&,int);

	math::angle_type sin(const angle_number&);
	math::angle_type cos(const angle_number&);
	math::angle_type tan(const angle_number&);
	angle_number asin(math::angle_type);
	angle_number acos(math::angle_type);
	angle_number atan(math::angle_type);
	math::angle_type sinh(const angle_number&);
	math::angle_type cosh(const angle_number&);
	math::angle_type tanh(const angle_number&);
	angle_number asinh(math::angle_type);
	angle_number acosh(math::angle_type);
	angle_number atanh(math::angle_type);

	inline math::angle_type radian_to_grade(math::angle_type x)
	{
		return x * 180 / PI;
	}

	inline math::angle_type grade_to_radian(math::angle_type x)
	{
		return x * PI / 180;
	}

	inline math::angle_type asin_grade(math::space_type x)
	{
		return radian_to_grade(std::asin(x));
	}

	inline math::angle_type acos_grade(math::space_type x)
	{
		return radian_to_grade(std::acos(x));
	}

	inline math::angle_type atan_grade(math::space_type x)
	{
		return radian_to_grade(std::atan(x));
	}

	inline math::angle_type asinh_grade(math::space_type x)
	{
		return radian_to_grade(std::asinh(x));
	}

	inline math::angle_type acosh_grade(math::space_type x)
	{
		return radian_to_grade(std::acosh(x));
	}

	inline math::angle_type atanh_grade(math::space_type x)
	{
		return radian_to_grade(std::atanh(x));
	}
}

namespace math
{
	typedef vector<math::angle_number> angle_container;
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
math::angle_number operator +(T x, const math::angle_number& y)
{
	return math::angle_number(x + y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
math::angle_number operator -(T x, const math::angle_number& y)
{
	return math::angle_number(x - y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
math::angle_number operator *(T x, const math::angle_number& y)
{
	return math::angle_number(x * y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
math::angle_number operator /(T x, const math::angle_number& y)
{
	return math::angle_number(x / y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
math::angle_number operator ^(T x, const math::angle_number& y)
{
	return math::angle_number(pow(x, y.get_value()));
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator ==(T x, const math::angle_number& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator !=(T x, const math::angle_number& y)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <(T x, const math::angle_number& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >(T x, const math::angle_number& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <=(T x, const math::angle_number& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >=(T x, const math::angle_number& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator ==(const math::angle_number& y, T x)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator !=(const math::angle_number& y, T x)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <(const math::angle_number& y, T x)
{
	return (y.get_value() < x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >(const math::angle_number& y, T x)
{
	return (y.get_value() > x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <=(const math::angle_number& y, T x)
{
	return (y.get_value() <= x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >=(const math::angle_number& y, T x)
{
	return (y.get_value() >= x);
}

bool operator ==(const math::angle_number&, const math::angle_number&);
bool operator !=(const math::angle_number&, const math::angle_number&);
bool operator <(const math::angle_number&, const math::angle_number&);
bool operator >(const math::angle_number&, const math::angle_number&);
bool operator <=(const math::angle_number&, const math::angle_number&);
bool operator >=(const math::angle_number&, const math::angle_number&);

void operator +=(wstring&, const math::angle_number&);
wstring operator +(const wstring&, const math::angle_number&);
wstring operator +(const math::angle_number&, const wstring&);

wostream& operator <<(wostream&, const math::angle_number&);
istream& operator >>(istream&, math::angle_number&);

#endif // ANGLE_NUMBER_HPP_INCLUDED
