#include "units.hpp"

using namespace std;

namespace physics::units
{
	const string electric_displacement_field::dimensions_match = "A*s/m2";
	const string electric_charge_density::dimensions_match = "A*s/m3";
	const string electric_current_density::dimensions_match = "A/m2";
	const string electric_field_strength::dimensions_match = "kg*m/A*s3";
	const string electron_mobility::dimensions_match = "A*s2/kg";
}
