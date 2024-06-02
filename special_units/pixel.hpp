#ifndef SCIFIR_UNITS_SPECIAL_UNITS_PIXEL_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_PIXEL_HPP_INCLUDED

#include "../topology/constants.hpp"
#include "../util/is_number.hpp"
#include "../units/scalar_unit.hpp"

#include "boost/math/constants/constants.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace scifir
{
	class pixel
	{
		public:
			pixel();
			pixel(const pixel&);
			pixel(pixel&&);
			explicit pixel(float);
			explicit pixel(double);
			explicit pixel(long double);
			explicit pixel(int);
			explicit pixel(string);
			explicit pixel(const scalar_unit&);

			pixel& operator=(const pixel&);
			pixel& operator=(pixel&&);
			pixel& operator=(float);
			pixel& operator=(string&);
			pixel& operator=(const scalar_unit&);

			explicit operator float() const
			{
				return float(value);
			}

			inline const float& get_value() const
			{
				return value;
			}

			pixel operator +(const pixel&) const;
			pixel operator -(const pixel&) const;
			pixel operator *(const pixel&) const;
			pixel operator /(const pixel&) const;
			pixel operator ^(const pixel&) const;
			void operator +=(const pixel&);
			void operator -=(const pixel&);
			void operator *=(const pixel&);
			void operator /=(const pixel&);
			void operator ^=(const pixel&);

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator =(T y)
			{
				value = y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pixel operator +(T y) const
			{
				return pixel(value + y);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pixel operator -(T y) const
			{
				return pixel(value - y);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pixel operator *(T y) const
			{
				return pixel(value * y);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pixel operator /(T y) const
			{
				return pixel(value / y);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pixel operator ^(T y) const
			{
				return pixel(std::pow(value, y));
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

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator ^=(T y)
			{
				value = std::pow(value, y);
			}

			pixel& operator++();
			pixel operator++(int);
			pixel& operator--();
			pixel operator--(int);

		private:
			float value;

	};

	string to_string(const pixel&);
	bool is_pixel(const string&);

	pixel sqrt(const pixel&);
	pixel sqrt_nth(const pixel&,int);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pixel operator +(T x, const scifir::pixel& y)
{
	return pixel(x + y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pixel operator -(T x, const scifir::pixel& y)
{
	return pixel(x - y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pixel operator *(T x, const scifir::pixel& y)
{
	return pixel(x * y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pixel operator /(T x, const scifir::pixel& y)
{
	return pixel(x / y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pixel operator ^(T x, const scifir::pixel& y)
{
	return pixel(pow(x, y.get_value()));
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(T x, const scifir::pixel& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(T x, const scifir::pixel& y)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(T x, const scifir::pixel& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(T x, const scifir::pixel& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(T x, const scifir::pixel& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(T x, const scifir::pixel& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(const scifir::pixel& y, T x)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(const scifir::pixel& y, T x)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(const scifir::pixel& y, T x)
{
	return (y.get_value() < x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(const scifir::pixel& y, T x)
{
	return (y.get_value() > x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(const scifir::pixel& y, T x)
{
	return (y.get_value() <= x);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(const scifir::pixel& y, T x)
{
	return (y.get_value() >= x);
}

bool operator ==(const scifir::pixel&, const scifir::pixel&);
bool operator !=(const scifir::pixel&, const scifir::pixel&);
bool operator <(const scifir::pixel&, const scifir::pixel&);
bool operator >(const scifir::pixel&, const scifir::pixel&);
bool operator <=(const scifir::pixel&, const scifir::pixel&);
bool operator >=(const scifir::pixel&, const scifir::pixel&);

bool operator ==(const scifir::pixel&, const string&);
bool operator !=(const scifir::pixel&, const string&);

bool operator ==(const string&, const scifir::pixel&);
bool operator !=(const string&, const scifir::pixel&);

void operator +=(string&, const scifir::pixel&);
string operator +(const string&, const scifir::pixel&);
string operator +(const scifir::pixel&, const string&);

ostream& operator <<(ostream&, const scifir::pixel&);
istream& operator >>(istream&, scifir::pixel&);

#endif // SCIFIR_UNITS_SPECIAL_UNITS_PIXEL_HPP_INCLUDED
