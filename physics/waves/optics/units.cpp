#include "units.hpp"

using namespace std;

namespace physics::units
{
	const string optical_power::dimensions_match = "1/m";
	const string luminance::dimensions_match = "cd/m2";
	const string luminous_energy::dimensions_match = "cd*sr*s";
	const string luminous_exposure::dimensions_match = "cd*sr*s/m2";
	const string luminous_efficacy::dimensions_match = "lm/W";
	const string ionizing_radiation::dimensions_match = "A*s/kg";
	const string absorbed_dose::dimensions_match = "m2/s3";
}
