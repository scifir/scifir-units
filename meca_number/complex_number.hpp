#ifndef SCIFIR_UNITS_MECA_NUMBER_COMPLEX_NUMBER_HPP_INCLUDED
#define SCIFIR_UNITS_MECA_NUMBER_COMPLEX_NUMBER_HPP_INCLUDED

#include "../meca_number/angle.hpp"
#include "../util/is_number.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace scifir
{
	template<typename T>
	class complex_number
	{
		public:
			complex_number() : real(),imaginary()
			{}

			complex_number(const complex_number<T>& x) : real(x.real),imaginary(x.imaginary)
			{}

			complex_number(complex_number<T>&& x) : real(std::move(x.real)),imaginary(std::move(x.imaginary))
			{}

			explicit complex_number(T x,T y) : real(x),imaginary(y)
			{}

			explicit complex_number(const string& init_complex_number) : complex_number()
			{
				if (init_complex_number.find("+"))
				{
					vector<string> numbers;
					boost::split(numbers,init_complex_number,boost::is_any_of("+"));
					if (numbers.size() == 2)
					{
						boost::trim(numbers[0]);
						boost::trim(numbers[1]);
						if (numbers[1].substr(0,numbers[1].length() - 3) == "(i)")
						{
							real = T(numbers[0]);
							imaginary = T(numbers[1].substr(0,numbers[1].length() - 3));
						}
						else
						{
							real = T();
							imaginary = T();
						}
					}
				}
				else
				{
					real = T();
					imaginary = T();
				}
			}

			complex_number<T>& operator=(const complex_number<T>& x)
			{
				real = x.real;
				imaginary = x.imaginary;
				return *this;
			}

			complex_number<T>& operator=(complex_number<T>&& x)
			{
				real = std::move(x.real);
				imaginary = std::move(x.imaginary);
				return *this;
			}

			complex_number<T> operator +(const complex_number<T>& x) const
			{
				return complex_number<T>(real + x.real,imaginary + x.imaginary);
			}

			complex_number<T> operator -(const complex_number<T>& x) const
			{
				return complex_number<T>(real - x.real,imaginary - x.imaginary);
			}

			complex_number<T> operator *(const complex_number<T>& x) const
			{
				return complex_number<T>(real * x.real - imaginary * x.imaginary,real * x.imaginary + imaginary * x.real);
			}

			complex_number<T> operator /(const complex_number<T>& x) const
			{
				T new_real = (real * x.real + x.imaginary * imaginary) / (real ^ 2 + imaginary ^ 2);
				T new_imaginary = (x.imaginary * real - x.real * imaginary) / (real ^ 2 + imaginary ^ 2);
				return complex_number<T>(new_real,new_imaginary);
			}

			void operator +=(const complex_number<T>& x)
			{
				real += x.real;
				imaginary += x.imaginary;
			}

			void operator -=(const complex_number<T>& x)
			{
				real -= x.real;
				imaginary -= x.imaginary;
			}

			void operator *=(const complex_number<T>& x)
			{
				real = real * x.real - imaginary * x.imaginary;
				imaginary = real * x.imaginary + imaginary * x.real;
			}

			void operator /=(const complex_number<T>& x)
			{
				real = (real * x.real + x.imaginary * imaginary) / (real ^ 2 + imaginary ^ 2);
				imaginary = (x.imaginary * real - x.real * imaginary) / (real ^ 2 + imaginary ^ 2);
			}

			complex_number<T> get_conjugate() const
			{
				return complex_number<T>(real,imaginary * -1);
			}

			T get_r() const
			{
				return scifir::sqrt(real^2 + imaginary^2);
			}

			angle get_argument() const
			{
				if (imaginary != 0 and real > 0)
				{
					return angle(2 * scifir::atan(imaginary / (real + (scifir::sqrt(real^2 + imaginary^2)))));
				}
				else if (real < 0 and imaginary == 0)
				{
					return angle(180.0f);
				}
				else
				{
					return angle();
				}
			}

			complex_number<T> get_reciprocal() const
			{
				T new_real = real / (real ^ 2 + imaginary ^ 2);
				T new_imaginary = (-1 * imaginary) / (real ^ 2 + imaginary ^ 2);
				return complex_number<T>(new_real,new_imaginary);
			}

			T real;
			T imaginary;
	};

	template<typename T>
	string to_string(const complex_number<T>& x)
	{
		ostringstream output;
		output << x.real << " + " << x.imaginary << "(i)";
		return output.str();
	}

	bool is_complex(const string&);

	template<typename T>
	T abs(const complex_number<T>& x)
	{
		return scifir::sqrt(x.real ^ 2 + x.imaginary ^ 2);
	}

	template<typename T>
	complex_number<T> sqrt(const complex_number<T>& x)
	{
		int sgn_value;
		if (x.imaginary > 0)
		{
			sgn_value = 1;
		}
		else if (x.imaginary < 0)
		{
			sgn_value = -1;
		}
		else
		{
			sgn_value = 0;
		}
		T new_real = scifir::sqrt(x.real + scifir::sqrt(x.real ^ 2 + x.imaginary ^ 2));
		T new_imaginary = sgn_value * scifir::sqrt(((-1) * x.real + scifir::sqrt(x.real ^ 2 + x.imaginary ^ 2)) / 2);
		return complex_number<T>(new_real,new_imaginary);
	}

	template<typename T>
	T sin(complex_number<T> x)
	{
		return std::sin(float(x.real));
	}
}

template<typename T>
bool operator ==(const scifir::complex_number<T>& x, const scifir::complex_number<T>& y)
{
	if (x.real == y.real and x.imaginary == y.imaginary)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::complex_number<T>& x, const scifir::complex_number<T>& y)
{
	return !(x == y);
}

template<typename T>
void operator +=(string& x, const scifir::complex_number<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x, const scifir::complex_number<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::complex_number<T>& x, const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os, const scifir::complex_number<T>& x)
{
	return os << to_string(x);
}

template<typename T>
istream& operator >>(istream& is, scifir::complex_number<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	scifir::complex_number<T> c(b);
	x = c;
	return is;
}

#endif // SCIFIR_UNITS_MECA_NUMBER_COMPLEX_NUMBER_HPP_INCLUDED
