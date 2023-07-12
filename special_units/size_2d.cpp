#include "size_2d.hpp"

using namespace std;

namespace scifir
{
	string to_string(const size_2d<float>& x)
	{
		ostringstream output;
		output << x.width << " * " << x.height;
		return output.str();
	}
}
