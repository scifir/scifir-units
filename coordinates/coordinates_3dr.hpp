#ifndef SCIFIR_UNITS_COORDINATES_COORDINATES_3DR_HPP_INCLUDED
#define SCIFIR_UNITS_COORDINATES_COORDINATES_3DR_HPP_INCLUDED

#include "../topology/point_3d.hpp"
#include "../meca_number/angle.hpp"
#include "../coordinates/coordinates_3d.hpp"
#include "../units/unit_basic.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	template<typename T = length>
	class coordinates_3dr
	{
		public:
			coordinates_3dr() : x(),y(),z(),theta(),phi()
			{}

			coordinates_3dr(const coordinates_3dr<T>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z),theta(x_coordinates.theta),phi(x_coordinates.phi)
			{}

			coordinates_3dr(coordinates_3dr<T>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y)),z(std::move(x_coordinates.z)),theta(std::move(x_coordinates.theta)),phi(std::move(x_coordinates.phi))
			{}

			explicit coordinates_3dr(const T& new_x,const T& new_y,const T& new_z,const angle& new_theta,const angle& new_phi) : x(new_x),y(new_y),z(new_z),theta(new_theta),phi(new_phi)
			{}

			explicit coordinates_3dr(const T& new_p,const angle& new_cylindrical_theta,T new_z,const angle& new_theta,const angle& new_phi) : x(),y(),z(),theta(new_theta),phi(new_phi)
			{
				set_position(new_p,new_cylindrical_theta,new_z);
			}

			explicit coordinates_3dr(const T& new_r,const angle& new_spherical_theta,const angle& new_spherical_phi,const angle& new_theta,const angle& new_phi) : x(),y(),z(),theta(new_theta),phi(new_phi)
			{
				set_position(new_r,new_spherical_theta,new_spherical_phi);
			}

			explicit coordinates_3dr(const angle& new_latitude,const angle& new_longitude,const T& new_altitude,const angle& new_theta,const angle& new_phi) : x(),y(),z(),theta(new_theta),phi(new_phi)
			{
				set_position(new_latitude,new_longitude,new_altitude);
			}

			explicit coordinates_3dr(const point_3d<T>& x_point,const angle& new_theta,const angle& new_phi) : x(x_point.x),y(x_point.y),z(x_point.z),theta(new_theta),phi(new_phi)
			{}

			explicit coordinates_3dr(point_3d<T>&& x_point,const angle& new_theta,const angle& new_phi) : x(std::move(x_point.x)),y(std::move(x_point.y)),z(std::move(x_point.z)),theta(new_theta),phi(new_phi)
			{}

			explicit coordinates_3dr(const coordinates_3d<T>& x_coordinates,const angle& new_theta,const angle& new_phi) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z),theta(new_theta),phi(new_phi)
			{}

			explicit coordinates_3dr(coordinates_3d<T>&& x_coordinates,const angle& new_theta,const angle& new_phi) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y)),z(std::move(x_coordinates.z)),theta(new_theta),phi(new_phi)
			{}

			explicit coordinates_3dr(const string& init_coordinates_3dr) : coordinates_3dr()
			{
				initialize_from_string(init_coordinates_3dr);
			}

			coordinates_3dr<T>& operator=(const coordinates_3dr<T>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				z = x_coordinates.z;
				theta = x_coordinates.theta;
				phi = x_coordinates.phi;
				return *this;
			}

			coordinates_3dr<T>& operator=(coordinates_3dr<T>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				y = std::move(x_coordinates.y);
				z = std::move(x_coordinates.z);
				theta = std::move(x_coordinates.theta);
				phi = std::move(x_coordinates.phi);
				return *this;
			}

			coordinates_3dr<T>& operator=(const point_3d<T>& x_point)
			{
				x = x_point.x;
				y = x_point.y;
				z = x_point.z;
				return *this;
			}

			coordinates_3dr<T>& operator=(point_3d<T>&& x_point)
			{
				x = std::move(x_point.x);
				y = std::move(x_point.y);
				z = std::move(x_point.z);
				return *this;
			}

			coordinates_3dr<T>& operator=(const coordinates_3d<T>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				z = x_coordinates.z;
				return *this;
			}

			coordinates_3dr<T>& operator=(coordinates_3d<T>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				y = std::move(x_coordinates.y);
				z = std::move(x_coordinates.z);
				return *this;
			}

			coordinates_3dr<T>& operator=(const string& init_coordinates_3dr)
			{
				initialize_from_string(init_coordinates_3dr);
				return *this;
			}

			T get_p() const
			{
				return scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2));
			}

			angle get_spherical_theta() const
			{
				return scifir::atan(float(y/x));
			}

			T get_r() const
			{
				return scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2) + scifir::pow(z,2));
			}

			angle get_spherical_phi() const
			{
				return angle(scifir::acos_grade(float(z/scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2) + scifir::pow(z,2)))));
			}

			angle get_latitude() const
			{
				return scifir::asin(float(z/T(6317,"km")));
			}

			angle get_longitude() const
			{
				return scifir::atan(float(y/x));
			}

			T get_altitude() const
			{
				return T();
			}

			void point_to(direction::name x)
			{
				if (x == direction::LEFT)
				{
					theta = 270.0f;
					phi = 90.0f;
				}
				else if(x == direction::RIGHT)
				{
					theta = 90.0f;
					phi = 90.0f;
				}
				else if(x == direction::TOP)
				{
					theta = 0.0f;
					phi = 0.0f;
				}
				else if(x == direction::BOTTOM)
				{
					theta = 0.0f;
					phi = 180.0f;
				}
				else if(x == direction::LEFT_TOP)
				{
					theta = 270.0f;
					phi = 45.0f;
				}
				else if(x == direction::RIGHT_TOP)
				{
					theta = 90.0f;
					phi = 45.0f;
				}
				else if(x == direction::RIGHT_BOTTOM)
				{
					theta = 90.0f;
					phi = 135.0f;
				}
				else if(x == direction::LEFT_BOTTOM)
				{
					theta = 270.0f;
					phi = 135.0f;
				}
				else if(x == direction::FRONT)
				{
					theta = 0.0f;
					phi = 90.0f;
				}
				else if(x == direction::BACK)
				{
					theta = 180.0f;
					phi = 90.0f;
				}
				else if(x == direction::LEFT_FRONT)
				{
					theta = 315.0f;
					phi = 90.0f;
				}
				else if(x == direction::RIGHT_FRONT)
				{
					theta = 45.0f;
					phi = 90.0f;
				}
				else if(x == direction::TOP_FRONT)
				{
					theta = 0.0f;
					phi = 45.0f;
				}
				else if(x == direction::BOTTOM_FRONT)
				{
					theta = 0.0f;
					phi = 135.0f;
				}
				else if(x == direction::LEFT_BACK)
				{
					theta = 225.0f;
					phi = 90.0f;
				}
				else if(x == direction::RIGHT_BACK)
				{
					theta = 135.0f;
					phi = 90.0f;
				}
				else if(x == direction::TOP_BACK)
				{
					theta = 180.0f;
					phi = 45.0f;
				}
				else if(x == direction::BOTTOM_BACK)
				{
					theta = 180.0f;
					phi = 135.0f;
				}
				else if(x == direction::LEFT_TOP_FRONT)
				{
					theta = 315.0f;
					phi = 45.0f;
				}
				else if(x == direction::RIGHT_TOP_FRONT)
				{
					theta = 45.0f;
					phi = 45.0f;
				}
				else if(x == direction::LEFT_BOTTOM_FRONT)
				{
					theta = 315.0f;
					phi = 135.0f;
				}
				else if(x == direction::RIGHT_BOTTOM_FRONT)
				{
					theta = 45.0f;
					phi = 135.0f;
				}
				else if(x == direction::LEFT_TOP_BACK)
				{
					theta = 225.0f;
					phi = 45.0f;
				}
				else if(x == direction::RIGHT_TOP_BACK)
				{
					theta = 135.0f;
					phi = 45.0f;
				}
				else if(x == direction::LEFT_BOTTOM_BACK)
				{
					theta = 225.0f;
					phi = 135.0f;
				}
				else if(x == direction::RIGHT_BOTTOM_BACK)
				{
					theta = 135.0f;
					phi = 135.0f;
				}
			}

			void set_position(const T& new_x,const T& new_y,const T& new_z)
			{
				x = new_x;
				y = new_y;
				z = new_z;
			}

			void set_position(const T& new_p,const angle& new_theta,T new_z)
			{
				new_z.change_dimensions(new_p);
				x = T(new_p * scifir::cos(new_theta));
				y = T(new_p * scifir::sin(new_theta));
				z = new_z;
			}

			void set_position(const T& new_r,const angle& new_theta,const angle& new_phi)
			{
				x = T(new_r * scifir::cos(new_theta) * scifir::sin(new_phi));
				y = T(new_r * scifir::sin(new_theta) * scifir::sin(new_phi));
				z = T(new_r * scifir::cos(new_phi));
			}

			void set_position(const angle& new_latitude,const angle& new_longitude,const T& new_altitude)
			{
				x = T(new_altitude * scifir::cos(new_latitude) * scifir::cos(new_longitude));
				y = T(new_altitude * scifir::cos(new_latitude) * scifir::sin(new_longitude));
				z = T(new_altitude * scifir::sin(new_latitude));
			}

			void rotate_in_x(const angle& x_angle)
			{
				T y_coord = y;
				T z_coord = z;
				y = y_coord * scifir::cos(x_angle) - z_coord * scifir::sin(x_angle);
				z = y_coord * scifir::sin(x_angle) + z_coord * scifir::cos(x_angle);
			}

			void rotate_in_y(const angle& x_angle)
			{
				T x_coord = x;
				T z_coord = z;
				x = x_coord * scifir::cos(x_angle) - z_coord * scifir::sin(x_angle);
				z = x_coord * scifir::sin(x_angle) + z_coord * scifir::cos(x_angle);
			}

			void rotate_in_z(const angle& x_angle)
			{
				T x_coord = x;
				T y_coord = y;
				x = x_coord * scifir::cos(x_angle) - y_coord * scifir::sin(x_angle);
				y = x_coord * scifir::sin(x_angle) + y_coord * scifir::cos(x_angle);
			}

			void move(const displacement_3d& x_displacement)
			{
				x += x_displacement.x_projection();
				y += x_displacement.y_projection();
				z += x_displacement.z_projection();
			}

			void move(const T& new_x,const T& new_y,const T& new_z)
			{
				x += new_x;
				y += new_y;
				z += new_z;
			}

			void move(const T& new_p,const angle& new_theta,T new_z)
			{
				new_z.change_dimensions(new_p);
				x += T(new_p * scifir::cos(new_theta));
				y += T(new_p * scifir::sin(new_theta));
				z += new_z;
			}

			void move(const T& new_r,const angle& new_theta,const angle& new_phi)
			{
				x += T(new_r * scifir::cos(new_theta) * scifir::sin(new_phi));
				y += T(new_r * scifir::sin(new_theta) * scifir::sin(new_phi));
				z += T(new_r * scifir::cos(new_phi));
			}

			T distance_to_origin() const
			{
				return scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2) + scifir::pow(z,2));
			}

			string display_cartesian() const
			{
				ostringstream out;
				out << "(" << x << "," << y << "," << z << ";" << theta << "," << phi << ")";
				return out.str();
			}

			string display_cylindrical() const
			{
				ostringstream out;
				out << "(" << get_p() << "," << get_spherical_theta() << "," << z << ";" << theta << "," << phi << ")";
				return out.str();
			}

			string display_spherical() const
			{
				ostringstream out;
				out << "(" << get_r() << "," << get_spherical_theta() << "," << get_spherical_phi() << ";" << theta << "," << phi << ")";
				return out.str();
			}

			string display_geographical() const
			{
				ostringstream out;
				out << "(" << get_latitude() << "," << get_longitude() << "," << get_altitude() << ";" << theta << "," << phi << ")";
				return out.str();
			}

			T x;
			T y;
			T z;
			angle theta;
			angle phi;

		private:
			void initialize_from_string(string init_coordinates_3dr)
			{
				vector<string> init_coordinates;
				vector<string> init_values;
				vector<string> init_angles;
				if (init_coordinates_3dr.front() == '(')
				{
					init_coordinates_3dr.erase(0,1);
				}
				if (init_coordinates_3dr.back() == ')')
				{
					init_coordinates_3dr.erase(init_coordinates_3dr.size()-1,1);
				}
				boost::split(init_coordinates,init_coordinates_3dr,boost::is_any_of(";"));
				if (init_coordinates.size() > 0)
				{
					boost::split(init_values,init_coordinates[0],boost::is_any_of(","));
				}
				if (init_coordinates.size() > 1)
				{
					boost::split(init_angles,init_coordinates[1],boost::is_any_of(","));
				}
				if (init_values.size() == 3 and init_angles.size() == 2)
				{
					if (is_angle(init_values[0]))
					{
						if (is_angle(init_values[1]))
						{
							if (!is_angle(init_values[2]))
							{
								set_position(angle(init_values[0]),angle(init_values[1]),T(init_values[2]));
							}
						}
					}
					else
					{
						if (is_angle(init_values[1]))
						{
							if (is_angle(init_values[2]))
							{
								set_position(T(init_values[0]),angle(init_values[1]),angle(init_values[2]));
							}
							else
							{
								set_position(T(init_values[0]),angle(init_values[1]),T(init_values[2]));
							}
						}
						else
						{
							if (!is_angle(init_values[2]))
							{
								set_position(T(init_values[0]),T(init_values[1]),T(init_values[2]));
							}
						}
					}
					theta = angle(init_angles[0]);
					phi = angle(init_angles[1]);
				}
			}
	};

	template<>
	class coordinates_3dr<float>
	{
		public:
			coordinates_3dr() : x(),y(),z(),theta(),phi()
			{}

			coordinates_3dr(const coordinates_3dr<float>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z),theta(x_coordinates.theta),phi(x_coordinates.phi)
			{}

			coordinates_3dr(coordinates_3dr<float>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y)),z(std::move(x_coordinates.z)),theta(std::move(x_coordinates.theta)),phi(std::move(x_coordinates.phi))
			{}

			explicit coordinates_3dr(float new_x,float new_y,float new_z,const angle& new_theta,const angle& new_phi) : x(new_x),y(new_y),z(new_z),theta(new_theta),phi(new_phi)
			{}

			explicit coordinates_3dr(float new_p,const angle& new_cylindrical_theta,float new_z,const angle& new_theta,const angle& new_phi) : x(),y(),z(),theta(new_theta),phi(new_phi)
			{
				set_position(new_p,new_cylindrical_theta,new_z);
			}

			explicit coordinates_3dr(float new_r,const angle& new_spherical_theta,const angle& new_spherical_phi,const angle& new_theta,const angle& new_phi) : x(),y(),z(),theta(new_theta),phi(new_phi)
			{
				set_position(new_r,new_spherical_theta,new_spherical_phi);
			}

			explicit coordinates_3dr(const angle& new_latitude,const angle& new_longitude,float new_altitude,const angle& new_theta,const angle& new_phi) : x(),y(),z(),theta(new_theta),phi(new_phi)
			{
				set_position(new_latitude,new_longitude,new_altitude);
			}

			explicit coordinates_3dr(const point_3d<float>& x_point,const angle& new_theta,const angle& new_phi) : x(x_point.x),y(x_point.y),z(x_point.z),theta(new_theta),phi(new_phi)
			{}

			explicit coordinates_3dr(point_3d<float>&& x_point,const angle& new_theta,const angle& new_phi) : x(std::move(x_point.x)),y(std::move(x_point.y)),z(std::move(x_point.z)),theta(new_theta),phi(new_phi)
			{}

			explicit coordinates_3dr(const coordinates_3d<float>& x_coordinates,const angle& new_theta,const angle& new_phi) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z),theta(new_theta),phi(new_phi)
			{}

			explicit coordinates_3dr(coordinates_3d<float>&& x_coordinates,const angle& new_theta,const angle& new_phi) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y)),z(std::move(x_coordinates.z)),theta(new_theta),phi(new_phi)
			{}

			explicit coordinates_3dr(const string& init_coordinates_3dr) : coordinates_3dr()
			{
				initialize_from_string(init_coordinates_3dr);
			}

			coordinates_3dr<float>& operator=(const coordinates_3dr<float>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				z = x_coordinates.z;
				theta = x_coordinates.theta;
				phi = x_coordinates.phi;
				return *this;
			}

			coordinates_3dr<float>& operator=(coordinates_3dr<float>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				y = std::move(x_coordinates.y);
				z = std::move(x_coordinates.z);
				theta = std::move(x_coordinates.theta);
				phi = std::move(x_coordinates.phi);
				return *this;
			}

			coordinates_3dr<float>& operator=(const point_3d<float>& x_point)
			{
				x = x_point.x;
				y = x_point.y;
				z = x_point.z;
				return *this;
			}

			coordinates_3dr<float>& operator=(point_3d<float>&& x_point)
			{
				x = std::move(x_point.x);
				y = std::move(x_point.y);
				z = std::move(x_point.z);
				return *this;
			}

			coordinates_3dr<float>& operator=(const coordinates_3d<float>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				z = x_coordinates.z;
				return *this;
			}

			coordinates_3dr<float>& operator=(coordinates_3d<float>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				y = std::move(x_coordinates.y);
				z = std::move(x_coordinates.z);
				return *this;
			}

			coordinates_3dr<float>& operator=(const string& init_coordinates_3dr)
			{
				initialize_from_string(init_coordinates_3dr);
				return *this;
			}

			float get_p() const
			{
				return float(std::sqrt(std::pow(x,2) + std::pow(y,2)));
			}

			angle get_spherical_theta() const
			{
				return scifir::atan(float(y/x));
			}

			float get_r() const
			{
				return float(std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2)));
			}

			angle get_spherical_phi() const
			{
				return angle(scifir::acos_grade(float(z/std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2)))));
			}

			angle get_latitude() const
			{
				return scifir::asin(z/6317);
			}

			angle get_longitude() const
			{
				return scifir::atan(float(y/x));
			}

			float get_altitude() const
			{
				return 0.0f;
			}

			void point_to(direction::name x)
			{
				if (x == direction::LEFT)
				{
					theta = 270.0f;
					phi = 90.0f;
				}
				else if(x == direction::RIGHT)
				{
					theta = 90.0f;
					phi = 90.0f;
				}
				else if(x == direction::TOP)
				{
					theta = 0.0f;
					phi = 0.0f;
				}
				else if(x == direction::BOTTOM)
				{
					theta = 0.0f;
					phi = 180.0f;
				}
				else if(x == direction::LEFT_TOP)
				{
					theta = 270.0f;
					phi = 45.0f;
				}
				else if(x == direction::RIGHT_TOP)
				{
					theta = 90.0f;
					phi = 45.0f;
				}
				else if(x == direction::RIGHT_BOTTOM)
				{
					theta = 90.0f;
					phi = 135.0f;
				}
				else if(x == direction::LEFT_BOTTOM)
				{
					theta = 270.0f;
					phi = 135.0f;
				}
				else if(x == direction::FRONT)
				{
					theta = 0.0f;
					phi = 90.0f;
				}
				else if(x == direction::BACK)
				{
					theta = 180.0f;
					phi = 90.0f;
				}
				else if(x == direction::LEFT_FRONT)
				{
					theta = 315.0f;
					phi = 90.0f;
				}
				else if(x == direction::RIGHT_FRONT)
				{
					theta = 45.0f;
					phi = 90.0f;
				}
				else if(x == direction::TOP_FRONT)
				{
					theta = 0.0f;
					phi = 45.0f;
				}
				else if(x == direction::BOTTOM_FRONT)
				{
					theta = 0.0f;
					phi = 135.0f;
				}
				else if(x == direction::LEFT_BACK)
				{
					theta = 225.0f;
					phi = 90.0f;
				}
				else if(x == direction::RIGHT_BACK)
				{
					theta = 135.0f;
					phi = 90.0f;
				}
				else if(x == direction::TOP_BACK)
				{
					theta = 180.0f;
					phi = 45.0f;
				}
				else if(x == direction::BOTTOM_BACK)
				{
					theta = 180.0f;
					phi = 135.0f;
				}
				else if(x == direction::LEFT_TOP_FRONT)
				{
					theta = 315.0f;
					phi = 45.0f;
				}
				else if(x == direction::RIGHT_TOP_FRONT)
				{
					theta = 45.0f;
					phi = 45.0f;
				}
				else if(x == direction::LEFT_BOTTOM_FRONT)
				{
					theta = 315.0f;
					phi = 135.0f;
				}
				else if(x == direction::RIGHT_BOTTOM_FRONT)
				{
					theta = 45.0f;
					phi = 135.0f;
				}
				else if(x == direction::LEFT_TOP_BACK)
				{
					theta = 225.0f;
					phi = 45.0f;
				}
				else if(x == direction::RIGHT_TOP_BACK)
				{
					theta = 135.0f;
					phi = 45.0f;
				}
				else if(x == direction::LEFT_BOTTOM_BACK)
				{
					theta = 225.0f;
					phi = 135.0f;
				}
				else if(x == direction::RIGHT_BOTTOM_BACK)
				{
					theta = 135.0f;
					phi = 135.0f;
				}
			}

			void set_position(float new_x,float new_y,float new_z)
			{
				x = new_x;
				y = new_y;
				z = new_z;
			}

			void set_position(float new_p,const angle& new_theta,float new_z)
			{
				x = new_p * scifir::cos(new_theta);
				y = new_p * scifir::sin(new_theta);
				z = new_z;
			}

			void set_position(float new_r,const angle& new_theta,const angle& new_phi)
			{
				x = new_r * scifir::cos(new_theta) * scifir::sin(new_phi);
				y = new_r * scifir::sin(new_theta) * scifir::sin(new_phi);
				z = new_r * scifir::cos(new_phi);
			}

			void set_position(const angle& new_latitude,const angle& new_longitude,float new_altitude)
			{
				x = new_altitude * scifir::cos(new_latitude) * scifir::cos(new_longitude);
				y = new_altitude * scifir::cos(new_latitude) * scifir::sin(new_longitude);
				z = new_altitude * scifir::sin(new_latitude);
			}

			void rotate_in_x(const angle& x_angle)
			{
				float y_coord = y;
				float z_coord = z;
				y = y_coord * scifir::cos(x_angle) - z_coord * scifir::sin(x_angle);
				z = y_coord * scifir::sin(x_angle) + z_coord * scifir::cos(x_angle);
			}

			void rotate_in_y(const angle& x_angle)
			{
				float x_coord = x;
				float z_coord = z;
				x = x_coord * scifir::cos(x_angle) - z_coord * scifir::sin(x_angle);
				z = x_coord * scifir::sin(x_angle) + z_coord * scifir::cos(x_angle);
			}

			void rotate_in_z(const angle& x_angle)
			{
				float x_coord = x;
				float y_coord = y;
				x = x_coord * scifir::cos(x_angle) - y_coord * scifir::sin(x_angle);
				y = x_coord * scifir::sin(x_angle) + y_coord * scifir::cos(x_angle);
			}

			void move(const displacement_3d& x_displacement)
			{
				x += float(x_displacement.x_projection());
				y += float(x_displacement.y_projection());
				z += float(x_displacement.z_projection());
			}

			void move(float new_x,float new_y,float new_z)
			{
				x += new_x;
				y += new_y;
				z += new_z;
			}

			void move(float new_p,const angle& new_theta,float new_z)
			{
				x += new_p * scifir::cos(new_theta);
				y += new_p * scifir::sin(new_theta);
				z += new_z;
			}

			void move(float new_r,const angle& new_theta,const angle& new_phi)
			{
				x += new_r * scifir::cos(new_theta) * scifir::sin(new_phi);
				y += new_r * scifir::sin(new_theta) * scifir::sin(new_phi);
				z += new_r * scifir::cos(new_phi);
			}

			float distance_to_origin() const
			{
				return float(std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2)));
			}

			string display_cartesian() const
			{
				ostringstream out;
				out << "(" << display_float(x) << "," << display_float(y) << "," << display_float(z) << ";" << theta << "," << phi << ")";
				return out.str();
			}

			string display_cylindrical() const
			{
				ostringstream out;
				out << "(" << display_float(get_p()) << "," << get_spherical_theta() << "," << display_float(z) << ";" << theta << "," << phi << ")";
				return out.str();
			}

			string display_spherical() const
			{
				ostringstream out;
				out << "(" << display_float(get_r()) << "," << get_spherical_theta() << "," << get_spherical_phi() << ";" << theta << "," << phi << ")";
				return out.str();
			}

			string display_geographical() const
			{
				ostringstream out;
				out << "(" << get_latitude() << "," << get_longitude() << "," << display_float(get_altitude()) << ";" << theta << "," << phi << ")";
				return out.str();
			}

			float x;
			float y;
			float z;
			angle theta;
			angle phi;

		private:
			void initialize_from_string(string init_coordinates_3dr)
			{
				vector<string> init_coordinates;
				vector<string> init_values;
				vector<string> init_angles;
				if (init_coordinates_3dr.front() == '(')
				{
					init_coordinates_3dr.erase(0,1);
				}
				if (init_coordinates_3dr.back() == ')')
				{
					init_coordinates_3dr.erase(init_coordinates_3dr.size()-1,1);
				}
				boost::split(init_coordinates,init_coordinates_3dr,boost::is_any_of(";"));
				if (init_coordinates.size() > 0)
				{
					boost::split(init_values,init_coordinates[0],boost::is_any_of(","));
				}
				if (init_coordinates.size() > 1)
				{
					boost::split(init_angles,init_coordinates[1],boost::is_any_of(","));
				}
				if (init_values.size() == 3 and init_angles.size() == 2)
				{
					if (is_angle(init_values[0]))
					{
						if (is_angle(init_values[1]))
						{
							if (!is_angle(init_values[2]))
							{
								set_position(angle(init_values[0]),angle(init_values[1]),stof(init_values[2]));
							}
						}
					}
					else
					{
						if (is_angle(init_values[1]))
						{
							if (is_angle(init_values[2]))
							{
								set_position(stof(init_values[0]),angle(init_values[1]),angle(init_values[2]));
							}
							else
							{
								set_position(stof(init_values[0]),angle(init_values[1]),stof(init_values[2]));
							}
						}
						else
						{
							if (!is_angle(init_values[2]))
							{
								set_position(stof(init_values[0]),stof(init_values[1]),stof(init_values[2]));
							}
						}
					}
					theta = angle(init_angles[0]);
					phi = angle(init_angles[1]);
				}
			}
	};

	template<typename T>
	string to_string(const coordinates_3dr<T>& x)
	{
		ostringstream out;
		out << "(" << x.x << "," << x.y << "," << x.z << ";" << x.theta << "," << x.phi << ")";
		return out.str();
	}

	string to_string(const coordinates_3dr<float>& x);

	template<typename T>
	T distance(const coordinates_3dr<T>& x,const coordinates_3dr<T>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2) + scifir::pow(x.z - y.z,2));
	}

	float distance(const coordinates_3dr<float>& x,const coordinates_3dr<float>& y);

	template<typename T>
	T distance(const coordinates_3dr<T>& x,const coordinates_3d<T>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2) + scifir::pow(x.z - y.z,2));
	}

	float distance(const coordinates_3dr<float>& x,const coordinates_3d<float>& y);

	template<typename T>
	T distance(const coordinates_3d<T>& x,const coordinates_3dr<T>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2) + scifir::pow(x.z - y.z,2));
	}

	float distance(const coordinates_3d<float>& x,const coordinates_3dr<float>& y);

	template<typename T>
	T distance(const coordinates_3dr<T>& x,const point_3d<T>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2) + scifir::pow(x.z - y.z,2));
	}

	float distance(const coordinates_3dr<float>& x,const point_3d<float>& y);

	template<typename T>
	T distance(const point_3d<T>& x,const coordinates_3dr<T>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2) + scifir::pow(x.z - y.z,2));
	}

	float distance(const point_3d<float>& x,const coordinates_3dr<float>& y);
}

