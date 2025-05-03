#ifndef SCIFIR_UNITS_COORDINATES_COORDINATES_3D_HPP_INCLUDED
#define SCIFIR_UNITS_COORDINATES_COORDINATES_3D_HPP_INCLUDED

#include "../meca_number/angle.hpp"
#include "../units/base_units.hpp"
#include "../derived_units/physics_units.hpp"
#include "../util/types.hpp"
#include "../units/constants.hpp"
#include "./latitude.hpp"
#include "./longitude.hpp"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

namespace scifir
{
	enum class cardinale_point { NORTH, SOUTH, EAST, WEST };

	inline latitude ECEF_to_LLA_latitude(const scalar_unit& x,scalar_unit y,const scalar_unit& z)
	{
		scalar_unit e_square = (scifir::pow(WGS84_EARTH_SEMIAXIS_A,2) - scifir::pow(WGS84_EARTH_SEMIAXIS_B,2))/scifir::pow(WGS84_EARTH_SEMIAXIS_A,2);
		scalar_unit e_prim_square = (scifir::pow(WGS84_EARTH_SEMIAXIS_A,2) - scifir::pow(WGS84_EARTH_SEMIAXIS_B,2))/scifir::pow(WGS84_EARTH_SEMIAXIS_B,2);
		scalar_unit p = scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2));
		scalar_unit F = 54.0f * scifir::pow(WGS84_EARTH_SEMIAXIS_B,2) * scifir::pow(z,2);
		long double G = std::pow(p.get_value(),2) + (1.0f - e_square.get_value()) * std::pow(z.get_value(),2) - e_square.get_value() * (std::pow(WGS84_EARTH_SEMIAXIS_A.get_value(),2) - std::pow(WGS84_EARTH_SEMIAXIS_B.get_value(),2));
		long double c = (scifir::pow(e_square,2) * F * scifir::pow(p,2)).get_value() / std::pow(G,3);
		long double s = std::cbrt(1.0f + c + std::sqrt(std::pow(c,2) + 2.0f * c));
		long double k = s + 1.0f + (1.0f/s);
		scalar_unit P = F/(3.0f * std::pow(k,2) * scalar_unit(std::pow(G,2),{ dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR) }));
		scalar_unit Q = scifir::sqrt(1.0f + 2.0f * scifir::pow(e_square,2) * P);
		scalar_unit r0 = -1.0f * ((P * e_square * p)/(1.0f + Q)) + scifir::sqrt((1.0f/2.0f) * scifir::pow(WGS84_EARTH_SEMIAXIS_A,2) * (1.0f + (1.0f / Q)) - (P * (1.0f - e_square) * scifir::pow(z,2))/(Q * (1.0f + Q)) - (1.0f/2.0f) * P * scifir::pow(p,2));
		scalar_unit V = scifir::sqrt(scifir::pow(p - e_square * r0,2) + (1.0f - e_square) * scifir::pow(z,2));
		scalar_unit z0 = scifir::pow(WGS84_EARTH_SEMIAXIS_B,2)*z/(WGS84_EARTH_SEMIAXIS_A * V);
		return latitude(scifir::atan(float((z + e_prim_square * z0)/p)));
	}

	inline longitude ECEF_to_LLA_longitude(const scalar_unit& x,scalar_unit y,const scalar_unit& z)
	{
		return longitude(scifir::atan2(float(y),float(x)));
	}

	inline scalar_unit ECEF_to_LLA_altitude(const scalar_unit& x,scalar_unit y,const scalar_unit& z)
	{
		scalar_unit e_square = (scifir::pow(WGS84_EARTH_SEMIAXIS_A,2) - scifir::pow(WGS84_EARTH_SEMIAXIS_B,2))/scifir::pow(WGS84_EARTH_SEMIAXIS_A,2);
		scalar_unit e_prim_square = (scifir::pow(WGS84_EARTH_SEMIAXIS_A,2) - scifir::pow(WGS84_EARTH_SEMIAXIS_B,2))/scifir::pow(WGS84_EARTH_SEMIAXIS_B,2);
		scalar_unit p = scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2));
		scalar_unit F = 54.0f * scifir::pow(WGS84_EARTH_SEMIAXIS_B,2) * scifir::pow(z,2);
		long double G = std::pow(p.get_value(),2) + (1.0f - e_square.get_value()) * std::pow(z.get_value(),2) - e_square.get_value() * (std::pow(WGS84_EARTH_SEMIAXIS_A.get_value(),2) - std::pow(WGS84_EARTH_SEMIAXIS_B.get_value(),2));
		long double c = (scifir::pow(e_square,2) * F * scifir::pow(p,2)).get_value() / std::pow(G,3);
		long double s = std::cbrt(1.0f + c + std::sqrt(std::pow(c,2) + 2.0f * c));
		long double k = s + 1.0f + (1.0f/s);
		scalar_unit P = F/(3.0f * std::pow(k,2) * scalar_unit(std::pow(G,2),{ dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR) }));
		scalar_unit Q = scifir::sqrt(1.0f + 2.0f * scifir::pow(e_square,2) * P);
		scalar_unit r0 = -1.0f * ((P * e_square * p)/(1.0f + Q)) + scifir::sqrt((1.0f/2.0f) * scifir::pow(WGS84_EARTH_SEMIAXIS_A,2) * (1.0f + (1.0f / Q)) - (P * (1.0f - e_square) * scifir::pow(z,2))/(Q * (1.0f + Q)) - (1.0f/2.0f) * P * scifir::pow(p,2));
		scalar_unit U = scifir::sqrt(scifir::pow(p - e_square * r0,2) + scifir::pow(z,2));
		scalar_unit V = scifir::sqrt(scifir::pow(p - e_square * r0,2) + (1.0f - e_square) * scifir::pow(z,2));
		return scalar_unit(U.get_value() * (1.0f - std::pow(WGS84_EARTH_SEMIAXIS_B.get_value(),2) / (WGS84_EARTH_SEMIAXIS_A.get_value() * V.get_value())),{ dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR) });
	}

	inline scalar_unit LLA_to_ECEF_x(const latitude& latitude,const longitude& longitude,scalar_unit altitude)
	{
		long double e_square = 0.00669437999014l;
		long double n = WGS84_EARTH_SEMIAXIS_A.get_value() / std::sqrt(1 - e_square * scifir::sin(latitude) * scifir::sin(latitude));
		altitude.change_dimensions("m");
		return (n + altitude) * scifir::cos(latitude) * scifir::cos(longitude);
	}

	inline scalar_unit LLA_to_ECEF_y(const latitude& latitude,const longitude& longitude,scalar_unit altitude)
	{
		long double e_square = 0.00669437999014l;
		long double n = WGS84_EARTH_SEMIAXIS_A.get_value() / std::sqrt(1 - e_square * scifir::sin(latitude) * scifir::sin(latitude));
		altitude.change_dimensions("m");
		return (n + altitude) * scifir::cos(latitude) * scifir::sin(longitude);
	}

	inline scalar_unit LLA_to_ECEF_z(const latitude& latitude,const longitude& longitude,scalar_unit altitude)
	{
		long double e_square = 0.00669437999014l;
		long double n = WGS84_EARTH_SEMIAXIS_A.get_value() / std::sqrt(1 - e_square * scifir::sin(latitude) * scifir::sin(latitude));
		altitude.change_dimensions("m");
		return ((1 - e_square) * n + altitude) * scifir::sin(latitude);
	}

	inline latitude ECEF_to_LLA_latitude(float x, float y, float z)
	{
		long double e_square = (std::pow(WGS84_EARTH_SEMIAXIS_A.get_value(),2) - std::pow(WGS84_EARTH_SEMIAXIS_B.get_value(),2))/std::pow(WGS84_EARTH_SEMIAXIS_A.get_value(),2);
		long double e_prim_square = (std::pow(WGS84_EARTH_SEMIAXIS_A.get_value(),2) - std::pow(WGS84_EARTH_SEMIAXIS_B.get_value(),2))/std::pow(WGS84_EARTH_SEMIAXIS_B.get_value(),2);
		long double p = std::sqrt(std::pow(x,2) + std::pow(y,2));
		long double F = 54.0l * std::pow((long double)WGS84_EARTH_SEMIAXIS_B.get_value(),2) * std::pow((long double)z,2);
		long double G = std::pow(p,2) + (1.0f - e_square) * std::pow(z,2) - e_square * (std::pow(WGS84_EARTH_SEMIAXIS_A.get_value(),2) - std::pow(WGS84_EARTH_SEMIAXIS_B.get_value(),2));
		long double c = std::pow(e_square,2) * F * std::pow(p,2) / std::pow(G,3);
		long double s = std::cbrt(1.0f + c + std::sqrt(std::pow(c,2) + 2.0f * c));
		long double k = s + 1.0f + (1.0f/s);
		long double P = F/(3.0f * std::pow(k,2) * std::pow(G,2));
		long double Q = std::sqrt(1.0f + 2.0f * std::pow(e_square,2) * P);
		long double r0 = -1.0f * ((P * e_square * p)/(1.0f + Q)) + std::sqrt((1.0f/2.0f) * std::pow(WGS84_EARTH_SEMIAXIS_A.get_value(),2) * (1.0f + (1.0f / Q)) - (P * (1.0f - e_square) * std::pow(z,2))/(Q * (1.0f + Q)) - (1.0f/2.0f) * P * std::pow(p,2));
		long double V = std::sqrt(std::pow(p - e_square * r0,2) + (1.0f - e_square) * std::pow(z,2));
		long double z0 = std::pow((long double)WGS84_EARTH_SEMIAXIS_B.get_value(),2) * (long double)z/((long double)WGS84_EARTH_SEMIAXIS_A.get_value() * V);
		return latitude(scifir::atan(float((z + e_prim_square * z0)/p)));
	}

	inline longitude ECEF_to_LLA_longitude(float x, float y, float z)
	{
		return longitude(scifir::atan2(y,x));
	}

	inline float ECEF_to_LLA_altitude(float x, float y, float z)
	{
		long double e_square = (std::pow(WGS84_EARTH_SEMIAXIS_A.get_value(),2) - std::pow(WGS84_EARTH_SEMIAXIS_B.get_value(),2))/std::pow(WGS84_EARTH_SEMIAXIS_A.get_value(),2);
		long double e_prim_square = (std::pow(WGS84_EARTH_SEMIAXIS_A.get_value(),2) - std::pow(WGS84_EARTH_SEMIAXIS_B.get_value(),2))/std::pow(WGS84_EARTH_SEMIAXIS_B.get_value(),2);
		long double p = std::sqrt(std::pow(x,2) + std::pow(y,2));
		long double F = 54.0l * std::pow((long double)WGS84_EARTH_SEMIAXIS_B.get_value(),2) * std::pow((long double)z,2);
		long double G = std::pow(p,2) + (1.0f - e_square) * std::pow(z,2) - e_square * (std::pow(WGS84_EARTH_SEMIAXIS_A.get_value(),2) - std::pow(WGS84_EARTH_SEMIAXIS_B.get_value(),2));
		long double c = std::pow(e_square,2) * F * std::pow(p,2) / std::pow(G,3);
		long double s = std::cbrt(1.0f + c + std::sqrt(std::pow(c,2) + 2.0f * c));
		long double k = s + 1.0f + (1.0f/s);
		long double P = F/(3.0f * std::pow(k,2) * std::pow(G,2));
		long double Q = std::sqrt(1.0f + 2.0f * std::pow(e_square,2) * P);
		long double r0 = -1.0f * ((P * e_square * p)/(1.0f + Q)) + std::sqrt((1.0f/2.0f) * std::pow(WGS84_EARTH_SEMIAXIS_A.get_value(),2) * (1.0f + (1.0f / Q)) - (P * (1.0f - e_square) * std::pow(z,2))/(Q * (1.0f + Q)) - (1.0f/2.0f) * P * std::pow(p,2));
		long double U = std::sqrt(std::pow(p - e_square * r0,2) + std::pow(z,2));
		long double V = std::sqrt(std::pow(p - e_square * r0,2) + (1.0f - e_square) * std::pow(z,2));
		return U * (1.0f - std::pow(WGS84_EARTH_SEMIAXIS_B.get_value(),2) / (WGS84_EARTH_SEMIAXIS_A.get_value() * V));
	}

	template<typename T = length>
	class coordinates_3d
	{
		public:
			enum type { CARTESIAN, CYLINDRICAL, SPHERICAL, GEODESIC };

			coordinates_3d() : x(),y(),z()
			{}

			coordinates_3d(const coordinates_3d<T>& x_coordinates) : x(x_coordinates.x),y(x_coordinates.y),z(x_coordinates.z)
			{}

			coordinates_3d(coordinates_3d<T>&& x_coordinates) : x(std::move(x_coordinates.x)),y(std::move(x_coordinates.y)),z(std::move(x_coordinates.z))
			{}

			explicit coordinates_3d(const scalar_unit& new_x,const scalar_unit& new_y,const scalar_unit& new_z) : x(new_x),y(new_y),z(new_z)
			{}

			explicit coordinates_3d(const scalar_unit& new_p,const angle& new_theta,scalar_unit new_z)
			{
				set_position(new_p,new_theta,new_z);
			}

			explicit coordinates_3d(const scalar_unit& new_r,const angle& new_theta,const angle& new_phi)
			{
				set_position(new_r,new_theta,new_phi);
			}

			explicit coordinates_3d(const angle& new_latitude,const angle& new_longitude,const scalar_unit& new_altitude) : coordinates_3d()
			{
				set_position(new_latitude,new_longitude,new_altitude);
			}

			explicit coordinates_3d(coordinates_3d::type coordinates_type, const string& coord1, const string& coord2, const string& coord3) : coordinates_3d()
			{
				if (coordinates_type == coordinates_3d<>::CARTESIAN)
				{
					set_position(T(coord1),T(coord2),T(coord3));
				}
				else if (coordinates_type == coordinates_3d<>::CYLINDRICAL)
				{
					set_position(T(coord1),angle(coord2),T(coord3));
				}
				else if (coordinates_type == coordinates_3d<>::SPHERICAL)
				{
					set_position(T(coord1),angle(coord2),angle(coord3));
				}
				else if (coordinates_type == coordinates_3d<>::GEODESIC)
				{
					set_position(latitude(coord1),longitude(coord2),T(coord3));
				}
			}

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

			coordinates_3d<T>& operator =(const string& init_coordinates_3d)
			{
				initialize_from_string(init_coordinates_3d);
				return *this;
			}

			static coordinates_3d<T> origin(const coordinates_3d<T>& origin,const coordinates_3d<T>& coordinates)
			{
				coordinates_3d<T> new_coordinates(origin);
				new_coordinates.move(coordinates.x,coordinates.y,coordinates.z);
				return new_coordinates;
			}

			T get_p() const
			{
				return T(scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2)));
			}

			angle get_theta() const
			{
				return scifir::atan(float(y/x));
			}

			T get_r() const
			{
				return T(scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2) + scifir::pow(z,2)));
			}

			angle get_phi() const
			{
				return angle(scifir::acos_degree(float(z/scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2) + scifir::pow(z,2)))));
			}

			latitude get_latitude() const
			{
				return ECEF_to_LLA_latitude(x,y,z);
			}

			longitude get_longitude() const
			{
				return ECEF_to_LLA_longitude(x,y,z);
			}

			scalar_unit get_altitude() const
			{
				return ECEF_to_LLA_altitude(x,y,z);
			}

			void set_position(const scalar_unit& new_x,const scalar_unit& new_y,const scalar_unit& new_z)
			{
				x = new_x;
				y = new_y;
				z = new_z;
			}

			void set_position(const scalar_unit& new_p,const angle& new_theta,scalar_unit new_z)
			{
				new_z.change_dimensions(new_p);
				x = T(new_p * scifir::cos(new_theta));
				y = T(new_p * scifir::sin(new_theta));
				z = new_z;
			}

			void set_position(const scalar_unit& new_r,const angle& new_theta,const angle& new_phi)
			{
				x = T(new_r * scifir::cos(new_theta) * scifir::sin(new_phi));
				y = T(new_r * scifir::sin(new_theta) * scifir::sin(new_phi));
				z = T(new_r * scifir::cos(new_phi));
			}

			void set_position(const latitude& new_latitude,const longitude& new_longitude,const scalar_unit& new_altitude)
			{
				x = LLA_to_ECEF_x(new_latitude,new_longitude,new_altitude);
				y = LLA_to_ECEF_y(new_latitude,new_longitude,new_altitude);
				z = LLA_to_ECEF_z(new_latitude,new_longitude,new_altitude);
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

			void move(const scalar_unit& new_x,const scalar_unit& new_y,const scalar_unit& new_z)
			{
				x += new_x;
				y += new_y;
				z += new_z;
			}

			void move(const scalar_unit& new_p,const angle& new_theta,scalar_unit new_z)
			{
				new_z.change_dimensions(new_p);
				x += T(new_p * scifir::cos(new_theta));
				y += T(new_p * scifir::sin(new_theta));
				z += new_z;
			}

			void move(const scalar_unit& new_r,const angle& new_theta,const angle& new_phi)
			{
				x += T(new_r * scifir::cos(new_theta) * scifir::sin(new_phi));
				y += T(new_r * scifir::sin(new_theta) * scifir::sin(new_phi));
				z += T(new_r * scifir::cos(new_phi));
			}

			T distance_to_origin() const
			{
				return T(scifir::sqrt(scifir::pow(x,2) + scifir::pow(y,2) + scifir::pow(z,2)));
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

		protected:
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
					if (is_latitude(values[0]))
					{
						if (is_longitude(values[1]))
						{
							if (!is_angle(values[2]))
							{
								cout << "values[0]: " << values[0] << endl;
								cout << "values[1]: " << values[1] << endl;
								cout << "values[2]: " << values[2] << endl;
								set_position(latitude(values[0]),longitude(values[1]),T(values[2]));
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

			explicit coordinates_3d(coordinates_3d<length>::type coordinates_type, const string& coord1, const string& coord2, const string& coord3) : coordinates_3d()
			{
				if (coordinates_type == coordinates_3d<length>::CARTESIAN)
				{
					set_position(stof(coord1),stof(coord2),stof(coord3));
				}
				else if (coordinates_type == coordinates_3d<length>::CYLINDRICAL)
				{
					set_position(stof(coord1),angle(coord2),stof(coord3));
				}
				else if (coordinates_type == coordinates_3d<length>::SPHERICAL)
				{
					set_position(stof(coord1),angle(coord2),angle(coord3));
				}
				else if (coordinates_type == coordinates_3d<length>::GEODESIC)
				{
					set_position(angle(coord1),angle(coord2),stof(coord3));
				}
			}

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

			latitude get_latitude() const
			{
				return ECEF_to_LLA_latitude(x,y,z);
			}

			longitude get_longitude() const
			{
				return ECEF_to_LLA_longitude(x,y,z);
			}

			float get_altitude() const
			{
				return ECEF_to_LLA_altitude(x,y,z);
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
					if (values[0] == "" or values[1] == "" or values[2] == "")
					{
						return;
					}
					if (is_latitude(values[0]))
					{
						if (is_longitude(values[1]))
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

	string to_string(cardinale_point x);

	template<typename T>
	string to_string(const coordinates_3d<T>& x)
	{
		return x.display_cartesian();
	}

	string to_string(const coordinates_3d<float>& x);

	cardinale_point create_cardinale_point(const string& x);

	template<typename T,typename U>
	T distance(const coordinates_3d<T>& x,const coordinates_3d<U>& y)
	{
		return T(scifir::sqrt(scifir::pow(x.x - y.x,2) + scifir::pow(x.y - y.y,2) + scifir::pow(x.z - y.z,2)));
	}

	float distance(const coordinates_3d<float>& x,const coordinates_3d<float>& y);

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
