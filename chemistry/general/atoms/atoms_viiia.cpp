#include "atoms_viiia.hpp"

namespace msci
{
	ATOM_CPP(atom_He)

	const atom_symbol atom_He::enum_type = atom_symbol::He;

	const string atom_He::name = "Helium";
	const string atom_He::symbol = "He";

	const atomic_group atom_He::group = VIIIA;
	const unsigned int atom_He::period = 1;
	const atomic_block atom_He::block = atomic_block::s;

	const unsigned int atom_He::z = 2;
	const unsigned int atom_He::mass_number = 2;

	const length atom_He::atomic_radius = 0_m;
	const mass atom_He::standard_atomic_mass = 4.003_amu;

	const float atom_He::electronegativity = 0;
	const bool atom_He::radioactive = false;

	const molar_energy atom_He::ionization_energy ("2372.3 kJ/mol");
	const length atom_He::covalent_radius = 28_pm;
	const length atom_He::van_der_waals_radius = 140_pm;

	const cas_number atom_He::cas_number ("7440-59-7");

	ATOM_CPP(atom_Ne)

	const atom_symbol atom_Ne::enum_type = atom_symbol::Ne;

	const string atom_Ne::name = "Neon";
	const string atom_Ne::symbol = "Ne";

	const atomic_group atom_Ne::group = VIIIA;
	const unsigned int atom_Ne::period = 2;
	const atomic_block atom_Ne::block = atomic_block::p;

	const unsigned int atom_Ne::z = 10;
	const unsigned int atom_Ne::mass_number = 10;

	const length atom_Ne::atomic_radius = 0_pm;
	const mass atom_Ne::standard_atomic_mass = 20.180_amu;

	const float atom_Ne::electronegativity = 0;
	const bool atom_Ne::radioactive = false;

	const molar_energy atom_Ne::ionization_energy ("2080.7 kJ/mol");
	const length atom_Ne::covalent_radius = 58_pm;
	const length atom_Ne::van_der_waals_radius = 154_pm;

	const cas_number atom_Ne::cas_number ("7440-01-9");

	ATOM_CPP(atom_Ar)

	const atom_symbol atom_Ar::enum_type = atom_symbol::Ar;

	const string atom_Ar::name = "Argon";
	const string atom_Ar::symbol = "Ar";

	const atomic_group atom_Ar::group = VIIIA;
	const unsigned int atom_Ar::period = 3;
	const atomic_block atom_Ar::block = atomic_block::p;

	const unsigned int atom_Ar::z = 18;
	const unsigned int atom_Ar::mass_number = 22;

	const length atom_Ar::atomic_radius = 0_pm;
	const mass atom_Ar::standard_atomic_mass = 39.948_amu;

	const float atom_Ar::electronegativity = 0;
	const bool atom_Ar::radioactive = false;

	const molar_energy atom_Ar::ionization_energy ("1520.6 kJ/mol");
	const length atom_Ar::covalent_radius = 106_pm;
	const length atom_Ar::van_der_waals_radius = 188_pm;

	const cas_number atom_Ar::cas_number ("7440-37-1");

	ATOM_CPP(atom_Kr)

	const atom_symbol atom_Kr::enum_type = atom_symbol::Kr;

	const string atom_Kr::name = "Krypton";
	const string atom_Kr::symbol = "Kr";

	const atomic_group atom_Kr::group = VIIIA;
	const unsigned int atom_Kr::period = 4;
	const atomic_block atom_Kr::block = atomic_block::p;

	const unsigned int atom_Kr::z = 36;
	const unsigned int atom_Kr::mass_number = 49;

	const length atom_Kr::atomic_radius = 0_pm;
	const mass atom_Kr::standard_atomic_mass = 84.8_amu;

	const float atom_Kr::electronegativity = 3.00;
	const bool atom_Kr::radioactive = false;

	const molar_energy atom_Kr::ionization_energy ("1350.8 kJ/mol");
	const length atom_Kr::covalent_radius = 116_pm;
	const length atom_Kr::van_der_waals_radius = 202_pm;

	const cas_number atom_Kr::cas_number ("7439-90-9");

	ATOM_CPP(atom_Xe)

	const atom_symbol atom_Xe::enum_type = atom_symbol::Xe;

	const string atom_Xe::name = "Xenon";
	const string atom_Xe::symbol = "Xe";

	const atomic_group atom_Xe::group = VIIIA;
	const unsigned int atom_Xe::period = 5;
	const atomic_block atom_Xe::block = atomic_block::p;

	const unsigned int atom_Xe::z = 54;
	const unsigned int atom_Xe::mass_number = 77;

	const length atom_Xe::atomic_radius = 0_pm;
	const mass atom_Xe::standard_atomic_mass = 131.29_amu;

	const float atom_Xe::electronegativity = 2.6;
	const bool atom_Xe::radioactive = false;

	const molar_energy atom_Xe::ionization_energy ("1170.4 kJ/mol");
	const length atom_Xe::covalent_radius = 140_pm;
	const length atom_Xe::van_der_waals_radius = 216_pm;

	const cas_number atom_Xe::cas_number ("7440-63-3");

	ATOM_CPP(atom_Rn)

	const atom_symbol atom_Rn::enum_type = atom_symbol::Rn;

	const string atom_Rn::name = "Radon";
	const string atom_Rn::symbol = "Rn";

	const atomic_group atom_Rn::group = VIIIA;
	const unsigned int atom_Rn::period = 6;
	const atomic_block atom_Rn::block = atomic_block::p;

	const unsigned int atom_Rn::z = 86;
	const unsigned int atom_Rn::mass_number = 136;

	const length atom_Rn::atomic_radius = 0_pm;
	const mass atom_Rn::standard_atomic_mass = 222.018_amu;

	const float atom_Rn::electronegativity = 2.2;
	const bool atom_Rn::radioactive = false;

	const molar_energy atom_Rn::ionization_energy ("1037 kJ/mol");
	const length atom_Rn::covalent_radius = 150_pm;
	const length atom_Rn::van_der_waals_radius = 220_pm;

	const cas_number atom_Rn::cas_number ("10043-92-2");

	ATOM_CPP(atom_Og)

	const atom_symbol atom_Og::enum_type = atom_symbol::Og;

	const string atom_Og::name = "Oganesson";
	const string atom_Og::symbol = "Og";

	const atomic_group atom_Og::group = VIIIA;
	const unsigned int atom_Og::period = 7;
	const atomic_block atom_Og::block = atomic_block::p;

	const unsigned int atom_Og::z = 118;
	const unsigned int atom_Og::mass_number = 176;

	const length atom_Og::atomic_radius = 0_pm;
	const mass atom_Og::standard_atomic_mass = 0_amu;

	const float atom_Og::electronegativity = 0;
	const bool atom_Og::radioactive = false;

	const molar_energy atom_Og::ionization_energy ("839.4 kJ/mol");
	const length atom_Og::covalent_radius = 157_pm;
	const length atom_Og::van_der_waals_radius = 0_pm;

	const cas_number atom_Og::cas_number ("54144-19-3");
}
