#ifndef SCIFIR_UNITS_SPECIAL_UNITS_PERCENTAGE_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_PERCENTAGE_HPP_INCLUDED

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
			enum type : int8_t {PERCENTAGE,RATIO,PARTS_PER_MILLION,PARTS_PER_BILLION,PARTS_PER_TRILLION,PARTS_PER_QUATRILLION};

			percentage();
			percentage(const percentage& x);
			percentage(percentage&& x);
			explicit percentage(float new_value,percentage::type init_type = percentage::PERCENTAGE);
			explicit percentage(double new_value,percentage::type init_type = percentage::PERCENTAGE);
			explicit percentage(long double new_value,percentage::type init_type = percentage::PERCENTAGE);
			explicit percentage(int new_value,percentage::type init_type = percentage::PERCENTAGE);
			explicit percentage(float new_value,const string& init_type);
			explicit percentage(double new_value,const string& init_type);
			explicit percentage(long double new_value,const string& init_type);
			explicit percentage(int new_value,const string& init_type);
			explicit percentage(const string& init_percentage);
			explicit percentage(const scalar_unit& x);

			percentage& operator =(const percentage& x);
			percentage& operator =(percentage&& x);
			percentage& operator =(float new_value);
			percentage& operator =(double new_value);
			percentage& operator =(long double new_value);
			percentage& operator =(int new_value);
			percentage& operator =(const string& init_percentage);
			percentage& operator =(const scalar_unit& x);

			explicit operator float() const
			{
				return float(value);
			}

			inline const float& get_value() const
			{
				return value;
			}

			percentage operator +(const percentage& x) const;
			percentage operator -(const percentage& x) const;
			percentage operator *(const percentage& x) const;
			percentage operator /(const percentage& x) const;
			void operator +=(const percentage& x);
			void operator -=(const percentage& x);
			void operator *=(const percentage& x);
			void operator /=(const percentage& x);

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator =(T x)
			{
				value = x;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			percentage operator +(T x) const
			{
				return percentage(value + x);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			percentage operator -(T x) const
			{
				return percentage(value - x);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			float operator *(T x) const
			{
				return float(value * x / 100);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			float operator /(T x) const
			{
				return float(value / (100 * x));
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator +=(T x)
			{
				value += x;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator -=(T x)
			{
				value -= x;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator *=(T x)
			{
				value *= x;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator /=(T x)
			{
				value /= x;
			}

			percentage& operator ++();
			percentage operator ++(int);
			percentage& operator --();
			percentage operator --(int);

			scalar_unit operator *(const scalar_unit& x) const;
			scalar_unit operator /(const scalar_unit& x) const;

			float get_factor() const;

			float get_ppm() const;
			/*float get_ppb() const;
			float get_ppt() const;
			float get_ppq() const;*/

			string display_percentage(int number_of_decimals = 2) const;
			string display_ppm() const;
			/*string display_ppb() const;
			string display_ppt() const;
			string display_ppq() const;*/

		private:
			float value;

			void initialize_from_string(const string& init_percentage);

	};

	string to_string(const percentage& x);
	bool is_percentage(const string& init_percentage);
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

scifir::scalar_unit operator *(const scifir::scalar_unit& x, const scifir::percentage& y);
scifir::scalar_unit operator /(const scifir::scalar_unit& x, const scifir::percentage& y);

bool operator ==(const scifir::percentage& x, const scifir::percentage& y);
bool operator !=(const scifir::percentage& x, const scifir::percentage& y);
bool operator <(const scifir::percentage& x, const scifir::percentage& y);
bool operator >(const scifir::percentage& x, const scifir::percentage& y);
bool operator <=(const scifir::percentage& x, const scifir::percentage& y);
bool operator >=(const scifir::percentage& x, const scifir::percentage& y);

bool operator ==(const scifir::percentage& x, const string& init_percentage);
bool operator !=(const scifir::percentage& x, const string& init_percentage);

bool operator ==(const string& init_percentage, const scifir::percentage& x);
bool operator !=(const string& init_percentage, const scifir::percentage& x);

void operator +=(string& x, const scifir::percentage& y);
string operator +(const string& x, const scifir::percentage& y);
string operator +(const scifir::percentage& y, const string& x);

ostream& operator <<(ostream& os, const scifir::percentage& x);
istream& operator >>(istream& is, scifir::percentage& x);

#endif // SCIFIR_UNITS_SPECIAL_UNITS_PERCENTAGE_HPP_INCLUDED
