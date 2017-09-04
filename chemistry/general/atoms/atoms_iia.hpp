#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_IIA_HPP
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_IIA_HPP

#include "normal_atom.hpp"

#include "units.hpp"

namespace chemistry
{
	class atom_Be : public normal_atom<atom_Be>
	{
		public:
			ATOM_HPP(atom_Be);

			static const atom_symbol enum_type = atom_symbol::Be;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIA;
			static const int period = 2;
			static const atomic_block block = atomic_block::s;

			static const int z = 4;
			static const int mass_number = 5;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.57;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Mg : public normal_atom<atom_Mg>
	{
		public:
			ATOM_HPP(atom_Mg);

			static const atom_symbol enum_type = atom_symbol::Mg;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIA;
			static const int period = 3;
			static const atomic_block block = atomic_block::s;

			static const int z = 12;
			static const int mass_number = 12;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1.31;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Ca : public normal_atom<atom_Ca>
	{
		public:
			ATOM_HPP(atom_Ca);

			static const atom_symbol enum_type = atom_symbol::Ca;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIA;
			static const int period = 4;
			static const atomic_block block = atomic_block::s;

			static const int z = 20;
			static const int mass_number = 20;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 1;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Sr : public normal_atom<atom_Sr>
	{
		public:
			ATOM_HPP(atom_Sr);

			static const atom_symbol enum_type = atom_symbol::Sr;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIA;
			static const int period = 5;
			static const atomic_block block = atomic_block::s;

			static const int z = 38;
			static const int mass_number = 45;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0.95;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Ba : public normal_atom<atom_Ba>
	{
		public:
			ATOM_HPP(atom_Ba);

			static const atom_symbol enum_type = atom_symbol::Ba;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIA;
			static const int period = 6;
			static const atomic_block block = atomic_block::s;

			static const int z = 56;
			static const int mass_number = 81;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0.89;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Ra : public normal_atom<atom_Ra>
	{
		public:
			ATOM_HPP(atom_Ra);

			static const atom_symbol enum_type = atom_symbol::Ra;

			static const string name;
			static const string symbol;

			static const atomic_group group = IIA;
			static const int period = 7;
			static const atomic_block block = atomic_block::s;

			static const int z = 88;
			static const int mass_number = 138;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0.9;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};
}

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_IIA_HPP
