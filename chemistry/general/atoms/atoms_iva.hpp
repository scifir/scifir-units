#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_IVA_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_IVA_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace chemistry
{
	class atom_C : public normal_atom<atom_C>
	{
		public:
			ATOM_HPP(atom_C);

			static constexpr atom_symbol enum_type = atom_symbol::C;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = IVA;
			static constexpr unsigned int period = 2;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 6;
			static constexpr unsigned int mass_number = 6;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.55;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Si : public normal_atom<atom_Si>
	{
		public:
			ATOM_HPP(atom_Si);

			static constexpr atom_symbol enum_type = atom_symbol::Si;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = IVA;
			static constexpr unsigned int period = 3;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 14;
			static constexpr unsigned int mass_number = 14;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.90;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Ge : public normal_atom<atom_Ge>
	{
		public:
			ATOM_HPP(atom_Ge);

			static constexpr atom_symbol enum_type = atom_symbol::Ge;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = IVA;
			static constexpr unsigned int period = 4;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 32;
			static constexpr unsigned int mass_number = 41;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.01;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Sn : public normal_atom<atom_Sn>
	{
		public:
			ATOM_HPP(atom_Sn);

			static constexpr atom_symbol enum_type = atom_symbol::Sn;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = IVA;
			static constexpr unsigned int period = 5;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 50;
			static constexpr unsigned int mass_number = 69;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.96;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Pb : public normal_atom<atom_Pb>
	{
		public:
			ATOM_HPP(atom_Pb);

			static constexpr atom_symbol enum_type = atom_symbol::Pb;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = IVA;
			static constexpr unsigned int period = 6;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 82;
			static constexpr unsigned int mass_number = 125;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.87;
			static constexpr bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Fl : public normal_atom<atom_Fl>
	{
		public:
			ATOM_HPP(atom_Fl);

			static constexpr atom_symbol enum_type = atom_symbol::Fl;

			static const string name;
			static const string symbol;

			static constexpr atomic_group group = IVA;
			static constexpr unsigned int period = 7;
			static constexpr atomic_block block = atomic_block::p;

			static constexpr unsigned int z = 114;
			static constexpr unsigned int mass_number = 175;

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

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_IVA_HPP
