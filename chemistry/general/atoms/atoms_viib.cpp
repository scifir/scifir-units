#include "atoms_viib.hpp"

namespace chemistry
{
	ATOM_CPP(atom_Mn)

	const string atom_Mn::name = "Manganese";
	const string atom_Mn::symbol = "Mn";

	const length atom_Mn::atomic_radius = 127_pm;
	const mass atom_Mn::standard_atomic_mass = 54.938_amu;

	const molar_energy atom_Mn::ionization_energy ("717.3 kJ/mol");
	const length atom_Mn::covalent_radius = 139_pm;
	const length atom_Mn::van_der_waals_radius = 0_pm;

	const cas_number atom_Mn::cas_number ("7439-96-5");

	ATOM_CPP(atom_Tc)

	const string atom_Tc::name = "Technetium";
	const string atom_Tc::symbol = "Tc";

	const length atom_Tc::atomic_radius = 136_pm;
	const mass atom_Tc::standard_atomic_mass = 98.907_amu;

	const molar_energy atom_Tc::ionization_energy ("702 kJ/mol");
	const length atom_Tc::covalent_radius = 147_pm;
	const length atom_Tc::van_der_waals_radius = 0_pm;

	const cas_number atom_Tc::cas_number ("7440-26-8");

	ATOM_CPP(atom_Re)

	const string atom_Re::name = "Rhenium";
	const string atom_Re::symbol = "Re";

	const length atom_Re::atomic_radius = 137_pm;
	const mass atom_Re::standard_atomic_mass = 186.207_amu;

	const molar_energy atom_Re::ionization_energy ("760 kJ/mol");
	const length atom_Re::covalent_radius = 151_pm;
	const length atom_Re::van_der_waals_radius = 0_pm;

	const cas_number atom_Re::cas_number ("7440-15-5");

	ATOM_CPP(atom_Bh)

	const string atom_Bh::name = "Bohrium";
	const string atom_Bh::symbol = "Bh";

	const length atom_Bh::atomic_radius = 128_pm;
	const mass atom_Bh::standard_atomic_mass = 264_amu;

	const molar_energy atom_Bh::ionization_energy ("742.9 kJ/mol");
	const length atom_Bh::covalent_radius = 141_pm;
	const length atom_Bh::van_der_waals_radius = 0_pm;

	const cas_number atom_Bh::cas_number ("54037-14-8");
}
