#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_VB_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_VB_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace chemistry
{
	class atom_V : public normal_atom<atom_V>
	{
		public:
			ATOM_HPP(atom_V);

			static const atom_symbol enum_type = atom_symbol::V;

			static const string name;
			static const string symbol;

			static const atomic_group group = VB;
			static const int period = 4;
			static const atomic_block block = atomic_block::d;

			static const int z = 23;
			static const int mass_number = 28;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.63;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Nb : public normal_atom<atom_Nb>
	{
		public:
			ATOM_HPP(atom_Nb);

			static const atom_symbol enum_type = atom_symbol::Nb;

			static const string name;
			static const string symbol;

			static const atomic_group group = VB;
			static const int period = 5;
			static const atomic_block block = atomic_block::d;

			static const int z = 41;
			static const int mass_number = 52;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.6;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Ta : public normal_atom<atom_Ta>
	{
		public:
			ATOM_HPP(atom_Ta);

			static const atom_symbol enum_type = atom_symbol::Ta;

			static const string name;
			static const string symbol;

			static const atomic_group group = VB;
			static const int period = 6;
			static const atomic_block block = atomic_block::d;

			static const int z = 73;
			static const int mass_number = 108;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.5;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Db : public normal_atom<atom_Db>
	{
		public:
			ATOM_HPP(atom_Db);

			static const atom_symbol enum_type = atom_symbol::Db;

			static const string name;
			static const string symbol;

			static const atomic_group group = VB;
			static const int period = 7;
			static const atomic_block block = atomic_block::d;

			static const int z = 105;
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

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_VB_HPP
