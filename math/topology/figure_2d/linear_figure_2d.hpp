#ifndef LINEAR_FIGURE_2D_HPP_INCLUDED
#define LINEAR_FIGURE_2D_HPP_INCLUDED

#include "units.hpp"

#include "math/topology/point_2d.hpp"
#include "math/topology/line_2d.hpp"

#include "figure_2d.hpp"

#include <vector>

using namespace std;
using namespace msci::units;

namespace msci
{
	class linear_figure_2d : public figure_2d
	{
		public:
			linear_figure_2d();
			explicit linear_figure_2d(const point_2d&);
			explicit linear_figure_2d(const vector<point_2d>&);

			inline vector<point_2d>& get_vertices()
			{
				return vertices;
			}

			inline const vector<point_2d>& get_vertices() const
			{
				return vertices;
			}

			inline vector<line_2d>& get_edges()
			{
				return edges;
			}

			inline const vector<line_2d>& get_edges() const
			{
				return edges;
			}

			inline point_2d& operator [](unsigned int i)
			{
				return vertices[i];
			}

			inline const point_2d& operator [](unsigned int i) const
			{
				return vertices[i];
			}

			virtual bool has_vertices() const;

			virtual length get_perimeter() const;

			virtual void translate_x(space_type);
			virtual void translate_y(space_type);

			virtual void rotate(angle_type);
			virtual void rotate(const msci::angle_number&);

			virtual void scale(space_type);
			//virtual void scale(const msci::percentage_number&);

		protected:
			vector<point_2d> vertices;
			vector<line_2d> edges;

			vector<line_2d> create_edges();
	};
}

bool operator ==(const msci::linear_figure_2d&,const msci::linear_figure_2d&);
bool operator !=(const msci::linear_figure_2d&,const msci::linear_figure_2d&);

#endif // LINEAR_FIGURE_2D_HPP_INCLUDED
