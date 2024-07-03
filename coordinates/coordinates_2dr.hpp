#ifndef SCIFIR_UNITS_COORDINATES_COORDINATES_2DR_HPP_INCLUDED
#define SCIFIR_UNITS_COORDINATES_COORDINATES_2DR_HPP_INCLUDED

#include "../coordinates/coordinates_2d.hpp"
#include "../topology/direction.hpp"
#include "../topology/point_2d.hpp"
#include "../meca_number/angle.hpp"
#include "../util/types.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace scifir
{
	template<typename T = length>
	class coordinates_2dr
	{
		public:
			coordinates_2dr() : x(),y(),theta()
			{}

			coordinates_2dr(const coordinates_2dr<T>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),theta(x_coordinates.theta)
			{}

			coordinates_2dr(coordinates_2dr<T>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y)),theta(std::move(x_coordinates.theta))
			{}

			explicit coordinates_2dr(const T& new_x,const T& new_y,const angle& new_theta) : x(new_x),y(new_y),theta(new_theta)
			{}

			explicit coordinates_2dr(const T& new_p,const angle& new_polar_theta,const angle& new_theta) : x(),y(),theta(new_theta)
			{
				set_position(new_p,new_polar_theta);
			}

			explicit coordinates_2dr(const scifir::point_2d<T>& new_point,const angle& new_theta) : x(new_point.x),y(new_point.y),theta(new_theta)
			{}

			explicit coordinates_2dr(scifir::point_2d<T>&& new_point,const angle& new_theta) : x(std::move(new_point.x)),y(std::move(new_point.y)),theta(new_theta)
			{}

			explicit coordinates_2dr(const scifir::coordinates_2d<T>& new_coordinates,const angle& new_theta) : x(new_coordinates.x),y(new_coordinates.y),theta(new_theta)
			{}

			explicit coordinates_2dr(scifir::coordinates_2d<T>&& new_coordinates,const angle& new_theta) : x(std::move(new_coordinates.x)),y(std::move(new_coordinates.y)),theta(new_theta)
			{}

			explicit coordinates_2dr(const string& init_coordinates_2dr) : coordinates_2dr()
			{
				initialize_from_string(init_coordinates_2dr);
			}

			coordinates_2dr<T>& operator=(const coordinates_2dr<T>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				theta = x_coordinates.theta;
				return *this;
			}

			coordinates_2dr<T>& operator=(coordinates_2dr<T>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				y = std::move(x_coordinates.y);
				theta = std::move(x_coordinates.theta);
				return *this;
			}

			coordinates_2dr<T>& operator=(const point_2d<T>& x_point)
			{
				x = x_point.x;
				y = x_point.y;
				return *this;
			}

			coordinates_2dr<T>& operator=(point_2d<T>&& x_point)
			{
				x = std::move(x_point.x);
				y = std::move(x_point.y);
				return *this;
			}

			coordinates_2dr<T>& operator=(const coordinates_2d<T>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				return *this;
			}

			coordinates_2dr<T>& operator=(coordinates_2d<T>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				y = std::move(x_coordinates.y);
				return *this;
			}

			coordinates_2dr<T>& operator=(const string& init_coordinates_2dr)
			{
				initialize_from_string(init_coordinates_2dr);
				return *this;
			}

			T get_p() const
			{
				return scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2));
			}

			angle get_polar_theta() const
			{
				return angle(radian_to_grade(std::atan2(y.get_value(),x.get_value())));
			}

			void point_to(direction::name x)
			{
				if (x == direction::LEFT)
				{
					theta = 180.0f;
				}
				else if(x == direction::RIGHT)
				{
					theta = 0.0f;
				}
				else if(x == direction::TOP)
				{
					theta = 90.0f;
				}
				else if(x == direction::BOTTOM)
				{
					theta = 270.0f;
				}
				else if(x == direction::LEFT_TOP)
				{
					theta = 135.0f;
				}
				else if(x == direction::RIGHT_TOP)
				{
					theta = 45.0f;
				}
				else if(x == direction::RIGHT_BOTTOM)
				{
					theta = 315.0f;
				}
				else if(x == direction::LEFT_BOTTOM)
				{
					theta = 225.0f;
				}
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
				out << "(" << x << "," << y << ";" << theta << ")";
				return out.str();
			}

			string display_polar() const
			{
				ostringstream out;
				out << "(" << get_p() << "," << get_polar_theta() << ";" << theta << ")";
				return out.str();
			}

			T x;
			T y;
			angle theta;

		private:
			void initialize_from_string(string init_coordinates_2dr)
			{
				vector<string> init_coordinates;
				vector<string> init_values;
				vector<string> init_angles;
				if (init_coordinates_2dr.front() == '(')
				{
					init_coordinates_2dr.erase(0,1);
				}
				if (init_coordinates_2dr.back() == ')')
				{
					init_coordinates_2dr.erase(init_coordinates_2dr.size()-1,1);
				}
				boost::split(init_coordinates,init_coordinates_2dr,boost::is_any_of(";"));
				if (init_coordinates.size() > 0)
				{
					boost::split(init_values,init_coordinates[0],boost::is_any_of(","));
				}
				if (init_coordinates.size() > 1)
				{
					boost::split(init_angles,init_coordinates[1],boost::is_any_of(","));
				}
				if (init_values.size() == 2 and init_angles.size() == 1)
				{
					if (is_angle(init_values[1]))
					{
						set_position(T(init_values[0]),angle(init_values[1]));
					}
					else
					{
						set_position(T(init_values[0]),T(init_values[1]));
					}
					theta = angle(init_angles[0]);
				}
			}
	};

	template<>
	class coordinates_2dr<float>
	{
		public:
			coordinates_2dr() : x(),y(),theta()
			{}

			coordinates_2dr(const coordinates_2dr<float>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),theta(x_coordinates.theta)
			{}

			coordinates_2dr(coordinates_2dr<float>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y)),theta(std::move(x_coordinates.theta))
			{}

			explicit coordinates_2dr(float new_x,float new_y,const angle& new_theta) : x(new_x),y(new_y),theta(new_theta)
			{}

			explicit coordinates_2dr(float new_p,const angle& new_polar_theta,const angle& new_theta) : x(),y(),theta(new_theta)
			{
				set_position(new_p,new_polar_theta);
			}

			explicit coordinates_2dr(const scifir::point_2d<float>& new_point,const angle& new_theta) : x(new_point.x),y(new_point.y),theta(new_theta)
			{}

			explicit coordinates_2dr(scifir::point_2d<float>&& new_point,const angle& new_theta) : x(std::move(new_point.x)),y(std::move(new_point.y)),theta(new_theta)
			{}

			explicit coordinates_2dr(const scifir::coordinates_2d<float>& new_point,const angle& new_theta) : x(new_point.x),y(new_point.y),theta(new_theta)
			{}

			explicit coordinates_2dr(scifir::coordinates_2d<float>&& new_point,const angle& new_theta) : x(std::move(new_point.x)),y(std::move(new_point.y)),theta(new_theta)
			{}

			explicit coordinates_2dr(const string& init_coordinates_2dr) : coordinates_2dr()
			{
				initialize_from_string(init_coordinates_2dr);
			}

			coordinates_2dr<float>& operator=(const coordinates_2dr<float>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				theta = x_coordinates.theta;
				return *this;
			}

			coordinates_2dr<float>& operator=(coordinates_2dr<float>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				y = std::move(x_coordinates.y);
				theta = std::move(x_coordinates.theta);
				return *this;
			}

			coordinates_2dr<float>& operator=(const point_2d<float>& x_point)
			{
				x = x_point.x;
				y = x_point.y;
				return *this;
			}

			coordinates_2dr<float>& operator=(point_2d<float>&& x_point)
			{
				x = std::move(x_point.x);
				y = std::move(x_point.y);
				return *this;
			}

			coordinates_2dr<float>& operator=(const coordinates_2d<float>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				return *this;
			}

			coordinates_2dr<float>& operator=(coordinates_2d<float>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				y = std::move(x_coordinates.y);
				return *this;
			}

			coordinates_2dr<float>& operator=(const string& init_coordinates_2dr)
			{
				initialize_from_string(init_coordinates_2dr);
				return *this;
			}

			float get_p() const
			{
				return float(std::sqrt(std::pow(x,2) + std::pow(y,2)));
			}

			angle get_polar_theta() const
			{
				return angle(radian_to_grade(std::atan2(y,x)));
			}

			void point_to(direction::name x)
			{
				if (x == direction::LEFT)
				{
					theta = 180.0f;
				}
				else if(x == direction::RIGHT)
				{
					theta = 0.0f;
				}
				else if(x == direction::TOP)
				{
					theta = 90.0f;
				}
				else if(x == direction::BOTTOM)
				{
					theta = 270.0f;
				}
				else if(x == direction::LEFT_TOP)
				{
					theta = 135.0f;
				}
				else if(x == direction::RIGHT_TOP)
				{
					theta = 45.0f;
				}
				else if(x == direction::RIGHT_BOTTOM)
				{
					theta = 315.0f;
				}
				else if(x == direction::LEFT_BOTTOM)
				{
					theta = 225.0f;
				}
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
				out << "(" << display_float(x) << "," << display_float(y) << ";" << theta << ")";
				return out.str();
			}

			string display_polar() const
			{
				ostringstream out;
				out << "(" << display_float(get_p()) << "," << get_polar_theta() << ";" << theta << ")";
				return out.str();
			}

			float x;
			float y;
			angle theta;

		private:
			void initialize_from_string(string init_coordinates_2dr)
			{
				vector<string> init_coordinates;
				vector<string> init_values;
				vector<string> init_angles;
				if (init_coordinates_2dr.front() == '(')
				{
					init_coordinates_2dr.erase(0,1);
				}
				if (init_coordinates_2dr.back() == ')')
				{
					init_coordinates_2dr.erase(init_coordinates_2dr.size()-1,1);
				}
				boost::split(init_coordinates,init_coordinates_2dr,boost::is_any_of(";"));
				if (init_coordinates.size() > 0)
				{
					boost::split(init_values,init_coordinates[0],boost::is_any_of(","));
				}
				if (init_coordinates.size() > 1)
				{
					boost::split(init_angles,init_coordinates[1],boost::is_any_of(","));
				}
				if (init_values.size() == 2 and init_angles.size() == 1)
				{
					if (is_angle(init_values[1]))
					{
						set_position(stof(init_values[0]),angle(init_values[1]));
					}
					else
					{
						set_position(stof(init_values[0]),stof(init_values[1]));
					}
					theta = angle(init_angles[0]);
				}
			}
	};

	template<typename T>
	string to_string(const coordinates_2dr<T>& x)
	{
		ostringstream out;
		out << "(" << x.x << "," << x.y << ";" << x.theta << ")";
		return out.str();
	}

	string to_string(const coordinates_2dr<float>& x);

	template<typename T>
	T distance(const coordinates_2dr<T>& x,const coordinates_2dr<T>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2));
	}

	float distance(const coordinates_2dr<float>& x,const coordinates_2dr<float>& y);

	template<typename T>
	T distance(const coordinates_2dr<T>& x,const coordinates_2d<T>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2));
	}

	float distance(const coordinates_2dr<float>& x,const coordinates_2d<float>& y);

	template<typename T>
	T distance(const coordinates_2d<T>& x,const coordinates_2dr<T>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2));
	}

	float distance(const coordinates_2d<float>& x,const coordinates_2dr<float>& y);

	template<typename T>
	T distance(const coordinates_2dr<T>& x,const point_2d<T>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2));
	}

	float distance(const coordinates_2dr<float>& x,const point_2d<float>& y);

	template<typename T>
	T distance(const point_2d<T>& x,const coordinates_2dr<T>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2));
	}

	float distance(const point_2d<float>& x,const coordinates_2dr<float>& y);
}

