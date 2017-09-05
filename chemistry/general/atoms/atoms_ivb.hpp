#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_IVB_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_IVB_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace chemistry
{
	class atom_Ti : public normal_atom<atom_Ti>
	{
		public:
			ATOM_HPP(atom_Ti);

			static const atom_symbol enum_type = atom_symbol::Ti;

			static const string name;
			static const string symbol;

			static const atomic_group group = IVB;
			static const int period = 4;
			static const atomic_block block = atomic_block::d;

			static const int z = 22;
			static const int mass_number = 26;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.54;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Zr : public normal_atom<atom_Zr>
	{
		public:
			ATOM_HPP(atom_Zr);

			static const atom_symbol enum_type = atom_symbol::Zr;

			static const string name;
			static const string symbol;

			static const atomic_group group = IVB;
			static const int period = 5;
			static const atomic_block block = atomic_block::d;

			static const int z = 40;
			static const int mass_number = 51;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.33;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Hf : public normal_atom<atom_Hf>
	{
		public:
			ATOM_HPP(atom_Hf);

			static const atom_symbol enum_type = atom_symbol::Hf;

			static const string name;
			static const string symbol;

			static const atomic_group group = IVB;
			static const int period = 6;
			static const atomic_block block = atomic_block::d;

			static const int z = 72;
			static const int mass_number = 106;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.3;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Rf : public normal_atom<atom_Rf>
	{
		public:
			ATOM_HPP(atom_Rf);

			static const atom_symbol enum_type = atom_symbol::Rf;

			static const string name;
			static const string symbol;

			static const atomic_group group = IVB;
			static const int period = 7;
			static const atomic_block block = atomic_block::d;

			static const int z = 104;
			static const int mass_number = 163;

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

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_IVB_HPP
