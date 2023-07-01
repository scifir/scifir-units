#ifndef MSCI_UNITS_SPECIAL_UNITS_POH_HPP_INCLUDED
#define MSCI_UNITS_SPECIAL_UNITS_POH_HPP_INCLUDED

#include "util/is_number.hpp"
#include "units/scalar_unit.hpp"
#include "predefined_units/substance_units.hpp"
#include "special_units/ph.hpp"

#include "boost/math/constants/constants.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace msci
{
	class pOH
	{
		public:
			pOH();
			pOH(const pOH&);
			pOH(pOH&&);
			explicit pOH(float);
			explicit pOH(const string&);
			explicit pOH(const scalar_unit&);

			pOH& operator=(const pOH&);
			pOH& operator=(pOH&&);
			pOH& operator=(float);
			pOH& operator=(const string&);
			pOH& operator=(const scalar_unit&);

			explicit operator float() const
			{
				return float(value);
			}

			inline const float& get_value() const
			{
				return value;
			}

			pOH operator +(const pOH&) const;
			pOH operator -(const pOH&) const;
			void operator +=(const pOH&);
			void operator -=(const pOH&);

			template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
			pOH operator +(T y) const
			{
				return pOH(value + y);
			}

			template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
			pOH operator -(T y) const
			{
				return pOH(value - y);
			}

			template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
			void operator +=(T y)
			{
				value += y;
				normalize_value();
			}

			template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
			void operator -=(T y)
			{
				value -= y;
				normalize_value();
			}

			pOH& operator++();
			pOH operator++(int);
			pOH& operator--();
			pOH operator--(int);

			concentration get_H() const;
			concentration get_OH() const;
			pH get_pH() const;

			bool is_acidic() const;
			bool is_basic() const;
			bool is_neutral() const;

			string display(int = 2) const;

		private:
			float value;

			void normalize_value();
	};

	string to_string(const pOH&);
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
msci::pOH operator +(T x, const msci::pOH& y)
{
	return pOH(x + y.get_value());
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
msci::pOH operator -(T x, const msci::pOH& y)
{
	return pOH(x - y.get_value());
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
bool operator ==(T x, const msci::pOH& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
bool operator !=(T x, const msci::pOH& y)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
bool operator <(T x, const msci::pOH& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
bool operator >(T x, const msci::pOH& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
bool operator <=(T x, const msci::pOH& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
bool operator >=(T x, const msci::pOH& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
bool operator ==(const msci::pOH& y, T x)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
bool operator !=(const msci::pOH& y, T x)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
bool operator <(const msci::pOH& y, T x)
{
	return (y.get_value() < x);
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
bool operator >(const msci::pOH& y, T x)
{
	return (y.get_value() > x);
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
bool operator <=(const msci::pOH& y, T x)
{
	return (y.get_value() <= x);
}

template<typename T, typename = typename enable_if<msci::is_number<T>::value>::type>
bool operator >=(const msci::pOH& y, T x)
{
	return (y.get_value() >= x);
}

bool operator ==(const msci::pOH&, const msci::pOH&);
bool operator !=(const msci::pOH&, const msci::pOH&);
bool operator <(const msci::pOH&, const msci::pOH&);
bool operator >(const msci::pOH&, const msci::pOH&);
bool operator <=(const msci::pOH&, const msci::pOH&);
bool operator >=(const msci::pOH&, const msci::pOH&);

bool operator ==(const msci::pOH&, const string&);
bool operator !=(const msci::pOH&, const string&);

bool operator ==(const string&, const msci::pOH&);
bool operator !=(const string&, const msci::pOH&);

void operator +=(string&, const msci::pOH&);
string operator +(const string&, const msci::pOH&);
string operator +(const msci::pOH&, const string&);

ostream& operator <<(ostream&, const msci::pOH&);
istream& operator >>(istream&, msci::pOH&);

#endif // MSCI_UNITS_SPECIAL_UNITS_POH_HPP_INCLUDED


