#include "atoms_viiia.hpp"

namespace msci
{
	ATOM_CPP(atom_He)

	const string atom_He::name = "Helium";
	const string atom_He::symbol = "He";

	const length atom_He::atomic_radius = 0_m;
	const mass atom_He::standard_atomic_mass = 4.003_amu;

	const molar_energy atom_He::ionization_energy ("2372.3 kJ/mol");
	const length atom_He::covalent_radius = 28_pm;
	const length atom_He::van_der_waals_radius = 140_pm;

	const cas_number atom_He::cas_number ("7440-59-7");

	ATOM_CPP(atom_Ne)

	const string atom_Ne::name = "Neon";
	const string atom_Ne::symbol = "Ne";

	const length atom_Ne::atomic_radius = 0_pm;
	const mass atom_Ne::standard_atomic_mass = 20.180_amu;

	const molar_energy atom_Ne::ionization_energy ("2080.7 kJ/mol");
	const length atom_Ne::covalent_radius = 58_pm;
	const length atom_Ne::van_der_waals_radius = 154_pm;

	const cas_number atom_Ne::cas_number ("7440-01-9");

	ATOM_CPP(atom_Ar)

	const string atom_Ar::name = "Argon";
	const string atom_Ar::symbol = "Ar";

	const length atom_Ar::atomic_radius = 0_pm;
	const mass atom_Ar::standard_atomic_mass = 39.948_amu;

	const molar_energy atom_Ar::ionization_energy ("1520.6 kJ/mol");
	const length atom_Ar::covalent_radius = 106_pm;
	const length atom_Ar::van_der_waals_radius = 188_pm;

	const cas_number atom_Ar::cas_number ("7440-37-1");

	ATOM_CPP(atom_Kr)

	const string atom_Kr::name = "Krypton";
	const string atom_Kr::symbol = "Kr";

	const length atom_Kr::atomic_radius = 0_pm;
	const mass atom_Kr::standard_atomic_mass = 84.8_amu;

	const molar_energy atom_Kr::ionization_energy ("1350.8 kJ/mol");
	const length atom_Kr::covalent_radius = 116_pm;
	const length atom_Kr::van_der_waals_radius = 202_pm;

	const cas_number atom_Kr::cas_number ("7439-90-9");

	ATOM_CPP(atom_Xe)

	const string atom_Xe::name = "Xenon";
	const string atom_Xe::symbol = "Xe";

	const length atom_Xe::atomic_radius = 0_pm;
	const mass atom_Xe::standard_atomic_mass = 131.29_amu;

	const molar_energy atom_Xe::ionization_energy ("1170.4 kJ/mol");
	const length atom_Xe::covalent_radius = 140_pm;
	const length atom_Xe::van_der_waals_radius = 216_pm;

	const cas_number atom_Xe::cas_number ("7440-63-3");

	ATOM_CPP(atom_Rn)

	const string atom_Rn::name = "Radon";
	const string atom_Rn::symbol = "Rn";

	const length atom_Rn::atomic_radius = 0_pm;
	const mass atom_Rn::standard_atomic_mass = 222.018_amu;

	const molar_energy atom_Rn::ionization_energy ("1037 kJ/mol");
	const length atom_Rn::covalent_radius = 150_pm;
	const length atom_Rn::van_der_waals_radius = 220_pm;

	const cas_number atom_Rn::cas_number ("10043-92-2");

	ATOM_CPP(atom_Og)

	const string atom_Og::name = "Oganesson";
	const string atom_Og::symbol = "Og";

	const length atom_Og::atomic_radius = 0_pm;
	const mass atom_Og::standard_atomic_mass = 0_amu;

	const molar_energy atom_Og::ionization_energy ("839.4 kJ/mol");
	const length atom_Og::covalent_radius = 157_pm;
	const length atom_Og::van_der_waals_radius = 0_pm;

	const cas_number atom_Og::cas_number ("54144-19-3");
}
