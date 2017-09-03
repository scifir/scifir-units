#include "atoms_ia.hpp"

namespace chemistry
{
	ATOM_CPP(atom_H)

	const string atom_H::name = "Hydrogen";
	const string atom_H::symbol = "H";

	const length atom_H::atomic_radius = 1.09_angstrom;
	const mass atom_H::standard_atomic_mass = 1.008_amu;

	const molar_energy atom_H::ionization_energy ("1312 kJ/mol");
	const length atom_H::covalent_radius = 31_pm;
	const length atom_H::van_der_waals_radius = 120_pm;

	const cas_number atom_H::cas_number ("12385-13-6");

	ATOM_CPP(atom_Li)

	const string atom_Li::name = "Lithium";
	const string atom_Li::symbol = "Li";

	const length atom_Li::atomic_radius = 152_pm;
	const mass atom_Li::standard_atomic_mass = 6.941_amu;

	const molar_energy atom_Li::ionization_energy ("520.2 kJ/mol");
	const length atom_Li::covalent_radius = 128_pm;
	const length atom_Li::van_der_waals_radius = 182_pm;

	const cas_number atom_Li::cas_number ("7439-93-2");

	ATOM_CPP(atom_Na)

	const string atom_Na::name = "Sodium";
	const string atom_Na::symbol = "Na";

	const length atom_Na::atomic_radius = 186_pm;
	const mass atom_Na::standard_atomic_mass = 22.99_amu;

	const molar_energy atom_Na::ionization_energy ("495.8 kJ/mol");
	const length atom_Na::covalent_radius = 166_pm;
	const length atom_Na::van_der_waals_radius = 227_pm;

	const cas_number atom_Na::cas_number ("7440-23-5");

	ATOM_CPP(atom_K)

	const string atom_K::name = "Potassium";
	const string atom_K::symbol = "K";

	const length atom_K::atomic_radius = 227_pm;
	const mass atom_K::standard_atomic_mass = 39.098_amu;

	const molar_energy atom_K::ionization_energy ("418.8 kJ/mol");
	const length atom_K::covalent_radius = 203_pm;
	const length atom_K::van_der_waals_radius = 275_pm;

	const cas_number atom_K::cas_number ("7440-09-7");

	ATOM_CPP(atom_Rb)

	const string atom_Rb::name = "Rubidium";
	const string atom_Rb::symbol = "Rb";

	const length atom_Rb::atomic_radius = 248_pm;
	const mass atom_Rb::standard_atomic_mass = 84.468_amu;

	const molar_energy atom_Rb::ionization_energy ("403 kJ/mol");
	const length atom_Rb::covalent_radius = 220_pm;
	const length atom_Rb::van_der_waals_radius = 303_pm;

	const cas_number atom_Rb::cas_number ("7440-17-7");

	ATOM_CPP(atom_Cs)

	const string atom_Cs::name = "Cesium";
	const string atom_Cs::symbol = "Cs";

	const length atom_Cs::atomic_radius = 265_pm;
	const mass atom_Cs::standard_atomic_mass = 132.905_amu;

	const molar_energy atom_Cs::ionization_energy ("375.7 kJ/mol");
	const length atom_Cs::covalent_radius = 244_pm;
	const length atom_Cs::van_der_waals_radius = 343_pm;

	const cas_number atom_Cs::cas_number ("7440-46-2");

	ATOM_CPP(atom_Fr)

	const string atom_Fr::name = "Francium";
	const string atom_Fr::symbol = "Fr";

	const length atom_Fr::atomic_radius = 348_pm;
	const mass atom_Fr::standard_atomic_mass = 223.02_amu;

	const molar_energy atom_Fr::ionization_energy ("393 kJ/mol");
	const length atom_Fr::covalent_radius = 260_pm;
	const length atom_Fr::van_der_waals_radius = 348_pm;

	const cas_number atom_Fr::cas_number ("7440-73-5");
}
