#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_IA_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_IA_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace chemistry
{
	class atom_H : public normal_atom<atom_H>
	{
		public:
			using normal_atom::normal_atom;

			static const atom_symbol enum_type = atom_symbol::H;

			static const string name;
			static const string symbol;

			static const atomic_group group = IA;
			static const int period = 1;
			static const atomic_block block = atomic_block::s;

			static const int z = 1;
			static const int neutrons_number = 0;
			static const int valence_number = 1;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.1;
			static const bool radioactive = false;

			static const temperature melting_point;
			static const temperature boiling_point;
			static const density density;
	};
}

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_IA_HPP
