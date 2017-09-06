#include "atom.hpp"

#include <cmath>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

namespace chemistry
{
	vector<vector<int>> electronic_configuration_order
	{
		{1, atomic_orbital_s},
		{2, atomic_orbital_s},
		{2, atomic_orbital_p},
		{3, atomic_orbital_s},
		{3, atomic_orbital_p},
		{4, atomic_orbital_s},
		{3, atomic_orbital_d},
		{4, atomic_orbital_p},
		{5, atomic_orbital_s},
		{4, atomic_orbital_d},
		{5, atomic_orbital_p},
		{6, atomic_orbital_s},
		{4, atomic_orbital_f},
		{5, atomic_orbital_d},
		{6, atomic_orbital_p},
		{7, atomic_orbital_s},
		{5, atomic_orbital_f},
		{6, atomic_orbital_d},
		{7, atomic_orbital_p}
	};

	atom::atom() : bonds()
	{
	}

	informatics::color atom::get_atomic_color() const
    {
		if (get_z() == 1)
		{
			return informatics::color(239,239,239);
		}
		switch(get_atomic_group())
		{
		case IA:
			return informatics::color(244,212,66);
		case IIA:
			return informatics::color(244,128,66);
		case IIIA:
			return informatics::color(66,197,244);
		case IVA:
			return informatics::color(40,40,40);
		case VA:
			return informatics::color(43,145,79);
		case VIA:
			return informatics::color(244,66,66);
		case VIIA:
			return informatics::color(244,66,220);
		}
		return informatics::color(70,70,70);
    }

	atomic_pattern atom::get_atomic_pattern() const
	{
		switch(get_period())
		{
		case 1:
			return atomic_pattern::none;
		case 2:
			return atomic_pattern::none;
		case 3:
			return atomic_pattern::line;
		case 4:
			return atomic_pattern::prepicated_line;
		case 5:
			return atomic_pattern::wave_line;
		case 6:
			return atomic_pattern::prepicated_wave_line;
		case 7:
			return atomic_pattern::circles;
		}
	}

