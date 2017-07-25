#ifndef PHYSICS_WAVES_UNITS_HPP_INCLUDED
#define PHYSICS_WAVES_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;

namespace physics::units
{
	class wavenumber : public scalar_unit<wavenumber>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class frequency : public scalar_unit<frequency>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_WAVES_UNITS_HPP_INCLUDED
