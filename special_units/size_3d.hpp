#ifndef SCIFIR_UNITS_SPECIAL_UNITS_SIZE_3D_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_SIZE_3D_HPP_INCLUDED

#include "../predefined_units/space_units.hpp"

#include "boost/algorithm/string.hpp"

#include <string>

using namespace std;

namespace scifir
{
	template<typename T = length>
	class size_3d
	{
		public:
			size_3d<T>() : width(),height(),depth()
			{}

			size_3d<T>(const size_3d<T>& x) : width(x.width),height(x.height),depth(x.depth)
			{}

			size_3d<T>(size_3d<T>&& x) : width(move(x.width)),height(move(x.height)),depth(move(x.depth))
			{}

			explicit size_3d<T>(const T& new_width,const T& new_height,const T& new_depth) : width(new_width),height(new_height),depth(new_depth)
			{}

			explicit size_3d<T>(const string& new_width,const string& new_height,const string& new_depth) : width(new_width),height(new_height),depth(new_depth)
			{}

			explicit size_3d<T>(const string& init_size_3d) : size_3d<T>()
			{
				vector<string> widths;
				boost::split(widths,init_size_3d,boost::is_any_of("*"));
				if (widths.size() == 3)
				{
					boost::trim(widths[0]);
					boost::trim(widths[1]);
					boost::trim(widths[2]);
					width = T(widths[0]);
					height = T(widths[1]);
					depth = T(widths[2]);
				}
			}

			size_3d<T>& operator=(const size_3d<T>& x)
			{
				width = x.width;
				height = x.height;
				depth = x.depth;
				return *this;
			}

			size_3d<T>& operator=(size_3d<T>&& x)
			{
				width = move(x.width);
				height = move(x.height);
				depth = move(x.depth);
				return *this;
			}

			size_3d<T> operator +(const size_3d<T>& x) const
			{
				return size_3d<T>(width + x.width,height + x.height,depth + x.depth);
			}

			size_3d<T> operator -(const size_3d<T>& x) const
			{
				return size_3d<T>(width - x.width,height - x.height,depth - x.depth);
			}

			void operator +=(const size_3d<T>& x)
			{
				width += x.width;
				height += x.height;
				depth += x.depth;
			}

			void operator -=(const size_3d<T>& x)
			{
				width -= x.width;
				height -= x.height;
				depth -= x.depth;
			}

			scalar_unit get_volume() const
			{
				return scalar_unit(width * height * depth);
			}

			T width;
			T height;
			T depth;
	};

	template<>
	class size_3d<float>
	{
		public:
			size_3d<float>() : width(),height(),depth()
			{}

			size_3d<float>(const size_3d<float>& x) : width(x.width),height(x.height),depth(x.depth)
			{}

			size_3d<float>(size_3d<float>&& x) : width(move(x.width)),height(move(x.height)),depth(move(x.depth))
			{}

			explicit size_3d<float>(const float& new_width,const float& new_height,const float& new_depth) : width(new_width),height(new_height),depth(new_depth)
			{}

			explicit size_3d<float>(const string& new_width,const string& new_height,const string& new_depth) : width(stof(new_width)),height(stof(new_height)),depth(stof(new_depth))
			{}

			explicit size_3d<float>(const string& init_size_3d) : size_3d<float>()
			{
				vector<string> widths;
				boost::split(widths,init_size_3d,boost::is_any_of("*"));
				if (widths.size() == 3)
				{
					boost::trim(widths[0]);
					boost::trim(widths[1]);
					boost::trim(widths[2]);
					width = stof(widths[0]);
					height = stof(widths[1]);
					depth = stof(widths[2]);
				}
			}

			size_3d<float>& operator=(const size_3d<float>& x)
			{
				width = x.width;
				height = x.height;
				depth = x.depth;
				return *this;
			}

			size_3d<float>& operator=(size_3d<float>&& x)
			{
				width = move(x.width);
				height = move(x.height);
				depth = move(x.depth);
				return *this;
			}

			size_3d<float> operator +(const size_3d<float>& x) const
			{
				return size_3d<float>(width + x.width,height + x.height,depth + x.depth);
			}

			size_3d<float> operator -(const size_3d<float>& x) const
			{
				return size_3d<float>(width - x.width,height - x.height,depth - x.depth);
			}

			void operator +=(const size_3d<float>& x)
			{
				width += x.width;
				height += x.height;
				depth += x.depth;
			}

			void operator -=(const size_3d<float>& x)
			{
				width -= x.width;
				height -= x.height;
				depth -= x.depth;
			}

			float get_volume() const
			{
				return width * height * depth;
			}

			float width;
			float height;
			float depth;
	};

	template<typename T>
	string to_string(const size_3d<T>& x)
	{
		ostringstream output;
		output << x.width << " * " << x.height << " * " << x.depth;
		return output.str();
	}

	string to_string(const size_3d<float>&);
}

template<typename T>
bool operator ==(const scifir::size_3d<T>& x, const scifir::size_3d<T>& y)
{
	if (x.width == y.width and x.height == y.height and x.depth == y.depth)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::size_3d<T>& x, const scifir::size_3d<T>& y)
{
	return !(x == y);
}

template<typename T>
void operator +=(string& x, const scifir::size_3d<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x, const scifir::size_3d<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::size_3d<T>& x, const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os, const scifir::size_3d<T>& x)
{
	return os << to_string(x);
}

template<typename T>
istream& operator >>(istream& is, scifir::size_3d<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	scifir::size_3d<T> c(b);
	x = c;
	return is;
}

#endif // SCIFIR_UNITS_SPECIAL_UNITS_SIZE_3D_HPP_INCLUDED
