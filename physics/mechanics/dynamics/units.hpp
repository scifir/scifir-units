#ifndef PHYSICS_MECHANICS_DYNAMICS_UNITS_HPP_INCLUDED
#define PHYSICS_MECHANICS_DYNAMICS_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;

namespace physics::units
{
	class impulse : public vector_unit<impulse>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class force : public vector_unit<force>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class torque : public vector_unit<torque>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class pressure : public vector_unit<pressure>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class surface_tension : public vector_unit<surface_tension>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class stiffness : public scalar_unit<stiffness>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class moment_of_inertia : public scalar_unit<stiffness>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_MECHANICS_DYNAMICS_UNITS_HPP_INCLUDED
