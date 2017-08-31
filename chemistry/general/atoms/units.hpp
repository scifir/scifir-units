#ifndef CHEMISTRY_GENERAL_COMPOUNDS_UNITS_HPP_INCLUDED
#define CHEMISTRY_GENERAL_COMPOUNDS_UNITS_HPP_INCLUDED

#include "physics/basic/units/scalar_unit.hpp"

using namespace std;
using namespace physics::units;

namespace physics::units
{
	SCALAR_UNIT_HPP(density);
	SCALAR_UNIT_HPP(viscosity);
	SCALAR_UNIT_HPP(specific_volume);
	SCALAR_UNIT_HPP(specific_heat_capacity);
	SCALAR_UNIT_HPP(specific_entropy);
	SCALAR_UNIT_HPP(specific_energy);
	SCALAR_UNIT_HPP(molar_volume);
	SCALAR_UNIT_HPP(molar_mass);
	SCALAR_UNIT_HPP(molar_heat_capacity);
	SCALAR_UNIT_HPP(molar_enthalpy);
	SCALAR_UNIT_HPP(molar_entropy);
	SCALAR_UNIT_HPP(molar_energy);
	SCALAR_UNIT_HPP(molar_conductivity);
	SCALAR_UNIT_HPP(energy_density);
}

#endif // CHEMISTRY_GENERAL_COMPOUNDS_UNITS_HPP_INCLUDED
