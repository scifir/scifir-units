#include "atoms_vb.hpp"

namespace msci
{
	ATOM_CPP(atom_V)

	const atom_symbol atom_V::enum_type = atom_symbol::V;

	const string atom_V::name = "Vanadium";
	const string atom_V::symbol = "V";

	const atomic_group atom_V::group = VB;
	const unsigned int atom_V::period = 4;
	const atomic_block atom_V::block = atomic_block::d;

	const unsigned int atom_V::z = 23;
	const unsigned int atom_V::mass_number = 28;

	const length atom_V::atomic_radius = 134_pm;
	const mass atom_V::standard_atomic_mass = 50.942_amu;

	const float atom_V::electronegativity = 1.63;
	const bool atom_V::radioactive = false;

	const molar_energy atom_V::ionization_energy ("650.9 kJ/mol");
	const length atom_V::covalent_radius = 153_pm;
	const length atom_V::van_der_waals_radius = 0_pm;

	const cas_number atom_V::cas_number ("7440-62-2");

	ATOM_CPP(atom_Nb)

	const atom_symbol atom_Nb::enum_type = atom_symbol::Nb;

	const string atom_Nb::name = "Niobium";
	const string atom_Nb::symbol = "Nb";

	const atomic_group atom_Nb::group = VB;
	const unsigned int atom_Nb::period = 5;
	const atomic_block atom_Nb::block = atomic_block::d;

	const unsigned int atom_Nb::z = 41;
	const unsigned int atom_Nb::mass_number = 52;

	const length atom_Nb::atomic_radius = 146_pm;
	const mass atom_Nb::standard_atomic_mass = 92.906_amu;

	const float atom_Nb::electronegativity = 1.6;
	const bool atom_Nb::radioactive = false;

	const molar_energy atom_Nb::ionization_energy ("652.1 kJ/mol");
	const length atom_Nb::covalent_radius = 164_pm;
	const length atom_Nb::van_der_waals_radius = 0_pm;

	const cas_number atom_Nb::cas_number ("7440-03-1");

	ATOM_CPP(atom_Ta)

	const atom_symbol atom_Ta::enum_type = atom_symbol::Ta;

	const string atom_Ta::name = "Tantalum";
	const string atom_Ta::symbol = "Ta";

	const atomic_group atom_Ta::group = VB;
	const unsigned int atom_Ta::period = 6;
	const atomic_block atom_Ta::block = atomic_block::d;

	const unsigned int atom_Ta::z = 73;
	const unsigned int atom_Ta::mass_number = 108;

	const length atom_Ta::atomic_radius = 146_pm;
	const mass atom_Ta::standard_atomic_mass = 180.948_amu;

	const float atom_Ta::electronegativity = 1.5;
	const bool atom_Ta::radioactive = false;

	const molar_energy atom_Ta::ionization_energy ("761 kJ/mol");
	const length atom_Ta::covalent_radius = 170_pm;
	const length atom_Ta::van_der_waals_radius = 0_pm;

	const cas_number atom_Ta::cas_number ("7440-25-7");

	ATOM_CPP(atom_Db)

	const atom_symbol atom_Db::enum_type = atom_symbol::Db;

	const string atom_Db::name = "Dubnium";
	const string atom_Db::symbol = "Db";

	const atomic_group atom_Db::group = VB;
	const unsigned int atom_Db::period = 7;
	const atomic_block atom_Db::block = atomic_block::d;

	const unsigned int atom_Db::z = 105;
	const unsigned int atom_Db::mass_number = 157;

	const length atom_Db::atomic_radius = 139_pm;
	const mass atom_Db::standard_atomic_mass = 262_amu;

	const float atom_Db::electronegativity = 0;
	const bool atom_Db::radioactive = false;

	const molar_energy atom_Db::ionization_energy ("656.1 kJ/mol");
	const length atom_Db::covalent_radius = 149_pm;
	const length atom_Db::van_der_waals_radius = 0_pm;

	const cas_number atom_Db::cas_number ("53850-35-4");
}
