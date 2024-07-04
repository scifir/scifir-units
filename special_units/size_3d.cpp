#include "./size_3d.hpp"

using namespace std;

namespace scifir
{
	string to_string(const size_3d<float>& x)
	{
		return x.display();
	}
}
