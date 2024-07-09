#ifndef SCIFIR_UNITS_COORDINATES_COORDINATES_2D_HPP_INCLUDED
#define SCIFIR_UNITS_COORDINATES_COORDINATES_2D_HPP_INCLUDED

#include "../topology/point_2d.hpp"
#include "../units/unit_basic.hpp"
#include "../predefined_units/physics_units.hpp"
#include "../util/types.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace scifir
{
	template<typename T = length>
	class coordinates_2d
	{
		public:
			coordinates_2d() : x(),y()
			{}

			coordinates_2d(const coordinates_2d<T>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y)
			{}

			coordinates_2d(coordinates_2d<T>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y))
			{}

			explicit coordinates_2d(const T& new_x,const T& new_y) : x(new_x),y(new_y)
			{}

			explicit coordinates_2d(const T& new_p,const angle& new_theta)
			{
				set_position(new_p,new_theta);
			}

			explicit coordinates_2d(const scifir::point_2d<T>& new_point) : x(new_point.x),y(new_point.y)
			{}

			explicit coordinates_2d(scifir::point_2d<T>&& new_point) : x(std::move(new_point.x)),y(std::move(new_point.y))
			{}

			explicit coordinates_2d(const string& init_coordinates_2d) : coordinates_2d()
			{
				initialize_from_string(init_coordinates_2d);
			}

			coordinates_2d<T>& operator =(const coordinates_2d<T>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				return *this;
			}

			coordinates_2d<T>& operator =(coordinates_2d<T>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				y = std::move(x_coordinates.y);
				return *this;
			}

			coordinates_2d<T>& operator =(const point_2d<T>& x_point)
			{
				x = x_point.x;
				y = x_point.y;
				return *this;
			}

			coordinates_2d<T>& operator =(point_2d<T>&& x_point)
			{
				x = std::move(x_point.x);
				y = std::move(x_point.y);
				return *this;
			}

			coordinates_2d<T>& operator =(const string& init_coordinates_2d)
			{
				initialize_from_string(init_coordinates_2d);
				return *this;
			}

			T get_p() const
			{
				return scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2));
			}

			angle get_theta() const
			{
				return angle(radian_to_grade(std::atan2(y.get_value(),x.get_value())));
			}

			void set_position(const T& new_x,const T& new_y)
			{
				x = new_x;
				y = new_y;
			}

			void set_position(const T& new_p,const angle& new_theta)
			{
				x = T(new_p * scifir::cos(new_theta));
				y = T(new_p * scifir::sin(new_theta));
			}

			void rotate(const angle& x_angle)
			{
				T x_coord = x;
				T y_coord = y;
				x = x_coord * scifir::cos(x_angle) - y_coord * scifir::sin(x_angle);
				y = x_coord * scifir::sin(x_angle) + y_coord * scifir::cos(x_angle);
			}

			void move(const displacement_2d& x_displacement)
			{
				x += x_displacement.x_projection();
				y += x_displacement.y_projection();
			}

			void move(const T& new_x,const T& new_y)
			{
				x += new_x;
				y += new_y;
			}

			void move(const T& new_p,const angle& new_theta)
			{
				x += new_p * scifir::cos(new_theta);
				y += new_p * scifir::sin(new_theta);
			}

			T distance_to_origin() const
			{
				return scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2));
			}

			string display_cartesian() const
			{
				ostringstream out;
				out << "(" << x << "," << y << ")";
				return out.str();
			}

			string display_polar() const
			{
				ostringstream out;
				out << "(" << get_p() << "," << get_theta() << ")";
				return out.str();
			}

			T x;
			T y;

		private:
			void initialize_from_string(string init_coordinates_2d)
			{
				vector<string> values;
				if (init_coordinates_2d.front() == '(')
				{
					init_coordinates_2d.erase(0,1);
				}
				if (init_coordinates_2d.back() == ')')
				{
					init_coordinates_2d.erase(init_coordinates_2d.size()-1,1);
				}
				boost::split(values,init_coordinates_2d,boost::is_any_of(","));
				if (values.size() == 2)
				{
					if (is_angle(values[1]))
					{
						set_position(T(values[0]),angle(values[1]));
					}
					else
					{
						set_position(T(values[0]),T(values[1]));
					}
				}
			}
	};

	template<>
	class coordinates_2d<float>
	{
		public:
			coordinates_2d() : x(),y()
			{}

			coordinates_2d(const coordinates_2d<float>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y)
			{}

			coordinates_2d(coordinates_2d<float>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y))
			{}

			explicit coordinates_2d(float new_x,float new_y) : x(new_x),y(new_y)
			{}

			explicit coordinates_2d(float new_p,const angle& new_theta)
			{
				set_position(new_p,new_theta);
			}

			explicit coordinates_2d(const scifir::point_2d<float>& new_point) : x(new_point.x),y(new_point.y)
			{}

			explicit coordinates_2d(scifir::point_2d<float>&& new_point) : x(std::move(new_point.x)),y(std::move(new_point.y))
			{}

			explicit coordinates_2d(const string& init_coordinates_2d) : coordinates_2d()
			{
				initialize_from_string(init_coordinates_2d);
			}

			coordinates_2d<float>& operator =(const coordinates_2d<float>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				return *this;
			}

			coordinates_2d<float>& operator =(coordinates_2d<float>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				y = std::move(x_coordinates.y);
				return *this;
			}

			coordinates_2d<float>& operator =(const point_2d<float>& x_point)
			{
				x = x_point.x;
				y = x_point.y;
				return *this;
			}

			coordinates_2d<float>& operator =(point_2d<float>&& x_point)
			{
				x = std::move(x_point.x);
				y = std::move(x_point.y);
				return *this;
			}

			coordinates_2d<float>& operator =(const string& init_coordinates_2d)
			{
				initialize_from_string(init_coordinates_2d);
				return *this;
			}

			float get_p() const
			{
				return float(std::sqrt(std::pow(x,2) + std::pow(y,2)));
			}

			angle get_theta() const
			{
				return angle(radian_to_grade(std::atan2(y,x)));
			}

			void set_position(float new_x,float new_y)
			{
				x = new_x;
				y = new_y;
			}

			void set_position(float new_p,const angle& new_theta)
			{
				x = new_p * scifir::cos(new_theta);
				y = new_p * scifir::sin(new_theta);
			}

			void rotate(const angle& x_angle)
			{
				float x_coord = x;
				float y_coord = y;
				x = x_coord * scifir::cos(x_angle) - y_coord * scifir::sin(x_angle);
				y = x_coord * scifir::sin(x_angle) + y_coord * scifir::cos(x_angle);
			}

			void move(const displacement_2d& x_displacement)
			{
				x += float(x_displacement.x_projection());
				y += float(x_displacement.y_projection());
			}

			void move(float new_x,float new_y)
			{
				x += new_x;
				y += new_y;
			}

			void move(float new_p,const angle& new_theta)
			{
				x += new_p * scifir::cos(new_theta);
				y += new_p * scifir::sin(new_theta);
			}

			float distance_to_origin() const
			{
				return float(std::sqrt(std::pow(x,2) + std::pow(y,2)));
			}

			string display_cartesian() const
			{
				ostringstream out;
				out << "(" << display_float(x) << "," << display_float(y) << ")";
				return out.str();
			}

			string display_polar() const
			{
				ostringstream out;
				out << "(" << display_float(get_p(),2) << "," << get_theta() << ")";
				return out.str();
			}

			float x;
			float y;

		private:
			void initialize_from_string(string init_coordinates_2d)
			{
				vector<string> values;
				if (init_coordinates_2d.front() == '(')
				{
					init_coordinates_2d.erase(0,1);
				}
				if (init_coordinates_2d.back() == ')')
				{
					init_coordinates_2d.erase(init_coordinates_2d.size()-1,1);
				}
				boost::split(values,init_coordinates_2d,boost::is_any_of(","));
				if (values.size() == 2)
				{
					if (is_angle(values[1]))
					{
						set_position(stof(values[0]),angle(values[1]));
					}
					else
					{
						set_position(stof(values[0]),stof(values[1]));
					}
				}
			}
	};

	template<typename T>
	string to_string(const coordinates_2d<T>& x)
	{
		return x.display_cartesian();
	}

	string to_string(const coordinates_2d<float>& x);

	template<typename T,typename U>
	T distance(const coordinates_2d<T>& x,const coordinates_2d<U>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2));
	}

	float distance(const coordinates_2d<float>& x,const coordinates_2d<float>& y);

	template<typename T,typename U>
	T distance(const coordinates_2d<T>& x,const point_2d<U>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2));
	}

	float distance(const coordinates_2d<float>& x,const point_2d<float>& y);

	template<typename T,typename U>
	T distance(const point_2d<T>& x,const coordinates_2d<U>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2));
	}

	float distance(const point_2d<float>& x,const coordinates_2d<float>& y);

	inline scalar_unit cartesian_2d_to_polar_p(const scalar_unit& x,scalar_unit y)
	{
		y.change_dimensions(x);
		return scalar_unit(std::sqrt(std::pow(float(x),2) + std::pow(float(y),2)),x.get_dimensions());
	}

	inline angle cartesian_2d_to_polar_theta(const scalar_unit& x,scalar_unit y)
	{
		y.change_dimensions(x);
		return scifir::angle(scifir::atan_grade(float(y)/float(x)));
	}

	inline scalar_unit polar_to_cartesian_2d_x(const scalar_unit& p,const angle& theta)
	{
		return p * scifir::cos(theta);
	}

	inline scalar_unit polar_to_cartesian_2d_y(const scalar_unit& p,const angle& theta)
	{
		return p * scifir::sin(theta);
	}

	inline float cartesian_2d_to_polar_p(float x,float y)
	{
		return float(std::sqrt(std::pow(x,2) + std::pow(y,2)));
	}

	inline angle cartesian_2d_to_polar_theta(float x,float y)
	{
		return scifir::angle(scifir::atan_grade(y/x));
	}

	inline float polar_to_cartesian_2d_x(float p,const angle& theta)
	{
		return p * scifir::cos(theta);
	}

	inline float polar_to_cartesian_2d_y(float p,const angle& theta)
	{
		return p * scifir::sin(theta);
	}
}

