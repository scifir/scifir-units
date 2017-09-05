#include "atoms_ivb.hpp"

namespace chemistry
{
	ATOM_CPP(atom_Ti)

	const string atom_Ti::name = "Titanium";
	const string atom_Ti::symbol = "Ti";

	const length atom_Ti::atomic_radius = 147_pm;
	const mass atom_Ti::standard_atomic_mass = 47.88_amu;

	const molar_energy atom_Ti::ionization_energy ("658.8 kJ/mol");
	const length atom_Ti::covalent_radius = 160_pm;
	const length atom_Ti::van_der_waals_radius = 0_pm;

	const cas_number atom_Ti::cas_number ("7440-32-6");

	ATOM_CPP(atom_Zr)

	const string atom_Zr::name = "Zirconium";
	const string atom_Zr::symbol = "Zr";

	const length atom_Zr::atomic_radius = 160_pm;
	const mass atom_Zr::standard_atomic_mass = 91.224_amu;

	const molar_energy atom_Zr::ionization_energy ("640.1 kJ/mol");
	const length atom_Zr::covalent_radius = 175_pm;
	const length atom_Zr::van_der_waals_radius = 0_pm;

	const cas_number atom_Zr::cas_number ("7440-67-7");

	ATOM_CPP(atom_Hf)

	const string atom_Hf::name = "Hafnium";
	const string atom_Hf::symbol = "Hf";

	const length atom_Hf::atomic_radius = 159_pm;
	const mass atom_Hf::standard_atomic_mass = 178.49_amu;

	const molar_energy atom_Hf::ionization_energy ("658.5 kJ/mol");
	const length atom_Hf::covalent_radius = 175_pm;
	const length atom_Hf::van_der_waals_radius = 0_pm;

	const cas_number atom_Hf::cas_number ("7440-58-6");

	ATOM_CPP(atom_Rf)

	const string atom_Rf::name = "Rutherfordium";
	const string atom_Rf::symbol = "Rf";

	const length atom_Rf::atomic_radius = 150_pm;
	const mass atom_Rf::standard_atomic_mass = 267_amu;

	const molar_energy atom_Rf::ionization_energy ("579.9 kJ/mol");
	const length atom_Rf::covalent_radius = 157_pm;
	const length atom_Rf::van_der_waals_radius = 0_pm;

	const cas_number atom_Rf::cas_number ("53850-36-5");
}
