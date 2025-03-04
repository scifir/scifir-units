#ifndef SCIFIR_UNITS_COORDINATES_COORDINATES_1D_HPP_INCLUDED
#define SCIFIR_UNITS_COORDINATES_COORDINATES_1D_HPP_INCLUDED

#include "../topology/point_1d.hpp"
#include "../units/base_units.hpp"
#include "../derived_units/physics_units.hpp"

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

namespace scifir
{
	template<typename T = length>
	class coordinates_1d
	{
		public:
			coordinates_1d() : x()
			{}
			
			coordinates_1d(const coordinates_1d<T>& x_coordinates) : x(x_coordinates.x)
			{}

			coordinates_1d(coordinates_1d<T>&& x_coordinates) : x(std::move(x_coordinates.x))
			{}

			explicit coordinates_1d(const scalar_unit& new_x) : x(new_x)
			{}

			template<typename U>
			explicit coordinates_1d(const point_1d<U>& new_point) : x(new_point.x)
			{}

			template<typename U>
			explicit coordinates_1d(point_1d<U>&& new_point) : x(std::move(new_point.x))
			{}

			explicit coordinates_1d(const string& init_coordinates_1d) : coordinates_1d()
			{
				initialize_from_string(init_coordinates_1d);
			}

			coordinates_1d<T>& operator =(const coordinates_1d<T>& x_coordinates)
			{
				x = x_coordinates.x;
				return *this;
			}

			coordinates_1d<T>& operator =(coordinates_1d<T>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				return *this;
			}

			coordinates_1d<T>& operator =(const point_1d<T>& x_point)
			{
				x = x_point.x;
				return *this;
			}

			coordinates_1d<T>& operator =(point_1d<T>&& x_point)
			{
				x = std::move(x_point.x);
				return *this;
			}

			coordinates_1d<T>& operator =(const string& init_coordinates_1d)
			{
				initialize_from_string(init_coordinates_1d);
				return *this;
			}

			static coordinates_1d<T> origin(const coordinates_1d<T>& origin,const coordinates_1d<T>& coordinates)
			{
				coordinates_1d<T> new_coordinates(origin);
				new_coordinates.move(coordinates.x);
				return new_coordinates;
			}

			void set_position(const scalar_unit& new_x)
			{
				x = new_x;
			}

			void move(const scalar_unit& x_value)
			{
				x += x_value;
			}

			T distance_to_origin() const
			{
				return T(std::abs(x.get_value()),x.get_dimensions());
			}

			string display_cartesian() const
			{
				ostringstream out;
				out << "(" << x <<  ")";
				return out.str();
			}

			T x;

		private:
			void initialize_from_string(string init_coordinates_1d)
			{
				if (init_coordinates_1d.front() == '(')
				{
					init_coordinates_1d.erase(0,1);
				}
				if (init_coordinates_1d.back() == ')')
				{
					init_coordinates_1d.erase(init_coordinates_1d.size()-1,1);
				}
				x = scalar_unit(T(init_coordinates_1d));
			}
	};

	template<>
	class coordinates_1d<float>
	{
		public:
			coordinates_1d() : x()
			{}
			
			coordinates_1d(const coordinates_1d<float>& x_coordinates) : x(x_coordinates.x)
			{}

			coordinates_1d(coordinates_1d<float>&& x_coordinates) : x(std::move(x_coordinates.x))
			{}

			explicit coordinates_1d(float new_x) : x(new_x)
			{}

			explicit coordinates_1d(const point_1d<float>& new_point) : x(new_point.x)
			{}

			explicit coordinates_1d(point_1d<float>&& new_point) : x(std::move(new_point.x))
			{}

			explicit coordinates_1d(const string& init_coordinates_1d) : coordinates_1d()
			{
				initialize_from_string(init_coordinates_1d);
			}

			coordinates_1d<float>& operator =(const coordinates_1d<float>& x_coordinates)
			{
				x = x_coordinates.x;
				return *this;
			}

			coordinates_1d<float>& operator =(coordinates_1d<float>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				return *this;
			}

			coordinates_1d<float>& operator =(const point_1d<float>& x_point)
			{
				x = x_point.x;
				return *this;
			}

