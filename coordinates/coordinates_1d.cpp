#include "./coordinates_1d.hpp"
#include "../util/types.hpp"

using namespace std;

namespace scifir
{
	string to_string(const coordinates_1d<float>& x)
	{
		return x.display_cartesian();
	}

	float distance(const coordinates_1d<float>& x,const coordinates_1d<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2)));
	}
}

ostream& operator <<(ostream& os,const scifir::coordinates_1d<float>& x)
{
	return os << scifir::to_string(x);
}