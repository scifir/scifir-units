#include "units.hpp"

#include <string>

using namespace std;

namespace physics::units
{
	const string density::dimensions_match = "g/m3";
	const string viscosity::dimensions_match = "m2/s";
	const string specific_volume::dimensions_match = "m3/g";
	const string specific_heat_capacity::dimensions_match = "m2/s2*K";
	const string specific_entropy::dimensions_match = "m2/s2*K";
	const string specific_energy::dimensions_match = "m2/s2";
	const string molar_volume::dimensions_match = "m3/mol";
	const string molar_mass::dimensions_match = "g/mol";
	const string molar_heat_capacity::dimensions_match = "m2*g/s2*K*mol";
	const string molar_entropy::dimensions_match = "m2*g/s2*K*mol";
	const string molar_energy::dimensions_match = "m2*g/s2*mol";
	const string molar_conductivity::dimensions_match = "s3*A2/g*mol";
	const string energy_density::dimensions_match = "g/m*s2";
}
