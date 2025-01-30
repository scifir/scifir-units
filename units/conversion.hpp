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
			enum type { NONE, HECTARE, DYNE, BARYE, BAR, ATMOSPHERE, MILIMETRES_MERCURY, TORRICELLI, CUBIC_CENTIMETRES, FAHRENHEIT, HORSEPOWER, WATT_HOUR, KILOWATT_HOUR,
			
			/* Imperial units */
			IMPERIAL_TWIP, IMPERIAL_THOU, IMPERIAL_BARLEYCORN, IMPERIAL_INCH, IMPERIAL_HAND, IMPERIAL_FOOT, IMPERIAL_YARD, IMPERIAL_CHAIN, IMPERIAL_FURLONG, IMPERIAL_MILE, IMPERIAL_LEAGUE, IMPERIAL_FATHOM, IMPERIAL_CABLE, IMPERIAL_NAUTICAL_MILE, IMPERIAL_LINK, IMPERIAL_ROD, IMPERIAL_PERCH, IMPERIAL_ROOD, IMPERIAL_ACRE, IMPERIAL_SQUARE_MILE, IMPERIAL_FLUID_OUNCE, IMPERIAL_GILL, IMPERIAL_PINT, IMPERIAL_QUART, IMPERIAL_GALLON, IMPERIAL_MINIM, IMPERIAL_FLUID_SCRUPLE, IMPERIAL_FLUID_DRACHM, IMPERIAL_FLUID_OUNCE, IMPERIAL_GRAIN, IMPERIAL_DRACHM, IMPERIAL_OUNCE, IMPERIAL_POUND, IMPERIAL_STONE, IMPERIAL_QUARTER, IMPERIAL_HUNDREDWEIGHT, IMPERIAL_TON, IMPERIAL_SLUG,
			
			/* US customary units of measurement */
			US_CUP, US_TABLESPOON, US_TEASPOON, US_BARREL, US_GILL, US_OUNCE, US_POUND, US_TON, US_STONE, US_SHOT, US_GALLON, US_FLUID_OUNCE, US_QUART, US_PINT,
			
			QUINTAL, CARAT, GRAIN, POUND_FORCE, TON_FORCE, FOOT_POUND_FORCE, BRITISH_THERMAL_UNIT, POUND_FORCE_PER_SQUARE_INCH, 
			CUSTOM };

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
