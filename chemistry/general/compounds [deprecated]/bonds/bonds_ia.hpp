#ifndef BONDS_IA_HPP_INCLUDED
#define BONDS_IA_HPP_INCLUDED

#include "physics/units.hpp"

using namespace std;
using namespace physics::units;

namespace chemistry
{
	map<atom_symbol,map<atom_symbol,length>> bound_length;
}

#endif // BONDS_IA_HPP_INCLUDED
