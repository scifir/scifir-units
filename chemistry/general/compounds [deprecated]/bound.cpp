#include "bound.hpp"

using namespace std;

namespace chemistry
{
	const bound_kind& bound::kind() const
	{
		if (atom.lock()->is_non_metallic() and atom2.lock()->is_metallic())
		{
			return ionic;
		}
		else if(atom1.lock()->is_non_metallic() and atom2.lock()->is_non_metallic())
		{
			return covalent;
		}
		else if(atom1.lock()->is_metallic() and atom2.lock()->is_metallic())
		{
			return metallic;
		}
	}

	int bound::total_electrons() const
	{
		if (weight() == bound_weight::simple)
		{
			return 2;
		}
		else if (weight() == bound_weight::double)
		{
			return 4;
		}
		else if (weight() == bound_weight::triple)
		{
			return 6;
		}
	}
}
