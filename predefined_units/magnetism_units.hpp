#ifndef PHYSICS_ELECTROMAGNETISM_MAGNETISM_UNITS_HPP_INCLUDED
#define PHYSICS_ELECTROMAGNETISM_MAGNETISM_UNITS_HPP_INCLUDED

#include "msci/units/units/scalar_unit.hpp"
#include "msci/units/units/vector_unit.hpp"

using namespace std;

namespace msci
{
	SCALAR_UNIT_HPP(polarization_density); // TODO: vector_field
	SCALAR_UNIT_HPP(magnetic_permeability); // TODO: vector_field
	SCALAR_UNIT_HPP(magnetization); // TODO: vector_field
	SCALAR_UNIT_HPP(magnetic_flux);
	VECTOR_UNIT_HPP(magnetic_strength); // TODO: vector_field
	VECTOR_UNIT_HPP(magnetic_moment);
	SCALAR_UNIT_HPP(magnetic_reluctance);
	VECTOR_UNIT_HPP(magnetic_vector_potential); // TODO: vector_field
	SCALAR_UNIT_HPP(magnetic_rigidity);
	VECTOR_UNIT_HPP(magnetomotive_force);
	SCALAR_UNIT_HPP(magnetic_susceptibility);
}

#endif // PHYSICS_ELECTROMAGNETISM_MAGNETISM_UNITS_HPP_INCLUDED
