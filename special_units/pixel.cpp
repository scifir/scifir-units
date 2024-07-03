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
	
	pixel::pixel(pixel&& x) : value(std::move(x.get_value()))
	{}

	pixel::pixel(float new_value) : value(new_value)
	{}

	pixel::pixel(double new_value) : value(float(new_value))
	{}

	pixel::pixel(long double new_value) : value(float(new_value))
	{}

	pixel::pixel(int new_value) : value(float(new_value))
	{}
	
	pixel::pixel(const string& init_pixel) : value()
	{
		initialize_from_string(init_pixel);
	}

	pixel::pixel(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = float(x);
		}
		else
		{
			cerr << "An pixel cannot be initialized with dimensions" << endl;
			value = 0;
		}
	}

	pixel& pixel::operator =(const pixel& x)
	{
		value = x.get_value();
		return *this;
	}

	pixel& pixel::operator =(pixel&& x)
	{
		value = std::move(x.get_value());
		return *this;
	}

	pixel& pixel::operator =(float new_value)
	{
		value = new_value;
		return *this;
	}

	pixel& pixel::operator =(const string& init_pixel)
	{
		initialize_from_string(init_pixel);
		return *this;
	}

	pixel& pixel::operator =(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = x.get_value();
		}
		else
		{
			cerr << "An pixel cannot be initialized with dimensions" << endl;
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

	void pixel::initialize_from_string(const string& init_pixel)
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

	string to_string(const pixel& x)
	{
		ostringstream output;
		output << display_float(x.get_value()) << " px";
		return output.str();
	}

	bool is_pixel(const string& init_pixel)
	{
		int iteration_limit;
		if (init_pixel.substr(init_pixel.length() - 3,3) == " px")
		{
			iteration_limit = int(init_pixel.length()) - 3;
		}
		else if (init_pixel.substr(init_pixel.length() - 2,2) == "px")
		{
			iteration_limit = int(init_pixel.length()) - 2;
		}
		else
		{
			iteration_limit = int(init_pixel.length());
		}
		bool dot_present = false;
		for (int i = 0; i < iteration_limit; i++)
		{
			if (init_pixel[i] == '.')
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
			else if (!std::isdigit(init_pixel[i]))
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

	pixel sqrt_nth(const pixel& x, int index)
	{
		return pixel(std::pow(x.get_value(), 1.0f / index));
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

bool operator ==(const scifir::pixel& x, const string& init_pixel)
{
	scifir::pixel y = scifir::pixel(init_pixel);
	return (x == y);
}

bool operator !=(const scifir::pixel& x, const string& init_pixel)
{
	return !(x == init_pixel);
}

bool operator ==(const string& init_pixel, const scifir::pixel& x)
{
	scifir::pixel y = scifir::pixel(init_pixel);
	return (y == x);
}

bool operator !=(const string& init_pixel, const scifir::pixel& x)
{
	return !(init_pixel == x);
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
	x = scifir::pixel(b);
	return is;
}

