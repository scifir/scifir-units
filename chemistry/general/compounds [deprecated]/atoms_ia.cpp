#include "atoms_ia.hpp"
using namespace std;

namespace chemistry
{
	namespace compounds
	{
		H::H(int new_charge, int new_neutrons) : atom(chemistry::atom::H, chemistry::atom_group::IA, 1, 1, new_charge, new_neutrons)
		{
			name = "Hydrogen";
			symbol = "H";
			atomic_weight = 1.008;
		}

		Li::Li(int new_charge, int new_neutrons) : atom(chemistry::atom::Li, chemistry::atom_group::IA, 2, 3, new_charge, new_neutrons)
		{
			name = "Lithium";
			symbol = "Li";
			atomic_weight = 6.941;
		}

		Na::Na(int new_charge, int new_neutrons) : atom(chemistry::atom::Na, chemistry::atom_group::IA, 3, 11, new_charge, new_neutrons)
		{
			name = "Sodium";
			symbol = "Na";
			atomic_weight = 22.990;
		}

		K::K(int new_charge, int new_neutrons) : atom(chemistry::atom::K, chemistry::atom_group::IA, 4, 19, new_charge, new_neutrons)
		{
			name = "Potassium";
			symbol = "K";
			atomic_weight = 39.098;
		}

		Rb::Rb(int new_charge, int new_neutrons) : atom(chemistry::atom::Rb, chemistry::atom_group::IA, 5, 37, new_charge, new_neutrons)
		{
			name = "Rubidium";
			symbol = "Rb";
			atomic_weight = 84.468;
		}

		Cs::Cs(int new_charge, int new_neutrons) : atom(chemistry::atom::Cs, chemistry::atom_group::IA, 6, 55, new_charge, new_neutrons)
		{
			name = "Cesium";
			symbol = "Cs";
			atomic_weight = 132.905;
		}

		Fr::Fr(int new_charge, int new_neutrons) : atom(chemistry::atom::Fr, chemistry::atom_group::IA, 7, 87, new_charge, new_neutrons)
		{
			name = "Francium";
			symbol = "Fr";
			atomic_weight = 223.020;
		}
	}
}
