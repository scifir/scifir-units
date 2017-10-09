#include "chemical_reaction.hpp"

using namespace std;

namespace msci
{
	chemical_reaction::chemical_reaction() : reactants(),products()
	{
	}

	msci::enthalpy chemical_reaction::get_enthalpy_change() const
	{
		return msci::enthalpy(0);
	}

	msci::entropy chemical_reaction::get_entropy_change() const
	{
		return msci::entropy(0);
	}
}
