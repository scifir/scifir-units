#ifndef SCIFIR_UNITS_NUTRITION_ABV_HPP_INCLUDED
#define SCIFIR_UNITS_NUTRITION_ABV_HPP_INCLUDED

#include "../units/scalar_unit.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace scifir
{
	class abv
	{
		public:
			enum type : int8_t {PERCENTAGE,RATIO};

			abv();
			abv(const abv& x);
			abv(abv&& x);
			explicit abv(float new_value,abv::type init_type = abv::PERCENTAGE);
			explicit abv(double new_value,abv::type init_type = abv::PERCENTAGE);
			explicit abv(long double new_value,abv::type init_type = abv::PERCENTAGE);
			explicit abv(int new_value,abv::type init_type = abv::PERCENTAGE);
			explicit abv(const string& init_abv);
			explicit abv(const scalar_unit& x);

			abv& operator =(const abv& x);
			abv& operator =(abv&& x);
			abv& operator =(float new_value);
			abv& operator =(double new_value);
			abv& operator =(long double new_value);
			abv& operator =(int new_value);
			abv& operator =(const string& init_abv);
			abv& operator =(const scalar_unit& x);

			explicit operator float() const
			{
				return float(value);
			}

			inline const float& get_value() const
			{
				return value;
			}

			abv operator +(const abv& x) const;
			abv operator -(const abv& x) const;
			void operator +=(const abv& x);
			void operator -=(const abv& x);

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			abv operator +(T x) const
			{
				return abv(value + x);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			abv operator -(T x) const
			{
				return abv(value - x);
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

			abv& operator ++();
			abv operator ++(int);
			abv& operator --();
			abv operator --(int);

			string display() const;

		private:
			float value;

			void initialize_from_string(const string& init_abv);
	};

	string to_string(const abv& x);
	bool is_abv(const string& init_abv);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::abv operator +(T x, const scifir::abv& y)
{
	return scifir::abv(x + y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::abv operator -(T x, const scifir::abv& y)
{
	return scifir::abv(x - y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(T x, const scifir::abv& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(T x, const scifir::abv& y)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(T x, const scifir::abv& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(T x, const scifir::abv& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(T x, const scifir::abv& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(T x, const scifir::abv& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(const scifir::abv& y, T x)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(const scifir::abv& y, T x)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(const scifir::abv& y, T x)
{
	return (y.get_value() < x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(const scifir::abv& y, T x)
{
	return (y.get_value() > x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(const scifir::abv& y, T x)
{
	return (y.get_value() <= x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(const scifir::abv& y, T x)
{
	return (y.get_value() >= x);
}

bool operator ==(const scifir::abv& x, const scifir::abv& y);
bool operator !=(const scifir::abv& x, const scifir::abv& y);
bool operator <(const scifir::abv& x, const scifir::abv& y);
bool operator >(const scifir::abv& x, const scifir::abv& y);
bool operator <=(const scifir::abv& x, const scifir::abv& y);
bool operator >=(const scifir::abv& x, const scifir::abv& y);

bool operator ==(const scifir::abv& x, const string& init_abv);
bool operator !=(const scifir::abv& x, const string& init_abv);

bool operator ==(const string& init_abv, const scifir::abv& x);
bool operator !=(const string& init_abv, const scifir::abv& x);

void operator +=(string& x, const scifir::abv& y);
string operator +(const string& x, const scifir::abv& y);
string operator +(const scifir::abv& y, const string& x);

ostream& operator <<(ostream& os, const scifir::abv& x);
istream& operator >>(istream& is, scifir::abv& x);

#endif // SCIFIR_UNITS_NUTRITION_ABV_HPP_INCLUDED