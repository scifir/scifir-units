#ifndef NITROGENOUS_BASE_HPP_INCLUDED
#define NITROGENOUS_BASE_HPP_INCLUDED

#include "chemistry/general/compounds/compound.hpp"

#include <string>
using namespace std;

namespace biology
{
	namespace dna
	{
		class nitrogenous_base
		{
			public:
				chemistry::compounds::compound compound;

				nitrogenous_base(string);
		};
	}
}

#endif // NITROGENOUS_BASE_HPP_INCLUDED
