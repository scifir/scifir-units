#ifndef ELECTRON_HPP_INCLUDED
#define ELECTRON_HPP_INCLUDED

#include "physics/units.hpp"

using namespace physics::units;

namespace physics
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
