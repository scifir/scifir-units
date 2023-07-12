#include "size_3d.hpp"

using namespace std;

namespace scifir
{
	string to_string(const size_3d<float>& x)
	{
		ostringstream output;
		output << x.width << " * " << x.height << " * " << x.depth;
		return output.str();
	}
}
