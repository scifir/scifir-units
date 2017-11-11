#include "atoms_iia.hpp"

namespace msci
{
    ATOM_CPP(atom_Be)

    const atom_symbol atom_Be::enum_type = atom_symbol::Be;

    const string atom_Be::name = "Beryllium";
    const string atom_Be::symbol = "Be";

    const atomic_group atom_Be::group = IIA;
	const unsigned int atom_Be::period = 2;
	const atomic_block atom_Be::block = atomic_block::s;

	const unsigned int atom_Be::z = 4;
	const unsigned int atom_Be::mass_number = 5;

    const length atom_Be::atomic_radius = 112_pm;
    const mass atom_Be::standard_atomic_mass = 9.012_amu;

    const float atom_Be::electronegativity = 1.57;
	const bool atom_Be::radioactive = false;

    const molar_energy atom_Be::ionization_energy ("899.5 kJ/mol");
    const length atom_Be::covalent_radius = 96_pm;
    const length atom_Be::van_der_waals_radius = 153_pm;

    const cas_number atom_Be::cas_number ("7440-41-7");

    ATOM_CPP(atom_Mg)

    const atom_symbol atom_Mg::enum_type = atom_symbol::Mg;

    const string atom_Mg::name = "Magnesium";
    const string atom_Mg::symbol = "Mg";

    const atomic_group atom_Mg::group = IIA;
	const unsigned int atom_Mg::period = 3;
	const atomic_block atom_Mg::block = atomic_block::s;

	const unsigned int atom_Mg::z = 12;
	const unsigned int atom_Mg::mass_number = 12;

    const length atom_Mg::atomic_radius = 160_pm;
    const mass atom_Mg::standard_atomic_mass = 24.305_amu;

    const float atom_Mg::electronegativity = 1.31;
	const bool atom_Mg::radioactive = false;

    const molar_energy atom_Mg::ionization_energy ("737.7 kJ/mol");
    const length atom_Mg::covalent_radius = 141_pm;
    const length atom_Mg::van_der_waals_radius = 173_pm;

    const cas_number atom_Mg::cas_number ("7439-95-4");

    ATOM_CPP(atom_Ca)

    const atom_symbol atom_Ca::enum_type = atom_symbol::Ca;

    const string atom_Ca::name = "Calcium";
    const string atom_Ca::symbol = "Ca";

    const atomic_group atom_Ca::group = IIA;
	const unsigned int atom_Ca::period = 4;
	const atomic_block atom_Ca::block = atomic_block::s;

	const unsigned int atom_Ca::z = 20;
	const unsigned int atom_Ca::mass_number = 20;

    const length atom_Ca::atomic_radius = 197_pm;
    const mass atom_Ca::standard_atomic_mass = 40.078_amu;

    const float atom_Ca::electronegativity = 1;
	const bool atom_Ca::radioactive = false;

    const molar_energy atom_Ca::ionization_energy ("589.8 kJ/mol");
    const length atom_Ca::covalent_radius = 176_pm;
    const length atom_Ca::van_der_waals_radius = 231_pm;

    const cas_number atom_Ca::cas_number ("7440-70-2");

    ATOM_CPP(atom_Sr)

    const atom_symbol atom_Sr::enum_type = atom_symbol::Sr;

    const string atom_Sr::name = "Strontium";
    const string atom_Sr::symbol = "Sr";

    const atomic_group atom_Sr::group = IIA;
	const unsigned int atom_Sr::period = 5;
	const atomic_block atom_Sr::block = atomic_block::s;

	const unsigned int atom_Sr::z = 38;
	const unsigned int atom_Sr::mass_number = 45;

    const length atom_Sr::atomic_radius = 215_pm;
    const mass atom_Sr::standard_atomic_mass = 87.62_amu;

    const float atom_Sr::electronegativity = 0.95;
	const bool atom_Sr::radioactive = false;

    const molar_energy atom_Sr::ionization_energy ("549.5 kJ/mol");
    const length atom_Sr::covalent_radius = 195_pm;
    const length atom_Sr::van_der_waals_radius = 249_pm;

    const cas_number atom_Sr::cas_number ("7440-24-6");

    ATOM_CPP(atom_Ba)

    const atom_symbol atom_Ba::enum_type = atom_symbol::Ba;

    const string atom_Ba::name = "Barium";
    const string atom_Ba::symbol = "Ba";

    const atomic_group atom_Ba::group = IIA;
	const unsigned int atom_Ba::period = 6;
	const atomic_block atom_Ba::block = atomic_block::s;

	const unsigned int atom_Ba::z = 56;
	const unsigned int atom_Ba::mass_number = 81;

    const length atom_Ba::atomic_radius = 222_pm;
    const mass atom_Ba::standard_atomic_mass = 137.327_amu;

    const float atom_Ba::electronegativity = 0.89;
	const bool atom_Ba::radioactive = false;

    const molar_energy atom_Ba::ionization_energy ("502.9 kJ/mol");
    const length atom_Ba::covalent_radius = 215_pm;
    const length atom_Ba::van_der_waals_radius = 268_pm;

    const cas_number atom_Ba::cas_number ("7440-39-3");

    ATOM_CPP(atom_Ra)

    const atom_symbol atom_Ra::enum_type = atom_symbol::Ra;

    const string atom_Ra::name = "Radium";
    const string atom_Ra::symbol = "Ra";

    const atomic_group atom_Ra::group = IIA;
	const unsigned int atom_Ra::period = 7;
	const atomic_block atom_Ra::block = atomic_block::s;

	const unsigned int atom_Ra::z = 88;
	const unsigned int atom_Ra::mass_number = 138;

    const length atom_Ra::atomic_radius = 283_pm;
    const mass atom_Ra::standard_atomic_mass = 226.025_amu;

    const float atom_Ra::electronegativity = 0.9;
	const bool atom_Ra::radioactive = false;

    const molar_energy atom_Ra::ionization_energy ("509.3 kJ/mol");
    const length atom_Ra::covalent_radius = 221_pm;
    const length atom_Ra::van_der_waals_radius = 283_pm;

    const cas_number atom_Ra::cas_number ("7440-14-4");
}
