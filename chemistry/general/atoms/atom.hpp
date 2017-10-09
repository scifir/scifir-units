#ifndef CHEMISTRY_GENERAL_ATOMS_ATOM_HPP_INCLUDED
#define CHEMISTRY_GENERAL_ATOMS_ATOM_HPP_INCLUDED

#include <cmath>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "../../../units.hpp"
#include "informatics/graphical/color.hpp"
#include "math/number/angle_number.hpp"

using namespace std;

#define ATOM_HPP(name) using normal_atom::normal_atom; \
	name()

#define ATOM_CPP(name) name::name() : normal_atom<name>() \
	{ \
	}

namespace msci
{
	enum class atom_symbol {H, He, Li, Be, B, C, N, O, F, Ne, Na, Mg, Al, Si, P, S, Cl, Ar, K, Ca, Sc, Ti, V, Cr, Mn, Fe, Co, Ni, Cu, Zn, Ga, Ge, As, Se, Br, Kr, Rb, Sr, Y, Zr, Nb, Mo, Tc, Ru, Rh, Pd, Ag, Cd, In, Sn, Sb, Te, I, Xe, Cs, Ba, La, Ce, Pr, Nd, Pm, Sm, Eu, Gd, Tb, Dy, Ho, Er, Tm, Yb, Lu, Hf, Ta, W, Re, Os, Ir, Pt, Au, Hg, Tl, Pb, Bi, Po, At, Rn, Fr, Ra, Ac, Th, Pa, U, Np, Pu, Am, Cm, Bk, Cf, Es, Fm, Md, No, Lr, Rf, Db, Sg, Bh, Hs, Mt, Ds, Rg, Cn, Nh, Fl, Mc, Lv, Ts, Og};
	enum atomic_group {IA, IIA, IIIA, IVA, VA, VIA, VIIA, VIIIA, IB, IIB, IIIB, IVB, VB, VIB, VIIB, VIIIB, LA, AC};
	enum class atomic_block {s,p,d,f};
	enum class atomic_pattern {none,line,prepicated_line,wave_line,prepicated_wave_line,circles};
	enum class molecular_geometry {linear,trigonal_planar,bent,tetrahedral,trigonal_pyramidal,trigonal_bipyramidal,seesaw,t_shaped,octahedral,square_pyramidal,square_planar,pentagonal_bipyramidal,pentagonal_pyramidal,planar_pentagonal,square_antipristamic,tricapped_trigonal_prismatic};
	enum class edge_position {linear,bent,trigonal_planar,trigonal_pyramidal,t_shaped_ax,t_shaped_eq,tetrahedral,seesaw_ax,seesaw_eq,square_planar,trigonal_bipyramidal_ax,trigonal_bipyramidal_eq,square_pyramidal_ax,square_pyramidal_eq,planar_pentagonal,octahedral,pentagonal_pyramidal_ax,pentagonal_pyramidal_eq,pentagonal_bipyramidal_ax,pentagonal_bipyramidal_eq,square_antipristamic,tricapped_trigonal_prismatic};
	enum atomic_orbital_type {atomic_orbital_s,atomic_orbital_p,atomic_orbital_d,atomic_orbital_f};
	enum class atomic_bond_type {ionic,covalent,metallic};
	enum class atomic_bond_weight {single,dual,triple};
	enum class crystal_structure {bcc,hexagonal};
	enum class magnetic_ordering {diamagnetic,paramagnetic};

	extern vector<vector<int>> electronic_configuration_order;

	class atomic_bond;

	class atom
	{
		public:
			atom();

			virtual const atom_symbol get_enum_type() const = 0;

			virtual const string& get_name() const = 0;
			virtual const string& get_symbol() const = 0;

			virtual const atomic_group get_atomic_group() const = 0;
			virtual const unsigned int get_period() const = 0;
			virtual const atomic_block get_atomic_block() const = 0;

			virtual const unsigned int get_z() const = 0;
			virtual const int get_valence_number() const = 0;

