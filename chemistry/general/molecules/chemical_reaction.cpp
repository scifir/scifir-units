#include "chemical_reaction.hpp"

using namespace std;

namespace msci
{
	chemical_reaction::chemical_reaction()
	{
	}

	msci::units::enthalpy chemical_reaction::get_enthalpy_change() const
	{
		return msci::units::enthalpy(0);
	}

	msci::units::entropy chemical_reaction::get_entropy_change() const
	{
		return msci::units::entropy(0);
	}
}