			coordinates_1d<float>& operator =(point_1d<float>&& x_point)
			{
				x = std::move(x_point.x);
				return *this;
			}

			coordinates_1d<float>& operator =(const string& init_coordinates_1d)
			{
				initialize_from_string(init_coordinates_1d);
				return *this;
			}

			void set_position(float new_x)
			{
				x = new_x;
			}

			void move(float x_value)
			{
				x += x_value;
			}

			float distance_to_origin() const
			{
				return float(std::abs(x));
			}

			string display_cartesian() const
			{
				ostringstream out;
				out << "(" << display_float(x) <<  ")";
				return out.str();
			}

			float x;

		private:
			void initialize_from_string(string init_coordinates_1d)
			{
				if (init_coordinates_1d.front() == '(')
				{
					init_coordinates_1d.erase(0,1);
				}
				if (init_coordinates_1d.back() == ')')
				{
					init_coordinates_1d.erase(init_coordinates_1d.size()-1,1);
				}
				x = stof(init_coordinates_1d);
			}
	};

	template<typename T>
	string to_string(const coordinates_1d<T>& x)
	{
		return x.display_cartesian();
	}

	string to_string(const coordinates_1d<float>& x);

	template<typename T,typename U>
	T distance(const coordinates_1d<T>& x,const coordinates_1d<U>& y)
	{
		return T(scifir::sqrt(scifir::pow(x.x - y.x,2)));
	}
	
	float distance(const coordinates_1d<float>& x,const coordinates_1d<float>& y);

	template<typename T,typename U>
	T distance(const coordinates_1d<T>& x,const point_1d<U>& y)
	{
		return T(scifir::sqrt(scifir::pow(x.x - y.x,2)));
	}

	float distance(const coordinates_1d<float>& x,const point_1d<float>& y);

	template<typename T,typename U>
	T distance(const point_1d<T>& x,const coordinates_1d<U>& y)
	{
		return T(scifir::sqrt(scifir::pow(x.x - y.x,2)));
	}

	float distance(const point_1d<float>& x,const coordinates_1d<float>& y);
}

template<typename T,typename U>
bool operator ==(const scifir::coordinates_1d<T>& x,const scifir::coordinates_1d<U>& y)
{
	if (x.x == y.x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T,typename U>
bool operator !=(const scifir::coordinates_1d<T>& x,const scifir::coordinates_1d<U>& y)
{
	return !(x == y);
}

template<typename T,typename U>
bool operator ==(const scifir::coordinates_1d<T>& x,const scifir::point_1d<U>& y)
{
	if (x.x == y.x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T,typename U>
bool operator !=(const scifir::coordinates_1d<T>& x,const scifir::point_1d<U>& y)
{
	return !(x == y);
}

template<typename T,typename U>
bool operator ==(const scifir::point_1d<T>& x,const scifir::coordinates_1d<U>& y)
{
	if (x.x == y.x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T,typename U>
bool operator !=(const scifir::point_1d<T>& x,const scifir::coordinates_1d<U>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_1d<T>& x, const string& init_coordinates_1d)
{
	scifir::coordinates_1d<T> y(init_coordinates_1d);
	return (x == y);
}

template<typename T>
bool operator !=(const scifir::coordinates_1d<T>& x, const string& init_coordinates_1d)
{
	return !(x == init_coordinates_1d);
}

template<typename T>
bool operator ==(const string& init_coordinates_1d, const scifir::coordinates_1d<T>& x)
{
	scifir::coordinates_1d<T> y(init_coordinates_1d);
	return (x == y);
}

template<typename T>
bool operator !=(const string& init_coordinates_1d, const scifir::coordinates_1d<T>& x)
{
	return !(init_coordinates_1d == x);
}

template<typename T>
void operator +=(string& x, const scifir::coordinates_1d<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x,const scifir::coordinates_1d<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::coordinates_1d<T>& x,const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os,const scifir::coordinates_1d<T>& x)
{
	return os << to_string(x);
}

ostream& operator <<(ostream& os,const scifir::coordinates_1d<float>& x);

template<typename T>
istream& operator >>(istream& is,scifir::coordinates_1d<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	x = scifir::coordinates_1d<T>(b);
	return is;
}

#endif // SCIFIR_UNITS_COORDINATES_COORDINATES_1D_HPP_INCLUDED
