#ifndef PHYSICS_MECHANICS_FLUIDDYNAMICS_UNITS_HPP_INCLUDED
#define PHYSICS_MECHANICS_FLUIDDYNAMICS_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
using namespace std;
using namespace physics::units;

namespace physics::units
{
	class volumetric_flow : public scalar_unit<volumetric_flow>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class diffusion_coefficient : public scalar_unit<diffusion_coefficient>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class compressibility : public scalar_unit<compressibility>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_MECHANICS_FLUIDDYNAMICS_UNITS_HPP_INCLUDED
