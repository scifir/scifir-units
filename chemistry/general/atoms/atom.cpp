#include "atom.hpp"
#include "../molecules/atomic_bond.hpp"

#include <cmath>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

namespace msci
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

	void atom::add_bond(const shared_ptr<atomic_bond>& x)
	{
		shared_ptr<atom> bond_atom1 = x->get_atom1().lock();
		shared_ptr<atom> bond_atom2 = x->get_atom2().lock();
		if (this == &*bond_atom1 or this == &*bond_atom2)
		{
			bonds.push_back(weak_ptr<atomic_bond>(x));
		}
	}

	bool atom::bonded_to(const atom& x) const
	{
		if (this == &x)
		{
			return false;
		}
		for (const auto& bond : bonds)
		{
			shared_ptr<atomic_bond> bond_lock = bond.lock();
			shared_ptr<atom> atom1_lock = bond_lock->get_atom1().lock();
			shared_ptr<atom> atom2_lock = bond_lock->get_atom2().lock();
			if (&x == &*atom1_lock or &x == &*atom2_lock)
			{
				return true;
			}
		}
		return false;
	}

	shared_ptr<atomic_bond> atom::get_bond_of(const atom& x) const
	{
		if (this == &x)
		{
			return nullptr;
		}
		for (const auto& bond : bonds)
		{
			shared_ptr<atomic_bond> bond_lock = bond.lock();
			shared_ptr<atom> atom1_lock = bond_lock->get_atom1().lock();
			shared_ptr<atom> atom2_lock = bond_lock->get_atom2().lock();
			if (&x == &*atom1_lock or &x == &*atom2_lock)
			{
				return bond_lock;
			}
		}
		return nullptr;
	}

	msci::color atom::get_atomic_color() const
    {
		if (get_z() == 1)
		{
			return msci::color(239,239,239);
		}
		switch(get_atomic_group())
		{
		case IA:
			return msci::color(244,212,66);
		case IIA:
			return msci::color(244,128,66);
		case IIIA:
			return msci::color(66,197,244);
		case IVA:
			return msci::color(40,40,40);
		case VA:
			return msci::color(43,145,79);
		case VIA:
			return msci::color(244,66,66);
		case VIIA:
			return msci::color(244,66,220);
		}
		return msci::color(70,70,70);
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
		return atomic_pattern::none;
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
		throw "No atomic geometry found. Bonds number: " + std::to_string(get_bonds_number()) + ", lone pairs: " + std::to_string(get_lone_pairs());
	}

	bool atom::is_valence_full() const
	{
		if(is_atomic_group_a())
		{
			if((is_atom_specimen(atom_symbol::H) or is_atom_specimen(atom_symbol::He)) and get_valence_electrons_number() == 2)
			{
				return true;
			}
			else if(get_valence_electrons_number() == 8)
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
		return true;
	}

	msci::angle_number get_molecular_geometry_angle(const atom& x,edge_position position1,edge_position position2)
	{
		switch (x.get_molecular_geometry())
		{
		case molecular_geometry::linear:
			return msci::angle_number(180);
		case molecular_geometry::bent:
			if (x.get_lone_pairs() == 1)
			{
				return msci::angle_number(120);
			}
			else if(x.get_lone_pairs() == 2)
			{
				return msci::angle_number(109.5);
			}
		case molecular_geometry::trigonal_planar:
			return msci::angle_number(120);
		case molecular_geometry::trigonal_pyramidal:
			return msci::angle_number(109.5);
		case molecular_geometry::t_shaped:
			if ((position1 == edge_position::t_shaped_ax and position2 == edge_position::t_shaped_eq) or (position1 == edge_position::t_shaped_eq and position2 == edge_position::t_shaped_ax))
			{
				return msci::angle_number(90);
			}
			else if (position1 == edge_position::t_shaped_ax and position2 == edge_position::t_shaped_ax)
			{
				return msci::angle_number(180);
			}
		case molecular_geometry::tetrahedral:
			return msci::angle_number(109.5);
		case molecular_geometry::seesaw:
			if (position1 == edge_position::seesaw_ax and position2 == edge_position::seesaw_ax)
			{
				return msci::angle_number(173.1);
			}
			else if (position1 == edge_position::seesaw_eq and position2 == edge_position::seesaw_eq)
			{
				return msci::angle_number(101.6);
			}
			else if ((position1 == edge_position::seesaw_ax and position2 == edge_position::seesaw_eq) or (position2 == edge_position::seesaw_ax and position1 == edge_position::seesaw_eq))
			{
				return msci::angle_number(90);
			}
		case molecular_geometry::square_planar:
			return msci::angle_number(90);
		case molecular_geometry::trigonal_bipyramidal:
			if (position1 == edge_position::trigonal_bipyramidal_ax and position2 == edge_position::trigonal_bipyramidal_ax)
			{
				return msci::angle_number(180);
			}
			else if ((position1 == edge_position::trigonal_bipyramidal_ax and position2 == edge_position::trigonal_bipyramidal_eq) or (position1 == edge_position::trigonal_bipyramidal_eq and position2 == edge_position::trigonal_bipyramidal_ax))
			{
				return msci::angle_number(90);
			}
			else if (position1 == edge_position::trigonal_bipyramidal_eq and position2 == edge_position::trigonal_bipyramidal_eq)
			{
				return msci::angle_number(120);
			}
		case molecular_geometry::square_pyramidal:
			return msci::angle_number(90);
		case molecular_geometry::planar_pentagonal:
			return msci::angle_number(72);
		case molecular_geometry::octahedral:
			return msci::angle_number(90);
		case molecular_geometry::pentagonal_pyramidal:
			if ((position1 == edge_position::pentagonal_pyramidal_ax and position2 == edge_position::pentagonal_pyramidal_eq) or (position1 == edge_position::pentagonal_pyramidal_eq and position2 == edge_position::pentagonal_pyramidal_ax))
			{
				return msci::angle_number(90);
			}
			else if (position1 == edge_position::pentagonal_pyramidal_eq and position2 == edge_position::pentagonal_pyramidal_eq)
			{
				return msci::angle_number(72);
			}
		case molecular_geometry::pentagonal_bipyramidal:
			if (position1 == edge_position::pentagonal_bipyramidal_ax and position2 == edge_position::pentagonal_bipyramidal_ax)
			{
				return msci::angle_number(180);
			}
			else if (position1 == edge_position::pentagonal_bipyramidal_eq and position2 == edge_position::pentagonal_bipyramidal_eq)
			{
				return msci::angle_number(72);
			}
			else if ((position1 == edge_position::pentagonal_bipyramidal_ax and position2 == edge_position::pentagonal_bipyramidal_eq) or (position1 == edge_position::pentagonal_bipyramidal_eq and position2 == edge_position::pentagonal_bipyramidal_ax))
			{
				return msci::angle_number(90);
			}
		case molecular_geometry::square_antipristamic:
			return msci::angle_number(50);
		case molecular_geometry::tricapped_trigonal_prismatic:
			return msci::angle_number(50);
		}
		return msci::angle_number(180);
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

	string to_string(const atom_symbol& x)
	{
		switch (x)
		{
			case atom_symbol::H:
				return "H";
			case atom_symbol::He:
				return "He";
			case atom_symbol::Li:
				return "Li";
			case atom_symbol::Be:
				return "Be";
			case atom_symbol::B:
				return "B";
			case atom_symbol::C:
				return "C";
			case atom_symbol::N:
				return "N";
			case atom_symbol::O:
				return "O";
			case atom_symbol::F:
				return "F";
			case atom_symbol::Ne:
				return "Ne";
			case atom_symbol::Na:
				return "Na";
			case atom_symbol::Mg:
				return "Mg";
			case atom_symbol::Al:
				return "Al";
			case atom_symbol::Si:
				return "Si";
			case atom_symbol::P:
				return "P";
			case atom_symbol::S:
				return "S";
			case atom_symbol::Cl:
				return "Cl";
			case atom_symbol::Ar:
				return "Ar";
			case atom_symbol::K:
				return "K";
			case atom_symbol::Ca:
				return "Ca";
			case atom_symbol::Sc:
				return "Sc";
			case atom_symbol::Ti:
				return "Ti";
			case atom_symbol::V:
				return "V";
			case atom_symbol::Cr:
				return "Cr";
			case atom_symbol::Mn:
				return "Mn";
			case atom_symbol::Fe:
				return "Fe";
			case atom_symbol::Co:
				return "Co";
			case atom_symbol::Ni:
				return "Ni";
			case atom_symbol::Cu:
				return "Cu";
			case atom_symbol::Zn:
				return "Zn";
			case atom_symbol::Ga:
				return "Ga";
			case atom_symbol::Ge:
				return "Ge";
			case atom_symbol::As:
				return "As";
			case atom_symbol::Se:
				return "Se";
			case atom_symbol::Br:
				return "Br";
			case atom_symbol::Kr:
				return "Kr";
			case atom_symbol::Rb:
				return "Rb";
			case atom_symbol::Sr:
				return "Sr";
			case atom_symbol::Y:
				return "Y";
			case atom_symbol::Zr:
				return "Zr";
			case atom_symbol::Nb:
				return "Nb";
			case atom_symbol::Mo:
				return "Mo";
			case atom_symbol::Tc:
				return "Tc";
			case atom_symbol::Ru:
				return "Ru";
			case atom_symbol::Rh:
				return "Rh";
			case atom_symbol::Pd:
				return "Pd";
			case atom_symbol::Ag:
				return "Ag";
			case atom_symbol::Cd:
				return "Cd";
			case atom_symbol::In:
				return "In";
			case atom_symbol::Sn:
				return "Sn";
			case atom_symbol::Sb:
				return "Sb";
			case atom_symbol::Te:
				return "Te";
			case atom_symbol::I:
				return "I";
			case atom_symbol::Xe:
				return "Xe";
			case atom_symbol::Cs:
				return "Cs";
			case atom_symbol::Ba:
				return "Ba";
			case atom_symbol::La:
				return "La";
			case atom_symbol::Ce:
				return "Ce";
			case atom_symbol::Pr:
				return "Pr";
			case atom_symbol::Nd:
				return "Nd";
			case atom_symbol::Pm:
				return "Pm";
			case atom_symbol::Sm:
				return "Sm";
			case atom_symbol::Eu:
				return "Eu";
			case atom_symbol::Gd:
				return "Gd";
			case atom_symbol::Tb:
				return "Tb";
			case atom_symbol::Dy:
				return "Dy";
			case atom_symbol::Ho:
				return "Ho";
			case atom_symbol::Er:
				return "Er";
			case atom_symbol::Tm:
				return "Tm";
			case atom_symbol::Yb:
				return "Yb";
			case atom_symbol::Lu:
				return "Lu";
			case atom_symbol::Hf:
				return "Hf";
			case atom_symbol::Ta:
				return "Ta";
			case atom_symbol::W:
				return "W";
			case atom_symbol::Re:
				return "Re";
			case atom_symbol::Os:
				return "Os";
			case atom_symbol::Ir:
				return "Ir";
			case atom_symbol::Pt:
				return "Pt";
			case atom_symbol::Au:
				return "Au";
			case atom_symbol::Hg:
				return "Hg";
			case atom_symbol::Tl:
				return "Tl";
			case atom_symbol::Pb:
				return "Pb";
			case atom_symbol::Bi:
				return "Bi";
			case atom_symbol::Po:
				return "Po";
			case atom_symbol::At:
				return "At";
			case atom_symbol::Rn:
				return "Rn";
			case atom_symbol::Fr:
				return "Fr";
			case atom_symbol::Ra:
				return "Ra";
			case atom_symbol::Ac:
				return "Ac";
			case atom_symbol::Th:
				return "Th";
			case atom_symbol::Pa:
				return "Pa";
			case atom_symbol::U:
				return "U";
			case atom_symbol::Np:
				return "Np";
			case atom_symbol::Pu:
				return "Pu";
			case atom_symbol::Am:
				return "Am";
			case atom_symbol::Cm:
				return "Cm";
			case atom_symbol::Bk:
				return "Bk";
			case atom_symbol::Cf:
				return "Cf";
			case atom_symbol::Es:
				return "Es";
			case atom_symbol::Fm:
				return "Fm";
			case atom_symbol::Md:
				return "Md";
			case atom_symbol::No:
				return "No";
			case atom_symbol::Lr:
				return "Lr";
			case atom_symbol::Rf:
				return "Rf";
			case atom_symbol::Db:
				return "Db";
			case atom_symbol::Sg:
				return "Sg";
			case atom_symbol::Bh:
				return "Bh";
			case atom_symbol::Hs:
				return "Hs";
			case atom_symbol::Mt:
				return "Mt";
			case atom_symbol::Ds:
				return "Ds";
			case atom_symbol::Rg:
				return "Rg";
			case atom_symbol::Cn:
				return "Cn";
			case atom_symbol::Nh:
				return "Nh";
			case atom_symbol::Fl:
				return "Fl";
			case atom_symbol::Mc:
				return "Mc";
			case atom_symbol::Lv:
				return "Lv";
			case atom_symbol::Ts:
				return "Ts";
			case atom_symbol::Og:
				return "Og";
		}
	}

	string to_string(const atomic_group& x)
	{
		switch (x)
		{
			case IA:
				return "IA";
			case IIA:
				return "IIA";
			case IIIA:
				return "IIIA";
			case IVA:
				return "IVA";
			case VA:
				return "VA";
			case VIA:
				return "VIA";
			case VIIA:
				return "VIIA";
			case VIIIA:
				return "VIIIA";
			case IB:
				return "IB";
			case IIB:
				return "IIB";
			case IIIB:
				return "IIIB";
			case IVB:
				return "IVB";
			case VB:
				return "VB";
			case VIB:
				return "VIB";
			case VIIB:
				return "VIIB";
			case VIIIB:
				return "VIIIB";
			case AC:
				return "AC";
			case LA:
				return "LA";
		}
	}

	string to_string(const atomic_block& x)
	{
		switch (x)
		{
			case atomic_block::s:
				return "s";
			case atomic_block::p:
				return "p";
			case atomic_block::d:
				return "d";
			case atomic_block::f:
				return "f";
		}
	}
}

bool operator ==(const msci::atom& x,const msci::atom& y)
{
	return (x.get_z() == y.get_z() and x.get_mass_number() == y.get_mass_number() and msci::are_isoelectronics(x,y));
}

bool operator !=(const msci::atom& x,const msci::atom& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const msci::atom& x)
{
	ostringstream charge_text;
	if (x.get_ionic_charge() < 0)
	{
		charge_text << abs(x.get_ionic_charge()) << "-";
	}
	else if (x.get_ionic_charge() > 0)
	{
		charge_text << abs(x.get_ionic_charge()) << "+";
	}
	return os << x.get_symbol().c_str() << charge_text.str();
}
