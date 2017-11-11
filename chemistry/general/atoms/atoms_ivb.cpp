#include "atoms_ivb.hpp"

namespace msci
{
	ATOM_CPP(atom_Ti)

	const atom_symbol atom_Ti::enum_type = atom_symbol::Ti;

	const string atom_Ti::name = "Titanium";
	const string atom_Ti::symbol = "Ti";

	const atomic_group atom_Ti::group = IVB;
	const unsigned int atom_Ti::period = 4;
	const atomic_block atom_Ti::block = atomic_block::d;

	const unsigned int atom_Ti::z = 22;
	const unsigned int atom_Ti::mass_number = 26;

	const length atom_Ti::atomic_radius = 147_pm;
	const mass atom_Ti::standard_atomic_mass = 47.88_amu;

	const float atom_Ti::electronegativity = 1.54;
	const bool atom_Ti::radioactive = false;

	const molar_energy atom_Ti::ionization_energy ("658.8 kJ/mol");
	const length atom_Ti::covalent_radius = 160_pm;
	const length atom_Ti::van_der_waals_radius = 0_pm;

	const cas_number atom_Ti::cas_number ("7440-32-6");

	ATOM_CPP(atom_Zr)

	const atom_symbol atom_Zr::enum_type = atom_symbol::Zr;

	const string atom_Zr::name = "Zirconium";
	const string atom_Zr::symbol = "Zr";

	const atomic_group atom_Zr::group = IVB;
	const unsigned int atom_Zr::period = 5;
	const atomic_block atom_Zr::block = atomic_block::d;

	const unsigned int atom_Zr::z = 40;
	const unsigned int atom_Zr::mass_number = 51;

	const length atom_Zr::atomic_radius = 160_pm;
	const mass atom_Zr::standard_atomic_mass = 91.224_amu;

	const float atom_Zr::electronegativity = 1.33;
	const bool atom_Zr::radioactive = false;

	const molar_energy atom_Zr::ionization_energy ("640.1 kJ/mol");
	const length atom_Zr::covalent_radius = 175_pm;
	const length atom_Zr::van_der_waals_radius = 0_pm;

	const cas_number atom_Zr::cas_number ("7440-67-7");

	ATOM_CPP(atom_Hf)

	const atom_symbol atom_Hf::enum_type = atom_symbol::Hf;

	const string atom_Hf::name = "Hafnium";
	const string atom_Hf::symbol = "Hf";

	const atomic_group atom_Hf::group = IVB;
	const unsigned int atom_Hf::period = 6;
	const atomic_block atom_Hf::block = atomic_block::d;

	const unsigned int atom_Hf::z = 72;
	const unsigned int atom_Hf::mass_number = 106;

	const length atom_Hf::atomic_radius = 159_pm;
	const mass atom_Hf::standard_atomic_mass = 178.49_amu;

	const float atom_Hf::electronegativity = 1.3;
	const bool atom_Hf::radioactive = false;

	const molar_energy atom_Hf::ionization_energy ("658.5 kJ/mol");
	const length atom_Hf::covalent_radius = 175_pm;
	const length atom_Hf::van_der_waals_radius = 0_pm;

	const cas_number atom_Hf::cas_number ("7440-58-6");

	ATOM_CPP(atom_Rf)

	const atom_symbol atom_Rf::enum_type = atom_symbol::Rf;

	const string atom_Rf::name = "Rutherfordium";
	const string atom_Rf::symbol = "Rf";

	const atomic_group atom_Rf::group = IVB;
	const unsigned int atom_Rf::period = 7;
	const atomic_block atom_Rf::block = atomic_block::d;

	const unsigned int atom_Rf::z = 104;
	const unsigned int atom_Rf::mass_number = 163;

	const length atom_Rf::atomic_radius = 150_pm;
	const mass atom_Rf::standard_atomic_mass = 267_amu;

	const float atom_Rf::electronegativity = 0;
	const bool atom_Rf::radioactive = false;

	const molar_energy atom_Rf::ionization_energy ("579.9 kJ/mol");
	const length atom_Rf::covalent_radius = 157_pm;
	const length atom_Rf::van_der_waals_radius = 0_pm;

	const cas_number atom_Rf::cas_number ("53850-36-5");
}
