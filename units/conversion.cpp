#include "./conversion.hpp"
#include "./dimension.hpp"

#include <string>

using namespace std;

namespace scifir
{
	conversion::conversion() : unit_to(),factor()
	{}

	conversion::conversion(const string& new_unit_to, float new_factor) : unit_to(new_unit_to),factor((long double)new_factor)
	{}

	conversion::conversion(const string& new_unit_to, double new_factor) : unit_to(new_unit_to),factor((long double)new_factor)
	{}

	conversion::conversion(const string& new_unit_to, long double new_factor) : unit_to(new_unit_to),factor(new_factor)
	{}

	map<string, conversion> get_conversion
	{
		// Common units
		{"ha", conversion("hm2", 1.0L)}, // Hectare
		{"ly", conversion("AU", 63241.0L)}, // Light-year
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
		{"�C", conversion("K", 1.0L)},
		{"�F", conversion("K", 5.0L / 9.0L)},
		{"bit", conversion("B", 1.0L / 8.0L)},
		{"kbit", conversion("B", 125.0L)},
		{"Mbit", conversion("kB", 125.0L)},
		{"Gbit", conversion("MB", 125.0L)},
		{"Tbit", conversion("GB", 125.0L)},
		{"Pbit", conversion("TB", 125.0L)},
		{"Ebit", conversion("PB", 125.0L)},
		{"Zbit", conversion("EB", 125.0L)},
		{"Ybit", conversion("ZB", 125.0L)},
		{"cc", conversion("mL", 1.0L)}
	};
}
