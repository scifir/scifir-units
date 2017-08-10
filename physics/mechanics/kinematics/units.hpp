#ifndef PHYSICS_MECHANICS_MOVEMENT_UNITS_HPP_INCLUDED
#define PHYSICS_MECHANICS_MOVEMENT_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;

namespace physics::units
{
	SCALAR_UNIT_HPP(distance);
	VECTOR_UNIT_HPP(velocity);
	VECTOR_UNIT_HPP(acceleration);
	VECTOR_UNIT_HPP(jerk);
	VECTOR_UNIT_HPP(snap);
	VECTOR_UNIT_HPP(angular_velocity);
	VECTOR_UNIT_HPP(angular_acceleration);
	VECTOR_UNIT_HPP(angular_momentum);
}

#endif // PHYSICS_MECHANICS_MOVEMENT_UNITS_HPP_INCLUDED
