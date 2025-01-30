#include "./conversion.hpp"

using namespace std;

namespace scifir
{
	conversion::conversion() : conversion_type(conversion::NONE)
	{}

	conversion::conversion(const conversion::type new_conversion_type) : conversion_type(new_conversion_type)
	{}

	long double conversion::get_conversion_factor() const
	{
		switch(conversion_type)
		{
			case conversion::NONE:
				return 0.0L;
			case conversion::HECTARE:
				return 1.0L;
			case conversion::DYNE:
				return 0.0L;
			case conversion::BARYE:
				return 0.0L;
			case conversion::BAR:
				return 0.0L;
			case conversion::ATMOSPHERE:
				return 0.0L;
			case conversion::MILIMETRES_MERCURY:
				return 0.0L;
			case conversion::TORRICELLI:
				return 0.0L;
			case conversion::CUBIC_CENTIMETRES:
				return 0.0L;
			case conversion::FAHRENHEIT:
				return 0.0L;
			case conversion::HORSEPOWER:
				return 0.0L;
			case conversion::WATT_HOUR:
				return 0.0L;
			case conversion::KILOWATT_HOUR:
				return 0.0L;
			case conversion::IMPERIAL_TWIP:
				return 0.0L;
			case conversion::IMPERIAL_THOU:
				return 0.0L;
			case conversion::IMPERIAL_BARLEYCORN:
				return 0.0L;
			case conversion::IMPERIAL_INCH:
				return 0.0L;
			case conversion::IMPERIAL_HAND:
				return 0.0L;
			case conversion::IMPERIAL_FOOT:
				return 0.0L;
			case conversion::IMPERIAL_YARD:
				return 0.0L;
			case conversion::IMPERIAL_CHAIN:
				return 0.0L;
			case conversion::IMPERIAL_FURLONG:
				return 0.0L;
			case conversion::IMPERIAL_MILE:
				return 0.0L;
			case conversion::IMPERIAL_LEAGUE:
				return 0.0L;
			case conversion::IMPERIAL_FATHOM:
				return 0.0L;
			case conversion::IMPERIAL_CABLE:
				return 0.0L;
			case conversion::IMPERIAL_NAUTICAL_MILE:
				return 0.0L;
			case conversion::IMPERIAL_LINK:
				return 0.0L;
			case conversion::IMPERIAL_ROD:
				return 0.0L;
			case conversion::IMPERIAL_PERCH:
				return 0.0L;
			case conversion::IMPERIAL_ROOD:
				return 0.0L;
			case conversion::IMPERIAL_ACRE:
				return 0.0L;
			case conversion::IMPERIAL_SQUARE_MILE:
				return 0.0L;
			case conversion::IMPERIAL_FLUID_OUNCE:
				return 0.0L;
			case conversion::IMPERIAL_GILL:
				return 0.0L;
			case conversion::IMPERIAL_PINT:
				return 0.0L;
			case conversion::IMPERIAL_QUART:
				return 0.0L;
			case conversion::IMPERIAL_GALLON:
				return 0.0L;
			case conversion::IMPERIAL_MINIM:
				return 0.0L;
			case conversion::IMPERIAL_FLUID_SCRUPLE:
				return 0.0L;
			case conversion::IMPERIAL_FLUID_DRACHM:
				return 0.0L;
			case conversion::IMPERIAL_GRAIN:
				return 0.0L;
			case conversion::IMPERIAL_DRACHM:
				return 0.0L;
			case conversion::IMPERIAL_OUNCE:
				return 0.0L;
			case conversion::IMPERIAL_POUND:
				return 0.0L;
			case conversion::IMPERIAL_STONE:
				return 0.0L;
			case conversion::IMPERIAL_QUARTER:
				return 0.0L;
			case conversion::IMPERIAL_HUNDREDWEIGHT:
				return 0.0L;
			case conversion::IMPERIAL_TON:
				return 0.0L;
			case conversion::IMPERIAL_SLUG:
				return 0.0L;
			case conversion::US_TWIP:
				return 0.0L;
			case conversion::US_MIL:
				return 0.0L;
			case conversion::US_POINT:
				return 0.0L;
			case conversion::US_PICA:
				return 0.0L;
			case conversion::US_INCH:
				return 0.0L;
			case conversion::US_FOOT:
				return 0.0L;
			case conversion::US_YARD:
				return 0.0L;
			case conversion::US_MILE:
				return 0.0L;
			case conversion::US_LEAGUE:
				return 0.0L;
			case conversion::US_FATHOM:
				return 0.0L;
			case conversion::US_CABLE:
				return 0.0L;
			case conversion::US_NAUTICAL_MILE:
				return 0.0L;
			case conversion::US_LINK:
				return 0.0L;
			case conversion::US_ROD:
				return 0.0L;
			case conversion::US_CHAIN:
				return 0.0L;
			case conversion::US_FURLONG:
				return 0.0L;
			case conversion::US_SQUARE_FOOT:
				return 0.0L;
			case conversion::US_SQUARE_CHAIN:
				return 0.0L;
			case conversion::US_ACRE:
				return 0.0L;
			case conversion::US_SECTION:
				return 0.0L;
			case conversion::US_SURVEY_TOWNSHIP:
				return 0.0L;
			case conversion::US_CUBIC_INCH:
				return 0.0L;
			case conversion::US_CUBIC_FOOT:
				return 0.0L;
			case conversion::US_CUBIC_YARD:
				return 0.0L;
			case conversion::US_ACRE_FOOT:
				return 0.0L;
			case conversion::US_MINIM:
				return 0.0L;
			case conversion::US_FLUID_DRAM:
				return 0.0L;
			case conversion::US_TEASPOON:
				return 0.0L;
			case conversion::US_TABLESPOON:
				return 0.0L;
			case conversion::US_FLUID_OUNCE:
				return 0.0L;
			case conversion::US_SHOT:
				return 0.0L;
			case conversion::US_GILL:
				return 0.0L;
			case conversion::US_CUP:
				return 0.0L;
			case conversion::US_PINT:
				return 0.0L;
			case conversion::US_QUART:
				return 0.0L;
			case conversion::US_POTTLE:
				return 0.0L;
			case conversion::US_GALLON:
				return 0.0L;
			case conversion::US_BARREL:
				return 0.0L;
			case conversion::US_OIL_BARREL:
				return 0.0L;
			case conversion::US_HOGSHEAD:
				return 0.0L;
			case conversion::US_PECK:
				return 0.0L;
			case conversion::US_BUSHEL:
				return 0.0L;
			case conversion::US_GRAIN:
				return 0.0L;
			case conversion::US_DRAM:
				return 0.0L;
			case conversion::US_OUNCE:
				return 0.0L;
			case conversion::US_POUND:
				return 0.0L;
			case conversion::US_SHORT_HUNDREDWEIGHT:
				return 0.0L;
			case conversion::US_LONG_HUNDREDWEIGHT:
				return 0.0L;
			case conversion::US_SHORT_TON:
				return 0.0L;
			case conversion::US_LONG_TON:
				return 0.0L;
			case conversion::US_PENNYWEIGHT:
				return 0.0L;
			case conversion::US_TROY_OUNCE:
				return 0.0L;
			case conversion::US_TROY_POUND:
				return 0.0L;
			case conversion::US_DESSERTSPOON:
				return 0.0L;
			case conversion::US_HAND:
				return 0.0L;
			case conversion::US_RACK:
				return 0.0L;
			case conversion::US_BOARD_FOOT:
				return 0.0L;
			case conversion::US_SLUG:
				return 0.0L;
			case conversion::US_POUNDAL:
				return 0.0L;
			case conversion::US_KIP:
				return 0.0L;
			case conversion::US_FOOT_POUND:
				return 0.0L;
			case conversion::US_HORSEPOWER:
				return 0.0L;
			case conversion::US_REFRIGERATION_TON:
				return 0.0L;
			case conversion::US_INCH_MERCURY:
				return 0.0L;
			case conversion::US_POUND_PER_SQUARE_INCH:
				return 0.0L;
			case conversion::US_POUND_FOOT:
				return 0.0L;
			case conversion::US_STONE:
				return 0.0L;
			case conversion::QUINTAL:
				return 0.0L;
			case conversion::CARAT:
				return 0.0L;
			case conversion::QUAD:
				return 0.0L;
			case conversion::BRITISH_THERMAL_UNIT:
				return 0.0L;
			case conversion::CUSTOM:
				return 0.0L;
		};
		return 0.0L;
	}