	molecular_geometry atom::get_molecular_geometry() const
	{
		// Check number of bonds and of unpaired electrons
		if (get_bonds_number() == 2)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::linear;
			}
			else if(get_lone_pairs() == 1)
			{
				return molecular_geometry::bent;
			}
			else if(get_lone_pairs() == 2)
			{
				return molecular_geometry::bent;
			}
			else if(get_lone_pairs() == 3)
			{
				return molecular_geometry::linear;
			}
		}
		else if(get_bonds_number() == 3)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::trigonal_planar;
			}
			else if(get_lone_pairs() == 1)
			{
				return molecular_geometry::trigonal_pyramidal;
			}
			else if(get_lone_pairs() == 2)
			{
				return molecular_geometry::t_shaped;
			}
		}
		else if(get_bonds_number() == 4)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::tetrahedral;
			}
			else if(get_lone_pairs() == 1)
			{
				return molecular_geometry::seesaw;
			}
			else if(get_lone_pairs() == 2)
			{
				return molecular_geometry::square_planar;
			}
		}
		else if(get_bonds_number() == 5)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::trigonal_bipyramidal;
			}
			else if(get_lone_pairs() == 1)
			{
				return molecular_geometry::square_pyramidal;
			}
			else if(get_lone_pairs() == 2)
			{
				return molecular_geometry::planar_pentagonal;
			}
		}
		else if(get_bonds_number() == 6)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::octahedral;
			}
			else if(get_lone_pairs() == 1)
			{
				return molecular_geometry::pentagonal_pyramidal;
			}
		}
		else if(get_bonds_number() == 7)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::pentagonal_bipyramidal;
			}
		}
		else if(get_bonds_number() == 8)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::square_antipristamic;
			}
		}
		else if(get_bonds_number() == 9)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::tricapped_trigonal_prismatic;
			}
		}
		throw "No atomic geometry found. Bonds number: " + to_string(get_bonds_number()) + ", lone pairs: " + to_string(get_lone_pairs());
	}

	bool atom::is_valence_full() const
			{
				if(is_atomic_group_a())
				{
					if(get_valence_electrons_number() == 2 or get_valence_electrons_number() == 8)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				return false;
			}

	bool atom::is_chiral() const
	{

	}

	math::angle_number get_molecular_geometry_angle(const atom& x,edge_position position1,edge_position position2)
	{
		switch (x.get_molecular_geometry())
		{
		case molecular_geometry::linear:
			return math::angle_number(180);
		case molecular_geometry::bent:
			if (x.get_lone_pairs() == 1)
			{
				return math::angle_number(120);
			}
			else if(x.get_lone_pairs() == 2)
			{
				return math::angle_number(109.5);
			}
		case molecular_geometry::trigonal_planar:
			return math::angle_number(120);
		case molecular_geometry::trigonal_pyramidal:
			return math::angle_number(109.5);
		case molecular_geometry::t_shaped:
			if ((position1 == edge_position::t_shaped_ax and position2 == edge_position::t_shaped_eq) or (position1 == edge_position::t_shaped_eq and position2 == edge_position::t_shaped_ax))
			{
				return math::angle_number(90);
			}
			else if (position1 == edge_position::t_shaped_ax and position2 == edge_position::t_shaped_ax)
			{
				return math::angle_number(180);
			}
		case molecular_geometry::tetrahedral:
			return math::angle_number(109.5);
		case molecular_geometry::seesaw:
			if (position1 == edge_position::seesaw_ax and position2 == edge_position::seesaw_ax)
			{
				return math::angle_number(173.1);
			}
			else if (position1 == edge_position::seesaw_eq and position2 == edge_position::seesaw_eq)
			{
				return math::angle_number(101.6);
			}
			else if ((position1 == edge_position::seesaw_ax and position2 == edge_position::seesaw_eq) or (position2 == edge_position::seesaw_ax and position1 == edge_position::seesaw_eq))
			{
				return math::angle_number(90);
			}
		case molecular_geometry::square_planar:
			return math::angle_number(90);
		case molecular_geometry::trigonal_bipyramidal:
			if (position1 == edge_position::trigonal_bipyramidal_ax and position2 == edge_position::trigonal_bipyramidal_ax)
			{
				return math::angle_number(180);
			}
			else if ((position1 == edge_position::trigonal_bipyramidal_ax and position2 == edge_position::trigonal_bipyramidal_eq) or (position1 == edge_position::trigonal_bipyramidal_eq and position2 == edge_position::trigonal_bipyramidal_ax))
			{
				return math::angle_number(90);
			}
			else if (position1 == edge_position::trigonal_bipyramidal_eq and position2 == edge_position::trigonal_bipyramidal_eq)
			{
				return math::angle_number(120);
			}
		case molecular_geometry::square_pyramidal:
			return math::angle_number(90);
		case molecular_geometry::planar_pentagonal:
			return math::angle_number(72);
		case molecular_geometry::octahedral:
			return math::angle_number(90);
		case molecular_geometry::pentagonal_pyramidal:
			if ((position1 == edge_position::pentagonal_pyramidal_ax and position2 == edge_position::pentagonal_pyramidal_eq) or (position1 == edge_position::pentagonal_pyramidal_eq and position2 == edge_position::pentagonal_pyramidal_ax))
			{
				return math::angle_number(90);
			}
			else if (position1 == edge_position::pentagonal_pyramidal_eq and position2 == edge_position::pentagonal_pyramidal_eq)
			{
				return math::angle_number(72);
			}
		case molecular_geometry::pentagonal_bipyramidal:
			if (position1 == edge_position::pentagonal_bipyramidal_ax and position2 == edge_position::pentagonal_bipyramidal_ax)
			{
				return math::angle_number(180);
			}
			else if (position1 == edge_position::pentagonal_bipyramidal_eq and position2 == edge_position::pentagonal_bipyramidal_eq)
			{
				return math::angle_number(72);
			}
			else if ((position1 == edge_position::pentagonal_bipyramidal_ax and position2 == edge_position::pentagonal_bipyramidal_eq) or (position1 == edge_position::pentagonal_bipyramidal_eq and position2 == edge_position::pentagonal_bipyramidal_ax))
			{
				return math::angle_number(90);
			}
		case molecular_geometry::square_antipristamic:
			return math::angle_number(50); // TODO: Finish this calculation
		case molecular_geometry::tricapped_trigonal_prismatic:
			return math::angle_number(50); // TODO: Finish this calculation
		}
	}

	bool are_isotopes(const atom& x,const atom& y)
	{
		return (x.get_z() == y.get_z() and x.get_mass_number() != y.get_mass_number());
	}

	bool are_isobares(const atom& x,const atom& y)
	{
		return (x.get_mass_number() == y.get_mass_number() and x.get_z() != y.get_z());
	}

	bool are_isoelectronics(const atom& x,const atom& y)
	{
		return (x.get_electronic_configuration() == y.get_electronic_configuration());
	}

	bool same_element(const atom& x,const atom& y)
	{
		return (x.get_z() == y.get_z() and x.get_mass_number() == y.get_mass_number());
	}

	bool same_specimen(const atom& x,const atom& y)
	{
		return (x.get_enum_type() == y.get_enum_type());
	}

	atom* get_atom(string atom_specie)
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
}

bool operator ==(const chemistry::atom& x,const chemistry::atom& y)
{
	return (x.get_z() == y.get_z() and x.get_mass_number() == y.get_mass_number() and chemistry::are_isoelectronics(x,y));
}

bool operator !=(const chemistry::atom& x,const chemistry::atom& y)
{
	return !(x == y);
}

wostream& operator <<(wostream& os,const chemistry::atom& x)
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
