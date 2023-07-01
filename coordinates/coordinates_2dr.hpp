#ifndef MSCI_UNITS_COORDINATES_COORDINATES_2DR_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_COORDINATES_2DR_HPP_INCLUDED

#include "coordinates/coordinates_2d.hpp"
#include "topology/direction.hpp"
#include "topology/point_2d.hpp"
#include "meca_number/angle.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	template<typename T = length>
	class coordinates_2dr
	{
		public:
			coordinates_2dr<T>() : x(),y(),theta()
			{}

			coordinates_2dr<T>(const coordinates_2dr<T>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),theta(x_coordinates.theta)
			{}

			coordinates_2dr<T>(coordinates_2dr<T>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y)),theta(std::move(x_coordinates.theta))
			{}

			explicit coordinates_2dr<T>(const T& new_x,const T& new_y,const angle& new_theta) : x(new_x),y(new_y),theta(new_theta)
			{}

			explicit coordinates_2dr<T>(const T& new_p,const angle& new_polar_theta,const angle& new_theta) : x(),y(),theta(new_theta)
			{
				set_position(new_p,new_polar_theta);
			}

			explicit coordinates_2dr<T>(const msci::point_2d<T>& new_point,const angle& new_theta) : x(new_point.x),y(new_point.y),theta(new_theta)
			{}

			explicit coordinates_2dr<T>(const msci::coordinates_2d<T>& new_coordinates,const angle& new_theta) : x(new_coordinates.x),y(new_coordinates.y),theta(new_theta)
			{}

			explicit coordinates_2dr<T>(string init_coordinates_2dr) : coordinates_2dr<T>()
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

			coordinates_2dr<T>& operator=(const coordinates_2d<T>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				return *this;
			}

			T get_p() const
			{
				return msci::sqrt(msci::pow(x,2) + msci::pow(y,2));
			}

			angle get_polar_theta() const
			{
				return angle(std::atan2(y.get_value(),x.get_value()));
			}

			void point_to(direction::name x)
			{
				if (x == direction::LEFT)
				{
					theta = 180;
				}
				else if(x == direction::RIGHT)
				{
					theta = 0;
				}
				else if(x == direction::TOP)
				{
					theta = 90;
				}
				else if(x == direction::BOTTOM)
				{
					theta = 270;
				}
				else if(x == direction::LEFT_TOP)
				{
					theta = 135;
				}
				else if(x == direction::RIGHT_TOP)
				{
					theta = 45;
				}
				else if(x == direction::RIGHT_BOTTOM)
				{
					theta = 315;
				}
				else if(x == direction::LEFT_BOTTOM)
				{
					theta = 225;
				}
			}

			void set_position(const T& new_x,const T& new_y)
			{
				x = new_x;
				y = new_y;
			}

			void set_position(const T& new_p,const angle& new_theta)
			{
				x = T(new_p * msci::cos(new_theta));
				y = T(new_p * msci::sin(new_theta));
			}

			void rotate(const angle& x_angle)
			{
				T x_coord = x;
				T y_coord = y;
				x = x_coord * msci::cos(x_angle) - y_coord * msci::sin(x_angle);
				y = x_coord * msci::sin(x_angle) + y_coord * msci::cos(x_angle);
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
				x += new_p * msci::cos(new_theta);
				y += new_p * msci::sin(new_theta);
			}

			T distance_to_origin() const
			{
				return msci::sqrt(msci::pow(x,2) + msci::pow(y,2));
			}

			string display_polar() const
			{
				ostringstream out;
				out << "(" << get_p() << "," << get_polar_theta() << "," << theta << ")";
				return out.str();
			}

			T x;
			T y;
			angle theta;
	};

	template<>
	class coordinates_2dr<float>
	{
		public:
			coordinates_2dr<float>() : x(),y(),theta()
			{}

			coordinates_2dr<float>(const coordinates_2dr<float>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),theta(x_coordinates.theta)
			{}

			coordinates_2dr<float>(coordinates_2dr<float>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y)),theta(std::move(x_coordinates.theta))
			{}

			explicit coordinates_2dr<float>(const float& new_x,const float& new_y,const angle& new_theta) : x(new_x),y(new_y),theta(new_theta)
			{}

			explicit coordinates_2dr<float>(const float& new_p,const angle& new_polar_theta,const angle& new_theta) : x(),y(),theta(new_theta)
			{
				set_position(new_p,new_polar_theta);
			}

			explicit coordinates_2dr<float>(const msci::point_2d<float>& new_point,const angle& new_theta) : x(new_point.x),y(new_point.y),theta(new_theta)
			{}

			explicit coordinates_2dr<float>(const msci::coordinates_2d<float>& new_point,const angle& new_theta) : x(new_point.x),y(new_point.y),theta(new_theta)
			{}

			explicit coordinates_2dr<float>(string init_coordinates_2dr) : coordinates_2dr<float>()
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

			coordinates_2dr<float>& operator=(const coordinates_2d<float>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				return *this;
			}

			float get_p() const
			{
				return std::sqrt(std::pow(x,2) + std::pow(y,2));
			}

			angle get_polar_theta() const
			{
				return angle(std::atan2(y,x));
			}

			void point_to(direction::name x)
			{
				if (x == direction::LEFT)
				{
					theta = 180;
				}
				else if(x == direction::RIGHT)
				{
					theta = 0;
				}
				else if(x == direction::TOP)
				{
					theta = 90;
				}
				else if(x == direction::BOTTOM)
				{
					theta = 270;
				}
				else if(x == direction::LEFT_TOP)
				{
					theta = 135;
				}
				else if(x == direction::RIGHT_TOP)
				{
					theta = 45;
				}
				else if(x == direction::RIGHT_BOTTOM)
				{
					theta = 315;
				}
				else if(x == direction::LEFT_BOTTOM)
				{
					theta = 225;
				}
			}

			void set_position(const float& new_x,const float& new_y)
			{
				x = new_x;
				y = new_y;
			}

			void set_position(const float& new_p,const angle& new_theta)
			{
				x = new_p * msci::cos(new_theta);
				y = new_p * msci::sin(new_theta);
			}

			void rotate(const angle& x_angle)
			{
				float x_coord = x;
				float y_coord = y;
				x = x_coord * msci::cos(x_angle) - y_coord * msci::sin(x_angle);
				y = x_coord * msci::sin(x_angle) + y_coord * msci::cos(x_angle);
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
				x += new_p * msci::cos(new_theta);
				y += new_p * msci::sin(new_theta);
			}

			float distance_to_origin() const
			{
				return std::sqrt(std::pow(x,2) + std::pow(y,2));
			}

			string display_polar() const
			{
				ostringstream out;
				out << "(" << get_p() << "," << get_polar_theta() << "," << theta << ")";
				return out.str();
			}

			float x;
			float y;
			angle theta;
	};

	template<typename T>
	string to_string(const coordinates_2dr<T>& x)
	{
		ostringstream out;
		out << "(" << x.x << "," << x.y << ";" << x.theta << ")";
		return out.str();
	}

	template<typename T>
	T distance(const coordinates_2dr<T>& x,const coordinates_2dr<T>& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2) + msci::pow(x.y - y.y,2));
	}

	float distance(const coordinates_2dr<float>&,const coordinates_2dr<float>&);

	template<typename T>
	T distance(const coordinates_2dr<T>& x,const coordinates_2d<T>& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2) + msci::pow(x.y - y.y,2));
	}

	float distance(const coordinates_2dr<float>&,const coordinates_2d<float>&);

	template<typename T>
	T distance(const coordinates_2d<T>& x,const coordinates_2dr<T>& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2) + msci::pow(x.y - y.y,2));
	}

	float distance(const coordinates_2d<float>&,const coordinates_2dr<float>&);

	template<typename T>
	T distance(const coordinates_2dr<T>& x,const point_2d<T>& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2) + msci::pow(x.y - y.y,2));
	}

	float distance(const coordinates_2dr<float>&,const point_2d<float>&);

	template<typename T>
	T distance(const point_2d<T>& x,const coordinates_2dr<T>& y)
	{
		return msci::sqrt(msci::pow(x.x - y.x,2) + msci::pow(x.y - y.y,2));
	}

	float distance(const point_2d<float>&,const coordinates_2dr<float>&);
}