			virtual const length& get_atomic_radius() const = 0;
			virtual const mass& get_standard_atomic_mass() const = 0;

			virtual const float get_electronegativity() const = 0;
			virtual const bool is_radioactive() const = 0;

			/*virtual const temperature& get_melting_point() const = 0;
			virtual const temperature& get_boiling_point() const = 0;
			virtual const density& get_density_stp() const = 0;

			virtual const molar_enthalpy& get_heat_of_fusion() const = 0;
			virtual const molar_enthalpy& get_heat_of_vaporization() const = 0;
			virtual const molar_heat_capacity& get_heat_capacity() const = 0;*/

			virtual const molar_energy& get_ionization_energy() const = 0;
			virtual const length& get_covalent_radius() const = 0;
			virtual const length& get_van_der_waals_radius() const = 0;

			/*virtual const crystal_structure get_crystal_structure() const = 0;
			virtual const thermal_conductivity& get_thermal_conductivity() const = 0;
			virtual const magnetic_ordering& get_magnetic_ordering() const = 0;
			virtual const magnetic_susceptibility& get_magnetic_susceptibility() const = 0;*/
			virtual const cas_number& get_cas_number() const = 0;

			inline const vector<weak_ptr<atomic_bond>>& get_bonds() const
			{
				return bonds;
			}

			inline int get_bonds_number() const
			{
				return get_bonds().size();
			}

			inline bool is_atom_specimen(atom_symbol x) const
			{
				return (x == get_enum_type());
			}

			virtual bool is_factible() const = 0;

			void add_bond(const shared_ptr<atomic_bond>&);

			bool bonded_to(const atom&) const;

			shared_ptr<atomic_bond> get_bond_of(const atom&) const;

			virtual int get_ionic_charge() const = 0;

            inline bool is_ion() const
            {
            	return (get_ionic_charge() != 0);
            }

            inline bool is_anion() const
            {
            	return (get_ionic_charge() < 0);
            }

            inline bool is_cation() const
            {
            	return (get_ionic_charge() > 0);
            }

            inline bool is_neutral() const
            {
            	return (get_ionic_charge() == 0);
            }

            inline bool is_metallic() const
            {
            	return (is_pure_metal() or is_transition_metal());
            }

            inline bool is_pure_metal() const
            {
            	return (get_atomic_group() == IA or get_atomic_group() == IIA);
            }

            inline bool is_transition_metal() const
            {
            	return (get_atomic_group() == IB or get_atomic_group() == IIB or get_atomic_group() == IIIB or get_atomic_group() == IVB or get_atomic_group() == VB or get_atomic_group() == VIB or get_atomic_group() == VIIB or get_atomic_group() == VIIIB);
            }

            inline bool is_non_metal() const
            {
            	return (get_z() == 1 or get_z() == 6 or get_z() == 7 or get_z() == 8 or get_z() == 9 or get_z() == 15 or get_z() == 16 or get_z() == 17 or get_z() == 34 or get_z() == 35 or get_z() == 53 or get_z() == 2 or get_z() == 10 or get_z() == 18 or get_z() == 36 or get_z() == 54 or get_z() == 86);
            }

            inline bool is_metalloid() const
            {
            	return (get_z() == 5 or get_z() == 6 or get_z() == 13 or get_z() == 14 or get_z() == 32 or get_z() == 33 or get_z() == 34 or get_z() == 51 or get_z() == 52 or get_z() == 84 or get_z() == 85);
            }

            inline bool is_alkali_metal() const
            {
            	return (get_atomic_group() == IA);
            }

            inline bool is_alkaline_earth_metal() const
            {
            	return (get_atomic_group() == IIA);
            }

            inline bool is_boron_group() const
            {
            	return (get_atomic_group() == IIIA);
            }

            inline bool is_carbon_group() const
            {
            	return (get_atomic_group() == IVA);
            }

            inline bool is_nitrogen_group() const
            {
            	return (get_atomic_group() == VA);
            }

            inline bool is_chalcogen() const
            {
            	return (get_atomic_group() == VIA);
            }

