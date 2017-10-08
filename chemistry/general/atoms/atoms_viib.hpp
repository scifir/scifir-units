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

			static constexpr atom_symbol enum_type = atom_symbol::Mn;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIB;
			static constexpr unsigned int period = 4;
			static constexpr atomic_block block = atomic_block::d;

			static constexpr unsigned int z = 25;
			static constexpr unsigned int mass_number = 30;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.55;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Tc : public normal_atom<atom_Tc>
	{
		public:
			ATOM_HPP(atom_Tc);

			static constexpr atom_symbol enum_type = atom_symbol::Tc;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIB;
			static constexpr unsigned int period = 5;
			static constexpr atomic_block block = atomic_block::d;

			static constexpr unsigned int z = 43;
			static constexpr unsigned int mass_number = 56;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.9;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Re : public normal_atom<atom_Re>
	{
		public:
			ATOM_HPP(atom_Re);

			static constexpr atom_symbol enum_type = atom_symbol::Re;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIB;
			static constexpr unsigned int period = 6;
			static constexpr atomic_block block = atomic_block::d;

			static constexpr unsigned int z = 75;
			static constexpr unsigned int mass_number = 111;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.9;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Bh : public normal_atom<atom_Bh>
	{
		public:
			ATOM_HPP(atom_Bh);

			static constexpr atom_symbol enum_type = atom_symbol::Bh;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIB;
			static constexpr unsigned int period = 7;
			static constexpr atomic_block block = atomic_block::d;

			static constexpr unsigned int z = 107;
			static constexpr unsigned int mass_number = 157;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};
}

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_VIIB_HPP
