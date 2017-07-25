#ifndef CHEMISTRY_GENERAL_COMPOUNDS_UNITS_HPP_INCLUDED
#define CHEMISTRY_GENERAL_COMPOUNDS_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"

using namespace std;
using namespace physics::units;

namespace physics::units
{
	class density : public scalar_unit<density>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class viscosity : public scalar_unit<viscosity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class specific_volume : public scalar_unit<specific_volume>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class specific_heat_capacity : public scalar_unit<specific_heat_capacity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class specific_entropy : public scalar_unit<specific_entropy>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class specific_energy : public scalar_unit<specific_energy>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class molar_volume : public scalar_unit<molar_volume>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class molar_mass : public scalar_unit<molar_mass>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class molar_heat_capacity : public scalar_unit<molar_heat_capacity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class molar_entropy : public scalar_unit<molar_entropy>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class molar_energy : public scalar_unit<molar_energy>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class molar_conductivity : public scalar_unit<molar_conductivity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class energy_density : public scalar_unit<energy_density>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};
}

#endif // CHEMISTRY_GENERAL_COMPOUNDS_UNITS_HPP_INCLUDED
