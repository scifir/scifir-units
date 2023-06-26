#ifndef MSCI_UNITS_SPECIAL_UNITS_PERCENTAGE_HPP_INCLUDED
#define MSCI_UNITS_SPECIAL_UNITS_PERCENTAGE_HPP_INCLUDED

#include "topology/constants.hpp"
#include "util/is_number.hpp"
#include "units/scalar_unit.hpp"

#include "boost/math/constants/constants.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace msci
{
	class percentage
	{
		public:
			percentage();
			percentage(const percentage&);
			percentage(percentage&&);
			explicit percentage(float);
			explicit percentage(string);
			explicit percentage(const scalar_unit&);

			percentage& operator=(const percentage&);
			percentage& operator=(percentage&&);
			percentage& operator=(float);
			percentage& operator=(string&);
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

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator =(T y)
			{
				value = y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			percentage operator +(T y) const
			{
				return percentage(value + y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			percentage operator -(T y) const
			{
				return percentage(value - y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			T operator *(T y) const
			{
				return T(value * y / 100);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			T operator /(T y) const
			{
				return percentage(100 * value / y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator +=(T y)
			{
				value += y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator -=(T y)
			{
				value -= y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator *=(T y)
			{
				value *= y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
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

		private:
			float value;

	};

	string to_string(const percentage&);
	bool is_percentage(const string&);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::percentage operator +(T x, const msci::percentage& y)
{
	return percentage(x + y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::percentage operator -(T x, const msci::percentage& y)
{
	return percentage(x - y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
T operator *(T x, const msci::percentage& y)
{
	return percentage(x * y.get_value() / 100);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
T operator /(T x, const msci::percentage& y)
{
	return percentage(100 * x / y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator ==(T x, const msci::percentage& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator !=(T x, const msci::percentage& y)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <(T x, const msci::percentage& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >(T x, const msci::percentage& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <=(T x, const msci::percentage& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >=(T x, const msci::percentage& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator ==(const msci::percentage& y, T x)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator !=(const msci::percentage& y, T x)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <(const msci::percentage& y, T x)
{
	return (y.get_value() < x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >(const msci::percentage& y, T x)
{
	return (y.get_value() > x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <=(const msci::percentage& y, T x)
{
	return (y.get_value() <= x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >=(const msci::percentage& y, T x)
{
	return (y.get_value() >= x);
}

msci::scalar_unit operator *(const msci::scalar_unit&, const msci::percentage&);
msci::scalar_unit operator /(const msci::scalar_unit&, const msci::percentage&);

bool operator ==(const msci::percentage&, const msci::percentage&);
bool operator !=(const msci::percentage&, const msci::percentage&);
bool operator <(const msci::percentage&, const msci::percentage&);
bool operator >(const msci::percentage&, const msci::percentage&);
bool operator <=(const msci::percentage&, const msci::percentage&);
bool operator >=(const msci::percentage&, const msci::percentage&);

bool operator ==(const msci::percentage&, const string&);
bool operator !=(const msci::percentage&, const string&);

bool operator ==(const string&, const msci::percentage&);
bool operator !=(const string&, const msci::percentage&);

void operator +=(string&, const msci::percentage&);
string operator +(const string&, const msci::percentage&);
string operator +(const msci::percentage&, const string&);

ostream& operator <<(ostream&, const msci::percentage&);
istream& operator >>(istream&, msci::percentage&);

#endif // MSCI_UNITS_SPECIAL_UNITS_PERCENTAGE_HPP_INCLUDED
