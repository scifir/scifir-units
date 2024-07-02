#ifndef SCIFIR_UNITS_MECA_NUMBER_LAB_NUMBER_HPP_INCLUDED
#define SCIFIR_UNITS_MECA_NUMBER_LAB_NUMBER_HPP_INCLUDED

#include "../util/is_number.hpp"
#include "../util/types.hpp"
#include "../units/scalar_unit.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

namespace scifir
{
	template<typename T>
	class lab_number
	{
		public:
			lab_number() : value(),error_value()
			{}

			lab_number(const lab_number<T>& x) : value(x.value),error_value(x.error_value)
			{}

			lab_number(lab_number<T>&& x) : value(std::move(x.value)),error_value(std::move(x.error_value))
			{}

			explicit lab_number(const T& x,const T& y) : value(x),error_value(y)
			{}

			lab_number<T>& operator =(const lab_number<T>& x)
			{
				value = x.value;
				error_value = x.error_value;
				return *this;
			}

			lab_number<T>& operator =(lab_number<T>&& x)
			{
				value = std::move(x.value);
				error_value = std::move(x.error_value);
				return *this;
			}

			lab_number<T> operator +(const lab_number<T>& x) const
			{
				return lab_number<T>(value + x.value,error_value + x.error_value);
			}

			lab_number<T> operator -(const lab_number<T>& x) const
			{
				return lab_number<T>(value - x.value,error_value - x.error_value);
			}

			template<typename U>
			lab_number<scalar_unit> operator *(const lab_number<U>& x) const
			{
				return lab_number<scalar_unit>(value * x.value,error_value * x.error_value);
			}

			template<typename U>
			lab_number<scalar_unit> operator /(const lab_number<U>& x) const
			{
				return lab_number<scalar_unit>(value / x.value,error_value / x.error_value);
			}

			void operator +=(const lab_number<T>& x)
			{
				value += x.value;
				error_value += x.error_value;
			}

			void operator -=(const lab_number<T>& x)
			{
				value -= x.value;
				error_value -= x.error_value;
			}

			string display(int number_of_decimals = 2) const
			{
				ostringstream output;
				output << value.display(number_of_decimals) << " \u00B1 " << error_value.display(number_of_decimals);
				return output.str();
			}

			T value;
			T error_value;
	};

	template<typename T>
	string to_string(const lab_number<T>& x)
	{
		ostringstream output;
		output << x.display(2);
		return output.str();
	}
}

template<typename T,typename U>
bool operator ==(const scifir::lab_number<T>& x, const scifir::lab_number<U>& y)
{
	if (x.value == y.value and x.error_value == y.error_value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T,typename U>
bool operator !=(const scifir::lab_number<T>& x, const scifir::lab_number<U>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::lab_number<T>& x, const string& y)
{
	return (to_string(x) == y);
}

template<typename T>
bool operator !=(const scifir::lab_number<T>& x, const string& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const string& x, const scifir::lab_number<T>& y)
{
	return (x == to_string(y));
}

template<typename T>
bool operator !=(const string& x, const scifir::lab_number<T>& y)
{
	return !(x == y);
}

template<typename T>
void operator +=(string& x, const scifir::lab_number<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x, const scifir::lab_number<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::lab_number<T>& x, const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os, const scifir::lab_number<T>& x)
{
	return os << to_string(x);
}

template<typename T>
istream& operator >>(istream& is, scifir::lab_number<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	vector<string> values;
	boost::split(values,b,boost::is_any_of("+-,\u00B1"));
	scifir::lab_number<T> c;
	if (values.size() == 3)
	{
		boost::trim(values[0]);
		boost::trim(values[2]);
		T x1 = T(values[0]);
		T x2 = T(values[2]);
		c = scifir::lab_number<T>(x1,x2);
	}
	else
	{
		c = scifir::lab_number<T>();
	}
	x = c;
	return is;
}

#endif // SCIFIR_UNITS_MECA_NUMBER_LAB_NUMBER_HPP_INCLUDED
