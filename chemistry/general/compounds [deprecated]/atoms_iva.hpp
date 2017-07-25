#ifndef ATOMS_IVA_HPP_INCLUDED
#define ATOMS_IVA_HPP_INCLUDED

#include "atom.hpp"

namespace chemistry
{
	namespace compounds
	{
		class C: public atom
		{
			public:
				C(int = 0, int = 0);
		};

		class Si: public atom
		{
			public:
				Si(int = 0, int = 0);
		};

		class Ge: public atom
		{
			public:
				Ge(int = 0, int = 0);
		};

		class Sn: public atom
		{
			public:
				Sn(int = 0, int = 0);
		};

		class Pb: public atom
		{
			public:
				Pb(int = 0, int = 0);
		};

		class Fl: public atom
		{
			public:
				Fl(int = 0, int = 0);
		};
	}
}

#endif // ATOMS_IVA_HPP_INCLUDED
