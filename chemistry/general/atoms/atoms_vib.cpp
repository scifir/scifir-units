#include "atoms_vib.hpp"

namespace msci
{
	ATOM_CPP(atom_Cr)

	const atom_symbol atom_Cr::enum_type = atom_symbol::Cr;

	const string atom_Cr::name = "Chromium";
	const string atom_Cr::symbol = "Cr";

	const atomic_group atom_Cr::group = VIB;
	const unsigned int atom_Cr::period = 4;
	const atomic_block atom_Cr::block = atomic_block::d;

	const unsigned int atom_Cr::z = 24;
	const unsigned int atom_Cr::mass_number = 28;

	const length atom_Cr::atomic_radius = 128_pm;
	const mass atom_Cr::standard_atomic_mass = 51.996_amu;

	const float atom_Cr::electronegativity = 1.66;
	const bool atom_Cr::radioactive = false;

	const molar_energy atom_Cr::ionization_energy ("652.9 kJ/mol");
	const length atom_Cr::covalent_radius = 139_pm;
	const length atom_Cr::van_der_waals_radius = 0_pm;

	const cas_number atom_Cr::cas_number ("7440-47-3");

	ATOM_CPP(atom_Mo)

	const atom_symbol atom_Mo::enum_type = atom_symbol::Mo;

	const string atom_Mo::name = "Molybdenum";
	const string atom_Mo::symbol = "Mo";

	const atomic_group atom_Mo::group = VIB;
	const unsigned int atom_Mo::period = 5;
	const atomic_block atom_Mo::block = atomic_block::d;

	const unsigned int atom_Mo::z = 42;
	const unsigned int atom_Mo::mass_number = 54;

	const length atom_Mo::atomic_radius = 139_pm;
	const mass atom_Mo::standard_atomic_mass = 95.95_amu;

	const float atom_Mo::electronegativity = 2.16;
	const bool atom_Mo::radioactive = false;

	const molar_energy atom_Mo::ionization_energy ("684.3 kJ/mol");
	const length atom_Mo::covalent_radius = 154_pm;
	const length atom_Mo::van_der_waals_radius = 0_pm;

	const cas_number atom_Mo::cas_number ("7439-98-7");

	ATOM_CPP(atom_W)

	const atom_symbol atom_W::enum_type = atom_symbol::W;

	const string atom_W::name = "Tungsten";
	const string atom_W::symbol = "W";

	const atomic_group atom_W::group = VIB;
	const unsigned int atom_W::period = 6;
	const atomic_block atom_W::block = atomic_block::d;

	const unsigned int atom_W::z = 74;
	const unsigned int atom_W::mass_number = 110;

	const length atom_W::atomic_radius = 139_pm;
	const mass atom_W::standard_atomic_mass = 183.85_amu;

	const float atom_W::electronegativity = 2.36;
	const bool atom_W::radioactive = false;

	const molar_energy atom_W::ionization_energy ("770 kJ/mol");
	const length atom_W::covalent_radius = 162_pm;
	const length atom_W::van_der_waals_radius = 0_pm;

	const cas_number atom_W::cas_number ("7440-33-7");

	ATOM_CPP(atom_Sg)

	const atom_symbol atom_Sg::enum_type = atom_symbol::Sg;

	const string atom_Sg::name = "Seaborgium";
	const string atom_Sg::symbol = "Sg";

	const atomic_group atom_Sg::group = VIB;
	const unsigned int atom_Sg::period = 7;
	const atomic_block atom_Sg::block = atomic_block::d;

	const unsigned int atom_Sg::z = 106;
	const unsigned int atom_Sg::mass_number = 160;

	const length atom_Sg::atomic_radius = 132_pm;
	const mass atom_Sg::standard_atomic_mass = 266_amu;

	const float atom_Sg::electronegativity = 0;
	const bool atom_Sg::radioactive = false;

	const molar_energy atom_Sg::ionization_energy ("752.6 kJ/mol");
	const length atom_Sg::covalent_radius = 143_pm;
	const length atom_Sg::van_der_waals_radius = 0_pm;

	const cas_number atom_Sg::cas_number ("54038-81-2");
}
