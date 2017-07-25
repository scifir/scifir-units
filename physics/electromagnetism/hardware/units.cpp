#include "units.hpp"

using namespace std;

namespace physics::units
{
	const string electrical_conductivity::dimensions_match = "A2*s3/kg*m3";
	const string electric_resistance::dimensions_match = "kg*m2/A2*s3";
	const string electric_conductance::dimensions_match = "A2*s3/kg*m2";
	const string permittivity::dimensions_match = "A2*s4/kg*m3";
	const string resistivity::dimensions_match = "kg*m3/A2*s3";
	const string linear_charge_density::dimensions_match = "A*s/m";
	const string frequency_drift::dimensions_match = "1/s2";
}
