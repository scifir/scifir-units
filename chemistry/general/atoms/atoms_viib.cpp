#include "atoms_viib.hpp"

namespace msci
{
	ATOM_CPP(atom_Mn)

	const atom_symbol atom_Mn::enum_type = atom_symbol::Mn;

	const string atom_Mn::name = "Manganese";
	const string atom_Mn::symbol = "Mn";

	const atomic_group atom_Mn::group = VIIB;
	const unsigned int atom_Mn::period = 4;
	const atomic_block atom_Mn::block = atomic_block::d;

	const unsigned int atom_Mn::z = 25;
	const unsigned int atom_Mn::mass_number = 30;

	const length atom_Mn::atomic_radius = 127_pm;
	const mass atom_Mn::standard_atomic_mass = 54.938_amu;

	const float atom_Mn::electronegativity = 1.55;
	const bool atom_Mn::radioactive = false;

	const molar_energy atom_Mn::ionization_energy ("717.3 kJ/mol");
	const length atom_Mn::covalent_radius = 139_pm;
	const length atom_Mn::van_der_waals_radius = 0_pm;

	const cas_number atom_Mn::cas_number ("7439-96-5");

	ATOM_CPP(atom_Tc)

	const atom_symbol atom_Tc::enum_type = atom_symbol::Tc;

	const string atom_Tc::name = "Technetium";
	const string atom_Tc::symbol = "Tc";

	const atomic_group atom_Tc::group = VIIB;
	const unsigned int atom_Tc::period = 5;
	const atomic_block atom_Tc::block = atomic_block::d;

	const unsigned int atom_Tc::z = 43;
	const unsigned int atom_Tc::mass_number = 56;

	const length atom_Tc::atomic_radius = 136_pm;
	const mass atom_Tc::standard_atomic_mass = 98.907_amu;

	const float atom_Tc::electronegativity = 1.9;
	const bool atom_Tc::radioactive = false;

	const molar_energy atom_Tc::ionization_energy ("702 kJ/mol");
	const length atom_Tc::covalent_radius = 147_pm;
	const length atom_Tc::van_der_waals_radius = 0_pm;

	const cas_number atom_Tc::cas_number ("7440-26-8");

	ATOM_CPP(atom_Re)

	const atom_symbol atom_Re::enum_type = atom_symbol::Re;

	const string atom_Re::name = "Rhenium";
	const string atom_Re::symbol = "Re";

	const atomic_group atom_Re::group = VIIB;
	const unsigned int atom_Re::period = 6;
	const atomic_block atom_Re::block = atomic_block::d;

	const unsigned int atom_Re::z = 75;
	const unsigned int atom_Re::mass_number = 111;

	const length atom_Re::atomic_radius = 137_pm;
	const mass atom_Re::standard_atomic_mass = 186.207_amu;

	const float atom_Re::electronegativity = 1.9;
	const bool atom_Re::radioactive = false;

	const molar_energy atom_Re::ionization_energy ("760 kJ/mol");
	const length atom_Re::covalent_radius = 151_pm;
	const length atom_Re::van_der_waals_radius = 0_pm;

	const cas_number atom_Re::cas_number ("7440-15-5");

	ATOM_CPP(atom_Bh)

	const atom_symbol atom_Bh::enum_type = atom_symbol::Bh;

	const string atom_Bh::name = "Bohrium";
	const string atom_Bh::symbol = "Bh";

	const atomic_group atom_Bh::group = VIIB;
	const unsigned int atom_Bh::period = 7;
	const atomic_block atom_Bh::block = atomic_block::d;

	const unsigned int atom_Bh::z = 107;
	const unsigned int atom_Bh::mass_number = 157;

	const length atom_Bh::atomic_radius = 128_pm;
	const mass atom_Bh::standard_atomic_mass = 264_amu;

	const float atom_Bh::electronegativity = 0;
	const bool atom_Bh::radioactive = false;

	const molar_energy atom_Bh::ionization_energy ("742.9 kJ/mol");
	const length atom_Bh::covalent_radius = 141_pm;
	const length atom_Bh::van_der_waals_radius = 0_pm;

	const cas_number atom_Bh::cas_number ("54037-14-8");
}
