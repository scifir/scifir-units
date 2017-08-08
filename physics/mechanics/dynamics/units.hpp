#ifndef PHYSICS_MECHANICS_DYNAMICS_UNITS_HPP_INCLUDED
#define PHYSICS_MECHANICS_DYNAMICS_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;

namespace physics::units
{
	class impulse : public vector_unit_crtp<impulse>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};

	class force : public vector_unit_crtp<force>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};

	class torque : public vector_unit_crtp<torque>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};

	class pressure : public vector_unit_crtp<pressure>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};

	class surface_tension : public vector_unit_crtp<surface_tension>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};

	class stiffness : public scalar_unit_crtp<stiffness>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class moment_of_inertia : public scalar_unit_crtp<stiffness>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_MECHANICS_DYNAMICS_UNITS_HPP_INCLUDED
