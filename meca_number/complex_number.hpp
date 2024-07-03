#ifndef SCIFIR_UNITS_MECA_NUMBER_COMPLEX_NUMBER_HPP_INCLUDED
#define SCIFIR_UNITS_MECA_NUMBER_COMPLEX_NUMBER_HPP_INCLUDED

#include "../meca_number/angle.hpp"
#include "../util/is_number.hpp"
#include "../units/scalar_unit.hpp"
#include "../util/types.hpp"

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

			explicit complex_number(const T& x,const T& y) : real(x),imaginary(y)
			{}

			explicit complex_number(const string& x,const string& y) : real(x),imaginary(y)
			{}

			explicit complex_number(const string& init_complex_number) : complex_number()
			{
				if (init_complex_number.find("+") != string::npos or init_complex_number.find("-") != string::npos)
				{
					vector<string> numbers;
					boost::split(numbers,init_complex_number,boost::is_any_of("+-"));
					if (numbers.size() == 2)
					{
						boost::trim(numbers[0]);
						boost::trim(numbers[1]);
						if (numbers[1].substr(numbers[1].length() - 3) == "(i)")
						{
							real = T(numbers[0]);
							imaginary = T(numbers[1].substr(0,numbers[1].length() - 3));
							if (init_complex_number.find("-") != string::npos)
							{
								imaginary *= -1;
							}
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

			complex_number<T>& operator =(const complex_number<T>& x)
			{
				real = x.real;
				imaginary = x.imaginary;
				return *this;
			}

			complex_number<T>& operator =(complex_number<T>&& x)
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

			template<typename U>
			complex_number<scalar_unit> operator *(const complex_number<U>& x) const
			{
				return complex_number<scalar_unit>(real * x.real - imaginary * x.imaginary,real * x.imaginary + imaginary * x.real);
			}

			template<typename U>
			complex_number<scalar_unit> operator /(const complex_number<U>& x) const
			{
				scalar_unit new_real = (real * x.real + x.imaginary * imaginary) / ((real^2) + (imaginary^2));
				scalar_unit new_imaginary = (x.imaginary * real - x.real * imaginary) / ((real^2) + (imaginary^2));
				return complex_number<scalar_unit>(new_real,new_imaginary);
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

			complex_number<T> get_conjugate() const
			{
				return complex_number<T>(real,imaginary * -1);
			}

			T get_r() const
			{
				return scifir::sqrt((real^2) + (imaginary^2));
			}

			angle get_argument() const
			{
				if (imaginary != 0 and real > 0)
				{
					return angle(2 * scifir::atan(float(imaginary / (real + (scifir::sqrt((real^2) + (imaginary^2)))))));
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

			complex_number<scalar_unit> get_reciprocal() const
			{
				scalar_unit new_real = real / ((real^2) + (imaginary^2));
				scalar_unit new_imaginary = (-1 * imaginary) / ((real^2) + (imaginary^2));
				return complex_number<scalar_unit>(new_real,new_imaginary);
			}

			string display(int number_of_decimals = 2) const
			{
				ostringstream output;
				output << real.display(number_of_decimals);
				if (imaginary >= 0)
				{
					output << " + ";
				}
				else
				{
					output << " - ";
				}
				output << display_float(std::abs(imaginary.get_value()),number_of_decimals) << " " << imaginary.display_dimensions() << "(i)";
				return output.str();
			}

			T real;
			T imaginary;
	};

	template<typename T>
	string to_string(const complex_number<T>& x)
	{
		ostringstream output;
		output << x.display(2);
		return output.str();
	}

	bool is_complex(const string& init_complex_number);

	template<typename T>
	T abs(const complex_number<T>& x)
	{
		return scifir::sqrt((x.real^2) + (x.imaginary^2));
	}

	template<typename T>
	complex_number<scalar_unit> sqrt(const complex_number<T>& x)
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
		scalar_unit new_real = scifir::sqrt(x.real + scifir::sqrt((x.real^2) + (x.imaginary^2)));
		scalar_unit new_imaginary = sgn_value * scifir::sqrt(((-1) * x.real + scifir::sqrt((x.real^2) + (x.imaginary^2))) / 2);
		return complex_number<scalar_unit>(new_real,new_imaginary);
	}

	/*template<typename T>
	T sin(complex_number<T> x)
	{
		return std::sin(float(x.real));
	}*/
}

template<typename T,typename U>
bool operator ==(const scifir::complex_number<T>& x, const scifir::complex_number<U>& y)
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

template<typename T,typename U>
bool operator !=(const scifir::complex_number<T>& x, const scifir::complex_number<U>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::complex_number<T>& x, const string& init_complex_number)
{
	return (x == scifir::complex_number<scifir::scalar_unit>(init_complex_number));
}

template<typename T>
bool operator !=(const scifir::complex_number<T>& x, const string& init_complex_number)
{
	return !(x == init_complex_number);
}

template<typename T>
bool operator ==(const string& init_complex_number, const scifir::complex_number<T>& x)
{
	return (scifir::complex_number<scifir::scalar_unit>(init_complex_number) == x);
}

template<typename T>
bool operator !=(const string& init_complex_number, const scifir::complex_number<T>& x)
{
	return !(init_complex_number == x);
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
	x = scifir::complex_number<T>(b);
	return is;
}

#endif // SCIFIR_UNITS_MECA_NUMBER_COMPLEX_NUMBER_HPP_INCLUDED
