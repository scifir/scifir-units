#include "normal_molecule.hpp"

using namespace std;

namespace chemistry
{
	vector<shared_ptr<atom>> normal_molecule::get_atoms() const
	{
		return atoms;
	}

	vector<shared_ptr<atomic_bond>> normal_molecule::get_bonds() const
	{
		return bonds;
	}

	vector<vector<bool>> normal_molecule::get_bonds_graph() const
	{
		return bonds_graph;
	}

	int normal_molecule::get_total_atoms() const
	{
		return atoms.size();
	}
}
