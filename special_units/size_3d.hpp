#ifndef SCIFIR_UNITS_SPECIAL_UNITS_SIZE_3D_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_SIZE_3D_HPP_INCLUDED

#include "../derived_units/space_units.hpp"
#include "../util/types.hpp"

#include "boost/algorithm/string.hpp"

#include <string>

using namespace std;

namespace scifir
{
	template<typename T = length>
	class size_3d
	{
		public:
			size_3d() : width(),height(),depth()
			{}

			size_3d(const size_3d<T>& x) : width(x.width),height(x.height),depth(x.depth)
			{}

			size_3d(size_3d<T>&& x) : width(std::move(x.width)),height(std::move(x.height)),depth(std::move(x.depth))
			{}

			explicit size_3d(const scalar_unit& new_width,const scalar_unit& new_height,const scalar_unit& new_depth) : width(new_width),height(new_height),depth(new_depth)
			{}

			explicit size_3d(const string& new_width,const string& new_height,const string& new_depth) : width(new_width),height(new_height),depth(new_depth)
			{}

			explicit size_3d(const string& init_size_3d) : size_3d()
			{
				initialize_from_string(init_size_3d);
			}

			size_3d<T>& operator =(const size_3d<T>& x)
			{
				width = x.width;
				height = x.height;
				depth = x.depth;
				return *this;
			}

			size_3d<T>& operator =(size_3d<T>&& x)
			{
				width = std::move(x.width);
				height = std::move(x.height);
				depth = std::move(x.depth);
				return *this;
			}

			size_3d<T>& operator =(const string& init_size_3d)
			{
				initialize_from_string(init_size_3d);
				return *this;
			}

			template<typename U>
			size_3d<T> operator +(const size_3d<U>& x) const
			{
				return size_3d<T>(width + x.width,height + x.height,depth + x.depth);
			}

			template<typename U>
			size_3d<T> operator -(const size_3d<U>& x) const
			{
				return size_3d<T>(width - x.width,height - x.height,depth - x.depth);
			}

			template<typename U>
			void operator +=(const size_3d<U>& x)
			{
				width += x.width;
				height += x.height;
				depth += x.depth;
			}

			template<typename U>
			void operator -=(const size_3d<U>& x)
			{
				width -= x.width;
				height -= x.height;
				depth -= x.depth;
			}

			scalar_unit get_volume() const
			{
				return scalar_unit(width * height * depth);
			}

			string display() const
			{
				ostringstream output;
				output << width << " * " << height << " * " << depth;
				return output.str();
			}

			T width;
			T height;
			T depth;

		private:
			void initialize_from_string(const string& init_size_3d)
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
	};

	template<>
	class size_3d<float>
	{
		public:
			size_3d() : width(),height(),depth()
			{}

			size_3d(const size_3d<float>& x) : width(x.width),height(x.height),depth(x.depth)
			{}

			size_3d(size_3d<float>&& x) : width(std::move(x.width)),height(std::move(x.height)),depth(std::move(x.depth))
			{}

			explicit size_3d(const float& new_width,const float& new_height,const float& new_depth) : width(new_width),height(new_height),depth(new_depth)
			{}

			explicit size_3d(const string& new_width,const string& new_height,const string& new_depth) : width(stof(new_width)),height(stof(new_height)),depth(stof(new_depth))
			{}

			explicit size_3d(const string& init_size_3d) : size_3d()
			{
				initialize_from_string(init_size_3d);
			}

			size_3d<float>& operator =(const size_3d<float>& x)
			{
				width = x.width;
				height = x.height;
				depth = x.depth;
				return *this;
			}

			size_3d<float>& operator =(size_3d<float>&& x)
			{
				width = std::move(x.width);
				height = std::move(x.height);
				depth = std::move(x.depth);
				return *this;
			}

			size_3d<float>& operator =(const string& init_size_3d)
			{
				initialize_from_string(init_size_3d);
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

			string display() const
			{
				ostringstream output;
				output << display_float(width,2) << " * " << display_float(height,2) << " * " << display_float(depth,2);
				return output.str();
			}

			float width;
			float height;
			float depth;

		private:
			void initialize_from_string(const string& init_size_3d)
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
	};

	template<typename T>
	string to_string(const size_3d<T>& x)
	{
		return x.display();
	}

	string to_string(const size_3d<float>& x);
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
bool operator ==(const scifir::size_3d<T>& x, const string& init_size_3d)
{
	scifir::size_3d<T> y(init_size_3d);
	return (x == y);
}

template<typename T>
bool operator !=(const scifir::size_3d<T>& x, const string& init_size_3d)
{
	return !(x == init_size_3d);
}

template<typename T>
bool operator ==(const string& init_size_3d, const scifir::size_3d<T>& x)
{
	scifir::size_3d<T> y(init_size_3d);
	return (x == y);
}

template<typename T>
bool operator !=(const string& init_size_3d, const scifir::size_3d<T>& x)
{
	return !(init_size_3d == x);
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
	x = scifir::size_3d<T>(b);
	return is;
}

#endif // SCIFIR_UNITS_SPECIAL_UNITS_SIZE_3D_HPP_INCLUDED
