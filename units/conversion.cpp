#include "units/conversion.hpp"
#include "units/dimension.hpp"

#include <string>

using namespace std;

namespace scifir
{
	conversion::conversion() : unit_to(),factor()
	{
	}

	conversion::conversion(const string& new_unit_to, float new_factor) : unit_to(new_unit_to),factor(new_factor)
	{
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
		{"gal(us)", conversion("", 3.785)},
		{"gallon(us)", conversion("", 3.785)},
		{"fluid_ounce(us)", conversion("m", 29.5735295641119)},
		{"quart(us)", conversion("", 0.94635294605158)},
		{"pint(us)", conversion("", 0.47317647302579)},
		{"gal(imperial)", conversion("", 4.54609000011111)},
		{"gallon(imperial)", conversion("", 4.54609000011111)},
		{"fluid_ounce(imperial)", conversion("m", 28.4130625006944)},
		{"quart(imperial)", conversion("", 1.13652250002778)},
		{"pint(imperial)", conversion("", 0.568261250013888)},
		{"cup(us)", conversion("m", 236.588236512895)},
		{"tablespoon(us)", conversion("m", 14.7867647820559)},
		{"teaspoon(us)", conversion("m", 4.92892159401865)},
		{"cup(imperial)", conversion("m", 284.130625014338)},
		{"tablespoon(imperial)", conversion("m", 17.7581640707895)},
		{"teaspoon(imperial)", conversion("m", 5.91938802359649)},
		{"cup", conversion("m", 250)},
		{"tablespoon", conversion("m", 15.0000000147868)},
		{"teaspoon", conversion("m", 5.00000000027252)},
		{"barrel(us)", conversion("", 119.240471202499)},
		{"barrel(imperial)", conversion("", 163.659240008909)},
		{"barrel(us_fed)", conversion("", 117.347765310396)},
		{"gill(us)", conversion("m", 118.294118256447)},
		{"gill(imperial)", conversion("m", 142.065312507169)},
		{"shot", conversion("m", 44.3602943461678)},
		{"oz", conversion("g", 28.35)},
		{"ounce", conversion("g", 28.35)},
		{"lb", conversion("kg", 0.4536)},
		{"pound", conversion("kg", 0.4536)},
		{"quarter(us)",conversion("kg",11.3398092595095)},
		{"quarter(imperial)",conversion("kg",12.7005863706506)},
		{"ton", conversion("kg", 1000)},
		{"ton(us)", conversion("kg", 907.184740760757)},
		{"ton(imperial)", conversion("kg", 1016.04690965205)},
		{"stone(us)", conversion("kg", 5.66990462975473)},
		{"stone(imperial)", conversion("kg", 6.3502931853253)},
		{"quintal", conversion("kg", 100.000000083915)},
		{"carat", conversion("g", 0.2)},
		{"grain", conversion("g", 0.0647989100543398)},
		{"lbf", conversion("N", 4.448)},
		{"pound_force", conversion("N", 4.448)},
		{"tnf", conversion("kN", 8.896)},
		{"ton_force", conversion("kN", 8.896)},
		{"psi", conversion("Pa", 6894.76)},
		{"Btu", conversion("J", 1055)},
		{"ft-lbf", conversion("J", 1356)},
		{"foot_pound_force", conversion("J", 1356)},
		{"Wh", conversion("J", 3600)},
		{"kWh", conversion("J", 3600000)},
		{"HP", conversion("kW", 0.7355)},
		{"hp", conversion("kW", 0.7457)},
		{"�C", conversion("K", 1)},
		{"�F", conversion("K", 5 / 9)},
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
