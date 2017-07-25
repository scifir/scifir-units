#ifndef PHYSICS_ELECTROMAGNETISM_HARDWARE_UNITS_HPP_INCLUDED
#define PHYSICS_ELECTROMAGNETISM_HARDWARE_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"
using namespace std;
using namespace physics::units;

namespace physics::units
{
	class electrical_conductivity : public scalar_unit<electrical_conductivity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class electric_resistance : public scalar_unit<electric_resistance>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class electric_conductance : public scalar_unit<electric_conductance>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class permittivity : public scalar_unit<permittivity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class resistivity : public scalar_unit<resistivity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class linear_charge_density : public scalar_unit<linear_charge_density>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class frequency_drift : public scalar_unit<frequency_drift>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_ELECTROMAGNETISM_HARDWARE_UNITS_HPP_INCLUDED
