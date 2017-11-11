#include "atoms_iva.hpp"

namespace msci
{
	ATOM_CPP(atom_C)

	const atom_symbol atom_C::enum_type = atom_symbol::C;

	const string atom_C::name = "Carbon";
	const string atom_C::symbol = "C";

	const atomic_group atom_C::group = IVA;
	const unsigned int atom_C::period = 2;
	const atomic_block atom_C::block = atomic_block::p;

	const unsigned int atom_C::z = 6;
	const unsigned int atom_C::mass_number = 6;

	const length atom_C::atomic_radius = 69_pm;
	const mass atom_C::standard_atomic_mass = 12.011_amu;

	const float atom_C::electronegativity = 2.55;
	const bool atom_C::radioactive = false;

	const molar_energy atom_C::ionization_energy ("1086.5 kJ/mol");
	const length atom_C::covalent_radius = 69_pm;
	const length atom_C::van_der_waals_radius = 170_pm;

	const cas_number atom_C::cas_number ("7440-44-0");

	ATOM_CPP(atom_Si)

	const atom_symbol atom_Si::enum_type = atom_symbol::Si;

	const string atom_Si::name = "Silicon";
	const string atom_Si::symbol = "Si";

	const atomic_group atom_Si::group = IVA;
	const unsigned int atom_Si::period = 3;
	const atomic_block atom_Si::block = atomic_block::p;

	const unsigned int atom_Si::z = 14;
	const unsigned int atom_Si::mass_number = 14;

	const length atom_Si::atomic_radius = 111_pm;
	const mass atom_Si::standard_atomic_mass = 28.086_amu;

	const float atom_Si::electronegativity = 1.90;
	const bool atom_Si::radioactive = false;

	const molar_energy atom_Si::ionization_energy ("786.5 kJ/mol");
	const length atom_Si::covalent_radius = 111_pm;
	const length atom_Si::van_der_waals_radius = 210_pm;

	const cas_number atom_Si::cas_number ("7440-21-3");

	ATOM_CPP(atom_Ge)

	const atom_symbol atom_Ge::enum_type = atom_symbol::Ge;

	const string atom_Ge::name = "Germanium";
	const string atom_Ge::symbol = "Ge";

	const atomic_group atom_Ge::group = IVA;
	const unsigned int atom_Ge::period = 4;
	const atomic_block atom_Ge::block = atomic_block::p;

	const unsigned int atom_Ge::z = 32;
	const unsigned int atom_Ge::mass_number = 41;

	const length atom_Ge::atomic_radius = 122_pm;
	const mass atom_Ge::standard_atomic_mass = 72.61_amu;

	const float atom_Ge::electronegativity = 2.01;
	const bool atom_Ge::radioactive = false;

	const molar_energy atom_Ge::ionization_energy ("762 kJ/mol");
	const length atom_Ge::covalent_radius = 122_pm;
	const length atom_Ge::van_der_waals_radius = 211_pm;

	const cas_number atom_Ge::cas_number ("7440-56-4");

	ATOM_CPP(atom_Sn)

	const atom_symbol atom_Sn::enum_type = atom_symbol::Sn;

	const string atom_Sn::name = "Tin";
	const string atom_Sn::symbol = "Sn";

	const atomic_group atom_Sn::group = IVA;
	const unsigned int atom_Sn::period = 5;
	const atomic_block atom_Sn::block = atomic_block::p;

	const unsigned int atom_Sn::z = 50;
	const unsigned int atom_Sn::mass_number = 69;

	const length atom_Sn::atomic_radius = 140_pm;
	const mass atom_Sn::standard_atomic_mass = 118.71_amu;

	const float atom_Sn::electronegativity = 1.96;
	const bool atom_Sn::radioactive = false;

	const molar_energy atom_Sn::ionization_energy ("708.6 kJ/mol");
	const length atom_Sn::covalent_radius = 139_pm;
	const length atom_Sn::van_der_waals_radius = 217_pm;

	const cas_number atom_Sn::cas_number ("7440-31-5");

	ATOM_CPP(atom_Pb)

	const atom_symbol atom_Pb::enum_type = atom_symbol::Pb;

	const string atom_Pb::name = "Lead";
	const string atom_Pb::symbol = "Pb";

	const atomic_group atom_Pb::group = IVA;
	const unsigned int atom_Pb::period = 6;
	const atomic_block atom_Pb::block = atomic_block::p;

	const unsigned int atom_Pb::z = 82;
	const unsigned int atom_Pb::mass_number = 125;

	const length atom_Pb::atomic_radius = 175_pm;
	const mass atom_Pb::standard_atomic_mass = 207.2_amu;

	const float atom_Pb::electronegativity = 1.87;
	const bool atom_Pb::radioactive = false;

	const molar_energy atom_Pb::ionization_energy ("715.6 kJ/mol");
	const length atom_Pb::covalent_radius = 146_pm;
	const length atom_Pb::van_der_waals_radius = 202_pm;

	const cas_number atom_Pb::cas_number ("7439-92-1");

	ATOM_CPP(atom_Fl)

	const atom_symbol atom_Fl::enum_type = atom_symbol::Fl;

	const string atom_Fl::name = "Flerovium";
	const string atom_Fl::symbol = "Fl";

	const atomic_group atom_Fl::group = IVA;
	const unsigned int atom_Fl::period = 7;
	const atomic_block atom_Fl::block = atomic_block::p;

	const unsigned int atom_Fl::z = 114;
	const unsigned int atom_Fl::mass_number = 175;

	const length atom_Fl::atomic_radius = 180_pm;
	const mass atom_Fl::standard_atomic_mass = 289_amu;

	const float atom_Fl::electronegativity = 0;
	const bool atom_Fl::radioactive = false;

	const molar_energy atom_Fl::ionization_energy ("823.9 kJ/mol");
	const length atom_Fl::covalent_radius = 177_pm;
	const length atom_Fl::van_der_waals_radius = 0_pm;

	const cas_number atom_Fl::cas_number ("54085-16-4");
}
