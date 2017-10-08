#ifndef CONVERSION_HPP_INCLUDED
#define CONVERSION_HPP_INCLUDED

#include "dimension.hpp"

#include <string>

using namespace std;

namespace msci::units
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
			float factor;
			string unit_to;
	};

	extern map<string, conversion> get_conversion;
}

#endif // CONVERSION_HPP_INCLUDED
