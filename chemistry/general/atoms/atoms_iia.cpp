#include "atoms_iia.hpp"

namespace chemistry
{
    ATOM_CPP(atom_Be)

    const string atom_Be::name = "Beryllium";
    const string atom_Be::symbol = "Be";

    const length atom_Be::atomic_radius = 112_pm;
    const mass atom_Be::standard_atomic_mass = 9.012_amu;

    const molar_energy atom_Be::ionization_energy ("899.5 kJ/mol");
    const length atom_Be::covalent_radius = 96_pm;
    const length atom_Be::van_der_waals_radius = 153_pm;

    const cas_number atom_Be::cas_number ("7440-41-7");

    ATOM_CPP(atom_Mg)

    const string atom_Mg::name = "Magnesium";
    const string atom_Mg::symbol = "Mg";

    const length atom_Mg::atomic_radius = 160_pm;
    const mass atom_Mg::standard_atomic_mass = 24.305_amu;

    const molar_energy atom_Mg::ionization_energy ("737.7 kJ/mol");
    const length atom_Mg::covalent_radius = 141_pm;
    const length atom_Mg::van_der_waals_radius = 173_pm;

    const cas_number atom_Mg::cas_number ("7439-95-4");

    ATOM_CPP(atom_Ca)

    const string atom_Ca::name = "Calcium";
    const string atom_Ca::symbol = "Ca";

    const length atom_Ca::atomic_radius = 197_pm;
    const mass atom_Ca::standard_atomic_mass = 40.078_amu;

    const molar_energy atom_Ca::ionization_energy ("589.8 kJ/mol");
    const length atom_Ca::covalent_radius = 176_pm;
    const length atom_Ca::van_der_waals_radius = 231_pm;

    const cas_number atom_Ca::cas_number ("7440-70-2");

    ATOM_CPP(atom_Sr)

    const string atom_Sr::name = "Strontium";
    const string atom_Sr::symbol = "Sr";

    const length atom_Sr::atomic_radius = 215_pm;
    const mass atom_Sr::standard_atomic_mass = 87.62_amu;

    const molar_energy atom_Sr::ionization_energy ("549.5 kJ/mol");
    const length atom_Sr::covalent_radius = 195_pm;
    const length atom_Sr::van_der_waals_radius = 249_pm;

    const cas_number atom_Sr::cas_number ("7440-24-6");

    ATOM_CPP(atom_Ba)

    const string atom_Ba::name = "Barium";
    const string atom_Ba::symbol = "Ba";

    const length atom_Ba::atomic_radius = 222_pm;
    const mass atom_Ba::standard_atomic_mass = 137.327_amu;

    const molar_energy atom_Ba::ionization_energy ("502.9 kJ/mol");
    const length atom_Ba::covalent_radius = 215_pm;
    const length atom_Ba::van_der_waals_radius = 268_pm;

    const cas_number atom_Ba::cas_number ("7440-39-3");

    ATOM_CPP(atom_Ra)

    const string atom_Ra::name = "Radium";
    const string atom_Ra::symbol = "Ra";

    const length atom_Ra::atomic_radius = 283_pm;
    const mass atom_Ra::standard_atomic_mass = 226.025_amu;

    const molar_energy atom_Ra::ionization_energy ("509.3 kJ/mol");
    const length atom_Ra::covalent_radius = 221_pm;
    const length atom_Ra::van_der_waals_radius = 283_pm;

    const cas_number atom_Ra::cas_number ("7440-14-4");
}
