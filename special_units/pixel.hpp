#ifndef MSCI_UNITS_SPECIAL_UNITS_PIXEL_HPP_INCLUDED
#define MSCI_UNITS_SPECIAL_UNITS_PIXEL_HPP_INCLUDED

#include "topology/constants.hpp"
#include "util/is_number.hpp"
#include "units/scalar_unit.hpp"

#include "boost/math/constants/constants.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace msci
{
	class pixel
	{
		public:
			pixel();
			pixel(const pixel&);
			pixel(pixel&&);
			explicit pixel(float);
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

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator =(T y)
			{
				value = y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			pixel operator +(T y) const
			{
				return pixel(value + y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			pixel operator -(T y) const
			{
				return pixel(value - y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			pixel operator *(T y) const
			{
				return pixel(value * y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			pixel operator /(T y) const
			{
				return pixel(value / y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			pixel operator ^(T y) const
			{
				return pixel(std::pow(value, y));
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

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
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

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::pixel operator +(T x, const msci::pixel& y)
{
	return pixel(x + y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::pixel operator -(T x, const msci::pixel& y)
{
	return pixel(x - y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::pixel operator *(T x, const msci::pixel& y)
{
	return pixel(x * y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::pixel operator /(T x, const msci::pixel& y)
{
	return pixel(x / y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::pixel operator ^(T x, const msci::pixel& y)
{
	return pixel(pow(x, y.get_value()));
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator ==(T x, const msci::pixel& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator !=(T x, const msci::pixel& y)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <(T x, const msci::pixel& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >(T x, const msci::pixel& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <=(T x, const msci::pixel& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >=(T x, const msci::pixel& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator ==(const msci::pixel& y, T x)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator !=(const msci::pixel& y, T x)
{
	return (x != y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <(const msci::pixel& y, T x)
{
	return (y.get_value() < x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >(const msci::pixel& y, T x)
{
	return (y.get_value() > x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <=(const msci::pixel& y, T x)
{
	return (y.get_value() <= x);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >=(const msci::pixel& y, T x)
{
	return (y.get_value() >= x);
}

bool operator ==(const msci::pixel&, const msci::pixel&);
bool operator !=(const msci::pixel&, const msci::pixel&);
bool operator <(const msci::pixel&, const msci::pixel&);
bool operator >(const msci::pixel&, const msci::pixel&);
bool operator <=(const msci::pixel&, const msci::pixel&);
bool operator >=(const msci::pixel&, const msci::pixel&);

bool operator ==(const msci::pixel&, const string&);
bool operator !=(const msci::pixel&, const string&);

bool operator ==(const string&, const msci::pixel&);
bool operator !=(const string&, const msci::pixel&);

void operator +=(string&, const msci::pixel&);
string operator +(const string&, const msci::pixel&);
string operator +(const msci::pixel&, const string&);

ostream& operator <<(ostream&, const msci::pixel&);
istream& operator >>(istream&, msci::pixel&);

#endif // MSCI_UNITS_SPECIAL_UNITS_PIXEL_HPP_INCLUDED
