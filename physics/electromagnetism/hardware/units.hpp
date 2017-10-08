#ifndef PHYSICS_ELECTROMAGNETISM_HARDWARE_UNITS_HPP_INCLUDED
#define PHYSICS_ELECTROMAGNETISM_HARDWARE_UNITS_HPP_INCLUDED

#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;
using namespace msci::units;

namespace msci::units
{
	SCALAR_UNIT_HPP(electrical_conductivity);
	SCALAR_UNIT_HPP(electric_resistance);
	SCALAR_UNIT_HPP(electric_conductance);
	SCALAR_UNIT_HPP(capacitance);
	SCALAR_UNIT_HPP(permittivity);
	SCALAR_UNIT_HPP(resistivity);
	SCALAR_UNIT_HPP(linear_charge_density);
	SCALAR_UNIT_HPP(frequency_drift);
}

#endif // PHYSICS_ELECTROMAGNETISM_HARDWARE_UNITS_HPP_INCLUDED
