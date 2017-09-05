#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_VIIB_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_VIIB_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace chemistry
{
	class atom_Mn : public normal_atom<atom_Mn>
	{
		public:
			ATOM_HPP(atom_Mn);

			static const atom_symbol enum_type = atom_symbol::Mn;

			static const string name;
			static const string symbol;

			static const atomic_group group = VIIB;
			static const int period = 4;
			static const atomic_block block = atomic_block::d;

			static const int z = 25;
			static const int mass_number = 30;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.55;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Tc : public normal_atom<atom_Tc>
	{
		public:
			ATOM_HPP(atom_Tc);

			static const atom_symbol enum_type = atom_symbol::Tc;

			static const string name;
			static const string symbol;

			static const atomic_group group = VIIB;
			static const int period = 5;
			static const atomic_block block = atomic_block::d;

			static const int z = 43;
			static const int mass_number = 56;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.9;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Re : public normal_atom<atom_Re>
	{
		public:
			ATOM_HPP(atom_Re);

			static const atom_symbol enum_type = atom_symbol::Re;

			static const string name;
			static const string symbol;

			static const atomic_group group = VIIB;
			static const int period = 6;
			static const atomic_block block = atomic_block::d;

			static const int z = 75;
			static const int mass_number = 111;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.9;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Bh : public normal_atom<atom_Bh>
	{
		public:
			ATOM_HPP(atom_Bh);

			static const atom_symbol enum_type = atom_symbol::Bh;

			static const string name;
			static const string symbol;

			static const atomic_group group = VIIB;
			static const int period = 7;
			static const atomic_block block = atomic_block::d;

			static const int z = 107;
			static const int mass_number = 157;

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

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_VIIB_HPP
