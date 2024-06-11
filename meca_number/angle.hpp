#ifndef SCIFIR_UNITS_MECA_NUMBER_ANGLE_HPP_INCLUDED
#define SCIFIR_UNITS_MECA_NUMBER_ANGLE_HPP_INCLUDED

#include "../topology/constants.hpp"
#include "../util/is_number.hpp"
#include "../units/scalar_unit.hpp"

#include "boost/math/constants/constants.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace scifir
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
			angle(const angle&);
			angle(angle&&);
			explicit angle(float);
			explicit angle(double);
			explicit angle(long double);
			explicit angle(int);
			explicit angle(string);
			explicit angle(const scalar_unit&);

			angle& operator=(const angle&);
			angle& operator=(angle&&);
			angle& operator=(float);
			angle& operator=(string);
			angle& operator=(const scalar_unit&);

			explicit operator float() const
			{
				return float(value);
			}

			inline const float& get_value() const
			{
				return value;
			}

			angle operator +(const angle&) const;
			angle operator -(const angle&) const;
			angle operator *(const angle&) const;
			angle operator /(const angle&) const;
			angle operator ^(const angle&) const;
			void operator +=(const angle&);
			void operator -=(const angle&);
			void operator *=(const angle&);
			void operator /=(const angle&);
			void operator ^=(const angle&);

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator =(T y)
			{
				value = float(y);
				normalize_value();
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			angle operator +(T y) const
			{
				return angle(value + y);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			angle operator -(T y) const
			{
				return angle(value - y);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			angle operator *(T y) const
			{
				return angle(value * y);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			angle operator /(T y) const
			{
				return angle(value / y);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			angle operator ^(T y) const
			{
				return angle(std::pow(value, y));
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator +=(T y)
			{
				value += y;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator -=(T y)
			{
				value -= y;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator *=(T y)
			{
				value *= y;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator /=(T y)
			{
				value /= y;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator ^=(T y)
			{
				value = std::pow(value, y);
				normalize_value();
			}

			angle& operator++();
			angle operator++(int);
			angle& operator--();
			angle operator--(int);

			void invert();

			string display(int = 2) const;

			inline float get_grade() const
			{
				return value;
			}

			inline float get_radian() const
			{
				return grade_to_radian(value);
			}

		private:
			float value;

			void normalize_value();
	};

	string to_string(const angle&);
	bool is_angle(const string&);
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

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::angle operator +(T x, const scifir::angle& y)
{
	return scifir::angle(x + y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::angle operator -(T x, const scifir::angle& y)
{
	return scifir::angle(x - y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::angle operator *(T x, const scifir::angle& y)
{
	return scifir::angle(x * y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::angle operator /(T x, const scifir::angle& y)
{
	return scifir::angle(x / y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::angle operator ^(T x, const scifir::angle& y)
{
	return scifir::angle(pow(x, y.get_value()));
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(T x, const scifir::angle& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(T x, const scifir::angle& y)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(T x, const scifir::angle& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(T x, const scifir::angle& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(T x, const scifir::angle& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(T x, const scifir::angle& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(const scifir::angle& y, T x)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(const scifir::angle& y, T x)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(const scifir::angle& y, T x)
{
	return (y.get_value() < x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(const scifir::angle& y, T x)
{
	return (y.get_value() > x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(const scifir::angle& y, T x)
{
	return (y.get_value() <= x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(const scifir::angle& y, T x)
{
	return (y.get_value() >= x);
}

bool operator ==(const scifir::angle&, const scifir::angle&);
bool operator !=(const scifir::angle&, const scifir::angle&);
bool operator <(const scifir::angle&, const scifir::angle&);
bool operator >(const scifir::angle&, const scifir::angle&);
bool operator <=(const scifir::angle&, const scifir::angle&);
bool operator >=(const scifir::angle&, const scifir::angle&);

bool operator ==(const scifir::angle&, const string&);
bool operator !=(const scifir::angle&, const string&);

bool operator ==(const string&, const scifir::angle&);
bool operator !=(const string&, const scifir::angle&);

void operator +=(string&, const scifir::angle&);
string operator +(const string&, const scifir::angle&);
string operator +(const scifir::angle&, const string&);

ostream& operator <<(ostream&, const scifir::angle&);
istream& operator >>(istream&, scifir::angle&);

#endif // SCIFIR_UNITS_MECA_NUMBER_ANGLE_HPP_INCLUDED
