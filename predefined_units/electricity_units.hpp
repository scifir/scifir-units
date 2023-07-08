#ifndef SCIFIR_UNITS_PREDEFINED_UNITS_ELECTRICITY_UNITS_HPP_INCLUDED
#define SCIFIR_UNITS_PREDEFINED_UNITS_ELECTRICITY_UNITS_HPP_INCLUDED

#include "units/scalar_unit.hpp"
#include "units/vector_unit_3d.hpp"

using namespace std;

namespace scifir
{
	SCALAR_UNIT_HPP(electric_current);
	SCALAR_UNIT_HPP(voltage);
	VECTOR_UNIT_HPP(electric_displacement_field);
	SCALAR_UNIT_HPP(electric_charge_density);
	SCALAR_UNIT_HPP(electric_current_density);
	VECTOR_UNIT_HPP(electric_field_strength);
	SCALAR_UNIT_HPP(electron_mobility);
	SCALAR_UNIT_HPP(inductance);
}

#endif // SCIFIR_UNITS_PREDEFINED_UNITS_ELECTRICITY_UNITS_HPP_INCLUDED
