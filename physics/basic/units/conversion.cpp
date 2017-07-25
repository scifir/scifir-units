#include "conversion.hpp"
#include "dimension.hpp"

#include <string>

using namespace std;

namespace physics::units
{
	conversion::conversion() : factor(0),unit_to("")
	{
	}

	conversion::conversion(string new_unit_to, float new_factor)
	{
		unit_to = new_unit_to;
		factor = new_factor;
	}

	map<string, conversion> get_conversion
	{
		// Common units
		{"ha", conversion("hm2", 1)}, // Hectare
		{"ly", conversion("AU", 63241)}, // Light-year
		{"dyn", conversion("N", 0.00001)}, // Dyne
		{"Ba", conversion("Pa", 0.1)}, // Barye
		{"bar", conversion("Pa", 100000)}, // Bar
		{"atm", conversion("Pa", 101325)}, // Atmosphere
		{"mmHg", conversion("Pa", 133.322387415)}, // mmHg
		{"Torr", conversion("Pa", 101325 / 760)}, // Torricelli
		// England units
		{"in", conversion("mm", 25.4)},
		{"inch", conversion("mm", 25.4)},
		{"ft", conversion("m", 0.3048)},
		{"foot", conversion("m", 0.3048)},
		{"yd", conversion("m", 0.9144)},
		{"yard", conversion("m", 0.9144)},
		{"mi", conversion("km", 1.609)},
		{"mile", conversion("km", 1.609)},
		{"acre", conversion("hm2", 0.4047)},
		//{"qt",conversion("asdf",1234)},
		//{"quart",conversion("asdf",1234)},
		{"gal", conversion("L", 3.785)},
		{"gallon", conversion("L", 3.785)},
		{"oz", conversion("g", 28.35)},
		{"ounce", conversion("g", 28.35)},
		{"lb", conversion("kg", 0.4536)},
		{"pound", conversion("kg", 0.4536)},
		{"t", conversion("kg", 1000)},
		{"ton", conversion("kg", 1000)},
		{"ltn", conversion("kg", 1016)},
		{"lbf", conversion("N", 4.448)},
		{"tnf", conversion("kN", 8.896)},
		{"psi", conversion("Pa", 6894.76)},
		{"Btu", conversion("J", 1055)},
		{"ft-lbf", conversion("J", 1356)},
		{"Wh", conversion("J", 3600)},
		{"kWh", conversion("J", 3600000)},
		{"HP", conversion("kW", 0.7355)},
		{"hp", conversion("kW", 0.7457)},
		{"°C", conversion("K", 1)},
		{"°F", conversion("K", 5 / 9)},
		{"bit", conversion("B", 1 / 8)},
		{"kbit", conversion("B", 125)},
		{"Mbit", conversion("kB", 125)},
		{"Gbit", conversion("MB", 125)},
		{"Tbit", conversion("GB", 125)},
		{"Pbit", conversion("TB", 125)},
		{"Ebit", conversion("PB", 125)},
		{"Zbit", conversion("EB", 125)},
		{"Ybit", conversion("ZB", 125)},
	};
}
