#ifndef MATH_TOPOLOGY_LINE_3D_HPP_INCLUDED
#define MATH_TOPOLOGY_LINE_3D_HPP_INCLUDED

#include "units.hpp"
#include "point_3d.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class line_3d
	{
		public:
			line_3d();
			explicit line_3d(const point_3d&,const point_3d&);

			inline point_3d& get_vertex1()
			{
				return vertex1;
			}

			inline const point_3d& get_vertex1() const
			{
				return vertex1;
			}

			inline point_3d& get_vertex2()
			{
				return vertex2;
			}

			inline const point_3d& get_vertex2() const
			{
				return vertex2;
			}

			length get_length() const;

			string display() const;
			void print() const;

		private:
			point_3d vertex1;
			point_3d vertex2;
	};
}

bool operator ==(const msci::line_3d&,const msci::line_3d&);
bool operator !=(const msci::line_3d&,const msci::line_3d&);
ostream& operator <<(ostream&,const msci::line_3d&);

#endif // MATH_TOPOLOGY_LINE_3D_HPP_INCLUDED
