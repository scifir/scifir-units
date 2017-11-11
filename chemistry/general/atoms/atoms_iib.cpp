#include "atoms_iib.hpp"

namespace msci
{
	ATOM_CPP(atom_Zn)

	const atom_symbol atom_Zn::enum_type = atom_symbol::Zn;

	const string atom_Zn::name = "Zinc";
	const string atom_Zn::symbol = "Zn";

	const atomic_group atom_Zn::group = IIB;
	const unsigned int atom_Zn::period = 4;
	const atomic_block atom_Zn::block = atomic_block::d;

	const unsigned int atom_Zn::z = 30;
	const unsigned int atom_Zn::mass_number = 35;

	const length atom_Zn::atomic_radius = 134_pm;
	const mass atom_Zn::standard_atomic_mass = 65.39_amu;

	const float atom_Zn::electronegativity = 1.65;
	const bool atom_Zn::radioactive = false;

	const molar_energy atom_Zn::ionization_energy ("906.4 kJ/mol");
	const length atom_Zn::covalent_radius = 122_pm;
	const length atom_Zn::van_der_waals_radius = 139_pm;

	const cas_number atom_Zn::cas_number ("7440-66-6");

	ATOM_CPP(atom_Cd)

	const atom_symbol atom_Cd::enum_type = atom_symbol::Cd;

	const string atom_Cd::name = "Cadmium";
	const string atom_Cd::symbol = "Cd";

	const atomic_group atom_Cd::group = IIB;
	const unsigned int atom_Cd::period = 5;
	const atomic_block atom_Cd::block = atomic_block::d;

	const unsigned int atom_Cd::z = 48;
	const unsigned int atom_Cd::mass_number = 64;

	const length atom_Cd::atomic_radius = 151_pm;
	const mass atom_Cd::standard_atomic_mass = 112.411_amu;

	const float atom_Cd::electronegativity = 1.69;
	const bool atom_Cd::radioactive = false;

	const molar_energy atom_Cd::ionization_energy ("867.8 kJ/mol");
	const length atom_Cd::covalent_radius = 144_pm;
	const length atom_Cd::van_der_waals_radius = 158_pm;

	const cas_number atom_Cd::cas_number ("7440-43-9");

	ATOM_CPP(atom_Hg)

	const atom_symbol atom_Hg::enum_type = atom_symbol::Hg;

	const string atom_Hg::name = "Mercury";
	const string atom_Hg::symbol = "Hg";

	const atomic_group atom_Hg::group = IIB;
	const unsigned int atom_Hg::period = 6;
	const atomic_block atom_Hg::block = atomic_block::d;

	const unsigned int atom_Hg::z = 80;
	const unsigned int atom_Hg::mass_number = 121;

	const length atom_Hg::atomic_radius = 151_pm;
	const mass atom_Hg::standard_atomic_mass = 200.59_amu;

	const float atom_Hg::electronegativity = 2.00;
	const bool atom_Hg::radioactive = false;

	const molar_energy atom_Hg::ionization_energy ("1007.1 kJ/mol");
	const length atom_Hg::covalent_radius = 132_pm;
	const length atom_Hg::van_der_waals_radius = 155_pm;

	const cas_number atom_Hg::cas_number ("7439-97-6");

	ATOM_CPP(atom_Cn)

	const atom_symbol atom_Cn::enum_type = atom_symbol::Cn;

	const string atom_Cn::name = "Copernicium";
	const string atom_Cn::symbol = "Cn";

	const atomic_group atom_Cn::group = IIB;
	const unsigned int atom_Cn::period = 7;
	const atomic_block atom_Cn::block = atomic_block::d;

	const unsigned int atom_Cn::z = 112;
	const unsigned int atom_Cn::mass_number = 173;

	const length atom_Cn::atomic_radius = 147_pm;
	const mass atom_Cn::standard_atomic_mass = 285_amu;

	const float atom_Cn::electronegativity = 0;
	const bool atom_Cn::radioactive = false;

	const molar_energy atom_Cn::ionization_energy ("1154.9 kJ/mol");
	const length atom_Cn::covalent_radius = 122_pm;
	const length atom_Cn::van_der_waals_radius = 0_pm;

	const cas_number atom_Cn::cas_number ("54084-26-3");
}
