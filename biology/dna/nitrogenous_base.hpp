#ifndef NITROGENOUS_BASE_HPP_INCLUDED
#define NITROGENOUS_BASE_HPP_INCLUDED

#include "chemistry/general/molecules/normal_molecule.hpp"

#include <string>
using namespace std;

namespace msci
{
	class nitrogenous_base
	{
		public:
			msci::normal_molecule molecule;

			nitrogenous_base();
			nitrogenous_base(const string&);
	};
}

#endif // NITROGENOUS_BASE_HPP_INCLUDED
