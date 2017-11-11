#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_IIB_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_IIB_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace msci
{
	class atom_Zn : public normal_atom<atom_Zn>
	{
		public:
			ATOM_HPP(atom_Zn);

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

	class atom_Cd : public normal_atom<atom_Cd>
	{
		public:
			ATOM_HPP(atom_Cd);

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

	class atom_Hg : public normal_atom<atom_Hg>
	{
		public:
			ATOM_HPP(atom_Hg);

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

	class atom_Cn : public normal_atom<atom_Cn>
	{
		public:
			ATOM_HPP(atom_Cn);

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

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_IIB_HPP
