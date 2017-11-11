#include "atoms_iiib.hpp"

namespace msci
{
	ATOM_CPP(atom_Sc)

	const atom_symbol atom_Sc::enum_type = atom_symbol::Sc;

	const string atom_Sc::name = "Scandium";
	const string atom_Sc::symbol = "Sc";

	const atomic_group atom_Sc::group = IB;
	const unsigned int atom_Sc::period = 4;
	const atomic_block atom_Sc::block = atomic_block::d;

	const unsigned int atom_Sc::z = 21;
	const unsigned int atom_Sc::mass_number = 24;

	const length atom_Sc::atomic_radius = 162_pm;
	const mass atom_Sc::standard_atomic_mass = 44.956_amu;

	const float atom_Sc::electronegativity = 1.36;
	const bool atom_Sc::radioactive = false;

	const molar_energy atom_Sc::ionization_energy ("633.1 kJ/mol");
	const length atom_Sc::covalent_radius = 170_pm;
	const length atom_Sc::van_der_waals_radius = 211_pm;

	const cas_number atom_Sc::cas_number ("7440-20-2");

	ATOM_CPP(atom_Y)

	const atom_symbol atom_Y::enum_type = atom_symbol::Y;

	const string atom_Y::name = "Yttrium";
	const string atom_Y::symbol = "Y";

	const atomic_group atom_Y::group = IB;
	const unsigned int atom_Y::period = 5;
	const atomic_block atom_Y::block = atomic_block::d;

	const unsigned int atom_Y::z = 39;
	const unsigned int atom_Y::mass_number = 50;

	const length atom_Y::atomic_radius = 180_pm;
	const mass atom_Y::standard_atomic_mass = 88.906_amu;

	const float atom_Y::electronegativity = 1.22;
	const bool atom_Y::radioactive = false;

	const molar_energy atom_Y::ionization_energy ("600 kJ/mol");
	const length atom_Y::covalent_radius = 190_pm;
	const length atom_Y::van_der_waals_radius = 0_pm;

	const cas_number atom_Y::cas_number ("7440-65-5");
}
