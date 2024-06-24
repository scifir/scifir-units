#ifndef SCIFIR_UNITS_COORDINATES_COORDINATES_ND_HPP_INCLUDED
#define SCIFIR_UNITS_COORDINATES_COORDINATES_ND_HPP_INCLUDED

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
	template<typename T = length>
	class coordinates_nd
	{
		public:
			coordinates_nd() : values()
			{}

			coordinates_nd(const coordinates_nd<T>& x) : values(x.values)
			{}

			coordinates_nd(coordinates_nd<T>&& x) : values(std::move(x.values))
			{}

			explicit coordinates_nd(const vector<T>& new_values) : values(new_values)
			{}

			explicit coordinates_nd(const T& new_x) : values()
			{
				values.push_back(new_x);
			}

			explicit coordinates_nd(const T& new_x,const T& new_y) : values()
			{
				values.push_back(new_x);
				values.push_back(new_y);
			}

			explicit coordinates_nd(const T& new_p,const angle& new_theta) : values()
			{
				set_position(new_p,new_theta);
			}

			explicit coordinates_nd(const T& new_x,const T& new_y,const T& new_z) : values()
			{
				values.push_back(new_x);
				values.push_back(new_y);
				values.push_back(new_z);
			}

			explicit coordinates_nd(const T& new_p,const angle& new_theta,T new_z) : values()
			{
				set_position(new_p,new_theta,new_z);
			}

			explicit coordinates_nd(const T& new_r,const angle& new_theta,const angle& new_phi) : values()
			{
				set_position(new_r,new_theta,new_phi);
			}

			explicit coordinates_nd(const angle& new_latitude,const angle& new_longitude,const T& new_altitude) : values()
			{
				set_position(new_latitude,new_longitude,new_altitude);
			}

			explicit coordinates_nd(const point_nd<T>& new_point) : values(new_point.values)
			{}

			explicit coordinates_nd(string init_coordinates_nd) : values()
			{
				vector<string> init_values;
				if (init_coordinates_nd.front() == '(')
				{
					init_coordinates_nd.erase(0,1);
				}
				if (init_coordinates_nd.back() == ')')
				{
					init_coordinates_nd.erase(init_coordinates_nd.size()-1,1);
				}
				boost::split(init_values,init_coordinates_nd,boost::is_any_of(","));
				if (init_values.size() == 2)
				{
					if (is_angle(init_values[1]))
					{
						set_position(T(init_values[0]),angle(init_values[1]));
					}
					else
					{
						set_position(T(init_values[0]),T(init_values[1]));
					}
				}
				else if (init_values.size() == 3)
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
				}
				else
				{
					for (const string& x_value : init_values)
					{
						values.push_back(T(x_value));
					}
				}
			}

			coordinates_nd<T>& operator=(const coordinates_nd<T>& x_coordinates)
			{
				values = x_coordinates.values;
				return *this;
			}

			coordinates_nd<T>& operator=(coordinates_nd<T>&& x_coordinates)
			{
				values = std::move(x_coordinates.values);
				return *this;
			}

			coordinates_nd<T>& operator=(const point_nd<T>& x_point)
			{
				values = x_point.values;
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

			angle get_theta() const
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

			angle get_phi() const
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

			void set_position(const T& new_x)
			{
				values.clear();
				values.push_back(new_x);
			}

			void set_position(const T& new_x,const T& new_y)
			{
				values.clear();
				values.push_back(new_x);
				values.push_back(new_y);
			}

			void set_position(const T& new_p,const angle& new_theta)
			{
				values.clear();
				values.push_back(T(new_p * scifir::cos(new_theta)));
				values.push_back(T(new_p * scifir::sin(new_theta)));
			}

			void set_position(const T& new_x,const T& new_y,const T& new_z)
			{
				values.clear();
				values.push_back(new_x);
				values.push_back(new_y);
				values.push_back(new_z);
			}

			void set_position(const T& new_p,const angle& new_theta,T new_z)
			{
				values.clear();
				new_z.change_dimensions(new_p);
				values.push_back(T(new_p * scifir::cos(new_theta)));
				values.push_back(T(new_p * scifir::sin(new_theta)));
				values.push_back(new_z);
			}

			void set_position(const T& new_r,const angle& new_theta,const angle& new_phi)
			{
				values.clear();
				values.push_back(T(new_r * scifir::cos(new_theta) * scifir::sin(new_phi)));
				values.push_back(T(new_r * scifir::sin(new_theta) * scifir::sin(new_phi)));
				values.push_back(T(new_r * scifir::cos(new_phi)));
			}

			void set_position(const angle& new_latitude,const angle& new_longitude,const T& new_altitude)
			{
				values.clear();
				values.push_back(T(new_altitude * scifir::cos(new_latitude) * scifir::cos(new_longitude)));
				values.push_back(T(new_altitude * scifir::cos(new_latitude) * scifir::sin(new_longitude)));
				values.push_back(T(new_altitude * scifir::sin(new_latitude)));
			}

			void set_position(const vector<T>& new_values)
			{
				values.clear();
				values = new_values;
			}

			void rotate(int dimension_number,int axis,const angle& new_theta)
			{
				if (dimension_number == 2 and get_nd() == 2)
				{
					T x_coord = values[0];
					T y_coord = values[1];
					values[0] = x_coord * scifir::cos(new_theta) - y_coord * scifir::sin(new_theta);
					values[1] = x_coord * scifir::sin(new_theta) + y_coord * scifir::cos(new_theta);
				}
				else if (dimension_number == 3 and get_nd() == 3)
				{
					T coord_1 = values[axis + 1];
					T coord_2 = values[axis + 2];
					values[axis + 1] = coord_1 * scifir::cos(new_theta) - coord_2 * scifir::sin(new_theta);
					values[axis + 2] = coord_1 * scifir::sin(new_theta) + coord_2 * scifir::cos(new_theta);
				}
			}

			void move(const T& new_x)
			{
				if (values.size() == 1)
				{
					values[0] += new_x;
				}
			}

			void move(const displacement_2d& x_displacement)
			{
				if (values.size() == 2)
				{
					values[0] += x_displacement.x_projection();
					values[1] += x_displacement.y_projection();
				}
			}

			void move(const T& new_x,const T& new_y)
			{
				if (values.size() == 2)
				{
					values[0] += new_x;
					values[1] += new_y;
				}
			}

			void move(const T& new_p,const angle& new_theta)
			{
				if (values.size() == 2)
				{
					values[0] += new_p * scifir::cos(new_theta);
					values[1] += new_p * scifir::sin(new_theta);
				}
			}

			void move(const displacement_3d& x_displacement)
			{
				if (values.size() == 3)
				{
					values[0] += x_displacement.x_projection();
					values[1] += x_displacement.y_projection();
					values[2] += x_displacement.z_projection();
				}
			}

			void move(const T& new_x,const T& new_y,const T& new_z)
			{
				if (values.size() == 3)
				{
					values[0] += new_x;
					values[1] += new_y;
					values[2] += new_z;
				}
			}

			void move(const T& new_p,const angle& new_theta,T new_z)
			{
				if (values.size() == 3)
				{
					new_z.change_dimensions(new_p);
					values[0] += T(new_p * scifir::cos(new_theta));
					values[1] += T(new_p * scifir::sin(new_theta));
					values[2] += new_z;
				}
			}

			void move(const T& new_r,const angle& new_theta,const angle& new_phi)
			{
				if (values.size() == 3)
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
				ostringstream out;
				out << "(" << get_p() << "," << get_theta() << ")";
				return out.str();
			}

			string display_cylindrical() const
			{
				ostringstream out;
				out << "(" << get_p() << "," << get_theta() << "," << values[2] << ")";
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

			vector<T> values;
	};

	template<>
	class coordinates_nd<float>
	{
		public:
			coordinates_nd() : values()
			{}

			coordinates_nd(const coordinates_nd<float>& x) : values(x.values)
			{}

			coordinates_nd(coordinates_nd<float>&& x) : values(std::move(x.values))
			{}

			explicit coordinates_nd(const vector<float>& new_values) : values(new_values)
			{}

			explicit coordinates_nd(const float& new_x) : values()
			{
				values.push_back(new_x);
			}

			explicit coordinates_nd(const float& new_x,const float& new_y) : values()
			{
				values.push_back(new_x);
				values.push_back(new_y);
			}

			explicit coordinates_nd(const float& new_p,const angle& new_theta) : values()
			{
				set_position(new_p,new_theta);
			}

			explicit coordinates_nd(const float& new_x,const float& new_y,const float& new_z) : values()
			{
				values.push_back(new_x);
				values.push_back(new_y);
				values.push_back(new_z);
			}

			explicit coordinates_nd(const float& new_p,const angle& new_theta,const float& new_z) : values()
			{
				set_position(new_p,new_theta,new_z);
			}

			explicit coordinates_nd(const float& new_r,const angle& new_theta,const angle& new_phi) : values()
			{
				set_position(new_r,new_theta,new_phi);
			}

			explicit coordinates_nd(const angle& new_latitude,const angle& new_longitude,const float& new_altitude) : values()
			{
				set_position(new_latitude,new_longitude,new_altitude);
			}

			explicit coordinates_nd(const point_nd<float>& new_point) : values(new_point.values)
			{}

			explicit coordinates_nd(string init_coordinates_nd) : values()
			{
				vector<string> init_values;
				if (init_coordinates_nd.front() == '(')
				{
					init_coordinates_nd.erase(0,1);
				}
				if (init_coordinates_nd.back() == ')')
				{
					init_coordinates_nd.erase(init_coordinates_nd.size()-1,1);
				}
				boost::split(init_values,init_coordinates_nd,boost::is_any_of(","));
				if (init_values.size() == 2)
				{
					if (is_angle(init_values[1]))
					{
						set_position(stof(init_values[0]),angle(init_values[1]));
					}
					else
					{
						set_position(stof(init_values[0]),stof(init_values[1]));
					}
				}
				else if (init_values.size() == 3)
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
				}
				else
				{
					for (const string& x_value : init_values)
					{
						values.push_back(stof(x_value));
					}
				}
			}

			coordinates_nd<float>& operator=(const coordinates_nd<float>& x_coordinates)
			{
				values = x_coordinates.values;
				return *this;
			}

			coordinates_nd<float>& operator=(coordinates_nd<float>&& x_coordinates)
			{
				values = std::move(x_coordinates.values);
				return *this;
			}

			coordinates_nd<float>& operator=(const point_nd<float>& x_point)
			{
				values = x_point.values;
				return *this;
			}

			bool is_nd(unsigned int i) const
			{
				return values.size() == i;
			}

			int get_nd() const
			{
				return int(values.size());
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

			angle get_theta() const
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

			angle get_phi() const
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

			void set_position(const float& new_x)
			{
				values.clear();
				values.push_back(new_x);
			}

			void set_position(const float& new_x,const float& new_y)
			{
				values.clear();
				values.push_back(new_x);
				values.push_back(new_y);
			}

			void set_position(const float& new_p,const angle& new_theta)
			{
				values.clear();
				values.push_back(new_p * scifir::cos(new_theta));
				values.push_back(new_p * scifir::sin(new_theta));
			}

			void set_position(const float& new_x,const float& new_y,const float& new_z)
			{
				values.clear();
				values.push_back(new_x);
				values.push_back(new_y);
				values.push_back(new_z);
			}

			void set_position(const float& new_p,const angle& new_theta,const float& new_z)
			{
				values.clear();
				values.push_back(new_p * scifir::cos(new_theta));
				values.push_back(new_p * scifir::sin(new_theta));
				values.push_back(new_z);
			}

			void set_position(const float& new_r,const angle& new_theta,const angle& new_phi)
			{
				values.clear();
				values.push_back(new_r * scifir::cos(new_theta) * scifir::sin(new_phi));
				values.push_back(new_r * scifir::sin(new_theta) * scifir::sin(new_phi));
				values.push_back(new_r * scifir::cos(new_phi));
			}

			void set_position(const angle& new_latitude,const angle& new_longitude,const float& new_altitude)
			{
				values.clear();
				values.push_back(new_altitude * scifir::cos(new_latitude) * scifir::cos(new_longitude));
				values.push_back(new_altitude * scifir::cos(new_latitude) * scifir::sin(new_longitude));
				values.push_back(new_altitude * scifir::sin(new_latitude));
			}

			void set_position(const vector<float>& new_values)
			{
				values.clear();
				values = new_values;
			}

			void rotate(int dimension_number,int axis,const angle& new_theta)
			{
				if (dimension_number == 2 and get_nd() == 2)
				{
					float x_coord = values[0];
					float y_coord = values[1];
					values[0] = x_coord * scifir::cos(new_theta) - y_coord * scifir::sin(new_theta);
					values[1] = x_coord * scifir::sin(new_theta) + y_coord * scifir::cos(new_theta);
				}
				else if (dimension_number == 3 and get_nd() == 3)
				{
					float coord_1 = values[axis + 1];
					float coord_2 = values[axis + 2];
					values[axis + 1] = coord_1 * scifir::cos(new_theta) - coord_2 * scifir::sin(new_theta);
					values[axis + 2] = coord_1 * scifir::sin(new_theta) + coord_2 * scifir::cos(new_theta);
				}
			}

			void move(const float& new_x)
			{
				if (values.size() == 1)
				{
					values[0] += new_x;
				}
			}

			void move(const displacement_2d& x_displacement)
			{
				if (values.size() == 2)
				{
					values[0] += float(x_displacement.x_projection());
					values[1] += float(x_displacement.y_projection());
				}
			}

			void move(const float& new_x,const float& new_y)
			{
				if (values.size() == 2)
				{
					values[0] += new_x;
					values[1] += new_y;
				}
			}

			void move(const float& new_p,const angle& new_theta)
			{
				if (values.size() == 2)
				{
					values[0] += new_p * scifir::cos(new_theta);
					values[1] += new_p * scifir::sin(new_theta);
				}
			}

			void move(const displacement_3d& x_displacement)
			{
				if (values.size() == 3)
				{
					values[0] += float(x_displacement.x_projection());
					values[1] += float(x_displacement.y_projection());
					values[2] += float(x_displacement.z_projection());
				}
			}

			void move(const float& new_x,const float& new_y,const float& new_z)
			{
				if (values.size() == 3)
				{
					values[0] += new_x;
					values[1] += new_y;
					values[2] += new_z;
				}
			}

			void move(const float& new_p,const angle& new_theta,const float& new_z)
			{
				if (values.size() == 3)
				{
					values[0] += new_p * scifir::cos(new_theta);
					values[1] += new_p * scifir::sin(new_theta);
					values[2] += new_z;
				}
			}

			void move(const float& new_r,const angle& new_theta,const angle& new_phi)
			{
				if (values.size() == 3)
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

			void move(const float& new_r,const vector<angle>& new_angles)
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
				ostringstream out;
				out << "(" << display_float(get_p()) << "," << get_theta() << ")";
				return out.str();
			}

			string display_cylindrical() const
			{
				ostringstream out;
				out << "(" << display_float(get_p()) << "," << get_theta() << "," << display_float(values[2]) << ")";
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

			vector<float> values;
	};

	template<typename T>
	string to_string(const coordinates_nd<T>& x)
	{
		ostringstream out;
		out << "(";
		for (int i = 0; i < x.values.size(); i++)
		{
			out << x.values[i];
			if ((i + 1) != x.values.size())
			{
				out << ",";
			}
		}
		out << ")";
		return out.str();
	}

	string to_string(const coordinates_nd<float>&);

	template<typename T>
	T distance(const coordinates_nd<T>& x1,const coordinates_nd<T>& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			scalar_unit x_length = scalar_unit(0.0f,"m2");
			for (int i = 0; i < x1.values.size(); i++)
			{
				x_length += scifir::pow(x1.values[i] - x2.values[i],2);
			}
			return scifir::sqrt(x_length);
		}
		else
		{
			return T();
		}
	}

	float distance(const coordinates_nd<float>&,const coordinates_nd<float>&);

	template<typename T>
	T distance(const coordinates_nd<T>& x1,const point_nd<T>& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			scalar_unit x_length = scalar_unit(0.0f,"m2");
			for (int i = 0; i < x1.values.size(); i++)
			{
				x_length += scifir::pow(x1.values[i] - x2.values[i],2);
			}
			return scifir::sqrt(x_length);
		}
		else
		{
			return T();
		}
	}

	float distance(const coordinates_nd<float>&,const point_nd<float>&);

	template<typename T>
	T distance(const point_nd<T>& x1,const coordinates_nd<T>& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			scalar_unit x_length = scalar_unit(0.0f,"m2");
			for (int i = 0; i < x1.values.size(); i++)
			{
				x_length += scifir::pow(x1.values[i] - x2.values[i],2);
			}
			return scifir::sqrt(x_length);
		}
		else
		{
			return T();
		}
	}

	float distance(const point_nd<float>&,const coordinates_nd<float>&);
}

