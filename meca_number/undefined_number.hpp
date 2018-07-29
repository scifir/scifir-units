#ifndef UNDEFINED_NUMBER_HPP_INCLUDED
#define UNDEFINED_NUMBER_HPP_INCLUDED

#include "math/topology/topology.hpp"
#include "informatics/types/is_number.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

namespace msci
{
	template<typename T>
	class undefined_number
	{
		public:
			undefined_number() : error_code(0), value(0)
			{
			}

			undefined_number(msci::space_type new_value)
			{
				value = new_value;
				error_code = 0;
			}

			virtual T* clone() const
			{
				return new T(dynamic_cast<T const &>(*this));
			}

			operator float() const
			{
				return value;
			}

			inline void invalidate(int new_error_code)
			{
				error_code = new_error_code;
			}

			bool is_defined() const
			{
				if(error_code == 0)
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			inline const int& get_error_code() const
			{
				return error_code;
			}

			inline const msci::space_type& get_value() const
			{
				return value;
			}

			void operator =(const T& new_number)
			{
				value = new_number.get_value();
				if(!new_number.is_defined())
				{
					invalidate(1);
				}
				else
				{
					error_code = 0;
				}
			}

			T operator +(const T& new_number) const
			{
				T z = *clone();
				z += new_number;
				return z;
			}

			T operator -(const T& new_number) const
			{
				T z = *clone();
				z -= new_number;
				return z;
			}

			T operator *(const T& new_number) const
			{
				T z = *clone();
				z *= new_number;
				return z;
			}

			T operator /(const T& new_number) const
			{
				T z = *clone();
				z /= new_number;
				return z;
			}

			T operator ^(const T& new_number) const
			{
				T z = *clone();
				z ^= new_number;
				return z;
			}

			void operator +=(const T& new_number)
			{
				if(is_defined())
				{
					if(new_number.is_defined())
					{
						value += new_number.get_value();
					}
					else
					{
						value = 0;
						invalidate(2);
					}
				}
			}

			void operator -=(const T& new_number)
			{
				if(is_defined())
				{
					if(new_number.is_defined())
					{
						value -= new_number.get_value();
					}
					else
					{
						value = 0;
						invalidate(3);
					}
				}
			}

			void operator *=(const T& new_number)
			{
				if(is_defined())
				{
					if(new_number.is_defined())
					{
						value *= new_number.get_value();
					}
					else
					{
						value = 0;
						invalidate(4);
					}
				}
			}

			void operator /=(const T& new_number)
			{
				if(is_defined())
				{
					if(new_number.is_defined())
					{
						value /= new_number.get_value();
					}
					else
					{
						value = 0;
						invalidate(5);
					}
				}
			}

			void operator ^=(const T& new_number)
			{
				if(is_defined())
				{
					if(new_number.is_defined())
					{
						value = std::pow(value, new_number.get_value());
					}
					else
					{
						value = 0;
						invalidate(6);
					}
				}
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator =(U new_number)
			{
				value = new_number;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			T operator +(U new_number) const
			{
				T z = *clone();
				z += new_number;
				return z;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			T operator -(U new_number) const
			{
				T z = *clone();
				z -= new_number;
				return z;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			T operator *(U new_number) const
			{
				T z = *clone();
				z *= new_number;
				return z;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			T operator /(U new_number) const
			{
				T z = *clone();
				z /= new_number;
				return z;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			T operator ^(U new_number) const
			{
				T z = *clone();
				z ^= new_number;
				return z;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator +=(U new_number)
			{
				value += new_number;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator -=(U new_number)
			{
				value -= new_number;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator *=(U new_number)
			{
				value *= new_number;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator /=(U new_number)
			{
				value /= new_number;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator ^=(U new_number)
			{
				value = pow(value, new_number);
			}

			T& operator++()
			{
				value++;
				return *clone();
			}

			T operator++(int)
			{
				T tmp = *clone();
				operator++();
				return tmp;
			}

			T& operator--()
			{
				value--;
				return *clone();
			}

			T operator--(int)
			{
				T tmp = *clone();
				operator--();
				return tmp;
			}

			virtual string print() const
			{
				ostringstream output;
				output << setprecision(numeric_limits<float>::max_exponent10 + 1);
				if(is_defined())
				{
					output << get_value();
				}
				else
				{
					output << "undefined";
					string message;
					switch(get_error_code())
					{
						case 1:
							message = "Number initiated to an undefined number";
							break;
						case 2:
							message = "cannot sum undefined number";
							break;
						case 3:
							message = "cannot substract undefined number";
							break;
						case 4:
							message = "cannot multiply undefined number";
							break;
						case 5:
							message = "cannot divide undefined number";
							break;
						case 6:
							message = "cannot power undefined number";
							break;
					}
					output << " " << message;
				}
				return output.str();
			}

		protected:
			int error_code;
			msci::space_type value;
	};

	template<typename T>
	msci::space_type abs(const undefined_number<T>& x)
	{
		return std::abs(x.get_value());
	}

	template<typename T>
	T sqrt(const undefined_number<T>& x)
	{
		return T(std::sqrt(x.get_value()));
	}

	template<typename T>
	T sqrt_nth(const undefined_number<T>& x, int y)
	{
		return T(pow(x.get_value(), 1 / y));
	}
}

template<typename U, typename V, typename = typename enable_if<is_number<V>::value>::type>
U operator +(V x, const msci::undefined_number<U>& y)
{
	return U(x + y.get_value());
}

template<typename U, typename V, typename = typename enable_if<is_number<V>::value>::type>
U operator -(V x, const msci::undefined_number<U>& y)
{
	return U(x - y.get_value());
}

template<typename U, typename V, typename = typename enable_if<is_number<V>::value>::type>
U operator *(V x, const msci::undefined_number<U>& y)
{
	return U(x * y.get_value());
}

template<typename U, typename V, typename = typename enable_if<is_number<V>::value>::type>
U operator /(V x, const msci::undefined_number<U>& y)
{
	return U(x / y.get_value());
}

template<typename U, typename V, typename = typename enable_if<is_number<V>::value>::type>
U operator ^(V x, const msci::undefined_number<U>& y)
{
	return U(pow(x, y.get_value()));
}

template<typename T, typename U>
bool operator ==(msci::undefined_number<T> x, msci::undefined_number<U> y)
{
	if(x.is_defined() and y.is_defined())
	{
		if(x.get_value() == y.get_value())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

template<typename T, typename U>
bool operator !=(msci::undefined_number<T> x, msci::undefined_number<U> y)
{
	return !(x == y);
}

template<typename T, typename U>
bool operator <(msci::undefined_number<T> x, msci::undefined_number<U> y)
{
	if(x.is_defined() and y.is_defined())
	{
		if(x.get_value() < y.get_value())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

template<typename T, typename U>
bool operator >(msci::undefined_number<T> x, msci::undefined_number<U> y)
{
	if(x.is_defined() and y.is_defined())
	{
		if(x.get_value() > y.get_value())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

template<typename T, typename U>
bool operator <=(msci::undefined_number<T> x, msci::undefined_number<U> y)
{
	return !(x > y);
}

template<typename T, typename U>
bool operator >=(msci::undefined_number<T> x, msci::undefined_number<U> y)
{
	return !(x < y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
bool operator ==(const msci::undefined_number<T>& x, U y)
{
	if(x.is_defined())
	{
		if(x.get_value() == y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
bool operator !=(const msci::undefined_number<T>& x, U y)
{
	return !(x == y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
bool operator <(const msci::undefined_number<T>& x, U y)
{
	if(x.is_defined())
	{
		if(x.get_value() < y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
bool operator >(const msci::undefined_number<T>& x, U y)
{
	if(x.is_defined())
	{
		if(x.get_value() > y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
bool operator <=(const msci::undefined_number<T>& x, U y)
{
	return !(x > y);
}

template<typename T, typename U, typename = typename enable_if<is_number<U>::value>::type>
bool operator >=(const msci::undefined_number<T>& x, U y)
{
	return !(x < y);
}

template<typename T>
void operator +=(string& x, const msci::undefined_number<T>& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

template<typename T>
string operator +(const string& x, const msci::undefined_number<T>& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

template<typename T>
string operator +(const msci::undefined_number<T>& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

template<typename T>
ostream & operator <<(ostream& os, const msci::undefined_number<T>& x)
{
	return os << x.print();
}

#endif // UNDEFINED_NUMBER_HPP_INCLUDED
