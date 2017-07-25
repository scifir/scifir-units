#ifndef CHEMISTRY_GENERAL_SUBSTANCE_UNITS_HPP_INCLUDED
#define CHEMISTRY_GENERAL_SUBSTANCE_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"

using namespace std;
using namespace physics::units;

namespace physics::units
{
	class molarity : public scalar_unit<molarity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class molality : public scalar_unit<molality>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class linear_mass_density : public scalar_unit<linear_mass_density>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class area_density : public scalar_unit<area_density>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class dynamic_viscosity : public scalar_unit<dynamic_viscosity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class mass_flow_rate : public scalar_unit<mass_flow_rate>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};
}

#endif // CHEMISTRY_GENERAL_SUBSTANCE_UNITS_HPP_INCLUDED
