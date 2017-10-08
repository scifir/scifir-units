#include "atoms_vib.hpp"

namespace msci
{
	ATOM_CPP(atom_Cr)

	const string atom_Cr::name = "Chromium";
	const string atom_Cr::symbol = "Cr";

	const length atom_Cr::atomic_radius = 128_pm;
	const mass atom_Cr::standard_atomic_mass = 51.996_amu;

	const molar_energy atom_Cr::ionization_energy ("652.9 kJ/mol");
	const length atom_Cr::covalent_radius = 139_pm;
	const length atom_Cr::van_der_waals_radius = 0_pm;

	const cas_number atom_Cr::cas_number ("7440-47-3");

	ATOM_CPP(atom_Mo)

	const string atom_Mo::name = "Molybdenum";
	const string atom_Mo::symbol = "Mo";

	const length atom_Mo::atomic_radius = 139_pm;
	const mass atom_Mo::standard_atomic_mass = 95.95_amu;

	const molar_energy atom_Mo::ionization_energy ("684.3 kJ/mol");
	const length atom_Mo::covalent_radius = 154_pm;
	const length atom_Mo::van_der_waals_radius = 0_pm;

	const cas_number atom_Mo::cas_number ("7439-98-7");

	ATOM_CPP(atom_W)

	const string atom_W::name = "Tungsten";
	const string atom_W::symbol = "W";

	const length atom_W::atomic_radius = 139_pm;
	const mass atom_W::standard_atomic_mass = 183.85_amu;

	const molar_energy atom_W::ionization_energy ("770 kJ/mol");
	const length atom_W::covalent_radius = 162_pm;
	const length atom_W::van_der_waals_radius = 0_pm;

	const cas_number atom_W::cas_number ("7440-33-7");

	ATOM_CPP(atom_Sg)

	const string atom_Sg::name = "Seaborgium";
	const string atom_Sg::symbol = "Sg";

	const length atom_Sg::atomic_radius = 132_pm;
	const mass atom_Sg::standard_atomic_mass = 266_amu;

	const molar_energy atom_Sg::ionization_energy ("752.6 kJ/mol");
	const length atom_Sg::covalent_radius = 143_pm;
	const length atom_Sg::van_der_waals_radius = 0_pm;

	const cas_number atom_Sg::cas_number ("54038-81-2");
}
