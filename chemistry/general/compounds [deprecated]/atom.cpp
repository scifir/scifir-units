#include "atom.hpp"

#include "orbital.hpp"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

namespace chemistry
{
	atom get_atom(string atom_specie)
	{
		/*switch(atom_specie)
		{
		case "H":
			return atom::H;
		case "He":
			return atom::He;
		case "Li":
			return atom::Li;
		case "Be":
			return atom::Be;
		case "B":
			return atom::B;
		case "C":
			return atom::C;
		case "N":
			return atom::N;
		case "O":
			return atom::O;
		case "F":
			return atom::F;
		case "Ne":
			return atom::Ne;
		case "Na":
			return atom::Na;
		case "Mg":
			return atom::Mg;
		case "Al":
			return atom::Al;
		case "Si":
			return atom::Si;
		case "P":
			return atom::P;
		case "S":
			return atom::S;
		case "Cl":
			return atom::Cl;
		case "Ar":
			return atom::Ar;
		case "K":
			return atom::K;
		case "Ca":
			return atom::Ca;
		case "Sc":
			return atom::Sc;
		case "Ti":
			return atom::Ti;
		case "V":
			return atom::V;
		case "Cr":
			return atom::Cr;
		case "Mn":
			return atom::Mn;
		case "Fe":
			return atom::Fe;
		case "Co":
			return atom::Co;
		case "Ni":
			return atom::Ni;
		case "Cu":
			return atom::Cu;
		case "Zn":
			return atom::Zn;
		case "Ga":
			return atom::Ga;
		case "Ge":
			return atom::Ge;
		case "As":
			return atom::As;
		case "Se":
			return atom::Se;
		case "Br":
			return atom::Br;
		case "Kr":
			return atom::Kr;
		case "Rb":
			return atom::Rb;
		case "Sr":
			return atom::Sr;
		case "Y":
			return atom::Y;
		case "Zr":
			return atom::Zr;
		case "Nb":
			return atom::Nb;
		case "Mo":
			return atom::Mo;
		case "Tc":
			return atom::Tc;
		case "Ru":
			return atom::Ru;
		case "Rh":
			return atom::Rh;
		case "Pd":
			return atom::Pd;
		case "Ag":
			return atom::Ag;
		case "Cd":
			return atom::Cd;
		case "In":
			return atom::In;
		case "Sn":
			return atom::Sn;
		case "Sb":
			return atom::Sb;
		case "Te":
			return atom::Te;
		case "I":
			return atom::I;
		case "Xe":
			return atom::Xe;
		case "Cs":
			return atom::Cs;
		case "Ba":
			return atom::Ba;
		case "La":
			return atom::La;
		case "Ce":
			return atom::Ce;
		case "Pr":
			return atom::Pr;
		case "Nd":
			return atom::Nd;
		case "Pm":
			return atom::Pm;
		case "Sm":
			return atom::Sm;
		case "Eu":
			return atom::Eu;
		case "Gd":
			return atom::Gd;
		case "Tb":
			return atom::Tb;
		case "Dy":
			return atom::Dy;
		case "Ho":
			return atom::Ho;
		case "Er":
			return atom::Er;
		case "Tm":
			return atom::Tm;
		case "Yb":
			return atom::Yb;
		case "Lu":
			return atom::Lu;
		case "Hf":
			return atom::Hf;
		case "Ta":
			return atom::Ta;
		case "W":
			return atom::W;
		case "Re":
			return atom::Re;
		case "Os":
			return atom::Os;
		case "Ir":
			return atom::Ir;
		case "Pt":
			return atom::Pt;
		case "Au":
			return atom::Au;
		case "Hg":
			return atom::Hg;
		case "Tl":
			return atom::Tl;
		case "Pb":
			return atom::Pb;
		case "Bi":
			return atom::Bi;
		case "Po":
			return atom::Po;
		case "At":
			return atom::At;
		case "Rn":
			return atom::Rn;
		case "Fr":
			return atom::Fr;
		case "Ra":
			return atom::Ra;
		case "Ac":
			return atom::Ac;
		case "Th":
			return atom::Th;
		case "Pa":
			return atom::Pa;
		case "U":
			return atom::U;
		case "Np":
			return atom::Np;
		case "Pu":
			return atom::Pu;
		case "Am":
			return atom::Am;
		case "Cm":
			return atom::Cm;
		case "Bk":
			return atom::Bk;
		case "Cf":
			return atom::Cf;
		case "Es":
			return atom::Es;
		case "Fm":
			return atom::Fm;
		case "Md":
			return atom::Md;
		case "No":
			return atom::No;
		case "Lr":
			return atom::Lr;
		case "Rf":
			return atom::Rf;
		case "Db":
			return atom::Db;
		case "Sg":
			return atom::Sg;
		case "Bh":
			return atom::Bh;
		case "Hs":
			return atom::Hs;
		case "Mt":
			return atom::Mt;
		case "Ds":
			return atom::Ds;
		case "Rg":
			return atom::Rg;
		case "Cn":
			return atom::Cn;
		case "Uut":
			return atom::Uut;
		case "Fl":
			return atom::Fl;
		case "Uup":
			return atom::Uup;
		case "Lv":
			return atom::Lv;
		case "Uus":
			return atom::Uus;
		case "Uuo":
			return atom::Uuo;
		}*/
	}

