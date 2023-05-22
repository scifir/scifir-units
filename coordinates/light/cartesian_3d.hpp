#ifndef MSCI_UNITS_COORDINATES_CARTESIAN_3D_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_CARTESIAN_3D_HPP_INCLUDED

#include "msci/units/topology/point_3d.hpp"
#include "msci/units/meca_number/angle.hpp"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

namespace msci
{
	enum coordinates_system {CARTESIAN, CYLINDRICAL, SPHERICAL, GEOGRAPHICAL, POLAR};

	class cartesian_3d
	{
		public:
			cartesian_3d();
			cartesian_3d(coordinates_system,float,float,float);
			cartesian_3d(coordinates_system,string);

			inline float& get_x()
			{
				return x;
			}

			inline const float& get_x() const
			{
				return x;
			}

			inline float& get_y()
			{
				return y;
			}

			inline const float& get_y() const
			{
				return y;
			}

			inline float& get_z()
			{
				return z;
			}

			inline const float& get_z() const
			{
				return z;
			}

			inline float get_p() const
			{
				return std::sqrt(std::pow(x,2) + std::pow(y,2));
			}

			inline float get_theta() const
			{
				return msci::atan_grade(y/x);
			}

			inline float get_r() const
			{
				return std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2));
			}

			inline float get_phi() const
			{
				return msci::acos_grade(z/std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2)));
			}

			string display() const;
			void set_position(coordinates_system,float,float,float);

		private:
			float x;
			float y;
			float z;
	};

	float distance(const cartesian_3d&,const cartesian_3d&);
}

bool operator ==(const msci::cartesian_3d&,const msci::cartesian_3d&);
bool operator !=(const msci::cartesian_3d&,const msci::cartesian_3d&);

bool operator ==(const msci::cartesian_3d&,const msci::point_3d&);
bool operator !=(const msci::cartesian_3d&,const msci::point_3d&);
bool operator ==(const msci::point_3d&,const msci::cartesian_3d&);
bool operator !=(const msci::point_3d&,const msci::cartesian_3d&);

ostream& operator << (ostream&, const msci::cartesian_3d&);

#endif // MSCI_UNITS_COORDINATES_CARTESIAN_3D_HPP_INCLUDED
