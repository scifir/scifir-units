#ifndef MSCI_UNITS_PREDEFINED_UNITS_DYNAMICS_UNITS_HPP_INCLUDED
#define MSCI_UNITS_PREDEFINED_UNITS_DYNAMICS_UNITS_HPP_INCLUDED

#include "units/scalar_unit.hpp"
#include "units/vector_unit_3d.hpp"

using namespace std;

namespace msci
{
	VECTOR_UNIT_HPP(impulse);
	SCALAR_UNIT_HPP(force);
	VECTOR_UNIT_HPP(torque);
	VECTOR_UNIT_HPP(pressure);
	VECTOR_UNIT_HPP(surface_tension);
	SCALAR_UNIT_HPP(stiffness);
	SCALAR_UNIT_HPP(moment_of_inertia);
}

#endif // MSCI_UNITS_PREDEFINED_UNITS_DYNAMICS_UNITS_HPP_INCLUDED
