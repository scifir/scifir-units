#ifndef CHEMISTRY_GENERAL_ATOMS_ATOMS_HPP_INCLUDED
#define CHEMISTRY_GENERAL_ATOMS_ATOMS_HPP_INCLUDED

using namespace std;

#include "atom.hpp"
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
#include "atoms_ac.hpp"
#include "atoms_la.hpp"

namespace msci
{
	atom* create_atom(const string&,int = 0);
	atom* create_atom(const string&,int,int);
}

#endif // CHEMISTRY_GENERAL_ATOMS_ATOMS_HPP_INCLUDED
