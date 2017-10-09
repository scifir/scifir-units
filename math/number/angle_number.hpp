#ifndef ANGLE_NUMBER_HPP_INCLUDED
#define ANGLE_NUMBER_HPP_INCLUDED

#include "math/constants.hpp"
#include "math/topology/topology.hpp"
#include "informatics/types/is_number.hpp"
#include "physics/basic/units/unit.hpp"

#include "boost/math/constants/constants.hpp"

#include <cmath>
#include <string>
#include <type_traits>

using namespace std;

namespace msci
{
	inline msci::angle_type radian_to_grade(msci::angle_type x)
	{
		return x * 180 / PI;
	}

	inline msci::angle_type grade_to_radian(msci::angle_type x)
	{
		return x * PI / 180;
	}

	class angle_number
	{
		public:
			angle_number();
			angle_number(msci::angle_type);
			angle_number(const unit&);

			virtual angle_number* clone() const
			{
				return new angle_number(static_cast<angle_number const &>(*this));
			}

			operator float() const
			{
				return float(value);
			}

			inline const msci::angle_type& get_value() const
			{
				return value;
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

			void invert();

			inline msci::angle_type get_radian_value() const
			{
				return grade_to_radian(value);
			}

		private:
			msci::angle_type value;

			void normalize_value();
	};

	bool parallel(const angle_number&, const angle_number&);
	bool orthogonal(const angle_number&, const angle_number&);

	angle_number sqrt(const angle_number&);
	angle_number sqrt_nth(const angle_number&,int);

	msci::angle_type sin(const angle_number&);
	msci::angle_type cos(const angle_number&);
	msci::angle_type tan(const angle_number&);
	angle_number asin(msci::angle_type);
	angle_number acos(msci::angle_type);
	angle_number atan(msci::angle_type);
	msci::angle_type sinh(const angle_number&);
	msci::angle_type cosh(const angle_number&);
	msci::angle_type tanh(const angle_number&);
	angle_number asinh(msci::angle_type);
	angle_number acosh(msci::angle_type);
	angle_number atanh(msci::angle_type);

	inline msci::angle_type asin_grade(msci::space_type x)
	{
		return radian_to_grade(std::asin(x));
	}

	inline msci::angle_type acos_grade(msci::space_type x)
	{
		return radian_to_grade(std::acos(x));
	}

	inline msci::angle_type atan_grade(msci::space_type x)
	{
		return radian_to_grade(std::atan(x));
	}

	inline msci::angle_type asinh_grade(msci::space_type x)
	{
		return radian_to_grade(std::asinh(x));
	}

	inline msci::angle_type acosh_grade(msci::space_type x)
	{
		return radian_to_grade(std::acosh(x));
	}

	inline msci::angle_type atanh_grade(msci::space_type x)
	{
		return radian_to_grade(std::atanh(x));
	}
}

namespace msci
{
	typedef vector<msci::angle_number> angle_container;
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::angle_number operator +(T x, const msci::angle_number& y)
{
	return msci::angle_number(x + y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::angle_number operator -(T x, const msci::angle_number& y)
{
	return msci::angle_number(x - y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::angle_number operator *(T x, const msci::angle_number& y)
{
	return msci::angle_number(x * y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::angle_number operator /(T x, const msci::angle_number& y)
{
	return msci::angle_number(x / y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::angle_number operator ^(T x, const msci::angle_number& y)
{
	return msci::angle_number(pow(x, y.get_value()));
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator ==(T x, const msci::angle_number& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator !=(T x, const msci::angle_number& y)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <(T x, const msci::angle_number& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >(T x, const msci::angle_number& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <=(T x, const msci::angle_number& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >=(T x, const msci::angle_number& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator ==(const msci::angle_number& y, T x)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator !=(const msci::angle_number& y, T x)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <(const msci::angle_number& y, T x)
{
	return (y.get_value() < x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >(const msci::angle_number& y, T x)
{
	return (y.get_value() > x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <=(const msci::angle_number& y, T x)
{
	return (y.get_value() <= x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >=(const msci::angle_number& y, T x)
{
	return (y.get_value() >= x);
}

bool operator ==(const msci::angle_number&, const msci::angle_number&);
bool operator !=(const msci::angle_number&, const msci::angle_number&);
bool operator <(const msci::angle_number&, const msci::angle_number&);
bool operator >(const msci::angle_number&, const msci::angle_number&);
bool operator <=(const msci::angle_number&, const msci::angle_number&);
bool operator >=(const msci::angle_number&, const msci::angle_number&);

void operator +=(wstring&, const msci::angle_number&);
wstring operator +(const wstring&, const msci::angle_number&);
wstring operator +(const msci::angle_number&, const wstring&);

wostream& operator <<(wostream&, const msci::angle_number&);
istream& operator >>(istream&, msci::angle_number&);

#endif // ANGLE_NUMBER_HPP_INCLUDED
