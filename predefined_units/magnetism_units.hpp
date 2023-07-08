#ifndef SCIFIR_UNITS_PREDEFINED_UNITS_MAGNETISM_UNITS_HPP_INCLUDED
#define SCIFIR_UNITS_PREDEFINED_UNITS_MAGNETISM_UNITS_HPP_INCLUDED

#include "units/scalar_unit.hpp"
#include "units/vector_unit_3d.hpp"

using namespace std;

namespace scifir
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

#endif // SCIFIR_UNITS_PREDEFINED_UNITS_MAGNETISM_UNITS_HPP_INCLUDED
