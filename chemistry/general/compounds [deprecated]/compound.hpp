#ifndef COMPOUND_HPP_INCLUDED
#define COMPOUND_HPP_INCLUDED

#include "atom.hpp"

#include <string>
#include <map>
#include <vector>
using namespace std;

namespace chemistry
{
	namespace compounds
	{
		class compound
		{
			public:
				compound(string);

				float mass();
				float total_mass();
				int atom_number();
				float atom_percentage(chemistry::atom);
				bool is_organic();

			private:
				vector<map<int,bound>> bonds;
				vector<atom> atoms;
				string nomenclature_structure;
		};
	}
}

#endif // COMPOUND_HPP_INCLUDED
