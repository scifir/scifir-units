#ifndef CHEMISTRY_GENERAL_ATOMS_ATOM_HPP_INCLUDED
#define CHEMISTRY_GENERAL_ATOMS_ATOM_HPP_INCLUDED

#include <cmath>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "physics/units.hpp"

using namespace std;
using namespace physics::units;

namespace chemistry
{
	enum atom_symbol {H, He, Li, Be, B, C, N, O, F, Ne, Na, Mg, Al, Si, P, S, Cl, Ar, K, Ca, Sc, Ti, V, Cr, Mn, Fe, Co, Ni, Cu, Zn, Ga, Ge, As, Se, Br, Kr, Rb, Sr, Y, Zr, Nb, Mo, Tc, Ru, Rh, Pd, Ag, Cd, In, Sn, Sb, Te, I, Xe, Cs, Ba, La, Ce, Pr, Nd, Pm, Sm, Eu, Gd, Tb, Dy, Ho, Er, Tm, Yb, Lu, Hf, Ta, W, Re, Os, Ir, Pt, Au, Hg, Tl, Pb, Bi, Po, At, Rn, Fr, Ra, Ac, Th, Pa, U, Np, Pu, Am, Cm, Bk, Cf, Es, Fm, Md, No, Lr, Rf, Db, Sg, Bh, Hs, Mt, Ds, Rg, Cn, Uut, Fl, Uup, Lv, Uus, Uuo};
	enum atomic_group {IA, IIA, IIIA, IVA, VA, VIA, VIIA, VIIIA, IB, IIB, IIIB, IVB, VB, VIB, VIIB, VIIIB};
	enum atomic_pattern_type {none,line};
	enum atomic_geometry {linear,trigonal_planar,bent,tetrahedral,trigonal_pyramidal,trigonal_bipyramidal,seesaw,t_shaped,octahedral,square_pyramidal,square_planar,pentagonal_bipyramidal,pentagonal_pyramidal,planar_pentagonal,square_antipristamic,tricapped_trigonal_prismatic};
	enum atomic_orbital_type {atomic_orbital_s,atomic_orbital_p,atomic_orbital_d,atomic_orbital_f};

	extern vector<vector<int>> electronic_configuration_order;

	template<typename T>
	class atom
	{
		public:
			atom()
			{

			}

			inline const string& get_name() const
			{
				return T::name;
			}

			inline const string& get_symbol() const
			{
				return T::symbol;
			}

			inline const atomic_group& get_atomic_group() const
			{
				return T::group;
			}

			inline const int& get_period() const
			{
				return T::period;
			}

			inline const int& get_z() const
			{
				return T::z;
			}

			inline const int& get_valence_number() const
			{
				return T::valence_number;
			}

			inline const float& get_electronegativity() const
			{
				return T::electronegativity;
			}

			inline const bool& is_radioactive() const
			{
				return T::radioactive;
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

            virtual int get_electrons_number() const = 0;
            virtual const unsigned int& get_neutrons_number() const = 0;
            virtual string get_electronic_configuration() const = 0;

            virtual mass get_real_mass() const = 0;

            mass get_real_mass_simplified() const
            {
				int calculated_mass = get_z() + get_neutrons_number();
            	return mass(calculated_mass,"uma");
            }

            virtual mass get_electrons_mass() const = 0;

            mass get_total_mass() const
            {
            	return get_real_mass() + get_electrons_mass();
            }

            const mass& get_standard_atomic_mass() const
            {
            	return T::standard_atomic_mass;
            }

			void print() const
			{
				wcout << *this;
			}

            virtual void print_image_2d() const = 0;
            virtual void print_image_3d() const = 0;
            //virtual c_canvas_t get_image_2d() = 0;
            //virtual GLObject get_image_3d() = 0;
	};
}

template<typename T>
wostream& operator <<(wostream& os, const chemistry::atom<T>& x)
{
	wostringstream charge_text;
	if (x.get_ionic_charge() < 0)
	{
		charge_text << abs(x.get_ionic_charge()) << "-";
	}
	else if (x.get_ionic_charge() > 0)
	{
		charge_text << abs(x.get_ionic_charge()) << "+";
	}
	return os << "[" << x.get_symbol().c_str() << "]" << charge_text.str();
}

#endif // CHEMISTRY_GENERAL_ATOMS_ATOM_HPP_INCLUDED
