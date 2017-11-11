#include "atoms_via.hpp"

namespace msci
{
	ATOM_CPP(atom_O)

	const atom_symbol atom_O::enum_type = atom_symbol::O;

	const string atom_O::name = "Oxygen";
	const string atom_O::symbol = "O";

	const atomic_group atom_O::group = VIA;
	const unsigned int atom_O::period = 2;
	const atomic_block atom_O::block = atomic_block::p;

	const unsigned int atom_O::z = 8;
	const unsigned int atom_O::mass_number = 8;

	const length atom_O::atomic_radius = 60_pm;
	const mass atom_O::standard_atomic_mass = 15.999_amu;

	const float atom_O::electronegativity = 3.44;
	const bool atom_O::radioactive = false;

	const molar_energy atom_O::ionization_energy ("1313.9 kJ/mol");
	const length atom_O::covalent_radius = 66_pm;
	const length atom_O::van_der_waals_radius = 152_pm;

	const cas_number atom_O::cas_number ("7782-44-7");

	ATOM_CPP(atom_S)

	const atom_symbol atom_S::enum_type = atom_symbol::S;

	const string atom_S::name = "Sulfur";
	const string atom_S::symbol = "S";

	const atomic_group atom_S::group = VIA;
	const unsigned int atom_S::period = 3;
	const atomic_block atom_S::block = atomic_block::p;

	const unsigned int atom_S::z = 16;
	const unsigned int atom_S::mass_number = 16;

	const length atom_S::atomic_radius = 100_pm;
	const mass atom_S::standard_atomic_mass = 32.066_amu;

	const float atom_S::electronegativity = 2.58;
	const bool atom_S::radioactive = false;

	const molar_energy atom_S::ionization_energy ("999.6 kJ/mol");
	const length atom_S::covalent_radius = 105_pm;
	const length atom_S::van_der_waals_radius = 180_pm;

	const cas_number atom_S::cas_number ("7704-34-9");

	ATOM_CPP(atom_Se)

	const atom_symbol atom_Se::enum_type = atom_symbol::Se;

	const string atom_Se::name = "Selenium";
	const string atom_Se::symbol = "Se";

	const atomic_group atom_Se::group = VIA;
	const unsigned int atom_Se::period = 4;
	const atomic_block atom_Se::block = atomic_block::p;

	const unsigned int atom_Se::z = 34;
	const unsigned int atom_Se::mass_number = 45;

	const length atom_Se::atomic_radius = 120_pm;
	const mass atom_Se::standard_atomic_mass = 78.972_amu;

	const float atom_Se::electronegativity = 2.55;
	const bool atom_Se::radioactive = false;

	const molar_energy atom_Se::ionization_energy ("941.0 kJ/mol");
	const length atom_Se::covalent_radius = 120_pm;
	const length atom_Se::van_der_waals_radius = 190_pm;

	const cas_number atom_Se::cas_number ("7782-49-2");

	ATOM_CPP(atom_Te)

	const atom_symbol atom_Te::enum_type = atom_symbol::Te;

	const string atom_Te::name = "Tellurium";
	const string atom_Te::symbol = "Te";

	const atomic_group atom_Te::group = VIA;
	const unsigned int atom_Te::period = 5;
	const atomic_block atom_Te::block = atomic_block::p;

	const unsigned int atom_Te::z = 52;
	const unsigned int atom_Te::mass_number = 76;

	const length atom_Te::atomic_radius = 140_pm;
	const mass atom_Te::standard_atomic_mass = 127.6_amu;

	const float atom_Te::electronegativity = 2.1;
	const bool atom_Te::radioactive = false;

	const molar_energy atom_Te::ionization_energy ("869.3 kJ/mol");
	const length atom_Te::covalent_radius = 138_pm;
	const length atom_Te::van_der_waals_radius = 206_pm;

	const cas_number atom_Te::cas_number ("13494-80-9");

	ATOM_CPP(atom_Po)

	const atom_symbol atom_Po::enum_type = atom_symbol::Po;

	const string atom_Po::name = "Polonium";
	const string atom_Po::symbol = "Po";

	const atomic_group atom_Po::group = VIA;
	const unsigned int atom_Po::period = 6;
	const atomic_block atom_Po::block = atomic_block::p;

	const unsigned int atom_Po::z = 84;
	const unsigned int atom_Po::mass_number = 125;

	const length atom_Po::atomic_radius = 168_pm;
	const mass atom_Po::standard_atomic_mass = 208.982_amu;

	const float atom_Po::electronegativity = 2.0;
	const bool atom_Po::radioactive = false;

	const molar_energy atom_Po::ionization_energy ("812.1 kJ/mol");
	const length atom_Po::covalent_radius = 140_pm;
	const length atom_Po::van_der_waals_radius = 197_pm;

	const cas_number atom_Po::cas_number ("7440-08-6");

	ATOM_CPP(atom_Lv)

	const atom_symbol atom_Lv::enum_type = atom_symbol::Lv;

	const string atom_Lv::name = "Livermorium";
	const string atom_Lv::symbol = "Lv";

	const atomic_group atom_Lv::group = VIA;
	const unsigned int atom_Lv::period = 7;
	const atomic_block atom_Lv::block = atomic_block::p;

	const unsigned int atom_Lv::z = 116;
	const unsigned int atom_Lv::mass_number = 177;

	const length atom_Lv::atomic_radius = 183_pm;
	const mass atom_Lv::standard_atomic_mass = 298_amu;

	const float atom_Lv::electronegativity = 0;
	const bool atom_Lv::radioactive = false;

	const molar_energy atom_Lv::ionization_energy ("723.6 kJ/mol");
	const length atom_Lv::covalent_radius = 162_pm;
	const length atom_Lv::van_der_waals_radius = 0_pm;

	const cas_number atom_Lv::cas_number ("54100-71-9");
}
