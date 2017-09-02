#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_IA_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_IA_HPP

#include "normal_atom.hpp"

#include "units.hpp"

#define ATOM_HPP(name) using normal_atom::normal_atom; \
	name()

#define ATOM_CPP(name) name::name() : normal_atom<name>() \
	{ \
	}

namespace chemistry
{
	class atom_H : public normal_atom<atom_H>
	{
		public:
			ATOM_HPP(atom_H);

			static const atom_symbol enum_type = atom_symbol::H;

			static const string name;
			static const string symbol;

			static const atomic_group group = IA;
			static const int period = 1;
			static const atomic_block block = atomic_block::s;

			static const int z = 1;
			static const int mass_number = 0;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.2;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Li : public normal_atom<atom_Li>
	{
		public:
			ATOM_HPP(atom_Li);

			static const atom_symbol enum_type = atom_symbol::Li;

			static const string name;
			static const string symbol;

			static const atomic_group group = IA;
			static const int period = 2;
			static const atomic_block block = atomic_block::s;

			static const int z = 3;
			static const int mass_number = 4;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0.98;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};
}

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_IA_HPP
