#ifndef CHEMISTRY_GENERAL_COMPOUNDS_UNITS_HPP_INCLUDED
#define CHEMISTRY_GENERAL_COMPOUNDS_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"

using namespace std;
using namespace physics::units;

namespace physics::units
{
	class density : public scalar_unit_crtp<density>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class viscosity : public scalar_unit_crtp<viscosity>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class specific_volume : public scalar_unit_crtp<specific_volume>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class specific_heat_capacity : public scalar_unit_crtp<specific_heat_capacity>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class specific_entropy : public scalar_unit_crtp<specific_entropy>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class specific_energy : public scalar_unit_crtp<specific_energy>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class molar_volume : public scalar_unit_crtp<molar_volume>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class molar_mass : public scalar_unit_crtp<molar_mass>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class molar_heat_capacity : public scalar_unit_crtp<molar_heat_capacity>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class molar_entropy : public scalar_unit_crtp<molar_entropy>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class molar_energy : public scalar_unit_crtp<molar_energy>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class molar_conductivity : public scalar_unit_crtp<molar_conductivity>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class energy_density : public scalar_unit_crtp<energy_density>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};
}

#endif // CHEMISTRY_GENERAL_COMPOUNDS_UNITS_HPP_INCLUDED
