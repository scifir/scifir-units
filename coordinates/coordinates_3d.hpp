#ifndef SCIFIR_UNITS_COORDINATES_COORDINATES_3D_HPP_INCLUDED
#define SCIFIR_UNITS_COORDINATES_COORDINATES_3D_HPP_INCLUDED

#include "../topology/point_3d.hpp"
#include "../meca_number/angle.hpp"
#include "../units/base_units.hpp"
#include "../predefined_units/physics_units.hpp"
#include "../util/types.hpp"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

namespace scifir
{
	template<typename T = length>
	class coordinates_3d
	{
		public:
			coordinates_3d() : x(),y(),z()
			{}

			coordinates_3d(const coordinates_3d<T>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z)
			{}

			coordinates_3d(coordinates_3d<T>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y)),z(std::move(x_coordinates.z))
			{}

			explicit coordinates_3d(const T& new_x,const T& new_y,const T& new_z) : x(new_x),y(new_y),z(new_z)
			{}

			explicit coordinates_3d(const T& new_p,const angle& new_theta,T new_z)
			{
				set_position(new_p,new_theta,new_z);
			}

			explicit coordinates_3d(const T& new_r,const angle& new_theta,const angle& new_phi)
			{
				set_position(new_r,new_theta,new_phi);
			}

			explicit coordinates_3d(const angle& new_latitude,const angle& new_longitude,const T& new_altitude) : coordinates_3d()
			{
				set_position(new_latitude,new_longitude,new_altitude);
			}

			explicit coordinates_3d(const point_3d<T>& x_point) : x(x_point.x),y(x_point.y),z(x_point.z)
			{}

			explicit coordinates_3d(point_3d<T>&& x_point) : x(std::move(x_point.x)),y(std::move(x_point.y)),z(std::move(x_point.z))
			{}

			explicit coordinates_3d(const string& init_coordinates_3d) : coordinates_3d()
			{
				initialize_from_string(init_coordinates_3d);
			}

			coordinates_3d<T>& operator =(const coordinates_3d<T>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				z = x_coordinates.z;
				return *this;
			}

			coordinates_3d<T>& operator =(coordinates_3d<T>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				y = std::move(x_coordinates.y);
				z = std::move(x_coordinates.z);
				return *this;
			}

			coordinates_3d<T>& operator =(const point_3d<T>& x_point)
			{
				x = x_point.x;
				y = x_point.y;
				z = x_point.z;
				return *this;
			}

			coordinates_3d<T>& operator =(point_3d<T>&& x_point)
			{
				x = std::move(x_point.x);
				y = std::move(x_point.y);
				z = std::move(x_point.z);
				return *this;
			}

			coordinates_3d<T>& operator =(const string& init_coordinates_3d)
			{
				initialize_from_string(init_coordinates_3d);
				return *this;
			}

