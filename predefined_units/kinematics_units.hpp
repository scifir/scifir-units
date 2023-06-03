#ifndef MSCI_UNITS_PREDEFINED_UNITS_KINEMATICS_UNITS_HPP_INCLUDED
#define MSCI_UNITS_PREDEFINED_UNITS_KINEMATICS_UNITS_HPP_INCLUDED

#include "units/scalar_unit.hpp"
#include "units/vector_unit_2d.hpp"
#include "units/vector_unit_3d.hpp"

using namespace std;

namespace msci
{
	SCALAR_UNIT_HPP(distance);
	VECTOR_UNIT_2D_HPP(displacement);
	VECTOR_UNIT_3D_HPP(displacement);
	VECTOR_UNIT_HPP(velocity);
	VECTOR_UNIT_HPP(acceleration);
	VECTOR_UNIT_HPP(jerk);
	VECTOR_UNIT_HPP(snap);
	VECTOR_UNIT_HPP(angular_velocity);
	VECTOR_UNIT_HPP(angular_acceleration);
	VECTOR_UNIT_HPP(angular_momentum);
}

#endif // MSCI_UNITS_PREDEFINED_UNITS_KINEMATICS_UNITS_HPP_INCLUDED
