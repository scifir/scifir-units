#ifndef PHYSICS_MECHANICS_DYNAMICS_UNITS_HPP_INCLUDED
#define PHYSICS_MECHANICS_DYNAMICS_UNITS_HPP_INCLUDED

#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;

namespace physics::units
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
