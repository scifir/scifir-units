#ifndef SCIFIR_UNITS_TOPOLOGY_POINT_1D_HPP_INCLUDED
#define SCIFIR_UNITS_TOPOLOGY_POINT_1D_HPP_INCLUDED

#include "../predefined_units/physics_units.hpp"
#include "../units/unit_basic.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace scifir
{
	template<typename T>
	class coordinates_1d;

	template<typename T = length>
	class point_1d
	{
		public:
			point_1d() : x()
			{}

			point_1d(const point_1d<T>& x_point) : x(x_point.x)
			{}

			point_1d(point_1d<T>&& x_point) : x(std::move(x_point.x))
			{}

			explicit point_1d(const T& new_x) : x(new_x)
			{}

			explicit point_1d(const coordinates_1d<T>&);

			explicit point_1d(coordinates_1d<T>&&);

			explicit point_1d(const string& init_point_1d) : point_1d()
			{
				initialize_from_string(init_point_1d);
			}

			point_1d<T>& operator=(const point_1d<T>& x_point)
			{
				x = x_point.x;
				return *this;
			}

			point_1d<T>& operator=(point_1d<T>&& x_point)
			{
				x = std::move(x_point.x);
				return *this;
			}

			point_1d<T>& operator=(const coordinates_1d<T>&);

			point_1d<T>& operator=(coordinates_1d<T>&&);

			point_1d<T>& operator=(const string& init_point_1d)
			{
				initialize_from_string(init_point_1d);
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

		private:
			void initialize_from_string(string init_point_1d)
			{
				if (init_point_1d.front() == '(')
				{
					init_point_1d.erase(0,1);
				}
				if (init_point_1d.back() == ')')
				{
					init_point_1d.erase(init_point_1d.size()-1,1);
				}
				x = T(init_point_1d);
			}
	};

	template<>
	class point_1d<float>
	{
		public:
			point_1d() : x()
			{}

			point_1d(const point_1d<float>& x_point) : x(x_point.x)
			{}

			point_1d(point_1d<float>&& x_point) : x(std::move(x_point.x))
			{}

			explicit point_1d(float new_x) : x(new_x)
			{}

			explicit point_1d(const coordinates_1d<float>&);

			explicit point_1d(coordinates_1d<float>&&);

			explicit point_1d(const string& init_point_1d) : point_1d()
			{
				initialize_from_string(init_point_1d);
			}

			point_1d<float>& operator=(const point_1d<float>& x_point)
			{
				x = x_point.x;
				return *this;
			}

			point_1d<float>& operator=(point_1d<float>&& x_point)
			{
				x = std::move(x_point.x);
				return *this;
			}

			point_1d<float>& operator=(const coordinates_1d<float>&);

			point_1d<float>& operator=(coordinates_1d<float>&&);

			point_1d<float>& operator=(const string& init_point_1d)
			{
				initialize_from_string(init_point_1d);
				return *this;
			}

			void set_position(const float& new_x)
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

			float x;

		private:
			void initialize_from_string(string init_point_1d)
			{
				if (init_point_1d.front() == '(')
				{
					init_point_1d.erase(0,1);
				}
				if (init_point_1d.back() == ')')
				{
					init_point_1d.erase(init_point_1d.size()-1,1);
				}
				x = stof(init_point_1d);
			}
	};

	template<typename T>
	string to_string(const point_1d<T>& x)
	{
		ostringstream out;
		out << "(" << x.x << ")";
		return out.str();
	}

	template<typename T>
	T distance(const point_1d<T>& x1,const point_1d<T>& x2)
	{
		return scifir::sqrt(scifir::pow(x1.x - x2.x,2));
	}

	float distance(const point_1d<float>&,const point_1d<float>&);
}

template<typename T>
bool operator ==(const scifir::point_1d<T>& x,const scifir::point_1d<T>& y)
{
	return (x.x == y.x);
}

template<typename T>
bool operator !=(const scifir::point_1d<T>& x,const scifir::point_1d<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::point_1d<T>& x, const string& y)
{
	point_1d<T> y_point = point_1d<T>(y);
	return (x == y_point);
}

template<typename T>
bool operator !=(const scifir::point_1d<T>& x, const string& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const string& x, const scifir::point_1d<T>& y)
{
	point_1d<T> x_point = point_1d<T>(x);
	return (x_point == y);
}

template<typename T>
bool operator !=(const string& x, const scifir::point_1d<T>& y)
{
	return !(x == y);
}

template<typename T>
void operator +=(string& x, const scifir::point_1d<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x,const scifir::point_1d<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::point_1d<T>& x,const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os,const scifir::point_1d<T>& x)
{
	return os << to_string(x);
}

ostream& operator <<(ostream& os,const scifir::point_1d<float>& x);

template<typename T>
istream& operator >>(istream& is, scifir::point_1d<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	scifir::point_1d<T> c(b);
	x = c;
	return is;
}

#endif // SCIFIR_UNITS_TOPOLOGY_POINT_1D_HPP_INCLUDED
