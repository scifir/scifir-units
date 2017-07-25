#ifndef CONVERSION_HPP_INCLUDED
#define CONVERSION_HPP_INCLUDED

#include "dimension.hpp"

#include <string>

using namespace std;

namespace physics::units
{
	class conversion
	{
		public:
			float factor;
			string unit_to;

			conversion();
			conversion(string, float);
	};

	extern map<string, conversion> get_conversion;
}

#endif // CONVERSION_HPP_INCLUDED
