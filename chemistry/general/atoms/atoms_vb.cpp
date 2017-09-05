#include "atoms_vb.hpp"

namespace chemistry
{
	ATOM_CPP(atom_V)

	const string atom_V::name = "Vanadium";
	const string atom_V::symbol = "V";

	const length atom_V::atomic_radius = 134_pm;
	const mass atom_V::standard_atomic_mass = 50.942_amu;

	const molar_energy atom_V::ionization_energy ("650.9 kJ/mol");
	const length atom_V::covalent_radius = 153_pm;
	const length atom_V::van_der_waals_radius = 0_pm;

	const cas_number atom_V::cas_number ("7440-62-2");

	ATOM_CPP(atom_Nb)

	const string atom_Nb::name = "Niobium";
	const string atom_Nb::symbol = "Nb";

	const length atom_Nb::atomic_radius = 146_pm;
	const mass atom_Nb::standard_atomic_mass = 92.906_amu;

	const molar_energy atom_Nb::ionization_energy ("652.1 kJ/mol");
	const length atom_Nb::covalent_radius = 164_pm;
	const length atom_Nb::van_der_waals_radius = 0_pm;

	const cas_number atom_Nb::cas_number ("7440-03-1");

	ATOM_CPP(atom_Ta)

	const string atom_Ta::name = "Tantalum";
	const string atom_Ta::symbol = "Ta";

	const length atom_Ta::atomic_radius = 146_pm;
	const mass atom_Ta::standard_atomic_mass = 180.948_amu;

	const molar_energy atom_Ta::ionization_energy ("761 kJ/mol");
	const length atom_Ta::covalent_radius = 170_pm;
	const length atom_Ta::van_der_waals_radius = 0_pm;

	const cas_number atom_Ta::cas_number ("7440-25-7");

	ATOM_CPP(atom_Db)

	const string atom_Db::name = "Dubnium";
	const string atom_Db::symbol = "Db";

	const length atom_Db::atomic_radius = 139_pm;
	const mass atom_Db::standard_atomic_mass = 262_amu;

	const molar_energy atom_Db::ionization_energy ("656.1 kJ/mol");
	const length atom_Db::covalent_radius = 149_pm;
	const length atom_Db::van_der_waals_radius = 0_pm;

	const cas_number atom_Db::cas_number ("53850-35-4");
}
