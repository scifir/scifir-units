#include "atoms_va.hpp"

namespace msci
{
	ATOM_CPP(atom_N)

	const atom_symbol atom_N::enum_type = atom_symbol::N;

	const string atom_N::name = "Nitrogen";
	const string atom_N::symbol = "N";

	const atomic_group atom_N::group = VA;
	const unsigned int atom_N::period = 2;
	const atomic_block atom_N::block = atomic_block::p;

	const unsigned int atom_N::z = 7;
	const unsigned int atom_N::mass_number = 7;

	const length atom_N::atomic_radius = 65_pm;
	const mass atom_N::standard_atomic_mass = 14.007_amu;

	const float atom_N::electronegativity = 3.04;
	const bool atom_N::radioactive = false;

	const molar_energy atom_N::ionization_energy ("1402.3 kJ/mol");
	const length atom_N::covalent_radius = 71_pm;
	const length atom_N::van_der_waals_radius = 155_pm;

	const cas_number atom_N::cas_number ("17778-37-9");

	ATOM_CPP(atom_P)

	const atom_symbol atom_P::enum_type = atom_symbol::P;

	const string atom_P::name = "Phosphorus";
	const string atom_P::symbol = "P";

	const atomic_group atom_P::group = VA;
	const unsigned int atom_P::period = 3;
	const atomic_block atom_P::block = atomic_block::p;

	const unsigned int atom_P::z = 15;
	const unsigned int atom_P::mass_number = 16;

	const length atom_P::atomic_radius = 100_pm;
	const mass atom_P::standard_atomic_mass = 30.974_amu;

	const float atom_P::electronegativity = 2.19;
	const bool atom_P::radioactive = false;

	const molar_energy atom_P::ionization_energy ("1011.8 kJ/mol");
	const length atom_P::covalent_radius = 107_pm;
	const length atom_P::van_der_waals_radius = 180_pm;

	const cas_number atom_P::cas_number ("7723-14-0");

	ATOM_CPP(atom_As)

	const atom_symbol atom_As::enum_type = atom_symbol::As;

	const string atom_As::name = "Arsenic";
	const string atom_As::symbol = "As";

	const atomic_group atom_As::group = VA;
	const unsigned int atom_As::period = 4;
	const atomic_block atom_As::block = atomic_block::p;

	const unsigned int atom_As::z = 33;
	const unsigned int atom_As::mass_number = 42;

	const length atom_As::atomic_radius = 119_pm;
	const mass atom_As::standard_atomic_mass = 74.922_amu;

	const float atom_As::electronegativity = 2.18;
	const bool atom_As::radioactive = false;

	const molar_energy atom_As::ionization_energy ("947.0 kJ/mol");
	const length atom_As::covalent_radius = 119_pm;
	const length atom_As::van_der_waals_radius = 185_pm;

	const cas_number atom_As::cas_number ("7440-38-2");

	ATOM_CPP(atom_Sb)

	const atom_symbol atom_Sb::enum_type = atom_symbol::Sb;

	const string atom_Sb::name = "Antimony";
	const string atom_Sb::symbol = "Sb";

	const atomic_group atom_Sb::group = VA;
	const unsigned int atom_Sb::period = 5;
	const atomic_block atom_Sb::block = atomic_block::p;

	const unsigned int atom_Sb::z = 51;
	const unsigned int atom_Sb::mass_number = 71;

	const length atom_Sb::atomic_radius = 140_pm;
	const mass atom_Sb::standard_atomic_mass = 121.760_amu;

	const float atom_Sb::electronegativity = 2.05;
	const bool atom_Sb::radioactive = false;

	const molar_energy atom_Sb::ionization_energy ("834 kJ/mol");
	const length atom_Sb::covalent_radius = 139_pm;
	const length atom_Sb::van_der_waals_radius = 206_pm;

	const cas_number atom_Sb::cas_number ("7440-36-0");

	ATOM_CPP(atom_Bi)

	const atom_symbol atom_Bi::enum_type = atom_symbol::Bi;

	const string atom_Bi::name = "Bismuth";
	const string atom_Bi::symbol = "Bi";

	const atomic_group atom_Bi::group = VA;
	const unsigned int atom_Bi::period = 6;
	const atomic_block atom_Bi::block = atomic_block::p;

	const unsigned int atom_Bi::z = 83;
	const unsigned int atom_Bi::mass_number = 126;

	const length atom_Bi::atomic_radius = 156_pm;
	const mass atom_Bi::standard_atomic_mass = 208.98_amu;

	const float atom_Bi::electronegativity = 2.02;
	const bool atom_Bi::radioactive = false;

	const molar_energy atom_Bi::ionization_energy ("703 kJ/mol");
	const length atom_Bi::covalent_radius = 148_pm;
	const length atom_Bi::van_der_waals_radius = 207_pm;

	const cas_number atom_Bi::cas_number ("7440-69-9");

	ATOM_CPP(atom_Mc)

	const atom_symbol atom_Mc::enum_type = atom_symbol::Mc;

	const string atom_Mc::name = "Moscovium";
	const string atom_Mc::symbol = "Mc";

	const atomic_group atom_Mc::group = VA;
	const unsigned int atom_Mc::period = 7;
	const atomic_block atom_Mc::block = atomic_block::p;

	const unsigned int atom_Mc::z = 115;
	const unsigned int atom_Mc::mass_number = 175;

	const length atom_Mc::atomic_radius = 187_pm;
	const mass atom_Mc::standard_atomic_mass = 0_amu;

	const float atom_Mc::electronegativity = 0;
	const bool atom_Mc::radioactive = false;

	const molar_energy atom_Mc::ionization_energy ("538.4 kJ/mol");
	const length atom_Mc::covalent_radius = 156_pm;
	const length atom_Mc::van_der_waals_radius = 0_pm;

	const cas_number atom_Mc::cas_number ("54085-64-2");
}
