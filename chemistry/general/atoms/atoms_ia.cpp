#include "atoms_ia.hpp"

namespace chemistry
{
	ATOM_CPP(atom_H)

	const string atom_H::name = "Hydrogen";
	const string atom_H::symbol = "H";

	const length atom_H::atomic_radius = 1.09_angstrom;
	const mass atom_H::standard_atomic_mass = 1.008_amu;

	const molar_energy atom_H::ionization_energy("1312 kJ/mol");
	const length atom_H::covalent_radius("31 pm");
	const length atom_H::van_der_waals_radius("120 pm");

	const cas_number atom_H::cas_number("12385-13-6");

	ATOM_CPP(atom_Li)

	const string atom_Li::name = "Lithium";
	const string atom_Li::symbol = "Li";

	const length atom_Li::atomic_radius = 152_pm;
	const mass atom_Li::standard_atomic_mass = 6.941_amu;

	const molar_energy atom_Li::ionization_energy("520.2 kJ/mol");
	const length atom_Li::covalent_radius("128 pm");
	const length atom_Li::van_der_waals_radius("182 pm");

	const cas_number atom_Li::cas_number("7439-93-2");
}
