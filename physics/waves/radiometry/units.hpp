#ifndef PHYSICS_WAVES_RADIOMETRY_UNITS_HPP_INCLUDED
#define PHYSICS_WAVES_RADIOMETRY_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;

namespace physics::units
{
	class irradiance : public vector_unit_crtp<irradiance>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};

	class radiant_exposure : public vector_unit_crtp<radiant_exposure>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};

	class radiant_intensity : public scalar_unit_crtp<radiant_intensity>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class spectral_intensity : public scalar_unit_crtp<spectral_intensity>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class radiance : public scalar_unit_crtp<radiance>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class spectral_radiance : public scalar_unit_crtp<spectral_radiance>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
	};

	class radiant_flux : public vector_unit_crtp<radiant_flux>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};

	class spectral_flux : public vector_unit_crtp<spectral_flux>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_WAVES_RADIOMETRY_UNITS_HPP_INCLUDED