template<typename T>
bool operator ==(const scifir::coordinates_3dr<T>& x,const scifir::coordinates_3dr<T>& y)
{
	if (x.x == y.x and x.y == y.y and x.z == y.z and x.theta == y.theta and x.phi == y.phi)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::coordinates_3dr<T>& x,const scifir::coordinates_3dr<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_3dr<T>& x,const scifir::coordinates_3d<T>& y)
{
	if (x.x == y.x and x.y == y.y and x.z == y.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::coordinates_3dr<T>& x,const scifir::coordinates_3d<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_3d<T>& x,const scifir::coordinates_3dr<T>& y)
{
	if (x.x == y.x and x.y == y.y and x.z == y.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::coordinates_3d<T>& x,const scifir::coordinates_3dr<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_3dr<T>& x,const scifir::point_3d<T>& y)
{
	if (x.x == y.x and x.y == y.y and x.z == y.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::coordinates_3dr<T>& x,const scifir::point_3d<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::point_3d<T>& x,const scifir::coordinates_3dr<T>& y)
{
	if (x.x == y.x and x.y == y.y and x.z == y.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::point_3d<T>& x,const scifir::coordinates_3dr<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_3dr<T>& x, const string& init_coordinates_3dr)
{
	coordinates_3dr<T> y = coordinates_3dr<T>(init_coordinates_3dr);
	return (x == y);
}

template<typename T>
bool operator !=(const scifir::coordinates_3dr<T>& x, const string& init_coordinates_3dr)
{
	return !(x == init_coordinates_3dr);
}

template<typename T>
bool operator ==(const string& init_coordinates_3dr, const scifir::coordinates_3dr<T>& x)
{
	coordinates_3dr<T> y = coordinates_3dr<T>(init_coordinates_3dr);
	return (x == y);
}

template<typename T>
bool operator !=(const string& init_coordinates_3dr, const scifir::coordinates_3dr<T>& x)
{
	return !(init_coordinates_3dr == x);
}

template<typename T>
void operator +=(string& x, const scifir::coordinates_3dr<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x,const scifir::coordinates_3dr<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::coordinates_3dr<T>& x,const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os, const scifir::coordinates_3dr<T>& x)
{
	return os << to_string(x);
}

ostream& operator <<(ostream& os,const scifir::coordinates_3dr<float>& x);

template<typename T>
istream& operator >>(istream& is,scifir::coordinates_3dr<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	x = scifir::coordinates_3dr<T>(b);
	return is;
}

#endif // SCIFIR_UNITS_COORDINATES_COORDINATES_3DR_HPP_INCLUDED
