#ifndef PHYSICS_THERMODYNAMICS_UNITS_HPP_INCLUDED
#define PHYSICS_THERMODYNAMICS_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;

namespace physics::units
{
	class energy : public scalar_unit<energy>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class action : public scalar_unit<action>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class power : public scalar_unit<power>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class power_density : public scalar_unit<power_density>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class enthalpy : public scalar_unit<enthalpy>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class entropy : public scalar_unit<entropy>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class heat_capacity : public scalar_unit<heat_capacity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class heat_flux_density : public scalar_unit<heat_flux_density>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class thermal_conductivity : public scalar_unit<thermal_conductivity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class thermal_diffusivity : public scalar_unit<thermal_diffusivity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class thermal_resistance : public scalar_unit<thermal_resistance>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class thermal_expansion_coefficient : public scalar_unit<thermal_expansion_coefficient>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class temperature_gradient : public vector_unit<temperature_gradient>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class energy_flux_density : public scalar_unit<energy_flux_density>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_THERMODYNAMICS_UNITS_HPP_INCLUDED
