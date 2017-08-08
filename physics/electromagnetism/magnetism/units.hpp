#ifndef PHYSICS_ELECTROMAGNETISM_MAGNETISM_UNITS_HPP_INCLUDED
#define PHYSICS_ELECTROMAGNETISM_MAGNETISM_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"
using namespace std;
using namespace physics::units;

namespace physics::units
{
	// TODO: vector_field
	class polarization_density : public scalar_unit_crtp<polarization_density>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	// TODO: vector_field
	class magnetic_permeability : public scalar_unit_crtp<magnetic_permeability>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	// TODO: vector_field
	class magnetization : public scalar_unit_crtp<magnetization>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class magnetic_moment : public vector_unit_crtp<magnetic_moment>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};

	class magnetic_reluctance : public scalar_unit_crtp<magnetic_reluctance>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	// TODO: vector_field
	class magnetic_vector_potential : public scalar_unit_crtp<magnetic_vector_potential>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class magnetic_rigidity : public scalar_unit_crtp<magnetic_rigidity>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class magnetomotive_force : public vector_unit_crtp<magnetomotive_force>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};

	class magnetic_susceptibility : public scalar_unit_crtp<magnetic_susceptibility>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_ELECTROMAGNETISM_MAGNETISM_UNITS_HPP_INCLUDED
