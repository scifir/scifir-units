#include "msci/units/predefined_units/atoms_units.hpp"

#include <string>

using namespace std;

namespace msci
{
	SCALAR_UNIT_CPP(density,"g/m3");
	SCALAR_UNIT_CPP(viscosity,"m2/s");
	SCALAR_UNIT_CPP(specific_volume,"m3/g");
	SCALAR_UNIT_CPP(specific_heat_capacity,"m2/s2*K");
	SCALAR_UNIT_CPP(specific_entropy,"m2/s2*K");
	SCALAR_UNIT_CPP(specific_energy,"m2/s2");
	SCALAR_UNIT_CPP(molar_volume,"m3/mol");
	SCALAR_UNIT_CPP(molar_mass,"g/mol");
	SCALAR_UNIT_CPP(molar_heat_capacity,"m2*g/s2*K*mol");
	SCALAR_UNIT_CPP(molar_enthalpy,"m2*g/s2*mol");
	SCALAR_UNIT_CPP(molar_entropy,"m2*g/s2*K*mol");
	SCALAR_UNIT_CPP(molar_energy,"m2*g/s2*mol");
	SCALAR_UNIT_CPP(molar_conductivity,"s3*A2/g*mol");
	SCALAR_UNIT_CPP(energy_density,"g/m*s2");

	cas_number::cas_number(string new_value) : value(new_value)
	{
	}

	string cas_number::display() const
	{
		return value;
	}
}
