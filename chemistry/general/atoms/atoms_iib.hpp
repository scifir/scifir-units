#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_IIB_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_IIB_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace chemistry
{
	class atom_Zn : public normal_atom<atom_Zn>
	{
		public:
			ATOM_HPP(atom_Zn);

			static const atom_symbol enum_type = atom_symbol::Zn;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIB;
			static const int period = 4;
			static const atomic_block block = atomic_block::d;

			static const int z = 30;
			static const int mass_number = 35;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.65;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Cd : public normal_atom<atom_Cd>
	{
		public:
			ATOM_HPP(atom_Cd);

			static const atom_symbol enum_type = atom_symbol::Cd;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIB;
			static const int period = 5;
			static const atomic_block block = atomic_block::d;

			static const int z = 48;
			static const int mass_number = 64;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.69;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Hg : public normal_atom<atom_Hg>
	{
		public:
			ATOM_HPP(atom_Hg);

			static const atom_symbol enum_type = atom_symbol::Hg;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIB;
			static const int period = 6;
			static const atomic_block block = atomic_block::d;

			static const int z = 80;
			static const int mass_number = 121;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.00;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Cn : public normal_atom<atom_Cn>
	{
		public:
			ATOM_HPP(atom_Cn);

			static const atom_symbol enum_type = atom_symbol::Cn;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIB;
			static const int period = 7;
			static const atomic_block block = atomic_block::d;

			static const int z = 112;
			static const int mass_number = 173;

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

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_IIB_HPP
