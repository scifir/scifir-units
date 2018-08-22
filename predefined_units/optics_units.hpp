#ifndef PHYSICS_OPTICS_UNITS_HPP_INCLUDED
#define PHYSICS_OPTICS_UNITS_HPP_INCLUDED

#include "msci/units/units/scalar_unit.hpp"
#include "msci/units/units/vector_unit.hpp"

using namespace std;

namespace msci
{
	SCALAR_UNIT_HPP(optical_power);
	SCALAR_UNIT_HPP(luminance);
	SCALAR_UNIT_HPP(illuminance);
	SCALAR_UNIT_HPP(luminous_flux);
	SCALAR_UNIT_HPP(luminous_energy);
	SCALAR_UNIT_HPP(luminous_exposure);
	SCALAR_UNIT_HPP(luminous_efficacy);
	SCALAR_UNIT_HPP(ionizing_radiation);
	SCALAR_UNIT_HPP(absorbed_dose);
}

#endif // PHYSICS_OPTICS_UNITS_HPP_INCLUDED
