#ifndef PHYSICS_ELECTROMAGNETISM_HARDWARE_UNITS_HPP_INCLUDED
#define PHYSICS_ELECTROMAGNETISM_HARDWARE_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"
using namespace std;
using namespace physics::units;

namespace physics::units
{
	class electrical_conductivity : public scalar_unit_crtp<electrical_conductivity>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class electric_resistance : public scalar_unit_crtp<electric_resistance>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class electric_conductance : public scalar_unit_crtp<electric_conductance>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class permittivity : public scalar_unit_crtp<permittivity>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class resistivity : public scalar_unit_crtp<resistivity>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class linear_charge_density : public scalar_unit_crtp<linear_charge_density>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class frequency_drift : public scalar_unit_crtp<frequency_drift>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_ELECTROMAGNETISM_HARDWARE_UNITS_HPP_INCLUDED
