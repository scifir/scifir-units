#ifndef CHEMISTRY_GENERAL_SUBSTANCE_UNITS_HPP_INCLUDED
#define CHEMISTRY_GENERAL_SUBSTANCE_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"

using namespace std;
using namespace physics::units;

namespace physics::units
{
	class molarity : public scalar_unit_crtp<molarity>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class molality : public scalar_unit_crtp<molality>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class linear_mass_density : public scalar_unit_crtp<linear_mass_density>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class area_density : public scalar_unit_crtp<area_density>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class dynamic_viscosity : public scalar_unit_crtp<dynamic_viscosity>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class mass_flow_rate : public scalar_unit_crtp<mass_flow_rate>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};
}

#endif // CHEMISTRY_GENERAL_SUBSTANCE_UNITS_HPP_INCLUDED
