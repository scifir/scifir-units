#include "units.hpp"

#include <string>

using namespace std;

namespace physics::units
{
	const string molarity::dimensions_match = "mol/m3";
	const string molality::dimensions_match = "mol/g";
	const string linear_mass_density::dimensions_match = "g/m";
	const string area_density::dimensions_match = "g/m2";
	const string dynamic_viscosity::dimensions_match = "g/m*s";
	const string mass_flow_rate::dimensions_match = "g/s";
}