			T get_p() const
			{
				return scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2));
			}

			angle get_theta() const
			{
				return scifir::atan(float(y/x));
			}

			T get_r() const
			{
				return scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2) + scifir::pow(z,2));
			}

			angle get_phi() const
			{
				return angle(scifir::acos_degree(float(z/scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2) + scifir::pow(z,2)))));
			}

			angle get_latitude() const
			{
				return scifir::asin(float(z/T(6317.0f,"km")));
			}

			angle get_longitude() const
			{
				return scifir::atan(float(y/x));
			}

			T get_altitude() const
			{
				return T();
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
				out << "(" << x << "," << y << "," << z << ")";
				return out.str();
			}

			string display_cylindrical() const
			{
				ostringstream out;
				out << "(" << get_p() << "," << get_theta() << "," << z << ")";
				return out.str();
			}

			string display_spherical() const
			{
				ostringstream out;
				out << "(" << get_r() << "," << get_theta() << "," << get_phi() << ")";
				return out.str();
			}

			string display_geographical() const
			{
				ostringstream out;
				out << "(" << get_latitude() << "," << get_longitude() << "," << get_altitude() << ")";
				return out.str();
			}

			T x;
			T y;
			T z;

		private:
			void initialize_from_string(string init_coordinates_3d)
			{
				vector<string> values;
				if (init_coordinates_3d.front() == '(')
				{
					init_coordinates_3d.erase(0,1);
				}
				if (init_coordinates_3d.back() == ')')
				{
					init_coordinates_3d.erase(init_coordinates_3d.size()-1,1);
				}
				boost::split(values,init_coordinates_3d,boost::is_any_of(","));
				if (values.size() == 3)
				{
					if (is_angle(values[0]))
					{
						if (is_angle(values[1]))
						{
							if (!is_angle(values[2]))
							{
								set_position(angle(values[0]),angle(values[1]),T(values[2]));
							}
						}
					}
					else
					{
						if (is_angle(values[1]))
						{
							if (is_angle(values[2]))
							{
								set_position(T(values[0]),angle(values[1]),angle(values[2]));
							}
							else
							{
								set_position(T(values[0]),angle(values[1]),T(values[2]));
							}
						}
						else
						{
							if (!is_angle(values[2]))
							{
								set_position(T(values[0]),T(values[1]),T(values[2]));
							}
						}
					}
				}
			}
	};

	template<>
	class coordinates_3d<float>
	{
		public:
			coordinates_3d() : x(),y(),z()
			{}

			coordinates_3d(const coordinates_3d<float>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z)
			{}

			coordinates_3d(coordinates_3d<float>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y)),z(std::move(x_coordinates.z))
			{}

			explicit coordinates_3d(float new_x,float new_y,float new_z) : x(new_x),y(new_y),z(new_z)
			{}

			explicit coordinates_3d(float new_p,const angle& new_theta,float new_z)
			{
				set_position(new_p,new_theta,new_z);
			}

			explicit coordinates_3d(float new_r,const angle& new_theta,const angle& new_phi)
			{
				set_position(new_r,new_theta,new_phi);
			}

			explicit coordinates_3d(const angle& new_latitude,const angle& new_longitude,float new_altitude) : coordinates_3d()
			{
				set_position(new_latitude,new_longitude,new_altitude);
			}

			explicit coordinates_3d(const point_3d<float>& x_point) : x(x_point.x),y(x_point.y),z(x_point.z)
			{}

			explicit coordinates_3d(point_3d<float>&& x_point) : x(std::move(x_point.x)),y(std::move(x_point.y)),z(std::move(x_point.z))
			{}

			explicit coordinates_3d(const string& init_coordinates_3d) : coordinates_3d()
			{
				initialize_from_string(init_coordinates_3d);
			}

			coordinates_3d<float>& operator =(const coordinates_3d<float>& x_coordinates)
			{
				x = x_coordinates.x;
				y = x_coordinates.y;
				z = x_coordinates.z;
				return *this;
			}

			coordinates_3d<float>& operator =(coordinates_3d<float>&& x_coordinates)
			{
				x = std::move(x_coordinates.x);
				y = std::move(x_coordinates.y);
				z = std::move(x_coordinates.z);
				return *this;
			}

			coordinates_3d<float>& operator =(const point_3d<float>& x_point)
			{
				x = x_point.x;
				y = x_point.y;
				z = x_point.z;
				return *this;
			}

			coordinates_3d<float>& operator =(point_3d<float>&& x_point)
			{
				x = std::move(x_point.x);
				y = std::move(x_point.y);
				z = std::move(x_point.z);
				return *this;
			}

			coordinates_3d<float>& operator =(const string& init_coordinates_3d)
			{
				initialize_from_string(init_coordinates_3d);
				return *this;
			}

			float get_p() const
			{
				return float(std::sqrt(std::pow(x,2) + std::pow(y,2)));
			}

			angle get_theta() const
			{
				return scifir::atan(float(y/x));
			}

			float get_r() const
			{
				return float(std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2)));
			}

			angle get_phi() const
			{
				return angle(scifir::acos_degree(float(z/std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2)))));
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
				return float();
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
				out << "(" << display_float(x) << "," << display_float(y) << "," << display_float(z) << ")";
				return out.str();
			}

			string display_cylindrical() const
			{
				ostringstream out;
				out << "(" << display_float(get_p()) << "," << get_theta() << "," << display_float(z) << ")";
				return out.str();
			}

			string display_spherical() const
			{
				ostringstream out;
				out << "(" << display_float(get_r()) << "," << get_theta() << "," << get_phi() << ")";
				return out.str();
			}

			string display_geographical() const
			{
				ostringstream out;
				out << "(" << get_latitude() << "," << get_longitude() << "," << display_float(get_altitude()) << ")";
				return out.str();
			}

			float x;
			float y;
			float z;

		private:
			void initialize_from_string(string init_coordinates_3d)
			{
				vector<string> values;
				if (init_coordinates_3d.front() == '(')
				{
					init_coordinates_3d.erase(0,1);
				}
				if (init_coordinates_3d.back() == ')')
				{
					init_coordinates_3d.erase(init_coordinates_3d.size()-1,1);
				}
				boost::split(values,init_coordinates_3d,boost::is_any_of(","));
				if (values.size() == 3)
				{
					if (is_angle(values[0]))
					{
						if (is_angle(values[1]))
						{
							if (!is_angle(values[2]))
							{
								set_position(angle(values[0]),angle(values[1]),stof(values[2]));
							}
						}
					}
					else
					{
						if (is_angle(values[1]))
						{
							if (is_angle(values[2]))
							{
								set_position(stof(values[0]),angle(values[1]),angle(values[2]));
							}
							else
							{
								set_position(stof(values[0]),angle(values[1]),stof(values[2]));
							}
						}
						else
						{
							if (!is_angle(values[2]))
							{
								set_position(stof(values[0]),stof(values[1]),stof(values[2]));
							}
						}
					}
				}
			}
	};

	template<typename T>
	string to_string(const coordinates_3d<T>& x)
	{
		return x.display_cartesian();
	}

	string to_string(const coordinates_3d<float>& x);

	template<typename T,typename U>
	T distance(const coordinates_3d<T>& x,const coordinates_3d<U>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2) + scifir::pow(x.z - y.z,2));
	}

	float distance(const coordinates_3d<float>& x,const coordinates_3d<float>& y);

	template<typename T,typename U>
	T distance(const coordinates_3d<T>& x,const point_3d<U>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2) + scifir::pow(x.z - y.z,2));
	}

	float distance(const coordinates_3d<float>& x,const point_3d<float>& y);

	template<typename T,typename U>
	T distance(const point_3d<T>& x,const coordinates_3d<U>& y)
	{
		return scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2) + scifir::pow(x.z - y.z,2));
	}

	float distance(const point_3d<float>& x,const coordinates_3d<float>& y);

	inline scalar_unit cartesian_3d_to_cylindrical_p(const scalar_unit& x,scalar_unit y,const scalar_unit& z)
	{
		y.change_dimensions(x);
		return scalar_unit(std::sqrt(std::pow(float(x),2) + std::pow(float(y),2)),x.get_dimensions());
	}

	inline angle cartesian_3d_to_cylindrical_theta(const scalar_unit& x,scalar_unit y,const scalar_unit& z)
	{
		y.change_dimensions(x);
		return angle(scifir::atan_degree(float(y) / float(x)));
	}

	inline scalar_unit cartesian_3d_to_cylindrical_z(const scalar_unit& x,const scalar_unit& y,const scalar_unit& z)
	{
		return z;
	}

	inline scalar_unit cartesian_3d_to_spherical_r(const scalar_unit& x,scalar_unit y,scalar_unit z)
	{
		y.change_dimensions(x);
		z.change_dimensions(x);
		return scalar_unit(std::sqrt(std::pow(float(x),2) + std::pow(float(y),2) + std::pow(float(z),2)),x.get_dimensions());
	}

	inline angle cartesian_3d_to_spherical_theta(const scalar_unit& x,scalar_unit y,const scalar_unit& z)
	{
		y.change_dimensions(x);
		return angle(scifir::atan_degree(float(y) / float(x)));
	}

	inline angle cartesian_3d_to_spherical_phi(const scalar_unit& x,scalar_unit y,scalar_unit z)
	{
		y.change_dimensions(x);
		z.change_dimensions(x);
		return angle(scifir::acos_degree(float(z) / float(std::sqrt(std::pow(float(x),2) + std::pow(float(y),2) + std::pow(float(z),2)))));
	}

	inline scalar_unit spherical_to_cartesian_3d_x(const scalar_unit& r,const angle& theta, const angle& phi)
	{
		return r * scifir::cos(theta) * scifir::sin(phi);
	}

	inline scalar_unit spherical_to_cartesian_3d_y(const scalar_unit& r,const angle& theta, const angle& phi)
	{
		return r * scifir::sin(theta) * scifir::sin(phi);
	}

	inline scalar_unit spherical_to_cartesian_3d_z(const scalar_unit& r,const angle& theta, const angle& phi)
	{
		return r * scifir::cos(phi);
	}

	inline scalar_unit spherical_to_cylindrical_p(const scalar_unit& r,const angle& theta, const angle& phi)
	{
		return r * scifir::sin(phi);
	}

	inline angle spherical_to_cylindrical_theta(const scalar_unit& r,const angle& theta, const angle& phi)
	{
		return theta;
	}

	inline scalar_unit spherical_to_cylindrical_z(const scalar_unit& r,const angle& theta, const angle& phi)
	{
		return r * scifir::cos(phi);
	}

	inline scalar_unit cylindrical_to_cartesian_3d_x(const scalar_unit& p,const angle& theta, const scalar_unit& z)
	{
		return p * scifir::cos(theta);
	}

	inline scalar_unit cylindrical_to_cartesian_3d_y(const scalar_unit& p,const angle& theta, const scalar_unit& z)
	{
		return p * scifir::sin(theta);
	}

	inline scalar_unit cylindrical_to_cartesian_3d_z(const scalar_unit& p,const angle& theta, const scalar_unit& z)
	{
		return z;
	}

	inline scalar_unit cylindrical_to_spherical_r(const scalar_unit& p,const angle& theta,scalar_unit z)
	{
		z.change_dimensions(p);
		return scalar_unit(std::sqrt(std::pow(float(p),2) + std::pow(float(z),2)),p.get_dimensions());
	}

	inline angle cylindrical_to_spherical_theta(const scalar_unit& p,const angle& theta,const scalar_unit& z)
	{
		return theta;
	}

	inline angle cylindrical_to_spherical_phi(const scalar_unit& p,const angle& theta,scalar_unit z)
	{
		z.change_dimensions(p);
		return angle(scifir::atan_degree(float(p) / float(z)));
	}

	inline float cartesian_3d_to_cylindrical_p(float x,float y,float z)
	{
		return float(std::sqrt(std::pow(x,2) + std::pow(y,2)));
	}

	inline angle cartesian_3d_to_cylindrical_theta(float x,float y,float z)
	{
		return angle(scifir::atan_degree(y / x));
	}

	inline float cartesian_3d_to_cylindrical_z(float x,float y,float z)
	{
		return z;
	}

	inline float cartesian_3d_to_spherical_r(float x,float y,float z)
	{
		return float(std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2)));
	}

	inline angle cartesian_3d_to_spherical_theta(float x,float y,float z)
	{
		return angle(scifir::atan_degree(y / x));
	}

	inline angle cartesian_3d_to_spherical_phi(float x,float y,float z)
	{
		return angle(scifir::acos_degree(z / float(std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2)))));
	}

	inline float spherical_to_cartesian_3d_x(float r,const angle& theta, const angle& phi)
	{
		return r * scifir::cos(theta) * scifir::sin(phi);
	}

	inline float spherical_to_cartesian_3d_y(float r,const angle& theta, const angle& phi)
	{
		return r * scifir::sin(theta) * scifir::sin(phi);
	}

	inline float spherical_to_cartesian_3d_z(float r,const angle& theta, const angle& phi)
	{
		return r * scifir::cos(phi);
	}

	inline float spherical_to_cylindrical_p(float r,const angle& theta, const angle& phi)
	{
		return r * scifir::sin(phi);
	}

	inline angle spherical_to_cylindrical_theta(float r,const angle& theta, const angle& phi)
	{
		return theta;
	}

	inline float spherical_to_cylindrical_z(float r,const angle& theta, const angle& phi)
	{
		return r * scifir::cos(phi);
	}

	inline float cylindrical_to_cartesian_3d_x(float p,const angle& theta, float z)
	{
		return p * scifir::cos(theta);
	}

	inline float cylindrical_to_cartesian_3d_y(float p,const angle& theta, float z)
	{
		return p * scifir::sin(theta);
	}

	inline float cylindrical_to_cartesian_3d_z(float p,const angle& theta, float z)
	{
		return z;
	}

	inline float cylindrical_to_spherical_r(float p,const angle& theta, float z)
	{
		return float(std::sqrt(std::pow(p,2) + std::pow(z,2)));
	}

	inline angle cylindrical_to_spherical_theta(float p,const angle& theta, float z)
	{
		return theta;
	}

	inline angle cylindrical_to_spherical_phi(float p,const angle& theta, float z)
	{
		return angle(scifir::atan_degree(p / z));
	}
}

