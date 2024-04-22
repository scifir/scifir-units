#ifndef SCIFIR_UNITS_SPECIAL_UNITS_SIZE_2D_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_SIZE_2D_HPP_INCLUDED

#include "../predefined_units/space_units.hpp"

#include "boost/algorithm/string.hpp"

#include <string>

using namespace std;

namespace scifir
{
	template<typename T = length>
	class size_2d
	{
		public:
			size_2d<T>() : width(),height()
			{}

			size_2d<T>(const size_2d<T>& x) : width(x.width),height(x.height)
			{}

			size_2d<T>(size_2d<T>&& x) : width(move(x.width)),height(move(x.height))
			{}

			explicit size_2d<T>(const T& new_width,const T& new_height) : width(new_width),height(new_height)
			{}

			explicit size_2d<T>(const string& new_width,const string& new_height) : width(new_width),height(new_height)
			{}

			explicit size_2d<T>(const string& init_size_2d) : size_2d<T>()
			{
				vector<string> widths;
				boost::split(widths,init_size_2d,boost::is_any_of("*"));
				if (widths.size() == 2)
				{
					boost::trim(widths[0]);
					boost::trim(widths[1]);
					width = T(widths[0]);
					height = T(widths[1]);
				}
			}

			size_2d<T>& operator=(const size_2d<T>& x)
			{
				width = x.width;
				height = x.height;
				return *this;
			}

			size_2d<T>& operator=(size_2d<T>&& x)
			{
				width = move(x.width);
				height = move(x.height);
				return *this;
			}

			size_2d<T> operator +(const size_2d<T>& x) const
			{
				return size_2d<T>(width + x.width,height + x.height);
			}

			size_2d<T> operator -(const size_2d<T>& x) const
			{
				return size_2d<T>(width - x.width,height - x.height);
			}

			void operator +=(const size_2d<T>& x)
			{
				width += x.width;
				height += x.height;
			}

			void operator -=(const size_2d<T>& x)
			{
				width -= x.width;
				height -= x.height;
			}

			scalar_unit get_area() const
			{
				return scalar_unit(width * height);
			}

			T width;
			T height;
	};

	template<>
	class size_2d<float>
	{
		public:
			size_2d<float>() : width(),height()
			{}

			size_2d<float>(const size_2d<float>& x) : width(x.width),height(x.height)
			{}

			size_2d<float>(size_2d<float>&& x) : width(move(x.width)),height(move(x.height))
			{}

			explicit size_2d<float>(const float& new_width,const float& new_height) : width(new_width),height(new_height)
			{}

			explicit size_2d<float>(const string& new_width,const string& new_height) : width(stof(new_width)),height(stof(new_height))
			{}

			explicit size_2d<float>(const string& init_size_2d) : size_2d<float>()
			{
				vector<string> widths;
				boost::split(widths,init_size_2d,boost::is_any_of("*"));
				if (widths.size() == 2)
				{
					boost::trim(widths[0]);
					boost::trim(widths[1]);
					width = stof(widths[0]);
					height = stof(widths[1]);
				}
			}

			size_2d<float>& operator=(const size_2d<float>& x)
			{
				width = x.width;
				height = x.height;
				return *this;
			}

			size_2d<float>& operator=(size_2d<float>&& x)
			{
				width = move(x.width);
				height = move(x.height);
				return *this;
			}

			size_2d<float> operator +(const size_2d<float>& x) const
			{
				return size_2d<float>(width + x.width,height + x.height);
			}

			size_2d<float> operator -(const size_2d<float>& x) const
			{
				return size_2d<float>(width - x.width,height - x.height);
			}

			void operator +=(const size_2d<float>& x)
			{
				width += x.width;
				height += x.height;
			}

			void operator -=(const size_2d<float>& x)
			{
				width -= x.width;
				height -= x.height;
			}

			float get_area() const
			{
				return width * height;
			}

			float width;
			float height;
	};

	template<typename T>
	string to_string(const size_2d<T>& x)
	{
		ostringstream output;
		output << x.width << " * " << x.height;
		return output.str();
	}

	string to_string(const size_2d<float>&);
}

template<typename T>
bool operator ==(const scifir::size_2d<T>& x, const scifir::size_2d<T>& y)
{
	if (x.width == y.width and x.height == y.height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::size_2d<T>& x, const scifir::size_2d<T>& y)
{
	return !(x == y);
}

template<typename T>
void operator +=(string& x, const scifir::size_2d<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x, const scifir::size_2d<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::size_2d<T>& x, const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os, const scifir::size_2d<T>& x)
{
	return os << to_string(x);
}

template<typename T>
istream& operator >>(istream& is, scifir::size_2d<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	scifir::size_2d<T> c(b);
	x = c;
	return is;
}

#endif // SCIFIR_UNITS_SPECIAL_UNITS_SIZE_2D_HPP_INCLUDED
