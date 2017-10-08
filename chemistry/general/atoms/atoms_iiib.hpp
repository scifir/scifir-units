#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_IIIB_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_IIIB_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace msci
{
	class atom_Sc : public normal_atom<atom_Sc>
	{
		public:
			ATOM_HPP(atom_Sc);

			static constexpr atom_symbol enum_type = atom_symbol::Sc;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = IB;
			static constexpr unsigned int period = 4;
			static constexpr atomic_block block = atomic_block::d;

			static constexpr unsigned int z = 21;
			static constexpr unsigned int mass_number = 24;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.36;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Y : public normal_atom<atom_Y>
	{
		public:
			ATOM_HPP(atom_Y);

			static constexpr atom_symbol enum_type = atom_symbol::Y;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = IB;
			static constexpr unsigned int period = 5;
			static constexpr atomic_block block = atomic_block::d;

			static constexpr unsigned int z = 39;
			static constexpr unsigned int mass_number = 50;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.22;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};
}

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_IIIB_HPP
