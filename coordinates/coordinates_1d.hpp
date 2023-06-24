#ifndef MSCI_UNITS_COORDINATES_COORDINATES_1D_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_COORDINATES_1D_HPP_INCLUDED

#include "topology/point_1d.hpp"
#include "units/unit_basic.hpp"

#include "predefined_units/kinematics_units.hpp"

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	template<typename T>
	class coordinates_1d
	{
		public:
			coordinates_1d<T>() : x()
			{}
			
			coordinates_1d<T>(const coordinates_1d<T>& x_coordinates) : x(x_coordinates.x)
			{}

			coordinates_1d<T>(coordinates_1d<T>&& x_coordinates) : x(std::move(x_coordinates.x))
			{}

			explicit coordinates_1d<T>(const T& new_x) : x(new_x)
			{}

			explicit coordinates_1d<T>(const point_1d<T>& new_point) : x(new_point.x)
			{}

			explicit coordinates_1d<T>(string init_coordinates_1d) : coordinates_1d<T>()
			{
				if (init_coordinates_1d.front() == '(')
				{
					init_coordinates_1d.erase(0,1);
				}
				if (init_coordinates_1d.back() == ')')
				{
					init_coordinates_1d.erase(init_coordinates_1d.size()-1,1);
				}
				x = T(init_coordinates_1d);
			}

			coordinates_1d<T>& operator=(const coordinates_1d<T>& x_coordinates)
			{
				x = x_coordinates.x;
				return *this;
			}

			coordinates_1d<T>& operator=(coordinates_1d<T>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				return *this;
			}

			coordinates_1d<T>& operator=(const point_1d<T>& x_point)
			{
				x = x_point.x;
				return *this;
			}

			void set_position(const T& new_x)
			{
				x = new_x;
			}

			void move(const T& x_value)
			{
				x += x_value;
			}

			T distance_to_origin() const
			{
				return T(std::abs(x.get_value()),x.get_dimensions());
			}

			T x;
	};

	template<>
	class coordinates_1d<float>
	{
		public:
			coordinates_1d<float>() : x()
			{}
			
			coordinates_1d<float>(const coordinates_1d<float>& x_coordinates) : x(x_coordinates.x)
			{}

			coordinates_1d<float>(coordinates_1d<float>&& x_coordinates) : x(std::move(x_coordinates.x))
			{}

			explicit coordinates_1d<float>(const float& new_x) : x(new_x)
			{}

			explicit coordinates_1d<float>(const point_1d<float>& new_point) : x(new_point.x)
			{}

			explicit coordinates_1d<float>(string init_coordinates_1d) : coordinates_1d<float>()
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

			coordinates_1d<float>& operator=(const coordinates_1d<float>& x_coordinates)
			{
				x = x_coordinates.x;
				return *this;
			}

			coordinates_1d<float>& operator=(coordinates_1d<float>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				return *this;
			}

			coordinates_1d<float>& operator=(const point_1d<float>& x_point)
			{
				x = x_point.x;
				return *this;
			}

			
			void set_position(const float& new_x)
			{
				x = new_x;
			}

			void move(const float& x_value)
			{
				x += x_value;
			}

			float distance_to_origin() const
			{
				return float(std::abs(x));
			}

			float x;
	};

	template<typename T>
	string to_string(const coordinates_1d<T>& x)
	{
		ostringstream out;
		out << "(" << x.x <<  ")";
		return out.str();
	}

	template<typename T>
	T distance(const coordinates_1d<T>& x,const coordinates_1d<T>& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2));
	}
	
	float distance(const coordinates_1d<float>&,const coordinates_1d<float>&);

	template<typename T>
	T distance(const coordinates_1d<T>& x,const point_1d<T>& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2));
	}

	float distance(const coordinates_1d<float>&,const point_1d<float>&);

	template<typename T>
	T distance(const point_1d<T>& x,const coordinates_1d<T>& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2));
	}

	float distance(const point_1d<float>&,const coordinates_1d<float>&);
}

template<typename T>
bool operator ==(const msci::coordinates_1d<T>& x,const msci::coordinates_1d<T>& y)
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

template<typename T>
bool operator !=(const msci::coordinates_1d<T>& x,const msci::coordinates_1d<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const msci::coordinates_1d<T>& x,const msci::point_1d<T>& y)
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

template<typename T>
bool operator !=(const msci::coordinates_1d<T>& x,const msci::point_1d<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const msci::point_1d<T>& x,const msci::coordinates_1d<T>& y)
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

template<typename T>
bool operator !=(const msci::point_1d<T>& x,const msci::coordinates_1d<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const msci::coordinates_1d<T>& x, const string& y)
{
	coordinates_1d<T> y_coordinates = coordinates_1d<T>(y);
	return (x == y_coordinates);
}

template<typename T>
bool operator !=(const msci::coordinates_1d<T>& x, const string& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const string& x, const msci::coordinates_1d<T>& y)
{
	coordinates_1d<T> x_coordinates = coordinates_1d<T>(x);
	return (x_coordinates == y);
}

template<typename T>
bool operator !=(const string& x, const msci::coordinates_1d<T>& y)
{
	return !(x == y);
}

template<typename T>
void operator +=(string& x, const msci::coordinates_1d<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x,const msci::coordinates_1d<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const msci::coordinates_1d<T>& x,const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator << (ostream& os,const msci::coordinates_1d<T>& x)
{
	return os << to_string(x);
}

template<typename T>
istream& operator >>(istream& is,msci::coordinates_1d<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::coordinates_1d<T> c(b);
	x = c;
	return is;
}

#endif // MSCI_UNITS_COORDINATES_COORDINATES_1D_HPP_INCLUDED
