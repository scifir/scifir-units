#ifndef MATH_TOPOLOGY_POINT_2D_HPP_INCLUDED
#define MATH_TOPOLOGY_POINT_2D_HPP_INCLUDED

#include "topology.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace math
{
	class point_2d
	{
		public:
			point_2d();
			point_2d(space_type,space_type);

			inline space_type& get_x()
			{
				return x;
			}

			inline space_type get_x() const
			{
				return x;
			}

			inline space_type& get_y()
			{
				return y;
			}

			inline space_type get_y() const
			{
				return y;
			}

			space_type distance_to_origin() const;

			wstring display() const;
			void print() const;

		private:
			space_type x;
			space_type y;
	};

	space_type distance(const point_2d&,const point_2d&);
}

bool operator ==(const math::point_2d&,const math::point_2d&);
bool operator !=(const math::point_2d&,const math::point_2d&);
wostream& operator <<(wostream&,const math::point_2d&);

#endif // MATH_TOPOLOGY_POINT_2D_HPP_INCLUDED
