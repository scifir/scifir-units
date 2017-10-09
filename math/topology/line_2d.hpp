#ifndef MATH_TOPOLOGY_LINE_2D_HPP_INCLUDED
#define MATH_TOPOLOGY_LINE_2D_HPP_INCLUDED

#include "units.hpp"

#include <cmath>
#include <iostream>
#include <string>

#include "point_2d.hpp"

using namespace std;

namespace msci
{
	class line_2d
	{
		public:
			line_2d();
			explicit line_2d(const point_2d&,const point_2d&);

			inline point_2d& get_vertex1()
			{
				return vertex1;
			}

			inline const point_2d& get_vertex1() const
			{
				return vertex1;
			}

			inline point_2d& get_vertex2()
			{
				return vertex2;
			}

			inline const point_2d& get_vertex2() const
			{
				return vertex2;
			}

			inline bool is_upper(const point_2d& x) const
			{
				if (is_horizontally_centered(x))
				{
					return (x.get_y() > get_y_relative_point(x.get_x()));
				}
				else
				{
					return (x.get_y() > get_max_y());
				}
			}

			inline bool is_vertical_upper(const point_2d& x) const
			{
				return (x.get_y() > get_y_relative_point(x.get_x()));
			}

			inline bool is_lower(const point_2d& x) const
			{
				if (is_horizontally_centered(x))
				{
					return (x.get_y() < get_y_relative_point(x.get_x()));
				}
				else
				{
					return (x.get_y() < get_min_y());
				}
			}

			inline bool is_vertical_lower(const point_2d& x) const
			{
				return (x.get_y() < get_y_relative_point(x.get_x()));
			}

			inline bool is_vertically_centered(const point_2d& x) const
			{
				return (x.get_y() >= get_min_y() and x.get_y() <= get_max_y());
			}

			inline bool is_at_left(const point_2d& x) const
			{
				if (is_vertically_centered(x))
				{
					return (x.get_x() < get_x_relative_point(x.get_y()));
				}
				else
				{
					return (x.get_x() < get_min_x());
				}
			}

			inline bool is_at_horizontal_left(const point_2d& x) const
			{
				return (x.get_x() < get_x_relative_point(x.get_y()));
			}

			inline bool is_at_right(const point_2d& x) const
			{
				if (is_vertically_centered(x))
				{
					return (x.get_x() > get_x_relative_point(x.get_y()));
				}
				else
				{
					return (x.get_x() > get_max_x());
				}
			}

			inline bool is_at_horizontal_right(const point_2d& x) const
			{
				return (x.get_x() > get_x_relative_point(x.get_y()));
			}

			inline bool is_horizontally_centered(const point_2d& x) const
			{
				return (x.get_x() >= get_min_x() and x.get_x() <= get_max_x());
			}

			inline space_type get_min_x() const
			{
				return std::min(vertex1.get_x(),vertex2.get_x());
			}

			inline space_type get_max_x() const
			{
				return std::max(vertex1.get_x(),vertex2.get_x());
			}

			inline space_type get_min_y() const
			{
				return std::min(vertex1.get_y(),vertex2.get_y());
			}

			inline space_type get_max_y() const
			{
				return std::max(vertex1.get_y(),vertex2.get_y());
			}

			inline space_type get_x_slope() const
			{
				return (std::abs(vertex1.get_x() - vertex2.get_x())/std::abs(vertex1.get_y() - vertex2.get_y()));
			}

			inline space_type get_y_slope() const
			{
				return (std::abs(vertex1.get_y() - vertex2.get_y())/std::abs(vertex1.get_x() - vertex2.get_x()));
			}

			inline space_type get_x_relative_point(space_type y_reference) const
			{
				return get_min_x() + get_x_slope()*y_reference;
			}

			inline space_type get_y_relative_point(space_type x_reference) const
			{
				return get_min_y() + get_y_slope()*x_reference;
			}

			length get_length() const;

			wstring display() const;
			void print() const;

		private:
			point_2d vertex1;
			point_2d vertex2;
	};
}

bool operator ==(const msci::line_2d&,const msci::line_2d&);
bool operator !=(const msci::line_2d&,const msci::line_2d&);
wostream& operator <<(wostream&,const msci::line_2d&);

#endif // MATH_TOPOLOGY_LINE_2D_HPP_INCLUDED
