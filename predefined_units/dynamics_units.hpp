#ifndef PHYSICS_MECHANICS_DYNAMICS_UNITS_HPP_INCLUDED
#define PHYSICS_MECHANICS_DYNAMICS_UNITS_HPP_INCLUDED

#include "msci/units/units/scalar_unit.hpp"
#include "msci/units/units/vector_unit_3d.hpp"

using namespace std;

namespace msci
{
	VECTOR_UNIT_HPP(impulse);
	VECTOR_UNIT_HPP(force);
	VECTOR_UNIT_HPP(torque);
	VECTOR_UNIT_HPP(pressure);
	VECTOR_UNIT_HPP(surface_tension);
	SCALAR_UNIT_HPP(stiffness);
	SCALAR_UNIT_HPP(moment_of_inertia);
}

#endif // PHYSICS_MECHANICS_DYNAMICS_UNITS_HPP_INCLUDED
