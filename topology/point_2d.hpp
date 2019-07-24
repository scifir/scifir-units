#ifndef MATH_TOPOLOGY_POINT_2D_HPP_INCLUDED
#define MATH_TOPOLOGY_POINT_2D_HPP_INCLUDED

#include "msci/units.hpp"

#include <string>

using namespace std;

namespace msci
{
	class point_2d
	{
		public:
			point_2d();
			point_2d(const length&,const length&);

			inline length& get_x()
			{
				return x;
			}

			inline length get_x() const
			{
				return x;
			}

			inline length& get_y()
			{
				return y;
			}

			inline length get_y() const
			{
				return y;
			}

			void move_in_direction(const length&,const angle&);

			length distance_to_origin() const;

			string display() const;

		private:
			length x;
			length y;
	};

	length distance_between_points(const point_2d&,const point_2d&);
}

bool operator ==(const msci::point_2d&,const msci::point_2d&);
bool operator !=(const msci::point_2d&,const msci::point_2d&);
ostream& operator <<(ostream&,const msci::point_2d&);

#endif // MATH_TOPOLOGY_POINT_2D_HPP_INCLUDED
