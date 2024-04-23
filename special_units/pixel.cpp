#include "./pixel.hpp"

#include "../util/types.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace scifir
{
	pixel::pixel() : value(0)
	{}
	
	pixel::pixel(const pixel& x) : value(x.get_value())
	{}
	
	pixel::pixel(pixel&& x) : value(move(x.get_value()))
	{}

	pixel::pixel(float x) : value(x)
	{}
	
	pixel::pixel(string init_pixel) : value()
	{
		if (init_pixel.substr(init_pixel.length() - 3,3) == " px")
		{
			value = stof(init_pixel.substr(0,init_pixel.length() - 3));
		}
		else if (init_pixel.substr(init_pixel.length() - 2,2) == "px")
		{
			value = stof(init_pixel.substr(0,init_pixel.length() - 2));
		}
		else
		{
			value = stof(init_pixel);
		}
	}

	pixel::pixel(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = float(x);
		}
		else
		{
			cerr << "An pixel cannot be initialized with dimensions";
			value = 0;
		}
	}

	pixel& pixel::operator=(const pixel& x)
	{
		value = x.get_value();
		return *this;
	}

	pixel& pixel::operator=(pixel&& x)
	{
		value = move(x.get_value());
		return *this;
	}

	pixel& pixel::operator=(float x)
	{
		value = x;
		return *this;
	}

	pixel& pixel::operator=(string& init_pixel)
	{
		if (init_pixel.substr(init_pixel.length() - 3,3) == " px")
		{
			value = stof(init_pixel.substr(0,init_pixel.length() - 3));
		}
		else if (init_pixel.substr(init_pixel.length() - 2,2) == "px")
		{
			value = stof(init_pixel.substr(0,init_pixel.length() - 2));
		}
		else
		{
			value = stof(init_pixel);
		}
		return *this;
	}

	pixel& pixel::operator=(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = x.get_value();
		}
		else
		{
			cerr << "An pixel cannot be initialized with dimensions";
		}
		return *this;
	}

	pixel pixel::operator +(const pixel& x) const
	{
		return pixel(value + x.get_value());
	}

	pixel pixel::operator -(const pixel& x) const
	{
		return pixel(value - x.get_value());
	}
	
	pixel pixel::operator *(const pixel& x) const
	{
		return pixel(value * x.get_value());
	}
	
	pixel pixel::operator /(const pixel& x) const
	{
		return pixel(value / x.get_value());
	}
	
	pixel pixel::operator ^(const pixel& x) const
	{
		return pixel(std::pow(value,x.get_value()));
	}

	void pixel::operator +=(const pixel& x)
	{
		value += x.get_value();
	}

	void pixel::operator -=(const pixel& x)
	{
		value -= x.get_value();
	}
	
	void pixel::operator *=(const pixel& x)
	{
		value *= x.get_value();
	}
	
	void pixel::operator /=(const pixel& x)
	{
		value /= x.get_value();
	}
	
	void pixel::operator ^=(const pixel& x)
	{
		value = std::pow(value,x.get_value());
	}
	
	pixel& pixel::operator++()
	{
		value++;
		return *this;
	}

	pixel pixel::operator++(int)
	{
		pixel tmp = pixel(*this);
		operator++();
		return tmp;
	}

	pixel& pixel::operator--()
	{
		value--;
		return *this;
	}

	pixel pixel::operator--(int)
	{
		pixel tmp = pixel(*this);
		operator--();
		return tmp;
	}

	string to_string(const pixel& x)
	{
		ostringstream output;
		output << display_float(x.get_value()) << " px";
		return output.str();
	}

	bool is_pixel(const string& x)
	{
		int iteration_limit;
		if (x.substr(x.length() - 3,3) == " px")
		{
			iteration_limit = x.length() - 3;
		}
		else if (x.substr(x.length() - 2,2) == "px")
		{
			iteration_limit = x.length() - 2;
		}
		else
		{
			iteration_limit = x.length();
		}
		bool dot_present = false;
		for (int i = 0; i < iteration_limit; i++)
		{
			if (x[i] == '.')
			{
				if (dot_present)
				{
					return false;
				}
				else
				{
					dot_present = true;
				}
			}
			else if (!std::isdigit(x[i]))
			{
				return false;
			}
		}
		return true;
	}

	pixel sqrt(const pixel& x)
	{
		return pixel(std::sqrt(x.get_value()));
	}

	pixel sqrt_nth(const pixel& x, int y)
	{
		return pixel(std::pow(x.get_value(), 1 / y));
	}
}

bool operator ==(const scifir::pixel& x, const scifir::pixel& y)
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

bool operator !=(const scifir::pixel& x, const scifir::pixel& y)
{
	return !(x == y);
}

bool operator <(const scifir::pixel& x, const scifir::pixel& y)
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

bool operator >(const scifir::pixel& x, const scifir::pixel& y)
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

bool operator <=(const scifir::pixel& x, const scifir::pixel& y)
{
	return !(x > y);
}

bool operator >=(const scifir::pixel& x, const scifir::pixel& y)
{
	return !(x < y);
}

bool operator ==(const scifir::pixel& x, const string& y)
{
	scifir::pixel y_pixel = scifir::pixel(y);
	return (x == y_pixel);
}

bool operator !=(const scifir::pixel& x, const string& y)
{
	return !(x == y);
}

bool operator ==(const string& x, const scifir::pixel& y)
{
	scifir::pixel x_pixel = scifir::pixel(x);
	return (x_pixel == y);
}

bool operator !=(const string& x, const scifir::pixel& y)
{
	return !(x == y);
}

void operator +=(string& x, const scifir::pixel& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const scifir::pixel& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const scifir::pixel& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const scifir::pixel& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, scifir::pixel& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	scifir::pixel c(b);
	x = c;
	return is;
}

