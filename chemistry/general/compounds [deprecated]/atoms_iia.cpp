#include "atoms_iia.hpp"
using namespace std;

namespace chemistry
{
	namespace compounds
	{
		Be::Be(int new_charge, int new_neutrons) : atom(chemistry::atom::Be, chemistry::atom_group::IIA, 2, 4, new_charge, new_neutrons)
		{
			name = "Beryllium";
			symbol = "Be";
			atomic_weight = 9.012;
		}

		Mg::Mg(int new_charge, int new_neutrons) : atom(chemistry::atom::Mg, chemistry::atom_group::IIA, 3, 12, new_charge, new_neutrons)
		{
			name = "Magnesium";
			symbol = "Mg";
			atomic_weight = 24.305;
		}

		Ca::Ca(int new_charge, int new_neutrons) : atom(chemistry::atom::Ca, chemistry::atom_group::IIA, 4, 20, new_charge, new_neutrons)
		{
			name = "Calcium";
			symbol = "Ca";
			atomic_weight = 40.078;
		}

		Sr::Sr(int new_charge, int new_neutrons) : atom(chemistry::atom::Sr, chemistry::atom_group::IIA, 5, 38, new_charge, new_neutrons)
		{
			name = "Strontium";
			symbol = "Sr";
			atomic_weight = 87.62;
		}

		Ba::Ba(int new_charge, int new_neutrons) : atom(chemistry::atom::Ba, chemistry::atom_group::IIA, 6, 56, new_charge, new_neutrons)
		{
			name = "Barium";
			symbol = "Ba";
			atomic_weight = 137.327;
		}

		Ra::Ra(int new_charge, int new_neutrons) : atom(chemistry::atom::Ra, chemistry::atom_group::IIA, 7, 88, new_charge, new_neutrons)
		{
			name = "Radium";
			symbol = "Ra";
			atomic_weight = 226.025;
		}
	}
}
