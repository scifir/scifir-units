#include "./size_nd.hpp"

using namespace std;

namespace scifir
{
	string to_string(const size_nd<float>& x)
	{
		return x.display();
	}
}
