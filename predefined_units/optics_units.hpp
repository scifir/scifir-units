#ifndef SCIFIR_UNITS_PREDEFINED_UNITS_OPTICS_UNITS_HPP_INCLUDED
#define SCIFIR_UNITS_PREDEFINED_UNITS_OPTICS_UNITS_HPP_INCLUDED

#include "units/scalar_unit.hpp"
#include "units/vector_unit_3d.hpp"

using namespace std;

namespace scifir
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

#endif // SCIFIR_UNITS_PREDEFINED_UNITS_OPTICS_UNITS_HPP_INCLUDED
