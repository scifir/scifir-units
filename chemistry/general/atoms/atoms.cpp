#include "./atoms.hpp"

namespace chemistry
{
	atom* create_atom(string new_atom,int new_ionic_charge)
	{
		if (new_atom == "H")
		{
			return new atom_H(new_ionic_charge);
		}
		else if (new_atom == "He")
		{
			return new atom_He(new_ionic_charge);
		}
		else if (new_atom == "Li")
		{
			return new atom_Li(new_ionic_charge);
		}
		else if (new_atom == "Be")
		{
			return new atom_Be(new_ionic_charge);
		}
		else if (new_atom == "B")
		{
			return new atom_B(new_ionic_charge);
		}
		else if (new_atom == "C")
		{
			return new atom_C(new_ionic_charge);
		}
		else if (new_atom == "N")
		{
			return new atom_N(new_ionic_charge);
		}
		else if (new_atom == "O")
		{
			return new atom_O(new_ionic_charge);
		}
		else if (new_atom == "F")
		{
			return new atom_F(new_ionic_charge);
		}
		else if (new_atom == "Ne")
		{
			return new atom_Ne(new_ionic_charge);
		}
		else if (new_atom == "Na")
		{
			return new atom_Na(new_ionic_charge);
		}
		else if (new_atom == "Mg")
		{
			return new atom_Mg(new_ionic_charge);
		}
		else if (new_atom == "Al")
		{
			return new atom_Al(new_ionic_charge);
		}
		else if (new_atom == "Si")
		{
			return new atom_Si(new_ionic_charge);
		}
		else if (new_atom == "P")
		{
			return new atom_P(new_ionic_charge);
		}
		else if (new_atom == "S")
		{
			return new atom_S(new_ionic_charge);
		}
		else if (new_atom == "Cl")
		{
			return new atom_Cl(new_ionic_charge);
		}
		else if (new_atom == "Ar")
		{
			return new atom_Ar(new_ionic_charge);
		}
		else if (new_atom == "K")
		{
			return new atom_K(new_ionic_charge);
		}
		else if (new_atom == "Ca")
		{
			return new atom_Ca(new_ionic_charge);
		}
		else if (new_atom == "Sc")
		{
			return new atom_Sc(new_ionic_charge);
		}
		else if (new_atom == "Ti")
		{
			return new atom_Ti(new_ionic_charge);
		}
		else if (new_atom == "V")
		{
			return new atom_V(new_ionic_charge);
		}
		else if (new_atom == "Cr")
		{
			return new atom_Cr(new_ionic_charge);
		}
		else if (new_atom == "Mn")
		{
			return new atom_Mn(new_ionic_charge);
		}
		else if (new_atom == "Fe")
		{
			return new atom_Fe(new_ionic_charge);
		}
		else if (new_atom == "Co")
		{
			return new atom_Co(new_ionic_charge);
		}
		else if (new_atom == "Ni")
		{
			return new atom_Ni(new_ionic_charge);
		}
		else if (new_atom == "Cu")
		{
			return new atom_Cu(new_ionic_charge);
		}
		else if (new_atom == "Zn")
		{
			return new atom_Zn(new_ionic_charge);
		}
		else if (new_atom == "Ga")
		{
			return new atom_Ga(new_ionic_charge);
		}
		else if (new_atom == "Ge")
		{
			return new atom_Ge(new_ionic_charge);
		}
		else if (new_atom == "As")
		{
			return new atom_As(new_ionic_charge);
		}
		else if (new_atom == "Se")
		{
			return new atom_Se(new_ionic_charge);
		}
		else if (new_atom == "Br")
		{
			return new atom_Br(new_ionic_charge);
		}
		else if (new_atom == "Kr")
		{
			return new atom_Kr(new_ionic_charge);
		}
		else if (new_atom == "Rb")
		{
			return new atom_Rb(new_ionic_charge);
		}
		else if (new_atom == "Sr")
		{
			return new atom_Sr(new_ionic_charge);
		}
		else if (new_atom == "Y")
		{
			return new atom_Y(new_ionic_charge);
		}
		else if (new_atom == "Zr")
		{
			return new atom_Zr(new_ionic_charge);
		}
		else if (new_atom == "Nb")
		{
			return new atom_Nb(new_ionic_charge);
		}
		else if (new_atom == "Mo")
		{
			return new atom_Mo(new_ionic_charge);
		}
		else if (new_atom == "Tc")
		{
			return new atom_Tc(new_ionic_charge);
		}
		else if (new_atom == "Ru")
		{
			return new atom_Ru(new_ionic_charge);
		}
		else if (new_atom == "Rh")
		{
			return new atom_Rh(new_ionic_charge);
		}
		else if (new_atom == "Pd")
		{
			return new atom_Pd(new_ionic_charge);
		}
		else if (new_atom == "Ag")
		{
			return new atom_Ag(new_ionic_charge);
		}
		else if (new_atom == "Cd")
		{
			return new atom_Cd(new_ionic_charge);
		}
		else if (new_atom == "In")
		{
			return new atom_In(new_ionic_charge);
		}
		else if (new_atom == "Sn")
		{
			return new atom_Sn(new_ionic_charge);
		}
		else if (new_atom == "Sb")
		{
			return new atom_Sb(new_ionic_charge);
		}
		else if (new_atom == "Te")
		{
			return new atom_Te(new_ionic_charge);
		}
		else if (new_atom == "I")
		{
			return new atom_I(new_ionic_charge);
		}
		else if (new_atom == "Xe")
		{
			return new atom_Xe(new_ionic_charge);
		}
		else if (new_atom == "Cs")
		{
			return new atom_Cs(new_ionic_charge);
		}
		else if (new_atom == "Ba")
		{
			return new atom_Ba(new_ionic_charge);
		}
		else if (new_atom == "Hf")
		{
			return new atom_Hf(new_ionic_charge);
		}
		else if (new_atom == "Ta")
		{
			return new atom_Ta(new_ionic_charge);
		}
		else if (new_atom == "W")
		{
			return new atom_W(new_ionic_charge);
		}
		else if (new_atom == "Re")
		{
			return new atom_Re(new_ionic_charge);
		}
		else if (new_atom == "Os")
		{
			return new atom_Os(new_ionic_charge);
		}
		else if (new_atom == "Ir")
		{
			return new atom_Ir(new_ionic_charge);
		}
		else if (new_atom == "Pt")
		{
			return new atom_Pt(new_ionic_charge);
		}
		else if (new_atom == "Au")
		{
			return new atom_Au(new_ionic_charge);
		}
		else if (new_atom == "Hg")
		{
			return new atom_Hg(new_ionic_charge);
		}
		else if (new_atom == "Tl")
		{
			return new atom_Tl(new_ionic_charge);
		}
		else if (new_atom == "Pb")
		{
			return new atom_Pb(new_ionic_charge);
		}
		else if (new_atom == "Bi")
		{
			return new atom_Bi(new_ionic_charge);
		}
		else if (new_atom == "Po")
		{
			return new atom_Po(new_ionic_charge);
		}
		else if (new_atom == "At")
		{
			return new atom_At(new_ionic_charge);
		}
		else if (new_atom == "Rn")
		{
			return new atom_Rn(new_ionic_charge);
		}
		else if (new_atom == "Fr")
		{
			return new atom_Fr(new_ionic_charge);
		}
		else if (new_atom == "Ra")
		{
			return new atom_Ra(new_ionic_charge);
		}
		else if (new_atom == "Rf")
		{
			return new atom_Rf(new_ionic_charge);
		}
		else if (new_atom == "Db")
		{
			return new atom_Db(new_ionic_charge);
		}
		else if (new_atom == "Sg")
		{
			return new atom_Sg(new_ionic_charge);
		}
		else if (new_atom == "Bh")
		{
			return new atom_Bh(new_ionic_charge);
		}
		else if (new_atom == "Hs")
		{
			return new atom_Hs(new_ionic_charge);
		}
		else if (new_atom == "Mt")
		{
			return new atom_Mt(new_ionic_charge);
		}
		else if (new_atom == "Ds")
		{
			return new atom_Ds(new_ionic_charge);
		}
		else if (new_atom == "Rg")
		{
			return new atom_Rg(new_ionic_charge);
		}
		else if (new_atom == "Cn")
		{
			return new atom_Cn(new_ionic_charge);
		}
		else if (new_atom == "Nh")
		{
			return new atom_Nh(new_ionic_charge);
		}
		else if (new_atom == "Fl")
		{
			return new atom_Fl(new_ionic_charge);
		}
		else if (new_atom == "Mc")
		{
			return new atom_Mc(new_ionic_charge);
		}
		else if (new_atom == "Lv")
		{
			return new atom_Lv(new_ionic_charge);
		}
		else if (new_atom == "Ts")
		{
			return new atom_Ts(new_ionic_charge);
		}
		else if (new_atom == "Og")
		{
			return new atom_Og(new_ionic_charge);
		}
		else if (new_atom == "La")
		{
			return new atom_La(new_ionic_charge);
		}
		else if (new_atom == "Ce")
		{
			return new atom_Ce(new_ionic_charge);
		}
		else if (new_atom == "Pr")
		{
			return new atom_Pr(new_ionic_charge);
		}
		else if (new_atom == "Nd")
		{
			return new atom_Nd(new_ionic_charge);
		}
		else if (new_atom == "Pm")
		{
			return new atom_Pm(new_ionic_charge);
		}
		else if (new_atom == "Sm")
		{
			return new atom_Sm(new_ionic_charge);
		}
		else if (new_atom == "Eu")
		{
			return new atom_Eu(new_ionic_charge);
		}
		else if (new_atom == "Gd")
		{
			return new atom_Gd(new_ionic_charge);
		}
		else if (new_atom == "Tb")
		{
			return new atom_Tb(new_ionic_charge);
		}
		else if (new_atom == "Dy")
		{
			return new atom_Dy(new_ionic_charge);
		}
		else if (new_atom == "Ho")
		{
			return new atom_Ho(new_ionic_charge);
		}
		else if (new_atom == "Er")
		{
			return new atom_Er(new_ionic_charge);
		}
		else if (new_atom == "Tm")
		{
			return new atom_Tm(new_ionic_charge);
		}
		else if (new_atom == "Yb")
		{
			return new atom_Yb(new_ionic_charge);
		}
		else if (new_atom == "Lu")
		{
			return new atom_Lu(new_ionic_charge);
		}
		else if (new_atom == "Ac")
		{
			return new atom_Ac(new_ionic_charge);
		}
		else if (new_atom == "Th")
		{
			return new atom_Th(new_ionic_charge);
		}
		else if (new_atom == "Pa")
		{
			return new atom_Pa(new_ionic_charge);
		}
		else if (new_atom == "U")
		{
			return new atom_U(new_ionic_charge);
		}
		else if (new_atom == "Np")
		{
			return new atom_Np(new_ionic_charge);
		}
		else if (new_atom == "Pu")
		{
			return new atom_Pu(new_ionic_charge);
		}
		else if (new_atom == "Am")
		{
			return new atom_Am(new_ionic_charge);
		}
		else if (new_atom == "Cm")
		{
			return new atom_Cm(new_ionic_charge);
		}
		else if (new_atom == "Bk")
		{
			return new atom_Bk(new_ionic_charge);
		}
		else if (new_atom == "Cf")
		{
			return new atom_Cf(new_ionic_charge);
		}
		else if (new_atom == "Es")
		{
			return new atom_Es(new_ionic_charge);
		}
		else if (new_atom == "Fm")
		{
			return new atom_Fm(new_ionic_charge);
		}
		else if (new_atom == "Md")
		{
			return new atom_Md(new_ionic_charge);
		}
		else if (new_atom == "No")
		{
			return new atom_No(new_ionic_charge);
		}
		else if (new_atom == "Lr")
		{
			return new atom_Lr(new_ionic_charge);
		}
	}

