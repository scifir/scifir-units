#ifndef SCIFIR_UNITS_TOPOLOGY_POINT_2D_HPP_INCLUDED
#define SCIFIR_UNITS_TOPOLOGY_POINT_2D_HPP_INCLUDED

#include "../predefined_units/physics_units.hpp"
#include "../units/unit_basic.hpp"

#include <string>

using namespace std;

namespace scifir
{
	template<typename T>
	class coordinates_2d;

	template<typename T = length>
	class point_2d
	{
		public:
			point_2d<T>() : x(),y()
			{}

			point_2d<T>(const point_2d<T>& x_point) : x(x_point.x),y(x_point.y)
			{}

			point_2d<T>(point_2d<T>&& x_point) : x(std::move(x_point.x)),y(std::move(x_point.y))
			{}

			explicit point_2d<T>(const T& new_x,const T& new_y) : x(new_x),y(new_y)
			{}
	
			explicit point_2d<T>(const T& new_p,const angle& new_theta)
			{
				set_position(new_p,new_theta);
			}

			explicit point_2d<T>(const coordinates_2d<T>&);

			explicit point_2d<T>(string init_point_2d) : point_2d<T>()
			{
				vector<string> values;
				if (init_point_2d.front() == '(')
				{
					init_point_2d.erase(0,1);
				}
				if (init_point_2d.back() == ')')
				{
					init_point_2d.erase(init_point_2d.size()-1,1);
				}
				boost::split(values,init_point_2d,boost::is_any_of(","));
				if (values.size() == 2)
				{
					if (is_angle(values[1]))
					{
						set_position(length(values[0]),angle(values[1]));
					}
					else
					{
						set_position(length(values[0]),length(values[1]));
					}
				}
			}

			point_2d<T>& operator=(const point_2d<T>& x_point)
			{
				x = x_point.x;
				y = x_point.y;
				return *this;
			}

			point_2d<T>& operator=(point_2d<T>&& x_point)
			{
				x = std::move(x_point.x);
				y = std::move(x_point.y);
				return *this;
			}

			point_2d<T>& operator=(const coordinates_2d<T>&);

			T get_p() const
			{
				return scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2));
			}

			angle get_theta() const
			{
				return angle(std::atan2(y.get_value(),x.get_value()));
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

			string display_polar() const
			{
				ostringstream out;
				out << "(" << get_p() << "," << get_theta() << ")";
				return out.str();
			}

			T x;
			T y;
	};

	template<>
	class point_2d<float>
	{
		public:
			point_2d<float>() : x(),y()
			{}

			point_2d<float>(const point_2d<float>& x_point) : x(x_point.x),y(x_point.y)
			{}

			point_2d<float>(point_2d<float>&& x_point) : x(std::move(x_point.x)),y(std::move(x_point.y))
			{}

			explicit point_2d<float>(const float& new_x,const float& new_y) : x(new_x),y(new_y)
			{}
	
			explicit point_2d<float>(const float& new_p,const angle& new_theta)
			{
				set_position(new_p,new_theta);
			}

			explicit point_2d<float>(const coordinates_2d<float>&);

			explicit point_2d<float>(string init_point_2d) : point_2d<float>()
			{
				vector<string> values;
				if (init_point_2d.front() == '(')
				{
					init_point_2d.erase(0,1);
				}
				if (init_point_2d.back() == ')')
				{
					init_point_2d.erase(init_point_2d.size()-1,1);
				}
				boost::split(values,init_point_2d,boost::is_any_of(","));
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

			point_2d<float>& operator=(const point_2d<float>& x_point)
			{
				x = x_point.x;
				y = x_point.y;
				return *this;
			}

			point_2d<float>& operator=(point_2d<float>&& x_point)
			{
				x = std::move(x_point.x);
				y = std::move(x_point.y);
				return *this;
			}

			point_2d<float>& operator=(const coordinates_2d<float>&);

			float get_p() const
			{
				return std::sqrt(std::pow(x,2) + std::pow(y,2));
			}

			angle get_theta() const
			{
				return angle(std::atan2(y,x));
			}

			void set_position(const float& new_x,const float& new_y)
			{
				x = new_x;
				y = new_y;
			}

			void set_position(const float& new_p,const angle& new_theta)
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

			void move(const float& new_x,const float& new_y)
			{
				x += new_x;
				y += new_y;
			}

			void move(const float& new_p,const angle& new_theta)
			{
				x += new_p * scifir::cos(new_theta);
				y += new_p * scifir::sin(new_theta);
			}

			float distance_to_origin() const
			{
				return std::sqrt(std::pow(x,2) + std::pow(y,2));
			}

			string display_polar() const
			{
				ostringstream out;
				out << "(" << get_p() << "," << get_theta() << ")";
				return out.str();
			}

			float x;
			float y;
	};

	template<typename T>
	string to_string(const point_2d<T>& x)
	{
		ostringstream out;
		out << "(" << x.x << "," << x.y << ")";
		return out.str();
	}

	template<typename T>
	T distance(const point_2d<T>& x1,const point_2d<T>& x2)
	{
		return scifir::sqrt(scifir::pow(x1.x - x2.x,2) + scifir::pow(x1.y - x2.y,2));
	}

	float distance(const point_2d<float>&,const point_2d<float>&);
}

template<typename T>
bool operator ==(const scifir::point_2d<T>& x,const scifir::point_2d<T>& y)
{
	return (x.x == y.x and x.y == y.y);
}

template<typename T>
bool operator !=(const scifir::point_2d<T>& x,const scifir::point_2d<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::point_2d<T>& x, const string& y)
{
	point_2d<T> y_point = point_2d<T>(y);
	return (x == y_point);
}

template<typename T>
bool operator !=(const scifir::point_2d<T>& x, const string& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const string& x, const scifir::point_2d<T>& y)
{
	point_2d<T> x_point = point_2d<T>(x);
	return (x_point == y);
}

template<typename T>
bool operator !=(const string& x, const scifir::point_2d<T>& y)
{
	return !(x == y);
}

template<typename T>
void operator +=(string& x, const scifir::point_2d<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x,const scifir::point_2d<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::point_2d<T>& x,const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os,const scifir::point_2d<T>& x)
{
	return os << to_string(x);
}

template<typename T>
istream& operator >>(istream& is, scifir::point_2d<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	scifir::point_2d<T> c(b);
	x = c;
	return is;
}

#endif // SCIFIR_UNITS_TOPOLOGY_POINT_2D_HPP_INCLUDED
