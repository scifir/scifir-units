#ifndef MSCI_UNITS_COORDINATES_COORDINATES_3D_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_COORDINATES_3D_HPP_INCLUDED

#include "topology/point_3d.hpp"
#include "meca_number/angle.hpp"

#include "units/unit_basic.hpp"
#include "predefined_units/kinematics_units.hpp"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

namespace msci
{
	enum class coordinates {CARTESIAN, CYLINDRICAL, SPHERICAL, GEOGRAPHICAL, POLAR};
	
	class coordinates_3d
	{
		public:
			coordinates_3d();
			coordinates_3d(const coordinates_3d&);
			coordinates_3d(coordinates_3d&&);
			explicit coordinates_3d(const length&,const length&,const length&);
			explicit coordinates_3d(const length&,const angle&,length);
			explicit coordinates_3d(const length&,const angle&,const angle&);
			explicit coordinates_3d(const angle&,const angle&,const length&);
			explicit coordinates_3d(const point_3d&);
			explicit coordinates_3d(string);

			coordinates_3d& operator=(const coordinates_3d&);
			coordinates_3d& operator=(coordinates_3d&&);
			coordinates_3d& operator=(const point_3d&);

			length get_p() const;
			angle get_theta() const;
			length get_r() const;
			angle get_phi() const;
			angle get_latitude() const;
			angle get_longitude() const;
			length get_altitude() const;

			void set_position(const length&,const length&,const length&);
			void set_position(const length&,const angle&,length);
			void set_position(const length&,const angle&,const angle&);
			void set_position(const angle&,const angle&,const length&);
			
			void rotate_in_x(const angle&);
			void rotate_in_y(const angle&);
			void rotate_in_z(const angle&);
			void move(const displacement_3d&);
			void move(const length&,const length&,const length&);
			void move(const length&,const angle&,length);
			void move(const length&,const angle&,const angle&);
			
			length distance_to_origin() const;
			
			string display_cylindrical() const;
			string display_spherical() const;
			string display_geographical() const;

			length x;
			length y;
			length z;
	};

	string to_string(const coordinates_3d&);
	length distance(const coordinates_3d&,const coordinates_3d&);
	length distance(const coordinates_3d&,const point_3d&);
	length distance(const point_3d&,const coordinates_3d&);
	
	inline float cartesian_3d_to_cylindrical_r(float x,float y,float z)
	{
		return std::sqrt(std::pow(x,2) + std::pow(y,2));
	}

	inline float cartesian_3d_to_cylindrical_theta(float x,float y,float z)
	{
		return std::atan(y/x);
	}

	inline float cartesian_3d_to_cylindrical_z(float x,float y,float z)
	{
		return z;
	}

	inline float cartesian_3d_to_spherical_r(float x,float y,float z)
	{
		return std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2));
	}

	inline float cartesian_3d_to_spherical_theta(float x,float y,float z)
	{
		return std::atan(y/x);
	}

	inline float cartesian_3d_to_spherical_phi(float x,float y,float z)
	{
		return std::acos(z/std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2)));
	}

	inline float spherical_to_cartesian_3d_x(float r,const angle& angle1, const angle& angle2)
	{
		return r * msci::cos(angle1) * msci::sin(angle2);
	}

	inline float spherical_to_cartesian_3d_y(float r,const angle& angle1, const angle& angle2)
	{
		return r * msci::sin(angle1) * msci::sin(angle2);
	}

	inline float spherical_to_cartesian_3d_z(float r,const angle& angle1, const angle& angle2)
	{
		return r * msci::cos(angle2);
	}

	inline float spherical_to_cylindrical_r(float r,const angle& angle1, const angle& angle2)
	{
		return r * msci::sin(angle2);
	}

	inline float spherical_to_cylindrical_theta(float r,const angle& angle1, const angle& angle2)
	{
		return angle1.get_value();
	}

	inline float spherical_to_cylindrical_z(float r,const angle& angle1, const angle& angle2)
	{
		return r * msci::cos(angle2);
	}

	inline float cylindrical_to_cartesian_3d_x(float r,const angle& angle, float z)
	{
		return r * msci::cos(angle);
	}

	inline float cylindrical_to_cartesian_3d_y(float r,const angle& angle, float z)
	{
		return r * msci::sin(angle);
	}

	inline float cylindrical_to_cartesian_3d_z(float r,const angle& angle, float z)
	{
		return z;
	}

	inline float cylindrical_to_spherical_r(float r,const angle& angle, float z)
	{
		return std::sqrt(std::pow(r,2) + std::pow(z,2));
	}

	inline float cylindrical_to_spherical_theta(float r,const angle& angle, float z)
	{
		return angle.get_value();
	}

	inline float cylindrical_to_spherical_phi(float r,const angle& angle, float z)
	{
		return std::atan(r/z);
	}
}

bool operator ==(const msci::coordinates_3d&,const msci::coordinates_3d&);
bool operator !=(const msci::coordinates_3d&,const msci::coordinates_3d&);

bool operator ==(const msci::coordinates_3d&,const msci::point_3d&);
bool operator !=(const msci::coordinates_3d&,const msci::point_3d&);
bool operator ==(const msci::point_3d&,const msci::coordinates_3d&);
bool operator !=(const msci::point_3d&,const msci::coordinates_3d&);

bool operator ==(const msci::coordinates_3d&, const string&);
bool operator !=(const msci::coordinates_3d&, const string&);

bool operator ==(const string&, const msci::coordinates_3d&);
bool operator !=(const string&, const msci::coordinates_3d&);

void operator +=(string&, const msci::coordinates_3d&);
string operator +(const string&,const msci::coordinates_3d&);
string operator +(const msci::coordinates_3d&,const string&);

ostream& operator << (ostream&, const msci::coordinates_3d&);
istream& operator >>(istream&, msci::coordinates_3d&);

#endif // MSCI_UNITS_COORDINATES_COORDINATES_3D_HPP_INCLUDED
