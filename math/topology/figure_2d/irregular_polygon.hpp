#ifndef MATH_TOPOLOGY_FIGURE_2D_IRREGULAR_POLYGON_HPP_INCLUDED
#define MATH_TOPOLOGY_FIGURE_2D_IRREGULAR_POLYGON_HPP_INCLUDED

#include "polygon.hpp"

using namespace std;

namespace msci
{
	class irregular_polygon : public polygon
	{
		public:
			irregular_polygon();
			explicit irregular_polygon(const vector<point_2d>&,const vector<polygon>&);

			virtual bool is_regular() const;
			virtual bool is_irregular() const;

		private:
			vector<polygon> inner_polygons;
	};
}

#endif // MATH_TOPOLOGY_FIGURE_2D_IRREGULAR_POLYGON_HPP_INCLUDED