template<typename T>
bool operator ==(const scifir::coordinates_2dr<T>& x,const scifir::coordinates_2dr<T>& y)
{
	if (x.x == y.x and x.y == y.y and x.theta == y.theta)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::coordinates_2dr<T>& x,const scifir::coordinates_2dr<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_2dr<T>& x,const scifir::coordinates_2d<T>& y)
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

template<typename T>
bool operator !=(const scifir::coordinates_2dr<T>& x,const scifir::coordinates_2d<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_2d<T>& x,const scifir::coordinates_2dr<T>& y)
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

template<typename T>
bool operator !=(const scifir::coordinates_2d<T>& x,const scifir::coordinates_2dr<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_2dr<T>& x,const scifir::point_2d<T>& y)
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

template<typename T>
bool operator !=(const scifir::coordinates_2dr<T>& x,const scifir::point_2d<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::point_2d<T>& x,const scifir::coordinates_2dr<T>& y)
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

template<typename T>
bool operator !=(const scifir::point_2d<T>& x,const scifir::coordinates_2dr<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_2dr<T>& x, const string& init_coordinates_2dr)
{
	coordinates_2dr<T> y = coordinates_2dr<T>(init_coordinates_2dr);
	return (x == y);
}

template<typename T>
bool operator !=(const scifir::coordinates_2dr<T>& x, const string& init_coordinates_2dr)
{
	return !(x == init_coordinates_2dr);
}

template<typename T>
bool operator ==(const string& init_coordinates_2dr, const scifir::coordinates_2dr<T>& x)
{
	coordinates_2dr<T> y = coordinates_2dr<T>(init_coordinates_2dr);
	return (x == y);
}

template<typename T>
bool operator !=(const string& init_coordinates_2dr, const scifir::coordinates_2dr<T>& x)
{
	return !(init_coordinates_2dr == x);
}

template<typename T>
void operator +=(string& x, const scifir::coordinates_2dr<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x,const scifir::coordinates_2dr<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::coordinates_2dr<T>& x,const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os, const scifir::coordinates_2dr<T>& x)
{
	return os << to_string(x);
}

ostream& operator <<(ostream& os,const scifir::coordinates_2dr<float>& x);

template<typename T>
istream& operator >>(istream& is,scifir::coordinates_2dr<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	x = scifir::coordinates_2dr<T>(b);
	return is;
}

#endif // SCIFIR_UNITS_COORDINATES_COORDINATES_2DR_HPP_INCLUDED
