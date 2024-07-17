#ifndef SCIFIR_UNITS_SPECIAL_UNITS_POH_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_POH_HPP_INCLUDED

#include "../util/is_number.hpp"
#include "../units/scalar_unit.hpp"
#include "../predefined_units/chemistry_units.hpp"
#include "./pH.hpp"

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
			pOH(const pOH& x);
			pOH(pOH&& x);
			explicit pOH(float new_value);
			explicit pOH(const string& init_pOH);
			explicit pOH(const scalar_unit& x);

			pOH& operator =(const pOH& x);
			pOH& operator =(pOH&& x);
			pOH& operator =(float new_value);
			pOH& operator =(const string& init_pOH);
			pOH& operator =(const scalar_unit& x);

			explicit operator float() const
			{
				return float(value);
			}

			inline const float& get_value() const
			{
				return value;
			}

			pOH operator +(const pOH& x) const;
			pOH operator -(const pOH& x) const;
			void operator +=(const pOH& x);
			void operator -=(const pOH& x);

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pOH operator +(T x) const
			{
				return pOH(value + x);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pOH operator -(T x) const
			{
				return pOH(value - x);
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

			pOH& operator ++();
			pOH operator ++(int);
			pOH& operator --();
			pOH operator --(int);

			molarity get_H() const;
			molarity get_OH() const;
			pH get_pH() const;

			bool is_acidic() const;
			bool is_basic() const;
			bool is_neutral() const;

			string display(int number_of_decimals = 2) const;

		private:
			float value;

			void normalize_value();
	};

	string to_string(const pOH& x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pOH operator +(T x, const scifir::pOH& y)
{
	return scifir::pOH(x + y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pOH operator -(T x, const scifir::pOH& y)
{
	return scifir::pOH(x - y.get_value());
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

bool operator ==(const scifir::pOH& x, const scifir::pOH& y);
bool operator !=(const scifir::pOH& x, const scifir::pOH& y);
bool operator <(const scifir::pOH& x, const scifir::pOH& y);
bool operator >(const scifir::pOH& x, const scifir::pOH& y);
bool operator <=(const scifir::pOH& x, const scifir::pOH& y);
bool operator >=(const scifir::pOH& x, const scifir::pOH& y);

bool operator ==(const scifir::pOH& x, const string& init_pOH);
bool operator !=(const scifir::pOH& x, const string& init_pOH);

bool operator ==(const string& init_pOH, const scifir::pOH& x);
bool operator !=(const string& init_pOH, const scifir::pOH& x);

void operator +=(string& x, const scifir::pOH& y);
string operator +(const string& x, const scifir::pOH& y);
string operator +(const scifir::pOH& y, const string& x);

ostream& operator <<(ostream& os, const scifir::pOH& x);
istream& operator >>(istream& is, scifir::pOH& x);

#endif // SCIFIR_UNITS_SPECIAL_UNITS_POH_HPP_INCLUDED


