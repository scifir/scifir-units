#ifndef SCIFIR_UNITS_SPECIAL_UNITS_PH_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_PH_HPP_INCLUDED

#include "../util/is_number.hpp"
#include "../units/scalar_unit.hpp"
#include "../predefined_units/chemistry_units.hpp"

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
			pH(const pH&);
			pH(pH&&);
			explicit pH(float);
			explicit pH(const string&);
			explicit pH(const scalar_unit&);

			pH& operator=(const pH&);
			pH& operator=(pH&&);
			pH& operator=(float);
			pH& operator=(const string&);
			pH& operator=(const scalar_unit&);

			explicit operator float() const
			{
				return float(value);
			}

			inline const float& get_value() const
			{
				return value;
			}

			pH operator +(const pH&) const;
			pH operator -(const pH&) const;
			void operator +=(const pH&);
			void operator -=(const pH&);

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pH operator +(T y) const
			{
				return pH(value + y);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pH operator -(T y) const
			{
				return pH(value - y);
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

			pH& operator++();
			pH operator++(int);
			pH& operator--();
			pH operator--(int);

			molarity get_H() const;
			molarity get_OH() const;
			pOH get_pOH() const;

			bool is_acidic() const;
			bool is_basic() const;
			bool is_neutral() const;

			string display(int = 2) const;

		private:
			float value;

			void normalize_value();
	};

	string to_string(const pH&);
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

bool operator ==(const scifir::pH&, const scifir::pH&);
bool operator !=(const scifir::pH&, const scifir::pH&);
bool operator <(const scifir::pH&, const scifir::pH&);
bool operator >(const scifir::pH&, const scifir::pH&);
bool operator <=(const scifir::pH&, const scifir::pH&);
bool operator >=(const scifir::pH&, const scifir::pH&);

bool operator ==(const scifir::pH&, const string&);
bool operator !=(const scifir::pH&, const string&);

bool operator ==(const string&, const scifir::pH&);
bool operator !=(const string&, const scifir::pH&);

void operator +=(string&, const scifir::pH&);
string operator +(const string&, const scifir::pH&);
string operator +(const scifir::pH&, const string&);

ostream& operator <<(ostream&, const scifir::pH&);
istream& operator >>(istream&, scifir::pH&);

#endif // SCIFIR_UNITS_SPECIAL_UNITS_PH_HPP_INCLUDED

