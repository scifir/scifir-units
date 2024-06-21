#ifndef SCIFIR_UNITS_SPECIAL_UNITS_PERCENTAGE_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_PERCENTAGE_HPP_INCLUDED

#include "../topology/constants.hpp"
#include "../util/is_number.hpp"
#include "../units/scalar_unit.hpp"

#include "boost/math/constants/constants.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace scifir
{
	class percentage
	{
		public:
			percentage();
			percentage(const percentage&);
			percentage(percentage&&);
			explicit percentage(float);
			explicit percentage(double);
			explicit percentage(long double);
			explicit percentage(int);
			explicit percentage(float,const string&);
			explicit percentage(double,const string&);
			explicit percentage(long double,const string&);
			explicit percentage(int,const string&);
			explicit percentage(const string&);
			explicit percentage(const scalar_unit&);

			percentage& operator=(const percentage&);
			percentage& operator=(percentage&&);
			percentage& operator=(float);
			percentage& operator=(double);
			percentage& operator=(long double);
			percentage& operator=(const string&);
			percentage& operator=(const scalar_unit&);

			explicit operator float() const
			{
				return float(value);
			}

			inline const float& get_value() const
			{
				return value;
			}

			percentage operator +(const percentage&) const;
			percentage operator -(const percentage&) const;
			percentage operator *(const percentage&) const;
			percentage operator /(const percentage&) const;
			void operator +=(const percentage&);
			void operator -=(const percentage&);
			void operator *=(const percentage&);
			void operator /=(const percentage&);

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator =(T y)
			{
				value = y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			percentage operator +(T y) const
			{
				return percentage(value + y);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			percentage operator -(T y) const
			{
				return percentage(value - y);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			float operator *(T y) const
			{
				return float(value * y / 100);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			float operator /(T y) const
			{
				return float(value / (100 * y));
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator +=(T y)
			{
				value += y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator -=(T y)
			{
				value -= y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator *=(T y)
			{
				value *= y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator /=(T y)
			{
				value /= y;
			}

			percentage& operator++();
			percentage operator++(int);
			percentage& operator--();
			percentage operator--(int);

			scalar_unit operator *(const scalar_unit&) const;
			scalar_unit operator /(const scalar_unit&) const;

			float get_factor() const;

			float get_ppm() const;
			/*float get_ppb() const;
			float get_ppt() const;
			float get_ppq() const;*/

			string display_ppm() const;
			/*string display_ppb() const;
			string display_ppt() const;
			string display_ppq() const;*/

		private:
			float value;

	};

	string to_string(const percentage&);
	bool is_percentage(const string&);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::percentage operator +(T x, const scifir::percentage& y)
{
	return scifir::percentage(x + y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::percentage operator -(T x, const scifir::percentage& y)
{
	return scifir::percentage(x - y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
float operator *(T x, const scifir::percentage& y)
{
	return float(x * y.get_value() / 100);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
float operator /(T x, const scifir::percentage& y)
{
	return float(100 * x / y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(T x, const scifir::percentage& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(T x, const scifir::percentage& y)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(T x, const scifir::percentage& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(T x, const scifir::percentage& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(T x, const scifir::percentage& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(T x, const scifir::percentage& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(const scifir::percentage& y, T x)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(const scifir::percentage& y, T x)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(const scifir::percentage& y, T x)
{
	return (y.get_value() < x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(const scifir::percentage& y, T x)
{
	return (y.get_value() > x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(const scifir::percentage& y, T x)
{
	return (y.get_value() <= x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(const scifir::percentage& y, T x)
{
	return (y.get_value() >= x);
}

scifir::scalar_unit operator *(const scifir::scalar_unit&, const scifir::percentage&);
scifir::scalar_unit operator /(const scifir::scalar_unit&, const scifir::percentage&);

bool operator ==(const scifir::percentage&, const scifir::percentage&);
bool operator !=(const scifir::percentage&, const scifir::percentage&);
bool operator <(const scifir::percentage&, const scifir::percentage&);
bool operator >(const scifir::percentage&, const scifir::percentage&);
bool operator <=(const scifir::percentage&, const scifir::percentage&);
bool operator >=(const scifir::percentage&, const scifir::percentage&);

bool operator ==(const scifir::percentage&, const string&);
bool operator !=(const scifir::percentage&, const string&);

bool operator ==(const string&, const scifir::percentage&);
bool operator !=(const string&, const scifir::percentage&);

void operator +=(string&, const scifir::percentage&);
string operator +(const string&, const scifir::percentage&);
string operator +(const scifir::percentage&, const string&);

ostream& operator <<(ostream&, const scifir::percentage&);
istream& operator >>(istream&, scifir::percentage&);

#endif // SCIFIR_UNITS_SPECIAL_UNITS_PERCENTAGE_HPP_INCLUDED
