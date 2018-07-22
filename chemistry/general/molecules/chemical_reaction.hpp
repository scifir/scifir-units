#ifndef CHEMISTRY_GENERAL_MOLECULES_CHEMICAL_REACTION_HPP_INCLUDED
#define CHEMISTRY_GENERAL_MOLECULES_CHEMICAL_REACTION_HPP_INCLUDED

#include "chemistry/general/atoms.hpp"
#include "molecule.hpp"

#include "units.hpp"

using namespace std;

namespace msci
{
	class chemical_reaction
	{
		public:
			chemical_reaction();

			inline const vector<boost::variant<shared_ptr<molecule>,shared_ptr<atom>>>& get_reactants() const
			{
				return reactants;
			}

			inline const vector<boost::variant<shared_ptr<molecule>,shared_ptr<atom>>>& get_products() const
			{
				return products;
			}

			msci::enthalpy get_enthalpy_change() const;
			msci::entropy get_entropy_change() const;

		private:
			vector<boost::variant<shared_ptr<molecule>,shared_ptr<atom>>> reactants;
			vector<boost::variant<shared_ptr<molecule>,shared_ptr<atom>>> products;
	};
}

#endif // CHEMISTRY_GENERAL_MOLECULES_CHEMICAL_REACTION_HPP_INCLUDED
