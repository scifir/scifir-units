#ifndef ATOMS_IB_HPP_INCLUDED
#define ATOMS_IB_HPP_INCLUDED

#include "atom.hpp"

namespace chemistry
{
	namespace compounds
	{
		class Cu: public atom
		{
			public:
				Cu(int = 0, int = 0);
		};

		class Ag: public atom
		{
			public:
				Ag(int = 0, int = 0);
		};

		class Au: public atom
		{
			public:
				Au(int = 0, int = 0);
		};

		class Rg: public atom
		{
			public:
				Rg(int = 0, int = 0);
		};
	}
}

#endif // ATOMS_IB_HPP_INCLUDED
