#ifndef angle_HPP_INCLUDED
#define angle_HPP_INCLUDED

#include "msci/units/topology/constants.hpp"
#include "msci/units/util/is_number.hpp"
#include "msci/units/units/scalar_unit.hpp"

#include "boost/math/constants/constants.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace msci
{
	inline float radian_to_grade(float x)
	{
		return x * 180 / PI;
	}

	inline float grade_to_radian(float x)
	{
		return x * PI / 180;
	}

	class angle
	{
		public:
			angle();
			angle(float);
			angle(const scalar_unit&);

			virtual angle* clone() const
			{
				return new angle(static_cast<angle const &>(*this));
			}

			operator float() const
			{
				return float(value);
			}

			inline const float& get_value() const
			{
				return value;
			}

			angle operator +(const angle&) const;
			angle operator -(const angle&) const;
			void operator +=(const angle&);
			void operator -=(const angle&);

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator =(T y)
			{
				value = y;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			angle operator +(T y) const
			{
				return angle(value + y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			angle operator -(T y) const
			{
				return angle(value - y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			angle operator *(T y) const
			{
				return angle(value * y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			angle operator /(T y) const
			{
				return angle(value / y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			angle operator ^(T y) const
			{
				return angle(std::pow(value, y));
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

			angle& operator++()
			{
				value++;
				return *clone();
			}

			angle operator++(int)
			{
				angle tmp = *clone();
				operator++();
				return tmp;
			}

			angle& operator--()
			{
				value--;
				return *clone();
			}

			angle operator--(int)
			{
				angle tmp = *clone();
				operator--();
				return tmp;
			}

			void invert();

			inline float get_radian_value() const
			{
				return grade_to_radian(value);
			}

		private:
			float value;

			void normalize_value();
	};

	bool parallel(const angle&, const angle&);
	bool orthogonal(const angle&, const angle&);

	angle sqrt(const angle&);
	angle sqrt_nth(const angle&,int);

	float sin(const angle&);
	float cos(const angle&);
	float tan(const angle&);
	angle asin(float);
	angle acos(float);
	angle atan(float);
	float sinh(const angle&);
	float cosh(const angle&);
	float tanh(const angle&);
	angle asinh(float);
	angle acosh(float);
	angle atanh(float);

	inline float asin_grade(float x)
	{
		return radian_to_grade(std::asin(x));
	}

	inline float acos_grade(float x)
	{
		return radian_to_grade(std::acos(x));
	}

	inline float atan_grade(float x)
	{
		return radian_to_grade(std::atan(x));
	}

	inline float asinh_grade(float x)
	{
		return radian_to_grade(std::asinh(x));
	}

	inline float acosh_grade(float x)
	{
		return radian_to_grade(std::acosh(x));
	}

	inline float atanh_grade(float x)
	{
		return radian_to_grade(std::atanh(x));
	}
}

namespace msci
{
	typedef vector<msci::angle> angle_container;
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::angle operator +(T x, const msci::angle& y)
{
	return msci::angle(x + y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::angle operator -(T x, const msci::angle& y)
{
	return msci::angle(x - y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::angle operator *(T x, const msci::angle& y)
{
	return msci::angle(x * y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::angle operator /(T x, const msci::angle& y)
{
	return msci::angle(x / y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::angle operator ^(T x, const msci::angle& y)
{
	return msci::angle(pow(x, y.get_value()));
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator ==(T x, const msci::angle& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator !=(T x, const msci::angle& y)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <(T x, const msci::angle& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >(T x, const msci::angle& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <=(T x, const msci::angle& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >=(T x, const msci::angle& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator ==(const msci::angle& y, T x)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator !=(const msci::angle& y, T x)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <(const msci::angle& y, T x)
{
	return (y.get_value() < x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >(const msci::angle& y, T x)
{
	return (y.get_value() > x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <=(const msci::angle& y, T x)
{
	return (y.get_value() <= x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >=(const msci::angle& y, T x)
{
	return (y.get_value() >= x);
}

bool operator ==(const msci::angle&, const msci::angle&);
bool operator !=(const msci::angle&, const msci::angle&);
bool operator <(const msci::angle&, const msci::angle&);
bool operator >(const msci::angle&, const msci::angle&);
bool operator <=(const msci::angle&, const msci::angle&);
bool operator >=(const msci::angle&, const msci::angle&);

void operator +=(string&, const msci::angle&);
string operator +(const string&, const msci::angle&);
string operator +(const msci::angle&, const string&);

ostream& operator <<(ostream&, const msci::angle&);
istream& operator >>(istream&, msci::angle&);

#endif // angle_HPP_INCLUDED
