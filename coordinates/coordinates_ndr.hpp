#ifndef SCIFIR_UNITS_COORDINATES_COORDINATES_NDR_HPP_INCLUDED
#define SCIFIR_UNITS_COORDINATES_COORDINATES_NDR_HPP_INCLUDED

#include "../coordinates/coordinates_nd.hpp"
#include "../topology/point_nd.hpp"
#include "../predefined_units/physics_units.hpp"
#include "../units/unit_basic.hpp"
#include "../util/types.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	extern angle coordinates_ndr_no_angle;

	template<typename T = length>
	class coordinates_ndr
	{
		public:
			coordinates_ndr() : values(),angles()
			{}

			coordinates_ndr(const coordinates_ndr<T>& x) : values(),angles()
			{
				if (x.values.size() == (x.angles.size() + 1))
				{
					values = x.values;
					angles = x.angles;
				}
			}

			coordinates_ndr(coordinates_ndr<T>&& x) : values(),angles()
			{
				if (x.values.size() == (x.angles.size() + 1))
				{
					values = std::move(x.values);
					angles = std::move(x.angles);
				}
			}

			explicit coordinates_ndr(const vector<T>& new_values,const vector<float>& new_angles) : values(),angles()
			{
				if (new_values.size() == (new_values.size() + 1))
				{
					values = new_values;
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			explicit coordinates_ndr(const vector<T>& new_values,const vector<angle>& new_angles) : values(),angles()
			{
				if (new_values.size() == (new_angles.size() + 1))
				{
					values = new_values;
					angles = new_angles;
				}
			}

			explicit coordinates_ndr(const T& new_x) : values(),angles()
			{
				values.push_back(new_x);
			}

			explicit coordinates_ndr(const T& new_x,const T& new_y,const angle& new_theta) : values(),angles()
			{
				values.push_back(new_x);
				values.push_back(new_y);
				angles.push_back(new_theta);
			}

			explicit coordinates_ndr(const T& new_p,const angle& new_polar_theta,const angle& new_theta) : values(),angles()
			{
				values.push_back(T(new_p * scifir::cos(new_polar_theta)));
				values.push_back(T(new_p * scifir::sin(new_polar_theta)));
				angles.push_back(new_theta);
			}

			explicit coordinates_ndr(const T& new_x,const T& new_y,const T& new_z,const angle& new_theta,const angle& new_phi) : values(),angles()
			{
				values.push_back(new_x);
				values.push_back(new_y);
				values.push_back(new_z);
				angles.push_back(new_theta);
				angles.push_back(new_phi);
			}

			explicit coordinates_ndr(const T& new_p,const angle& new_cylindrical_theta,T new_z,const angle& new_theta,const angle& new_phi) : values(),angles()
			{
				values.push_back(T(new_p * scifir::cos(new_cylindrical_theta)));
				values.push_back(T(new_p * scifir::sin(new_cylindrical_theta)));
				values.push_back(new_z);
				angles.push_back(new_theta);
				angles.push_back(new_phi);
			}

			explicit coordinates_ndr(const T& new_r,const angle& new_spherical_theta,const angle& new_spherical_phi,const angle& new_theta,const angle& new_phi) : values(),angles()
			{
				values.push_back(T(new_r * scifir::cos(new_spherical_theta) * scifir::sin(new_spherical_phi)));
				values.push_back(T(new_r * scifir::sin(new_spherical_theta) * scifir::sin(new_spherical_phi)));
				values.push_back(T(new_r * scifir::cos(new_spherical_phi)));
				angles.push_back(new_theta);
				angles.push_back(new_phi);
			}

			explicit coordinates_ndr(const angle& new_latitude,const angle& new_longitude,const T& new_altitude,const angle& new_theta,const angle& new_phi) : values(),angles()
			{
				values.push_back(T(new_altitude * scifir::cos(new_latitude) * scifir::cos(new_longitude)));
				values.push_back(T(new_altitude * scifir::cos(new_latitude) * scifir::sin(new_longitude)));
				values.push_back(T(new_altitude * scifir::sin(new_latitude)));
				angles.push_back(new_theta);
				angles.push_back(new_phi);
			}

			explicit coordinates_ndr(const point_nd<T>& new_point,const vector<float>& new_angles) : values(),angles()
			{
				if (new_point.values.size() == (new_angles.size() + 1))
				{
					values = new_point.values;
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			explicit coordinates_ndr(point_nd<T>&& new_point,const vector<float>& new_angles) : values(),angles()
			{
				if (new_point.values.size() == (new_angles.size() + 1))
				{
					values = std::move(new_point.values);
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			explicit coordinates_ndr(const point_nd<T>& new_point,const vector<angle>& new_angles) : values(),angles()
			{
				if (new_point.values.size() == (new_angles.size() + 1))
				{
					values = new_point.values;
					angles = new_angles;
				}
			}

			explicit coordinates_ndr(point_nd<T>&& new_point,const vector<angle>& new_angles) : values(),angles()
			{
				if (new_point.values.size() == (new_angles.size() + 1))
				{
					values = std::move(new_point.values);
					angles = new_angles;
				}
			}

			explicit coordinates_ndr(const coordinates_nd<T>& new_coordinates,const vector<float>& new_angles) : values(),angles()
			{
				if (new_coordinates.values.size() == (new_angles.size() + 1))
				{
					values = new_coordinates.values;
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			explicit coordinates_ndr(coordinates_nd<T>&& new_coordinates,const vector<float>& new_angles) : values(),angles()
			{
				if (new_coordinates.values.size() == (new_angles.size() + 1))
				{
					values = std::move(new_coordinates.values);
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			explicit coordinates_ndr(const coordinates_nd<T>& new_coordinates,const vector<angle>& new_angles) : values(),angles()
			{
				if (new_coordinates.values.size() == (new_angles.size() + 1))
				{
					values = new_coordinates.values;
					angles = new_angles;
				}
			}

			explicit coordinates_ndr(coordinates_nd<T>&& new_coordinates,const vector<angle>& new_angles) : values(),angles()
			{
				if (new_coordinates.values.size() == (new_angles.size() + 1))
				{
					values = std::move(new_coordinates.values);
					angles = new_angles;
				}
			}

			explicit coordinates_ndr(const string& init_coordinates_ndr) : values(),angles()
			{
				initialize_from_string(init_coordinates_ndr);
			}

			coordinates_ndr<T>& operator=(const coordinates_ndr<T>& x_coordinates)
			{
				if (x_coordinates.values.size() == (x_coordinates.angles.size() + 1))
				{
					values = x_coordinates.values;
					angles = x_coordinates.angles;
				}
				return *this;
			}

			coordinates_ndr<T>& operator=(coordinates_ndr<T>&& x_coordinates)
			{
				if (x_coordinates.values.size() == (x_coordinates.angles.size() + 1))
				{
					values = std::move(x_coordinates.values);
					angles = std::move(x_coordinates.angles);
				}
				return *this;
			}

			coordinates_ndr<T>& operator=(const point_nd<T>& x_point)
			{
				if (x_point.values.size() == (angles.size() + 1))
				{
					values = x_point.values;
				}
				return *this;
			}

			coordinates_ndr<T>& operator=(point_nd<T>&& x_point)
			{
				if (x_point.values.size() == (angles.size() + 1))
				{
					values = std::move(x_point.values);
				}
				return *this;
			}

			coordinates_ndr<T>& operator=(const coordinates_nd<T>& x_coordinates)
			{
				if (x_coordinates.values.size() == (angles.size() + 1))
				{
					values = x_coordinates.values;
				}
				return *this;
			}

			coordinates_ndr<T>& operator=(coordinates_nd<T>&& x_coordinates)
			{
				if (x_coordinates.values.size() == (angles.size() + 1))
				{
					values = std::move(x_coordinates.values);
				}
				return *this;
			}

			coordinates_ndr<T>& operator=(const string& init_coordinates_ndr)
			{
				initialize_from_string(init_coordinates_ndr);
				return *this;
			}

			bool is_nd(int i) const
			{
				return values.size() == i;
			}

			int get_nd() const
			{
				return values.size();
			}

			void change_nd(const vector<T>& new_values,const vector<float>& new_angles)
			{
				if (new_values.size() == (new_angles.size() + 1))
				{
					values = new_values;
					angles.clear();
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			void change_nd(const vector<T>& new_values,const vector<angle>& new_angles)
			{
				if (new_values.size() == (new_angles.size() + 1))
				{
					values = new_values;
					angles = new_angles;
				}
			}

			const vector<T>& get_values() const
			{
				return values;
			}

			void set_values(const vector<T>& new_values)
			{
				if (values.size() == new_values.size())
				{
					values = new_values;
				}
			}

			const T& get_value(int i) const
			{
				if (i < (values.size()))
				{
					return values[i];
				}
				else
				{
					return no_value;
				}
			}

			T& get_value(int i)
			{
				if (i < (values.size()))
				{
					return values[i];
				}
				else
				{
					return no_value;
				}
			}

			const vector<angle>& get_angles() const
			{
				return angles;
			}

			void set_angles(const vector<float>& new_angles)
			{
				if (values.size() == (new_angles.size() + 1))
				{
					angles.clear();
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			void set_angles(const vector<angle>& new_angles)
			{
				if (values.size() == (new_angles.size() + 1))
				{
					angles = new_angles;
				}
			}

			const angle& get_angle(int i) const
			{
				if (i < (values.size() - 1))
				{
					return angles[i];
				}
				else
				{
					return coordinates_ndr_no_angle;
				}
			}

			angle& get_angle(int i)
			{
				if (i < (values.size() - 1))
				{
					return angles[i];
				}
				else
				{
					return coordinates_ndr_no_angle;
				}
			}

			T get_p() const
			{
				if (get_nd() == 2 or get_nd() == 3)
				{
					return scifir::sqrt(scifir::pow(values[0],2) + scifir::pow(values[1],2));
				}
				else
				{
					return T();
				}
			}

			angle get_spherical_theta() const
			{
				if (get_nd() == 2 or get_nd() == 3)
				{
					return angle(scifir::atan_grade(float(values[1]/values[0])));
				}
				else
				{
					return angle();
				}
			}

			T get_r() const
			{
				if (get_nd() == 2 or get_nd() == 3)
				{
					return scifir::sqrt(scifir::pow(values[0],2) + scifir::pow(values[1],2) + scifir::pow(values[2],2));
				}
				else
				{
					return T();
				}
			}

			angle get_spherical_phi() const
			{
				if (get_nd() == 3)
				{
					return angle(scifir::acos_grade(float(values[2]/scifir::sqrt(scifir::pow(values[0],2) + scifir::pow(values[1],2) + scifir::pow(values[2],2)))));
				}
				else
				{
					return angle();
				}
			}

			angle get_latitude() const
			{
				return scifir::asin(float(values[2]/T(6317,"km")));
			}

			angle get_longitude() const
			{
				return scifir::atan(float(values[1]/values[0]));
			}

			T get_altitude() const
			{
				return T();
			}

			void point_to(direction::name x)
			{
				if (is_nd(1))
				{
					if (x == direction::LEFT)
					{
						if (values[0] > 0)
						{
							values[0] *= -1;
						}
					}
					else if(x == direction::RIGHT)
					{
						if (values[0] < 0)
						{
							values[0] *= -1;
						}
					}
				}
				else if (is_nd(2))
				{
					if (x == direction::LEFT)
					{
						angles[0] = 180.0f;
					}
					else if(x == direction::RIGHT)
					{
						angles[0] = 0.0f;
					}
					else if(x == direction::TOP)
					{
						angles[0] = 90.0f;
					}
					else if(x == direction::BOTTOM)
					{
						angles[0] = 270.0f;
					}
					else if(x == direction::LEFT_TOP)
					{
						angles[0] = 135.0f;
					}
					else if(x == direction::RIGHT_TOP)
					{
						angles[0] = 45.0f;
					}
					else if(x == direction::RIGHT_BOTTOM)
					{
						angles[0] = 315.0f;
					}
					else if(x == direction::LEFT_BOTTOM)
					{
						angles[0] = 225.0f;
					}
				}
				else if (is_nd(3))
				{
					if (x == direction::LEFT)
					{
						angles[0] = 270.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::RIGHT)
					{
						angles[0] = 90.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::TOP)
					{
						angles[0] = 0.0f;
						angles[1] = 0.0f;
					}
					else if(x == direction::BOTTOM)
					{
						angles[0] = 0.0f;
						angles[1] = 180.0f;
					}
					else if(x == direction::LEFT_TOP)
					{
						angles[0] = 270.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::RIGHT_TOP)
					{
						angles[0] = 90.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::RIGHT_BOTTOM)
					{
						angles[0] = 90.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::LEFT_BOTTOM)
					{
						angles[0] = 270.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::FRONT)
					{
						angles[0] = 0.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::BACK)
					{
						angles[0] = 180.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::LEFT_FRONT)
					{
						angles[0] = 315.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::RIGHT_FRONT)
					{
						angles[0] = 45.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::TOP_FRONT)
					{
						angles[0] = 0.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::BOTTOM_FRONT)
					{
						angles[0] = 0.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::LEFT_BACK)
					{
						angles[0] = 225.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::RIGHT_BACK)
					{
						angles[0] = 135.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::TOP_BACK)
					{
						angles[0] = 180.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::BOTTOM_BACK)
					{
						angles[0] = 180.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::LEFT_TOP_FRONT)
					{
						angles[0] = 315.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::RIGHT_TOP_FRONT)
					{
						angles[0] = 45.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::LEFT_BOTTOM_FRONT)
					{
						angles[0] = 315.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::RIGHT_BOTTOM_FRONT)
					{
						angles[0] = 45.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::LEFT_TOP_BACK)
					{
						angles[0] = 225.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::RIGHT_TOP_BACK)
					{
						angles[0] = 135.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::LEFT_BOTTOM_BACK)
					{
						angles[0] = 225.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::RIGHT_BOTTOM_BACK)
					{
						angles[0] = 135.0f;
						angles[1] = 135.0f;
					}
				}
			}

			void set_position(const T& new_x)
			{
				if (values.size() == 1 and angles.size() == 0)
				{
					values.clear();
					values.push_back(new_x);
				}
			}

			void set_position(const T& new_x,const T& new_y)
			{
				if (values.size() == 2 and angles.size() == 1)
				{
					values.clear();
					values.push_back(new_x);
					values.push_back(new_y);
				}
			}

			void set_position(const T& new_p,const angle& new_theta)
			{
				if (values.size() == 2 and angles.size() == 1)
				{
					values.clear();
					values.push_back(T(new_p * scifir::cos(new_theta)));
					values.push_back(T(new_p * scifir::sin(new_theta)));
				}
			}

			void set_position(const T& new_x,const T& new_y,const T& new_z)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values.clear();
					values.push_back(new_x);
					values.push_back(new_y);
					values.push_back(new_z);
				}
			}

			void set_position(const T& new_p,const angle& new_theta,T new_z)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values.clear();
					new_z.change_dimensions(new_p);
					values.push_back(T(new_p * scifir::cos(new_theta)));
					values.push_back(T(new_p * scifir::sin(new_theta)));
					values.push_back(new_z);
				}
			}

			void set_position(const T& new_r,const angle& new_theta,const angle& new_phi)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values.clear();
					values.push_back(T(new_r * scifir::cos(new_theta) * scifir::sin(new_phi)));
					values.push_back(T(new_r * scifir::sin(new_theta) * scifir::sin(new_phi)));
					values.push_back(T(new_r * scifir::cos(new_phi)));
				}
			}

			void set_position(const angle& new_latitude,const angle& new_longitude,const T& new_altitude)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values.clear();
					values.push_back(T(new_altitude * scifir::cos(new_latitude) * scifir::cos(new_longitude)));
					values.push_back(T(new_altitude * scifir::cos(new_latitude) * scifir::sin(new_longitude)));
					values.push_back(T(new_altitude * scifir::sin(new_latitude)));
				}
			}

			void set_position(const vector<T>& new_values)
			{
				if (values.size() == new_values.size() and new_values.size() == (angles.size() + 1))
				{
					values.clear();
					values = new_values;
				}
			}

			void rotate_in_2d(const angle& new_theta)
			{
				if (get_nd() == 2)
				{
					T x_coord = values[0];
					T y_coord = values[1];
					values[0] = x_coord * scifir::cos(new_theta) - y_coord * scifir::sin(new_theta);
					values[1] = x_coord * scifir::sin(new_theta) + y_coord * scifir::cos(new_theta);
				}
			}

			void rotate_in_3d(int axis,const angle& new_theta)
			{
				if (get_nd() == 3)
				{
					if (axis == 1)
					{
						T y_coord = values[1];
						T z_coord = values[2];
						values[1] = y_coord * scifir::cos(new_theta) - z_coord * scifir::sin(new_theta);
						values[2] = y_coord * scifir::sin(new_theta) + z_coord * scifir::cos(new_theta);
					}
					else if (axis == 2)
					{
						T x_coord = values[0];
						T z_coord = values[2];
						values[0] = x_coord * scifir::cos(new_theta) - z_coord * scifir::sin(new_theta);
						values[2] = x_coord * scifir::sin(new_theta) + z_coord * scifir::cos(new_theta);
					}
					else if (axis == 3)
					{
						T x_coord = values[0];
						T y_coord = values[1];
						values[0] = x_coord * scifir::cos(new_theta) - y_coord * scifir::sin(new_theta);
						values[1] = x_coord * scifir::sin(new_theta) + y_coord * scifir::cos(new_theta);
					}
				}
			}

			void move(const T& new_x)
			{
				if (values.size() == 1 and angles.size() == 0)
				{
					values[0] += new_x;
				}
			}

			void move(const displacement_2d& x_displacement)
			{
				if (values.size() == 2 and angles.size() == 1)
				{
					values[0] += x_displacement.x_projection();
					values[1] += x_displacement.y_projection();
				}
			}

			void move(const T& new_x,const T& new_y)
			{
				if (values.size() == 2 and angles.size() == 1)
				{
					values[0] += new_x;
					values[1] += new_y;
				}
			}

			void move(const T& new_p,const angle& new_theta)
			{
				if (values.size() == 2 and angles.size() == 1)
				{
					values[0] += new_p * scifir::cos(new_theta);
					values[1] += new_p * scifir::sin(new_theta);
				}
			}

			void move(const displacement_3d& x_displacement)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values[0] += x_displacement.x_projection();
					values[1] += x_displacement.y_projection();
					values[2] += x_displacement.z_projection();
				}
			}

			void move(const T& new_x,const T& new_y,const T& new_z)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values[0] += new_x;
					values[1] += new_y;
					values[2] += new_z;
				}
			}

			void move(const T& new_p,const angle& new_theta,T new_z)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					new_z.change_dimensions(new_p);
					values[0] += T(new_p * scifir::cos(new_theta));
					values[1] += T(new_p * scifir::sin(new_theta));
					values[2] += new_z;
				}
			}

			void move(const T& new_r,const angle& new_theta,const angle& new_phi)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values[0] += T(new_r * scifir::cos(new_theta) * scifir::sin(new_phi));
					values[1] += T(new_r * scifir::sin(new_theta) * scifir::sin(new_phi));
					values[2] += T(new_r * scifir::cos(new_phi));
				}
			}

			void move(const displacement_nd& x_displacement)
			{
				if (x_displacement.get_nd() == get_nd())
				{
					for (int i = 0; i < x_displacement.get_nd(); i++)
					{
						values[i] += x_displacement.n_projection(i);
					}
				}
			}

			void move(const T& new_r,const vector<angle>& new_angles)
			{
				displacement_nd x_displacement = displacement_nd(new_r,new_angles);
				move(x_displacement);
			}

			T distance_to_origin() const
			{
				scalar_unit x_T = scalar_unit(0.0f,"m2");
				for (int i = 0; i < values.size(); i++)
				{
					x_T += scifir::pow(values[i],2);
				}
				return scifir::sqrt(x_T);
			}

			string display_polar() const
			{
				if (values.size() == 2 and angles.size() == 1)
				{
					ostringstream out;
					out << "(";
					if (get_nd() == 2)
					{
						out << get_p() << "," << get_spherical_theta() << ";" << angles[0];
					}
					out << ")";
					return out.str();
				}
				else
				{
					return "[no-2d]";
				}
			}

			string display_cylindrical() const
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					ostringstream out;
					out << "(";
					if (get_nd() == 3)
					{
						out << get_p() << "," << get_spherical_theta() << "," << values[2] << ";" << angles[0] << "," << angles[1];
					}
					out << ")";
					return out.str();
				}
				else
				{
					return "[no-3d]";
				}
			}

			string display_spherical() const
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					ostringstream out;
					out << "(";
					if (get_nd() == 3)
					{
						out << get_r() << "," << get_spherical_theta() << "," << get_spherical_phi() << ";" << angles[0] << "," << angles[1];
					}
					out << ")";
					return out.str();
				}
				else
				{
					return "[no-3d]";
				}
			}

			string display_geographical() const
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					ostringstream out;
					out << "(";
					if (get_nd() == 3)
					{
						out << get_latitude() << "," << get_longitude() << "," << get_altitude() << ";" << angles[0] << "," << angles[1];
					}
					out << ")";
					return out.str();
				}
				else
				{
					return "[no-3d]";
				}
			}

		private:
			vector<T> values;
			vector<angle> angles;
			static T no_value;

			void initialize_from_string(string init_coordinates_ndr)
			{
				vector<string> init_coordinates;
				vector<string> init_values;
				vector<string> init_angles;
				if (init_coordinates_ndr.front() == '(')
				{
					init_coordinates_ndr.erase(0,1);
				}
				if (init_coordinates_ndr.back() == ')')
				{
					init_coordinates_ndr.erase(init_coordinates_ndr.size()-1,1);
				}
				boost::split(init_coordinates,init_coordinates_ndr,boost::is_any_of(";"));
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
						values.push_back(T(T(init_values[0]) * scifir::cos(angle(init_values[1]))));
						values.push_back(T(T(init_values[0]) * scifir::sin(angle(init_values[1]))));
					}
					else
					{
						values.push_back(T(init_values[0]));
						values.push_back(T(init_values[1]));
					}
					angles.push_back(angle(init_angles[0]));
				}
				else if (init_values.size() == 3 and init_angles.size() == 2)
				{
					if (is_angle(init_values[0]))
					{
						if (is_angle(init_values[1]))
						{
							if (!is_angle(init_values[2]))
							{
								values.push_back(T(T(init_values[2]) * scifir::cos(angle(init_values[0])) * scifir::cos(angle(init_values[1]))));
								values.push_back(T(T(init_values[2]) * scifir::cos(angle(init_values[0])) * scifir::sin(angle(init_values[1]))));
								values.push_back(T(T(init_values[2]) * scifir::sin(angle(init_values[0]))));
							}
						}
					}
					else
					{
						if (is_angle(init_values[1]))
						{
							if (is_angle(init_values[2]))
							{
								values.push_back(T(T(init_values[0]) * scifir::cos(angle(init_values[1])) * scifir::sin(angle(init_values[2]))));
								values.push_back(T(T(init_values[0]) * scifir::sin(angle(init_values[1])) * scifir::sin(angle(init_values[2]))));
								values.push_back(T(T(init_values[0]) * scifir::cos(angle(init_values[2]))));
							}
							else
							{
								values.push_back(T(T(init_values[0]) * scifir::cos(angle(init_values[1]))));
								values.push_back(T(T(init_values[0]) * scifir::sin(angle(init_values[1]))));
								values.push_back(T(init_values[2]));
							}
						}
						else
						{
							if (!is_angle(init_values[2]))
							{
								values.push_back(T(init_values[0]));
								values.push_back(T(init_values[1]));
								values.push_back(T(init_values[2]));
							}
						}
					}
					angles.push_back(angle(init_angles[0]));
					angles.push_back(angle(init_angles[1]));
				}
				else
				{
					if (init_values.size() == (init_angles.size() + 1))
					{
						for (int i = 0; i < init_values.size(); i++)
						{
							values.push_back(T(init_values[i]));
						}
						for (int i = 0; i < init_angles.size(); i++)
						{
							angles.push_back(angle(init_angles[i]));
						}
					}
				}
			}
	};

	template<typename T>
	T coordinates_ndr<T>::no_value = T();

	template<>
	class coordinates_ndr<float>
	{
		public:
			coordinates_ndr() : values(),angles()
			{}

			coordinates_ndr(const coordinates_ndr<float>& x) : values(),angles()
			{
				if (x.values.size() == (x.angles.size() + 1))
				{
					values = x.values;
					angles = x.angles;
				}
			}

			coordinates_ndr(coordinates_ndr<float>&& x) : values(),angles()
			{
				if (x.values.size() == (x.angles.size() + 1))
				{
					values = std::move(x.values);
					angles = std::move(x.angles);
				}
			}

			explicit coordinates_ndr(const vector<float>& new_values,const vector<float>& new_angles) : values(),angles()
			{
				if (new_values.size() == (new_angles.size() + 1))
				{
					values = new_values;
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			explicit coordinates_ndr(const vector<float>& new_values,const vector<angle>& new_angles) : values(),angles()
			{
				if (new_values.size() == (new_angles.size() + 1))
				{
					values = new_values;
					angles = new_angles;
				}
			}

			explicit coordinates_ndr(float new_x) : values(),angles()
			{
				values.push_back(new_x);
			}

			explicit coordinates_ndr(float new_x,float new_y,const angle& new_theta) : values(),angles()
			{
				values.push_back(new_x);
				values.push_back(new_y);
				angles.push_back(new_theta);
			}

			explicit coordinates_ndr(float new_p,const angle& new_polar_theta,const angle& new_theta) : values(),angles()
			{
				values.push_back(new_p * scifir::cos(new_polar_theta));
				values.push_back(new_p * scifir::sin(new_polar_theta));
				angles.push_back(new_theta);
			}

			explicit coordinates_ndr(float new_x,float new_y,float new_z,const angle& new_theta,const angle& new_phi) : values(),angles()
			{
				values.push_back(new_x);
				values.push_back(new_y);
				values.push_back(new_z);
				angles.push_back(new_theta);
				angles.push_back(new_phi);
			}

			explicit coordinates_ndr(float new_p,const angle& new_cylindrical_theta,float new_z,const angle& new_theta,const angle& new_phi) : values(),angles()
			{
				values.push_back(new_p * scifir::cos(new_cylindrical_theta));
				values.push_back(new_p * scifir::sin(new_cylindrical_theta));
				values.push_back(new_z);
				angles.push_back(new_theta);
				angles.push_back(new_phi);
			}

			explicit coordinates_ndr(float new_r,const angle& new_spherical_theta,const angle& new_spherical_phi,const angle& new_theta,const angle& new_phi) : values(),angles()
			{
				values.push_back(new_r * scifir::cos(new_spherical_theta) * scifir::sin(new_spherical_phi));
				values.push_back(new_r * scifir::sin(new_spherical_theta) * scifir::sin(new_spherical_phi));
				values.push_back(new_r * scifir::cos(new_spherical_phi));
				angles.push_back(new_theta);
				angles.push_back(new_phi);
			}

			explicit coordinates_ndr(const angle& new_latitude,const angle& new_longitude,float new_altitude,const angle& new_theta,const angle& new_phi) : values(),angles()
			{
				values.push_back(new_altitude * scifir::cos(new_latitude) * scifir::cos(new_longitude));
				values.push_back(new_altitude * scifir::cos(new_latitude) * scifir::sin(new_longitude));
				values.push_back(new_altitude * scifir::sin(new_latitude));
				angles.push_back(new_theta);
				angles.push_back(new_phi);
			}

			explicit coordinates_ndr(const point_nd<float>& new_point,const vector<float>& new_angles) : values(),angles()
			{
				if (new_point.values.size() == (new_angles.size() + 1))
				{
					values = new_point.values;
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			explicit coordinates_ndr(point_nd<float>&& new_point,const vector<float>& new_angles) : values(),angles()
			{
				if (new_point.values.size() == (new_angles.size() + 1))
				{
					values = std::move(new_point.values);
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			explicit coordinates_ndr(const point_nd<float>& new_point,const vector<angle>& new_angles) : values(),angles()
			{
				if (new_point.values.size() == (new_angles.size() + 1))
				{
					values = new_point.values;
					angles = new_angles;
				}
			}

			explicit coordinates_ndr(point_nd<float>&& new_point,const vector<angle>& new_angles) : values(),angles()
			{
				if (new_point.values.size() == (new_angles.size() + 1))
				{
					values = std::move(new_point.values);
					angles = new_angles;
				}
			}

			explicit coordinates_ndr(const coordinates_nd<float>& new_coordinates,const vector<float>& new_angles) : values(),angles()
			{
				if (new_coordinates.values.size() == (new_angles.size() + 1))
				{
					values = new_coordinates.values;
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			explicit coordinates_ndr(coordinates_nd<float>&& new_coordinates,const vector<float>& new_angles) : values(),angles()
			{
				if (new_coordinates.values.size() == (new_angles.size() + 1))
				{
					values = std::move(new_coordinates.values);
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			explicit coordinates_ndr(const coordinates_nd<float>& new_coordinates,const vector<angle>& new_angles) : values(),angles()
			{
				if (new_coordinates.values.size() == (new_angles.size() + 1))
				{
					values = new_coordinates.values;
					angles = new_angles;
				}
			}

			explicit coordinates_ndr(coordinates_nd<float>&& new_coordinates,const vector<angle>& new_angles) : values(),angles()
			{
				if (new_coordinates.values.size() == (new_angles.size() + 1))
				{
					values = std::move(new_coordinates.values);
					angles = new_angles;
				}
			}

			explicit coordinates_ndr(const string& init_coordinates_ndr) : values(),angles()
			{
				initialize_from_string(init_coordinates_ndr);
			}

			coordinates_ndr<float>& operator=(const coordinates_ndr<float>& x_coordinates)
			{
				if (x_coordinates.values.size() == (x_coordinates.angles.size() + 1))
				{
					values = x_coordinates.values;
					angles = x_coordinates.angles;
				}
				return *this;
			}

			coordinates_ndr<float>& operator=(coordinates_ndr<float>&& x_coordinates)
			{
				if (x_coordinates.values.size() == (x_coordinates.angles.size() + 1))
				{
					values = std::move(x_coordinates.values);
					angles = std::move(x_coordinates.angles);
				}
				return *this;
			}

			coordinates_ndr<float>& operator=(const point_nd<float>& x_point)
			{
				if (x_point.values.size() == (angles.size() + 1))
				{
					values = x_point.values;
				}
				return *this;
			}

			coordinates_ndr<float>& operator=(point_nd<float>&& x_point)
			{
				if (x_point.values.size() == (angles.size() + 1))
				{
					values = std::move(x_point.values);
				}
				return *this;
			}

			coordinates_ndr<float>& operator=(const coordinates_nd<float>& x_coordinates)
			{
				if (x_coordinates.values.size() == (angles.size() + 1))
				{
					values = x_coordinates.values;
				}
				return *this;
			}

			coordinates_ndr<float>& operator=(coordinates_nd<float>&& x_coordinates)
			{
				if (x_coordinates.values.size() == (angles.size() + 1))
				{
					values = std::move(x_coordinates.values);
				}
				return *this;
			}

			coordinates_ndr<float>& operator=(const string& init_coordinates_ndr)
			{
				initialize_from_string(init_coordinates_ndr);
				return *this;
			}

			bool is_nd(unsigned int i) const
			{
				return values.size() == i;
			}

			int get_nd() const
			{
				return values.size();
			}

			void change_nd(const vector<float>& new_values,const vector<float>& new_angles)
			{
				if (new_values.size() == (new_angles.size() + 1))
				{
					values = new_values;
					angles.clear();
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			void change_nd(const vector<float>& new_values,const vector<angle>& new_angles)
			{
				if (new_values.size() == (new_angles.size() + 1))
				{
					values = new_values;
					angles = new_angles;
				}
			}

			const vector<float>& get_values() const
			{
				return values;
			}

			void set_values(const vector<float>& new_values)
			{
				if (values.size() == new_values.size())
				{
					values = new_values;
				}
			}

			const float& get_value(unsigned int i) const
			{
				if (i < (values.size()))
				{
					return values[i];
				}
				else
				{
					return no_value;
				}
			}

			float& get_value(unsigned int i)
			{
				if (i < (values.size()))
				{
					return values[i];
				}
				else
				{
					return no_value;
				}
			}

			const vector<angle>& get_angles() const
			{
				return angles;
			}

			void set_angles(const vector<float>& new_angles)
			{
				if (values.size() == (new_angles.size() + 1))
				{
					angles.clear();
					for(const float& x_angle : new_angles)
					{
						angles.push_back(angle(x_angle));
					}
				}
			}

			void set_angles(const vector<angle>& new_angles)
			{
				if (values.size() == (new_angles.size() + 1))
				{
					angles = new_angles;
				}
			}

			const angle& get_angle(unsigned int i) const
			{
				if (i < (values.size() - 1))
				{
					return angles[i];
				}
				else
				{
					return coordinates_ndr_no_angle;
				}
			}

			angle& get_angle(unsigned int i)
			{
				if (i < (values.size() - 1))
				{
					return angles[i];
				}
				else
				{
					return coordinates_ndr_no_angle;
				}
			}

			float get_p() const
			{
				if (get_nd() == 2 or get_nd() == 3)
				{
					return float(std::sqrt(std::pow(values[0],2) + std::pow(values[1],2)));
				}
				else
				{
					return float();
				}
			}

			angle get_spherical_theta() const
			{
				if (get_nd() == 2 or get_nd() == 3)
				{
					return angle(scifir::atan_grade(float(values[1]/values[0])));
				}
				else
				{
					return angle();
				}
			}

			float get_r() const
			{
				if (get_nd() == 2 or get_nd() == 3)
				{
					return float(std::sqrt(std::pow(values[0],2) + std::pow(values[1],2) + std::pow(values[2],2)));
				}
				else
				{
					return float();
				}
			}

			angle get_spherical_phi() const
			{
				if (get_nd() == 3)
				{
					return angle(scifir::acos_grade(float(values[2]/std::sqrt(std::pow(values[0],2) + std::pow(values[1],2) + std::pow(values[2],2)))));
				}
				else
				{
					return angle();
				}
			}

			angle get_latitude() const
			{
				return scifir::asin(float(values[2]/6317));
			}

			angle get_longitude() const
			{
				return scifir::atan(float(values[1]/values[0]));
			}

			float get_altitude() const
			{
				return float();
			}

			void point_to(direction::name x)
			{
				if (is_nd(1))
				{
					if (x == direction::LEFT)
					{
						if (values[0] > 0)
						{
							values[0] *= -1;
						}
					}
					else if(x == direction::RIGHT)
					{
						if (values[0] < 0)
						{
							values[0] *= -1;
						}
					}
				}
				else if (is_nd(2))
				{
					if (x == direction::LEFT)
					{
						angles[0] = 180.0f;
					}
					else if(x == direction::RIGHT)
					{
						angles[0] = 0.0f;
					}
					else if(x == direction::TOP)
					{
						angles[0] = 90.0f;
					}
					else if(x == direction::BOTTOM)
					{
						angles[0] = 270.0f;
					}
					else if(x == direction::LEFT_TOP)
					{
						angles[0] = 135.0f;
					}
					else if(x == direction::RIGHT_TOP)
					{
						angles[0] = 45.0f;
					}
					else if(x == direction::RIGHT_BOTTOM)
					{
						angles[0] = 315.0f;
					}
					else if(x == direction::LEFT_BOTTOM)
					{
						angles[0] = 225.0f;
					}
				}
				else if (is_nd(3))
				{
					if (x == direction::LEFT)
					{
						angles[0] = 270.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::RIGHT)
					{
						angles[0] = 90.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::TOP)
					{
						angles[0] = 0.0f;
						angles[1] = 0.0f;
					}
					else if(x == direction::BOTTOM)
					{
						angles[0] = 0.0f;
						angles[1] = 180.0f;
					}
					else if(x == direction::LEFT_TOP)
					{
						angles[0] = 270.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::RIGHT_TOP)
					{
						angles[0] = 90.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::RIGHT_BOTTOM)
					{
						angles[0] = 90.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::LEFT_BOTTOM)
					{
						angles[0] = 270.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::FRONT)
					{
						angles[0] = 0.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::BACK)
					{
						angles[0] = 180.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::LEFT_FRONT)
					{
						angles[0] = 315.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::RIGHT_FRONT)
					{
						angles[0] = 45.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::TOP_FRONT)
					{
						angles[0] = 0.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::BOTTOM_FRONT)
					{
						angles[0] = 0.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::LEFT_BACK)
					{
						angles[0] = 225.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::RIGHT_BACK)
					{
						angles[0] = 135.0f;
						angles[1] = 90.0f;
					}
					else if(x == direction::TOP_BACK)
					{
						angles[0] = 180.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::BOTTOM_BACK)
					{
						angles[0] = 180.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::LEFT_TOP_FRONT)
					{
						angles[0] = 315.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::RIGHT_TOP_FRONT)
					{
						angles[0] = 45.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::LEFT_BOTTOM_FRONT)
					{
						angles[0] = 315.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::RIGHT_BOTTOM_FRONT)
					{
						angles[0] = 45.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::LEFT_TOP_BACK)
					{
						angles[0] = 225.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::RIGHT_TOP_BACK)
					{
						angles[0] = 135.0f;
						angles[1] = 45.0f;
					}
					else if(x == direction::LEFT_BOTTOM_BACK)
					{
						angles[0] = 225.0f;
						angles[1] = 135.0f;
					}
					else if(x == direction::RIGHT_BOTTOM_BACK)
					{
						angles[0] = 135.0f;
						angles[1] = 135.0f;
					}
				}
			}

			void set_position(float new_x)
			{
				if (values.size() == 1 and angles.size() == 0)
				{
					values.clear();
					values.push_back(new_x);
				}
			}

			void set_position(float new_x,float new_y)
			{
				if (values.size() == 2 and angles.size() == 1)
				{
					values.clear();
					values.push_back(new_x);
					values.push_back(new_y);
				}
			}

			void set_position(float new_p,const angle& new_theta)
			{
				if (values.size() == 2 and angles.size() == 1)
				{
					values.clear();
					values.push_back(new_p * scifir::cos(new_theta));
					values.push_back(new_p * scifir::sin(new_theta));
				}
			}

			void set_position(float new_x,float new_y,float new_z)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values.clear();
					values.push_back(new_x);
					values.push_back(new_y);
					values.push_back(new_z);
				}
			}

			void set_position(float new_p,const angle& new_theta,float new_z)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values.clear();
					values.push_back(new_p * scifir::cos(new_theta));
					values.push_back(new_p * scifir::sin(new_theta));
					values.push_back(new_z);
				}
			}

			void set_position(float new_r,const angle& new_theta,const angle& new_phi)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values.clear();
					values.push_back(new_r * scifir::cos(new_theta) * scifir::sin(new_phi));
					values.push_back(new_r * scifir::sin(new_theta) * scifir::sin(new_phi));
					values.push_back(new_r * scifir::cos(new_phi));
				}
			}

			void set_position(const angle& new_latitude,const angle& new_longitude,float new_altitude)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values.clear();
					values.push_back(new_altitude * scifir::cos(new_latitude) * scifir::cos(new_longitude));
					values.push_back(new_altitude * scifir::cos(new_latitude) * scifir::sin(new_longitude));
					values.push_back(new_altitude * scifir::sin(new_latitude));
				}
			}

			void set_position(const vector<float>& new_values)
			{
				values.clear();
				values = new_values;
			}

			void rotate_in_2d(const angle& new_theta)
			{
				if (get_nd() == 2)
				{
					float x_coord = values[0];
					float y_coord = values[1];
					values[0] = x_coord * scifir::cos(new_theta) - y_coord * scifir::sin(new_theta);
					values[1] = x_coord * scifir::sin(new_theta) + y_coord * scifir::cos(new_theta);
				}
			}

			void rotate_in_3d(int axis,const angle& new_theta)
			{
				if (get_nd() == 3)
				{
					if (axis == 1)
					{
						float y_coord = values[1];
						float z_coord = values[2];
						values[1] = y_coord * scifir::cos(new_theta) - z_coord * scifir::sin(new_theta);
						values[2] = y_coord * scifir::sin(new_theta) + z_coord * scifir::cos(new_theta);
					}
					else if (axis == 2)
					{
						float x_coord = values[0];
						float z_coord = values[2];
						values[0] = x_coord * scifir::cos(new_theta) - z_coord * scifir::sin(new_theta);
						values[2] = x_coord * scifir::sin(new_theta) + z_coord * scifir::cos(new_theta);
					}
					else if (axis == 3)
					{
						float x_coord = values[0];
						float y_coord = values[1];
						values[0] = x_coord * scifir::cos(new_theta) - y_coord * scifir::sin(new_theta);
						values[1] = x_coord * scifir::sin(new_theta) + y_coord * scifir::cos(new_theta);
					}
				}
			}

			void move(float new_x)
			{
				if (values.size() == 1 and angles.size() == 0)
				{
					values[0] += new_x;
				}
			}

			void move(const displacement_2d& x_displacement)
			{
				if (values.size() == 2 and angles.size() == 1)
				{
					values[0] += float(x_displacement.x_projection());
					values[1] += float(x_displacement.y_projection());
				}
			}

			void move(float new_x,float new_y)
			{
				if (values.size() == 2 and angles.size() == 1)
				{
					values[0] += new_x;
					values[1] += new_y;
				}
			}

			void move(float new_p,const angle& new_theta)
			{
				if (values.size() == 2 and angles.size() == 1)
				{
					values[0] += new_p * scifir::cos(new_theta);
					values[1] += new_p * scifir::sin(new_theta);
				}
			}

			void move(const displacement_3d& x_displacement)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values[0] += float(x_displacement.x_projection());
					values[1] += float(x_displacement.y_projection());
					values[2] += float(x_displacement.z_projection());
				}
			}

			void move(float new_x,float new_y,float new_z)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values[0] += new_x;
					values[1] += new_y;
					values[2] += new_z;
				}
			}

			void move(float new_p,const angle& new_theta,float new_z)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values[0] += new_p * scifir::cos(new_theta);
					values[1] += new_p * scifir::sin(new_theta);
					values[2] += new_z;
				}
			}

			void move(float new_r,const angle& new_theta,const angle& new_phi)
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					values[0] += new_r * scifir::cos(new_theta) * scifir::sin(new_phi);
					values[1] += new_r * scifir::sin(new_theta) * scifir::sin(new_phi);
					values[2] += new_r * scifir::cos(new_phi);
				}
			}

			void move(const displacement_nd& x_displacement)
			{
				if (x_displacement.get_nd() == get_nd())
				{
					for (int i = 0; i < x_displacement.get_nd(); i++)
					{
						values[i] += float(x_displacement.n_projection(i));
					}
				}
			}

			void move(float new_r,const vector<angle>& new_angles)
			{
				displacement_nd x_displacement = displacement_nd(new_r,"m",new_angles);
				move(x_displacement);
			}

			float distance_to_origin() const
			{
				float x_T = 0;
				for (unsigned int i = 0; i < values.size(); i++)
				{
					x_T += float(std::pow(values[i],2));
				}
				return std::sqrt(x_T);
			}

			string display_polar() const
			{
				if (values.size() == 2 and angles.size() == 1)
				{
					ostringstream out;
					out << "(";
					if (get_nd() == 2)
					{
						out << display_float(get_p()) << "," << get_spherical_theta() << ";" << angles[0];
					}
					out << ")";
					return out.str();
				}
				else
				{
					return "[no-2d]";
				}
			}

			string display_cylindrical() const
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					ostringstream out;
					out << "(";
					if (get_nd() == 3)
					{
						out << display_float(get_p()) << "," << get_spherical_theta() << "," << display_float(values[2]) << ";" << angles[0] << "," << angles[1];
					}
					out << ")";
					return out.str();
				}
				else
				{
					return "[no-3d]";
				}
			}

			string display_spherical() const
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					ostringstream out;
					out << "(";
					if (get_nd() == 3)
					{
						out << display_float(get_r()) << "," << get_spherical_theta() << "," << get_spherical_phi() << ";" << angles[0] << "," << angles[1];
					}
					out << ")";
					return out.str();
				}
				else
				{
					return "[no-3d]";
				}
			}

			string display_geographical() const
			{
				if (values.size() == 3 and angles.size() == 2)
				{
					ostringstream out;
					out << "(";
					if (get_nd() == 3)
					{
						out << get_latitude() << "," << get_longitude() << "," << display_float(get_altitude()) << ";" << angles[0] << "," << angles[1];
					}
					out << ")";
					return out.str();
				}
				else
				{
					return "[no-3d]";
				}
			}

		private:
			vector<float> values;
			vector<angle> angles;
			static float no_value;

			void initialize_from_string(string init_coordinates_ndr)
			{
				vector<string> init_coordinates;
				vector<string> init_values;
				vector<string> init_angles;
				if (init_coordinates_ndr.front() == '(')
				{
					init_coordinates_ndr.erase(0,1);
				}
				if (init_coordinates_ndr.back() == ')')
				{
					init_coordinates_ndr.erase(init_coordinates_ndr.size()-1,1);
				}
				boost::split(init_coordinates,init_coordinates_ndr,boost::is_any_of(";"));
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
						values.push_back(stof(init_values[0]) * scifir::cos(angle(init_values[1])));
						values.push_back(stof(init_values[0]) * scifir::sin(angle(init_values[1])));
					}
					else
					{
						values.push_back(stof(init_values[0]));
						values.push_back(stof(init_values[1]));
					}
					angles.push_back(angle(init_angles[0]));
				}
				else if (init_values.size() == 3 and init_angles.size() == 2)
				{
					if (is_angle(init_values[0]))
					{
						if (is_angle(init_values[1]))
						{
							if (!is_angle(init_values[2]))
							{
								values.push_back(stof(init_values[2]) * scifir::cos(angle(init_values[0])) * scifir::cos(angle(init_values[1])));
								values.push_back(stof(init_values[2]) * scifir::cos(angle(init_values[0])) * scifir::sin(angle(init_values[1])));
								values.push_back(stof(init_values[2]) * scifir::sin(angle(init_values[0])));
							}
						}
					}
					else
					{
						if (is_angle(init_values[1]))
						{
							if (is_angle(init_values[2]))
							{
								values.push_back(stof(init_values[0]) * scifir::cos(angle(init_values[1])) * scifir::sin(angle(init_values[2])));
								values.push_back(stof(init_values[0]) * scifir::sin(angle(init_values[1])) * scifir::sin(angle(init_values[2])));
								values.push_back(stof(init_values[0]) * scifir::cos(angle(init_values[2])));
							}
							else
							{
								values.push_back(stof(init_values[0]) * scifir::cos(angle(init_values[1])));
								values.push_back(stof(init_values[0]) * scifir::sin(angle(init_values[1])));
								values.push_back(stof(init_values[2]));
							}
						}
						else
						{
							if (!is_angle(init_values[2]))
							{
								values.push_back(stof(init_values[0]));
								values.push_back(stof(init_values[1]));
								values.push_back(stof(init_values[2]));
							}
						}
					}
					angles.push_back(angle(init_angles[0]));
					angles.push_back(angle(init_angles[1]));
				}
				else
				{
					if (init_values.size() == (init_angles.size() + 1))
					{
						for (int i = 0; i < init_values.size(); i++)
						{
							values.push_back(stof(init_values[i]));
						}
						for (int i = 0; i < init_angles.size(); i++)
						{
							angles.push_back(angle(init_angles[i]));
						}
					}
				}
			}
	};

	template<typename T>
	string to_string(const coordinates_ndr<T>& x)
	{
		if (x.get_values().size() > 0)
		{
			ostringstream out;
			out << "(";
			if (x.get_values().size() > 0)
			{
				for (int i = 0; i < x.get_values().size(); i++)
				{
					out << x.get_value(i);
					if ((i + 1) != x.get_values().size())
					{
						out << ",";
					}
				}
			}
			if (x.get_angles().size() > 0)
			{
				out << ";";
				for (int i = 0; i < x.get_angles().size(); i++)
				{
					out << x.get_angle(i);
					if ((i + 1) != x.get_angles().size())
					{
						out << ",";
					}
				}
			}
			out << ")";
			return out.str();
		}
		else
		{
			return "[empty]";
		}
	}

	string to_string(const coordinates_ndr<float>&);

	template<typename T>
	T distance(const coordinates_ndr<T>& x1,const coordinates_ndr<T>& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			scalar_unit x_length = scalar_unit(0.0f,"m2");
			for (int i = 0; i < x1.get_values().size(); i++)
			{
				x_length += scifir::pow(x1.get_value(i) - x2.get_value(i),2);
			}
			return scifir::sqrt(x_length);
		}
		else
		{
			return T();
		}
	}

	float distance(const coordinates_ndr<float>&,const coordinates_ndr<float>&);

	template<typename T>
	T distance(const coordinates_ndr<T>& x1,const coordinates_nd<T>& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			scalar_unit x_length = scalar_unit(0.0f,"m2");
			for (int i = 0; i < x1.get_values().size(); i++)
			{
				x_length += scifir::pow(x1.get_value(i) - x2.values[i],2);
			}
			return scifir::sqrt(x_length);
		}
		else
		{
			return T();
		}
	}

	float distance(const coordinates_ndr<float>&,const coordinates_nd<float>&);

	template<typename T>
	T distance(const coordinates_nd<T>& x1,const coordinates_ndr<T>& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			scalar_unit x_length = scalar_unit(0.0f,"m2");
			for (int i = 0; i < x1.values.size(); i++)
			{
				x_length += scifir::pow(x1.values[i] - x2.get_value(i),2);
			}
			return scifir::sqrt(x_length);
		}
		else
		{
			return T();
		}
	}

	float distance(const coordinates_nd<float>&,const coordinates_ndr<float>&);

	template<typename T>
	T distance(const coordinates_ndr<T>& x1,const point_nd<T>& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			scalar_unit x_length = scalar_unit(0.0f,"m2");
			for (int i = 0; i < x1.get_values().size(); i++)
			{
				x_length += scifir::pow(x1.get_value(i) - x2.values[i],2);
			}
			return scifir::sqrt(x_length);
		}
		else
		{
			return T();
		}
	}

	float distance(const coordinates_ndr<float>&,const point_nd<float>&);

	template<typename T>
	T distance(const point_nd<T>& x1,const coordinates_ndr<T>& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			scalar_unit x_length = scalar_unit(0.0f,"m2");
			for (int i = 0; i < x1.values.size(); i++)
			{
				x_length += scifir::pow(x1.values[i] - x2.get_value(i),2);
			}
			return scifir::sqrt(x_length);
		}
		else
		{
			return T();
		}
	}

	float distance(const point_nd<float>&,const coordinates_ndr<float>&);
}

