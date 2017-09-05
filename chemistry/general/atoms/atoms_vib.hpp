#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_VIB_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_VIB_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace chemistry
{
	class atom_Cr : public normal_atom<atom_Cr>
	{
		public:
			ATOM_HPP(atom_Cr);

			static const atom_symbol enum_type = atom_symbol::Cr;

			static const string name;
			static const string symbol;

			static const atomic_group group = VIB;
			static const int period = 4;
			static const atomic_block block = atomic_block::d;

			static const int z = 24;
			static const int mass_number = 28;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.66;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Mo : public normal_atom<atom_Mo>
	{
		public:
			ATOM_HPP(atom_Mo);

			static const atom_symbol enum_type = atom_symbol::Mo;

			static const string name;
			static const string symbol;

			static const atomic_group group = VIB;
			static const int period = 5;
			static const atomic_block block = atomic_block::d;

			static const int z = 42;
			static const int mass_number = 54;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.16;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_W : public normal_atom<atom_W>
	{
		public:
			ATOM_HPP(atom_W);

			static const atom_symbol enum_type = atom_symbol::W;

			static const string name;
			static const string symbol;

			static const atomic_group group = VIB;
			static const int period = 6;
			static const atomic_block block = atomic_block::d;

			static const int z = 74;
			static const int mass_number = 110;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.36;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Sg : public normal_atom<atom_Sg>
	{
		public:
			ATOM_HPP(atom_Sg);

			static const atom_symbol enum_type = atom_symbol::Sg;

			static const string name;
			static const string symbol;

			static const atomic_group group = VIB;
			static const int period = 7;
			static const atomic_block block = atomic_block::d;

			static const int z = 106;
			static const int mass_number = 160;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};
}

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_VIB_HPP
