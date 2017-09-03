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

			static const float electron_affinity;

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

	class atom_Na : public normal_atom<atom_Na>
	{
		public:
			ATOM_HPP(atom_Na);

			static const atom_symbol enum_type = atom_symbol::Na;

			static const string name;
			static const string symbol;

			static const atomic_group group = IA;
			static const int period = 3;
			static const atomic_block block = atomic_block::s;

			static const int z = 11;
			static const int mass_number = 12;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0.93;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_K : public normal_atom<atom_K>
	{
		public:
			ATOM_HPP(atom_K);

			static const atom_symbol enum_type = atom_symbol::K;

			static const string name;
			static const string symbol;

			static const atomic_group group = IA;
			static const int period = 4;
			static const atomic_block block = atomic_block::s;

			static const int z = 19;
			static const int mass_number = 20;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0.82;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Rb : public normal_atom<atom_Rb>
	{
		public:
			ATOM_HPP(atom_Rb);

			static const atom_symbol enum_type = atom_symbol::Rb;

			static const string name;
			static const string symbol;

			static const atomic_group group = IA;
			static const int period = 5;
			static const atomic_block block = atomic_block::s;

			static const int z = 37;
			static const int mass_number = 47;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0.82;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Cs : public normal_atom<atom_Cs>
	{
		public:
			ATOM_HPP(atom_Cs);

			static const atom_symbol enum_type = atom_symbol::Cs;

			static const string name;
			static const string symbol;

			static const atomic_group group = IA;
			static const int period = 6;
			static const atomic_block block = atomic_block::s;

			static const int z = 55;
			static const int mass_number = 78;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0.79;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};

	class atom_Fr : public normal_atom<atom_Fr>
	{
		public:
			ATOM_HPP(atom_Fr);

			static const atom_symbol enum_type = atom_symbol::Fr;

			static const string name;
			static const string symbol;

			static const atomic_group group = IA;
			static const int period = 7;
			static const atomic_block block = atomic_block::s;

			static const int z = 87;
			static const int mass_number = 136;

			static const length atomic_radius;
			static const mass standard_atomic_mass;

			static constexpr float electronegativity = 0.79;
			static const bool radioactive = false;

			static const molar_energy ionization_energy;
			static const length covalent_radius;
			static const length van_der_waals_radius;

			static const cas_number cas_number;
	};
}

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_IA_HPP
