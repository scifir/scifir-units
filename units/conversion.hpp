#ifndef SCIFIR_UNITS_UNITS_CONVERSION_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_CONVERSION_HPP_INCLUDED

#include "../units/dimension.hpp"

#include <string>

using namespace std;

namespace scifir
{
	class conversion
	{
		public:
			conversion();
			explicit conversion(const string&, float);

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

#endif // SCIFIR_UNITS_UNITS_CONVERSION_HPP_INCLUDED
