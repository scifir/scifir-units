#include "atoms_ib.hpp"

namespace msci
{
	ATOM_CPP(atom_Cu)

	const string atom_Cu::name = "Copper";
	const string atom_Cu::symbol = "Cu";

	const length atom_Cu::atomic_radius = 128_pm;
	const mass atom_Cu::standard_atomic_mass = 63.546_amu;

	const molar_energy atom_Cu::ionization_energy ("745.5 kJ/mol");
	const length atom_Cu::covalent_radius = 132_pm;
	const length atom_Cu::van_der_waals_radius = 140_pm;

	const cas_number atom_Cu::cas_number ("7440-50-8");

	ATOM_CPP(atom_Ag)

	const string atom_Ag::name = "Silver";
	const string atom_Ag::symbol = "Ag";

	const length atom_Ag::atomic_radius = 144_pm;
	const mass atom_Ag::standard_atomic_mass = 107.858_amu;

	const molar_energy atom_Ag::ionization_energy ("731.0 kJ/mol");
	const length atom_Ag::covalent_radius = 145_pm;
	const length atom_Ag::van_der_waals_radius = 172_pm;

	const cas_number atom_Ag::cas_number ("7440-22-4");

	ATOM_CPP(atom_Au)

	const string atom_Au::name = "Gold";
	const string atom_Au::symbol = "Au";

	const length atom_Au::atomic_radius = 144_pm;
	const mass atom_Au::standard_atomic_mass = 196.967_amu;

	const molar_energy atom_Au::ionization_energy ("890.1 kJ/mol");
	const length atom_Au::covalent_radius = 136_pm;
	const length atom_Au::van_der_waals_radius = 166_pm;

	const cas_number atom_Au::cas_number ("7440-57-5");

	ATOM_CPP(atom_Rg)

	const string atom_Rg::name = "Roentgenium";
	const string atom_Rg::symbol = "Rg";

	const length atom_Rg::atomic_radius = 138_pm;
	const mass atom_Rg::standard_atomic_mass = 272_amu;

	const molar_energy atom_Rg::ionization_energy ("1022.7 kJ/mol");
	const length atom_Rg::covalent_radius = 121_pm;
	const length atom_Rg::van_der_waals_radius = 0_pm;

	const cas_number atom_Rg::cas_number ("54386-24-2");
}
