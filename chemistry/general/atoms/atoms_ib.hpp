#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_IB_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_IB_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace chemistry
{
	class atom_Cu : public normal_atom<atom_Cu>
	{
		public:
			ATOM_HPP(atom_Cu);

			static constexpr atom_symbol enum_type = atom_symbol::Cu;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = IB;
			static constexpr unsigned int period = 4;
			static constexpr atomic_block block = atomic_block::d;

			static constexpr unsigned int z = 29;
			static constexpr unsigned int mass_number = 35;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.90;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Ag : public normal_atom<atom_Ag>
	{
		public:
			ATOM_HPP(atom_Ag);

			static constexpr atom_symbol enum_type = atom_symbol::Ag;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = IB;
			static constexpr unsigned int period = 5;
			static constexpr atomic_block block = atomic_block::d;

			static constexpr unsigned int z = 47;
			static constexpr unsigned int mass_number = 61;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.93;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Au : public normal_atom<atom_Au>
	{
		public:
			ATOM_HPP(atom_Au);

			static constexpr atom_symbol enum_type = atom_symbol::Au;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = IB;
			static constexpr unsigned int period = 6;
			static constexpr atomic_block block = atomic_block::d;

			static constexpr unsigned int z = 79;
			static constexpr unsigned int mass_number = 118;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.54;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Rg : public normal_atom<atom_Rg>
	{
		public:
			ATOM_HPP(atom_Rg);

			static constexpr atom_symbol enum_type = atom_symbol::Rg;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = IB;
			static constexpr unsigned int period = 7;
			static constexpr atomic_block block = atomic_block::d;

			static constexpr unsigned int z = 111;
			static constexpr unsigned int mass_number = 161;

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

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_IB_HPP
