#include "atoms_iiia.hpp"

namespace msci
{
	ATOM_CPP(atom_B)

	const string atom_B::name = "Boron";
	const string atom_B::symbol = "B";

	const length atom_B::atomic_radius = 90_pm;
	const mass atom_B::standard_atomic_mass = 10.811_amu;

	const molar_energy atom_B::ionization_energy ("800.6 kJ/mol");
	const length atom_B::covalent_radius = 84_pm;
	const length atom_B::van_der_waals_radius = 192_pm;

	const cas_number atom_B::cas_number ("7440-42-8");

	ATOM_CPP(atom_Al)

	const string atom_Al::name = "Aluminum";
	const string atom_Al::symbol = "Al";

	const length atom_Al::atomic_radius = 143_pm;
	const mass atom_Al::standard_atomic_mass = 26.982_amu;

	const molar_energy atom_Al::ionization_energy ("577.5 kJ/mol");
	const length atom_Al::covalent_radius = 121_pm;
	const length atom_Al::van_der_waals_radius = 184_pm;

	const cas_number atom_Al::cas_number ("7429-90-5");

	ATOM_CPP(atom_Ga)

	const string atom_Ga::name = "Gallium";
	const string atom_Ga::symbol = "Ga";

	const length atom_Ga::atomic_radius = 135_pm;
	const mass atom_Ga::standard_atomic_mass = 69.732_amu;

	const molar_energy atom_Ga::ionization_energy ("578.8 kJ/mol");
	const length atom_Ga::covalent_radius = 122_pm;
	const length atom_Ga::van_der_waals_radius = 187_pm;

	const cas_number atom_Ga::cas_number ("7440-55-3");

	ATOM_CPP(atom_In)

	const string atom_In::name = "Indium";
	const string atom_In::symbol = "In";

	const length atom_In::atomic_radius = 167_pm;
	const mass atom_In::standard_atomic_mass = 114.818_amu;

	const molar_energy atom_In::ionization_energy ("558.3 kJ/mol");
	const length atom_In::covalent_radius = 142_pm;
	const length atom_In::van_der_waals_radius = 193_pm;

	const cas_number atom_In::cas_number ("7440-74-6");

	ATOM_CPP(atom_Tl)

	const string atom_Tl::name = "Thallium";
	const string atom_Tl::symbol = "Tl";

	const length atom_Tl::atomic_radius = 170_pm;
	const mass atom_Tl::standard_atomic_mass = 204.383_amu;

	const molar_energy atom_Tl::ionization_energy ("589.4 kJ/mol");
	const length atom_Tl::covalent_radius = 145_pm;
	const length atom_Tl::van_der_waals_radius = 196_pm;

	const cas_number atom_Tl::cas_number ("7440-28-0");

	ATOM_CPP(atom_Nh)

	const string atom_Nh::name = "Nihonium";
	const string atom_Nh::symbol = "Nh";

	const length atom_Nh::atomic_radius = 170_pm;
	const mass atom_Nh::standard_atomic_mass = 0_amu;

	const molar_energy atom_Nh::ionization_energy ("704.9 kJ/mol");
	const length atom_Nh::covalent_radius = 180_pm;
	const length atom_Nh::van_der_waals_radius = 0_pm;

	const cas_number atom_Nh::cas_number ("54084-70-7");
}
