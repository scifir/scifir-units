#include "chemical_reaction.hpp"

using namespace std;

namespace chemistry
{
	chemical_reaction::chemical_reaction()
	{
	}

	physics::units::enthalpy chemical_reaction::get_enthalpy_change() const
	{
		return physics::units::enthalpy(0);
	}

	physics::units::entropy chemical_reaction::get_entropy_change() const
	{
		return physics::units::entropy(0);
	}
}
