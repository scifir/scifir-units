#include "./conversion.hpp"
#include "./dimension.hpp"

#include <string>

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
				return 0.0L;
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

	/*map<string, conversion> get_conversion
	{
		// Common units
		{"ha", conversion("hm2", 1.0L)}, // Hectare
		{"dyn", conversion("N", 0.00001L)}, // Dyne
		{"Ba", conversion("Pa", 0.1L)}, // Barye
		{"bar", conversion("Pa", 100000.0L)}, // Bar
		{"atm", conversion("Pa", 101325.0L)}, // Atmosphere
		{"mmHg", conversion("Pa", 133.322387415L)}, // mmHg
		{"Torr", conversion("Pa", 101325.0L / 760.0L)}, // Torricelli
		// England units
		{"in", conversion("mm", 25.4L)},
		{"inch", conversion("mm", 25.4L)},
		{"ft", conversion("m", 0.3048L)},
		{"foot", conversion("m", 0.3048L)},
		{"yd", conversion("m", 0.9144L)},
		{"yard", conversion("m", 0.9144L)},
		{"mi", conversion("km", 1.609L)},
		{"mile", conversion("km", 1.609L)},
		{"acre", conversion("hm2", 0.4047L)},
		{"gal(us)", conversion("", 3.785L)},
		{"gallon(us)", conversion("", 3.785L)},
		{"fluid_ounce(us)", conversion("m", 29.5735295641119L)},
		{"quart(us)", conversion("", 0.94635294605158L)},
		{"pint(us)", conversion("", 0.47317647302579L)},
		{"gal(imperial)", conversion("", 4.54609000011111L)},
		{"gallon(imperial)", conversion("", 4.54609000011111L)},
		{"fluid_ounce(imperial)", conversion("m", 28.4130625006944L)},
		{"quart(imperial)", conversion("", 1.13652250002778L)},
		{"pint(imperial)", conversion("", 0.568261250013888L)},
		{"cup(us)", conversion("m", 236.588236512895L)},
		{"tablespoon(us)", conversion("m", 14.7867647820559L)},
		{"teaspoon(us)", conversion("m", 4.92892159401865L)},
		{"cup(imperial)", conversion("m", 284.130625014338L)},
		{"tablespoon(imperial)", conversion("m", 17.7581640707895L)},
		{"teaspoon(imperial)", conversion("m", 5.91938802359649L)},
		{"cup", conversion("m", 250.0L)},
		{"tablespoon", conversion("m", 15.0000000147868L)},
		{"teaspoon", conversion("m", 5.00000000027252L)},
		{"barrel(us)", conversion("", 119.240471202499L)},
		{"barrel(imperial)", conversion("", 163.659240008909L)},
		{"barrel(us_fed)", conversion("", 117.347765310396L)},
		{"gill(us)", conversion("m", 118.294118256447L)},
		{"gill(imperial)", conversion("m", 142.065312507169L)},
		{"shot", conversion("m", 44.3602943461678L)},
		{"oz", conversion("g", 28.35L)},
		{"ounce", conversion("g", 28.35L)},
		{"lb", conversion("kg", 0.4536L)},
		{"pound", conversion("kg", 0.4536L)},
		{"quarter(us)",conversion("kg",11.3398092595095L)},
		{"quarter(imperial)",conversion("kg",12.7005863706506L)},
		{"ton", conversion("kg", 1000.0L)},
		{"ton(us)", conversion("kg", 907.184740760757L)},
		{"ton(imperial)", conversion("kg", 1016.04690965205L)},
		{"stone(us)", conversion("kg", 5.66990462975473L)},
		{"stone(imperial)", conversion("kg", 6.3502931853253L)},
		{"quintal", conversion("kg", 100.000000083915L)},
		{"carat", conversion("g", 0.2L)},
		{"grain", conversion("g", 0.0647989100543398L)},
		{"lbf", conversion("N", 4.448L)},
		{"pound_force", conversion("N", 4.448L)},
		{"tnf", conversion("kN", 8.896L)},
		{"ton_force", conversion("kN", 8.896L)},
		{"psi", conversion("Pa", 6894.76L)},
		{"Btu", conversion("J", 1055.0L)},
		{"ft-lbf", conversion("J", 1356.0L)},
		{"foot_pound_force", conversion("J", 1356.0L)},
		{"Wh", conversion("J", 3600.0L)},
		{"kWh", conversion("J", 3600000.0L)},
		{"HP", conversion("kW", 0.7355L)},
		{"hp", conversion("kW", 0.7457L)},
		{"�F", conversion("K", 5.0L / 9.0L)},
		{"cc", conversion("mL", 1.0L)}
	};*/
}