template<typename T,typename U>
bool operator ==(const scifir::coordinates_2d<T>& x,const scifir::coordinates_2d<U>& y)
{
	if (x.x == y.x and x.y == y.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T,typename U>
bool operator !=(const scifir::coordinates_2d<T>& x,const scifir::coordinates_2d<U>& y)
{
	return !(x == y);
}

template<typename T,typename U>
bool operator ==(const scifir::coordinates_2d<T>& x,const scifir::point_2d<U>& y)
{
	if (x.x == y.x and x.y == y.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T,typename U>
bool operator !=(const scifir::coordinates_2d<T>& x,const scifir::point_2d<U>& y)
{
	return !(x == y);
}

template<typename T,typename U>
bool operator ==(const scifir::point_2d<T>& x,const scifir::coordinates_2d<U>& y)
{
	if (x.x == y.x and x.y == y.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T,typename U>
bool operator !=(const scifir::point_2d<T>& x,const scifir::coordinates_2d<U>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_2d<T>& x, const string& init_coordinates_2d)
{
	scifir::coordinates_2d<T> y(init_coordinates_2d);
	return (x == y);
}

template<typename T>
bool operator !=(const scifir::coordinates_2d<T>& x, const string& init_coordinates_2d)
{
	return !(x == init_coordinates_2d);
}

template<typename T>
bool operator ==(const string& init_coordinates_2d, const scifir::coordinates_2d<T>& x)
{
	scifir::coordinates_2d<T> y(init_coordinates_2d);
	return (x == y);
}

template<typename T>
bool operator !=(const string& init_coordinates_2d, const scifir::coordinates_2d<T>& x)
{
	return !(init_coordinates_2d == x);
}

template<typename T>
void operator +=(string& x, const scifir::coordinates_2d<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x,const scifir::coordinates_2d<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::coordinates_2d<T>& x,const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os,const scifir::coordinates_2d<T>& x)
{
	return os << to_string(x);
}

ostream& operator <<(ostream& os,const scifir::coordinates_2d<float>& x);

template<typename T>
istream& operator >>(istream& is,scifir::coordinates_2d<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	x = scifir::coordinates_2d<T>(b);
	return is;
}

#endif // SCIFIR_UNITS_COORDINATES_COORDINATES_2D_HPP_INCLUDED
