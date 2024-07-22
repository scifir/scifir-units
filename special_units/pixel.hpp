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
			pixel(const pixel& x);
			pixel(pixel&& x);
			explicit pixel(float new_value);
			explicit pixel(double new_value);
			explicit pixel(long double new_value);
			explicit pixel(int new_value);
			explicit pixel(const string& init_pixel);
			explicit pixel(const scalar_unit& x);

			pixel& operator =(const pixel& x);
			pixel& operator =(pixel&& x);
			pixel& operator =(float new_value);
			pixel& operator =(const string& init_pixel);
			pixel& operator =(const scalar_unit& x);

			explicit operator float() const
			{
				return float(value);
			}

			inline const float& get_value() const
			{
				return value;
			}

			pixel operator +(const pixel& x) const;
			pixel operator -(const pixel& x) const;
			pixel operator *(const pixel& x) const;
			pixel operator /(const pixel& x) const;
			pixel operator ^(const pixel& x) const;
			void operator +=(const pixel& x);
			void operator -=(const pixel& x);
			void operator *=(const pixel& x);
			void operator /=(const pixel& x);
			void operator ^=(const pixel& x);

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator =(T x)
			{
				value = x;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pixel operator +(T x) const
			{
				return pixel(value + x);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pixel operator -(T x) const
			{
				return pixel(value - x);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pixel operator *(T x) const
			{
				return pixel(value * x);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pixel operator /(T x) const
			{
				return pixel(value / x);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			pixel operator ^(T x) const
			{
				return pixel(std::pow(value, x));
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

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator ^=(T x)
			{
				value = std::pow(value, x);
			}

			pixel& operator ++();
			pixel operator ++(int);
			pixel& operator --();
			pixel operator --(int);

			scalar_unit to_scalar_unit() const;

		private:
			float value;

			void initialize_from_string(const string& init_pixel);

	};

	string to_string(const pixel& x);
	bool is_pixel(const string& init_pixel);

	pixel sqrt(const pixel& x);
	pixel sqrt_nth(const pixel& x,int index);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pixel operator +(T x, const scifir::pixel& y)
{
	return scifir::pixel(x + y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pixel operator -(T x, const scifir::pixel& y)
{
	return scifir::pixel(x - y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pixel operator *(T x, const scifir::pixel& y)
{
	return scifir::pixel(x * y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pixel operator /(T x, const scifir::pixel& y)
{
	return scifir::pixel(x / y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::pixel operator ^(T x, const scifir::pixel& y)
{
	return scifir::pixel(std::pow(x, y.get_value()));
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

bool operator ==(const scifir::pixel& x, const scifir::pixel& y);
bool operator !=(const scifir::pixel& x, const scifir::pixel& y);
bool operator <(const scifir::pixel& x, const scifir::pixel& y);
bool operator >(const scifir::pixel& x, const scifir::pixel& y);
bool operator <=(const scifir::pixel& x, const scifir::pixel& y);
bool operator >=(const scifir::pixel& x, const scifir::pixel& y);

bool operator ==(const scifir::pixel& x, const string& init_pixel);
bool operator !=(const scifir::pixel& x, const string& init_pixel);

bool operator ==(const string& init_pixel, const scifir::pixel& x);
bool operator !=(const string& init_pixel, const scifir::pixel& x);

void operator +=(string& x, const scifir::pixel& y);
string operator +(const string& x, const scifir::pixel& y);
string operator +(const scifir::pixel& y, const string& x);

ostream& operator <<(ostream& os, const scifir::pixel& x);
istream& operator >>(istream& is, scifir::pixel& x);

#endif // SCIFIR_UNITS_SPECIAL_UNITS_PIXEL_HPP_INCLUDED
