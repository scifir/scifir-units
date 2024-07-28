#ifndef SCIFIR_UNITS_SPECIAL_UNITS_PH_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_PH_HPP_INCLUDED

#include "../util/is_number.hpp"
#include "../units/scalar_unit.hpp"
#include "../derived_units/chemistry_units.hpp"

#include "boost/math/constants/constants.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace scifir
{
	class pOH;

	class pH
	{
		public:
			pH();
			pH(const pH& x);
			pH(pH&& x);
			explicit pH(float new_value);
			explicit pH(const string& init_pH);
			explicit pH(const scalar_unit& x);

			pH& operator =(const pH& x);
			pH& operator =(pH&& x);
			pH& operator =(float new_value);
			pH& operator =(const string& init_pH);
			pH& operator =(const scalar_unit& x);

			explicit operator float() const
			{
				return float(value);
			}

			inline const float& get_value() const
			{
				return value;
			}

			pH operator +(const pH& x) const;
			pH operator -(const pH& x) const;
			void operator +=(const pH& x);
			void operator -=(const pH& x);

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pH operator +(T x) const
			{
				return pH(value + x);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pH operator -(T x) const
			{
				return pH(value - x);
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

			pH& operator ++();
			pH operator ++(int);
			pH& operator --();
			pH operator --(int);

			molarity get_H() const;
			molarity get_OH() const;
			pOH get_pOH() const;

			bool is_acidic() const;
			bool is_basic() const;
			bool is_neutral() const;

			string display(int number_of_decimals = 2) const;

		private:
			float value;

			void normalize_value();
	};

	string to_string(const pH& x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pH operator +(T x, const scifir::pH& y)
{
	return scifir::pH(x + y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pH operator -(T x, const scifir::pH& y)
{
	return scifir::pH(x - y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(T x, const scifir::pH& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(T x, const scifir::pH& y)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(T x, const scifir::pH& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(T x, const scifir::pH& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(T x, const scifir::pH& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(T x, const scifir::pH& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(const scifir::pH& y, T x)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(const scifir::pH& y, T x)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(const scifir::pH& y, T x)
{
	return (y.get_value() < x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(const scifir::pH& y, T x)
{
	return (y.get_value() > x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(const scifir::pH& y, T x)
{
	return (y.get_value() <= x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(const scifir::pH& y, T x)
{
	return (y.get_value() >= x);
}

bool operator ==(const scifir::pH& x, const scifir::pH& y);
bool operator !=(const scifir::pH& x, const scifir::pH& y);
bool operator <(const scifir::pH& x, const scifir::pH& y);
bool operator >(const scifir::pH& x, const scifir::pH& y);
bool operator <=(const scifir::pH& x, const scifir::pH& y);
bool operator >=(const scifir::pH& x, const scifir::pH& y);

bool operator ==(const scifir::pH& x, const string& init_pH);
bool operator !=(const scifir::pH& x, const string& init_pH);

bool operator ==(const string& init_pH, const scifir::pH& x);
bool operator !=(const string& init_pH, const scifir::pH& x);

void operator +=(string& x, const scifir::pH& y);
string operator +(const string& x, const scifir::pH& y);
string operator +(const scifir::pH& y, const string& x);

ostream& operator <<(ostream& os, const scifir::pH& x);
istream& operator >>(istream& is, scifir::pH& x);

#endif // SCIFIR_UNITS_SPECIAL_UNITS_PH_HPP_INCLUDED

