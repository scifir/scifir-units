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
	inline float radian_to_degree(float x)
	{
		return x * 180.0f / PI;
	}

	inline float degree_to_radian(float x)
	{
		return x * PI / 180.0f;
	}

	class angle
	{
		public:
			enum type : int8_t {DEGREE,RADIAN};

			angle();
			angle(const angle& x);
			angle(angle&& x);
			explicit angle(float new_value,angle::type init_type = angle::DEGREE);
			explicit angle(double new_value,angle::type init_type = angle::DEGREE);
			explicit angle(long double new_value,angle::type init_type = angle::DEGREE);
			explicit angle(int new_value,angle::type init_type = angle::DEGREE);
			explicit angle(const string& init_angle);
			explicit angle(const scalar_unit& x);

			angle& operator =(const angle& x);
			angle& operator =(angle&& x);
			angle& operator =(float new_value);
			angle& operator =(const string& init_angle);
			angle& operator =(const scalar_unit& x);

			explicit operator float() const
			{
				return float(value);
			}

			inline const float& get_value() const
			{
				return value;
			}

			angle operator +(const angle& x) const;
			angle operator -(const angle& x) const;
			angle operator *(const angle& x) const;
			angle operator /(const angle& x) const;
			angle operator ^(const angle& x) const;
			void operator +=(const angle& x);
			void operator -=(const angle& x);
			void operator *=(const angle& x);
			void operator /=(const angle& x);
			void operator ^=(const angle& x);

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator =(T new_value)
			{
				value = float(new_value);
				normalize_value();
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			angle operator +(T x) const
			{
				return angle(value + x);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			angle operator -(T x) const
			{
				return angle(value - x);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			angle operator *(T x) const
			{
				return angle(value * x);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			angle operator /(T x) const
			{
				return angle(value / x);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			angle operator ^(T x) const
			{
				return angle(std::pow(value, x));
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator +=(T x)
			{
				value += x;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator -=(T x)
			{
				value -= x;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator *=(T x)
			{
				value *= x;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator /=(T x)
			{
				value /= x;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator ^=(T x)
			{
				value = std::pow(value, x);
				normalize_value();
			}

			angle& operator++();
			angle operator++(int);
			angle& operator--();
			angle operator--(int);

			void invert();

			string display(int number_of_decimals = 2) const;

			inline float get_degree() const
			{
				return value;
			}

			inline float get_radian() const
			{
				return degree_to_radian(value);
			}

		private:
			float value;

			void normalize_value();
			void initialize_from_string(string init_angle);
	};

	string to_string(const angle& x);
	bool is_angle(const string& init_angle);
	bool parallel(const angle& x, const angle& y);
	bool orthogonal(const angle& x, const angle& y);

	angle sqrt(const angle& x);
	angle sqrt_nth(const angle& x,int index);

	float sin(const angle& x);
	float cos(const angle& x);
	float tan(const angle& x);
	angle asin(float x);
	angle acos(float x);
	angle atan(float x);
	float sinh(const angle& x);
	float cosh(const angle& x);
	float tanh(const angle& x);
	angle asinh(float x);
	angle acosh(float x);
	angle atanh(float x);

	inline float asin_degree(float x)
	{
		return radian_to_degree(std::asin(x));
	}

	inline float acos_degree(float x)
	{
		return radian_to_degree(std::acos(x));
	}

	inline float atan_degree(float x)
	{
		return radian_to_degree(std::atan(x));
	}

	inline float asinh_degree(float x)
	{
		return radian_to_degree(std::asinh(x));
	}

	inline float acosh_degree(float x)
	{
		return radian_to_degree(std::acosh(x));
	}

	inline float atanh_degree(float x)
	{
		return radian_to_degree(std::atanh(x));
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

bool operator ==(const scifir::angle& x, const scifir::angle& y);
bool operator !=(const scifir::angle& x, const scifir::angle& y);
bool operator <(const scifir::angle& x, const scifir::angle& y);
bool operator >(const scifir::angle& x, const scifir::angle& y);
bool operator <=(const scifir::angle& x, const scifir::angle& y);
bool operator >=(const scifir::angle& x, const scifir::angle& y);

bool operator ==(const scifir::angle& x, const string& init_angle);
bool operator !=(const scifir::angle& x, const string& init_angle);

bool operator ==(const string& init_angle, const scifir::angle& x);
bool operator !=(const string& init_angle, const scifir::angle& x);

void operator +=(string& x, const scifir::angle& y);
string operator +(const string& x, const scifir::angle& y);
string operator +(const scifir::angle& y, const string& x);

ostream& operator <<(ostream& os, const scifir::angle& x);
istream& operator >>(istream& is, scifir::angle& x);

#endif // SCIFIR_UNITS_MECA_NUMBER_ANGLE_HPP_INCLUDED