	vector<dimension> conversion::get_conversion_dimensions() const
	{
		vector<dimension> conversion_dimensions = vector<dimension>();
		switch(conversion_type)
		{
			case conversion::NONE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::HECTARE:
				conversion_dimensions.push_back(dimension(dimension::METRE,prefix::HECTO,dimension::NUMERATOR));
				conversion_dimensions.push_back(dimension(dimension::METRE,prefix::HECTO,dimension::NUMERATOR));
				break;
			case conversion::DYNE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::BARYE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::BAR:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::ATMOSPHERE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::MILIMETRES_MERCURY:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::TORRICELLI:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::CUBIC_CENTIMETRES:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::FAHRENHEIT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::HORSEPOWER:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::WATT_HOUR:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::KILOWATT_HOUR:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_TWIP:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_THOU:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_BARLEYCORN:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_INCH:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_HAND:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_FOOT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_YARD:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_CHAIN:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_FURLONG:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_MILE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_LEAGUE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_FATHOM:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_CABLE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_NAUTICAL_MILE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_LINK:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_ROD:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_PERCH:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_ROOD:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_ACRE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_SQUARE_MILE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_FLUID_OUNCE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_GILL:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_PINT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_QUART:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_GALLON:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_MINIM:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_FLUID_SCRUPLE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_FLUID_DRACHM:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_GRAIN:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_DRACHM:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_OUNCE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_POUND:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_STONE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_QUARTER:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_HUNDREDWEIGHT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_TON:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::IMPERIAL_SLUG:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_TWIP:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_MIL:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_POINT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_PICA:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_INCH:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_FOOT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_YARD:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_MILE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_LEAGUE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_FATHOM:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_CABLE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_NAUTICAL_MILE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_LINK:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_ROD:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_CHAIN:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_FURLONG:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_SQUARE_FOOT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_SQUARE_CHAIN:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_ACRE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_SECTION:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_SURVEY_TOWNSHIP:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_CUBIC_INCH:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_CUBIC_FOOT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_CUBIC_YARD:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_ACRE_FOOT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_MINIM:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_FLUID_DRAM:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_TEASPOON:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_TABLESPOON:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_FLUID_OUNCE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_SHOT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_GILL:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_CUP:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_PINT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_QUART:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_POTTLE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_GALLON:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_BARREL:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_OIL_BARREL:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_HOGSHEAD:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_PECK:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_BUSHEL:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_GRAIN:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_DRAM:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_OUNCE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_POUND:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_SHORT_HUNDREDWEIGHT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_LONG_HUNDREDWEIGHT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_SHORT_TON:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_LONG_TON:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_PENNYWEIGHT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_TROY_OUNCE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_TROY_POUND:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_DESSERTSPOON:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_HAND:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_RACK:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_BOARD_FOOT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_SLUG:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_POUNDAL:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_KIP:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_FOOT_POUND:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_HORSEPOWER:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_REFRIGERATION_TON:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_INCH_MERCURY:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_POUND_PER_SQUARE_INCH:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_POUND_FOOT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::US_STONE:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::QUINTAL:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::CARAT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::QUAD:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::BRITISH_THERMAL_UNIT:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
			case conversion::CUSTOM:
				conversion_dimensions.push_back(dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR));
				break;
		};
		return conversion_dimensions;
	}
}
