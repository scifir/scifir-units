#include "chemistry/general/substance/units.hpp"

#include <string>

using namespace std;

namespace physics::units
{
	SCALAR_UNIT_CPP(molarity,"mol/m3");
	SCALAR_UNIT_CPP(molality,"g/g");
	SCALAR_UNIT_CPP(linear_mass_density,"g/m");
	SCALAR_UNIT_CPP(area_density,"g/m2");
	SCALAR_UNIT_CPP(dynamic_viscosity,"g/m*s");
	SCALAR_UNIT_CPP(mass_flow_rate,"g/s");
	SCALAR_UNIT_CPP(catalytic_activity,"kat");
}
