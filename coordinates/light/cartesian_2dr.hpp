#ifndef MSCI_UNITS_COORDINATES_CARTESIAN_2DR_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_CARTESIAN_2DR_HPP_INCLUDED

#include "msci/units/topology/point_2d.hpp"
#include "msci/units/meca_number/angle.hpp"
#include "msci/units/coordinates/light/cartesian_2d.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class cartesian_2dr
	{
		public:
			cartesian_2dr();
			cartesian_2dr(const length&,const length&,float);
			cartesian_2dr(const string&);

			inline length& get_x()
			{
				return x;
			}

			inline const length& get_x() const
			{
				return x;
			}

			inline length& get_y()
			{
				return y;
			}

			inline const length& get_y() const
			{
				return y;
			}

			inline msci::angle& get_angle()
			{
				return angle;
			}

			inline const msci::angle& get_angle() const
			{
				return angle;
			}

			string display() const;

		private:
			length x;
			length y;
			msci::angle angle;
	};

	length coordinates_distance(const cartesian_2dr&,const cartesian_2dr&);
}

bool operator ==(const msci::cartesian_2dr&,const msci::cartesian_2dr&);
bool operator !=(const msci::cartesian_2dr&,const msci::cartesian_2dr&);

bool operator ==(const msci::cartesian_2dr&,const msci::cartesian_2d&);
bool operator !=(const msci::cartesian_2dr&,const msci::cartesian_2d&);
bool operator ==(const msci::cartesian_2d&,const msci::cartesian_2dr&);
bool operator !=(const msci::cartesian_2d&,const msci::cartesian_2dr&);

bool operator ==(const msci::cartesian_2dr&,const msci::point_2d&);
bool operator !=(const msci::cartesian_2dr&,const msci::point_2d&);
bool operator ==(const msci::point_2d&,const msci::cartesian_2dr&);
bool operator !=(const msci::point_2d&,const msci::cartesian_2dr&);

ostream& operator << (ostream&, const msci::cartesian_2dr&);

#endif // MSCI_UNITS_COORDINATES_CARTESIAN_2DR_HPP_INCLUDED
