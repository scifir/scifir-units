#include "./size_nd.hpp"

using namespace std;

namespace scifir
{
	string to_string(const size_nd<float>& x)
	{
		ostringstream output;
		output << x.widths[0];
		for (unsigned int i = 1; i < x.widths.size(); i++)
		{
			output << " * " << x.widths[i];
		}
		return output.str();
	}
}
