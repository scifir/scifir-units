#include "./units.hpp"

using namespace std;

namespace msci::units
{
	SCALAR_UNIT_CPP(energy,"kg*m2/s2");
	SCALAR_UNIT_CPP(action,"kg*m2/s");
	SCALAR_UNIT_CPP(power,"kg*m2/s3");
	SCALAR_UNIT_CPP(power_density,"kg/m*s3");
	SCALAR_UNIT_CPP(enthalpy,"kg*m2/s2");
	SCALAR_UNIT_CPP(entropy,"kg*m2/K*s2");
	SCALAR_UNIT_CPP(heat_capacity,"kg*m2/K*s2");
	SCALAR_UNIT_CPP(heat_flux_density,"kg/s3");
	SCALAR_UNIT_CPP(thermal_conductivity,"kg*m/K*s3");
	SCALAR_UNIT_CPP(thermal_diffusivity,"m2/s");
	SCALAR_UNIT_CPP(thermal_resistance,"K*s3/kg*m2");
	SCALAR_UNIT_CPP(thermal_expansion_coefficient,"1/K");
	VECTOR_UNIT_CPP(temperature_gradient,"K/m");
	SCALAR_UNIT_CPP(energy_flux_density,"kg/s3");
}
