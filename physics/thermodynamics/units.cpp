#include "units.hpp"

using namespace std;

namespace physics::units
{
	const string energy::dimensions_match = "kg*m2/s2";
	const string action::dimensions_match = "kg*m2/s";
	const string power::dimensions_match = "kg*m2/s3";
	const string power_density::dimensions_match = "kg/m*s3";
	const string enthalpy::dimensions_match = "kg*m2/s2";
	const string entropy::dimensions_match = "kg*m2/K*s2";
	const string heat_capacity::dimensions_match = "kg*m2/K*s2";
	const string heat_flux_density::dimensions_match = "kg/s3";
	const string thermal_conductivity::dimensions_match = "kg*m/K*s3";
	const string thermal_diffusivity::dimensions_match = "m2/s";
	const string thermal_resistance::dimensions_match = "K*s3/kg*m2";
	const string thermal_expansion_coefficient::dimensions_match = "1/K";
	const string temperature_gradient::dimensions_match = "K/m";
	const string energy_flux_density::dimensions_match = "kg/s3";
}
