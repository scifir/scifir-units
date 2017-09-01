#include "atoms_ia.hpp"

namespace chemistry
{
	atom_H::atom_H() : normal_atom<atom_H>()
	{
	}

	const string atom_H::name = "Hydrogen";
	const string atom_H::symbol = "H";

	const length atom_H::atomic_radius = 1.09_angstrom;
	const mass atom_H::standard_atomic_mass = 1.008_amu;

	const temperature atom_H::melting_point = 13.99_K;
	const temperature atom_H::boiling_point = 20.271_K;
	const density atom_H::density_stp("0.08988 g/L");

	const molar_enthalpy atom_H::heat_of_fusion("0.117 kJ/mol");
	const molar_enthalpy atom_H::heat_of_vaporization("0.904 kJ/mol");
	const molar_heat_capacity atom_H::heat_capacity("28.836 J/mol*K");

	const molar_energy atom_H::ionization_energy("1312 kJ/mol");
	const length atom_H::covalent_radius("31 pm");
	const length atom_H::van_der_waals_radius("120 pm");

	const crystal_structure atom_H::crystal_structure = crystal_structure::hexagonal;
	const thermal_conductivity atom_H::thermal_conductivity("0.1805 W/m*K");
	const magnetic_ordering atom_H::magnetic_ordering = magnetic_ordering::diamagnetic;
	const magnetic_susceptibility atom_H::magnetic_susceptibility("3.98 cm3/mol");//("-3.98 * 10^-6 cm3/mol");
	const cas_number atom_H::cas_number("12385-13-6");
}
