#include "predefined_units/hardware_units.hpp"

using namespace std;

namespace msci
{
	SCALAR_UNIT_CPP(electrical_conductivity,"A2*s3/kg*m3");
	SCALAR_UNIT_CPP(resistance,"kg*m2/A2*s3");
	SCALAR_UNIT_CPP(electric_conductance,"A2*s3/kg*m2");
	SCALAR_UNIT_CPP(capacitance,"A2*s4/m2*kg");
	SCALAR_UNIT_CPP(permittivity,"A2*s4/kg*m3");
	SCALAR_UNIT_CPP(resistivity,"kg*m3/A2*s3");
	SCALAR_UNIT_CPP(linear_charge_density,"A*s/m");
	SCALAR_UNIT_CPP(frequency_drift,"1/s2");
}
