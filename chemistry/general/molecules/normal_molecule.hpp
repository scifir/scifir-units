#ifndef NORMAL_MOLECULE_HPP_INCLUDED
#define NORMAL_MOLECULE_HPP_INCLUDED

#include <memory>
#include <string>
#include <vector>

#include "chemistry/general/molecules/molecule.hpp"

using namespace std;

namespace chemistry
{
	class normal_molecule : public molecule
	{
		public:
			normal_molecule(string);

			virtual vector<shared_ptr<atom>> get_atoms() const;
			virtual vector<shared_ptr<atomic_bond>> get_bonds() const;
			virtual vector<vector<bool>> get_bonds_graph() const;
			virtual int get_total_atoms() const;

			virtual void save(string,string) const;

		private:
			vector<shared_ptr<atom>> atoms;
			vector<shared_ptr<atomic_bond>> bonds;
			vector<vector<bool>> bonds_graph;
	};
}

#endif // NORMAL_MOLECULE_HPP_INCLUDED