	vector<vector<int>> electron_configuration_order
	{
		{1, chemistry::orbital::s},
		{2, chemistry::orbital::s},
		{2, chemistry::orbital::p},
		{3, chemistry::orbital::s},
		{3, chemistry::orbital::p},
		{4, chemistry::orbital::s},
		{3, chemistry::orbital::d},
		{4, chemistry::orbital::p},
		{5, chemistry::orbital::s},
		{4, chemistry::orbital::d},
		{5, chemistry::orbital::p},
		{6, chemistry::orbital::s},
		{4, chemistry::orbital::f},
		{5, chemistry::orbital::d},
		{6, chemistry::orbital::p},
		{7, chemistry::orbital::s},
		{5, chemistry::orbital::f},
		{6, chemistry::orbital::d},
		{7, chemistry::orbital::p}
	};

	atom::atom(chemistry::atom new_atom_specie, chemistry::atom_group new_group, int new_period, int new_z, int new_charge, int new_neutrons)
	{
		atom_specie = new_atom_specie;
		group = new_group;
		period = new_period;
		if(period < 1 || period > 7)
		{
			cerr << "Period outside the limits: " << period << " given" << endl;
		}
		z = new_z;
		neutrons = new_neutrons;
		electrons = z - new_charge;
		charge = new_charge;
		bonds = vector<weak_ptr<atom>>();
		orbitals = vector<orbital_group>();
		int electron_count = 0;
		int electron_configuration_position = 0;
		while(electron_count < electrons)
		{
			vector<int> new_orbital_configuration = electron_configuration_order[electron_configuration_position];
			int orbital_period = new_orbital_configuration[0];
			chemistry::orbital orbital_kind = chemistry::orbital(new_orbital_configuration[1]);
			orbital_group new_orbital_group = orbital_group(orbital_kind);
			int orbital_number_electrons;
			int orbital_kind_total_remaining = new_orbital_group.orbital_max;
			for(int i = 1; i <= new_orbital_group.orbital_max; i++)
			{
				int electron_difference = electrons - electron_count;
				if(electron_difference > orbital_kind_total_remaining)
				{
					orbital_number_electrons = 2;
				}
				else
				{
					orbital_number_electrons = 1;
				}
				orbital new_orbital = create_orbital(orbital_kind, orbital_period, orbital_number_electrons);
				new_orbital_group.add(new_orbital);
				orbital_kind_total_remaining--;
				electron_count += orbital_number_electrons;
			}
			orbitals.push_back(new_orbital_group);
			electron_configuration_position += 1;
		}
	}

	string atom::electronic_configuration()
	{
		ostringstream output;
		bool first = true;
		for(auto& orbital_group : orbitals)
		{
			if(!first)
			{
				output << " ";
			}
			output << orbital_group;
			first = false;
		}
		return output.str();
	}

	float atom::mass()
	{
		return chemistry::compounds::mass_proton * z + chemistry::compounds::mass_neutron * neutrons;
	}

	float atom::total_mass()
	{
		return mass() + chemistry::compounds::mass_electron * electrons;
	}
}

ostream& operator <<(ostream& os, const chemistry::atom& atom)
{
	ostringstream charge_representation;
	if(atom.charge > 0)
	{
		if(atom.charge > 1)
		{
			charge_representation << "+" << atom.charge;
		}
		else
		{
			charge_representation << "+";
		}
	}
	else if(atom.charge < 0)
	{
		if(atom.charge < 1)
		{
			charge_representation << "-" << atom.charge;
		}
		else
		{
			charge_representation << "-";
		}
	}
	return os << atom.symbol << charge_representation.str();
}
