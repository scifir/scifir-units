#include "atoms_ia.hpp"

namespace msci
{
	ATOM_CPP(atom_H)

	const atom_symbol atom_H::enum_type = atom_symbol::H;

	const string atom_H::name = "Hydrogen";
	const string atom_H::symbol = "H";

	const atomic_group atom_H::group = IA;
	const unsigned int atom_H::period = 1;
	const atomic_block atom_H::block = atomic_block::s;

	const unsigned int atom_H::z = 1;
	const unsigned int atom_H::mass_number = 0;

	const length atom_H::atomic_radius = 1.09_angstrom;
	const mass atom_H::standard_atomic_mass = 1.008_amu;

	const float atom_H::electronegativity = 2.2;
	const bool atom_H::radioactive = false;

	const molar_energy atom_H::ionization_energy ("1312 kJ/mol");
	const length atom_H::covalent_radius = 31_pm;
	const length atom_H::van_der_waals_radius = 120_pm;

	const cas_number atom_H::cas_number ("12385-13-6");

	ATOM_CPP(atom_Li)

	const atom_symbol atom_Li::enum_type = atom_symbol::Li;

	const string atom_Li::name = "Lithium";
	const string atom_Li::symbol = "Li";

	const atomic_group atom_Li::group = IA;
	const unsigned int atom_Li::period = 2;
	const atomic_block atom_Li::block = atomic_block::s;

	const unsigned int atom_Li::z = 3;
	const unsigned int atom_Li::mass_number = 4;

	const length atom_Li::atomic_radius = 152_pm;
	const mass atom_Li::standard_atomic_mass = 6.941_amu;

	const float atom_Li::electronegativity = 0.98;
	const bool atom_Li::radioactive = false;

	const molar_energy atom_Li::ionization_energy ("520.2 kJ/mol");
	const length atom_Li::covalent_radius = 128_pm;
	const length atom_Li::van_der_waals_radius = 182_pm;

	const cas_number atom_Li::cas_number ("7439-93-2");

	ATOM_CPP(atom_Na)

	const atom_symbol atom_Na::enum_type = atom_symbol::Na;

	const string atom_Na::name = "Sodium";
	const string atom_Na::symbol = "Na";

	const atomic_group atom_Na::group = IA;
	const unsigned int atom_Na::period = 3;
	const atomic_block atom_Na::block = atomic_block::s;

	const unsigned int atom_Na::z = 11;
	const unsigned int atom_Na::mass_number = 12;

	const length atom_Na::atomic_radius = 186_pm;
	const mass atom_Na::standard_atomic_mass = 22.99_amu;

	const float atom_Na::electronegativity = 0.93;
	const bool atom_Na::radioactive = false;

	const molar_energy atom_Na::ionization_energy ("495.8 kJ/mol");
	const length atom_Na::covalent_radius = 166_pm;
	const length atom_Na::van_der_waals_radius = 227_pm;

	const cas_number atom_Na::cas_number ("7440-23-5");

	ATOM_CPP(atom_K)

	const atom_symbol atom_K::enum_type = atom_symbol::K;

	const string atom_K::name = "Potassium";
	const string atom_K::symbol = "K";

	const atomic_group atom_K::group = IA;
	const unsigned int atom_K::period = 4;
	const atomic_block atom_K::block = atomic_block::s;

	const unsigned int atom_K::z = 19;
	const unsigned int atom_K::mass_number = 20;

	const length atom_K::atomic_radius = 227_pm;
	const mass atom_K::standard_atomic_mass = 39.098_amu;

	const float atom_K::electronegativity = 0.82;
	const bool atom_K::radioactive = false;

	const molar_energy atom_K::ionization_energy ("418.8 kJ/mol");
	const length atom_K::covalent_radius = 203_pm;
	const length atom_K::van_der_waals_radius = 275_pm;

	const cas_number atom_K::cas_number ("7440-09-7");

	ATOM_CPP(atom_Rb)

	const atom_symbol atom_Rb::enum_type = atom_symbol::Rb;

	const string atom_Rb::name = "Rubidium";
	const string atom_Rb::symbol = "Rb";

	const atomic_group atom_Rb::group = IA;
	const unsigned int atom_Rb::period = 5;
	const atomic_block atom_Rb::block = atomic_block::s;

	const unsigned int atom_Rb::z = 37;
	const unsigned int atom_Rb::mass_number = 47;

	const length atom_Rb::atomic_radius = 248_pm;
	const mass atom_Rb::standard_atomic_mass = 84.468_amu;

	const float atom_Rb::electronegativity = 0.82;
	const bool atom_Rb::radioactive = false;

	const molar_energy atom_Rb::ionization_energy ("403 kJ/mol");
	const length atom_Rb::covalent_radius = 220_pm;
	const length atom_Rb::van_der_waals_radius = 303_pm;

	const cas_number atom_Rb::cas_number ("7440-17-7");

	ATOM_CPP(atom_Cs)

	const atom_symbol atom_Cs::enum_type = atom_symbol::Cs;

	const string atom_Cs::name = "Cesium";
	const string atom_Cs::symbol = "Cs";

	const atomic_group atom_Cs::group = IA;
	const unsigned int atom_Cs::period = 6;
	const atomic_block atom_Cs::block = atomic_block::s;

	const unsigned int atom_Cs::z = 55;
	const unsigned int atom_Cs::mass_number = 78;

	const length atom_Cs::atomic_radius = 265_pm;
	const mass atom_Cs::standard_atomic_mass = 132.905_amu;

	const float atom_Cs::electronegativity = 0.79;
	const bool atom_Cs::radioactive = false;

	const molar_energy atom_Cs::ionization_energy ("375.7 kJ/mol");
	const length atom_Cs::covalent_radius = 244_pm;
	const length atom_Cs::van_der_waals_radius = 343_pm;

	const cas_number atom_Cs::cas_number ("7440-46-2");

	ATOM_CPP(atom_Fr)

	const atom_symbol atom_Fr::enum_type = atom_symbol::Fr;

	const string atom_Fr::name = "Francium";
	const string atom_Fr::symbol = "Fr";

	const atomic_group atom_Fr::group = IA;
	const unsigned int atom_Fr::period = 7;
	const atomic_block atom_Fr::block = atomic_block::s;

	const unsigned int atom_Fr::z = 87;
	const unsigned int atom_Fr::mass_number = 136;

	const length atom_Fr::atomic_radius = 348_pm;
	const mass atom_Fr::standard_atomic_mass = 223.02_amu;

	const float atom_Fr::electronegativity = 0.79;
	const bool atom_Fr::radioactive = false;

	const molar_energy atom_Fr::ionization_energy ("393 kJ/mol");
	const length atom_Fr::covalent_radius = 260_pm;
	const length atom_Fr::van_der_waals_radius = 348_pm;

	const cas_number atom_Fr::cas_number ("7440-73-5");
}
