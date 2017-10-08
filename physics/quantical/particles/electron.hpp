#ifndef ELECTRON_HPP_INCLUDED
#define ELECTRON_HPP_INCLUDED

#include "units.hpp"

using namespace msci::units;

namespace msci
{
	class electron
	{
		public:
			electron(float);

			float spin;

			static const mass common_mass;
	};
}

#endif // ELECTRON_HPP_INCLUDED