            inline bool is_halogen() const
            {
            	return (get_atomic_group() == VIIA);
            }

            inline bool is_noble_gas() const
            {
            	return (get_atomic_group() == VIIIA);
            }

            inline bool is_lanthanide() const
            {
            	return (get_atomic_group() == LA);
            }

            inline bool is_actinide() const
            {
            	return (get_atomic_group() == AC);
            }

            inline bool is_rare_earth() const
            {
            	return (is_lanthanide() or is_atom_specimen(atom_symbol::Sc) or is_atom_specimen(atom_symbol::Y));
            }

            inline bool is_atomic_group_a() const
            {
				return (get_atomic_group() == IA or get_atomic_group() == IIA or get_atomic_group() == IIIA or get_atomic_group() == IVA or get_atomic_group() == VA or get_atomic_group() == VIA or get_atomic_group() == VIIA or get_atomic_group() == VIIIA);
            }

            inline bool is_atomic_group_b() const
            {
				return (get_atomic_group() == IB or get_atomic_group() == IIB or get_atomic_group() == IIIB or get_atomic_group() == IVB or get_atomic_group() == VB or get_atomic_group() == VIB or get_atomic_group() == VIIB or get_atomic_group() == VIIIB);
            }

            virtual int get_electrons_number() const = 0;

            inline int get_valence_electrons_number() const
            {
            	return (get_valence_number() - get_ionic_charge());
            }

            virtual const unsigned int get_mass_number() const = 0;
            virtual string get_electronic_configuration() const = 0;

            virtual int get_lone_pairs() const = 0;

            virtual mass get_real_mass() const = 0;

            inline mass get_real_mass_simplified() const
            {
				int calculated_mass = get_z() + get_mass_number();
            	return mass(calculated_mass,"amu");
            }

            virtual mass get_electrons_mass() const = 0;

            inline mass get_total_mass() const
            {
            	return get_real_mass() + get_electrons_mass();
            }

            virtual bool is_common_isotope() const = 0;

            inline bool is_uncommon_isotope() const
            {
            	return !is_common_isotope();
            }

            virtual bool is_exotic() const = 0;

            msci::color get_atomic_color() const;

			atomic_pattern get_atomic_pattern() const;

			molecular_geometry get_molecular_geometry() const;

			bool is_valence_full() const;

			bool is_chiral() const;

			inline bool is_achiral() const
			{
				return !is_chiral();
			}

			/*electron_cloud get_electron_cloud() const
			{

			}

			void print_electron_cloud() const
			{
				electron_cloud x = get_electron_cloud();
				x.print_3d();
			}*/

			inline void print() const
			{
				//wcout << *this;
			}

            virtual void print_image_2d() const = 0;
            virtual void print_image_3d() const = 0;
            //virtual c_canvas_t get_image_2d() const = 0;
            //virtual c_canvas_t get_detailed_image_2d() const = 0;
            //virtual GLObject get_image_3d() const = 0;

            virtual string get_file_format() const = 0;

		private:
			vector<weak_ptr<atomic_bond>> bonds;
	};

	template<typename T>
	class atom_crtp : public atom
	{
		public:
			atom_crtp() : atom()
			{
			}

			virtual const atom_symbol get_enum_type() const
			{
				return T::enum_type;
			}

			virtual const string& get_name() const
			{
				return T::name;
			}

			virtual const string& get_symbol() const
			{
				return T::symbol;
			}

			virtual const atomic_group get_atomic_group() const
			{
				return T::group;
			}

			virtual const unsigned int get_period() const
			{
				return T::period;
			}

			virtual const atomic_block get_atomic_block() const
			{
				return T::block;
			}

			virtual const unsigned int get_z() const
			{
				return T::z;
			}

