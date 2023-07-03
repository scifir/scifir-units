#include "predefined_units/space_units.hpp"

#include "units/unit_basic.hpp"
#include "special_units/size_2d.hpp"
#include "special_units/size_3d.hpp"

using namespace std;

namespace msci
{
	SCALAR_UNIT_CPP(area,"m2");

	area::area(const size_2d<length>& x) : scalar_unit()
	{
		length x_height = x.height;
		x_height.change_dimensions(x.width);
		*this = x.width * x_height;
	}

	SCALAR_UNIT_CPP(volume,"m3");

	volume::volume(const size_3d<length>& x) : scalar_unit()
	{
		length x_height = x.height;
		length x_depth = x.depth;
		x_height.change_dimensions(x.width);
		x_depth.change_dimensions(x.width);
		*this = x.width * x_height * x_depth;
	}

	SCALAR_UNIT_CPP(curvature,"1/m");
}
