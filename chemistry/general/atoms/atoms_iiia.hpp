#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_IIIA_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_IIIA_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace chemistry
{
	class atom_B : public normal_atom<atom_B>
	{
		public:
			ATOM_HPP(atom_B);

			static const atom_symbol enum_type = atom_symbol::B;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIIA;
			static const int period = 2;
			static const atomic_block block = atomic_block::p;

			static const int z = 5;
			static const int mass_number = 6;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.04;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Al : public normal_atom<atom_Al>
	{
		public:
			ATOM_HPP(atom_Al);

			static const atom_symbol enum_type = atom_symbol::Al;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIIA;
			static const int period = 3;
			static const atomic_block block = atomic_block::p;

			static const int z = 13;
			static const int mass_number = 14;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.61;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Ga : public normal_atom<atom_Ga>
	{
		public:
			ATOM_HPP(atom_Ga);

			static const atom_symbol enum_type = atom_symbol::Ga;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIIA;
			static const int period = 4;
			static const atomic_block block = atomic_block::p;

			static const int z = 31;
			static const int mass_number = 39;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.81;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_In : public normal_atom<atom_In>
	{
		public:
			ATOM_HPP(atom_In);

			static const atom_symbol enum_type = atom_symbol::In;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIIA;
			static const int period = 5;
			static const atomic_block block = atomic_block::p;

			static const int z = 49;
			static const int mass_number = 66;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.78;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Tl : public normal_atom<atom_Tl>
	{
		public:
			ATOM_HPP(atom_Tl);

			static const atom_symbol enum_type = atom_symbol::Tl;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIIA;
			static const int period = 6;
			static const atomic_block block = atomic_block::p;

			static const int z = 81;
			static const int mass_number = 123;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.62;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Nh : public normal_atom<atom_Nh>
	{
		public:
			ATOM_HPP(atom_Nh);

			static const atom_symbol enum_type = atom_symbol::Nh;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIIA;
			static const int period = 7;
			static const atomic_block block = atomic_block::p;

			static const int z = 113;
			static const int mass_number = 173;

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

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_IIIA_HPP
