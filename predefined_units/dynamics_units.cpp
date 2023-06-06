#include "predefined_units/dynamics_units.hpp"

using namespace std;

namespace msci
{
	VECTOR_UNIT_CPP(impulse,"m*kg/s");
	VECTOR_UNIT_CPP(force,"kg*m/s2");
	VECTOR_UNIT_CPP(torque,"kg*m2/s2");
	VECTOR_UNIT_CPP(pressure,"kg/m*s2");
	VECTOR_UNIT_CPP(surface_tension,"kg/s2");
	SCALAR_UNIT_CPP(stiffness,"kg/s2");
	SCALAR_UNIT_CPP(moment_of_inertia,"m2*kg");
}
