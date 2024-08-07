#ifndef SCIFIR_UNITS_DERIVED_UNITS_HARDWARE_UNITS_HPP_INCLUDED
#define SCIFIR_UNITS_DERIVED_UNITS_HARDWARE_UNITS_HPP_INCLUDED

#include "../units/scalar_unit.hpp"
#include "../units/vector_unit_3d.hpp"

using namespace std;

namespace scifir
{
	SCALAR_UNIT_HPP(electrical_conductivity);
	SCALAR_UNIT_HPP(resistance);
	SCALAR_UNIT_HPP(electric_conductance);
	SCALAR_UNIT_HPP(capacitance);
	SCALAR_UNIT_HPP(permittivity);
	SCALAR_UNIT_HPP(resistivity);
	SCALAR_UNIT_HPP(linear_charge_density);
	SCALAR_UNIT_HPP(surface_charge_density);
	SCALAR_UNIT_HPP(volume_charge_density);
	SCALAR_UNIT_HPP(frequency_drift);
}

#endif // SCIFIR_UNITS_DERIVED_UNITS_HARDWARE_UNITS_HPP_INCLUDED
