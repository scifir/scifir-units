#ifndef ATOM_HPP_INCLUDED
#define ATOM_HPP_INCLUDED

#include "orbital.hpp"

#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>
using namespace std;

namespace chemistry
{
	enum atom_symbol {H, He, Li, Be, B, C, N, O, F, Ne, Na, Mg, Al, Si, P, S, Cl, Ar, K, Ca, Sc, Ti, V, Cr, Mn, Fe, Co, Ni, Cu, Zn, Ga, Ge, As, Se, Br, Kr, Rb, Sr, Y, Zr, Nb, Mo, Tc, Ru, Rh, Pd, Ag, Cd, In, Sn, Sb, Te, I, Xe, Cs, Ba, La, Ce, Pr, Nd, Pm, Sm, Eu, Gd, Tb, Dy, Ho, Er, Tm, Yb, Lu, Hf, Ta, W, Re, Os, Ir, Pt, Au, Hg, Tl, Pb, Bi, Po, At, Rn, Fr, Ra, Ac, Th, Pa, U, Np, Pu, Am, Cm, Bk, Cf, Es, Fm, Md, No, Lr, Rf, Db, Sg, Bh, Hs, Mt, Ds, Rg, Cn, Uut, Fl, Uup, Lv, Uus, Uuo};
	enum atom_group {IA, IIA, IIIA, IVA, VA, VIA, VIIA, VIIIA, IB, IIB, IIIB, IVB, VB, VIB, VIIB, VIIIB};

	int const mass_proton = 1;
	int const mass_neutron = 1;
	int const mass_electron = 1;

	extern vector<vector<int>> electron_configuration_order;

	class atom
	{
		public:
			static const int period;
			static const int z;
			static const int neutrons;
			static const int valence_electrons;
			static const int charge;
			static const string name;
			static const string symbol;
			static const float atomic_weight;

			vector<weak_ptr<atom>> bonds;
			vector<orbital_group> orbitals;

			atom(atom_symbol, atom_group, int, int, int, int);
			int total_valence_electrons();
			string electronic_configuration();
			float mass();
			float total_mass();

			static const atom& get_atom_type();
			static const atom_group& get_group();

			bool is_non_metallic() const;
			bool is_metallic() const;
	};
}

#include "atoms_ia.hpp"
#include "atoms_iia.hpp"
#include "atoms_iiia.hpp"
#include "atoms_iva.hpp"
#include "atoms_va.hpp"
#include "atoms_via.hpp"
#include "atoms_viia.hpp"
#include "atoms_viiia.hpp"
#include "atoms_ib.hpp"
#include "atoms_iib.hpp"
#include "atoms_iiib.hpp"
#include "atoms_ivb.hpp"
#include "atoms_vb.hpp"
#include "atoms_vib.hpp"
#include "atoms_viib.hpp"
#include "atoms_viiib.hpp"

ostream& operator <<(ostream&, const chemistry::atom&);

#endif // ATOM_HPP_INCLUDED
