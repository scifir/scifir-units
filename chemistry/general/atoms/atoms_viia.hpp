#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_VIIA_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_VIIA_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace chemistry
{
	class atom_F : public normal_atom<atom_F>
	{
		public:
			ATOM_HPP(atom_F);

			static constexpr atom_symbol enum_type = atom_symbol::F;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIA;
			static constexpr unsigned int period = 2;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 9;
			static constexpr unsigned int mass_number = 10;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 3.98;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Cl : public normal_atom<atom_Cl>
	{
		public:
			ATOM_HPP(atom_Cl);

			static constexpr atom_symbol enum_type = atom_symbol::Cl;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIA;
			static constexpr unsigned int period = 3;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 17;
			static constexpr unsigned int mass_number = 18;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 3.16;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Br : public normal_atom<atom_Br>
	{
		public:
			ATOM_HPP(atom_Br);

			static constexpr atom_symbol enum_type = atom_symbol::Br;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIA;
			static constexpr unsigned int period = 4;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 35;
			static constexpr unsigned int mass_number = 45;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.96;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_I : public normal_atom<atom_I>
	{
		public:
			ATOM_HPP(atom_I);

			static constexpr atom_symbol enum_type = atom_symbol::I;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIA;
			static constexpr unsigned int period = 5;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 53;
			static constexpr unsigned int mass_number = 74;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.66;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_At : public normal_atom<atom_At>
	{
		public:
			ATOM_HPP(atom_At);

			static constexpr atom_symbol enum_type = atom_symbol::At;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIA;
			static constexpr unsigned int period = 6;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 85;
			static constexpr unsigned int mass_number = 125;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.2;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Ts : public normal_atom<atom_Ts>
	{
		public:
			ATOM_HPP(atom_Ts);

			static constexpr atom_symbol enum_type = atom_symbol::Ts;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = VIIA;
			static constexpr unsigned int period = 7;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 117;
			static constexpr unsigned int mass_number = 177;

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

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_VIIA_HPP
