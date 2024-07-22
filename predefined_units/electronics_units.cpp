#include "./electronics_units.hpp"

using namespace std;

namespace scifir
{
	SCALAR_UNIT_CPP(electrical_conductivity,"A2*s3/kg*m3");
	SCALAR_UNIT_CPP(resistance,"Ω");
	SCALAR_UNIT_CPP(electric_conductance,"S");
	SCALAR_UNIT_CPP(capacitance,"F");
	SCALAR_UNIT_CPP(permittivity,"A2*s4/kg*m3");
	SCALAR_UNIT_CPP(resistivity,"kg*m3/A2*s3");
	SCALAR_UNIT_CPP(linear_charge_density,"C/m");
	SCALAR_UNIT_CPP(surface_charge_density,"C/m2");
	SCALAR_UNIT_CPP(volume_charge_density,"C/m3");
	SCALAR_UNIT_CPP(frequency_drift,"1/s2");
}
