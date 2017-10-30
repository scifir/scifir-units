#ifndef MATH_TOPOLOGY_FIGURE_2D_CIRCLE_HPP_INCLUDED
#define MATH_TOPOLOGY_FIGURE_2D_CIRCLE_HPP_INCLUDED

#include "figure_2d.hpp"

using namespace std;

namespace msci
{
	class circle : public figure_2d
	{
		public:
			circle();
			explicit circle(const point_2d&,space_type);
			explicit circle(space_type,space_type,space_type);

			inline const space_type& get_r() const
			{
				return r;
			}

			inline space_type min_x() const
			{
				return (figure_2d::center.get_x() - r);
			}

			inline space_type max_x() const
			{
				return (figure_2d::center.get_x() + r);
			}

			inline space_type min_y() const
			{
				return (figure_2d::center.get_y() - r);
			}

			inline space_type max_y() const
			{
				return (figure_2d::center.get_y() + r);
			}

			virtual bool has_vertices() const;

			virtual length get_perimeter() const;
			virtual area get_area() const;
			virtual bool is_inside(const point_2d&) const;

			virtual void rotate(angle_type);
			virtual void rotate(const msci::angle_number&);

			virtual void scale(space_type);
			//virtual void scale(const msci::percentage_number&) = 0;

			virtual string display() const;

		private:
			space_type r;
	};
}

bool operator ==(const msci::circle&,const msci::circle&);
bool operator !=(const msci::circle&,const msci::circle&);

#endif // MATH_TOPOLOGY_FIGURE_2D_CIRCLE_HPP_INCLUDED
