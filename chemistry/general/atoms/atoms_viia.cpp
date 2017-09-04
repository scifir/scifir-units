#include "atoms_viia.hpp"

namespace chemistry
{
	ATOM_CPP(atom_F)

	const string atom_F::name = "Fluorine";
	const string atom_F::symbol = "F";

	const length atom_F::atomic_radius = 50_pm;
	const mass atom_F::standard_atomic_mass = 18.998_amu;

	const molar_energy atom_F::ionization_energy ("1681 kJ/mol");
	const length atom_F::covalent_radius = 64_pm;
	const length atom_F::van_der_waals_radius = 135_pm;

	const cas_number atom_F::cas_number ("7782-41-4");

	ATOM_CPP(atom_Cl)

	const string atom_Cl::name = "Chlorine";
	const string atom_Cl::symbol = "Cl";

	const length atom_Cl::atomic_radius = 100_pm;
	const mass atom_Cl::standard_atomic_mass = 35.453_amu;

	const molar_energy atom_Cl::ionization_energy ("1251.2 kJ/mol");
	const length atom_Cl::covalent_radius = 102_pm;
	const length atom_Cl::van_der_waals_radius = 175_pm;

	const cas_number atom_Cl::cas_number ("7782-50-5");

	ATOM_CPP(atom_Br)

	const string atom_Br::name = "Bromine";
	const string atom_Br::symbol = "Br";

	const length atom_Br::atomic_radius = 120_pm;
	const mass atom_Br::standard_atomic_mass = 79.904_amu;

	const molar_energy atom_Br::ionization_energy ("1139.9 kJ/mol");
	const length atom_Br::covalent_radius = 120_pm;
	const length atom_Br::van_der_waals_radius = 185_pm;

	const cas_number atom_Br::cas_number ("7726-95-6");

	ATOM_CPP(atom_I)

	const string atom_I::name = "Iodine";
	const string atom_I::symbol = "I";

	const length atom_I::atomic_radius = 140_pm;
	const mass atom_I::standard_atomic_mass = 126.904_amu;

	const molar_energy atom_I::ionization_energy ("1008.4 kJ/mol");
	const length atom_I::covalent_radius = 139_pm;
	const length atom_I::van_der_waals_radius = 198_pm;

	const cas_number atom_I::cas_number ("7553-56-2");

	ATOM_CPP(atom_At)

	const string atom_At::name = "Astatine";
	const string atom_At::symbol = "At";

	const length atom_At::atomic_radius = 0_pm;
	const mass atom_At::standard_atomic_mass = 209.987_amu;

	const molar_energy atom_At::ionization_energy ("899.003 kJ/mol");
	const length atom_At::covalent_radius = 150_pm;
	const length atom_At::van_der_waals_radius = 202_pm;

	const cas_number atom_At::cas_number ("7440-68-8");

	ATOM_CPP(atom_Ts)

	const string atom_Ts::name = "Tennessine";
	const string atom_Ts::symbol = "Ts";

	const length atom_Ts::atomic_radius = 0_pm;
	const mass atom_Ts::standard_atomic_mass = 0_amu;

	const molar_energy atom_Ts::ionization_energy ("742.9 kJ/mol");
	const length atom_Ts::covalent_radius = 156_pm;
	const length atom_Ts::van_der_waals_radius = 0_pm;

	const cas_number atom_Ts::cas_number ("54101-14-3");
}
