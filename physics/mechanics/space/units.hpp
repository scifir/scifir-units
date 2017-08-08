#ifndef PHYSICS_MECHANICS_SPACE_UNITS_HPP_INCLUDED
#define PHYSICS_MECHANICS_SPACE_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"
using namespace std;

namespace physics::units
{
	class area : public scalar_unit_crtp<area>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class volume : public scalar_unit_crtp<volume>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class curvature : public scalar_unit_crtp<curvature>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_MECHANICS_SPACE_UNITS_HPP_INCLUDED
