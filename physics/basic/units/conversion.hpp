#ifndef CONVERSION_HPP_INCLUDED
#define CONVERSION_HPP_INCLUDED

#include "dimension.hpp"

#include <string>

using namespace std;

namespace msci
{
	class conversion
	{
		public:
			conversion();
			conversion(const string&, float);

			inline const float& get_factor() const
			{
				return factor;
			}

			inline const string& get_unit_to() const
			{
				return unit_to;
			}

		private:
			string unit_to;
			float factor;
	};

	extern map<string, conversion> get_conversion;
}

#endif // CONVERSION_HPP_INCLUDED
