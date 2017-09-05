#include "atoms_iib.hpp"

namespace chemistry
{
	ATOM_CPP(atom_Zn)

	const string atom_Zn::name = "Zinc";
	const string atom_Zn::symbol = "Zn";

	const length atom_Zn::atomic_radius = 134_pm;
	const mass atom_Zn::standard_atomic_mass = 65.39_amu;

	const molar_energy atom_Zn::ionization_energy ("906.4 kJ/mol");
	const length atom_Zn::covalent_radius = 122_pm;
	const length atom_Zn::van_der_waals_radius = 139_pm;

	const cas_number atom_Zn::cas_number ("7440-66-6");

	ATOM_CPP(atom_Cd)

	const string atom_Cd::name = "Cadmium";
	const string atom_Cd::symbol = "Cd";

	const length atom_Cd::atomic_radius = 151_pm;
	const mass atom_Cd::standard_atomic_mass = 112.411_amu;

	const molar_energy atom_Cd::ionization_energy ("867.8 kJ/mol");
	const length atom_Cd::covalent_radius = 144_pm;
	const length atom_Cd::van_der_waals_radius = 158_pm;

	const cas_number atom_Cd::cas_number ("7440-43-9");

	ATOM_CPP(atom_Hg)

	const string atom_Hg::name = "Mercury";
	const string atom_Hg::symbol = "Hg";

	const length atom_Hg::atomic_radius = 151_pm;
	const mass atom_Hg::standard_atomic_mass = 200.59_amu;

	const molar_energy atom_Hg::ionization_energy ("1007.1 kJ/mol");
	const length atom_Hg::covalent_radius = 132_pm;
	const length atom_Hg::van_der_waals_radius = 155_pm;

	const cas_number atom_Hg::cas_number ("7439-97-6");

	ATOM_CPP(atom_Cn)

	const string atom_Cn::name = "Copernicium";
	const string atom_Cn::symbol = "Cn";

	const length atom_Cn::atomic_radius = 147_pm;
	const mass atom_Cn::standard_atomic_mass = 285_amu;

	const molar_energy atom_Cn::ionization_energy ("1154.9 kJ/mol");
	const length atom_Cn::covalent_radius = 122_pm;
	const length atom_Cn::van_der_waals_radius = 0_pm;

	const cas_number atom_Cn::cas_number ("54084-26-3");
}
