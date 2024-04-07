#ifndef SCIFIR_UNITS_PREDEFINED_UNITS_ATOMS_UNITS_HPP_INCLUDED
#define SCIFIR_UNITS_PREDEFINED_UNITS_ATOMS_UNITS_HPP_INCLUDED

#include "units/scalar_unit.hpp"

using namespace std;

namespace scifir
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
	SCALAR_UNIT_HPP(catalytic_efficiency);

	class cas_number
	{
		public:
			cas_number(string);

			inline string get_value() const
			{
				return value;
			}

			string display() const;

		private:
			string value;
	};
}

#endif // SCIFIR_UNITS_PREDEFINED_UNITS_ATOMS_UNITS_HPP_INCLUDED
