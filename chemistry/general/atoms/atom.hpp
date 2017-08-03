#ifndef CHEMISTRY_GENERAL_ATOMS_ATOM_HPP_INCLUDED
#define CHEMISTRY_GENERAL_ATOMS_ATOM_HPP_INCLUDED

// TODO: create triple_point and melting_point (maybe point classes)
// TODO: finish the static member-variables of Hydrogren
// TODO: finish the data of all the atoms
// TODO: finish is_valence_full(), ionic bonds and metallic bonds inside atomic_bond (among other electric functions)
// TODO: 3D graphical functions: get_image_3d(),print_image_3d()
// TODO: 2D graphical functions: get_image_2d(),get_detailed_image_2d(),print_image_2d()
// TODO: electron cloud functions: get_electron_cloud(),print_electron_cloud()
// TODO: finish electron_cloud object
// TODO: document that is_atom_specimen() is always used instead of get_z() or get_symbol() to test for the specimen, cause for isotopes the string symbol can change

#include <cmath>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "physics/units.hpp"
#include "informatics/graphical/color.hpp"
#include "math/number/angle_number.hpp"

using namespace std;
using namespace physics::units;

namespace chemistry
{
	enum class atom_symbol {H, He, Li, Be, B, C, N, O, F, Ne, Na, Mg, Al, Si, P, S, Cl, Ar, K, Ca, Sc, Ti, V, Cr, Mn, Fe, Co, Ni, Cu, Zn, Ga, Ge, As, Se, Br, Kr, Rb, Sr, Y, Zr, Nb, Mo, Tc, Ru, Rh, Pd, Ag, Cd, In, Sn, Sb, Te, I, Xe, Cs, Ba, La, Ce, Pr, Nd, Pm, Sm, Eu, Gd, Tb, Dy, Ho, Er, Tm, Yb, Lu, Hf, Ta, W, Re, Os, Ir, Pt, Au, Hg, Tl, Pb, Bi, Po, At, Rn, Fr, Ra, Ac, Th, Pa, U, Np, Pu, Am, Cm, Bk, Cf, Es, Fm, Md, No, Lr, Rf, Db, Sg, Bh, Hs, Mt, Ds, Rg, Cn, Uut, Fl, Uup, Lv, Uus, Uuo};
	enum atomic_group {IA, IIA, IIIA, IVA, VA, VIA, VIIA, VIIIA, IB, IIB, IIIB, IVB, VB, VIB, VIIB, VIIIB, LA, AC};
	enum class atomic_block {s,p,d,f};
	enum class atomic_pattern {none,line,prepicated_line,wave_line,prepicated_wave_line,circles};
	enum class molecular_geometry {linear,trigonal_planar,bent,tetrahedral,trigonal_pyramidal,trigonal_bipyramidal,seesaw,t_shaped,octahedral,square_pyramidal,square_planar,pentagonal_bipyramidal,pentagonal_pyramidal,planar_pentagonal,square_antipristamic,tricapped_trigonal_prismatic};
	enum class edge_position {linear,bent,trigonal_planar,trigonal_pyramidal,t_shaped_ax,t_shaped_eq,tetrahedral,seesaw_ax,seesaw_eq,square_planar,trigonal_bipyramidal_ax,trigonal_bipyramidal_eq,square_pyramidal_ax,square_pyramidal_eq,planar_pentagonal,octahedral,pentagonal_pyramidal_ax,pentagonal_pyramidal_eq,pentagonal_bipyramidal_ax,pentagonal_bipyramidal_eq,square_antipristamic,tricapped_trigonal_prismatic};
	enum atomic_orbital_type {atomic_orbital_s,atomic_orbital_p,atomic_orbital_d,atomic_orbital_f};
	enum class atomic_bond_type {ionic,covalent,metallic};
	enum class atomic_bond_weight {single,dual,triple};

	extern vector<vector<int>> electronic_configuration_order;

	class atomic_bond;

	class atom
	{
		public:
			atom();

			virtual atom_symbol get_enum_type() const = 0;

			virtual string get_name() const = 0;

			virtual string get_symbol() const = 0;

			virtual atomic_group get_atomic_group() const = 0;

			virtual int get_period() const = 0;

			virtual atomic_block get_atomic_block() const = 0;

			virtual int get_z() const = 0;

			virtual int get_valence_number() const = 0;

			virtual float get_electronegativity() const = 0;

			virtual bool is_radioactive() const = 0;

			virtual length get_atomic_radius() const = 0;

			virtual mass get_standard_atomic_mass() const = 0;

			inline vector<weak_ptr<atomic_bond>> get_bonds() const
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

            inline bool is_atomic_group_a() const
            {
				return (get_atomic_group() == IA or get_atomic_group() == IIA or get_atomic_group() == IIIA or get_atomic_group() == IVA or get_atomic_group() == VA or get_atomic_group() == VIA or get_atomic_group() == VIIA or get_atomic_group() == VIIIA);
            }

            virtual int get_electrons_number() const = 0;

            inline int get_valence_electrons_number() const
            {
            	return (get_valence_number() - get_ionic_charge());
            }

            virtual const unsigned int& get_mass_number() const = 0;
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

            informatics::color get_atomic_color() const; // TODO: finish function

			atomic_pattern get_atomic_pattern() const;

			molecular_geometry get_molecular_geometry() const;

			bool is_valence_full() const; // TODO: finish function

			bool is_chiral() const; //TODO: finish function

			inline bool is_achiral() const
			{
				return !is_chiral();
			}

			/*electron_cloud get_electron_cloud() const // TODO: finish function
			{

			}

			void print_electron_cloud() const // TODO: finish function
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
            //virtual c_canvas_t get_image_2d() const = 0; // TODO: finish function
            //virtual c_canvas_t get_detailed_image_2d() const = 0; // TODO: finish function
            //virtual GLObject get_image_3d() const = 0; // TODO: finish function
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

			virtual inline atom_symbol get_enum_type() const
			{
				return T::enum_type;
			}

			virtual inline string get_name() const
			{
				return T::name;
			}

			virtual inline string get_symbol() const
			{
				return T::symbol;
			}

			virtual inline atomic_group get_atomic_group() const
			{
				return T::group;
			}

			virtual inline int get_period() const
			{
				return T::period;
			}

			virtual atomic_block get_atomic_block() const
			{
				return T::block;
			}

			virtual inline int get_z() const
			{
				return T::z;
			}

			virtual inline int get_valence_number() const
			{
				return T::valence_number;
			}

			virtual inline float get_electronegativity() const
			{
				return T::electronegativity;
			}

			virtual inline bool is_radioactive() const
			{
				return T::radioactive;
			}

			virtual inline length get_atomic_radius() const
			{
				//return T::atomic_radius;
			}

			virtual inline mass get_standard_atomic_mass() const
			{
				//return T::standard_atomic_mass;
			}

			virtual bool is_common_isotope() const
            {
            	return (get_mass_number() == T::neutrons_number);
            }
	};

	math::number::angle_number get_molecular_geometry_angle(const atom&); // TODO: finish two angles

	bool are_isotopes(const atom&,const atom&);
	bool are_isobares(const atom&,const atom&);
	bool are_isoelectronics(const atom&,const atom&);
	bool same_element(const atom&,const atom&);
}

bool operator ==(const chemistry::atom&,const chemistry::atom&);
bool operator !=(const chemistry::atom&,const chemistry::atom&);
wostream& operator <<(wostream&,const chemistry::atom&);

#endif // CHEMISTRY_GENERAL_ATOMS_ATOM_HPP_INCLUDED
