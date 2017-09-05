#include "atoms_iiib.hpp"

namespace chemistry
{
	ATOM_CPP(atom_Sc)

	const string atom_Sc::name = "Scandium";
	const string atom_Sc::symbol = "Sc";

	const length atom_Sc::atomic_radius = 162_pm;
	const mass atom_Sc::standard_atomic_mass = 44.956_amu;

	const molar_energy atom_Sc::ionization_energy ("633.1 kJ/mol");
	const length atom_Sc::covalent_radius = 170_pm;
	const length atom_Sc::van_der_waals_radius = 211_pm;

	const cas_number atom_Sc::cas_number ("7440-20-2");

	ATOM_CPP(atom_Y)

	const string atom_Y::name = "Yttrium";
	const string atom_Y::symbol = "Y";

	const length atom_Y::atomic_radius = 180_pm;
	const mass atom_Y::standard_atomic_mass = 88.906_amu;

	const molar_energy atom_Y::ionization_energy ("600 kJ/mol");
	const length atom_Y::covalent_radius = 190_pm;
	const length atom_Y::van_der_waals_radius = 0_pm;

	const cas_number atom_Y::cas_number ("7440-65-5");
}
