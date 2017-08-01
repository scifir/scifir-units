#ifndef DNA_HPP_INCLUDED
#define DNA_HPP_INCLUDED

#include <vector>

#include "gene.hpp"

using namespace std;

namespace biology
{
	class dna
	{
		public:
			dna();

		private:
			vector<gene> genes;
	};
}

#endif // DNA_HPP_INCLUDED