template<typename T>
bool operator ==(const scifir::coordinates_ndr<T>& x,const scifir::coordinates_ndr<T>& y)
{
	for (int i = 0; i < x.get_values().size(); i++)
	{
		if (x.get_value(i) != y.get_value(i))
		{
			return false;
		}
	}
	for (int i = 0; i < x.get_angles().size(); i++)
	{
		if (x.get_angle(i) != y.get_angle(i))
		{
			return false;
		}
	}
	return true;
}

template<typename T>
bool operator !=(const scifir::coordinates_ndr<T>& x,const scifir::coordinates_ndr<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_ndr<T>& x,const scifir::coordinates_nd<T>& y)
{
	if (x.get_values().size() == y.values.size())
	{
		for (int i = 0 ; i < x.get_values().size(); i++)
		{
			if (x.get_value(i) != y.values[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::coordinates_ndr<T>& x,const scifir::coordinates_nd<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_nd<T>& x,const scifir::coordinates_ndr<T>& y)
{
	if (x.values.size() == y.get_values().size())
	{
		for (int i = 0 ; i < x.values.size(); i++)
		{
			if (x.values[i] != y.get_value(i))
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::coordinates_nd<T>& x,const scifir::coordinates_ndr<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_ndr<T>& x,const scifir::point_nd<T>& y)
{
	if (x.get_values().size() == y.values.size())
	{
		for (int i = 0 ; i < x.get_values().size(); i++)
		{
			if (x.get_value(i) != y.values[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::coordinates_ndr<T>& x,const scifir::point_nd<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::point_nd<T>& x,const scifir::coordinates_ndr<T>& y)
{
	if (x.values.size() == y.get_values().size())
	{
		for (int i = 0 ; i < x.values.size(); i++)
		{
			if (x.values[i] != y.get_value(i))
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::point_nd<T>& x,const scifir::coordinates_ndr<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_ndr<T>& x, const string& y)
{
	coordinates_ndr<T> y_coordinates = coordinates_ndr<T>(y);
	return (x == y_coordinates);
}

template<typename T>
bool operator !=(const scifir::coordinates_ndr<T>& x, const string& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const string& x, const scifir::coordinates_ndr<T>& y)
{
	coordinates_ndr<T> x_coordinates = coordinates_ndr<T>(x);
	return (x_coordinates == y);
}

template<typename T>
bool operator !=(const string& x, const scifir::coordinates_ndr<T>& y)
{
	return !(x == y);
}

template<typename T>
void operator +=(string& x, const scifir::coordinates_ndr<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x,const scifir::coordinates_ndr<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::coordinates_ndr<T>& x,const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os,const scifir::coordinates_ndr<T>& x)
{
	return os << to_string(x);
}

ostream& operator <<(ostream& os,const scifir::coordinates_ndr<float>& x);

template<typename T>
istream& operator >>(istream& is, scifir::coordinates_ndr<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	scifir::coordinates_ndr<T> c(b);
	x = c;
	return is;
}

#endif // SCIFIR_UNITS_COORDINATES_COORDINATES_NDR_HPP_INCLUDED
