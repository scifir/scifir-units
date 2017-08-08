#ifndef PHYSICS_ELECTROMAGNETISM_ELECTRICITY_UNITS_HPP_INCLUDED
#define PHYSICS_ELECTROMAGNETISM_ELECTRICITY_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;

namespace physics::units
{
	class electric_displacement_field : public vector_unit_crtp<electric_displacement_field>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};

	class electric_charge_density : public scalar_unit_crtp<electric_charge_density>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class electric_current_density : public scalar_unit_crtp<electric_current_density>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class electric_field_strength : public vector_unit_crtp<electric_field_strength>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};

	class electron_mobility : public scalar_unit_crtp<electron_mobility>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_ELECTROMAGNETISM_ELECTRICITY_UNITS_HPP_INCLUDED
