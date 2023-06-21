#ifndef MSCI_UNITS_MECA_NUMBER_LAB_NUMBER_HPP_INCLUDED
#define MSCI_UNITS_MECA_NUMBER_LAB_NUMBER_HPP_INCLUDED

#include "util/is_number.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace msci
{
	template<typename T>
	class lab_number
	{
		public:
			lab_number() : value(),error_value()
			{}

			lab_number(const lab_number<T>& x) : value(x.value),error_value(x.error_value)
			{}

			lab_number(lab_number<T>&& x) : value(move(x.value)),error_value(move(x.error_value))
			{}

			explicit lab_number(T x,T y) : value(x),error_value(y)
			{}

			lab_number<T>& operator=(const lab_number<T>& x)
			{
				value = x.value;
				error_value = x.error_value;
				return *this;
			}

			lab_number<T>& operator=(lab_number<T>&& x)
			{
				value = move(x.value);
				error_value = move(x.error_value);
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

			lab_number<T> operator *(const lab_number<T>& x) const
			{
				return lab_number<T>(value * x.value,error_value * x.error_value);
			}

			lab_number<T> operator /(const lab_number<T>& x) const
			{
				return lab_number<T>(value / x.value,error_value / x.error_value);
			}

			lab_number<T> operator ^(const lab_number<T>& x) const
			{
				return lab_number<T>(value ^ x.value,error_value ^ x.error_value);
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

			void operator *=(const lab_number<T>& x)
			{
				value *= x.value;
				error_value *= x.error_value;
			}

			void operator /=(const lab_number<T>& x)
			{
				value /= x.value;
				error_value /= x.error_value;
			}

			void operator ^=(const lab_number<T>& x)
			{
				value ^= x.value;
				error_value ^= x.error_value;
			}

			T value;
			T error_value;
	};
	
	template<typename T>
	string to_string(const lab_number<T>& x)
	{
		ostringstream output;
		output << setprecision(numeric_limits<float>::max_exponent10 + 1);
		if(std::abs(x.error_value) > std::abs(x.value))
		{
			output << "Error: error greater than value" << endl;
		}
		else
		{
			output << x.value << " +- " << x.error_value;
		}
		return output.str();
	}
}

template<typename T>
bool operator ==(const msci::lab_number<T>& x, const msci::lab_number<T>& y)
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

template<typename T>
bool operator !=(const msci::lab_number<T>& x, const msci::lab_number<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const msci::angle& x, const string& y)
{
	return (to_string(x) == y);
}

template<typename T>
bool operator !=(const msci::angle& x, const string& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const string& x, const msci::angle& y)
{
	return (x == to_string(y));
}

template<typename T>
bool operator !=(const string& x, const msci::angle& y)
{
	return !(x == y);
}

template<typename T>
void operator +=(string& x, const msci::lab_number<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x, const msci::lab_number<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const msci::lab_number<T>& x, const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os, const msci::lab_number<T>& x)
{
	return os << to_string(x);
}

template<typename T>
istream& operator >>(istream& is, msci::lab_number<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	vector<string> values;
	boost::split(values,b,boost::is_any_of(" +- "));
	msci::lab_number<T> c;
	if (values.size() == 2)
	{
		T x1 = T(values[0]);
		T x2 = T(values[1]);
		c = msci::lab_number<T>(x1,x2);
	}
	else
	{
		c = msci::lab_number<T>();
	}
	x = c;
	return is;
}

#endif // MSCI_UNITS_MECA_NUMBER_LAB_NUMBER_HPP_INCLUDED
