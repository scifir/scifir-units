#ifndef PHYSICS_MECHANICS_MOVEMENT_UNITS_HPP_INCLUDED
#define PHYSICS_MECHANICS_MOVEMENT_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;

namespace physics::units
{
	class distance : public scalar_unit<distance>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class velocity : public vector_unit<velocity>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class acceleration : public vector_unit<acceleration>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class jerk : public vector_unit<jerk>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class snap : public vector_unit<snap>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class angular_velocity : public vector_unit<angular_velocity>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class angular_acceleration : public vector_unit<angular_acceleration>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class angular_momentum : public vector_unit<angular_momentum>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_MECHANICS_MOVEMENT_UNITS_HPP_INCLUDED
