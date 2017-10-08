#ifndef PHYSICS_MECHANICS_FLUIDDYNAMICS_UNITS_HPP_INCLUDED
#define PHYSICS_MECHANICS_FLUIDDYNAMICS_UNITS_HPP_INCLUDED

#include "physics/basic/units/scalar_unit.hpp"

using namespace std;
using namespace msci::units;

namespace msci::units
{
	SCALAR_UNIT_HPP(volumetric_flow);
	SCALAR_UNIT_HPP(diffusion_coefficient);
	SCALAR_UNIT_HPP(compressibility);
}

#endif // PHYSICS_MECHANICS_FLUIDDYNAMICS_UNITS_HPP_INCLUDED