template<typename T,typename U>
bool operator ==(const scifir::coordinates_3d<T>& x,const scifir::coordinates_3d<U>& y)
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

template<typename T,typename U>
bool operator !=(const scifir::coordinates_3d<T>& x,const scifir::coordinates_3d<U>& y)
{
	return !(x == y);
}

template<typename T,typename U>
bool operator ==(const scifir::coordinates_3d<T>& x,const scifir::point_3d<U>& y)
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

template<typename T,typename U>
bool operator !=(const scifir::coordinates_3d<T>& x,const scifir::point_3d<U>& y)
{
	return !(x == y);
}

template<typename T,typename U>
bool operator ==(const scifir::point_3d<T>& x,const scifir::coordinates_3d<U>& y)
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

template<typename T,typename U>
bool operator !=(const scifir::point_3d<T>& x,const scifir::coordinates_3d<U> y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_3d<T>& x, const string& init_coordinates_3d)
{
	scifir::coordinates_3d<T> y(init_coordinates_3d);
	return (x == y);
}

template<typename T>
bool operator !=(const scifir::coordinates_3d<T>& x, const string& init_coordinates_3d)
{
	return !(x == init_coordinates_3d);
}

template<typename T>
bool operator ==(const string& init_coordinates_3d, const scifir::coordinates_3d<T>& x)
{
	scifir::coordinates_3d<T> y(init_coordinates_3d);
	return (x == y);
}

template<typename T>
bool operator !=(const string& init_coordinates_3d, const scifir::coordinates_3d<T>& x)
{
	return !(init_coordinates_3d == x);
}

template<typename T>
void operator +=(string& x, const scifir::coordinates_3d<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x,const scifir::coordinates_3d<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::coordinates_3d<T>& x,const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os, const scifir::coordinates_3d<T>& x)
{
	return os << to_string(x);
}

ostream& operator <<(ostream& os,const scifir::coordinates_3d<float>& x);

template<typename T>
istream& operator >>(istream& is, scifir::coordinates_3d<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	x = scifir::coordinates_3d<T>(b);
	return is;
}

#endif // SCIFIR_UNITS_COORDINATES_COORDINATES_3D_HPP_INCLUDED
