#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_VIIIA_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_VIIIA_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace chemistry
{
	class atom_He : public normal_atom<atom_He>
	{
		public:
			ATOM_HPP(atom_He);

			static constexpr atom_symbol enum_type = atom_symbol::He;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIIA;
			static constexpr unsigned int period = 1;
			static constexpr atomic_block block = atomic_block::s;

			static constexpr unsigned int z = 2;
			static constexpr unsigned int mass_number = 2;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Ne : public normal_atom<atom_Ne>
	{
		public:
			ATOM_HPP(atom_Ne);

			static constexpr atom_symbol enum_type = atom_symbol::Ne;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIIA;
			static constexpr unsigned int period = 2;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 10;
			static constexpr unsigned int mass_number = 10;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Ar : public normal_atom<atom_Ar>
	{
		public:
			ATOM_HPP(atom_Ar);

			static constexpr atom_symbol enum_type = atom_symbol::Ar;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIIA;
			static constexpr unsigned int period = 3;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 18;
			static constexpr unsigned int mass_number = 22;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Kr : public normal_atom<atom_Kr>
	{
		public:
			ATOM_HPP(atom_Kr);

			static constexpr atom_symbol enum_type = atom_symbol::Kr;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIIA;
			static constexpr unsigned int period = 4;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 36;
			static constexpr unsigned int mass_number = 49;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 3.00;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Xe : public normal_atom<atom_Xe>
	{
		public:
			ATOM_HPP(atom_Xe);

			static constexpr atom_symbol enum_type = atom_symbol::Xe;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIIA;
			static constexpr unsigned int period = 5;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 54;
			static constexpr unsigned int mass_number = 77;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.6;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Rn : public normal_atom<atom_Rn>
	{
		public:
			ATOM_HPP(atom_Rn);

			static constexpr atom_symbol enum_type = atom_symbol::Rn;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIIA;
			static constexpr unsigned int period = 6;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 86;
			static constexpr unsigned int mass_number = 136;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.2;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Og : public normal_atom<atom_Og>
	{
		public:
			ATOM_HPP(atom_Og);

			static constexpr atom_symbol enum_type = atom_symbol::Og;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIIA;
			static constexpr unsigned int period = 7;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 118;
			static constexpr unsigned int mass_number = 176;

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

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_VIIIA_HPP
