#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_VB_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_VB_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace msci
{
	class atom_V : public normal_atom<atom_V>
	{
		public:
			ATOM_HPP(atom_V);

			static const atom_symbol enum_type;

			static const string name;
			static const string symbol;

			static const atomic_group group;
			static const unsigned int period;
			static const atomic_block block;

			static const unsigned int z;
			static const unsigned int mass_number;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static const float electronegativity;
			static const bool radioactive;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Nb : public normal_atom<atom_Nb>
	{
		public:
			ATOM_HPP(atom_Nb);

			static const atom_symbol enum_type;

			static const string name;
			static const string symbol;

			static const atomic_group group;
			static const unsigned int period;
			static const atomic_block block;

			static const unsigned int z;
			static const unsigned int mass_number;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static const float electronegativity;
			static const bool radioactive;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Ta : public normal_atom<atom_Ta>
	{
		public:
			ATOM_HPP(atom_Ta);

			static const atom_symbol enum_type;

			static const string name;
			static const string symbol;

			static const atomic_group group;
			static const unsigned int period;
			static const atomic_block block;

			static const unsigned int z;
			static const unsigned int mass_number;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static const float electronegativity;
			static const bool radioactive;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Db : public normal_atom<atom_Db>
	{
		public:
			ATOM_HPP(atom_Db);

			static const atom_symbol enum_type;

			static const string name;
			static const string symbol;

			static const atomic_group group;
			static const unsigned int period;
			static const atomic_block block;

			static const unsigned int z;
			static const unsigned int mass_number;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static const float electronegativity;
			static const bool radioactive;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};
}

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_VB_HPP
