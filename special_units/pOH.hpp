#ifndef SCIFIR_UNITS_SPECIAL_UNITS_POH_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_POH_HPP_INCLUDED

#include "util/is_number.hpp"
#include "units/scalar_unit.hpp"
#include "predefined_units/chemistry_units.hpp"
#include "special_units/pH.hpp"

#include "boost/math/constants/constants.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace scifir
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

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pOH operator +(T y) const
			{
				return pOH(value + y);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pOH operator -(T y) const
			{
				return pOH(value - y);
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

			pOH& operator++();
			pOH operator++(int);
			pOH& operator--();
			pOH operator--(int);

			molarity get_H() const;
			molarity get_OH() const;
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

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pOH operator +(T x, const scifir::pOH& y)
{
	return pOH(x + y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pOH operator -(T x, const scifir::pOH& y)
{
	return pOH(x - y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(T x, const scifir::pOH& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(T x, const scifir::pOH& y)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(T x, const scifir::pOH& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(T x, const scifir::pOH& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(T x, const scifir::pOH& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(T x, const scifir::pOH& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(const scifir::pOH& y, T x)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(const scifir::pOH& y, T x)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(const scifir::pOH& y, T x)
{
	return (y.get_value() < x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(const scifir::pOH& y, T x)
{
	return (y.get_value() > x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(const scifir::pOH& y, T x)
{
	return (y.get_value() <= x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(const scifir::pOH& y, T x)
{
	return (y.get_value() >= x);
}

bool operator ==(const scifir::pOH&, const scifir::pOH&);
bool operator !=(const scifir::pOH&, const scifir::pOH&);
bool operator <(const scifir::pOH&, const scifir::pOH&);
bool operator >(const scifir::pOH&, const scifir::pOH&);
bool operator <=(const scifir::pOH&, const scifir::pOH&);
bool operator >=(const scifir::pOH&, const scifir::pOH&);

bool operator ==(const scifir::pOH&, const string&);
bool operator !=(const scifir::pOH&, const string&);

bool operator ==(const string&, const scifir::pOH&);
bool operator !=(const string&, const scifir::pOH&);

void operator +=(string&, const scifir::pOH&);
string operator +(const string&, const scifir::pOH&);
string operator +(const scifir::pOH&, const string&);

ostream& operator <<(ostream&, const scifir::pOH&);
istream& operator >>(istream&, scifir::pOH&);

#endif // SCIFIR_UNITS_SPECIAL_UNITS_POH_HPP_INCLUDED