template<typename T>
bool operator ==(const msci::coordinates_2dr<T>& x,const msci::coordinates_2dr<T>& y)
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
bool operator !=(const msci::coordinates_2dr<T>& x,const msci::coordinates_2dr<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const msci::coordinates_2dr<T>& x,const msci::coordinates_2d<T>& y)
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
bool operator !=(const msci::coordinates_2dr<T>& x,const msci::coordinates_2d<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const msci::coordinates_2d<T>& x,const msci::coordinates_2dr<T>& y)
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
bool operator !=(const msci::coordinates_2d<T>& x,const msci::coordinates_2dr<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const msci::coordinates_2dr<T>& x,const msci::point_2d<T>& y)
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
bool operator !=(const msci::coordinates_2dr<T>& x,const msci::point_2d<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const msci::point_2d<T>& x,const msci::coordinates_2dr<T>& y)
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
bool operator !=(const msci::point_2d<T>& x,const msci::coordinates_2dr<T>& y)
{
	return !(x == y);
}

template<typename T>
ostream& operator << (ostream& os, const msci::coordinates_2dr<T>& x)
{
	return os << to_string(x);
}

template<typename T>
istream& operator >>(istream& is,msci::coordinates_2dr<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::coordinates_2dr<T> c(b);
	x = c;
	return is;
}

#endif // MSCI_UNITS_COORDINATES_COORDINATES_2DR_HPP_INCLUDED
