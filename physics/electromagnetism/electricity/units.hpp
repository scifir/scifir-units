#ifndef PHYSICS_ELECTROMAGNETISM_ELECTRICITY_UNITS_HPP_INCLUDED
#define PHYSICS_ELECTROMAGNETISM_ELECTRICITY_UNITS_HPP_INCLUDED

#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;

namespace physics::units
{
	VECTOR_UNIT_HPP(electric_displacement_field);
	SCALAR_UNIT_HPP(electric_charge_density);
	SCALAR_UNIT_HPP(electric_current_density);
	VECTOR_UNIT_HPP(electric_field_strength);
	SCALAR_UNIT_HPP(electron_mobility);
}

#endif // PHYSICS_ELECTROMAGNETISM_ELECTRICITY_UNITS_HPP_INCLUDED
