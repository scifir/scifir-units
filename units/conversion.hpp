#ifndef MSCI_UNITS_UNITS_CONVERSION_HPP_INCLUDED
#define MSCI_UNITS_UNITS_CONVERSION_HPP_INCLUDED

#include "units/dimension.hpp"

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

#endif // MSCI_UNITS_UNITS_CONVERSION_HPP_INCLUDED
