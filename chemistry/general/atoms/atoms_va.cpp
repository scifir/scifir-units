#include "atoms_va.hpp"

namespace chemistry
{
	ATOM_CPP(atom_N)

	const string atom_N::name = "Nitrogen";
	const string atom_N::symbol = "N";

	const length atom_N::atomic_radius = 65_pm;
	const mass atom_N::standard_atomic_mass = 14.007_amu;

	const molar_energy atom_N::ionization_energy ("1402.3 kJ/mol");
	const length atom_N::covalent_radius = 71_pm;
	const length atom_N::van_der_waals_radius = 155_pm;

	const cas_number atom_N::cas_number ("17778-37-9");

	ATOM_CPP(atom_P)

	const string atom_P::name = "Phosphorus";
	const string atom_P::symbol = "P";

	const length atom_P::atomic_radius = 100_pm;
	const mass atom_P::standard_atomic_mass = 30.974_amu;

	const molar_energy atom_P::ionization_energy ("1011.8 kJ/mol");
	const length atom_P::covalent_radius = 107_pm;
	const length atom_P::van_der_waals_radius = 180_pm;

	const cas_number atom_P::cas_number ("7723-14-0");

	ATOM_CPP(atom_As)

	const string atom_As::name = "Arsenic";
	const string atom_As::symbol = "As";

	const length atom_As::atomic_radius = 119_pm;
	const mass atom_As::standard_atomic_mass = 74.922_amu;

	const molar_energy atom_As::ionization_energy ("947.0 kJ/mol");
	const length atom_As::covalent_radius = 119_pm;
	const length atom_As::van_der_waals_radius = 185_pm;

	const cas_number atom_As::cas_number ("7440-38-2");

	ATOM_CPP(atom_Sb)

	const string atom_Sb::name = "Antimony";
	const string atom_Sb::symbol = "Sb";

	const length atom_Sb::atomic_radius = 140_pm;
	const mass atom_Sb::standard_atomic_mass = 121.760_amu;

	const molar_energy atom_Sb::ionization_energy ("834 kJ/mol");
	const length atom_Sb::covalent_radius = 139_pm;
	const length atom_Sb::van_der_waals_radius = 206_pm;

	const cas_number atom_Sb::cas_number ("7440-36-0");

	ATOM_CPP(atom_Bi)

	const string atom_Bi::name = "Bismuth";
	const string atom_Bi::symbol = "Bi";

	const length atom_Bi::atomic_radius = 156_pm;
	const mass atom_Bi::standard_atomic_mass = 208.98_amu;

	const molar_energy atom_Bi::ionization_energy ("703 kJ/mol");
	const length atom_Bi::covalent_radius = 148_pm;
	const length atom_Bi::van_der_waals_radius = 207_pm;

	const cas_number atom_Bi::cas_number ("7440-69-9");

	ATOM_CPP(atom_Mc)

	const string atom_Mc::name = "Moscovium";
	const string atom_Mc::symbol = "Mc";

	const length atom_Mc::atomic_radius = 187_pm;
	const mass atom_Mc::standard_atomic_mass = 0_amu;

	const molar_energy atom_Mc::ionization_energy ("538.4 kJ/mol");
	const length atom_Mc::covalent_radius = 156_pm;
	const length atom_Mc::van_der_waals_radius = 0_pm;

	const cas_number atom_Mc::cas_number ("54085-64-2");
}
