#ifndef PHYSICS_MECHANICS_MOVEMENT_UNITS_HPP_INCLUDED
#define PHYSICS_MECHANICS_MOVEMENT_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;

namespace physics::units
{
	class distance : public scalar_unit_crtp<distance>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};

	class velocity : public vector_unit_crtp<velocity>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};

	class acceleration : public vector_unit_crtp<acceleration>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};

	class jerk : public vector_unit_crtp<jerk>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};

	class snap : public vector_unit_crtp<snap>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};

	class angular_velocity : public vector_unit_crtp<angular_velocity>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};

	class angular_acceleration : public vector_unit_crtp<angular_acceleration>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};

	class angular_momentum : public vector_unit_crtp<angular_momentum>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};
}

#endif // PHYSICS_MECHANICS_MOVEMENT_UNITS_HPP_INCLUDED