	atom* create_atom(string new_atom,int new_ionic_charge,int new_neutrons_number)
	{
		if (new_atom == "H")
		{
			return new atom_H(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "He")
		{
			return new atom_He(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Li")
		{
			return new atom_Li(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Be")
		{
			return new atom_Be(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "B")
		{
			return new atom_B(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "C")
		{
			return new atom_C(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "N")
		{
			return new atom_N(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "O")
		{
			return new atom_O(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "F")
		{
			return new atom_F(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ne")
		{
			return new atom_Ne(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Na")
		{
			return new atom_Na(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Mg")
		{
			return new atom_Mg(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Al")
		{
			return new atom_Al(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Si")
		{
			return new atom_Si(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "P")
		{
			return new atom_P(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "S")
		{
			return new atom_S(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Cl")
		{
			return new atom_Cl(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ar")
		{
			return new atom_Ar(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "K")
		{
			return new atom_K(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ca")
		{
			return new atom_Ca(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Sc")
		{
			return new atom_Sc(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ti")
		{
			return new atom_Ti(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "V")
		{
			return new atom_V(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Cr")
		{
			return new atom_Cr(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Mn")
		{
			return new atom_Mn(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Fe")
		{
			return new atom_Fe(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Co")
		{
			return new atom_Co(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ni")
		{
			return new atom_Ni(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Cu")
		{
			return new atom_Cu(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Zn")
		{
			return new atom_Zn(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ga")
		{
			return new atom_Ga(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ge")
		{
			return new atom_Ge(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "As")
		{
			return new atom_As(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Se")
		{
			return new atom_Se(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Br")
		{
			return new atom_Br(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Kr")
		{
			return new atom_Kr(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Rb")
		{
			return new atom_Rb(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Sr")
		{
			return new atom_Sr(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Y")
		{
			return new atom_Y(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Zr")
		{
			return new atom_Zr(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Nb")
		{
			return new atom_Nb(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Mo")
		{
			return new atom_Mo(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Tc")
		{
			return new atom_Tc(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ru")
		{
			return new atom_Ru(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Rh")
		{
			return new atom_Rh(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Pd")
		{
			return new atom_Pd(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ag")
		{
			return new atom_Ag(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Cd")
		{
			return new atom_Cd(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "In")
		{
			return new atom_In(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Sn")
		{
			return new atom_Sn(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Sb")
		{
			return new atom_Sb(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Te")
		{
			return new atom_Te(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "I")
		{
			return new atom_I(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Xe")
		{
			return new atom_Xe(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Cs")
		{
			return new atom_Cs(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ba")
		{
			return new atom_Ba(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Hf")
		{
			return new atom_Hf(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ta")
		{
			return new atom_Ta(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "W")
		{
			return new atom_W(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Re")
		{
			return new atom_Re(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Os")
		{
			return new atom_Os(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ir")
		{
			return new atom_Ir(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Pt")
		{
			return new atom_Pt(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Au")
		{
			return new atom_Au(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Hg")
		{
			return new atom_Hg(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Tl")
		{
			return new atom_Tl(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Pb")
		{
			return new atom_Pb(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Bi")
		{
			return new atom_Bi(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Po")
		{
			return new atom_Po(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "At")
		{
			return new atom_At(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Rn")
		{
			return new atom_Rn(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Fr")
		{
			return new atom_Fr(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ra")
		{
			return new atom_Ra(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Rf")
		{
			return new atom_Rf(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Db")
		{
			return new atom_Db(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Sg")
		{
			return new atom_Sg(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Bh")
		{
			return new atom_Bh(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Hs")
		{
			return new atom_Hs(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Mt")
		{
			return new atom_Mt(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ds")
		{
			return new atom_Ds(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Rg")
		{
			return new atom_Rg(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Cn")
		{
			return new atom_Cn(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Nh")
		{
			return new atom_Nh(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Fl")
		{
			return new atom_Fl(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Mc")
		{
			return new atom_Mc(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Lv")
		{
			return new atom_Lv(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ts")
		{
			return new atom_Ts(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Og")
		{
			return new atom_Og(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "La")
		{
			return new atom_La(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ce")
		{
			return new atom_Ce(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Pr")
		{
			return new atom_Pr(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Nd")
		{
			return new atom_Nd(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Pm")
		{
			return new atom_Pm(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Sm")
		{
			return new atom_Sm(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Eu")
		{
			return new atom_Eu(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Gd")
		{
			return new atom_Gd(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Tb")
		{
			return new atom_Tb(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Dy")
		{
			return new atom_Dy(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ho")
		{
			return new atom_Ho(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Er")
		{
			return new atom_Er(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Tm")
		{
			return new atom_Tm(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Yb")
		{
			return new atom_Yb(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Lu")
		{
			return new atom_Lu(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Ac")
		{
			return new atom_Ac(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Th")
		{
			return new atom_Th(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Pa")
		{
			return new atom_Pa(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "U")
		{
			return new atom_U(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Np")
		{
			return new atom_Np(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Pu")
		{
			return new atom_Pu(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Am")
		{
			return new atom_Am(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Cm")
		{
			return new atom_Cm(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Bk")
		{
			return new atom_Bk(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Cf")
		{
			return new atom_Cf(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Es")
		{
			return new atom_Es(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Fm")
		{
			return new atom_Fm(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Md")
		{
			return new atom_Md(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "No")
		{
			return new atom_No(new_ionic_charge,new_neutrons_number);
		}
		else if (new_atom == "Lr")
		{
			return new atom_Lr(new_ionic_charge,new_neutrons_number);
		}
	}
}
