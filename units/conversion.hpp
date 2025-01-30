#ifndef SCIFIR_UNITS_UNITS_CONVERSION_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_CONVERSION_HPP_INCLUDED

#include "./dimension.hpp"

#include <string>

using namespace std;

namespace scifir
{
	class conversion
	{
		public:
			enum type { NONE, HECTARE, DYNE, BARYE, BAR, ATMOSPHERE, MILIMETRES_MERCURY, TORRICELLI, CUBIC_CENTIMETRES, FAHRENHEIT, HORSEPOWER, WATT_HOUR, KILOWATT_HOUR, INCH, FOOT, YARD, MILE, ACRE, IMPERIAL_GALLON, IMPERIAL_FLUID_OUNCE, IMPERIAL_QUART, IMPERIAL_PINT, IMPERIAL_OUNCE, IMPERIAL_POUND, US_CUP, US_TABLESPOON, US_TEASPOON, US_BARREL, US_GILL, US_OUNCE, US_POUND, US_TON, US_STONE, SHOT, QUINTAL, CARAT, GRAIN, POUND_FORCE, TON_FORCE, FOOT_POUND_FORCE, BRITISH_THERMAL_UNIT, POUND_FORCE_PER_SQUARE_INCH, US_GALLON, US_FLUID_OUNCE, US_QUART, US_PINT, CUSTOM };

			conversion();
			explicit conversion(const string& new_unit_to, float new_factor);
			explicit conversion(const string& new_unit_to, double new_factor);
			explicit conversion(const string& new_unit_to, long double new_factor);

			inline const long double& get_factor() const
			{
				return factor;
			}

			inline const string& get_unit_to() const
			{
				return unit_to;
			}

		private:
			string unit_to;
			long double factor;
	};

	extern map<string, conversion> get_conversion;
}

#endif // SCIFIR_UNITS_UNITS_CONVERSION_HPP_INCLUDED
