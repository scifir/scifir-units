#ifndef CHEMISTRY_GENERAL_SUBSTANCE_UNITS_HPP_INCLUDED
#define CHEMISTRY_GENERAL_SUBSTANCE_UNITS_HPP_INCLUDED

#include "physics/basic/units/scalar_unit.hpp"

#include <iostream>

using namespace std;

namespace physics::units
{
	SCALAR_UNIT_HPP(molarity);
	SCALAR_UNIT_HPP(molality);
	SCALAR_UNIT_HPP(concentration);
	SCALAR_UNIT_HPP(linear_mass_density);
	SCALAR_UNIT_HPP(area_density);
	SCALAR_UNIT_HPP(dynamic_viscosity);
	SCALAR_UNIT_HPP(mass_flow_rate);
	SCALAR_UNIT_HPP(catalytic_activity);
}

wostream& operator <<(wostream&, const physics::units::concentration&);

#endif // CHEMISTRY_GENERAL_SUBSTANCE_UNITS_HPP_INCLUDED
