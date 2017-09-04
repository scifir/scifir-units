#include "atoms_iva.hpp"

namespace chemistry
{
	ATOM_CPP(atom_C)

	const string atom_C::name = "Carbon";
	const string atom_C::symbol = "C";

	const length atom_C::atomic_radius = 69_pm;
	const mass atom_C::standard_atomic_mass = 12.011_amu;

	const molar_energy atom_C::ionization_energy ("1086.5 kJ/mol");
	const length atom_C::covalent_radius = 69_pm;
	const length atom_C::van_der_waals_radius = 170_pm;

	const cas_number atom_C::cas_number ("7440-44-0");

	ATOM_CPP(atom_Si)

	const string atom_Si::name = "Silicon";
	const string atom_Si::symbol = "Si";

	const length atom_Si::atomic_radius = 111_pm;
	const mass atom_Si::standard_atomic_mass = 28.086_amu;

	const molar_energy atom_Si::ionization_energy ("786.5 kJ/mol");
	const length atom_Si::covalent_radius = 111_pm;
	const length atom_Si::van_der_waals_radius = 210_pm;

	const cas_number atom_Si::cas_number ("7440-21-3");

	ATOM_CPP(atom_Ge)

	const string atom_Ge::name = "Germanium";
	const string atom_Ge::symbol = "Ge";

	const length atom_Ge::atomic_radius = 122_pm;
	const mass atom_Ge::standard_atomic_mass = 72.61_amu;

	const molar_energy atom_Ge::ionization_energy ("762 kJ/mol");
	const length atom_Ge::covalent_radius = 122_pm;
	const length atom_Ge::van_der_waals_radius = 211_pm;

	const cas_number atom_Ge::cas_number ("7440-56-4");

	ATOM_CPP(atom_Sn)

	const string atom_Sn::name = "Tin";
	const string atom_Sn::symbol = "Sn";

	const length atom_Sn::atomic_radius = 140_pm;
	const mass atom_Sn::standard_atomic_mass = 118.71_amu;

	const molar_energy atom_Sn::ionization_energy ("708.6 kJ/mol");
	const length atom_Sn::covalent_radius = 139_pm;
	const length atom_Sn::van_der_waals_radius = 217_pm;

	const cas_number atom_Sn::cas_number ("7440-31-5");

	ATOM_CPP(atom_Pb)

	const string atom_Pb::name = "Lead";
	const string atom_Pb::symbol = "Pb";

	const length atom_Pb::atomic_radius = 175_pm;
	const mass atom_Pb::standard_atomic_mass = 207.2_amu;

	const molar_energy atom_Pb::ionization_energy ("715.6 kJ/mol");
	const length atom_Pb::covalent_radius = 146_pm;
	const length atom_Pb::van_der_waals_radius = 202_pm;

	const cas_number atom_Pb::cas_number ("7439-92-1");

	ATOM_CPP(atom_Fl)

	const string atom_Fl::name = "Flerovium";
	const string atom_Fl::symbol = "Fl";

	const length atom_Fl::atomic_radius = 180_pm;
	const mass atom_Fl::standard_atomic_mass = 289_amu;

	const molar_energy atom_Fl::ionization_energy ("823.9 kJ/mol");
	const length atom_Fl::covalent_radius = 177_pm;
	const length atom_Fl::van_der_waals_radius = 0_pm;

	const cas_number atom_Fl::cas_number ("54085-16-4");
}