			virtual const int get_valence_number() const
			{
				if (get_atomic_group() == IA)
				{
					return 1;
				}
				else if(get_atomic_group() == IIA)
				{
					return 2;
				}
				else if(get_atomic_group() == IIIA)
				{
					return 3;
				}
				else if(get_atomic_group() == IVA)
				{
					return 4;
				}
				else if(get_atomic_group() == VA)
				{
					return 5;
				}
				else if(get_atomic_group() == VIA)
				{
					return 6;
				}
				else if(get_atomic_group() == VIIA)
				{
					return 7;
				}
				else if(get_atomic_group() == VIIIA)
				{
					return 8;
				}
				if (get_atomic_group() == IIIB)
				{
					return 3;
				}
				else if (get_atomic_group() == IVB)
				{
					return 4;
				}
				else if (get_atomic_group() == VB)
				{
					return 5;
				}
				else if (get_atomic_group() == VIB)
				{
					return 6;
				}
				else if (get_atomic_group() == VIIB)
				{
					return 7;
				}
				else if (get_atomic_group() == VIIIB)
				{
					if (get_z() == 26 or get_z() == 44 or get_z() == 76 or get_z() == 108)
					{
						return 8;
					}
					else if (get_z() == 27 or get_z() == 45 or get_z() == 77 or get_z() == 109)
					{
						return 9;
					}
					else if (get_z() == 28 or get_z() == 46 or get_z() == 78 or get_z() == 110)
					{
						return 10;
					}
				}
				else if (get_atomic_group() == IB)
				{
					return 11;
				}
				else if (get_atomic_group() == IIB)
				{
					return 12;
				}
				return 1;
			}

			virtual const length& get_atomic_radius() const
			{
				return T::atomic_radius;
			}

			virtual const mass& get_standard_atomic_mass() const
			{
				return T::standard_atomic_mass;
			}

			virtual const float get_electronegativity() const
			{
				return T::electronegativity;
			}

			virtual const bool is_radioactive() const
			{
				return T::radioactive;
			}

			/*virtual const temperature& get_melting_point() const
			{
				return T::melting_point;
			}

			virtual const temperature& get_boiling_point() const
			{
				return T::boiling_point;
			}

			virtual const density& get_density_stp() const
			{
				return T::density_stp;
			}

            virtual const molar_enthalpy& get_heat_of_fusion() const
            {
				return T::heat_of_fusion;
            }

			virtual const molar_enthalpy& get_heat_of_vaporization() const
			{
                return T::heat_of_vaporization;
			}

			virtual const molar_heat_capacity& get_heat_capacity() const
			{
				return T::heat_capacity;
			}*/

			virtual const molar_energy& get_ionization_energy() const
			{
				return T::ionization_energy;
			}

			virtual const length& get_covalent_radius() const
			{
				return T::covalent_radius;
			}

			virtual const length& get_van_der_waals_radius() const
			{
				return T::van_der_waals_radius;
			}

			/*virtual const crystal_structure get_crystal_structure() const
			{
				return T::crystal_structure;
			}

			virtual const thermal_conductivity& get_thermal_conductivity() const
			{
				return T::thermal_conductivity;
			}

			virtual const magnetic_ordering& get_magnetic_ordering() const
			{
				return T::magnetic_ordering;
			}

			virtual const magnetic_susceptibility& get_magnetic_susceptibility() const
			{
				return T::magnetic_susceptibility;
			}*/

			virtual const cas_number& get_cas_number() const
			{
				return T::cas_number;
			}

			virtual bool is_common_isotope() const
            {
            	return (get_mass_number() == T::mass_number);
            }
	};

	msci::angle_number get_molecular_geometry_angle(const atom&);

	bool are_isotopes(const atom&,const atom&);
	bool are_isobares(const atom&,const atom&);
	bool are_isoelectronics(const atom&,const atom&);
	bool same_element(const atom&,const atom&);
	bool same_specimen(const atom&,const atom&);
}

bool operator ==(const msci::atom&,const msci::atom&);
bool operator !=(const msci::atom&,const msci::atom&);
wostream& operator <<(wostream&,const msci::atom&);

#endif // CHEMISTRY_GENERAL_ATOMS_ATOM_HPP_INCLUDED
