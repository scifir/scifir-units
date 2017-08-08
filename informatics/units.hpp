#ifndef INFORMATIC_UNITS_HPP_INCLUDED
#define INFORMATIC_UNITS_HPP_INCLUDED

#include "physics/basic/units/scalar_unit.hpp"

using namespace std;

namespace physics::units
{
	class transfer_speed : public scalar_unit_crtp<transfer_speed>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};
}

#endif // INFORMATIC_UNITS_HPP_INCLUDED
