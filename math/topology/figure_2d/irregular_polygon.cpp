#include "irregular_polygon.hpp"

using namespace std;

namespace math
{
	irregular_polygon::irregular_polygon() : polygon(),inner_polygons()
	{
	}

	irregular_polygon::irregular_polygon(const vector<point_2d>& new_vertices,const vector<polygon>& new_inner_polygons) : polygon(new_vertices),inner_polygons(new_inner_polygons)
	{
	}

	bool irregular_polygon::is_regular() const
	{
		return (inner_polygons.size() == 0);
	}

	bool irregular_polygon::is_irregular() const
	{
		return (inner_polygons.size() > 0);
	}
}
