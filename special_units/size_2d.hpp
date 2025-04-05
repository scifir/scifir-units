#ifndef SCIFIR_UNITS_SPECIAL_UNITS_SIZE_2D_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_SIZE_2D_HPP_INCLUDED

#include "../derived_units/space_units.hpp"
#include "../util/types.hpp"

#include "boost/algorithm/string.hpp"

#include <string>

using namespace std;

namespace scifir
{
	template<typename T = length>
	class size_2d
	{
		public:
			size_2d() : width(),height()
			{}

			size_2d(const size_2d<T>& x) : width(x.width),height(x.height)
			{}

			size_2d(size_2d<T>&& x) : width(std::move(x.width)),height(std::move(x.height))
			{}

			explicit size_2d(const scalar_unit& new_width,const scalar_unit& new_height) : width(new_width),height(new_height)
			{}

			explicit size_2d(const string& new_width,const string& new_height) : width(new_width),height(new_height)
			{}

			explicit size_2d(const string& init_size_2d) : size_2d()
			{
				initialize_from_string(init_size_2d);
			}

			size_2d<T>& operator =(const size_2d<T>& x)
			{
				width = x.width;
				height = x.height;
				return *this;
			}

			size_2d<T>& operator =(size_2d<T>&& x)
			{
				width = std::move(x.width);
				height = std::move(x.height);
				return *this;
			}

			size_2d<T>& operator =(const string& init_size_2d)
			{
				initialize_from_string(init_size_2d);
				return *this;
			}

			template<typename U>
			size_2d<T> operator +(const size_2d<U>& x) const
			{
				return size_2d<T>(width + x.width,height + x.height);
			}

			template<typename U>
			size_2d<T> operator -(const size_2d<U>& x) const
			{
				return size_2d<T>(width - x.width,height - x.height);
			}

			template<typename U>
			void operator +=(const size_2d<U>& x)
			{
				width += x.width;
				height += x.height;
			}

			template<typename U>
			void operator -=(const size_2d<U>& x)
			{
				width -= x.width;
				height -= x.height;
			}

			scalar_unit get_area() const
			{
				return scalar_unit(width * height);
			}

			string display() const
			{
				ostringstream output;
				output << width << " * " << height;
				return output.str();
			}

			T width;
			T height;

		private:
			void initialize_from_string(const string& init_size_2d)
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
	};

	template<>
	class size_2d<float>
	{
		public:
			size_2d() : width(),height()
			{}

			size_2d(const size_2d<float>& x) : width(x.width),height(x.height)
			{}

			size_2d(size_2d<float>&& x) : width(std::move(x.width)),height(std::move(x.height))
			{}

			explicit size_2d(const float& new_width,const float& new_height) : width(new_width),height(new_height)
			{}

			explicit size_2d(const string& new_width,const string& new_height) : width(stof(new_width)),height(stof(new_height))
			{}

			explicit size_2d(const string& init_size_2d) : size_2d()
			{
				initialize_from_string(init_size_2d);
			}

			size_2d<float>& operator =(const size_2d<float>& x)
			{
				width = x.width;
				height = x.height;
				return *this;
			}

			size_2d<float>& operator =(size_2d<float>&& x)
			{
				width = std::move(x.width);
				height = std::move(x.height);
				return *this;
			}

			size_2d<float>& operator =(const string& init_size_2d)
			{
				initialize_from_string(init_size_2d);
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

			string display() const
			{
				ostringstream output;
				output << display_float(width,2) << " * " << display_float(height,2);
				return output.str();
			}

			float width;
			float height;

		private:
			void initialize_from_string(const string& init_size_2d)
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
	};

	template<typename T>
	string to_string(const size_2d<T>& x)
	{
		return x.display();
	}

	string to_string(const size_2d<float>& x);
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
bool operator ==(const scifir::size_2d<T>& x, const string& init_size_2d)
{
	scifir::size_2d<T> y(init_size_2d);
	return (x == y);
}

template<typename T>
bool operator !=(const scifir::size_2d<T>& x, const string& init_size_2d)
{
	return !(x == init_size_2d);
}

template<typename T>
bool operator ==(const string& init_size_2d, const scifir::size_2d<T>& x)
{
	scifir::size_2d<T> y(init_size_2d);
	return (x == y);
}

template<typename T>
bool operator !=(const string& init_size_2d, const scifir::size_2d<T>& x)
{
	return !(init_size_2d == x);
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
	x = scifir::size_2d<T>(b);
	return is;
}

#endif // SCIFIR_UNITS_SPECIAL_UNITS_SIZE_2D_HPP_INCLUDED