template<typename T>
bool operator ==(const scifir::coordinates_nd<T>& x,const scifir::coordinates_nd<T>& y)
{
	for (int i = 0; i < x.values.size(); i++)
	{
		if (x.values[i] != y.values[i])
		{
			return false;
		}
	}
	return true;
}

template<typename T>
bool operator !=(const scifir::coordinates_nd<T>& x,const scifir::coordinates_nd<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_nd<T>& x,const scifir::point_nd<T>& y)
{
	for (int i = 0 ; i < x.values.size(); i++)
	{
		if (x.values[i] == y.values[i])
		{
			return false;
		}
	}
	return true;
}

template<typename T>
bool operator !=(const scifir::coordinates_nd<T>& x,const scifir::point_nd<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::point_nd<T>& x,const scifir::coordinates_nd<T>& y)
{
	for (int i = 0 ; i < x.values.size(); i++)
	{
		if (x.values[i] == y.values[i])
		{
			return false;
		}
	}
	return true;
}

template<typename T>
bool operator !=(const scifir::point_nd<T>& x,const scifir::coordinates_nd<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::coordinates_nd<T>& x, const string& y)
{
	coordinates_nd<T> y_coordinates = coordinates_nd<T>(y);
	return (x == y_coordinates);
}

template<typename T>
bool operator !=(const scifir::coordinates_nd<T>& x, const string& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const string& x, const scifir::coordinates_nd<T>& y)
{
	coordinates_nd<T> x_coordinates = coordinates_nd<T>(x);
	return (x_coordinates == y);
}

template<typename T>
bool operator !=(const string& x, const scifir::coordinates_nd<T>& y)
{
	return !(x == y);
}

template<typename T>
void operator +=(string& x, const scifir::coordinates_nd<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x,const scifir::coordinates_nd<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::coordinates_nd<T>& x,const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os,const scifir::coordinates_nd<T>& x)
{
	return os << to_string(x);
}

template<typename T>
istream& operator >>(istream& is, scifir::coordinates_nd<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	scifir::coordinates_nd<T> c(b);
	x = c;
	return is;
}

#endif // SCIFIR_UNITS_COORDINATES_COORDINATES_ND_HPP_INCLUDED
