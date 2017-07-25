#include "atom.hpp"
#include "compound.hpp"
using namespace std;

namespace chemistry
{
	namespace compounds
	{
		compound::compound(string structure)
		{
			nomenclature_structure = structure;
		}

		float compound::atom_percentage(chemistry::atom atom)
		{
			return 0;
		}

		bool compound::is_organic()
		{
			if(atom_percentage(chemistry::atom::C) > 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
