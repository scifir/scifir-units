#ifndef SCIFIR_UNITS_TOPOLOGY_POINT_1D_HPP_INCLUDED
#define SCIFIR_UNITS_TOPOLOGY_POINT_1D_HPP_INCLUDED

#include "../derived_units/physics_units.hpp"
#include "../units/base_units.hpp"
#include "../util/types.hpp"

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

			explicit point_1d(const scalar_unit& new_x) : x(new_x)
			{}

			template<typename U>
			explicit point_1d(const coordinates_1d<U>& x_coordinates) : x(T(x_coordinates.x))
			{}

			template<typename U>
			explicit point_1d(coordinates_1d<U>&& x_coordinates) : x(T(std::move(x_coordinates.x)))
			{}

			explicit point_1d(const string& init_point_1d) : point_1d()
			{
				initialize_from_string(init_point_1d);
			}

			point_1d<T>& operator =(const point_1d<T>& x_point)
			{
				x = x_point.x;
				return *this;
			}

			point_1d<T>& operator =(point_1d<T>&& x_point)
			{
				x = std::move(x_point.x);
				return *this;
			}

			template<typename U>
			point_1d<T>& operator =(const coordinates_1d<U>& x_coordinates)
			{
				x = T(x_coordinates.x);
				return *this;
			}

			template<typename U>
			point_1d<T>& operator =(coordinates_1d<U>&& x_coordinates)
			{
				x = T(std::move(x_coordinates.x));
				return *this;
			}

			point_1d<T>& operator =(const string& init_point_1d)
			{
				initialize_from_string(init_point_1d);
				return *this;
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
				out << "(" << x << ")";
				return out.str();
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
				x = scalar_unit(T(init_point_1d));
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

			explicit point_1d(const coordinates_1d<float>& x_coordinates);

			explicit point_1d(coordinates_1d<float>&& x_coordinates);

			explicit point_1d(const string& init_point_1d) : point_1d()
			{
				initialize_from_string(init_point_1d);
			}

			point_1d<float>& operator =(const point_1d<float>& x_point)
			{
				x = x_point.x;
				return *this;
			}

			point_1d<float>& operator =(point_1d<float>&& x_point)
			{
				x = std::move(x_point.x);
				return *this;
			}

			point_1d<float>& operator =(const coordinates_1d<float>&);

			point_1d<float>& operator =(coordinates_1d<float>&&);

			point_1d<float>& operator =(const string& init_point_1d)
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

			string display_cartesian() const
			{
				ostringstream out;
				out << "(" << display_float(x) << ")";
				return out.str();
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
		return x.display_cartesian();
	}

	string to_string(const point_1d<float>& x);

	template<typename T,typename U>
	T distance(const point_1d<T>& x,const point_1d<U>& y)
	{
		return T(scifir::sqrt(scifir::pow(x.x - y.x,2)));
	}

	float distance(const point_1d<float>& x,const point_1d<float>& y);
}

template<typename T,typename U>
bool operator ==(const scifir::point_1d<T>& x,const scifir::point_1d<U>& y)
{
	return (x.x == y.x);
}

template<typename T,typename U>
bool operator !=(const scifir::point_1d<T>& x,const scifir::point_1d<U>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::point_1d<T>& x, const string& init_point_1d)
{
	scifir::point_1d<T> y(init_point_1d);
	return (x == y);
}

template<typename T>
bool operator !=(const scifir::point_1d<T>& x, const string& init_point_1d)
{
	return !(x == init_point_1d);
}

template<typename T>
bool operator ==(const string& init_point_1d, const scifir::point_1d<T>& x)
{
	scifir::point_1d<T> y(init_point_1d);
	return (x == y);
}

template<typename T>
bool operator !=(const string& init_point_1d, const scifir::point_1d<T>& x)
{
	return !(init_point_1d == x);
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
	x = scifir::point_1d<T>(b);
	return is;
}

#endif // SCIFIR_UNITS_TOPOLOGY_POINT_1D_HPP_INCLUDED
