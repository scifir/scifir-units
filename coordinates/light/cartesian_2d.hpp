#ifndef CARTESIAN_2D_HPP_INCLUDED
#define CARTESIAN_2D_HPP_INCLUDED

#include "msci/units/topology/point_2d.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class cartesian_2d
	{
		public:
			cartesian_2d();
			cartesian_2d(float,float);

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

			string display() const;

		private:
			float x;
			float y;
	};

	float coordinates_distance(const cartesian_2d&,const cartesian_2d&);
}

bool operator ==(const msci::cartesian_2d&,const msci::cartesian_2d&);
bool operator !=(const msci::cartesian_2d&,const msci::cartesian_2d&);

bool operator ==(const msci::cartesian_2d&,const msci::point_2d&);
bool operator !=(const msci::cartesian_2d&,const msci::point_2d&);
bool operator ==(const msci::point_2d&,const msci::cartesian_2d&);
bool operator !=(const msci::point_2d&,const msci::cartesian_2d&);

ostream& operator << (ostream&, const msci::cartesian_2d&);

#endif // CARTESIAN_2D_HPP_INCLUDED
