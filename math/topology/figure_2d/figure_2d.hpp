#ifndef MATH_TOPOLOGY_FIGURE_2D_HPP_INCLUDED
#define MATH_TOPOLOGY_FIGURE_2D_HPP_INCLUDED

#include "units.hpp"

#include "math/topology/point_2d.hpp"
#include "math/topology/line_2d.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace msci::units;

namespace msci
{
	class figure_2d
	{
		public:
			figure_2d();
			explicit figure_2d(const point_2d&);

			inline const point_2d& get_center() const
			{
				return center;
			}

			virtual bool has_vertices() const = 0;

			virtual length get_perimeter() const = 0;
			virtual area get_area() const = 0;
			virtual bool is_inside(const point_2d&) const = 0;
			bool is_partially_inside(const figure_2d&) const;
			bool is_totally_inside(const figure_2d&) const;

			inline bool is_outside(const point_2d& x) const
			{
				return !is_inside(x);
			}

			inline bool is_outside(const figure_2d& x) const
			{
				return !is_partially_inside(x);
			}

			inline void translate(space_type x_translation,space_type y_translation)
			{
				translate_x(x_translation);
				translate_y(y_translation);
			}

			inline void translate(const point_2d& x1)
			{
				translate(x1.get_x(),x1.get_y());
			}

			virtual void translate_x(space_type);
			virtual void translate_y(space_type);

			virtual void rotate(angle_type) = 0;
			virtual void rotate(const msci::angle_number&) = 0;

			virtual void scale(space_type) = 0;
			//virtual void scale(const msci::percentage_number&) = 0;

			virtual wstring display() const = 0;
			void print() const;

		protected:
			point_2d center;
	};
}

wostream& operator <<(wostream&,const msci::figure_2d&);

#endif // MATH_TOPOLOGY_FIGURE_2D_HPP_INCLUDED
