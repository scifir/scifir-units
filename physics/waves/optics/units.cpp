#include "./units.hpp"

using namespace std;

namespace physics::units
{
	SCALAR_UNIT_CPP(optical_power,"1/m");
	SCALAR_UNIT_CPP(luminance,"cd/m2");
	SCALAR_UNIT_CPP(illuminance,"lx");
	SCALAR_UNIT_CPP(luminous_flux,"lm");
	SCALAR_UNIT_CPP(luminous_energy,"cd*sr*s");
	SCALAR_UNIT_CPP(luminous_exposure,"cd*sr*s/m2");
	SCALAR_UNIT_CPP(luminous_efficacy,"lm/W");
	SCALAR_UNIT_CPP(ionizing_radiation,"A*s/kg");
	SCALAR_UNIT_CPP(absorbed_dose,"m2/s3");
}
